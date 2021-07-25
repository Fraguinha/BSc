import java.time.LocalDate;
import java.time.ZoneId;
import java.util.ArrayList;

/**
 * Conta
 */
public class Conta {

    protected final int numero;
    protected ArrayList<String> titulares;
    protected final LocalDate dataCriacao;
    protected double saldo;
    protected final ArrayList<Movimento> movimentos;
    private static int nContas = 0;

    public Conta(ArrayList<String> titulares, double saldo) {
        this.numero = (++nContas);
        this.titulares = titulares;
        this.dataCriacao = LocalDate.now(ZoneId.of("Portugal"));
        this.saldo = saldo;
        this.movimentos = new ArrayList<Movimento>();
    }

    public int getNumero() {
        return this.numero;
    }

    public ArrayList<String> getTitulares() {
        return this.titulares;
    }

    public LocalDate getData() {
        return this.dataCriacao;
    }

    public double getSaldo() {
        return this.saldo;
    }

    public void setTitulares(ArrayList<String> titulares) {
        this.titulares = titulares.clone();
    }

    public void novoMovimento(String descricao, double montante) {
        if (this.saldo + montante > 0) {
            this.movimentos.add(new Movimento(descricao, montante));
            this.saldo += montante;
        } else {
            System.out.println("Saldo insuficiente!");
        }
    }

    public ArrayList<Movimento> getUltimosMovimentos(int n) {
        if (this.movimentos.size() >= n) {
            ArrayList<Movimento> ultimosMovimentos = new ArrayList<Movimento>(
                    this.movimentos.subList(this.movimentos.size() - n, this.movimentos.size()));
            return ultimosMovimentos;
        } else {
            return this.movimentos;
        }

    }
}
