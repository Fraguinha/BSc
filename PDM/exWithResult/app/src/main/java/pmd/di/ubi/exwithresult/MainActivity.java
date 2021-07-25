package pmd.di.ubi.exwithresult;

import androidx.appcompat.app.AppCompatActivity;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.*;

public class MainActivity extends Activity {

    EditText fname;
    EditText lname;

    private String name1;
    private String name2;
    private static int iRequest_code = 69;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        fname = (EditText) findViewById(R.id.fName);
        lname = (EditText) findViewById(R.id.lName);
    }


    public void goToSecond(View view) {

        name1 = fname.getText().toString();
        name2 = lname.getText().toString();

        Intent i = new Intent(this, ProcessNames.class);

        i.putExtra("name1", name1);
        i.putExtra("name2", name2);

        startActivityForResult(i, iRequest_code);
    }

    @Override
    protected void onActivityResult(int iReqCode, int iResultCode, Intent iResult) {
        if ((iReqCode == iRequest_code) && (iResultCode == RESULT_OK)) {
            TextView oVT = (TextView) findViewById(R.id.concat);
            oVT.setText(iResult.getStringExtra("concatNames"));
        }
    }

}
