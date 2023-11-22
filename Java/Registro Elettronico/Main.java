import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        String nome;
        String cognome;
        int dataDiNascita;
        String luogoDiNascita;
        int annoScolastico;
        char sezione;
        String corso;
        int matricola;
        float mediaVoti;

        int numeroAlunni;

        do{
            System.out.print("Inserisci il numero di alunni da inserire: ");
            numeroAlunni = input.nextInt();
        }while (numeroAlunni < 1);

        DatiAnagrafici[] listaAlunni = new DatiAnagrafici[numeroAlunni];

        for (int i = 0; i < numeroAlunni; i++){
            System.out.println("\nInserisci i dati dell'alunno " + (i + 1) + ":");
            do {
                System.out.print("Inserisci il nome dell'alunno: ");
                nome = input.next();
            }while (nome.length() < 2 || nome.isEmpty());

            do {
                System.out.print("Inserisci il cognome dell'alunno: ");
                cognome = input.next();
            }while (cognome.length() < 2 || cognome.isEmpty());

            do {
                System.out.print("Inserisci la data di nascita dell'alunno (solo l'anno): ");
                dataDiNascita = input.nextInt();
            }while (dataDiNascita < 1950 || dataDiNascita > 2023);

            do {
                System.out.print("Inserisci il luogo di nascita dell'alunno: ");
                luogoDiNascita = input.next();
            }while (luogoDiNascita.length() < 2 || luogoDiNascita.isEmpty());

            do {
                System.out.print("Inserisci l'anno scolastico dell'alunno (una sola cifra): ");
                annoScolastico = input.nextInt();
            }while (annoScolastico < 1 || annoScolastico > 5);

            do {
                System.out.print("Inserisci la sezione dell'alunno (un solo carattere in maiuscolo): ");
                sezione = input.next().charAt(0);
            }while (sezione < 'A' || sezione > 'Z');

            do{
                System.out.print("Inserisci il corso dell'alunno: ");
                corso = input.next();
            }while (corso.length() < 2 || corso.isEmpty());

            do {
                System.out.print("Inserisci la matricola dell'alunno (codice da 7 cifre): ");
                matricola = input.nextInt();
            }while (matricola < 1000000 || matricola > 9999999);

            do{
                System.out.print("Inserisci la media dei voti dell'alunno (media assoluta, utilizza la ',' per inserire i decimali): ");
                mediaVoti = input.nextFloat();
            }while (mediaVoti < 0 || mediaVoti > 10);

            listaAlunni[i] = new Alunno(nome, cognome, dataDiNascita, luogoDiNascita, annoScolastico, sezione, corso, matricola, mediaVoti);
        }

        System.out.println("\nEcco l'elenco degli alunni inseriti:\n");

        for (int j = 0; j < numeroAlunni; j++){
            System.out.println(listaAlunni[j].toString());
        }
    }
}
