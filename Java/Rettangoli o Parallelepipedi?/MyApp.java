import java.util.Scanner;
public class MyApp {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Inserisci il numero di parallelepipedi: ");
        int numParallelepipedi = scanner.nextInt();
        Parallelepipedo[] parallelepipediArray = new Parallelepipedo[numParallelepipedi];

        for (int i = 0; i < numParallelepipedi; i++) {
            System.out.println("Inserimento parallelepipedo " + (i + 1) + ":");

            double base, altezza, profondita;

            do {
                System.out.print("Inserisci la base: ");
                base = scanner.nextDouble();
            } while (base <= 0);

            do {
                System.out.print("Inserisci l'altezza: ");
                altezza = scanner.nextDouble();
            } while (altezza <= 0);

            do {
                System.out.print("Inserisci la profondità: ");
                profondita = scanner.nextDouble();
            } while (profondita <= 0);

            parallelepipediArray[i] = new Parallelepipedo(base, altezza, profondita);
        }

        // Visualizza in ordine di inserimento
        System.out.println("\nParallelepipedi in ordine di inserimento:");
        for (int i = 0; i < parallelepipediArray.length; i++) {
            Parallelepipedo parallelepipedo = parallelepipediArray[i];
            System.out.println("Parallelepipedo " + (i + 1) + ": Base = " + parallelepipedo.base +
                    ", Altezza = " + parallelepipedo.altezza + ", Profondità = " + parallelepipedo.getProfondita());
        }

        // Ordina gli oggetti in base al volume crescente
        for (int i = 0; i < parallelepipediArray.length - 1; i++) {
            for (int j = 0; j < parallelepipediArray.length - 1 - i; j++) {
                if (parallelepipediArray[j].volume() > parallelepipediArray[j + 1].volume()) {
                    Parallelepipedo temp = parallelepipediArray[j];
                    parallelepipediArray[j] = parallelepipediArray[j + 1];
                    parallelepipediArray[j + 1] = temp;
                }
            }
        }

        // Visualizza in ordine di volume crescente
        System.out.println("\nParallelepipedi in ordine di volume crescente:");
        for (int i = 0; i < parallelepipediArray.length; i++) {
            Parallelepipedo parallelepipedo = parallelepipediArray[i];
            System.out.println("Parallelepipedo " + (i + 1) + ": Base = " + parallelepipedo.base +
                    ", Altezza = " + parallelepipedo.altezza + ", Profondità = " + parallelepipedo.getProfondita() +
                    ", Volume = " + parallelepipedo.volume());
        }
    }
}
