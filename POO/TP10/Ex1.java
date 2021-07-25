import java.io.IOException;

public class Ex1 {

    private static String leStr() {
        int ch;
        String r = "";
        boolean fim = false;
        while (!fim) {
            try {
                ch = System.in.read();
                if (ch < 0 || (char) ch == '\n')
                    fim = true;
                else
                    r = r + (char) ch;
            } catch (java.io.IOException e) {
                fim = true;
            }
        }
        return r;
    }

    public static void main(String[] args) {
        int index = 0;
        String palavra = " ";
        String[] tabPal = new String[10];
        System.out.print("Introduza uma palavra: ");

        palavra = leStr();

        while (!palavra.equalsIgnoreCase("fim")) {

            boolean flag = true;
            while (flag) {
                System.out.print("Introduza um índice: ");
                try {
                    index = Integer.valueOf(leStr().trim()).intValue();
                } catch (NumberFormatException e) {
                    System.out.println("Introduza um valor inteiro!");
                }

                try {
                    tabPal[index] = palavra;
                    flag = false;
                } catch (ArrayIndexOutOfBoundsException e) {
                    System.out.println(" 0 <= índice <= 9");
                }
            }

            System.out.print("Introduza uma palavra");
            System.out.println("(para terminar escreva fim): ");
            palavra = leStr();

        }
    }
}
