public class Ex1 {
    public static void main(String[] args) {
        System.out.println("5+3=" + (5 + 3));
        System.out.println("5-3=" + (5 - 3));
        System.out.println("5*3=" + (5 * 3));
        System.out.println("5/3=" + (5 / 3));
        System.out.println("5%3=" + (5 % 3));

        int a = 2;
        int b = 3;
        int c = 4;

        System.out.println("a=" + (a++));
        System.out.println("a=" + (++a));

        b /= 3;
        System.out.println("b=" + b);

        c += 1;
        System.out.println("c=" + c);
    }
}