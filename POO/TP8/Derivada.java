/**
 * Derivada
 */
public class Derivada extends Base {
    private int a, c;

    public Derivada(Base b, int a, int c) {
        super(b.a, b.b);
        this.a = a;
        this.c = c;
    }

    public void setA(int a) {
        this.a = a;
    }

    public void setC(int c) {
        this.c = c;
    }

    public int getA() {
        return a;
    }

    public int getC() {
        return c;
    }

    public String toString() {
        return "Derivada{a=" + this.a + ", b=" + this.b + ", c=" + this.c;
    }

    public int soma() {
        return this.a + this.b + this.c;
    }

    public boolean equals(Object obj) {
        if (this == obj)
            return true;

        if (obj != null && obj instanceof Derivada) {
            Derivada d = (Derivada) obj;
            if (super.equals(d) && this.a == d.getA() && this.c == d.getC()) {
                return true;
            }
        }
        return false;
    }

    public Object clone() {
        Base b = new Base(super.getA(), super.getB());
        Derivada d = new Derivada(b, this.a, this.c);

        return (Object) d;
    }
}