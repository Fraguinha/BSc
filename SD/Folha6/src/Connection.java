import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

public class Connection implements Runnable {

  private Socket socket;
  private Server server;

  public Connection(Socket socket, Server server) {
    this.socket = socket;
    this.server = server;
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
