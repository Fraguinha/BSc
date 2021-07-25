/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package entities;

import java.io.Serializable;
import javax.persistence.Basic;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.NamedQueries;
import javax.persistence.NamedQuery;
import javax.persistence.Table;
import javax.validation.constraints.NotNull;
import javax.xml.bind.annotation.XmlRootElement;

@Entity
@Table(name = "BOOKLIST")
@XmlRootElement
@NamedQueries({
  @NamedQuery(name = "Booklist.findAll", query = "SELECT b FROM Booklist b"),
  @NamedQuery(name = "Booklist.findById", query = "SELECT b FROM Booklist b WHERE b.id = :id"),
  @NamedQuery(name = "Booklist.findByQuantity", query = "SELECT b FROM Booklist b WHERE b.quantity = :quantity"),
  @NamedQuery(name = "Booklist.findByListValue", query = "SELECT b FROM Booklist b WHERE b.listValue = :listValue")})
public class Booklist implements Serializable {

  private static final long serialVersionUID = 1L;
  @Id
  @GeneratedValue(strategy = GenerationType.IDENTITY)
  @Basic(optional = false)
  @Column(name = "ID")
  private Integer id;
  @Basic(optional = false)
  @NotNull
  @Column(name = "QUANTITY")
  private int quantity;
  @Basic(optional = false)
  @NotNull
  @Column(name = "LIST_VALUE")
  private double listValue;
  
  @JoinColumn(name = "ISBN", referencedColumnName = "ID")
  @NotNull
  @ManyToOne(optional = false)
  private Book book;
  
  @JoinColumn(name = "SALE_ID", referencedColumnName = "ID")
  @NotNull
  @ManyToOne(optional = false)
  private Sale sale;

  public Booklist() {
  }

  public Booklist(Integer id) {
    this.id = id;
  }

  public Booklist(Integer id, int quantity, double listValue, Book b, Sale s) {
    this.id = id;
    this.quantity = quantity;
    this.listValue = listValue;
    book = b;
    sale = s;
  }

  public Integer getId() {
    return id;
  }

  public void setId(Integer id) {
    this.id = id;
  }

  public int getQuantity() {
    return quantity;
  }

  public void setQuantity(int quantity) {
    this.quantity = quantity;
  }

  public double getListValue() {
    return listValue;
  }

  public void setListValue(double listValue) {
    this.listValue = listValue;
  }

  public Book getBook() {
    return book;
  }

  public void setBook(Book book) {
    this.book = book;
  }

  public Sale getSale() {
    return sale;
  }

  public void setSale(Sale sale) {
    this.sale = sale;
  }
  
  

  @Override
  public int hashCode() {
    int hash = 0;
    hash += (id != null ? id.hashCode() : 0);
    return hash;
  }

  @Override
  public boolean equals(Object object) {
    // TODO: Warning - this method won't work in the case the id fields are not set
    if (!(object instanceof Booklist)) {
      return false;
    }
    Booklist other = (Booklist) object;
    if ((this.id == null && other.id != null) || (this.id != null && !this.id.equals(other.id))) {
      return false;
    }
    return true;
  }

  @Override
  public String toString() {
    return "entities.Booklist[ id=" + id + " ]";
  }

}
