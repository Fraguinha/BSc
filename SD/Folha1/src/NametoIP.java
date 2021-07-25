import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.InetAddress;
import java.net.UnknownHostException;

public class NametoIP {
  public static void main(String[] args) {
    System.out.print("Domain name: ");
    try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
      String ip = br.readLine();
      InetAddress addr = InetAddress.getByName(ip);
      System.out.println(addressFromBytes(addr.getAddress()));
    } catch (UnknownHostException e) {
      System.err.println("Invalid domain name");
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  private static String addressFromBytes(byte[] ip) {
    StringBuilder s = new StringBuilder();
    for (int i = 0; i < ip.length; i++) {
      if (i > 0) {
        s.append(".");
      }
      s.append(ip[i] & 0xff);
    }
    return s.toString();
  }
}
