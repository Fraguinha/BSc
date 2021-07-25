import java.io.EOFException;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class Server4 {

  public static void main(String[] args) {
    int port = 2222;
    try (ServerSocket server = new ServerSocket(port)) {
      ArrayList<Student> students = load("students.ser");
      System.out.println("listening on port: " + port);
      int connections = 0;
      while (true) {
        Socket socket = server.accept();
        connections += 1;
        System.out.println("Accepted connection");
        handleClient(socket, students, connections);
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  private static void save(List<Student> students, String filename) {
    try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(filename))) {
      for (Student s : students) {
        oos.writeObject(s);
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  private static ArrayList<Student> load(String filename) {
    ArrayList<Student> students = new ArrayList<>();
    try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(filename))) {
      Object obj = null;
      while ((obj = ois.readObject()) != null) {
        students.add((Student) obj);
      }
      System.out.println();
    } catch (FileNotFoundException e) {
      System.out.println("No students file");
    } catch (EOFException e) {
      System.out.println("Loaded students file");
    } catch (IOException | ClassNotFoundException e) {
      e.printStackTrace();
    }
    return students;
  }

  public static void handleClient(Socket socket, List<Student> students, int connections) {
    try (ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
        ObjectInputStream ois = new ObjectInputStream(socket.getInputStream())) {
      String menu = "Gestor de alunos\n" + "\n" + "1 - Registar aluno\n" + "2 - Listar alunos\n"
          + "3 - Consultar acessos\n" + "4 - Consultar aluno\n" + "\n" + "0 - Sair\n" + "\n" + "opção: ";
      boolean exit = false;
      int option = 0;
      do {
        try {
          oos.writeObject(menu);
          String req = (String) ois.readObject();
          option = Integer.parseInt(req);
          switch (option) {
          case 0:
            exit = true;
            break;
          case 1:
            option1(ois, oos, students);
            break;
          case 2:
            option2(ois, oos, students);
            break;
          case 3:
            option3(ois, oos, connections);
            break;
          case 4:
            option4(ois, oos, students);
            break;
          default:
            oos.writeObject("\nOpção Inválida\n" + "\nPressione [ENTER] Para continuar");
            ois.readObject();
            break;
          }
        } catch (NumberFormatException e) {
          oos.writeObject("\nOpção Inválida\n" + "\nPressione [ENTER] Para continuar");
          ois.readObject();
        }
      } while (!exit);
    } catch (IOException e) {
      System.out.println("Client disconnected");
    } catch (ClassNotFoundException e) {
      e.printStackTrace();
    }
  }

  private static void option1(ObjectInputStream ois, ObjectOutputStream oos, List<Student> students)
      throws IOException, ClassNotFoundException {
    oos.writeObject("Nome do aluno: ");
    String name = (String) ois.readObject();
    oos.writeObject("Curso do aluno: ");
    String degree = (String) ois.readObject();
    oos.writeObject("Email do aluno: ");
    String email = (String) ois.readObject();
    Student s = new Student(name, degree, email);
    students.add(s);
    save(students, "students.ser");
  }

  private static void option2(ObjectInputStream ois, ObjectOutputStream oos, List<Student> students)
      throws IOException, ClassNotFoundException {
    StringBuilder s = new StringBuilder();
    s.append("\n");
    boolean hasStudents = false;
    for (Student student : students) {
      hasStudents = true;
      s.append(student + "\n");
    }
    if (hasStudents) {
      oos.writeObject(s.toString() + "\nPressione [ENTER] para continuar");
    } else {
      oos.writeObject("\nNo students registered" + "\n\nPressione [ENTER] para continuar");
    }
    ois.readObject();
  }

  private static void option3(ObjectInputStream ois, ObjectOutputStream oos, int connections)
      throws IOException, ClassNotFoundException {
    oos.writeObject("\n" + connections + "\n\nPressione [ENTER] Para continuar");
    ois.readObject();
  }

  private static void option4(ObjectInputStream ois, ObjectOutputStream oos, List<Student> students)
      throws IOException, ClassNotFoundException {
    oos.writeObject("\nNome do aluno: ");
    String name = (String) ois.readObject();
    ArrayList<Student> info = new ArrayList<>();
    for (Student s : students) {
      if (s.getName().equalsIgnoreCase(name))
        info.add(s);
    }
    if (!info.isEmpty()) {
      StringBuilder s = new StringBuilder();
      for (Student student : info) {
        s.append(student + "\n");
      }
      oos.writeObject("\nStudent info:\n\n" + s.toString() + "\nPressione [ENTER] Para continuar");
    } else {
      oos.writeObject("\nNo students found with name: " + name + "\n\nPressione [ENTER] Para continuar");
    }
    ois.readObject();
  }
}
