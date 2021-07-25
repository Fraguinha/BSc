import java.io.IOException;
import java.io.ObjectOutputStream;
import java.net.Socket;

public class Connection1 extends Thread {

  private Socket s;

  public Connection1(Socket s) {
    this.s = s;
    this.start();
  }

  @Override
  public void run() {
    try {
      ObjectOutputStream os = new ObjectOutputStream(s.getOutputStream());
      os.writeObject("System date & time: " + new java.util.Date());
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
}
