package ReallyNicePiano.Controllers;

import ReallyNicePiano.ReallyNicePiano;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.effect.Bloom;
import javafx.scene.input.MouseEvent;

import java.net.URL;
import java.util.ResourceBundle;

public class MenuController implements Initializable {

    @FXML
    public Button btnPiano;
    @FXML
    public Button btnHistory;
    @FXML
    public Button btnSettings;

    @FXML
    public void handleHover(MouseEvent event) {
        Button b = (Button) event.getSource();
        b.setCache(true);
        Bloom bloom = new Bloom();
        bloom.setThreshold(1.0);
        b.setEffect(bloom);
    }

    @FXML
    public void handleMenuButtonAction(ActionEvent event) {
        if (event.getSource() == btnPiano) {
            ReallyNicePiano.stage.setScene(ReallyNicePiano.piano());
            ReallyNicePiano.stage.setTitle("Piano");
        } else if (event.getSource() == btnHistory) {
            ReallyNicePiano.stage.setScene(ReallyNicePiano.history());
            ReallyNicePiano.stage.setTitle("Recordings");
        } else if (event.getSource() == btnSettings) {
            ReallyNicePiano.stage.setScene(ReallyNicePiano.settings());
            ReallyNicePiano.stage.setTitle("Settings");
        }
        ReallyNicePiano.stage.show();
    }

    @Override
    public void initialize(URL url, ResourceBundle rb) {
    }
}