import java.time.LocalDate;
import java.time.ZoneId;

/**
 * Movimento
 */
public class Movimento {

    private final String descricao;
    private final LocalDate date;
    private final double montante;

    public String getDescricao() {
        return this.descricao;
    }

    public LocalDate getDate() {
        return this.date;
    }

    public double getMontante() {
        return this.montante;
    }

    public Movimento(String descricao, double montante) {
        this.descricao = descricao;
        this.montante = montante;
        this.date = LocalDate.now(ZoneId.of("Portugal"));
    }

    public String toString() {
        return (descricao + " " + montante + " " + date + "\n");
    }

}