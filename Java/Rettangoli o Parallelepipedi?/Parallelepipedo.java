class Parallelepipedo extends Rettangolo {
    private double profondita;

    public Parallelepipedo(double base, double altezza, double profondita) {
        super(base, altezza);
        this.profondita = profondita;
    }

    public double getProfondita() {
        return profondita;
    }

    public double volume() {
        return base * altezza * profondita;
    }
}
