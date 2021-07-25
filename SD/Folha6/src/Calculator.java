import java.rmi.RemoteException;

public class Calculator extends java.rmi.server.UnicastRemoteObject implements CalculatorInterface {

  private static final long serialVersionUID = 1L;

  public Calculator() throws java.rmi.RemoteException {
    // Explicitly throw remote exception
  }

  @Override
  public long add(long a, long b) throws RemoteException {
    return a + b;
  }

  @Override
  public long div(long a, long b) throws RemoteException {
    return a / b;
  }

  @Override
  public long mul(long a, long b) throws RemoteException {
    return a * b;
  }

  @Override
  public long sub(long a, long b) throws RemoteException {
    return a - b;
  }

}
