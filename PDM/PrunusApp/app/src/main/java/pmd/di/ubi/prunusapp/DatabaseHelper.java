package pmd.di.ubi.prunusapp;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class DatabaseHelper extends SQLiteOpenHelper {

    private static final String DB_NAME = "PrunusAppDB";
    private static final int DB_VERSION = 1;

    protected static final String TABLE1_NAME = "pessegueiro";
    protected static final String TABLE1_COL1 = "id";
    protected static final String TABLE1_COL2 = "name";
    protected static final String TABLE1_COL3 = "info";

    protected static final String TABLE2_NAME = "contagem";
    protected static final String TABLE2_COL1 = "id";
    protected static final String TABLE2_COL2 = "fk";
    protected static final String TABLE2_COL3 = "date";
    protected static final String TABLE2_COL4 = "count";

    private static final String CREATE_TABLE1 = "CREATE TABLE " + TABLE1_NAME + "(" +
            TABLE1_COL1 + " INTEGER, " +
            TABLE1_COL2 + " VARCHAR(80), " +
            TABLE1_COL3 + " VARCHAR(280), " +
            "PRIMARY KEY (" + TABLE1_COL1 + "));";

    private static final String CREATE_TABLE2 = "CREATE TABLE " + TABLE2_NAME + "(" +
            TABLE2_COL1 + " INTEGER, " +
            TABLE2_COL2 + " INTEGER, " +
            TABLE2_COL3 + " VARCHAR(80), " +
            TABLE2_COL4 + " INTEGER, " +
            "PRIMARY KEY (" + TABLE2_COL1 + ")" +
            "FOREIGN KEY (" + TABLE2_COL2 + ")" + " REFERENCES " + TABLE1_NAME + "(" + TABLE1_COL1 + "));";

    public DatabaseHelper(Context context) {
        super(context, DB_NAME, null, DB_VERSION);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL(CREATE_TABLE1);
        db.execSQL(CREATE_TABLE2);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL("DROP TABLE " + TABLE1_NAME + ", " + TABLE2_NAME + ";");
        db.execSQL(CREATE_TABLE1);
        db.execSQL(CREATE_TABLE2);
    }
}
