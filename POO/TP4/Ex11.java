public class Ex11 {

    private static double[] lerVector(int n) {

        double[] v = new double[n];

        for (int i = 0; i < n; i++) {
            v[i] = Ler.umDouble();
        }

        return v;
    }

    private static void printVector(double[] v) {

        for (double i : v) {
            System.out.println(i);
        }

    }

    private static double productoInterno(double[] v, double[] u) {

        double d = 0.0;

        for (int i = 0; i < v.length; i++) {
            d += (v[i] * u[i]);
        }

        return d;
    }

    public static void main(String[] args) {

        System.out.println("Tamanho do vector:");

        int n;
        n = Ler.umInt();

        double[] v = lerVector(n);
        double[] u = lerVector(n);

        printVector(v);
        printVector(u);

        System.out.println(productoInterno(v, u));

    }
}