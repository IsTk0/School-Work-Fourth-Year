/**
 * Aggiungi qui una descrizione della classe MyApp
 * 
 * @author (il tuo nome) 
 * @version (un numero di versione o una data)
 */

import java.util.Scanner;


public class Main
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Buondì, quanti atleti sono presenti nella squadra > ");
        int numeroAtleti = input.nextInt();
        
        Atleta[] listaAtleti = new Atleta[numeroAtleti];
        
        String nome = "", cognome = "";
        int annoDiNascita = 0, altezza = 0, annoAttuale = 2023;
        double peso = 0;

        for (int i = 0; i < numeroAtleti; i++){
            do{
                System.out.print("\nInserisci il nome dell'altleta numero " + (i + 1) + ": ");
                nome = input.next();
            }while(nome.isEmpty());
            
            do{
                System.out.print("Inserisci il cognome dell'altleta " + nome + ": ");
                cognome = input.next();
            }while(cognome.isEmpty());
                
            do{
                System.out.print("Inserisci l'anno di nascita dell'altleta: ");
                annoDiNascita = input.nextInt();
            }while(annoDiNascita >= 1900 && annoDiNascita <= annoAttuale);
            
            do{
                System.out.print("Inserisci l'altezza in cm dell'altleta: ");
                altezza = input.nextInt();
            }while(altezza >= 40 && altezza <= 230);
            
            do{
                System.out.print("Inserisci il peso in chili dell'altleta: ");
                peso = input.nextDouble();
            }while(peso >= 30 && peso <= 350);
            
            listaAtleti[i] = new Atleta(nome, cognome, annoDiNascita, altezza, peso);
        }
        
        System.out.println("\nEcco la lista di tutti gli atleti da te inseriti");
        
        int numeroAtletaPiuGiovane = 0;
        
        for (int j = 0; j < numeroAtleti; j++){
            System.out.println(listaAtleti[j].toString());
            if (listaAtleti[numeroAtletaPiuGiovane].getAnnoDiNascita() <= listaAtleti[j].getAnnoDiNascita()){ numeroAtletaPiuGiovane = j;}
        }
        
        System.out.println("L'atleta piu giovane è: " + listaAtleti[numeroAtletaPiuGiovane].toString());
        System.out.println("Arrivederci!");
    }
}