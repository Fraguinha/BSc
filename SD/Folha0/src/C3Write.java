import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

public class C3Write {

  public static void main(String[] args) {
    Person p1 = new Person("Person 1", "example1@email.com", 123456789);
    Person p2 = new Person("Person 2", "example2@email.com", 987654321);
    try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("test3.ser"))) {
      oos.writeObject(p1);
      oos.writeObject(p2);
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
}
