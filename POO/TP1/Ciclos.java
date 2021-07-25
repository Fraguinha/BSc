public class Ciclos {
    public static void main(String[] args) {

        int x = 0;

        for (int i = 1; i <= 100; i++) {

            System.out.print(i + " ");

        }
        System.out.println();

        while (x <= 100) {

            System.out.print(x + " ");
            x++;

        }
        System.out.println();

        x = 0;

        do {

            System.out.print(x + " ");
            x++;

        } while (x <= 100);
        System.out.println();

        int y = 100;

        for (int i = 100; i > 0; i--) {

            System.out.print(i + " ");

        }
        System.out.println();

        while (y > 0) {

            System.out.print(y + " ");
            y--;

        }
        System.out.println();

        y = 100;

        do {

            System.out.print(y + " ");
            y--;

        } while (y > 0);
        System.out.println();

        int sum = 0;
        double prod = 1;

        for (int i = 1; i <= 100; i++) {

            sum = sum + i;

        }
        System.out.println("Soma=" + sum);

        for (int i = 1; i <= 100; i++) {

            prod = prod * i;

        }
        System.out.println("Produto=" + prod);

        sum = 0;

        for (int i = 1; i <= 100; i += 2) {

            sum = sum + i;

        }
        System.out.println("Soma=" + sum);
    }
}
