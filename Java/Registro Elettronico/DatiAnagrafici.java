public class DatiAnagrafici {
    private String nome;
    private String cognome;
    private int dataDiNascita;
    private String luogoDiNascita;

    DatiAnagrafici(String nome, String cognome, int dataDiNascita, String luogoDiNascita) {
        this.nome = nome;
        this.cognome = cognome;
        this.dataDiNascita = dataDiNascita;
        this.luogoDiNascita = luogoDiNascita;
    }

    public String getNome() {
        return nome;
    }

    public String getCognome() {
        return cognome;
    }

    public int getDataDiNascita() {
        return dataDiNascita;
    }

    public String getLuogoDiNascita() {
        return luogoDiNascita;
    }

    public String toString() {
        return "DatiAnagrafici{" + "nome='" + nome + '\'' + ", cognome='" + cognome + '\'' + ", dataDiNascita=" + dataDiNascita + ", luogoDiNascita='" + luogoDiNascita + '\'' + '}';
    }
}
