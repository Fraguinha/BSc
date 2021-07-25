import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.RemoteException;

public class CalculatorServer {
  public static void main(String[] args) {
    System.setSecurityManager(new SecurityManager());
    try {
      java.rmi.registry.LocateRegistry.createRegistry(1099);
      Calculator c = new Calculator();
      Naming.rebind("rmi://localhost:1099/CalculatorService", c);
    } catch (RemoteException | MalformedURLException e) {
      e.printStackTrace();
    }
  }
}
