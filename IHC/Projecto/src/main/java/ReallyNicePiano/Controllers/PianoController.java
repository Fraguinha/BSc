package ReallyNicePiano.Controllers;

import ReallyNicePiano.Models.HistoryModel;
import ReallyNicePiano.Models.PianoModel;
import ReallyNicePiano.ReallyNicePiano;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.effect.InnerShadow;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.stage.FileChooser;

import java.io.File;
import java.net.URL;
import java.util.ResourceBundle;

public class PianoController implements Initializable {

    @FXML private Label lblOctave;
    @FXML private ToggleButton tbRecord;
    @FXML private CheckBox cbKeyboard;

    @FXML private Button _do;
    @FXML private Button _re;
    @FXML private Button _mi;
    @FXML private Button _fa;
    @FXML private Button _sol;
    @FXML
    private Button _la;
    @FXML
    private Button _si;
    @FXML
    private Button _doS;
    @FXML
    private Button _reS;
    @FXML
    private Button _faS;
    @FXML
    private Button _solS;
    @FXML
    private Button _laS;

    @FXML
    private Label S;
    @FXML
    private Label D;
    @FXML
    private Label F;
    @FXML
    private Label G;
    @FXML
    private Label H;
    @FXML
    private Label J;
    @FXML
    private Label K;
    @FXML
    private Label E;
    @FXML
    private Label R;
    @FXML
    private Label Y;
    @FXML
    private Label U;
    @FXML
    private Label I;
    @FXML
    private Label A;
    @FXML
    private Label L;

    @FXML
    private ScrollPane sp;
    @FXML
    private AnchorPane anchorPane;

    private static double pos = 25;
    private static double doPos = 78;
    private static double rePos = 69;
    private static double miPos = 60;
    private static double faPos = 53;
    private static double solPos = 46;
    private static double laPos = 39;
    private static double siPos = 32;

    @FXML
    private Button record;
    @FXML
    private Button play;


    @FXML
    private void handleKeyClicked(ActionEvent event) {
        Button btn = (Button) event.getSource();

        playNote(btn);
        addNote(btn.getId());
    }

    private void playNote(Button btn) {
        InnerShadow is = new InnerShadow();
        is.setOffsetX(2.0f);
        is.setOffsetY(2.0f);

        btn.setEffect(is);
        String key = btn.getId();

        PianoModel.playKey(key);
    }

    private void addNote(String key) {
        if (tbRecord.isSelected()) {
            double top = 35, width = 27, height = 55;
            String img = "seminima.png";
            switch (key) {
                case "_do":
                    top = doPos;
                    img = "seminima-traco.png";
                    break;
                case "_re":
                    top = rePos;
                    break;
                case "_mi":
                    top = miPos;
                    break;
                case "_fa":
                    top = faPos;
                    break;
                case "_sol":
                    top = solPos;
                    break;
                case "_la":
                    top = laPos;
                    break;
                case "_si":
                    top = siPos;
                    break;
            }

            File file = new File("src/main/Resources/Images/" + img);
            Image image = new Image(file.toURI().toString());
            ImageView imageView = new ImageView(image);
            imageView.setFitWidth(width);
            imageView.setFitHeight(height);
            imageView.setPreserveRatio(true);
            imageView.setSmooth(true);

            AnchorPane.setTopAnchor(imageView, top);
            AnchorPane.setLeftAnchor(imageView, pos);
            pos += 50;
            anchorPane.getChildren().add(imageView);
            sp.setHvalue(1.0);
        }
    }


    @FXML
    public void handleKeyPressed(KeyEvent event) {
        double pos_copy = pos;
        InnerShadow is = new InnerShadow();
        is.setOffsetX(2.0f);
        is.setOffsetY(2.0f);

        switch (event.getText().toUpperCase()) {
            case "S":
                _do.fire();
                _do.setEffect(is);
                break;
            case "D":
                _re.fire();
                _re.setEffect(is);
                break;
            case "F":
                _mi.fire();
                _mi.setEffect(is);
                break;
            case "G":
                _fa.fire();
                _fa.setEffect(is);
                break;
            case "H":
                _sol.fire();
                _sol.setEffect(is);
                break;
            case "J":
                _la.fire();
                _la.setEffect(is);
                break;
            case "K":
                _si.fire();
                _si.setEffect(is);
                break;
            case "E":
                _doS.fire();
                _doS.setEffect(is);
                break;
            case "R":
                _reS.fire();
                _reS.setEffect(is);
                break;
            case "Y":
                _faS.fire();
                _faS.setEffect(is);
                break;
            case "U":
                _solS.fire();
                _solS.setEffect(is);
                break;
            case "I":
                _laS.fire();
                _laS.setEffect(is);
                break;
            case "A":
                handleDecrementOctaveAction(null);
                break;
            case "L":
                handleIncrementOctaveAction(null);
                break;
            default:
                break;
        }

    }

