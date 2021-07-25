package controllers;

import bean.BooklistBean;
import entities.Booklist;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;
import javax.ejb.EJB;
import javax.enterprise.context.SessionScoped;
import javax.inject.Named;

@Named(value = "booklistController")
@SessionScoped
public class BooklistController implements Serializable {

  @EJB
  private BooklistBean booklistBean;
  private List<Booklist> booklistList = new ArrayList<>();

  public List<Booklist> getBooklistList() {
    booklistList = booklistBean.getBooklist();
    return booklistList;
  }

}
