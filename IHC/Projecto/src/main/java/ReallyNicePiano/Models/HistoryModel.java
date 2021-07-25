package ReallyNicePiano.Models;

import ReallyNicePiano.Controllers.HistoryController;

import java.io.*;
import java.util.ArrayList;

public class HistoryModel {

    public static ArrayList<Recording> history = new ArrayList<>();
    public static String DIRECTORY = "./history/";

    public static void readHistory(HistoryController controller) {
        File directory = new File(DIRECTORY);
        if (!directory.isDirectory()) {
            directory.mkdir();
        }
        File[] files = directory.listFiles();
        for (File file : files) {
            Recording rec = readFile(file);
            if (rec != null) {
                history.add(rec);
                controller.addRecording(rec.getName());
            }
        }
    }

    public static void playRecording(String name) {
        for (Recording rec : history) {
            if (rec.getName().equals(name)) {
                rec.startPlayback();
                break;
            }
        }
    }

    public static void deleteRecording(String name) {
        for (Recording rec : history) {
            if (rec.getName().equals(name)) {
                history.remove(rec);
                System.out.println(DIRECTORY + name);
                File file = new File(DIRECTORY + name);
                file.delete();
                break;
            }
        }
    }

    public static Recording readFile(File file) {
        Recording rec = null;
        try {
            FileInputStream fileStream = new FileInputStream(file);
            ObjectInputStream objectStream = new ObjectInputStream(fileStream);
            rec = (Recording) objectStream.readObject();
            objectStream.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return rec;
    }

    public static void saveFile(Recording rec, File file) {
        try {
            FileOutputStream fileStream = new FileOutputStream(file);
            ObjectOutputStream objectStream = new ObjectOutputStream(fileStream);
            objectStream.writeObject(rec);
            objectStream.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void updateDirectory(File directory) {
        DIRECTORY = directory.getPath() + "/";
    }

    public static String getCurrentDirectory() {
        return DIRECTORY;
    }
}
