/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package areatriangulo;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

/**
 *
 * @author carolinasilva
 */
public class FXMLDocumentController implements Initializable {

    @FXML
    private TextField txfA;
    @FXML
    private TextField txfB;
    @FXML
    private TextField txfC;
    @FXML
    private Label result;

    @FXML
    private void handleButtonAction(ActionEvent event) {
        try {
            float a = Float.valueOf(txfA.getText());
            float b = Float.valueOf(txfB.getText());
            float c = Float.valueOf(txfC.getText());
            if (a > (b + c) || b > (a + c) || c > (a + b)) {
                result.setText("Não é um triângulo!");
            } else {
                float s = (a + b + c) / 2;
                float area = (float) Math.sqrt(s * (s - a) * (s - b) * (s - c));
                result.setText(String.valueOf(area));
            }
        } catch (Exception e) {
            result.setText("Valor Inválido!");
        }

    }

    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }

}
