import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

public class Test1 {
  public static void main(String[] args) {
    ThreadPoolExecutor pool = new ThreadPoolExecutor(1, 10, 5, TimeUnit.SECONDS, new ArrayBlockingQueue<>(100),
        Executors.defaultThreadFactory());

    ThreadPoolExecutor daemons = new ThreadPoolExecutor(1, 10, 5, TimeUnit.SECONDS, new ArrayBlockingQueue<>(100),
        r -> {
          Thread t = Executors.defaultThreadFactory().newThread(r);
          t.setDaemon(true);
          return t;
        });

    Shared obj = new Shared(1);

    pool.execute(new T1A(obj, 1));
    daemons.execute(new T1B(obj));

    pool.shutdown();
  }
}
