import java.io.EOFException;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

public class Server {
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

  public static void main(String[] args) {
    int port = 2222;
    try (ServerSocket server = new ServerSocket(port)) {
      ThreadPoolExecutor pool = new ThreadPoolExecutor(5, 10, 5, TimeUnit.SECONDS, new ArrayBlockingQueue<>(10),
          Executors.defaultThreadFactory());
      ArrayList<Student> students = load("students.ser");
      System.out.println("listening on port: " + port);
      int connections = 0;
      while (true) {
        Socket socket = server.accept();
        connections += 1;
        System.out.println("Accepted connection");
        pool.execute(new Connection(socket, students, connections));
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
}
