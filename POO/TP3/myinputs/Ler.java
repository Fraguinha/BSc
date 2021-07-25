import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;

public class Ler {

    public static String umaString() {

        String s = "";

        try {

            BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
            s = in.readLine();

        } catch (IOException e) {

            System.out.println(e);

        }

        return s;
    }

    public static int umInt() {

        while (true) {

            try {

                return Integer.parseInt(umaString().trim());

            } catch (NumberFormatException e) {

                System.out.println(e);

            }
        }
    }

    public static double umDouble() {

        while (true) {

            try {

                return Double.parseDouble(umaString().trim());

            } catch (NumberFormatException e) {

                System.out.println(e);

            }
        }
    }

    public static float umFloat() {

        while (true) {

            try {

                return Float.parseFloat(umaString().trim());

            } catch (NumberFormatException e) {

                System.out.println(e);

            }
        }
    }

    public static boolean umBoolean() {

        return Boolean.parseBoolean(umaString().trim());

    }

    public static char umChar() {

        char c = ' ';

        try {

            BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
            c = (char) (in.read());

        } catch (IOException e) {

            System.out.println(e);

        }

        return c;
    }

    public static byte umByte() {

        while (true) {

            try {

                return Byte.parseByte(umaString().trim());

            } catch (NumberFormatException e) {

                System.out.println(e);

            }
        }
    }

    public static short umShort() {

        while (true) {

            try {

                return Short.parseShort(umaString().trim());

            } catch (NumberFormatException e) {

                System.out.println(e);

            }
        }
    }

    public static long umLong() {

        while (true) {

            try {

                return Long.parseLong(umaString().trim());

            } catch (NumberFormatException e) {

                System.out.println(e);

            }
        }
    }
}