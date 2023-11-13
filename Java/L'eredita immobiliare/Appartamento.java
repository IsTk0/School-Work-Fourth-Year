public class Appartamento extends Abitazione {
    private int piano;
    private int numeroDiBalconi;
    private boolean ascensore;

    public Appartamento(int numeroDiPiani, int superficie, String indirizzo, int piano, int numeroDiBalconi, boolean ascensore) {
        super(numeroDiPiani, superficie, indirizzo);  
        this.piano = piano;
        this.numeroDiBalconi = numeroDiBalconi;
        this.ascensore = ascensore;
    }

    public int getPiano() {
        return piano;
    }

    public boolean getAscensore() {
        return ascensore;
    }
    
    public int getNumeroDiBalconi() {
        return numeroDiBalconi;
    }

    public void setPiano(int piano) {
        this.piano = piano;
    }

    public void setNumeroDiBalconi(int numeroDiBalconi) {
        this.numeroDiBalconi = numeroDiBalconi;
    }

    public void setAscensore(boolean ascensore) {
        this.ascensore = ascensore;
    }
}