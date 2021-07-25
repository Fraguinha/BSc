import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

public class Test6 {

  public static void main(String[] arg) {
    ThreadPoolExecutor pool1 = new ThreadPoolExecutor(5, 10, 5, TimeUnit.SECONDS, new ArrayBlockingQueue<>(10),
        Executors.defaultThreadFactory());
    ThreadPoolExecutor pool2 = new ThreadPoolExecutor(5, 10, 5, TimeUnit.SECONDS, new ArrayBlockingQueue<>(10),
        Executors.defaultThreadFactory());

    for (int i = 0; i < 5; i++) {
      pool1.execute(new T5());
      pool2.execute(new T5());
    }

    System.out.println("Pool 1 active threads: " + pool1.getActiveCount());
    System.out.println("Pool 2 active threads: " + pool2.getActiveCount());

    pool1.shutdown();
    pool2.shutdown();
  }
}
