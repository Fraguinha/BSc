import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.List;

public class C6 {

  public static void main(String[] args) {
    ArrayList<Book> books = readStoredBooks();
    boolean exit = false;
    int option;
    do {
      System.out.println("Gestor de livros");
      System.out.println();
      System.out.println("1 - Adicionar livros");
      System.out.println("2 - Procurar livro");
      System.out.println("3 - Listar livros");
      System.out.println();
      System.out.println("0 - Sair");
      System.out.println();
      System.out.print("opção: ");
      try {
        option = Integer.parseInt(System.console().readLine());
        switch (option) {
        case 0:
          option0(books);
          exit = true;
          break;
        case 1:
          option1(books);
          break;
        case 2:
          option2(books);
          break;
        case 3:
          option3(books);
          break;
        default:
          System.out.println("Opção Inválida - Selecione uma opção válida");
          break;
        }
      } catch (NumberFormatException e) {
        System.out.println("Opção Inválida - Introduza um numero");
      }
    } while (!exit);
  }

  private static void option0(List<Book> books) {
    storeBooks(books);
  }

  private static void option1(List<Book> books) {
    System.out.println();
    books.addAll(readNewBooks());
    System.out.println();
    System.out.println();
  }

  private static void option2(List<Book> books) {
    System.out.println();
    System.out.print("Nome do livro: ");
    String name = System.console().readLine();
    boolean isPresent = false;
    for (Book b : books) {
      if (b.getName().equalsIgnoreCase(name))
        isPresent = true;
    }
    System.out.println();
    if (isPresent) {
      System.out.println("O livro está disponível");
    } else {
      System.out.println("O livro não está disponível");
    }
    System.out.println();
  }

  private static void option3(List<Book> books) {
    System.out.println();
    for (Book b : books) {
      System.out.println(b);
    }
    System.out.println();
    System.out.print("[Pressione ENTER para continuar] ");
    System.console().readLine();
    System.out.println();
  }

  private static ArrayList<Book> readStoredBooks() {
    ArrayList<Book> books = new ArrayList<>();
    try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream("test6.ser"))) {
      Object obj;
      while ((obj = ois.readObject()) != null) {
        books.add((Book) obj);
      }
      System.out.println();
    } catch (FileNotFoundException e) {
      System.out.println("Não há livros armazenados");
    } catch (IOException | ClassNotFoundException e) {
      e.printStackTrace();
    }
    return books;
  }

  private static ArrayList<Book> readNewBooks() {
    ArrayList<Book> books = new ArrayList<>();
    System.out.println("Introduza uma lista de livros:");
    String line;
    while ((line = System.console().readLine()) != null) {
      books.add(new Book(line));
    }
    return books;
  }

  private static void storeBooks(List<Book> books) {
    try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("test6.ser"))) {
      for (Book b : books) {
        oos.writeObject(b);
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
}
