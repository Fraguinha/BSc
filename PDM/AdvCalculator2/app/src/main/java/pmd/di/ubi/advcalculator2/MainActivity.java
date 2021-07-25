package pmd.di.ubi.advcalculator2;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.*;
import android.widget.*;

public class MainActivity extends AppCompatActivity {

    EditText oETnumber1;
    EditText oETnumber2;
    Button oButton1;
    Button oButton2;
    Button oButton3;
    Button oButton4;
    TextView oTVresult;

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        oETnumber1 = (EditText)findViewById(R.id.number1);
        oETnumber2 = (EditText)findViewById(R.id.number2);
        oButton1   = (Button)findViewById(R.id.SUM);
        oButton2   = (Button)findViewById(R.id.SUB);
        oButton3   = (Button)findViewById(R.id.MUL);
        oButton4   = (Button)findViewById(R.id.DIV);
        oTVresult  = (TextView)findViewById(R.id.result);



        // Classe com nome
        class ClickListener implements View.OnClickListener {
            @Override
            public void onClick(View v) {
                double d1 = (new Double(oETnumber1.getText().toString())).doubleValue();
                double d2 = (new Double(oETnumber2.getText().toString())).doubleValue();
                double result = 0;
                switch( v.getId() ){
                    case R.id.SUM:
                        result = d1+d2;
                        break;

                    case R.id.SUB :
                        result = d1-d2;
                        break;

                    case R.id.MUL :
                        result = d1*d2;
                        break;

                    case R.id.DIV :
                        if(d2 != 0) {
                            result = d1 / d2;
                        }
                        else{
                            result = 0.0;
                        }
                        break;
                }
                oTVresult.setText(  result + " " );

            }
        }

        // Instanciar a classe implementada antes
        ClickListener oOCListener = new ClickListener();

        // Associar o MESMO consumidor a todos os Botões
        oButton2.setOnClickListener( oOCListener );
        oButton3.setOnClickListener( oOCListener );
        oButton4.setOnClickListener( oOCListener );

    }

    public void somar(View v){
        double d1 = (new Double(oETnumber1.getText().toString())).doubleValue();
        double d2 = (new Double(oETnumber2.getText().toString())).doubleValue();
        double result = 100;//d1+d2;
        oTVresult.setText(  result + " " );
    }
}
