public class Ex12 {

    private static int[][] lerMatrix(int n, int m) {

        int[][] matrix = new int[n][m];

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {
                matrix[i][j] = Ler.umInt();
            }

        }

        return matrix;

    }

    private static int countImpar(int[][] matrix) {

        int count = 0;

        for (int[] i : matrix) {

            for (int j : i) {

                if (j % 2 != 0) {
                    count++;
                }
            }

        }

        return count;

    }

    private static int[][] transposta(int[][] matrix) {

        int[][] transposta = new int[matrix[0].length][matrix.length];

        for (int i = 0; i < matrix.length; i++) {

            for (int j = 0; j < matrix[i].length; j++) {

                transposta[j][i] = matrix[i][j];

            }

        }

        return transposta;

    }

    public static void main(String[] args) {

        int[][] m = lerMatrix(2, 3);

        System.out.println(countImpar(m));

        int[][] t = transposta(m);

        for (int[] i : t) {

            for (int j : i) {

                System.out.print(j + " ");

            }

            System.out.println();
        }

    }
}