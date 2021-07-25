public class Empregado {

    private int num;
    private String nome;
    private int salario;

    public int getNum() {
        return this.num;
    }

    public String getNome() {
        return this.nome;
    }

    public int getSalario() {
        return this.salario;
    }

    public void setNum(int n) {
        this.num = n;
    }

    public void setNome(String s) {
        this.nome = s;
    }

    public void setSalario(int n) {
        this.salario = n;
    }

    public Empregado() {
        this.num = 0;
        this.nome = "";
        this.salario = 0;
    }

    public Empregado(int n, String s) {
        this.num = n;
        this.nome = s;
    }

    public Empregado(int n, String s, int n2) {
        this.num = n;
        this.nome = s;
        this.salario = n2;
    }

    public String toString() {
        return "Num: " + this.num + " Nome: " + this.nome + " Salario: " + this.salario;
    }

    public void incSalario(float per) {
        this.salario = this.salario + (this.salario * per);
    }

}