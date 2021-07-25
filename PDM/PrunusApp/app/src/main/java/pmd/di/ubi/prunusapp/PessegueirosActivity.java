package pmd.di.ubi.prunusapp;

import android.app.Activity;
import android.content.ContentValues;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

public class PessegueirosActivity extends Activity {

    private DatabaseHelper dbHelper;
    private SQLiteDatabase db;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        dbHelper = new DatabaseHelper(this);
        db = dbHelper.getWritableDatabase();

        setView();
    }

    private void setView() {
        setContentView(R.layout.activity_pessegueiros);

        LinearLayout ll = findViewById(R.id.pessegueiro_llsv);

        Cursor cursor = db.query(dbHelper.TABLE1_NAME, new String[]{"*"}, null, null, null, null, null, null);
        boolean theresMore = cursor.moveToFirst();
        while (theresMore) {
            LinearLayout row = (LinearLayout) getLayoutInflater().inflate(R.layout.row_pessegueiro, null);

            row.setId(cursor.getInt(0) * 10);

            TextView tv = row.findViewById(R.id.row_pessegueiro_name);
            tv.setId(cursor.getInt(0) * 10 + 1);
            tv.setText(cursor.getString(1));

            Button b1 = row.findViewById(R.id.row_pessegueiro_contagem);
            b1.setId(cursor.getInt(0) * 10 + 2);

            Button b2 = row.findViewById(R.id.row_pessegueiro_remove);
            b2.setId(cursor.getInt(0) * 10 + 3);

            ll.addView(row);

            theresMore = cursor.moveToNext();
        }
    }

    public void addPessegueiro(View v) {
        TextView tv1 = findViewById(R.id.pessegueiro_lbl_name);
        TextView tv2 = findViewById(R.id.pessegueiro_lbl_info);
        EditText et1 = findViewById(R.id.pessegueiro_name);
        EditText et2 = findViewById(R.id.pessegueiro_info);
        Button b = findViewById(R.id.pessegueiro_cancel);

        if (tv1.getVisibility() != View.VISIBLE) {
            tv1.setVisibility(View.VISIBLE);
            tv2.setVisibility(View.VISIBLE);
            et1.setVisibility(View.VISIBLE);
            et2.setVisibility(View.VISIBLE);
            b.setVisibility(View.VISIBLE);
        } else {
            String name = et1.getText().toString();
            String info = et2.getText().toString();

            if (!name.equals("")) {
                ContentValues cv = new ContentValues();
                cv.put(dbHelper.TABLE1_COL2, name);
                cv.put(dbHelper.TABLE1_COL3, info);
                db.insert(dbHelper.TABLE1_NAME, null, cv);

                setView();

                tv1.setVisibility(View.GONE);
                tv2.setVisibility(View.GONE);
                et1.setVisibility(View.GONE);
                et2.setVisibility(View.GONE);
                b.setVisibility(View.GONE);
            } else {
                Toast.makeText(this, "Por favor especifique um nome", Toast.LENGTH_SHORT).show();
            }
        }
    }

    public void cancelPessegueiro(View v) {
        findViewById(R.id.pessegueiro_lbl_name).setVisibility(View.GONE);
        findViewById(R.id.pessegueiro_lbl_info).setVisibility(View.GONE);
        findViewById(R.id.pessegueiro_name).setVisibility(View.GONE);
        findViewById(R.id.pessegueiro_info).setVisibility(View.GONE);
        findViewById(R.id.pessegueiro_cancel).setVisibility(View.GONE);
    }

    public void goToContagens(View v) {
        Intent i = new Intent(this, ContagemActivity.class);
        i.putExtra("id", (v.getId()) / 10);
        startActivity(i);
    }

    public void removePessegueiro(View v) {
        db.delete(dbHelper.TABLE1_NAME, dbHelper.TABLE1_COL1 + "=" + (v.getId()) / 10, null);
        db.delete(dbHelper.TABLE2_NAME, dbHelper.TABLE2_COL2 + "=" + (v.getId()) / 10, null);
        setView();
    }
}
