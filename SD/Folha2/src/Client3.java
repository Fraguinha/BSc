import java.io.BufferedReader;
import java.io.EOFException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ConnectException;
import java.net.Socket;

public class Client3 {
  public static void main(String[] args) {
    String server = "localhost";
    int port = 2222;
    try (Socket socket = new Socket(server, port);
        ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
        ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
      String msg;
      String ans;
      do {
        System.out.print("Message: ");
        msg = br.readLine();
        oos.writeObject(msg);
        System.out.println("Sent: " + msg);
        ans = (String) ois.readObject();
        System.out.println("Received: " + ans);
      } while (!ans.equals("end"));
    } catch (EOFException e) {
      System.err.println("Disconnected");
    } catch (ConnectException e) {
      System.err.println("Could not connect to server");
    } catch (ClassNotFoundException | IOException e) {
      e.printStackTrace();
    }
  }
}
