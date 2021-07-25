import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.Socket;

public class Client1 {

  public Client1() {
    try (Socket s = new Socket("127.0.0.1", 5432); ObjectInputStream ois = new ObjectInputStream(s.getInputStream())) {
      System.out.println(ois.readObject());
    } catch (IOException e) {
      System.out.println(e.getMessage());
    } catch (ClassNotFoundException e) {
      e.printStackTrace();
    }
  }

  public static void main(String[] args) {
    new Client1();
  }
}
