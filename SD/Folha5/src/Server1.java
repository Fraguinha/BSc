import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server1 {

  public Server1() {
    try (ServerSocket ss = new ServerSocket(5432)) {
      while (true) {
        Socket s = ss.accept();
        new Connection1(s);
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  public static void main(String[] args) {
    new Server1();
  }
}
