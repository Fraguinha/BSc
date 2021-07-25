public class TesteString {
    public static void main(String[] args) {
        String a = "Carolina";
        String b = "li";
        int c = 0;
        char letra;

        System.out.println("STRING: " + a);
        System.out.println("Caracter na 4 posição: " + a.charAt(3));
        System.out.println("Comprimento da String: " + a.length());
        System.out.println("Concatenar a string " + a + " e a string " + b + ": " + a.concat(b));
        System.out.println("Substring de " + a + " a começar no 3 caracter: " + a.substring(2));
        System.out.println("Localização da substring " + b + " em " + a + ": " + a.indexOf(b));
        System.out.println("Comparação entre a String " + a + " e " + b + ":" + a.compareTo(b));

        String txt = "The competent programmer is fully aware of the limited size of his own skull. He therefore approaches his task with full humility, and avoids clever tricks like the plague.";

        System.out.println("\n\nString:\n" + txt);
        System.out.println("\nQuantos caracteres tem a String (incluindo espaços)?\n" + txt.length());
        for (int i = 0; i < txt.length(); i++) {
            if (txt.charAt(i) != ' ') {
                c++;
            }
        }
        System.out.println("Quantos caracteres tem a String (excluindo espaços)?\n" + c);
        System.out.println("Quantas palavras tem a String?\n" + (txt.length() - c + 1) + "\n");

        for (int i = 0; i < 26; i++) {
            c = 0;
            for (int j = 0; j < txt.length(); j++) {
                if (txt.charAt(j) == (char) (65 + i) || txt.charAt(j) == (char) (97 + i)) {
                    c++;
                }
            }
            letra = (char) (65 + i);
            System.out.println(letra + ": " + c);
        }

        System.out.println("Introduza uma palavra:\n");
        a = Ler.umaString();

        if (txt.indexOf(a) >= 0) {
            System.out.println("\nA substring existe na string e encontra-se na posição: " + txt.indexOf(a));
        } else {
            System.out.println("\nA substring não existe na string.");
        }

    }
}