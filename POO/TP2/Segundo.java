import java.util.*;

public class Segundo {

    private static String[] saudacoes = { "Bom dia", "Boa tarde", "Boa noite" };
    private static String nome = "Fraga";
    private static int horas;
    private static int minutos;
    private static int dia;
    private static String mes;
    private static int ano;

    public static void getHoras() {

        GregorianCalendar calend = new GregorianCalendar();

        horas = calend.get(Calendar.HOUR_OF_DAY);
        minutos = calend.get(Calendar.MINUTE);

        dia = calend.get(Calendar.DAY_OF_MONTH);
        mes = calend.get(Calendar.MONTH);
        ano = calend.get(Calendar.YEAR);
    }

    private static int periodoDia(int h) {
        return (h + 20) / 8 % 3;
    }

    public static void main(String args[]) {

        String msg1, msg2;
        getHoras();
        msg1 = minutos == 0 ? horas + " em ponto " : horas + " hora" + (horas == 1 ? "" : "s");
        msg2 = " e " + minutos + " minuto" + (minutos != 1 ? "s" : "");
        System.out.println(saudacoes[periodoDia(horas)] + ", " + nome);
        System.out.println(msg1 + (minutos == 0 ? "" : msg2));
        System.out.println(dia + "/" + mes + "/" + ano);
    }
}