/**
 * TesteDerivada
 */
public class TesteDerivada {

    public static void main(String[] args) {
        Base b = new Base(1, 2);

        Derivada d = new Derivada(b, 2, 3);

        System.out.println("2+2+3=" + d.soma());

        if (d.equals(d.clone())) {
            System.out.println("OK");
        }

        System.out.println(x);
    }
}