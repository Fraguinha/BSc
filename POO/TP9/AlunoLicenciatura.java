import java.util.ArrayList;
import java.util.Objects;

public class AlunoLicenciatura extends Aluno {

    private String curso;
    private ArrayList<Disciplina> disciplinas;

    public AlunoLicenciatura(Aluno a, String curso) {
        super(a.getNumero(), a.getNome());
        this.curso = curso;
        disciplinas = new ArrayList<Disciplina>();
    }

    public String getCurso() {
        return curso;
    }

    public ArrayList<Disciplina> getDisciplinas() {
        return disciplinas;
    }

    public void setCurso(String curso) {
        this.curso = curso;
    }

    public void setDisciplinas(ArrayList<Disciplina> disciplinas) {
        for (Disciplina d : disciplinas) {
            this.disciplinas.add(d);
        }
    }

    @Override
    public String toString() {
        return "AlunoLicenciatura{" + "curso=" + curso + ", disciplinas=" + disciplinas + '}';
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
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        AlunoLicenciatura other = (AlunoLicenciatura) obj;
        if (!Objects.equals(this.curso, other.curso)) {
            return false;
        }
        if (!Objects.equals(this.disciplinas, other.disciplinas)) {
            return false;
        }
        return true;
    }

    @Override
    public Object clone() {
        Aluno a = new Aluno(super.getNumero(), super.getNome());
        AlunoLicenciatura al = new AlunoLicenciatura(a, this.curso);

        return (Object) al;
    }

    private boolean findDisciplina(Disciplina d) {
        for (Disciplina a : disciplinas) {
            if (a.equals(d)) {
                return true;
            }
        }
        return false;
    }

    public void addDisciplina(Disciplina d) {
        if (!findDisciplina(d)) {
            disciplinas.add(d);
        }
    }

    public int getNotaDisciplinas(int codigo) {
        for (Disciplina a : disciplinas) {
            if (a.getCodigo() == codigo) {
                return a.getNota();
            }
        }
        return 0;
    }

    public float mediaLicenciatura() {
        float sum = 0;
        for (Disciplina a : disciplinas) {
            sum += a.getNota();
        }
        return sum / disciplinas.size();
    }
}
