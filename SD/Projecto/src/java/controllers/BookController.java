package controllers;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

import javax.ejb.EJB;
import javax.enterprise.context.SessionScoped;
import javax.inject.Named;

import bean.BookBean;
import bean.BooklistBean;
import bean.SaleBean;
import bean.UsersBean;
import entities.Book;
import entities.Booklist;
import entities.Sale;
import entities.Users;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

@Named(value = "bookController")
@SessionScoped
public class BookController implements Serializable {

  @EJB
  private BookBean bookBean;
  @EJB
  private SaleBean saleBean;
  @EJB
  private BooklistBean booklistBean;
  @EJB
  private UsersBean usersBean;
  private Book book = new Book();
  private ArrayList<Book> shoppingCart = new ArrayList<Book>();
  private Book newBook = new Book();
  private Book cartBook = new Book();

    public Book getCartBook() {
        return cartBook;
    }

    public void setCartBook(Book cartBook) {
        this.cartBook = cartBook;
    }

  public Book getBook() {
    return book;
  }

  public void setBook(Book book) {
    this.book = book;
  }

  public Book getNewBook() {
    return newBook;
  }

  public void setNewBook(Book newBook) {
    this.newBook = newBook;
  }

  public ArrayList<Book> getShoppingCart() {
    return shoppingCart;
  }

  public void setShoppingCart(ArrayList<Book> shoppingCart) {
    this.shoppingCart = shoppingCart;
  }

  public List<Book> getBookList() {
    return bookBean.getBooks();
  }

  public void findBook(int id) {
    setBook(bookBean.getBookById(id));
  }

  public String addToCart() throws SQLException {
    Connection con = DriverManager.getConnection("jdbc:derby://localhost:1527/bookstore", "APP", "APP");
    Statement stmt = con.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_UPDATABLE);
    String command = "SELECT * FROM APP.BOOK WHERE ID = " + Integer.parseInt(book.getId().toString());
    ResultSet rs = stmt.executeQuery(command);
    rs.next();
    System.out.println("" + rs.getInt("QUANTITY"));
    if (rs.getInt("QUANTITY") >= cartBook.getQuantity()) {
      for (Book bo : shoppingCart) {
          if (bo.getId() == book.getId()) {
              bo.setQuantity(bo.getQuantity() + cartBook.getQuantity());

              return "index";
          }
      }
      Book b = new Book(book.getId(), book.getName(), book.getAuthor(), book.getPublisher(), book.getLanguage(), book.getGenre(), book.getYearPublication(), cartBook.getQuantity(), book.getPrice() * cartBook.getQuantity());
      shoppingCart.add(b);
      //price = price + rs.getDouble("PRICE") * cartBook.getQuantity();
      stmt.close();
      return "index";
    } else {
      /* Enviar um alerta a dizer que não existe a quantidade pretendida */
        System.out.println("Erro!");
    }
    return "viewBook";
  }

  public String buy(int user_id) throws SQLException {
    double v = 0;
    Sale s = new Sale(0,v);
    s.setClient(usersBean.getUsers(user_id));
    saleBean.addSale(s);
    Connection con = DriverManager.getConnection("jdbc:derby://localhost:1527/bookstore", "APP", "APP");
    for (int i = 0; i < shoppingCart.size(); i++) {
        Statement stmt = con.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_UPDATABLE);
        String command = "SELECT * FROM APP.BOOK WHERE ID = " + shoppingCart.get(i).getId();
        ResultSet rs = stmt.executeQuery(command);
        rs.next();
        int q = shoppingCart.get(i).getQuantity();
        if (rs.getInt("QUANTITY") >= q) {
            Book o = new Book(shoppingCart.get(i).getId(), shoppingCart.get(i).getName(), shoppingCart.get(i).getAuthor(), shoppingCart.get(i).getPublisher(), shoppingCart.get(i).getLanguage(), shoppingCart.get(i).getGenre(), shoppingCart.get(i).getYearPublication(), rs.getInt("QUANTITY") - shoppingCart.get(i).getQuantity(), book.getPrice());
            stmt.close();
            v += q * shoppingCart.get(i).getPrice();
            bookBean.updateBook(o);
            booklistBean.addBooklist(new Booklist(0,q,q * shoppingCart.get(i).getPrice(),o,s));
        }
    }
    s.setValue(v);
    saleBean.updateSale(s);
    shoppingCart = new ArrayList<Book>();
    return "index";
  }

  public String removeFromCart(int id) throws SQLException {
      Book c = new Book();
      for (Book b : shoppingCart) {
          if (b.getId() == id) {
              c = b;
              break;
          }
      }
      System.out.println("id:" + id + "b id: " + c.getId());
      shoppingCart.remove(c);
      return "cart";
  }
  
    public String clear() throws SQLException {
      shoppingCart.clear();
      return "cart";
   
  }
  public void addBook() {
    bookBean.addBook(newBook);
    newBook = new Book();
  }

  public void updateBook() {
    bookBean.updateBook(book);
  }

  public String deleteBook() {
    bookBean.deleteBook(book);
    return "index";
  }
}
