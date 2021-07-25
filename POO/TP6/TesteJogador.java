public class TesteJogador {

    public static void main(String[] args) {
        Jogador a = new Jogador("Carolina");
        Jogador b = new Jogador("Ana", 10000);
        Jogador c = new Jogador();

        int[] golos = new int[34];

        a.setSalario(750);
        c.setNome("Pedro");
        c.setSalario(500);

        for (int i = 0; i < 34; i++) {
            golos[i] = (int) (Math.random() * 10);
        }

        c.setGolos(golos);

        for (int i = 0; i < 34; i++) {
            golos[i] = (int) (Math.random() * 7);
        }

        a.setGolos(golos);

        for (int i = 0; i < 34; i++) {
            golos[i] = (int) (Math.random() * 15);
        }

        b.setGolos(golos);

        System.out.println("Nome: " + a.getNome() + " Salario: " + a.getSalario());
        for (int i = 0; i < 34; i++) {
            System.out.println("\nJornada " + (i + 1) + " Golos: " + a.consultarGoloN(i));
        }

        System.out.println("Qual o aumento salarial de b?");
        b.aumentarSalario(Ler.umFloat());

        System.out.println("Altere o numero de golos da 3 Jornada de " + a.getNome());
        a.modificarGoloN(Ler.umInt(), 3);

        System.out.println(a.toString());
        System.out.println(b.toString());
        System.out.println(c.toString());

    }
}