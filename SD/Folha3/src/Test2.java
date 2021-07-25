
public class Test2 {
  public static void main(String[] str) {
    new Thread(new T2()).start();
    new Thread(new T2()).start();
  }
}
