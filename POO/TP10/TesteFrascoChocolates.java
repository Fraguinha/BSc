/**
 * TesteFrascoChocolates
 */
public class TesteFrascoChocolates {
    public static void main(String args[]) {
        int i, valor;
        int fornecedor[] = { 20, 80, 70, 60, 100, 50, 60, 20 };

        FrascoChocolates F = new FrascoChocolates(120, 50);

        for (i = 0; i < 8; i = i + 2) {
            try {
                valor = fornecedor[i];
                F.enche(valor);
                valor = fornecedor[i + 1];
                F.retira(valor);
            } catch (FrascoVazio fv) {
                System.out.println(fv.getMessage());
            } catch (FrascoCheio fc) {
                System.out.println(fc.getMessage());
            }

        }
    }
}
