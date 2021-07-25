import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class RMIImplementation extends UnicastRemoteObject implements RMIInterface {

  private static final long serialVersionUID = 1L;

  private int count;

  public RMIImplementation(String name) throws RemoteException {
    this.count = 0;
    try {
      Naming.rebind(name, this);
    } catch (RemoteException e) {
      throw e;
    } catch (Exception e) {
      throw new RemoteException(e.getMessage());
    }
  }

  public java.util.Date getDate() {
    System.out.println("Remote method: RMIImplementation.getDate()");
    this.count += 1;
    return new java.util.Date();
  }

  public int getCount() {
    System.out.println("Remote method: RMIImplementation.getCount()");
    return count;
  }
}
