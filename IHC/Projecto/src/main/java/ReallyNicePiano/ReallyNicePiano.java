package ReallyNicePiano;

import ReallyNicePiano.Models.SettingsModel;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.net.URL;

public class ReallyNicePiano extends Application {

    public static Stage stage;

    public static URL getResource(String filename) {
        return ReallyNicePiano.class.getClassLoader().getResource(filename);
    }

    @Override
    public void start(Stage stage) {
        SettingsModel.readSettings();

        ReallyNicePiano.stage = stage;
        stage.setResizable(false);

        stage.setScene(ReallyNicePiano.menu());
        stage.setTitle("Main Menu");
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }


    public static Scene settings() {
        try {
            return new Scene(FXMLLoader.load(ReallyNicePiano.getResource("Views/Settings.fxml")));
        } catch (Exception e) {
            return null;
        }
    }

    public static Scene history() {
        try {
            return new Scene(FXMLLoader.load(ReallyNicePiano.getResource("Views/History.fxml")));
        } catch (Exception e) {
            return null;
        }
    }

    public static Scene piano() {
        try {
            return new Scene(FXMLLoader.load(ReallyNicePiano.getResource("Views/Piano.fxml")));
        } catch (Exception e) {
            return null;
        }
    }

    public static Scene menu() {
        try {
            return new Scene(FXMLLoader.load(ReallyNicePiano.getResource("Views/Menu.fxml")));
        } catch (Exception e) {
            return null;
        }
    }

}
