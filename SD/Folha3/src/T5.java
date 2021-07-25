public class T5 implements Runnable {

  public void run() {
    try {
      Thread.sleep(1000);
      System.out.println(Thread.currentThread());
    } catch (InterruptedException e) {
      Thread.currentThread().interrupt();
    }
  }
}
