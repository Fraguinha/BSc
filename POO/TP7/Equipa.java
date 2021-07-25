import java.util.ArrayList;

public class Equipa {

    private String nome;
    private ArrayList<Jogador> jogadores;

    public String getNome() {
        return this.nome;
    }

    public ArrayList<Jogador> getJogadores() {
        return this.jogadores;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setJogadores(ArrayList<Jogador> jogadores) {
        this.jogadores = jogadores;
    }

    public Equipa(String nome) {
        this.nome = nome;
        this.jogadores = new ArrayList<Jogador>();
    }

    public String toString() {

        String s = "Equipa{nome=" + this.nome + ", jogadores=[\n";

        for (Jogador j : this.jogadores) {
            s += "  " + j.getNome() + "\n";
        }

        s += "]}";

        return s;
    }

    // vê isto (é uma forma mais eficiente (e intuitiva) de fazer o equals do que a
    // que a que o prof deu)
    public boolean equals(Object obj) {

        if (this == obj)
            return true;

        if (obj != null && obj instanceof Equipa) {
            Equipa e = (Equipa) obj;
            if (this.nome.equals(e.nome) && this.jogadores.equals(e.jogadores))
                return true;
        }

        return false;
    }

    public Object clone() {

        Equipa e = new Equipa(this.nome);

        e.setJogadores(this.getJogadores());

        return e;
    }

    public void inserirJogador(Jogador j) {
        this.jogadores.add(j);
    }

    public void removerJogadorI(int i) {
        this.jogadores.remove(i);
    }

    public int getNumJogadores() {
        return this.jogadores.size();
    }

    public boolean eJogador(Jogador j) {
        for (Jogador x : this.jogadores) {
            if (x.equals(j))
                return true;
        }
        return false;
    }

    public String melhorJogador() {

        String nome = "";
        int max = 0;
        int golos;

        for (Jogador x : this.jogadores) {
            golos = 0;
            for (int i : x.getGolos()) {
                golos += i;
            }
            if (golos > max) {
                nome = x.getNome();
                max = golos;
            }
        }

        return nome;
    }

}