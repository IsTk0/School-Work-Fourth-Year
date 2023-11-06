/**
 * Aggiungi qui una descrizione della classe Atleta
 * 
 * @author (il tuo nome) 
 * @version (un numero di versione o una data)
 */

public class Atleta
{
    private String nome = "", cognome = "";
    private int annoDiNascita = 0, altezza = 0;
    private double peso = 0;
    
    public Atleta(String nome, String cognome, int annoDiNascita, int altezza, double peso){
        this.nome = nome;
        this.cognome = cognome; 
        this.annoDiNascita = annoDiNascita;
        this.altezza = altezza; 
        this.peso = peso;
    }
    
    public String getNome(){return nome;}
    public String getCognome(){return cognome;}
    public int getAnnoDiNascita(){return annoDiNascita;}
    public int getAltezza(){return altezza;}
    public double getPeso(){return peso;}
    
    public String toString(){return "L'atleta " + nome + " " + cognome + " è nato nel " + annoDiNascita + " è alto " + altezza + " e pesa " + peso;}
}