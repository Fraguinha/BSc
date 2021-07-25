/**
 * Equipa
 */
public class Equipa {
    private String nome;

    private ArrayList<Jogador> jogadores;

    public Equipa(String nome) {
        this.nome = nome;
        this.jogadores = new ArrayList<Jogador>();
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public ArrayList<Jogador> getJogadores() {
        return jogadores;
    }

    public void setJogadores(ArrayList<Jogador> jogadores) {
        this.jogadores = jogadores.clone();
    }

    public void inserirJogador(Jogador a) {
        this.jogadores.add(a);
    }

    public void removerJogador(int pos) {
        this.jogadores.remove(pos);
    }

    public int getNumJogadores()     {
        return this.jogadores.size();
    }

    public boolean eJogador(String nome) {
        for (Jogador x : this.jogadores) {
            if (x.nome.equals(nome))
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

    public String toString() {
        String s = "Equipa{nome=" + this.nome + ", jogadores=[\n";

        for (Jogador j : this.jogadores) {
            s += "  " + j.getNome() + "\n";
        }

        s += "]}";

        return s;
    }

    public boolean equals(Object obj) {

        if(this == obj) {
            return true;
        }
        if(obj!=NULL && obj instanceof Equipa)
        {
            Equipa e = (Equipa)obj;
            if(
                this.nome.equals(e.getNome()) &&
                this.jogadores.equals(e.getJogadores())
            ) {
                return true;
            }
        }
        return false;
    }

    public Object clone() {
        Equipa r = new Equipa(this.nome);
        e.setJogadores(this.jogadores);
        return (Object)e;
    }
    
}
