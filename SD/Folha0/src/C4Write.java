import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class C4Write {
  public static void main(String[] args) {
    System.out.println("Introduza um conjunto de linhas:");
    try (BufferedWriter bw = new BufferedWriter(new FileWriter("teste4.txt"))) {
      String line1 = null;
      String line2 = null;
      line1 = System.console().readLine();
      while (line1 != null) {
        bw.write(line1);
        line2 = System.console().readLine();
        if (line2 != null) {
          bw.newLine();
        }
        line1 = line2;
      }
      bw.flush();
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
}
