public interface RMIInterface extends java.rmi.Remote {
  public java.util.Date getDate() throws java.rmi.RemoteException;

  public int getCount() throws java.rmi.RemoteException;
}
