public class T1B implements Runnable {
  private Shared obj;

  public void run() {
    while (true) {
      obj.setSharedInt(obj.getSharedInt() + 1);
    }
  }

  public T1B(Shared obj) {
    this.obj = obj;
  }
}
