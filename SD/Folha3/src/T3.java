public class T3 implements Runnable {

  private int[] a;
  private int[] b;
  private int[] c;

  private int p;
  private int u;

  public T3(int[] a, int[] b, int[] c, int p, int u) {
    this.a = a;
    this.b = b;
    this.c = c;
    this.p = p;
    this.u = u;
  }

  public void run() {
    for (int i = p; i < u; i++) {
      c[i] = a[i] + b[i];
    }
  }
}
