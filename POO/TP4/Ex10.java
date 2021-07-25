public class Ex10 {

    private static char maior(String s) {

        char c = s.charAt(0);

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) > c) {
                c = s.charAt(i);
            }
        }

        return c;
    }

    public static void main(String[] args) {

        System.out.println(maior(Ler.umaString()));

    }
}