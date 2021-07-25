import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ConnectException;
import java.net.Socket;

public class Client2A {
  public static void main(String[] args) {
    String server = "localhost";
    int port = 2222;
    try (Socket socket = new Socket(server, port);
        ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
        ObjectInputStream ois = new ObjectInputStream(socket.getInputStream())) {
      System.out.println("Sent: A");
      oos.writeObject("A");
      System.out.println("Sent: 2");
      oos.writeObject(2);
      System.out.println("Received: " + ois.readObject());
    } catch (ConnectException e) {
      System.err.println("Could not connect to server");
    } catch (ClassNotFoundException | IOException e) {
      e.printStackTrace();
    }
  }
}
