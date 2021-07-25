public class Ex7a {

    public static void main(String[] args) {

        int p, u;
        System.out.println("P:");
        p = Ler.umInt();
        System.out.println("P:");
        u = Ler.umInt();

        int soma = 0;

        for (int i = p; i <= u; i++) {
            soma += i;
        }

        System.out.println("Somatorio: " + soma);

    }
}