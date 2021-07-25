package pmd.di.ubi.exstorage2;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class AjudanteParaAbrirBD extends SQLiteOpenHelper {
    private static final int DB_VERSION = 2;
    private  static final String DB_NAME = "FavoriteMovies";
    protected static final String TABLE_NAME = "Movie";
    protected static final String COL1 = "id";
    protected static final String COL2 = "name";
    protected static final String COL3 = "year";

    private static final String CREATE_MOVIE = "CREATE TABLE " + TABLE_NAME + "(" +
            COL1 + " INTEGER PRIMARY KEY, " +
            COL2 + " VARCHAR(50), " +
            COL3 + " INTEGER);";

    public AjudanteParaAbrirBD(Context context) {
        super(context, DB_NAME, null, DB_VERSION);
        System.out.println(CREATE_MOVIE);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL(CREATE_MOVIE);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL("DROP TABLE " + TABLE_NAME + ";");
        db.execSQL(CREATE_MOVIE);
    }
}
