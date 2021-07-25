public class T2 implements Runnable {

  public void run() {
    System.out.println("Hi there, from " + Thread.currentThread().getName());
  }
}
