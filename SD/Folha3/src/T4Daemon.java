public class T4Daemon extends Thread {
  public T4Daemon() {
    setDaemon(true);
  }

  @Override
  public void run() {
    for (int i = 0; i < 10; i++) {
      try {
        sleep(500);
      } catch (InterruptedException e) {
        Thread.currentThread().interrupt();
      }
      System.out.println(" I'm a daemon Thread");
    }
  }
}
