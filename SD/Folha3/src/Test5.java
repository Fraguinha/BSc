import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

public class Test5 {

  public static void main(String[] arg) {
    ThreadPoolExecutor pool = new ThreadPoolExecutor(5, 10, 5, TimeUnit.SECONDS, new ArrayBlockingQueue<>(10),
        Executors.defaultThreadFactory());

    for (int i = 0; i < 5; i++) {
      pool.execute(new T5());
    }

    System.out.println("Active threads: " + pool.getActiveCount());

    pool.shutdown();
  }
}
