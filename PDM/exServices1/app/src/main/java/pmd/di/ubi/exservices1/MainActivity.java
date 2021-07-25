package pmd.di.ubi.exservices1;

import android.Manifest;
import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        requestPermissions(new String[]{Manifest.permission.RECEIVE_SMS}, 1);

    }

    public void onButtonClick(View v){
        Intent i = new Intent(this, ServiceAlarm.class);

        startService(i);
    }
}
