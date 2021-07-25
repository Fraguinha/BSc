public class TesteFila {
    public static void main(String[] args) {
        System.out.println("Insira o tamanho da fila :");
        Fila A = new Fila(Ler.umInt());

        while (!A.cheia()) {
            System.out.println("\nIntroduza um elemento na fila:");
            A.inserir(Ler.umInt());
            System.out.println("\nFila: " + A);
        }

        System.out.println("\nRemovemos todos os elementos");
        while (!A.vazia()) {
            A.retirar();
            System.out.println("\nFila: " + A);
        }

    }

}
