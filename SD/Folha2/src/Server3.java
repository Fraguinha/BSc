import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class Server3 {
  public static void main(String[] args) {
    int port = 2222;
    try (ServerSocket server = new ServerSocket(port);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
      System.out.println("listening on port: " + port);
      while (true) {
        Socket socket = server.accept();
        System.out.println("Accepted connection");
        handleClient(socket, br);
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  public static void handleClient(Socket socket, BufferedReader br) {
    try (ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
        ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());) {
      while (true) {
        System.out.println("Received: " + ois.readObject());
        System.out.print("Message: ");
        String msg = br.readLine();
        oos.writeObject(msg);
        System.out.println("Sent: " + msg);
      }
    } catch (IOException e) {
      System.out.println("Client disconnected");
    } catch (ClassNotFoundException e) {
      e.printStackTrace();
    }
  }
}
