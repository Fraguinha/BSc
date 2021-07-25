package pmd.di.ubi.advancedcalculator;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

import android.text.TextWatcher;
import android.view.*;
import android.widget.*;
import android.text.Editable;

import java.lang.Math;



public class MainActivity extends AppCompatActivity {
    EditText oTEdit1 ;
    EditText oTEdit2 ;
    Button oButtonA ;
    Button oButtonS ;
    Button oButtonM ;
    Button oButtonD ;
    Button oButtonL ;
    Button oButtonP ;
    TextView oTView1 ;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        oTEdit1 = (EditText) findViewById(R.id.number1);
        oTEdit2 = (EditText) findViewById(R.id.number2);
        oButtonA = (Button) findViewById (R.id.sum) ;
        oButtonS = (Button) findViewById (R.id.sub) ;
        oButtonM = (Button) findViewById (R.id.mul) ;
        oButtonD = (Button) findViewById (R.id.div) ;
        oButtonL = (Button) findViewById (R.id.log) ;
        oButtonP = (Button) findViewById (R.id.pow) ;
        oTView1 = (TextView) findViewById(R.id.result);

        oButtonA.setOnClickListener (
                new View.OnClickListener () {
                    public void onClick (View oView) {
                        double d1 = (new Double(oTEdit1.getText().toString())).doubleValue();
                        double d2 = (new Double(oTEdit2.getText().toString())).doubleValue();
                        double dSum = d1 + d2 ;
                        oTView1.setText(String.valueOf(dSum));
                    } });

        oButtonS.setOnClickListener (
                new View.OnClickListener () {
                    public void onClick (View oView) {
                        double d1 = (new Double(oTEdit1.getText().toString())).doubleValue();
                        double d2 = (new Double(oTEdit2.getText().toString())).doubleValue();
                        double dSum = d1 - d2 ;
                        oTView1.setText(String.valueOf(dSum));
                    } });

        oButtonM.setOnClickListener (
                new View.OnClickListener () {
                    public void onClick (View oView) {
                        double d1 = (new Double(oTEdit1.getText().toString())).doubleValue();
                        double d2 = (new Double(oTEdit2.getText().toString())).doubleValue();
                        double dSum = d1 * d2 ;
                        oTView1.setText(String.valueOf(dSum));
                    } });

        oButtonD.setOnClickListener (
                new View.OnClickListener () {
                    public void onClick (View oView) {
                        double d1 = (new Double(oTEdit1.getText().toString())).doubleValue();
                        double d2 = (new Double(oTEdit2.getText().toString())).doubleValue();
                        if(d2 != 0){
                            double dSum = d1 / d2 ;
                            oTView1.setText(String.valueOf(dSum));
                        }else{
                            oTView1.setText("Error");
                        }

                    } });

        oButtonL.setOnClickListener (
                new View.OnClickListener () {
                    public void onClick (View oView) {
                        double d1 = (new Double(oTEdit1.getText().toString())).doubleValue();
                        double d2 = (new Double(oTEdit2.getText().toString())).doubleValue();
                        if(d1 >= 0){
                            double dSum = Math.log(d1)/Math.log((d2));
                            oTView1.setText(String.valueOf(dSum));
                        }else{
                            oTView1.setText("Error");
                        }

                    } });
        oButtonP.setOnClickListener (
                new View.OnClickListener () {
                    public void onClick (View oView) {
                        double d1 = (new Double(oTEdit1.getText().toString())).doubleValue();
                        double d2 = (new Double(oTEdit2.getText().toString())).doubleValue();

                        double dSum = Math.pow(d1,d2) ;
                        oTView1.setText(String.valueOf(dSum));


                    } });

        oTEdit2.addTextChangedListener(
                new TextWatcher() {
                    @Override
                    public void beforeTextChanged(CharSequence s, int start, int count, int after) {
                    }

                    @Override
                    public void onTextChanged(CharSequence s, int start, int before, int count) {
                        double d1 = (new Double(oTEdit1.getText().toString())).doubleValue();
                        double d2 = (new Double(oTEdit2.getText().toString())).doubleValue();
                        double dSum = d1 + d2 ;
                        oTView1.setText(String.valueOf(dSum));
                    }

                    @Override
                    public void afterTextChanged(Editable s) {

                    }
                });
    }
}
