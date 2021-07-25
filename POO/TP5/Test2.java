import java.util.ArrayList;

public class Test2 {

    private static ArrayList<Empregado> lista = new ArrayList<>();

    public static void criarEmpregado() {

        String nome = Ler.umaString();
        int num = Ler.umInt();
        int sal = Ler.umInt();

        lista.add(new Empregado(num, nome, sal));

    }

    public static void consultarEmpregado() {

    }

    public static void modificarEmpregado() {

        lista.get(lista.indexOf(e)).setNum(num);
        lista.get(lista.indexOf(e)).setNome(nome);
        lista.get(lista.indexOf(e)).setSalario(s);

    }

    public static void apagarEmpregado() {
        lista.remove(e);
    }

    public static void main(String[] args) {

        boolean exit = false;
        int i;

        do {

            System.out.println("1 - Criar empregado");
            System.out.println("2 - Consultar empregados");
            System.out.println("3 - Modificar empregados");
            System.out.println("4 - Apagar um empregado");
            System.out.println("0 - Sair");

            i = Ler.umInt();

            switch (i) {
            case 0:
                exit = true;
                break;
            case 1:
                criarEmpregado();
                break;
            case 2:
                consultarEmpregado();
                break;
            case 3:
                modificarEmpregado();
                break;
            case 4:
                apagarEmpregado();
                break;

            }

        } while (exit != true);
    }
}