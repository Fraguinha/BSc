import java.time.LocalDate;
import java.time.ZoneId;
import java.util.ArrayList;

/**
 * ContaVencimento
 */
public class ContaVencimento extends Conta {

    private double limite;
    private int NIB;

    public double getLimite() {
        return this.limite;
    }

    public int getNIB() {
        return this.NIB;
    }

    public void setLimite(double limite) {
        this.limite = limite;
    }

    public void setNIB(int NIB) {
        this.NIB = NIB;
    }

    public ContaVencimento(ArrayList<String> Titulares, int saldo, double limite, int NIB) {
        super(Titulares, saldo);
        this.limite = limite;
        this.NIB = NIB;
    }

    public void novoMovimento(String descricao, double montante) {
        if (this.saldo + montante > limite) {
            this.movimentos.add(new Movimento(descricao, montante));
            this.saldo += montante;
        } else {
            System.out.println("Saldo insuficiente!");
        }
    }
}