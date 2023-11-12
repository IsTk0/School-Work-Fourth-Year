/**
 * Classe Main per il progetto "Squadra di calcio"
 *
 * @author Antonio
 * @version 12/11
 */

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        final int GIOCATORI_MAX = 20;

        String nome;
        String cognome;
        int annoDiNascita;
        int altezza;
        double peso;

        Scanner input = new Scanner(System.in);

        Squadra squadra = new Squadra();

        for (int i = 0; i < GIOCATORI_MAX; i++) {
            do {
                System.out.print("\nInserisci il nome dell'atleta numero " + (i + 1) + ": ");
                nome = input.next();
            } while (nome.isEmpty());

            do {
                System.out.print("Inserisci il cognome dell'atleta " + nome + ": ");
                cognome = input.next();
            } while (cognome.isEmpty());

            do {
                System.out.print("Inserisci l'anno di nascita dell'atleta: ");
                annoDiNascita = input.nextInt();
            } while (annoDiNascita < 1900 || annoDiNascita > 2023);

            do {
                System.out.print("Inserisci l'altezza in cm dell'atleta: ");
                altezza = input.nextInt();
            } while (altezza < 40 || altezza > 230);

            do {
                System.out.print("Inserisci il peso in chili dell'atleta: ");
                peso = input.nextDouble();
            } while (peso < 30 || peso > 350);

            Atleta atleta = new Atleta(nome, cognome, annoDiNascita, altezza, peso);

            squadra.setGiocatore(atleta, i);
        }

        squadra.riordinaGiocatori();

        System.out.println("\nEcco i giocatori in ordine alfabetico (per cognome):");

        squadra.printGiocatori();
    }
}
