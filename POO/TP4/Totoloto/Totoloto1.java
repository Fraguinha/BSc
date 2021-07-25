public class Totoloto1 {

    public static void main(String[] args) {

        System.out.println("Introduza uma chave de totoloto");

        int[] chave = new int[6];

        for (int i = 0; i < 6; i++) {

            do {

                chave[i] = Ler.umInt();

            } while (chave[i] < 1 || chave[i] > 49);

        }
    }

}