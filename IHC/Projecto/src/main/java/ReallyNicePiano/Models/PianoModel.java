package ReallyNicePiano.Models;

import ReallyNicePiano.ReallyNicePiano;
import javafx.scene.media.AudioClip;

import java.io.File;

public abstract class PianoModel {

    private static int octave = 4;

    private static Recording currentRecording = null;
    private static boolean isRecording = false;

    public static void playKey(String key) {
        String filename = key + octave + ".m4a";
        makeSound(filename);

        if (isRecording) {
            currentRecording.addNote(key + octave);
        }
    }

    public static void makeSound(String filename) {
        new AudioClip(ReallyNicePiano.class.getClassLoader().getResource("Sounds/" + filename).toString()).play();
    }

    public static void toggleRecord(boolean toggleButton) {
        isRecording = toggleButton;
        if (isRecording) {
            if (currentRecording != null) {
                currentRecording.stopPlayback();
            }
            currentRecording = new Recording();
        }
    }

    public static void startPlayback() {
        if (currentRecording != null) {
            currentRecording.startPlayback();
        }
    }

    public static void pausePlayback() {
        if (currentRecording != null) {
            currentRecording.pausePlayback();
        }
    }

    public static void stopPlayback() {
        if (currentRecording != null) {
            currentRecording.stopPlayback();
        }
    }

    public static void saveRecording(File file) {
        if (currentRecording != null) {
            currentRecording.setName(file.getName());
            HistoryModel.history.add(currentRecording);
            HistoryModel.saveFile(currentRecording, file);
        }
    }

    public static void deleteRecording() {
        toggleRecord(false);
        if (currentRecording != null) {
            currentRecording.stopPlayback();
        }
        currentRecording = null;
    }

    public static int incOctave() {
        if (octave < 7) {
            octave += 1;
        }
        return octave;
    }

    public static int decOctave() {
        if (octave > 1) {
            octave -= 1;
        }
        return octave;
    }
}
