/**
 * Dichiarazione della classe Atleta
 * 
 * @author Antonio
 * @version 12/11
 */

public class Atleta
{
    private String nome;
    private String cognome;
    private int annoDiNascita;
    private int altezza;
    private double peso;
    
    public Atleta(String nome, String cognome, int annoDiNascita, int altezza, double peso){
        this.nome = nome;
        this.cognome = cognome; 
        this.annoDiNascita = annoDiNascita;
        this.altezza = altezza; 
        this.peso = peso;
    }
    public String getNome(){return nome;}
    public String getCognome(){return cognome;}

    public String toString(){return "Atleta " + nome + " " + cognome + " è nato nel " + annoDiNascita + " è alto " + altezza + " e pesa " + peso;}
}

