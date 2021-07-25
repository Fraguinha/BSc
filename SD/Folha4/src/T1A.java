public class T1A implements Runnable {
  private Shared obj;
  private int m;

  public void run() {
    int x = m;
    int y = -m;
    while (true) {
      int shared = obj.getSharedInt();
      x = x - shared;
      x = x + shared;
      if (x + y != 0) {
        System.out.println("Critical Section Violated");
        break;
      }
    }
  }

  public T1A(Shared obj, int m) {
    this.obj = obj;
    this.m = m;
  }
}
