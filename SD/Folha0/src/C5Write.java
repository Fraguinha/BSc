import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.List;

public class C5Write {

  public static void main(String[] args) {
    ArrayList<Book> books = readBooks();
    writeBooks(books);
  }

  private static ArrayList<Book> readBooks() {
    ArrayList<Book> books = new ArrayList<>();
    System.out.println("Introduza uma lista de livros:");
    String line;
    while ((line = System.console().readLine()) != null) {
      books.add(new Book(line));
    }
    return books;
  }

  private static void writeBooks(List<Book> books) {
    try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("test5.ser"))) {
      for (Book b : books) {
        oos.writeObject(b);
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
}
