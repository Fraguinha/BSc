public class Autocarros {
    public static void main(String[] args) {
        Fila oficina, inspecao, pronto;
        int op;

        oficina = new Fila(20);
        inspecao = new Fila(20);
        pronto = new Fila(20);

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
                if (!inspecao.cheia()) {
                    System.out.println("Insira o numero do autocarro para inspeção:");
                    inspecao.inserir(Ler.umInt());
                    System.out.println("Autocarros para inspeção: " + inspecao);
                    System.out.println("Autocarros na oficina: " + oficina);
                    System.out.println("Autocarros prontos: " + pronto);
                } else {
                    System.out.println("Erro: Inspeção Cheia!");
                }

                break;
            case 2:
                if (!inspecao.vazia()) {
                    if (!oficina.cheia()) {
                        oficina.inserir(inspecao.retirar());
                        System.out.println("Autocarros para inspeção: " + inspecao);
                        System.out.println("Autocarros na oficina: " + oficina);
                        System.out.println("Autocarros prontos: " + pronto);
                    } else {
                        System.out.println("Erro: Oficina Cheia!");
                    }
                } else {
                    System.out.println("Erro: Inspeção Vazia!");
                }
                break;
            case 3:
                if (!oficina.vazia()) {
                    if (!pronto.cheia()) {
                        pronto.inserir(oficina.retirar());
                        System.out.println("Autocarros para inspeção: " + inspecao);
                        System.out.println("Autocarros na oficina: " + oficina);
                        System.out.println("Autocarros prontos: " + pronto);
                    } else {
                        System.out.println("Erro: Pronto Cheia!");
                    }
                } else {
                    System.out.println("Erro: Oficina Vazia!");
                }
                break;
            case 4:
                if (!inspecao.vazia()) {
                    if (!pronto.cheia()) {
                        pronto.inserir(inspecao.retirar());
                        System.out.println("Autocarros para inspeção: " + inspecao);
                        System.out.println("Autocarros na oficina: " + oficina);
                        System.out.println("Autocarros prontos: " + pronto);
                    } else {
                        System.out.println("Erro: Pronto Cheia!");
                    }
                } else {
                    System.out.println("Erro: Inspeção Vazia!");
                }
                break;
            case 5:
                if (!pronto.vazia()) {
                    pronto.retirar();
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