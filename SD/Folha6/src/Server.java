import java.io.EOFException;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.MalformedURLException;
import java.net.ServerSocket;
import java.net.Socket;
import java.rmi.Naming;
import java.rmi.RemoteException;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

public class Server implements ServerInterface {

  private ArrayList<Student> students;
  private String filename;
  private int connections;
  private int port;

  private void load() {
    students = new ArrayList<>();
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
  }

  public void save() {
    synchronized (students) {
      try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(filename))) {
        for (Student s : students) {
          oos.writeObject(s);
        }
      } catch (IOException e) {
        e.printStackTrace();
      }
    }
  }

  public List<Student> search(String name) {
    ArrayList<Student> results = new ArrayList<>();
    for (Student s : students) {
      if (s.getName().equalsIgnoreCase(name))
        results.add(s);
    }
    return results;
  }

  public Server(String filename) {
    this.filename = filename;
    this.connections = 0;
    this.port = 2222;
    load();
    try (ServerSocket server = new ServerSocket(port)) {
      ThreadPoolExecutor pool = new ThreadPoolExecutor(5, 10, 5, TimeUnit.SECONDS, new ArrayBlockingQueue<>(10),
          Executors.defaultThreadFactory());
      System.out.println("listening on port: " + port);
      while (true) {
        Socket socket = server.accept();
        connections += 1;
        System.out.println("Accepted connection");
        pool.execute(new Connection(socket, this));
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  public static void main(String[] args) {
    System.setSecurityManager(new SecurityManager());
    try {
      java.rmi.registry.LocateRegistry.createRegistry(1099);
      Server s = new Server("students.ser");
      Naming.rebind("rmi://localhost:1099/ServerService", s);
    } catch (RemoteException | MalformedURLException e) {
      e.printStackTrace();
    }
  }
}
