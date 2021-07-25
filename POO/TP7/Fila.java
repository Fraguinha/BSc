import java.util.ArrayList;

public class Fila {

    private ArrayList<Integer> fila;

    public ArrayList<Integer> getFila() {
        return this.fila;
    }

    public void setFila(ArrayList<Integer> fila) {
        this.fila = fila;
    }

    public void inserir(int i) {
        this.fila.add(i);
    }

    public int remover() {
        return this.fila.remove(0);
    }

    public boolean estaVazia() {
        return this.fila.isEmpty();
    }

    public String toString() {
        return fila.toString();
    }

}
