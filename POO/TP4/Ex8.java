public class Ex8a {
    public static void main(String[] args) {

        int a, b, c;

        a = Ler.umInt();
        b = Ler.umInt();
        c = Ler.umInt();

        System.out.println(a > b && a > c ? a : (b > c ? b : c));
    }
}