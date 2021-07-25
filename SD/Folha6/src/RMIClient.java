import java.net.MalformedURLException;
import java.net.UnknownHostException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.util.Date;

public class RMIClient {
  public static void main(String[] argv) {
    System.setSecurityManager(new SecurityManager());
    try {
      String serverName = java.net.InetAddress.getLocalHost().getHostName();
      // bind server object to object in client
      RMIInterface myServerObject = (RMIInterface) Naming.lookup("//" + serverName + "/RMIImplementation");
      // invoke method on server
      Date d = myServerObject.getDate();
      int c = myServerObject.getCount();
      System.out.println("Date on server is: " + d);
      System.out.print("Date was called: " + c);
      if (c > 1) {
        System.out.println(" times");
      } else {
        System.out.println(" time");
      }
    } catch (UnknownHostException | MalformedURLException | RemoteException | NotBoundException e) {
      e.printStackTrace();
    }
    System.out.println("RMI connection successful");
  }
}
