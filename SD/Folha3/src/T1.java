public class T1 extends Thread {
  @Override
  public void run() {
    System.out.println("Hello there, from  " + getName());
  }
}
