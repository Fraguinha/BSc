public class Ex13 {

    private static int invert(int n) {

        int count = 0;
        int temp = n;
        int m = 0;

        while (temp != 0) {
            temp = temp / 10;
            count++;
        }

        for (int i = count; i >= 0; i--) {
            temp = n % 10;
            m += temp * (int) Math.pow(10, i);
            n = n / 10;
        }

        return m;
    }

    public static void main(String[] args) {

        System.out.println(invert(Ler.umInt()));

    }
}