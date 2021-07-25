import java.util.ArrayList;

public class Ex1 {
    public static void main(String[] args) {

        ArrayList<String> lista = new ArrayList<String>();

        lista.add("Maria");
        lista.add("João");

        String s = lista.get(0);

        System.out.println(lista.toString() + "," + s);

    }
}
