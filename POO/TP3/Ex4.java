public class Ex4 {
    public static void main(String[] args) {

        int numero = 0;
        int p[] = new int[2];
        Double decNum, rD;
        numero = -100000;
        decNum = 12345.6789;
        System.out.println("O valor da variável inteira é: " + numero);
        System.out.println("O valor da variável real é: " + decNum);
        char letra = 'A';
        System.out.println(letra);
        letra = 65;
        System.out.println(letra);
        letra = 97;
        System.out.println(letra);
        float x = 12.5f, y = 3E30F, zero = 0f, rF;
        byte b = 127;
        short sht = 9;
        long lng = 0xEFFFFFFF, rL;
        System.out.println(lng);
        rL = lng * 10;
        System.out.println("rL: " + rL);
        rF = lng + 1;
        System.out.println("rF: " + rF);
        rF = (float) (x * y / decNum);
        System.out.println("rF: " + rF);
        rD = (double) (x * y / p[1]);
        System.out.println("rD: " + rD);
        rF = 0 / 1;
        System.out.println("rF: " + rF);
        rF = sht + b * y * x * lng;
        System.out.println("rF: " + rF);
        rD = -b * (sht + zero + x * lng + y * decNum * -numero / letra);
        System.out.println("rD: " + rD);
        rD = 1E269;
        System.out.println("rD: " + rD);

    }
}