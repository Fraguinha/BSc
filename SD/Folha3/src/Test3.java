import java.util.Random;

public class Test3 {

  private static final int ARRAY_SIZE = 1000000;

  public static void main(String[] args) throws InterruptedException {
    Random r = new Random();
    int[] a = new int[ARRAY_SIZE];
    int[] b = new int[ARRAY_SIZE];
    int[] c = new int[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
      a[i] = r.nextInt();
      b[i] = r.nextInt();
    }
    Thread t1 = new Thread(new T3(a, b, c, 0, ARRAY_SIZE / 2), "t1");
    Thread t2 = new Thread(new T3(a, b, c, ARRAY_SIZE / 2, ARRAY_SIZE), "t2");
    t1.start();
    t2.start();
    t1.join();
    t2.join();
    int s = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
      s += c[i];
    }
    System.out.println(s);
  }
}
