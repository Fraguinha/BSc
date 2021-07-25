public class Contador {

    private int count;

    public Contador() {
        this.count = 0;
    }

    public Contador(int n) {
        this.count = n;
    }

    public void incContador() {
        this.count += 1;
    }

    public void incContador(int n) {
        this.count += n;
    }

    public void decContador() {
        this.count -= 1;
    }

    public void decContador(int n) {
        this.count -= n;
    }

    public int showContador() {
        return this.count;
    }

    public String toString() {
        return ("Count: " + this.count);
    }
}