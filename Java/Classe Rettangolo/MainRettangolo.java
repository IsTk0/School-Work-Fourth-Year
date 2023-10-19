
/**
 * In questo file è presente la dichiarazione del main per la creazione degli oggetti Rettangolo e le varie manipolazioni dello stesso
 * 
 * @author antonio
 * @version 19/10
 */
import java.util.Scanner;

public class MainRettangolo
{
    public static void Main(String[] args){
        Scanner input = new Scanner(System.in);     //nomeClasse, nomeRiferimento = new nomeCostrutore(paramtri);
        float base, altezza;
        boolean running = true;
        int choose;

        //input
        do{
        System.out.print("Inserisci il valore della base del rettangolo -> ");
        base = input.nextFloat();
        }while(base <= 0);
        do{
            System.out.print("Inserisci il valore dell'altezza del rettangolo -> ");
            altezza = input.nextFloat();
        }while(altezza <= 0);
        
        //creazione oggetto rettangolo
        Rettangolo rettangolo = new Rettangolo(base, altezza);
        
        //area output
        System.out.println(rettangolo.toString());
        
        //menu
        while (running){
            System.out.print("\nInserisci '1' se si vuole modificare la base del oggetto Rettangolo\nInserisci '2' se si vuole modificare l'altezza del oggetto Rettangolo\nInserisci '0 per uscirte da questa funzione per la modifica dei valori del Rettangolo\nInput->");
            choose = input.nextInt();
            if (choose == 1){
                System.out.println("Inserisci la nuova base del oggetto Rettangolo -> ");
                rettangolo.setBase(input.nextFloat());
            }
            else if (choose == 2){
                System.out.println("Inserisci la nuova altezza del oggetto Rettangolo -> ");
                rettangolo.setAltezza(input.nextFloat());
            }
            else if (choose == 0){running = false;}
            
            else {System.out.println("\nIl valore da te inserito, non è corretto, perfavore ri-inserisci il valore in maniera corretta.");}
            System.out.print("\nAttulmente le informazioni inserite all'interno del oggetto rettangolo sono: " + rettangolo.toString());
        }
        
        System.out.println("\n\n\nGrazie ed arrivederci ~ Antonio Carbone");
    }
}
