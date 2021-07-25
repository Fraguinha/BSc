/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package calculadora;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;

import pt.ubi.ihc.Registadora;

/**
 *
 * @author carolinasilva
 */
public class FXMLDocumentController implements Initializable {

    @FXML
    private TextArea txtAreaPP;
    @FXML
    private Label lblRes;

    private String num = "0";

    private Registadora reg;

    @FXML
    private void handleNumberButtons(ActionEvent event) {
        Button btn = (Button) event.getSource();
        String s = btn.getText();
        txtAreaPP.appendText(s);
        num += s;
    }

    @FXML
    private void handleFunctionButtons(ActionEvent event) {
        Button btn = (Button) event.getSource();
        char c = btn.getText().charAt(0);
        if (c == '-' && num.equals("0")) {
            num = "-";
            txtAreaPP.appendText(c + "");
        } else {
            txtAreaPP.appendText(" " + c + "\n");
            reg.regista(Double.valueOf(num));
            reg.defineOperador(c);
            lblRes.setText(reg.getResultado() + "");
            num = "0";
        }
    }

    @FXML
    private void handleCalculate(ActionEvent event) {
        reg.regista(Double.valueOf(num));
        double d = reg.getResultado();
        String s = reg.getMensagemErro();
        txtAreaPP.appendText("\n" + "-----------------------" + "\n");
        if (!s.equals("")) {
            txtAreaPP.appendText(s + "\n");
        }
        txtAreaPP.appendText(d + "\n\n");
        reg = new Registadora();
        num = "0";
    }

    @FXML
    private void handleClear(ActionEvent event) {
        reg = new Registadora();
        txtAreaPP.setText("");
        num = "0";
    }

    @FXML
    private void handleDot(ActionEvent event) {
        if (!num.contains(".")) {
            txtAreaPP.appendText(".");
            num += ".";
        }
    }

    @Override
    public void initialize(URL url, ResourceBundle rb) {
        reg = new Registadora();
    }

}
