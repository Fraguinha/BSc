public class Ex7b {

    public static void main(String[] args) {

        int p, u;
        System.out.println("P:");
        p = Ler.umInt();
        System.out.println("P:");
        u = Ler.umInt();

        int soma = 0;

        while (p <= u) {
            soma += p;
            p++;
        }

        System.out.println("Somatorio: " + soma);

    }
}