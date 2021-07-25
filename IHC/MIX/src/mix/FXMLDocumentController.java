/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mix;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.ColorPicker;
import javafx.scene.control.Slider;
import javafx.scene.image.ImageView;
import javafx.scene.layout.BorderPane;
import javafx.scene.paint.Color;

/**
 *
 * @author carolinasilva
 */
public class FXMLDocumentController implements Initializable {
    
    @FXML private Slider sldr;
    @FXML private ImageView img;
    @FXML private ColorPicker pkr;
    @FXML private BorderPane pane;
    @FXML private Button btnTimer;
    
    public void adjustSize() {
         double scale = sldr.getValue();
         
         img.setScaleX(scale);
         img.setScaleY(scale);
    }
    
    
    public void changeBackground(){
        Color c = pkr.getValue();
        System.out.println(c.getRed());
        pane.setStyle("-fx-background-color: rgb("+ String.valueOf(c.getRed()*255) + "," 
                + String.valueOf(c.getGreen()*255) + "," + String.valueOf(c.getBlue()*255) + ")");
    }
   
    
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        sldr.valueProperty().addListener((observable, oldv, newv) -> adjustSize());
        pkr.valueProperty().addListener((observable, oldv, newv) -> changeBackground());
    }    
    
}
