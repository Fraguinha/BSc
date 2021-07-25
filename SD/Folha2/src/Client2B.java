import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ConnectException;
import java.net.Socket;

public class Client2B {
  public static void main(String[] args) {
    String server = "localhost";
    int port = 2222;
    try (Socket socket = new Socket(server, port);
        ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
        ObjectInputStream ois = new ObjectInputStream(socket.getInputStream())) {
      System.out.println("Sent: B");
      oos.writeObject("B");
      System.out.println("Sent: 4.0");
      oos.writeObject(4.0);
      System.out.println("Received: " + ois.readObject());
    } catch (ConnectException e) {
      System.err.println("Could not connect to server");
    } catch (ClassNotFoundException | IOException e) {
      e.printStackTrace();
    }
  }
}
