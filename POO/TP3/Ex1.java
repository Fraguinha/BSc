import java.io.*;

public class Ex1 {

    public static void main(String[] args) throws IOException {

        BufferedReader Scanner;
        Scanner = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("Escreva um inteiro: ");

        String s = Scanner.readLine();
        System.out.println(s);

        int i = Integer.parseInt(s);
        System.out.println(i);

        String t = Scanner.readLine();
        double d = Double.parseDouble(t);
        System.out.println(d);

        String v = Scanner.readLine();
        boolean b = Boolean.parseBoolean(v);
        System.out.println(b);

        System.out.println("O inteiro foi: " + i);
    }
}