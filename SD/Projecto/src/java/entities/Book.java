package entities;

import java.io.Serializable;

import javax.persistence.Basic;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.NamedQueries;
import javax.persistence.NamedQuery;
import javax.persistence.Table;
import javax.validation.constraints.NotNull;
import javax.validation.constraints.Size;
import javax.xml.bind.annotation.XmlRootElement;

@Entity
@Table(name = "BOOK")
@XmlRootElement
@NamedQueries({
  @NamedQuery(name = "Book.findAll", query = "SELECT b FROM Book b"),
  @NamedQuery(name = "Book.findById", query = "SELECT b FROM Book b WHERE b.id = :id"),
  @NamedQuery(name = "Book.findByName", query = "SELECT b FROM Book b WHERE b.name = :name"),
  @NamedQuery(name = "Book.findByAuthor", query = "SELECT b FROM Book b WHERE b.author = :author"),
  @NamedQuery(name = "Book.findByPublisher", query = "SELECT b FROM Book b WHERE b.publisher = :publisher"),
  @NamedQuery(name = "Book.findByLanguage", query = "SELECT b FROM Book b WHERE b.language = :language"),
  @NamedQuery(name = "Book.findByGenre", query = "SELECT b FROM Book b WHERE b.genre = :genre"),
  @NamedQuery(name = "Book.findByYearPublication", query = "SELECT b FROM Book b WHERE b.yearPublication = :yearPublication"),
  @NamedQuery(name = "Book.findByQuantity", query = "SELECT b FROM Book b WHERE b.quantity = :quantity"),
  @NamedQuery(name = "Book.findByPrice", query = "SELECT b FROM Book b WHERE b.price = :price")
})
public class Book implements Serializable {

  private static final long serialVersionUID = 1L;

  @Id
  @GeneratedValue(strategy = GenerationType.IDENTITY)
  @Basic(optional = false)
  @NotNull
  @Column(name = "ID")
  private Integer id;

  @Basic(optional = false)
  @NotNull
  @Size(min = 1, max = 30)
  @Column(name = "NAME")
  private String name;

  @Basic(optional = false)
  @NotNull
  @Size(min = 1, max = 30)
  @Column(name = "AUTHOR")
  private String author;

  @Basic(optional = false)
  @NotNull
  @Size(min = 1, max = 30)
  @Column(name = "PUBLISHER")
  private String publisher;

  @Basic(optional = false)
  @NotNull
  @Size(min = 1, max = 30)
  @Column(name = "LANGUAGE")
  private String language;

  @Basic(optional = false)
  @NotNull
  @Size(min = 1, max = 30)
  @Column(name = "GENRE")
  private String genre;

  @Basic(optional = false)
  @NotNull
  @Column(name = "YEAR_PUBLICATION")
  private int yearPublication;

  @Basic(optional = false)
  @NotNull
  @Column(name = "QUANTITY")
  private int quantity;

  @Basic(optional = false)
  @NotNull
  @Column(name = "PRICE")
  private double price;

  public Book() {
  }

  public Book(Integer id) {
    this.id = id;
  }

  public Book(Integer id, String name, String author, String publisher, String language, String genre,
          int yearPublication, int quantity, double price) {
    this.id = id;
    this.name = name;
    this.author = author;
    this.publisher = publisher;
    this.language = language;
    this.genre = genre;
    this.yearPublication = yearPublication;
    this.quantity = quantity;
    this.price = price;
  }

  public Integer getId() {
    return id;
  }

  public void setId(Integer id) {
    this.id = id;
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public String getAuthor() {
    return author;
  }

  public void setAuthor(String author) {
    this.author = author;
  }

  public String getPublisher() {
    return publisher;
  }

  public void setPublisher(String publisher) {
    this.publisher = publisher;
  }

  public String getLanguage() {
    return language;
  }

  public void setLanguage(String language) {
    this.language = language;
  }

  public String getGenre() {
    return genre;
  }

  public void setGenre(String genre) {
    this.genre = genre;
  }

  public int getYearPublication() {
    return yearPublication;
  }

  public void setYearPublication(int yearPublication) {
    this.yearPublication = yearPublication;
  }

  public int getQuantity() {
    return quantity;
  }

  public void setQuantity(int quantity) {
    this.quantity = quantity;
  }

  public double getPrice() {
    return price;
  }

  public void setPrice(double price) {
    this.price = price;
  }

  @Override
  public int hashCode() {
    int hash = 0;
    hash += (id != null ? id.hashCode() : 0);
    return hash;
  }

  @Override
  public boolean equals(Object object) {
    if (!(object instanceof Book)) {
      return false;
    }
    Book other = (Book) object;
    if ((this.id == null && other.id != null) || (this.id != null && !this.id.equals(other.id))) {
      return false;
    }
    return true;
  }

  @Override
  public String toString() {
    return "entities.Book[ id=" + id + " ]";
  }

}
