import java.io.Serializable;
import java.rmi.RemoteException;

public class Student implements Serializable {
  private static final long serialVersionUID = 1L;

  private String name;
  private String degree;
  private String email;

  /**
   * @return the name
   */
  public String getName() {
    return name;
  }

  /**
   * @param name the name to set
   */
  public void setName(String name) {
    this.name = name;
  }

  /**
   * @return the degree
   */
  public String getDegree() {
    return degree;
  }

  /**
   * @param degree the degree to set
   */
  public void setDegree(String degree) {
    this.degree = degree;
  }

  /**
   * @return the email
   */
  public String getEmail() {
    return email;
  }

  /**
   * @param email the email to set
   */
  public void setEmail(String email) {
    this.email = email;
  }

  /*
   * (non-Javadoc)
   *
   * @see java.lang.Object#hashCode()
   */

  @Override
  public int hashCode() {
    final int prime = 31;
    int result = 1;
    result = prime * result + ((degree == null) ? 0 : degree.hashCode());
    result = prime * result + ((email == null) ? 0 : email.hashCode());
    result = prime * result + ((name == null) ? 0 : name.hashCode());
    return result;
  }

  /*
   * (non-Javadoc)
   *
   * @see java.lang.Object#equals(java.lang.Object)
   */

  @Override
  public boolean equals(Object obj) {
    if (this == obj)
      return true;
    if (obj == null)
      return false;
    if (getClass() != obj.getClass())
      return false;
    Student other = (Student) obj;
    if (degree == null) {
      if (other.degree != null)
        return false;
    } else if (!degree.equals(other.degree))
      return false;
    if (email == null) {
      if (other.email != null)
        return false;
    } else if (!email.equals(other.email))
      return false;
    if (name == null) {
      if (other.name != null)
        return false;
    } else if (!name.equals(other.name))
      return false;
    return true;
  }

  /*
   * (non-Javadoc)
   *
   * @see java.lang.Object#toString()
   */

  @Override
  public String toString() {
    return "Student [degree=" + degree + ", email=" + email + ", name=" + name + "]";
  }

  /**
   * @param name
   * @param degree
   * @param email
   */
  public Student(String name, String degree, String email) throws RemoteException {
    this.name = name;
    this.degree = degree;
    this.email = email;
  }
}
