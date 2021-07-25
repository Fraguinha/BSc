import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.ArrayList;

public class Connection implements Runnable {

  private Socket socket;
  private ArrayList<Student> students;
  private int connections;

  public Connection(Socket socket, ArrayList<Student> students, int connections) {
    this.socket = socket;
    this.students = students;
    this.connections = connections;
  }

  private synchronized void save(ArrayList<Student> students, String filename) {
    try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(filename))) {
      for (Student s : students) {
        oos.writeObject(s);
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  private ArrayList<Student> search(String name, ArrayList<Student> students) {
    ArrayList<Student> results = new ArrayList<>();
    for (Student s : students) {
      if (s.getName().equalsIgnoreCase(name))
        results.add(s);
    }
    return results;
  }

  public void run() {
    try (ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
        ObjectInputStream ois = new ObjectInputStream(socket.getInputStream())) {
      boolean exit = false;
      do {
        try {
          String req = (String) ois.readObject();
          int option = Integer.parseInt(req);
          Student s;
          switch (option) {
          case 0:
            exit = true;
            break;
          case 1:
            s = (Student) ois.readObject();
            synchronized (students) {
              students.add(s);
              save(students, "students.ser");
            }
            break;
          case 2:
            oos.writeObject(students);
            break;
          case 3:
            oos.writeObject(String.valueOf(connections));
            break;
          case 4:
            String name = (String) ois.readObject();
            oos.writeObject(search(name, students));
            break;
          default:
            oos.writeObject("\nOpção Inválida\n\nPressione [ENTER] Para continuar");
            ois.readObject();
            break;
          }
        } catch (NumberFormatException e) {
          oos.writeObject("\nOpção Inválida\n\nPressione [ENTER] Para continuar");
          ois.readObject();
        }
      } while (!exit);
    } catch (IOException e) {
      System.out.println("Client disconnected");
    } catch (ClassNotFoundException e) {
      e.printStackTrace();
    }
  }
}
