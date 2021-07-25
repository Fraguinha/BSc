import javax.swing.undo.UndoManager;

public class GerirEmpregados {

    public static void main(String[] args) {
        int op, pos, segSocial = 0, salario = 0;
        Empregado temp = new Empregado();
        String nome = "";
        ArrayList<Empregado> empresa = new ArrayList<Empregado>();
        do {
            System.out.println("Escolha uma opção:");
            System.out.println("1 – Criar empregado");
            System.out.println("2 – Consultar todos os empregados");
            System.out.println("3 – Modificar um empregado");
            System.out.println("4 – Apagar um empregado");
            System.out.println("5 - Sair.");

            op = Ler.umInt();
            switch (op) {
            case 1:

                System.out.println("Numero de segurança social:");
                segSocial = Ler.umInt();
                System.out.println("Nome:");
                nome = Ler.umaString();
                empresa.add(new Empregado(segSocial, nome));
                break;
            case 2:
                for (Empregado e : empresa) {
                    System.out.println(e);
                }
                break;
            case 3:
                System.out.println("Introduza o numero de s social do empregado a alterar");
                temp.setSegSocial(Ler.umInt());
                for (Empregado e : empresa) {
                    if (e.equals(temp)) {
                        System.out.println("Introduza o novo nome: ");
                        e.setNome(Ler.umaString());

                        System.out.println("Introduza o novo salario:");
                        e.setSalario(Ler.umInt());
                    }
                }
                break;
            case 4:
                System.out.println("Introduza o numero de s social do empregado a alterar");
                temp.setSegSocial(Ler.umInt());
                for (Empregado e : empresa) {
                    if (e.equals(temp)) {
                        empresa.remove(e);
                    }
                }

                break;
            }
        } while (op != 5);

    }
}
