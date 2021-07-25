import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class C2Write {

  public static void main(String[] args) {
    try (PrintWriter pw = new PrintWriter(new FileWriter("teste2.txt"))) {
      pw.println(2.31);
      pw.println(false);
      pw.print("X");
      pw.flush();
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
}
