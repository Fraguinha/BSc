import javax.swing.*;

public class Ex5a {
    public static void main(String[] args) {
        String s;
        int r;
        final double PI = 3.14159273269;

        s = JOptionPane.showInputDialog(null, "Introduza o raio: ");

        r = Integer.parseInt(s);

        JOptionPane.showMessageDialog(null, "O perímetro é: " + (2 * PI * r));
        JOptionPane.showMessageDialog(null, "A área é: " + (PI * r * r));
    }
}