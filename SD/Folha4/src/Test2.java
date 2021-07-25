import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

public class Test2 {
  public static void main(String[] args) {
    ThreadPoolExecutor pool = new ThreadPoolExecutor(5, 10, 5, TimeUnit.SECONDS, new ArrayBlockingQueue<>(10),
        Executors.defaultThreadFactory());

    MovieRoom room = new MovieRoom("La La Land", 30);
    for (int i = 0; i < 5; i++) {
      pool.execute(new T2(room));
    }

    pool.shutdown();
  }
}
