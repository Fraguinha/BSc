public class MovieRoom {
  private String movie;
  private int tickets;
  private int seats;

  public synchronized int buyTicket() {
    int ticket = getTickets();
    if (ticket > 0) {
      int seat = 1 + getSeats() - ticket;
      setTickets(ticket - 1);
      return seat;
    }
    return -1;
  }

  public MovieRoom(String movie, int seats) {
    this.movie = movie;
    this.seats = seats;
    this.tickets = seats;
  }

  public MovieRoom(int seats) {
    this.seats = seats;
    this.tickets = seats;
  }

  /**
   * @return the movie
   */
  public String getMovie() {
    return movie;
  }

  /**
   * @param movie the movie to set
   */
  public void setMovie(String movie) {
    this.movie = movie;
    this.tickets = this.seats;
  }

  /**
   * @return the tickets
   */
  public int getTickets() {
    return tickets;
  }

  /**
   * @param tickets the tickets to set
   */
  public void setTickets(int tickets) {
    this.tickets = tickets;
  }

  /**
   * @return the seats
   */
  public int getSeats() {
    return seats;
  }

  /**
   * @param seats the seats to set
   */
  public void setSeats(int seats) {
    this.seats = seats;
  }
}
