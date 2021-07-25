import java.time.LocalDate;
import java.time.ZoneId;
import java.util.ArrayList;
import java.time.temporal.ChronoUnit;

/**
 * ContaAPrazo
 */
public class ContaAPrazo extends Conta {

    public void addJuros() {
        double juros = (ChronoUnit.DAYS.between(super.dataCriacao, LocalDate.now())) * 0.01;
        super.saldo += juros;
    }

    public ContaAPrazo(ArrayList<String> Titulares, int saldo) {
        super(Titulares, saldo);
    }
}
