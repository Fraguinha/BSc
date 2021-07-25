import java.util.*;

public class Ex2 {
    public static void main(String[] args) {

        Scanner keyboard = new Scanner(System.in);
        System.out.println("Digite um número ");

        int num = keyboard.nextInt();
        System.out.println("o número digitado: " + num);

        String s = keyboard.nextLine();
        System.out.println(s);

        double d = keyboard.nextDouble();
        System.out.println(d);

        boolean b = keyboard.nextBoolean();
        System.out.println(b);

        keyboard.close();
    }
}