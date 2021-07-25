public class Fila {
    private int[] fila;
    private int n_elementos, dim, in, out;

    // construtor
    public Fila(int n) {
        dim = n;
        fila = new int[dim];
        in = 0;
        out = 0;
    }

    public void inserir(int e) {
        fila[in] = e;
        n_elementos++;
        in = (in + 1) % dim;
    }

    public int retirar() {
        int e = fila[out];
        n_elementos--;
        out = (out + 1) % dim;
        return e;
    }

    public boolean cheia() {
        return (n_elementos == dim);
    }

    public boolean vazia() {
        return (n_elementos == 0);
    }

    public String toString() {
        String s = "";
        for (int i = out; i < out + n_elementos; i++) {
            s += fila[i] + " ";
        }
        return s;
    }
}