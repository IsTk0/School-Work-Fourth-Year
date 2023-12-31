import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        Abitazione[] abitazioni = new Abitazione[2];

        int numeroDiPiani;
        int superficie;
        int superficieGiardino;
        int piano;
        int numeroDiBalconi;
        String indirizzo;
        String tipoAbitazione;
        boolean piscina;
        boolean ascensore;

        // Ciclo per l'inserimento automatico dei dati
        for (int i = 0; i < abitazioni.length; i++) {
            System.out.println("Inserisci i dati per l'abitazione " + (i + 1));

            do{
                System.out.print("Numero di piani: ");
                numeroDiPiani = input.nextInt();
            }while(numeroDiPiani <= 0);
            
            do{
                System.out.print("Superficie: ");
                superficie = input.nextInt();
            }while(superficie <= 0);

            do{
                System.out.print("Indirizzo: ");
                indirizzo = input.nextLine();
            }while(indirizzo.length() <= 0);

            do{
                System.out.print("Tipo di abitazione (Villa o Appartamento): ");
                tipoAbitazione = input.nextLine();
            }while(tipoAbitazione.isEmpty());

            if ("Villa".equals(tipoAbitazione)) {
                do{
                    System.out.print("Superficie giardino: ");
                    superficieGiardino = input.nextInt();
                }while(superficieGiardino <= 0);
                
                do{
                    System.out.print("Presenza piscina (true/false): ");
                    piscina = input.nextBoolean();
                }while(piscina != true || piscina != false);

                abitazioni[i] = new Villa(numeroDiPiani, superficie, indirizzo, superficieGiardino, piscina);

            } else if ("Appartamento".equals(tipoAbitazione)) {
                do{
                    System.out.print("Piano: ");
                    piano = input.nextInt();
                }while(piano <= 0);
                
                do{
                    System.out.print("Numero di balconi: ");
                    numeroDiBalconi = input.nextInt();
                }while(numeroDiBalconi <= 0);

                do{
                    System.out.print("Presenza ascensore (true/false): ");
                    ascensore = input.nextBoolean();
                }while(ascensore != true || ascensore != false);

                abitazioni[i] = new Appartamento(numeroDiPiani, superficie, indirizzo, piano, numeroDiBalconi, ascensore);
            } else {
                System.out.println("Tipo di abitazione non riconosciuto. Riprova.");
                i--; 
            }
        }
    }
}
