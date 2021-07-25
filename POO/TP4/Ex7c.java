public class Ex7c {

    public static void main(String[] args) {

        int p, u;
        System.out.println("P:");
        p = Ler.umInt();
        System.out.println("P:");
        u = Ler.umInt();

        int soma = 0;

        do {
            soma += p;
            p++;
        } while (p <= u);

        System.out.println("Somatorio: " + soma);

    }
}