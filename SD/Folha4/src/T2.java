import java.util.Random;

public class T2 implements Runnable {

  MovieRoom room;
  Random random;

  public void run() {
    while (true) {
      try {
        int timeout = random.nextInt(1000);
        Thread.sleep(timeout >= 0 ? timeout : -timeout);
        if (room.getTickets() == 0) {
          System.out.println(Thread.currentThread().getName() + " ended");
          break;
        }
        System.out.println(
            Thread.currentThread().getName() + " sold ticket: " + room.buyTicket() + " for movie: " + room.getMovie());
      } catch (InterruptedException ex) {
        Thread.currentThread().interrupt();
      }
    }
  }

  public T2(MovieRoom room) {
    this.random = new Random();
    this.room = room;
  }
}
