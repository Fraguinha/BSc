public class Empregado {
    private int segSocial;
    private String nome;
    private float salario;

    public Empregado() {
        segSocial = 0;
        nome = "";
        salario = (float) 500;
    }

    public Empregado(int segSocial, String nome) {
        this.segSocial = segSocial;
        this.nome = nome;
        this.salario = (float) 500;
    }

    public int getSegSocial() {
        return segSocial;
    }

    public String getNome() {
        return nome;
    }

    public float getSalario() {
        return salario;
    }

    public static int getNumEmpregados() {
        return numEmpregados;
    }

    public void setSegSocial(int segSocial) {
        this.segSocial = segSocial;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setSalario(float salario) {
        this.salario = salario;
    }

    public String toString() {
        String s = "Nº segurança social: " + segSocial + "Nome: " + nome + "Salario" + salario;
        return s;
    }

    public void aumentarSalario(float percentagem) {
        salario = salario + (salario * percentagem);
    }

    public static void apagarEmpregado() {
        numEmpregados--;
    }

    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        
        if (obj != null && obj instanceof Empregado) {
            Empregado e = (Empregado) obj;
            if(this.segSocial = e.getSegSocial()) {
                return true;
            }
        }
        return false;
    }

    public Object clone() {
        Jogador j = new Jogador(this.segSocial, this.nome);
        j.setSalario(this.salario);
        return (Object) j;
    }
}