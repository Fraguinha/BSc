package ReallyNicePiano.Models;

import java.io.Serializable;
import java.time.Duration;
import java.time.Instant;
import java.util.ArrayList;
import java.util.HashMap;

public class Recording implements Serializable {

    private static final long serialVersionUID = 1L;

    private String name;

    private HashMap<Integer, Long> silences;
    private ArrayList<String> notes;

    private Thread currentlyPlayingThread;
    private Instant lastPlayed;
    private boolean isPaused;
    private int length;

    public Recording() {
        this.name = null;

        this.silences = new HashMap<>();
        this.notes = new ArrayList<>();

        this.currentlyPlayingThread = null;
        this.lastPlayed = Instant.now();
        this.isPaused = false;
        this.length = 0;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return "Recording{" +
                "name='" + name + '\'' +
                ", silences=" + silences +
                ", notes=" + notes +
                ", currentlyPlayingThread=" + currentlyPlayingThread +
                ", lastPlayed=" + lastPlayed +
                ", isPaused=" + isPaused +
                ", length=" + length +
                '}';
    }

    public void addNote(String note) {
        Instant now = Instant.now();

        silences.put(length++, Duration.between(lastPlayed, now).toMillis());
        notes.add(note);

        lastPlayed = now;
    }

    public void startPlayback() {
        if (isPaused) {
            isPaused = false;
        } else {
            if (currentlyPlayingThread == null) {
                currentlyPlayingThread = new Thread() {
                    public void run() {
                        try {
                            int i = 0;
                            for (String note : notes) {
                                String filename = note + ".m4a";
                                while (isPaused) {
                                    Thread.sleep(1);
                                }
                                Thread.sleep(silences.get(i++));
                                PianoModel.makeSound(filename);
                            }
                            currentlyPlayingThread = null;
                            isPaused = false;
                        } catch (InterruptedException e) {
                            currentlyPlayingThread = null;
                            isPaused = false;
                        }
                    }
                };
                currentlyPlayingThread.start();
            }
        }
    }

    public void pausePlayback() {
        if (currentlyPlayingThread != null) {
            isPaused = true;
        }
    }

    public void stopPlayback() {
        if (currentlyPlayingThread != null) {
            currentlyPlayingThread.interrupt();
        }
    }
}
