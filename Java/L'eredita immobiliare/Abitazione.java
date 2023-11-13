public class Abitazione {
    protected int numeroDiPiani;
    protected int superficie;
    protected String indirizzo;

    public Abitazione(int numeroDiPiani, int superficie, String indirizzo) {
        this.numeroDiPiani = numeroDiPiani;
        this.superficie = superficie;
        this.indirizzo = indirizzo;
    }

    public int getNumeroDiPiani() {
        return numeroDiPiani;
    }
    
    public String getIndirizzo() {
        return indirizzo;
    }
    
    public int getSuperficie() {
        return superficie;
    }
    
    public void setNumeroDiPiani(int numeroDiPiani) {
        this.numeroDiPiani = numeroDiPiani;
    }

    public void setSuperficie(int superficie) {
        this.superficie = superficie;
    }

    public void setIndirizzo(String indirizzo) {
        this.indirizzo = indirizzo;
    }
}