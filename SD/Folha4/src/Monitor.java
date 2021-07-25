public class Monitor extends Thread {
  Critical c;

  public Monitor(String name) {
    c = new Critical();
  }

  @Override
  public void run() {
    c.methodA();
    Critical.methodB();
  }
}
