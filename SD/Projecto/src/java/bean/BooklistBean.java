package bean;

import entities.Booklist;
import java.util.List;
import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.validation.ConstraintViolationException;
import org.jboss.logging.Logger;
import org.jboss.logging.Logger.Level;

@Stateless
public class BooklistBean {

  @PersistenceContext(unitName = "BookstorePU")
  private EntityManager em;

  public void persist(Object object) {
    em.persist(object);
  }

  public List<Booklist> getBooklist() {
    return (List<Booklist>) em.createNamedQuery("Booklist.findAll").getResultList();
  }

  public Booklist addBooklist(Booklist bl) {
    bl.setId(getBooklist().size() + 1);
    try {
    em.persist(bl);
    } catch (ConstraintViolationException e) {
       System.out.println("EX:");;
       e.getConstraintViolations().forEach(err->System.out.println(err.toString()));
    }
    return bl;
  }
}
