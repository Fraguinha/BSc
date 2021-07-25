package pmd.di.ubi.activitylifecycle;

import android.app.Activity;
import android.os.Bundle;
import android.util.*;

public class MainActivity extends Activity
{

    private static final String TAG = "ActivityLifeCycle";

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Log.wtf(TAG, "onCreate");

    }

    @Override
    public void onStart()
    {
        super.onStart();
        Log.wtf(TAG, "onStart");
    }

    @Override
    public void onResume()
    {
        super.onResume();
        Log.wtf(TAG, "onResume");
    }

    @Override
    public void onRestart()
    {
        super.onRestart();
        Log.wtf(TAG, "onRestart");
    }

    @Override
    public void onPause()
    {
        super.onPause();
        Log.wtf(TAG, "onPause");
    }

    @Override
    public void onStop()
    {
        super.onStop();
        Log.wtf(TAG, "onStop");
    }

    @Override
    public void onDestroy()
    {
        super.onDestroy();
        Log.wtf(TAG, "onDestroy");
    }

}

