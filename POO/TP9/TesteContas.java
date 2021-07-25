import java.util.ArrayList;

/**
 * TesteContas
 */
public class TesteContas {

    public static void main(String[] args) {

        int n, saldo, NIB;
        Movimento m;
        ArrayList<Conta> contas = new ArrayList<Conta>();

        ArrayList<String> titulares1 = new ArrayList<String>();
        System.out.println("\nCONTA Nº0\nConta Vencimento\n\nIntroduza o número de titulares da conta:");
        n = Ler.umInt();
        for (int i = 0; i < n; i++) {
            System.out.println("\nIntroduza o nome de um dos titulares:");
            titulares1.add(Ler.umaString());
        }
        System.out.println("Introduza o NIB da conta vencimento:");
        NIB = Ler.umInt();
        System.out.println("Defina o valor com que deseja abrir a conta:");
        saldo = Ler.umInt();

        contas.add(new ContaVencimento(titulares1, saldo, -250, NIB)); // $$$

        ArrayList<String> titulares2 = new ArrayList<String>();
        System.out.println("\nCONTA Nº1\nConta Normal\n\nIntroduza o número de titulares da conta:");
        n = Ler.umInt();
        for (int i = 0; i < n; i++) {
            System.out.println("\nIntroduza o nome de um dos titulares:");
            titulares2.add(Ler.umaString());
        }
        System.out.println("Defina o valor com que deseja abrir a conta:");
        saldo = Ler.umInt();

        contas.add(new Conta(titulares2, saldo));

        ArrayList<String> titulares3 = new ArrayList<String>();
        System.out.println("\nCONTA Nº2\nConta a Prazo\n\nIntroduza o número de titulares da conta:");
        n = Ler.umInt();
        for (int i = 0; i < n; i++) {
            System.out.println("\nIntroduza o nome de um dos titulares:");
            titulares3.add(Ler.umaString());
        }
        System.out.println("Defina o valor com que deseja abrir a conta:");
        saldo = Ler.umInt();

        contas.add(new ContaAPrazo(titulares2, saldo));

        for (Conta c : contas) {
            System.out.println("\n\nConta " + c.getNumero() + ":\nSaldo Inicial: " + c.getSaldo());
            m = new Movimento("Despesas de manutenção", -2);
            System.out.println("Movimento:\n" + m);
            c.novoMovimento(m.getDescricao(), m.getMontante());
            m = new Movimento("Compra de imóvel", -300000);
            System.out.println("Movimento:\n" + m);
            c.novoMovimento(m.getDescricao(), m.getMontante());
            m = new Movimento("Pagamento de Propinas", -1000);
            System.out.println("Movimento:\n" + m);
            c.novoMovimento(m.getDescricao(), m.getMontante());
            m = new Movimento("Depósito de ordenado", 25000000);
            System.out.println("Movimento:\n" + m);
            m = new Movimento("Investimento", -10000000);
            System.out.println("Movimento:\n" + m);
            c.novoMovimento(m.getDescricao(), m.getMontante());
            System.out.println(c.getUltimosMovimentos(5));

            if (c instanceof ContaAPrazo) {
                ContaAPrazo nc = (ContaAPrazo) c;
                nc.addJuros();
            }
            System.out.println("Saldo Final: " + c.getSaldo());
        }

    }
}