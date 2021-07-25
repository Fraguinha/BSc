import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ConnectException;
import java.net.Socket;

public class Client {
  public static void main(String[] args) {
    String server = "localhost";
    int port = 2222;
    try (Socket socket = new Socket(server, port);
        ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
        ObjectInputStream ois = new ObjectInputStream(socket.getInputStream())) {
      System.out.println("Sent: Hi, I am the client");
      oos.writeObject("Hi, I am the client");
      System.out.println("Received: " + ois.readObject());
      System.out.println("Sent: I am still here");
      oos.writeObject("I am still here");
      System.out.println("Received: " + ois.readObject());
    } catch (ConnectException e) {
      System.err.println("Could not connect to server");
    } catch (ClassNotFoundException | IOException e) {
      e.printStackTrace();
    }
  }
}
