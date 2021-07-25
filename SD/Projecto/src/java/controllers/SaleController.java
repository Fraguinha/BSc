package controllers;

import bean.SaleBean;
import entities.Sale;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;
import javax.ejb.EJB;
import javax.enterprise.context.SessionScoped;
import javax.inject.Named;

@Named(value = "saleController")
@SessionScoped
public class SaleController implements Serializable {

  @EJB
  private SaleBean saleBean;
  private List<Sale> saleList = new ArrayList<>();

  public List<Sale> getSaleList() {
    saleList = saleBean.getSale();
    return saleList;
  }

}
