public class T4Normal extends Thread {

  @Override
  public void run() {
    for (int i = 0; i < 5; i++) {
      try {
        sleep(500);
      } catch (InterruptedException e) {
        Thread.currentThread().interrupt();
      }
      System.out.println(" I' m the normal Thread");
    }
    System.out.println(" The normal Thread is exiting");
  }
}
