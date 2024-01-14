public class Computer {
    private int codiceSeriale;
    private String marca;
    private String modello;
    private float velocitaProcessore;
    private int dimensioneRam;
    private int dimensioneHardDisk;
    private int dimensioneSchermo;
    private int annoAcquisto;

    public Computer(int codiceSeriale, String marca, String modello, float velocitaProcessore, int dimensioneRam, int dimensioneHardDisk, int dimensioneSchermo, int annoAcquisto) {
        this.codiceSeriale = codiceSeriale;
        this.marca = marca;
        this.modello = modello;
        this.velocitaProcessore = velocitaProcessore;
        this.dimensioneRam = dimensioneRam;
        this.dimensioneHardDisk = dimensioneHardDisk;
        this.dimensioneSchermo = dimensioneSchermo;
        this.annoAcquisto = annoAcquisto;
    }

    public int getCodiceSeriale() {
        return codiceSeriale;
    }

    public String getMarca() {
        return marca;
    }

    public String getModello() {
        return modello;
    }

    public float getVelocitaProcessore() {
        return velocitaProcessore;
    }

    public int getDimensioneRam() {
        return dimensioneRam;
    }

    public int getDimensioneHardDisk() {
        return dimensioneHardDisk;
    }

    public int getDimensioneSchermo() {
        return dimensioneSchermo;
    }

    public int getAnnoAcquisto() {
        return annoAcquisto;
    }

    public void setCodiceSeriale(int codiceSeriale) {
        this.codiceSeriale = codiceSeriale;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public void setModello(String modello) {
        this.modello = modello;
    }

    public void setVelocitaProcessore(float velocitaProcessore) {
        this.velocitaProcessore = velocitaProcessore;
    }

    public void setDimensioneRam(int dimensioneRam) {
        this.dimensioneRam = dimensioneRam;
    }

    public void setDimensioneHardDisk(int dimensioneHardDisk) {
        this.dimensioneHardDisk = dimensioneHardDisk;
    }

    public void setDimensioneSchermo(int dimensioneSchermo) {
        this.dimensioneSchermo = dimensioneSchermo;
    }

    public void setAnnoAcquisto(int annoAcquisto) {
        this.annoAcquisto = annoAcquisto;
    }

    public String toString() {
        return "Computer{" +
                "codiceSeriale=" + codiceSeriale +
                ", marca='" + marca + '\'' +
                ", modello='" + modello + '\'' +
                ", velocitaProcessore=" + velocitaProcessore +
                ", dimensioneRam=" + dimensioneRam +
                ", dimensioneHardDisk=" + dimensioneHardDisk +
                ", dimensioneSchermo=" + dimensioneSchermo +
                ", annoAcquisto=" + annoAcquisto +
                '}';
    }
}
