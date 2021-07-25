package pmd.di.ubi.exservices1;

import android.app.Service;
import android.content.Intent;
import android.os.Handler;
import android.os.IBinder;
import android.util.Log;
import android.widget.Toast;


public class ServiceAlarm extends Service {

    Handler h;

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        h = new Handler();
        new Thread() {
            @Override
            public void run() {
                for (int i = 0; i < 10; i++) {
                    Runnable r = new Runnable() {
                        @Override
                        public void run() {
                            Toast.makeText(
                                    ServiceAlarm.this,
                                    "Service Started",
                                    Toast.LENGTH_SHORT).show();
                        }
                    };
                    h.post(r);

                    try {
                        Thread.sleep(5000);
                    } catch (InterruptedException e) {
                        Log.e("SERVICEALARMS", "Interrupted Exception!");
                    }
                }
            }
        }.start();

        return START_NOT_STICKY;
    }

    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }
}
