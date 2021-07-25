import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.InetAddress;
import java.net.UnknownHostException;

public class IPtoName {
  public static void main(String[] args) {
    System.out.print("IP address: ");
    try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
      String ip = br.readLine();
      InetAddress addr = InetAddress.getByName(ip);
      System.out.println(addr.getHostName());
    } catch (UnknownHostException e) {
      System.err.println("Invalid IP address");
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
}
