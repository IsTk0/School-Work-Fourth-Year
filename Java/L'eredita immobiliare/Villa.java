public class Villa extends Abitazione {
    private int superficieGiardino;
    private boolean piscina;

    public Villa(int numeroDiPiani, int superficie, String indirizzo, int superficieGiardino, boolean piscina) {
        super(numeroDiPiani, superficie, indirizzo);  
        this.superficieGiardino = superficieGiardino;
        this.piscina = piscina;
    }

    public int getSuperficieGiardino() {
        return superficieGiardino;
    }
    
    public boolean getPiscina() {
        return piscina;
    }

    public void setSuperficieGiardino(int superficieGiardino) {
        this.superficieGiardino = superficieGiardino;
    }
    
    public void setPiscina(boolean piscina) {
        this.piscina = piscina;
    }
}