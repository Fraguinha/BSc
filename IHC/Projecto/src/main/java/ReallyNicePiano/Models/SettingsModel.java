package ReallyNicePiano.Models;

import java.io.*;

public class SettingsModel {

    public static void readSettings() {
        try {
            File file = new File(".settings");
            FileInputStream fileStream = new FileInputStream(file);
            ObjectInputStream objectStream = new ObjectInputStream(fileStream);
            File directory = (File) objectStream.readObject();
            HistoryModel.updateDirectory(directory);
            objectStream.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void saveSettings(File directory) {
        try {
            File file = new File(".settings");
            FileOutputStream fileStream = new FileOutputStream(file);
            ObjectOutputStream objectStream = new ObjectOutputStream(fileStream);
            objectStream.writeObject(directory);
            objectStream.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}

