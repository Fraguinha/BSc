public class CadeirasCriticas {

    private String nomeCurso;
    private String[] disciplinas;

    public String getNomeCurso() {
        return this.nomeCurso;
    }

    public String[] getDiciplinas() {
        return this.disciplinas;
    }

    public void setNomeCurso(String s) {
        this.nomeCurso = s;
    }

    public void setDisciplinas(String[] s) {
        this.disciplinas = s;
    }

    public void setDisciplinasIndex(String s, int i) {
        this.disciplinas[i] = s;
    }

    public CadeirasCriticas() {
        this.nomeCurso = "";
        this.disciplinas = new String[3];
        for (int i = 0; i < 3; i++) {
            this.disciplinas[i] = "";
        }
    }

    public CadeirasCriticas(String nc) {
        this.nomeCurso = nc;
        this.disciplinas = new String[3];
        for (int i = 0; i < 3; i++) {
            this.disciplinas[i] = "";
        }
    }

    public String toString() {
        return "Nome Curso: " + this.nomeCurso + " Disciplina 1: " + this.disciplinas[0] + " Disciplina 2: "
                + this.disciplinas[1] + " Disciplina 3: " + this.disciplinas[2];
    }

}