public class Jogador {

    private String nome;
    private double salario;
    private int[] golos = new int[34];

    Jogador() {
        this.nome = "";
        this.salario = 0;
        for (int i = 0; i < 34; i++) {
            golos[i] = 0;
        }
    }

    Jogador(String nome) {
        this.nome = nome;
        this.salario = 0;
        for (int i = 0; i < 34; i++) {
            golos[i] = 0;
        }
    }

    Jogador(String nome, double salario) {
        this.nome = nome;
        this.salario = salario;
        for (int i = 0; i < 34; i++) {
            golos[i] = 0;
        }
    }

    protected String getNome() {
        return this.nome;
    }

    protected double getSalario() {
        return this.salario;
    }

    protected int[] getGolos() {
        return golos;
    }

    protected void setNome(String nome) {
        this.nome = nome;
    }

    protected void setSalario(double salario) {
        this.salario = salario;
    }

    protected void setGolos(int[] golos) {
        for (int i = 0; i < 34; i++) {
            this.golos[i] = golos[i];
        }
    }

    protected void aumentarSalario(double percentagem) {
        this.salario = this.salario * (percentagem / 100) + this.salario;
    }

    protected void modificarGoloN(int golos, int n) {
        this.golos[n] = golos;
    }

    protected int consultarGoloN(int n) {
        return this.golos[n];
    }

    public String toString() {
        String s = "Nome: " + this.nome + " Salario: " + this.salario;
        for (int i = 0; i < 34; i++) {
            s += "\nJornada " + (i + 1) + " Golos: " + this.golos[i];
        }
        return s;
    }
}