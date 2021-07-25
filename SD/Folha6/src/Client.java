import java.io.BufferedReader;
import java.io.EOFException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ConnectException;
import java.net.Socket;
import java.net.SocketException;
import java.util.ArrayList;

public class Client {
  public static void main(String[] args) {
    String server = "localhost";
    int port = 2222;
    try (Socket socket = new Socket(server, port);
        ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
        ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
      String menu = "Gestor de alunos\n\n1 - Registar aluno\n2 - Listar alunos\n3 - Consultar acessos\n4 - Consultar aluno\n\n0 - Sair\n\nopção: ";
      boolean exit = false;
      int option = 0;
      do {
        try {
          System.out.print(menu);
          option = Integer.parseInt(br.readLine());
          ArrayList<Student> students;
          switch (option) {
          case 0:
            oos.writeObject("0");
            exit = true;
            break;
          case 1:
            oos.writeObject("1");
            oos.writeObject(createStudent(br));
            waitEnter("\nPressione [ENTER] Para continuar", br);
            break;
          case 2:
            oos.writeObject("2");
            students = (ArrayList<Student>) ois.readObject();
            listStudents(students);
            waitEnter("\nPressione [ENTER] Para continuar", br);
            break;
          case 3:
            oos.writeObject("3");
            int connections = Integer.parseInt((String) ois.readObject());
            System.out.println(connections);
            waitEnter("\nPressione [ENTER] Para continuar", br);
            break;
          case 4:
            oos.writeObject("4");
            String name = searchName(br);
            oos.writeObject(name);
            students = (ArrayList<Student>) ois.readObject();
            if (!students.isEmpty()) {
              listStudents(students);
            } else {
              System.out.println("No students found with name: " + name);
            }
            waitEnter("\nPressione [ENTER] Para continuar", br);
            break;
          default:
            waitEnter("\nOpção Inválida\n\nPressione [ENTER] Para continuar", br);
            break;
          }
        } catch (NumberFormatException e) {
          waitEnter("\nOpção Inválida\n\nPressione [ENTER] Para continuar", br);
        }
      } while (!exit);
    } catch (EOFException e) {
      System.err.println("Disconnected");
    } catch (ConnectException e) {
      System.err.println("Could not connect to server");
    } catch (SocketException e) {
      System.err.println("Lost connection to server");
    } catch (ClassNotFoundException | IOException e) {
      e.printStackTrace();
    }
  }

  private static void waitEnter(String info, BufferedReader br) throws IOException {
    System.out.print(info);
    br.readLine();
  }

  private static Student createStudent(BufferedReader br) throws IOException {
    System.out.println("Name of student: ");
    String name = br.readLine();
    System.out.println("Degree of student: ");
    String degree = br.readLine();
    System.out.println("Email of student: ");
    String email = br.readLine();
    return new Student(name, degree, email);
  }

  private static void listStudents(ArrayList<Student> students) {
    for (Student s : students) {
      System.out.println(s);
    }
  }

  private static String searchName(BufferedReader br) throws IOException {
    System.out.print("Name of student: ");
    return br.readLine();
  }
}
