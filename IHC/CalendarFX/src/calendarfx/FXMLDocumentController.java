/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package calendarfx;

import java.net.URL;
import java.util.Calendar;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.control.Spinner;
import javafx.scene.control.SpinnerValueFactory;

/**
 *
 * @author carolinasilva
 */
public class FXMLDocumentController implements Initializable {
    
    @FXML
    private Label[] dias;
    @FXML 
    private ComboBox cbMes;
    @FXML
    private Spinner spAno;
    
    private String[] months = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    
    @FXML
    private void handleButtonAction(ActionEvent event) {
    }
    
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        Calendar cal = Calendar.getInstance();
        cbMes.getItems().setAll(months);
        cbMes.setValue(months[cal.get(Calendar.MONTH)]);
        
        spAno.setValueFactory(
                new SpinnerValueFactory.IntegerSpinnerValueFactory(1970,2100,cal.get(Calendar.YEAR))
        );
        
    }    
    
}
