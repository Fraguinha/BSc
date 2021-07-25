import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
  public static void main(String[] args) {
    int port = 2222;
    try (ServerSocket server = new ServerSocket(port)) {
      System.out.println("listening on port: " + port);
      while (true) {
        Socket socket = server.accept();
        System.out.println("Accepted connection");
        try (ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
            ObjectInputStream ois = new ObjectInputStream(socket.getInputStream())) {
          System.out.println("Sent: Hi, I am the server");
          oos.writeObject("Hi, I am the server");
          System.out.println("Received: " + ois.readObject());
          System.out.println("Sent: Are you still there?");
          oos.writeObject("Are you still there?");
          System.out.println("Received: " + ois.readObject());
        }
      }
    } catch (ClassNotFoundException | IOException e) {
      e.printStackTrace();
    }
  }
}
