/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package blocotexto;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.CheckBox;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;

/**
 *
 * @author carolinasilva
 */
public class FXMLDocumentController implements Initializable {
    
    @FXML
    private TextArea textArea;
    @FXML
    private TextField textField;
    @FXML
    private Label result;
    @FXML
    private CheckBox checkbox;
    
    @FXML
    private void handleButtonAction(ActionEvent event) {
        String word = textField.getText();
        String text = textArea.getText();
        
        if(checkbox.isSelected()){
            word = word.toLowerCase();
            text = text.toLowerCase();    
        }
        
        String[] textWords = text.split("[ ,.:;!?\n]+");
        
        int count = 0;
        for (String textWord : textWords) {
            if(textWord.equals(word))
                count++;
        }
        
        result.setText(Integer.toString(count));
    }      
    
    
    @Override
    public void initialize(URL url, ResourceBundle rb) {
    } 
    
}
