import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class Server2 {
  public static void main(String[] args) {
    int port = 2222;
    try (ServerSocket server = new ServerSocket(port)) {
      System.out.println("listening on port: " + port);
      while (true) {
        Socket socket = server.accept();
        System.out.println("Accepted connection");
        handleClient(socket);
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  public static void handleClient(Socket socket) {
    try (ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
        ObjectInputStream ois = new ObjectInputStream(socket.getInputStream())) {
      Object obj = ois.readObject();
      System.out.println("Received: " + obj);
      if (obj.equals("A")) {
        Integer i = (Integer) ois.readObject();
        int j = i.intValue();
        System.out.println("Received: " + j);
        double ans = Math.pow(j, 2);
        System.out.println("Sent: " + ans);
        oos.writeObject(ans);
      } else if (obj.equals("B")) {
        Double a = (Double) ois.readObject();
        double b = a.doubleValue();
        System.out.println("Received: " + b);
        double ans = Math.sqrt(b);
        System.out.println("Sent: " + ans);
        oos.writeObject(ans);
      }
    } catch (ClassNotFoundException | IOException e) {
      e.printStackTrace();
    }
  }
}
