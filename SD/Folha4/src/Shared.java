public class Shared {
  private int sharedInt;

  /**
   * @return the sharedInt
   */
  public int getSharedInt() {
    return sharedInt;
  }

  /**
   * @param sharedInt the sharedInt to set
   */
  public void setSharedInt(int sharedInt) {
    this.sharedInt = sharedInt;
  }

  public Shared(int sharedInt) {
    this.sharedInt = sharedInt;
  }

}
