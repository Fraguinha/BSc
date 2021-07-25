public class Test4 extends Thread {
  Reentrant r;

  public Test4() {
    this.r = new Reentrant();
    this.start();
  }

  @Override
  public void run() {
    r.myMethod();
  }

  public static void main(String[] args) {
    new Test4();
  }
}
