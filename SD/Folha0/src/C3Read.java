import java.io.EOFException;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;

public class C3Read {

  public static void main(String[] args) {
    try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream("test3.ser"))) {
      Object obj = null;
      while ((obj = ois.readObject()) != null) {
        System.out.println(obj);
      }
    } catch (EOFException e) {
      // end of stream
    } catch (IOException | ClassNotFoundException e) {
      e.printStackTrace();
    }
  }
}
