public class Rettangolo {
    protected double base;
    protected double altezza;

    public Rettangolo(double base, double altezza) {
        this.base = base;
        this.altezza = altezza;
    }

    public double area() {
        return base * altezza;
    }
}
