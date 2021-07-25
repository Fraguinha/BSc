public class Test3 {

    public static void main(String[] args) {

        CadeirasCriticas c1 = new CadeirasCriticas("Engenharia Informatica");
        CadeirasCriticas c2 = new CadeirasCriticas("Informatica Web");

        System.out.println(c1.getNomeCurso());
        System.out.println(c1.getDiciplinas());

        System.out.println(c1);
        System.out.println(c2);
    }

}