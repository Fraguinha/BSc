package ReallyNicePiano.Controllers;

import ReallyNicePiano.Models.HistoryModel;
import ReallyNicePiano.ReallyNicePiano;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollPane;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;

import java.net.URL;
import java.util.ResourceBundle;

public class HistoryController implements Initializable {

    @FXML
    private ScrollPane sp;
    @FXML
    private AnchorPane anchorPane;
    @FXML
    private VBox vbox;

    public void addRecording(String name) {
        Label lbl = new Label(name);

        Button play = new Button();
        play.setId(name + "_play");
        play.setOnAction(this::playRecording);
        play.setPrefWidth(40);
        play.setPrefHeight(40);
        play.setMaxWidth(40);
        play.setMaxHeight(40);
        play.setMinHeight(40);
        play.setMinWidth(40);

        Image image = new Image(ReallyNicePiano.getResource("Images/play-green.png").toString());
        ImageView iv = new ImageView(image);
        iv.setFitHeight(20);
        iv.setFitWidth(20);

        play.setGraphic(iv);

        Button del = new Button();
        del.setId(name + "_del");
        del.setOnAction(this::deleteRecording);
        del.setPrefWidth(40);
        del.setPrefHeight(40);
        del.setMaxWidth(40);
        del.setMaxHeight(40);
        del.setMinHeight(40);
        del.setMinWidth(40);

        Image image2 = new Image(ReallyNicePiano.getResource("Images/delete.png").toString());
        ImageView iv2 = new ImageView(image2);
        iv2.setFitHeight(30);
        iv2.setFitWidth(30);

        del.setGraphic(iv2);

        HBox hbox = new HBox();
        hbox.setId(name);
        hbox.getChildren().addAll(lbl, play, del);
        hbox.setSpacing(20);
        hbox.setAlignment(Pos.CENTER_RIGHT);
        hbox.setPadding(new Insets(15, 15, 15, 30));
        vbox.getChildren().add(hbox);
    }

    private void playRecording(ActionEvent event) {
        Button btn = (Button) event.getSource();
        String name = btn.getId().split("_")[0];
        HistoryModel.playRecording(name);
    }

    private void deleteRecording(ActionEvent event) {
        Button btn = (Button) event.getSource();
        String name = btn.getId().split("_")[0];
        HistoryModel.deleteRecording(name);
        ReallyNicePiano.stage.setScene(ReallyNicePiano.history());
        ReallyNicePiano.stage.setTitle("Recordings");
        ReallyNicePiano.stage.show();
    }

    @Override
    public void initialize(URL url, ResourceBundle rb) {
        sp.setContent(anchorPane);
        vbox = new VBox();
        anchorPane.getChildren().add(vbox);
        HistoryModel.readHistory(this);
    }

    public void handleMenuButtonAction(ActionEvent actionEvent) {
        ReallyNicePiano.stage.setScene(ReallyNicePiano.menu());
        ReallyNicePiano.stage.setTitle("Main Menu");
        ReallyNicePiano.stage.show();
    }
}
