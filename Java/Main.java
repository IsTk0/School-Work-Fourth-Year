/**
 * In questo file troviamo tutte le creazione delle squadre e la loro stampa in ordine di punteggio, goal fatti, goal subiti e differenza reti
 * 
 * @author Antonio
 * @version 24/10
 */

import java.util.Scanner;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Main{

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        String nomeSquadra = "";
        int partiteVinte = 0, partitePareggiate = 0, partitePerse = 0, goalFatti = 0, goalSubiti = 0;
        
        Squadra squadra1 = new Squadra(nomeSquadra, partiteVinte, partitePareggiate, partitePerse, goalFatti, goalSubiti);
        Squadra squadra2 = new Squadra(nomeSquadra, partiteVinte, partitePareggiate, partitePerse, goalFatti, goalSubiti);
        Squadra squadra3 = new Squadra(nomeSquadra, partiteVinte, partitePareggiate, partitePerse, goalFatti, goalSubiti);
        
        for (int i = 0; i < 3; i++){
            System.out.println("\nInserisci i dati della squadra numero: " + (i+1));
            do{
                System.out.print("Inserisci il nome della squadra -> ");
                nomeSquadra = input.nextLine();
            }while(nomeSquadra.isEmpty());
            
            do{
                System.out.print("Inserisci la quantita di partite vinte -> ");
                partiteVinte = input.nextInt();
            }while(partiteVinte <= 0);
            
            do{
                System.out.print("Inserisci la quantita di partite pareggiate -> ");
                partitePareggiate = input.nextInt();
            }while(partitePareggiate <= 0);
            
            do{
                System.out.print("Inserisci la quantita di partite perse -> ");
                partitePerse = input.nextInt();
            }while(partitePerse <= 0);
            
            do{
                System.out.print("Inserisci la quantita di goal segnati -> ");
                goalFatti = input.nextInt();
            }while(goalFatti < 0);
            
            do{
                System.out.print("Inserisci la quantita di goal subiti -> ");
                goalSubiti = input.nextInt();
            }while(goalSubiti < 0);
            
            int punteggioSquadra = 0;
            
            for (int j = 0; j < partiteVinte; j++){punteggioSquadra = punteggioSquadra + 3;} 
            for (int k = 0; k < partitePareggiate; k++){partitePareggiate = partitePareggiate + 1;} 
            
            if (i == 0){    
                squadra1.setPunteggioSquadra(punteggioSquadra);
                squadra1.setNomeSquadra(nomeSquadra);
                squadra1.setPartiteVinte(partiteVinte);
                squadra1.setPartitePareggiate(partitePareggiate);
                squadra1.setPartitePerse(partitePerse);
                squadra1.setGoalFatti(goalFatti);
                squadra1.setGoalSubiti(goalSubiti);
            }
            else if (i == 1){
                squadra2.setPunteggioSquadra(punteggioSquadra);
                squadra2.setNomeSquadra(nomeSquadra);
                squadra2.setPartiteVinte(partiteVinte);
                squadra2.setPartitePareggiate(partitePareggiate);
                squadra2.setPartitePerse(partitePerse);
                squadra2.setGoalFatti(goalFatti);
                squadra2.setGoalSubiti(goalSubiti);
            }
            else if (i == 2){
                squadra3.setPunteggioSquadra(punteggioSquadra);
                squadra3.setNomeSquadra(nomeSquadra);
                squadra3.setPartiteVinte(partiteVinte);
                squadra3.setPartitePareggiate(partitePareggiate);
                squadra3.setPartitePerse(partitePerse);
                squadra3.setGoalFatti(goalFatti);
                squadra3.setGoalSubiti(goalSubiti);
                
            }
            else{System.out.print("L'esecuzione del programma non è andata come ci aspettavamo.");}
        }
            
        

        System.out.println("\n----------------------------------------------------------------");

        List<Squadra> squadre = new ArrayList<>();
        squadre.add(squadra1);
        squadre.add(squadra2);
        squadre.add(squadra3);

        // Ordine per punti
        Collections.sort(squadre, Comparator.comparingInt(Squadra::getPunteggioSquadra).reversed());

        System.out.println("\nOrdine per punti della classifica (dal maggiore al minore):");
        for (Squadra squadra : squadre) {
            System.out.println("I punti assegnati alla squadra " + squadra.getNomeSquadra() + " sono pari a : " + squadra.getPunteggioSquadra());
        }

        // Ordine per gol fatti
        Collections.sort(squadre, Comparator.comparingInt(Squadra::getGoalFatti).reversed());

        System.out.println("\nOrdine per gol fatti (dal maggiore al minore):");
        for (Squadra squadra : squadre) {
            System.out.println("Goal segnati dalla squadra " + squadra.getNomeSquadra() + " sono: " + squadra.getGoalFatti());
        }

        // Ordine per gol subiti
        Collections.sort(squadre, Comparator.comparingInt(Squadra::getGoalSubiti));

        System.out.println("\nOrdine delle squadre per goal subiti (dal minore al maggiore):");
        for (Squadra squadra : squadre) {
            System.out.println("Goal subiti da squadre avversarie per " + squadra.getNomeSquadra() + " sono: " + squadra.getGoalSubiti());
        }

        // Ordine per differenza reti
        Collections.sort(squadre, Comparator.comparingInt(Squadra::differenzaReti));

        System.out.println("\nOrdine delle squadre per differenza reti (in ordine da chi ha una differenza maggiore, i numeri negativi indicano che il numero di goal subiti sono maggiori dei goal fatti):");
        for (Squadra squadra : squadre) {
            System.out.println("La differenza di reti da parte della squadra " + squadra.getNomeSquadra() + " sono: " + squadra.differenzaReti());
        }

        System.out.println("\n\n\nGrazie ed arrivederci ~ Antonio Carbone");
    }
    
}
