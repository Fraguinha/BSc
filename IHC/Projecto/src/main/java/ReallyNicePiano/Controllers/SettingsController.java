package ReallyNicePiano.Controllers;

import ReallyNicePiano.Models.HistoryModel;
import ReallyNicePiano.Models.SettingsModel;
import ReallyNicePiano.ReallyNicePiano;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.TextField;
import javafx.stage.DirectoryChooser;

import java.io.File;
import java.net.URL;
import java.util.ResourceBundle;

public class SettingsController implements Initializable {

    @FXML
    TextField lblDirectory;

    @Override
    public void initialize(URL url, ResourceBundle rb) {
        lblDirectory.setText(HistoryModel.getCurrentDirectory());
    }

    public void handleChangeDirButtonAction(ActionEvent actionEvent) {
        DirectoryChooser chooser = new DirectoryChooser();
        File d = new File(lblDirectory.getText());
        chooser.setInitialDirectory(d);
        File dir = chooser.showDialog(ReallyNicePiano.stage);
        if (!dir.equals(d)) {
            HistoryModel.updateDirectory(dir);
            SettingsModel.saveSettings(dir);
            String path = dir.getPath();
            lblDirectory.setText(path);
        }
    }

    public void handleMenuButtonAction(ActionEvent actionEvent) {
        ReallyNicePiano.stage.setScene(ReallyNicePiano.menu());
        ReallyNicePiano.stage.setTitle("Main Menu");
        ReallyNicePiano.stage.show();
    }
}
