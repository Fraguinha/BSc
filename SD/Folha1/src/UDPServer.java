import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class UDPServer {

  public static void main(String[] args) {
    try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
      System.out.print("Port: ");
      int serverPort = Integer.parseInt(br.readLine());
      try (DatagramSocket socket = new DatagramSocket(serverPort)) {
        byte[] serverAddress = InetAddress.getLocalHost().getAddress();
        System.out.println("Socket listening on: " + addressFromBytes(serverAddress) + ":" + serverPort);
        while (true) {
          byte[] buffer = new byte[4096];
          DatagramPacket request = new DatagramPacket(buffer, buffer.length);
          socket.receive(request);
          System.out.println("Received: " + new String(request.getData()));
          System.out.print("Message: ");
          byte[] message = br.readLine().getBytes();
          DatagramPacket reply = new DatagramPacket(message, message.length, request.getAddress(), request.getPort());
          socket.send(reply);
        }
      }
    } catch (NumberFormatException e) {
      System.err.println("Invalid port number");
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
