public class TesteFila {
    public static void main(String[] args) {

        Fila A = new Fila();

        for (int i = 0; i < 3; i++) {
            System.out.println("\nIntroduza um elemento na fila:");
            A.inserir(Ler.umInt());
        }

        System.out.println("\nFila: " + A);

        System.out.println("\nRemovemos todos os elementos");
        while (!A.estaVazia()) {
            A.remover();
            System.out.println("\nFila: " + A);
        }

        System.out.println("\nFila: " + A);

    }

}