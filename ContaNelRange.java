/*
 * @Descrizione: Scrivere un programma in Java che dati due valori numerici h e k, legga n valori e conti quanti di essi sono compresi tra h e k, fornendo il risultato
 * 
 * @Autore: Antonio Carbone
 * @Versione 1.0 06-10-2023
 */

import java.util.Scanner;

public class ContaNelRange {
    public static void main(String[] args){
        int counter = 0;

        Scanner input = new Scanner(System.in);

        System.out.print("Inserisci il valore minore nel range (h): ");
        int h = input.nextInt();
        System.out.print("Inserisci il valore minore nel range (k): ");
        int k = input.nextInt();

        System.out.print("Inserisci il numero di valori da leggere e da verificare: ");
        int n = input.nextInt();

        for (int i = 0; i < n; i++) {
            System.out.print("Inserisci il valore numero " + (i + 1) + ": ");
            int value = input.nextInt();

            if (value >= h && value <= k) {
                counter++;
            }
        }

        System.out.println("I valori compresi tra " + h + " e " + k + " sono: " + counter);
    }
}
