package pmd.di.ubi.exwithresult;

import androidx.appcompat.app.AppCompatActivity;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;

public class ProcessNames extends Activity {

    private String cat;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_process_names);

        System.out.println("Activity 2");

        Intent i = getIntent();

        String name1 = i.getStringExtra("name1");
        String name2 = i.getStringExtra("name2");

        cat = name1 + name2;


    }

    public void goBack(View view){
        Intent i = new Intent();
        i.putExtra("concatNames", cat);
        setResult(RESULT_OK, i);
        super.finish();
    }
}
