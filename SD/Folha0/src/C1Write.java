import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class C1Write {

  public static void main(String[] args) {
    try (BufferedWriter bw = new BufferedWriter(new FileWriter("teste1.txt"))) {
      bw.write("1");
      bw.newLine();
      bw.write("2");
      bw.flush();
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
}
