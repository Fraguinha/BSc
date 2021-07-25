package pmd.di.ubi.prunusapp;

import android.app.Activity;
import android.content.ContentValues;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

public class ContagemActivity extends Activity {

    private DatabaseHelper dbHelper;
    private SQLiteDatabase db;
    private int id;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        Intent i = getIntent();
        id = i.getIntExtra("id", 0);

        dbHelper = new DatabaseHelper(this);
        db = dbHelper.getWritableDatabase();

        setView();
    }

    private void setView() {
        setContentView(R.layout.activity_contagem);

        LinearLayout ll = findViewById(R.id.contagem_llsv);

        Cursor cursor = db.query(dbHelper.TABLE2_NAME, new String[]{"*"}, dbHelper.TABLE2_COL2 + "=" + id, null, null, null, null, null);
        boolean theresMore = cursor.moveToFirst();
        while (theresMore) {
            LinearLayout row = (LinearLayout) getLayoutInflater().inflate(R.layout.row_contagem, null);

            row.setId(cursor.getInt(0) * 10);

            TextView tv1 = row.findViewById(R.id.row_contagem_date);
            tv1.setId(cursor.getInt(0) * 10 + 1);
            tv1.setText(cursor.getString(2));

            TextView tv2 = row.findViewById(R.id.row_contagem_count);
            tv2.setId(cursor.getInt(0) * 10 + 2);
            tv2.setText(cursor.getString(3));

            Button b = row.findViewById(R.id.row_contagem_remove);
            b.setId(cursor.getInt(0) * 10 + 3);

            ll.addView(row);

            theresMore = cursor.moveToNext();
        }
    }

    public void addContagem(View v) {
        TextView tv = findViewById(R.id.contagem_lbl_count);
        EditText et = findViewById(R.id.contagem_count);
        DatePicker dp = findViewById(R.id.contagem_date);
        Button b = findViewById(R.id.contagem_cancel);

        if (tv.getVisibility() != View.VISIBLE) {
            tv.setVisibility(View.VISIBLE);
            et.setVisibility(View.VISIBLE);
            dp.setVisibility(View.VISIBLE);
            b.setVisibility(View.VISIBLE);

        } else {
            String count = et.getText().toString();
            String date = dp.getDayOfMonth() + "/" +
                    (dp.getMonth() + 1) + "/" +
                    dp.getYear();

            if (!count.equals("")) {
                int c = Integer.valueOf(count);
                ContentValues cv = new ContentValues();
                cv.put(dbHelper.TABLE2_COL2, id);
                cv.put(dbHelper.TABLE2_COL3, date);
                cv.put(dbHelper.TABLE2_COL4, c);
                db.insert(dbHelper.TABLE2_NAME, null, cv);

                setView();

                tv.setVisibility(View.GONE);
                et.setVisibility(View.GONE);
                dp.setVisibility(View.GONE);
                b.setVisibility(View.GONE);
            } else {
                Toast.makeText(this, "Por favor especifique uma contagem", Toast.LENGTH_SHORT).show();
            }
        }
    }

    public void cancelContagem(View v) {
        findViewById(R.id.contagem_lbl_count).setVisibility(View.GONE);
        findViewById(R.id.contagem_count).setVisibility(View.GONE);
        findViewById(R.id.contagem_date).setVisibility(View.GONE);
        findViewById(R.id.contagem_cancel).setVisibility(View.GONE);
    }

    public void removeContagem(View v) {
        System.out.println(v.getId());
        db.delete(dbHelper.TABLE2_NAME, dbHelper.TABLE2_COL1 + "=" + ((v.getId()) - 3) / 10, null);
        setView();
    }
}
