public class Base {

    protected int a;
    protected int b;

    public int getA() {
        return this.a;
    }

    public int getB() {
        return this.b;
    }

    public void setA(int a) {
        this.a = a;
    }

    public void setB(int b) {
        this.b = b;
    }

    public Base() {
        this.a = 0;
        this.b = 0;
    }

    public Base(int a, int b) {
        this.a = a;
        this.b = b;
    }

    public String toString() {
        return "Base{a=" + this.a + ", b=" + this.b + "}";
    }

    @Override
    public boolean equals(Object obj) {

        if (this == obj)
            return true;

        if (obj != null && obj instanceof Base) {

            Base b = (Base) obj;
            if (this.a == b.a && this.b == b.b)
                return true;
        }

        return false;
    }

    @Override
    public Object clone() {
        Base b = new Base(this.a, this.b);
        return (Object) b;
    }

    public int soma() {
        return a + b;
    }

    public int soma(int x) {
        return a + b + x;
    }

}