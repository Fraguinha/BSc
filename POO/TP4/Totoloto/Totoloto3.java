public class Totoloto3 {

    public static void main(String[] args) {

        int[] chave = new int[6];
        int min = 1, max = 49;
        boolean flag;
        int n;

        System.out.println("Introduza o numero de chaves:");
        n = Ler.umInt();

        for (int j = 0; j < n; j++) {

            for (int i = 0; i < 6; i++) {

                do {

                    flag = false;
                    chave[i] = ((int) (Math.random() * max) + min);
                    for (int k = 0; k < i; k++) {
                        if (chave[i] == chave[k]) {
                            flag = true;
                        }
                    }

                } while (flag);

                System.out.print(chave[i] + " ");

            }

            System.out.println();
        }

    }
}