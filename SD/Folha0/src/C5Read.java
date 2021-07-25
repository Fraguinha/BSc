import java.io.EOFException;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.ArrayList;

public class C5Read {

  public static void main(String[] args) {
    ArrayList<Book> books = readBooks();
    for (Book b : books) {
      System.out.println(b);
    }
  }

  private static ArrayList<Book> readBooks() {
    ArrayList<Book> books = new ArrayList<>();
    try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream("test5.ser"))) {
      Object obj;
      while ((obj = ois.readObject()) != null) {
        books.add((Book) obj);
      }
    } catch (FileNotFoundException e) {
      System.out.println("Não há livros armazenados");
    } catch (EOFException e) {
      System.out.println("Livros foram importados");
    } catch (IOException | ClassNotFoundException e) {
      e.printStackTrace();
    }
    return books;
  }
}
