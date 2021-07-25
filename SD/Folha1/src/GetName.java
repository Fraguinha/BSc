import java.net.InetAddress;
import java.net.UnknownHostException;

public class GetName {
  public static void main(String[] args) {
    try {
      InetAddress addr = InetAddress.getLocalHost();
      System.out.println(addr.getHostName());
    } catch (UnknownHostException e) {
      e.printStackTrace();
    }
  }
}
