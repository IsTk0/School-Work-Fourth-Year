/*
 * @Descrizione: L'utente inserira il numero di numeri che vuole generare, e che il programma automaticamente sommerrare, e restituira all'utente
 *
 * @Autore: Antonio Carbone
 * @Versione 1.0 11-10-2023
 */

//import java.util.Random;
import java.util.Scanner;
import java.lang.Math;

public class SommaNumeriCasuali {
    public static void main(String args[]){
        //Random random = new Random();
        Scanner input = new Scanner(System.in);

        int sum = 0, numberOfGeneration = 0, rangeOfGeneration;
        
        do{
            System.out.print("Inserisci il numero massimo che si vuole generare randomicamente -> ");
            rangeOfGeneration = input.nextInt();
        }while(rangeOfGeneration <= 0 && rangeOfGeneration <= 2147483647);
        
        do{
            System.out.print("Inserisci il numero di volte che si vuole far generare dei numeri casuali -> ");
            numberOfGeneration = input.nextInt();
        }while(numberOfGeneration <= 0 && numberOfGeneration <= 2147483647); 
        /*
        System.out.println("\nVuoi visualizare ogni passaggio dell'esecuzione del programma?\nInserisci 'S' per vederli, qualsiasi altro carattere verrà interpretato come un no -> ");
        String choose = input.next();
        System.out.println(choose);*/
        
        for (int i = 0; i < numberOfGeneration; i++){
            int numberGenerated = (int)(Math.random() * (rangeOfGeneration ) + 1);
            sum = sum + numberGenerated;
            /*
            if (choose == "S" || choose == "s"){
                System.out.println("\n---- Esecuzione del ciclo iterativo numero: " + (i + 1) + " ----");
                System.out.println("Il numero generato a questa esecuzione del ciclo è pari a -> " + numberGenerated);
                System.out.println("La somma dei numeri generati fino ad ora è pari a -> " + sum);
            }*/
        }
        
        System.out.println("\n\nLa somma dei numeri generati randomicamente è pari a -> " + sum);
    }

}
