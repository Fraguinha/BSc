/**
 * TesteBase
 */
public class TesteBase {

    public static void main(String[] args) {
        Base a = new Base(1, 2);

        if (a.soma() == 3)
            System.out.println("OK");

        if (a.soma(1) == 4)
            System.out.println("OK");

        Base b = (Base) a.clone();

        if (a.equals(b))
            System.out.println("OK");

        System.out.println(a);

    }
}