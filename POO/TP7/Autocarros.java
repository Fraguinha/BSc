public class Autocarros {
    public static void main(String[] args) {

        Fila oficina, inspecao, pronto;
        int op;

        oficina = new Fila();
        inspecao = new Fila();
        pronto = new Fila();

        do {
            System.out.println("Escolha uma opção:");
            System.out.println("1 – Adicionar autocarro para inspeção");
            System.out.println("2 – Autocarro vai para a oficina");
            System.out.println("3 – Autocarro sai da oficina");
            System.out.println("4 – Autocarro operacional");
            System.out.println("5 - Autocarro pronto");
            System.out.println("6 - Sair.");

            op = Ler.umInt();

            switch (op) {
            case 1:
                System.out.println("Insira o numero do autocarro para inspeção:");
                inspecao.inserir(Ler.umInt());
                System.out.println("Autocarros para inspeção: " + inspecao);
                System.out.println("Autocarros na oficina: " + oficina);
                System.out.println("Autocarros prontos: " + pronto);

                break;
            case 2:
                if (!inspecao.estaVazia()) {
                    oficina.inserir(inspecao.remover());
                    System.out.println("Autocarros para inspeção: " + inspecao);
                    System.out.println("Autocarros na oficina: " + oficina);
                    System.out.println("Autocarros prontos: " + pronto);
                } else {
                    System.out.println("Erro: Inspeção Vazia!");
                }
                break;
            case 3:
                if (!oficina.estaVazia()) {
                    pronto.inserir(oficina.remover());
                    System.out.println("Autocarros para inspeção: " + inspecao);
                    System.out.println("Autocarros na oficina: " + oficina);
                    System.out.println("Autocarros prontos: " + pronto);
                } else {
                    System.out.println("Erro: Oficina Vazia!");
                }
                break;
            case 4:
                if (!inspecao.estaVazia()) {
                    pronto.inserir(inspecao.remover());
                    System.out.println("Autocarros para inspeção: " + inspecao);
                    System.out.println("Autocarros na oficina: " + oficina);
                    System.out.println("Autocarros prontos: " + pronto);
                } else {
                    System.out.println("Erro: Inspeção Vazia!");
                }
                break;
            case 5:
                if (!pronto.estaVazia()) {
                    pronto.remover();
                    System.out.println("Autocarros para inspeção: " + inspecao);
                    System.out.println("Autocarros na oficina: " + oficina);
                    System.out.println("Autocarros prontos: " + pronto);
                } else {
                    System.out.println("Erro: Pronto Vazia!");
                }

            }
        } while (op != 6);
    }
}