    @FXML
    private void handleKeyReleased(KeyEvent keyEvent) {
        switch (keyEvent.getText().toUpperCase()) {
            case "S":
                _do.setEffect(null);
                break;
            case "D":
                _re.setEffect(null);
                break;
            case "F":
                _mi.setEffect(null);
                break;
            case "G":
                _fa.setEffect(null);
                break;
            case "H":
                _sol.setEffect(null);
                break;
            case "J":
                _la.setEffect(null);
                break;
            case "K":
                _si.setEffect(null);
                break;
            case "E":
                _doS.setEffect(null);
                break;
            case "R":
                _reS.setEffect(null);
                break;
            case "Y":
                _faS.setEffect(null);
                break;
            case "U":
                _solS.setEffect(null);
                break;
            case "I":
                _laS.setEffect(null);
                break;
            default:
                break;
        }
    }

    @FXML
    private void handleRecordButtonAction(ActionEvent event) {
        PianoModel.toggleRecord(tbRecord.isSelected());
    }

    @FXML
    private void handleDeleteButtonAction(ActionEvent event) {
        tbRecord.setSelected(false);
        PianoModel.deleteRecording();
        anchorPane.getChildren().clear();
        pos = 25;
    }

    @FXML
    private void handlePlayButtonAction(ActionEvent event) {
        PianoModel.startPlayback();
    }

    @FXML
    private void handlePauseButtonAction(ActionEvent event) {
        PianoModel.pausePlayback();
    }

    @FXML
    private void handleStopButtonAction(ActionEvent event) {
        PianoModel.stopPlayback();
    }

    @FXML
    private void handleShowKeyboardPressed(ActionEvent event) {
        if (cbKeyboard.isSelected()) {
            S.setVisible(true);
            D.setVisible(true);
            F.setVisible(true);
            G.setVisible(true);
            H.setVisible(true);
            J.setVisible(true);
            K.setVisible(true);
            E.setVisible(true);
            R.setVisible(true);
            Y.setVisible(true);
            U.setVisible(true);
            I.setVisible(true);
            A.setVisible(true);
            L.setVisible(true);

        } else {
            S.setVisible(false);
            D.setVisible(false);
            F.setVisible(false);
            G.setVisible(false);
            H.setVisible(false);
            J.setVisible(false);
            K.setVisible(false);
            E.setVisible(false);
            R.setVisible(false);
            Y.setVisible(false);
            U.setVisible(false);
            I.setVisible(false);
            A.setVisible(false);
            L.setVisible(false);
        }
    }

    @FXML
    private void handleIncrementOctaveAction(ActionEvent event) {
        int octave = PianoModel.incOctave();
        lblOctave.setText(String.valueOf(octave));
    }

    @FXML
    private void handleDecrementOctaveAction(ActionEvent event) {
        int octave = PianoModel.decOctave();
        lblOctave.setText(String.valueOf(octave));
    }

    @Override
    public void initialize(URL url, ResourceBundle rb) {
        sp.setContent(anchorPane);
    }

    public void handleMouseReleased(MouseEvent mouseEvent) {
        Button b = (Button) mouseEvent.getSource();

        b.setEffect(null);
    }

    public void handleSaveButtonAction(ActionEvent actionEvent) {
        FileChooser chooser = new FileChooser();
        chooser.getExtensionFilters().add(new FileChooser.ExtensionFilter("Piano files (*.piano)", "*.piano"));
        String dir = HistoryModel.getCurrentDirectory();
        chooser.setInitialDirectory(new File(dir));
        File file = chooser.showSaveDialog(ReallyNicePiano.stage);

        PianoModel.saveRecording(file);
    }

    public void handleMenuButtonAction(ActionEvent actionEvent) {
        ReallyNicePiano.stage.setScene(ReallyNicePiano.menu());
        ReallyNicePiano.stage.setTitle("Main Menu");
        ReallyNicePiano.stage.show();
    }
}
