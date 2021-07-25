/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package registoalunoubi;

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
    private TextField txfNome;
    @FXML
    private TextField txfNumero;
    @FXML
    private TextField txfCurso;
    
    
    @FXML
    private void handleButtonAction(ActionEvent event) {
        String nome = txfNome.getText();
        System.out.println(nome);
        String numero = txfNumero.getText();
        System.out.println(numero);
        String curso = txfCurso.getText();
        System.out.println(curso);
    }
    
    @FXML
    private void handleCancel(ActionEvent event) {
        System.exit(0);
    }
    
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }    
    
}
