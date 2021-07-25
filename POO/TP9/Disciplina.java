public class Disciplina {
    private int codigo;
    private String designacao;
    private int nota;

    public Disciplina(int codigo, String designacao, int nota) {
        this.codigo = codigo;
        this.designacao = designacao;
        this.nota = nota;
    }

    public int getCodigo() {
        return codigo;
    }

    public String getDesignacao() {
        return designacao;
    }

    public int getNota() {
        return nota;
    }

    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    public void setDesignacao(String designacao) {
        this.designacao = designacao;
    }

    public void setNota(int nota) {
        this.nota = nota;
    }

    @Override
    public String toString() {
        return "Disciplina{" + "codigo=" + codigo + ", designacao=" + designacao + ", nota=" + nota + '}';
    }

    @Override
    public int hashCode() {
        int hash = 5;
        return hash;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj != null && obj instanceof Disciplina) {
            final Disciplina other = (Disciplina) obj;
            if (this.codigo == other.codigo && this.designacao.equals(other.getDesignacao())) {
                return true;
            }
        }
        return false;
    }

    @Override
    public Object clone() {
        Disciplina d = new Disciplina(this.codigo, this.designacao, this.nota);

        return (Object) d;
    }
    /* Construtor de cópia?? */
}
