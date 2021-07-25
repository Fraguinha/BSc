import java.net.InetAddress;
import java.net.UnknownHostException;

public class GetIP {
  public static void main(String[] args) {
    try {
      InetAddress addr = InetAddress.getLocalHost();
      System.out.println(addressFromBytes(addr.getAddress()));
    } catch (UnknownHostException e) {
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
