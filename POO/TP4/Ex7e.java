public class Ex7e {

    public static void main(String[] args) {

        int p, u;

        System.out.println("P:");
        p = Ler.umInt();

        do {
            System.out.println("P:");
            u = Ler.umInt();
        } while (u < p);

        int soma = 0;

        for (int i = p; i <= u; i++) {
            soma += i;
        }

        System.out.println("Somatorio: " + soma);

    }
}