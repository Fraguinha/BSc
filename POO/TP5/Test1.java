public class Test1 {
    public static void main(String[] args) {

        Contador c = new Contador();

        System.out.println(c);

        int n = Ler.umInt();
        int max = 100;
        min = -100;
        int x;

        Contador pos = new Contador();
        Contador neg = new Contador();

        for (int i = 0; i < n; i++) {

            x = ((int) (Math.random() * max) + min);
            if (x >= 0) {
                pos.incContador();
            } else {
                neg.incContador();
            }

        }

        System.out.println("Positivos: " + pos.showContador());
        System.out.println("Negativos: " + neg.showContador());

    }
}