public class Ex3 {
    public static void main(String[] args) throws java.io.IOException // !!!!
    {
        char c;
        int i;
        System.out.print("Introduza um caráter pelo teclado: ");
        i = System.in.read();
        System.out.println("O código ASII do caráter que introduziu é : " + i);
        c = (char) i;
        System.out.println("O caráter que introduziu foi: " + c);
    }
}
