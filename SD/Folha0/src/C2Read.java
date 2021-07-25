import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;

public class C2Read {

  public static void main(String[] args) {
    try (Scanner sc = new Scanner(new FileReader("teste2.txt"))) {
      System.out.println(sc.nextFloat());
      System.out.println(sc.nextBoolean());
      System.out.println(sc.next());
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    }
  }
}
