package controllers;

import bean.UsersBean;
import entities.Users;
import java.io.Serializable;
import java.util.List;
import javax.ejb.EJB;
import javax.enterprise.context.SessionScoped;
import javax.inject.Named;

@Named(value = "userController")
@SessionScoped
public class UsersController implements Serializable {

  @EJB
  private UsersBean userBean;
  private Users user = new Users();
  private boolean loggedIn;

  public Users getUser() {
    return user;
  }

  public void setUser(Users user) {
    this.user = user;
  }

  public boolean isLoggedIn() {
    return loggedIn;
  }

  public void setLoggedIn(boolean loggedIn) {
    this.loggedIn = loggedIn;
  }

  public List<Users> getUserList() {
    List<Users> userList = userBean.getUsers();
    return userList;
  }
  
  public String addUser() {
    userBean.addUser(user);
    return "index";
  }
  
  public String login() {
    List<Users> users = userBean.login(user.getUsername(), user.getPassword());
    if (!users.isEmpty()) {
      setUser(users.get(0));
      setLoggedIn(true);
      return "index";
    } else {
      return "login";
    }    
  }

  public String logout() {
    user = new Users();
    setLoggedIn(false);
    return "index";
  }
}
