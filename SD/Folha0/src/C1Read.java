import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class C1Read {

  public static void main(String[] args) {
    try (BufferedReader br = new BufferedReader(new FileReader("teste1.txt"))) {
      System.out.println(br.readLine());
      System.out.println(br.readLine());
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
}
