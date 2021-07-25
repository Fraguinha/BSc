import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketTimeoutException;
import java.net.UnknownHostException;

public class UDPClient {

  public static void main(String[] args) {
    try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        DatagramSocket socket = new DatagramSocket()) {
      socket.setSoTimeout(10000);
      System.out.print("Server: ");
      InetAddress serverAddress = InetAddress.getByName(br.readLine());
      System.out.print("Port: ");
      int serverPort = Integer.parseUnsignedInt(br.readLine());
      while (true) {
        System.out.print("Message: ");
        byte[] message = br.readLine().getBytes();
        if (new String(message).equals("quit"))
          break;
        long t = System.currentTimeMillis();
        DatagramPacket request = new DatagramPacket(message, message.length, serverAddress, serverPort);
        socket.send(request);
        byte[] buffer = new byte[4096];
        DatagramPacket reply = new DatagramPacket(buffer, buffer.length);
        socket.receive(reply);
        System.out.println("Received: " + new String(reply.getData()));
        System.out.println("RTT: " + (System.currentTimeMillis() - t) + " ms");
      }
    } catch (SocketTimeoutException e) {
      System.err.println("Server timeout");
    } catch (UnknownHostException e) {
      System.err.println("Invalid IP address");
    } catch (NumberFormatException e) {
      System.err.println("Invalid port number");
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
}
