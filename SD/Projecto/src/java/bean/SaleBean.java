package bean;

import entities.Sale;
import java.util.List;
import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;

@Stateless
public class SaleBean {

  @PersistenceContext(unitName = "BookstorePU")
  private EntityManager em;

  public void persist(Object object) {
    em.persist(object);
  }

  public List<Sale> getSale() {
    return (List<Sale>) em.createNamedQuery("Sale.findAll").getResultList();
  }

  public Sale addSale(Sale sale) {
    sale.setId(nextId());
    em.persist(sale);
    return sale;
  }
  
  public void updateSale(Sale sale) {
    em.createQuery(
            "UPDATE Sale s SET s.value = " + sale.getValue()
            + " WHERE s.id = :id")
            .setParameter("id", sale.getId())
            .executeUpdate();
  }

  public Integer nextId() {
    return getSale().size() + 1;
  }
}
