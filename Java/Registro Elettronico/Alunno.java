public class Alunno extends DatiAnagrafici{
    private int annoScolastico;
    private char sezione;
    private String corso;
    private int matricola;
    private float mediaVoti;

    Alunno(String nome, String cognome, int dataDiNascita, String luogoDiNascita, int annoScolastico, char sezione, String corso, int matricola, float mediaVoti) {
        super(nome, cognome, dataDiNascita, luogoDiNascita);
        this.annoScolastico = annoScolastico;
        this.sezione = sezione;
        this.corso = corso;
        this.matricola = matricola;
        this.mediaVoti = mediaVoti;
    }

    public int getAnnoScolastico() {
        return annoScolastico;
    }

    public char getSezione() {
        return sezione;
    }

    public String getCorso() {
        return corso;
    }

    public int getMatricola() {
        return matricola;
    }

    public float getMediaVoti() {
        return mediaVoti;
    }

    public void setSezione(char sezione) {
        this.sezione = sezione;
    }

    public void setCorso(String corso) {
        this.corso = corso;
    }

    public void setMediaVoti(float mediaVoti) {
        this.mediaVoti = mediaVoti;
    }

    @Override
    public String toString() {
        return "Alunno{" +
                "nome='" + getNome() + '\'' +
                ", cognome='" + getCognome() + '\'' +
                ", dataDiNascita=" + getDataDiNascita() +
                ", luogoDiNascita='" + getLuogoDiNascita() + '\'' +
                ", annoScolastico=" + annoScolastico +
                ", sezione=" + sezione +
                ", corso='" + corso + '\'' +
                ", matricola=" + matricola +
                ", mediaVoti=" + mediaVoti +
                '}';
    }



}
