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
@Table(name = "USERS")
@XmlRootElement
@NamedQueries({
  @NamedQuery(name = "Users.findAll", query = "SELECT u FROM Users u"),
  @NamedQuery(name = "Users.findById", query = "SELECT u FROM Users u WHERE u.id = :id"),
  @NamedQuery(name = "Users.findByEmail", query = "SELECT u FROM Users u WHERE u.email = :email"),
  @NamedQuery(name = "Users.findByUsername", query = "SELECT u FROM Users u WHERE u.username = :username"),
  @NamedQuery(name = "Users.findByPassword", query = "SELECT u FROM Users u WHERE u.password = :password"),
  @NamedQuery(name = "Users.findByType", query = "SELECT u FROM Users u WHERE u.type = :type"),
  @NamedQuery(name = "Users.findByAuth", query = "SELECT u FROM Users u WHERE u.username = :username AND u.password = :password")
})
public class Users implements Serializable {

  private static final long serialVersionUID = 1L;
  @Id
  @GeneratedValue(strategy = GenerationType.IDENTITY)
  @Basic(optional = false)
  @Column(name = "ID")
  private Integer id;

  @Basic(optional = false)
  @NotNull
  @Size(min = 1, max = 30)
  @Column(name = "EMAIL")
  private String email;

  @Basic(optional = false)
  @NotNull
  @Size(min = 1, max = 30)
  @Column(name = "USERNAME")
  private String username;

  @Basic(optional = false)
  @NotNull
  @Size(min = 1, max = 32)
  @Column(name = "PASSWORD")
  private String password;

  @Basic(optional = false)
  @NotNull
  @Column(name = "TYPE")
  private int type;

  public Users() {
  }

  public Users(Integer id) {
    this.id = id;
  }

  public Users(Integer id, String name, String email, String password, int type) {
    this.id = id;
    this.email = email;
    this.username = name;
    this.password = password;
    this.type = type;
  }

  public Integer getid() {
    return id;
  }

  public void setid(Integer id) {
    this.id = id;
  }

  public String getUsername() {
    return username;
  }

  public void setUsername(String username) {
    this.username = username;
  }

  public String getEmail() {
    return email;
  }

  public void setEmail(String email) {
    this.email = email;
  }

  public String getPassword() {
    return password;
  }

  public void setPassword(String password) {
    this.password = password;
  }

  public int getType() {
    return type;
  }

  public void setType(int type) {
    this.type = type;
  }

  @Override
  public int hashCode() {
    int hash = 0;
    hash += (id != null ? id.hashCode() : 0);
    return hash;
  }

  @Override
  public boolean equals(Object object) {
    if (!(object instanceof Users)) {
      return false;
    }
    Users other = (Users) object;
    if ((this.id == null && other.id != null) || (this.id != null && !this.id.equals(other.id))) {
      return false;
    }
    return true;
  }

  @Override
  public String toString() {
    return "entities.User[ id=" + id + " ]";
  }

}
