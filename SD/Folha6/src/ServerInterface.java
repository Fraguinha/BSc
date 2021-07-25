import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.List;

public interface ServerInterface extends Remote {

  public void save() throws RemoteException;

  public List<Student> search(String name) throws RemoteException;
}
