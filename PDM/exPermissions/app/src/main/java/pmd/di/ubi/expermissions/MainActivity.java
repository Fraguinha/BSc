package pmd.di.ubi.expermissions;

import androidx.appcompat.app.AppCompatActivity;

import android.Manifest;
import android.app.Activity;
import android.os.Bundle;
import android.provider.CallLog;
import android.net.Uri;
import android.database.Cursor;
import android.widget.TextView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView oTV = (TextView) findViewById(R.id.lc);

        if(checkSelfPermission(Manifest.permission.READ_CALL_LOG) != 0) {
            // 0 = PackageManager.PERMISSION_GRANTED
            requestPermissions(new String[]{Manifest.permission.READ_CALL_LOG}, 1);
        }
            Uri uriCalls = Uri.parse("content://call_log/calls");
            Cursor curCalls = getContentResolver().query(uriCalls, null, null, null, null);

            String sInfo = "Last Call: ";
            if (curCalls.moveToLast()) {
                sInfo += curCalls.getString(curCalls.getColumnIndex(CallLog.Calls.NUMBER))
                        + "\nDuration: " + curCalls.getString(curCalls.getColumnIndex(CallLog.Calls.DURATION));
            }
            oTV.setText(sInfo);

    }
}
