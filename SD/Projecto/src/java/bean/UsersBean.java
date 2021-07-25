package bean;

import entities.Users;
import java.util.List;
import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;

@Stateless
public class UsersBean {

  @PersistenceContext(unitName = "BookstorePU")
  private EntityManager em;

  public void persist(Object object) {
    em.persist(object);
  }

  public List<Users> getUsers() {
    return (List<Users>) em.createNamedQuery("Users.findAll").getResultList();
  }
  
  public Users getUsers(int id) {
    return (Users) em.createNamedQuery("Users.findById").setParameter("id", id).getSingleResult();
  }
  
  public Users addUser(Users user) {
    em.persist(user);
    return user;
  }

  public List<Users> login(String username, String password) {
    List<Users> users = em.createNamedQuery("Users.findByAuth")
            .setParameter("username", username)
            .setParameter("password", password)
            .getResultList();
    return users;
  }
}
