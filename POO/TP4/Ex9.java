public class Ex9 {

    private static int maior(int a, int b, int c) {

        return (a > b && a > c ? a : (b > c ? b : c));
    }

    public static void main(String[] args) {

        System.out.println(maior(Ler.umInt(), Ler.umInt(), Ler.umInt()));

    }
}