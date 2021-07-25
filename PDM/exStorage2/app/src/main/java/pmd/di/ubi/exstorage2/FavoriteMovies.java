package pmd.di.ubi.exstorage2;


import android.app.Activity;
import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;


public class FavoriteMovies extends Activity {
    private SQLiteDatabase oSQLiteDB;
    private AjudanteParaAbrirBD oAPABD;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_favoritemovies);

        oAPABD = new AjudanteParaAbrirBD(this);
        oSQLiteDB = oAPABD.getWritableDatabase();


        LinearLayout oLL = findViewById(R.id.llsv);



        Cursor oCursor = oSQLiteDB.query(oAPABD.TABLE_NAME, new String[]{"*"}, null,
                null, null, null, null, null);




        boolean bCarryOn = oCursor.moveToFirst();
        while (bCarryOn)    {
            LinearLayout oLL1 = (LinearLayout) getLayoutInflater().inflate(R.layout.line, null);

            oLL1.setId(oCursor.getInt( 0)*10+4);

            EditText oED1 = oLL1.findViewById(R.id.ED1);
            oED1.setId( oCursor . getInt (0)*10+2);
            oED1.setText(oCursor.getString(1));

            EditText oED2 = oLL1.findViewById(R.id.ED2);
            oED2.setId(oCursor.getInt(0)*10+3) ;
            oED2.setText(oCursor.getInt(2)+"");

            Button oB1 = oLL1.findViewById(R.id.EDIT);
            oB1.setId(oCursor.getInt(0)*10+1);

            Button oB2 = oLL1.findViewById(R.id.DEL);
            oB2.setId((int)oCursor.getInt(0)*10);

            oLL.addView(oLL1);
            bCarryOn = oCursor.moveToNext();
        }
    }

    @Override
    protected void onResume() {
        super.onResume();
        oSQLiteDB = oAPABD.getWritableDatabase();
    }

    @Override
    protected void onPause() {
        super.onPause();
        oAPABD.close();
    }

    public void onINSERTclick(View v){
        ContentValues oCV = new ContentValues();
        EditText oED1 = (EditText)findViewById(R.id.name);
        EditText oED2 = (EditText)findViewById(R.id.year);
        oCV.put(oAPABD.COL2, oED1.getText().toString());
        oCV.put(oAPABD.COL3, oED2.getText().toString());
        oSQLiteDB.insert(oAPABD.TABLE_NAME, null, oCV);
    }


    public void onDELclick (View v) {
        int rid = v.getId()/10;
        oSQLiteDB.delete(oAPABD.TABLE_NAME,"ROWID="+rid,null);
        System.out.println(rid);
        LinearLayout oLL1 = findViewById((v.getId())+4);
        ((LinearLayout) oLL1.getParent()).removeView(oLL1);
    }

    public void onEDITclick(View v) {
        ContentValues oCV = new ContentValues();
        EditText ED1 = findViewById((v.getId())+1);
        oCV.put(oAPABD.COL2, ED1.getText().toString());
        EditText ED2 = findViewById(v.getId()+2);
        oCV.put(oAPABD.COL3, ED2.getText().toString());

        oSQLiteDB.update(oAPABD.TABLE_NAME, oCV,"ROWID="+((v.getId() -1)/10), null);
    }
}
