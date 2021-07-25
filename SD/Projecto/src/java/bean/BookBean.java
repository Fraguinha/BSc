package bean;

import entities.Book;
import java.util.List;
import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;

@Stateless
public class BookBean {

  @PersistenceContext(unitName = "BookstorePU")
  private EntityManager em;

  public void persist(Object object) {
    em.persist(object);
  }

  public List<Book> getBooks() {
    return (List<Book>) em.createNamedQuery("Book.findAll").getResultList();
  }

  public Book getBookById(int id) {
    List<Book> books = em.createNamedQuery("Book.findById").setParameter("id", id).getResultList();
    return books.get(0);
  }
  
  public int nextId() {
    return getBooks().size() + 1;
  }

  public void addBook(Book book) {
    book.setId(nextId());
    em.persist(book);
  }

  public void updateBook(Book book) {
    em.createQuery(
            "UPDATE Book b SET b.name = '" + book.getName()
            + "', b.author = '" + book.getAuthor()
            + "', b.publisher = '" + book.getPublisher()
            + "', b.language = '" + book.getLanguage()
            + "', b.genre = '" + book.getGenre()
            + "', b.yearPublication = " + book.getYearPublication()
            + ", b.quantity = " + book.getQuantity()
            + ", b.price = " + book.getPrice()
            + " WHERE b.id = :id")
            .setParameter("id", book.getId())
            .executeUpdate();
  }

  public void deleteBook(Book book) {
    em.createQuery("DELETE FROM Book b WHERE b.id = :id")
            .setParameter("id", book.getId())
            .executeUpdate();
  }
}
