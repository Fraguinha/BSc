import java.util.ArrayList;

public class TesteAluno {
    public static int contarLicenciatura(ArrayList<Aluno> alunos) {
        int cont = 0;
        for (Aluno a : alunos) {
            if (a instanceof AlunoLicenciatura) {
                cont++;
            }
        }
        return cont;
    }

    public static void main(String[] args) {

        int n;
        ArrayList<Aluno> alunos = new ArrayList<>();
        Disciplina d;
        AlunoLicenciatura a = new AlunoLicenciatura(new Aluno(39970, "Carolina"), "EI");
        alunos.add(a);

        System.out.println("Quantas disciplinas pretende adicionar?");
        n = Ler.umInt();

        for (int i = 0; i < n; i++) {
            System.out.println("Introduza o codigo, nome  e nota da disciplina:");
            d = new Disciplina(Ler.umInt(), Ler.umaString(), Ler.umInt());
            a.addDisciplina(d);
        }
        System.out.println("Introduzao o codigo da disciplina que pretende saber a nota:");
        System.out.println("Nota: " + a.getNotaDisciplinas(Ler.umInt()));

        System.out.println("Média:" + a.mediaLicenciatura());

        System.out.println("Introduza o dados de 1 aluno (numero nome).");

        alunos.add(new Aluno(Ler.umInt(), Ler.umaString()));

        System.out.println("Introduza o dados de 1 aluno de licenciatura (numero nome curso).");

        alunos.add(new AlunoLicenciatura(new Aluno(Ler.umInt(), Ler.umaString()), Ler.umaString()));

        System.out.println("Alunos de licenciatura no arraylist:" + TesteAluno.contarLicenciatura(alunos));
    }
}
