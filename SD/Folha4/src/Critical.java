import java.util.Random;

public class Critical {
  public synchronized void methodA() {
    System.out.println(Thread.currentThread().getName() + " Method A");
    try {
      int timeout = new Random().nextInt();
      Thread.sleep(timeout > 0 ? timeout : -timeout);
    } catch (InterruptedException e) {
      Thread.currentThread().interrupt();
    }
    System.out.println(Thread.currentThread().getName() + " Exiting method A");
  }

  public static synchronized void methodB() {
    System.out.println(Thread.currentThread().getName() + " Method B");
    try {
      int timeout = new Random().nextInt();
      Thread.sleep(timeout > 0 ? timeout : -timeout);
    } catch (InterruptedException e) {
      Thread.currentThread().interrupt();
    }
    System.out.println(Thread.currentThread().getName() + " Exiting method B");
  }
}
