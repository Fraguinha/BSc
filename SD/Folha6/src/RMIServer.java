public class RMIServer {
  public static void main(String[] argv) {
    System.setSecurityManager(new SecurityManager());
    try {
      // Iniciar a execução do registry no porto desejado
      java.rmi.registry.LocateRegistry.createRegistry(1099);
      System.out.println("RMI registry ready.");
    } catch (Exception e) {
      System.out.println("Exception starting RMI registry:");
      e.printStackTrace();
    }
    try {
      new RMIImplementation("RMIImplementation");
      System.out.println("Server ok");
    } catch (Exception e) {
      System.out.println("Server error: " + e);
    }
  }
}
