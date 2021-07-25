public class Totoloto2 {

    public static void main(String[] args) {

        int[] chave = new int[6];
        int min = 1, max = 49;
        boolean flag;

        for (int i = 0; i < 6; i++) {

            do {

                flag = false;
                chave[i] = ((int) (Math.random() * max) + min);
                for (int j = 0; j < i; j++) {
                    if (chave[i] == chave[j]) {
                        flag = true;
                    }
                }

            } while (flag);

            System.out.print(chave[i] + " ");

        }

        System.out.println();

    }

}