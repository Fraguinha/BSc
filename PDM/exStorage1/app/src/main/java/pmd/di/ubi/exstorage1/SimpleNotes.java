package pmd.di.ubi.exstorage1;

import android.app.Activity;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class SimpleNotes extends Activity {

    EditText etext;
    SharedPreferences oSP;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        etext = findViewById(R.id.etext);

        oSP = getPreferences(0);
        if (!oSP.getBoolean("recover", false)) {

            try {
                BufferedReader in = new BufferedReader(
                        new InputStreamReader(getResources().openRawResource(R.raw.instructions))
                );
                char[] text = new char[1024];
                in.read(text);
                etext.setText(String.valueOf(text));
                in.close();
            } catch (IOException e) {
                Log.e("Exception:", e.toString());
            }
        } else {
            try {
                BufferedReader in = new BufferedReader(new InputStreamReader(
                        openFileInput("savednote.txt")));
                char[] text = new char[1024];
                in.read(text);
                etext.setText(String.valueOf(text));
                in.close();
            } catch (IOException e) {
                Log.e("Exception", e.toString());
            }
        }

    }

    public void exitNotSave(View v) {
        SharedPreferences.Editor oEditor = oSP.edit();
        oEditor.putBoolean("recover", true);

        try {
            FileOutputStream fosFile = openFileOutput("savednote.txt", 0);
            fosFile.write(etext.getText().toString().getBytes());
            fosFile.close();
            oEditor.commit();
        } catch (IOException e) {
            Log.e("SIMPLENOTES", "FILE IO PROBLEM");
        }

        super.finish();
    }

    public void sendSave(View v) {
        String text = etext.getText().toString();
        SharedPreferences.Editor oEditor = oSP.edit();
        oEditor.putBoolean("recover", false);


        File fFnote = new File(Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES), "note.txt");
        try {
            FileOutputStream fosFile = new FileOutputStream(fFnote);
            fosFile.close();
            oEditor.commit();
        } catch(IOException e) {
            Log.e("Exception", e.toString());
        }

        super.finish();
    }
}
