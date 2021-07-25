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
@Table(name = "SALE")
@XmlRootElement
@NamedQueries({
  @NamedQuery(name = "Sale.findAll", query = "SELECT s FROM Sale s"),
  @NamedQuery(name = "Sale.findById", query = "SELECT s FROM Sale s WHERE s.id = :id"),
  @NamedQuery(name = "Sale.findByValue", query = "SELECT s FROM Sale s WHERE s.value = :value")
})
public class Sale implements Serializable {

  private static final long serialVersionUID = 1L;

  @Id
  @GeneratedValue(strategy = GenerationType.IDENTITY)
  @Basic(optional = false)
  @NotNull
  @Column(name = "ID")
  private Integer id;

  @Basic(optional = false)
  @NotNull
  @Column(name = "VALUE")
  private double value;

  @JoinColumn(name = "CLIENT", referencedColumnName = "ID")
  @ManyToOne(optional = false)
  private Users client;

  public Sale() {
  }

  public Sale(Integer id) {
    this.id = id;
  }

  public Sale(Integer id, double value) {
    this.id = id;
    this.value = value;
  }

  public Integer getId() {
    return id;
  }

  public void setId(Integer id) {
    this.id = id;
  }

  public double getValue() {
    return value;
  }

  public void setValue(double value) {
    this.value = value;
  }

  public Users getClient() {
    return client;
  }

  public void setClient(Users client) {
    this.client = client;
  }

  @Override
  public int hashCode() {
    int hash = 0;
    hash += (id != null ? id.hashCode() : 0);
    return hash;
  }

  @Override
  public boolean equals(Object object) {
    if (!(object instanceof Sale)) {
      return false;
    }
    Sale other = (Sale) object;
    if ((this.id == null && other.id != null) || (this.id != null && !this.id.equals(other.id))) {
      return false;
    }
    return true;
  }

  @Override
  public String toString() {
    return "entities.Sale[ id=" + id + " ]";
  }

}
