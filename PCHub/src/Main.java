import java.util.*;

public class Main {

    public static int generatoreCodiceSeriale(int codiceSeriale) {
        codiceSeriale++;
        return codiceSeriale;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int numeroDevice = 0;
        boolean inserimento = true;
        boolean eccezioneSollevata = false;

        while (inserimento == true) {
            try {
                numeroDevice = 0;
                System.out.println("Il numero che andrai a inserire è il numero di computer che vuoi inserire adesso.\nHai 1000 slot di computer inseribili in totale per il futuro. ");
                System.out.println("Inserisci il numero di computer che si vuole inserire: ");
                numeroDevice = input.nextInt();
            } catch (InputMismatchException e) {
                System.out.println("Errore: Il dato che si è inserito non corrisponde con il tipo previsto.");
                input.nextLine();
                eccezioneSollevata = true;
            } finally {
                if (numeroDevice > 0 && numeroDevice <= 1000) {
                    inserimento = false;
                }
                if (eccezioneSollevata == false && (numeroDevice <= 0 || numeroDevice > 1000)) {
                    System.out.println("Errore: La marca del computer non può essere vuota.");
                }
            }
        }

        Computer[] listaDevice = new Computer[1000];

        int codiceSeriale = 00000;
        int slotCompilati = 0;

        for (; slotCompilati < numeroDevice; slotCompilati++) {

            codiceSeriale = generatoreCodiceSeriale(codiceSeriale);

            String marca = "";
            String modello = "";
            float velocitaProcessore = 0;
            int dimensioneRam = 0;
            int dimensioneHardDisk = 0;
            int dimensioneSchermo = 0;
            int annoAcquisto = 0;

            boolean inserimentoMarca = true;
            eccezioneSollevata = false;
            while (inserimentoMarca == true) {
                try {
                    marca = "";
                    System.out.println("Inserisci la marca del computer: ");
                    marca = input.next();
                } catch (InputMismatchException e) {
                    System.out.println("Errore: Il dato che si è inserito non corrisponde con il tipo previsto.");
                    input.nextLine();
                    eccezioneSollevata = true;
                } finally {
                    if (marca != "") {
                        inserimentoMarca = false;
                    }
                    if (eccezioneSollevata == false && marca == "") {
                        System.out.println("Errore: La marca del computer non può essere vuota.");
                    }
                }
            }

            boolean inserimentoModello = true;
            eccezioneSollevata = false;
            while (inserimentoModello == true) {
                try {
                    modello = "";
                    System.out.println("Inserisci il modello del computer: ");
                    modello = input.next();
                } catch (InputMismatchException e) {
                    System.out.println("Errore: Il dato che si è inserito non corrisponde con il tipo previsto.");
                    input.nextLine();
                    eccezioneSollevata = true;
                } finally {
                    if (modello != "") {
                        inserimentoModello = false;
                    }
                    if (eccezioneSollevata == false && modello == "") {
                        System.out.println("Errore: Il modello del computer non può essere vuoto.");
                    }
                }
            }

            boolean inserimentoVelocitaProcessore = true;
            eccezioneSollevata = false;
            while (inserimentoVelocitaProcessore == true) {
                try {
                    velocitaProcessore = 0;
                    System.out.println("Inserisci la velocità del processore del computer: ");
                    velocitaProcessore = input.nextFloat();
                } catch (InputMismatchException e) {
                    System.out.println("Errore: Il dato che si è inserito non corrisponde con il tipo previsto.");
                    input.nextLine();
                    eccezioneSollevata = true;
                } finally {
                    if (velocitaProcessore > 0) {
                        inserimentoVelocitaProcessore = false;
                    }
                    if (eccezioneSollevata == false && velocitaProcessore <= 0) {
                        System.out.println("Errore: La velocità del processore del computer non può minore o uguale a 0.");
                    }
                }
            }

            boolean inserimentoDimensioneRam = true;
            eccezioneSollevata = false;
            while (inserimentoDimensioneRam == true) {
                try {
                    dimensioneRam = 0;
                    System.out.println("Inserisci la dimensione della RAM del computer: ");
                    dimensioneRam = input.nextInt();
                } catch (InputMismatchException e) {
                    System.out.println("Errore: Il dato che si è inserito non corrisponde con il tipo previsto.");
                    input.nextLine();
                    eccezioneSollevata = true;
                } finally {
                    if (dimensioneRam > 0) {
                        inserimentoDimensioneRam = false;
                    }
                    if (eccezioneSollevata == false && dimensioneRam <= 0) {
                        System.out.println("Errore: La dimensione della RAM del computer non può essere minore o uguale a 0.");
                    }
                }
            }

            boolean inserimentoDimensioneHardDisk = true;
            eccezioneSollevata = false;
            while (inserimentoDimensioneHardDisk == true) {
                try {
                    dimensioneHardDisk = 0;
                    System.out.println("Inserisci la dimensione dell'hard disk del computer: ");
                    dimensioneHardDisk = input.nextInt();
                } catch (InputMismatchException e) {
                    System.out.println("Errore: Il dato che si è inserito non corrisponde con il tipo previsto.");
                    input.nextLine();
                    eccezioneSollevata = true;
                } finally {
                    if (dimensioneHardDisk > 0) {
                        inserimentoDimensioneHardDisk = false;
                    }
                    if (eccezioneSollevata == false && dimensioneHardDisk <= 0) {
                        System.out.println("Errore: La dimensione dell'hard disk del computer non può essere minore o uguale a 0.");
                    }
                }
            }

            boolean inserimentoDimensioneSchermo = true;
            eccezioneSollevata = false;
            while (inserimentoDimensioneSchermo == true) {
                try {
                    dimensioneSchermo = 0;
                    System.out.println("Inserisci la dimensione dello schermo del computer: ");
                    dimensioneSchermo = input.nextInt();
                } catch (InputMismatchException e) {
                    System.out.println("Errore: Il dato che si è inserito non corrisponde con il tipo previsto.");
                    input.nextLine();
                    eccezioneSollevata = true;
                } finally {
                    if (dimensioneSchermo > 0) {
                        inserimentoDimensioneSchermo = false;
                    }
                    if (eccezioneSollevata == false && dimensioneSchermo <= 0) {
                        System.out.println("Errore: La dimensione dello schermo del computer non può essere minore o uguale a 0.");
                    }
                }
            }

            boolean inserimentoAnnoAcquisto = true;
            eccezioneSollevata = false;
            while (inserimentoAnnoAcquisto == true) {
                try {
                    annoAcquisto = 0;
                    System.out.println("Inserisci l'anno di acquisto del computer: ");
                    annoAcquisto = input.nextInt();
                } catch (InputMismatchException e) {
                    System.out.println("Errore: Il dato che si è inserito non corrisponde con il tipo previsto.");
                    input.nextLine();
                    eccezioneSollevata = true;
                } finally {
                    if (annoAcquisto <= 2024 && annoAcquisto >= 1960) {
                        inserimentoAnnoAcquisto = false;
                    }
                    if (eccezioneSollevata == false && (annoAcquisto > 2024 || annoAcquisto < 1960)) {
                        System.out.println("Errore: L'anno di acquisto del computer non può essere maggiore del 2024 e minore del 1960.");
                    }
                }
            }

            listaDevice[slotCompilati] = new Computer(codiceSeriale, marca, modello, velocitaProcessore, dimensioneRam, dimensioneHardDisk, dimensioneSchermo, annoAcquisto);
            System.out.println("Computer inserito con successo. Seguono i dati inseriti: " + listaDevice[slotCompilati].toString());
        }

        boolean mostraMenu = true;
        int scelta = 0;

        do {
            System.out.println("\nScegli un'opzione:");
            System.out.println("1. Aggiungi un nuovo computer");
            System.out.println("2. Elimina un computer tramite codice seriale");
            System.out.println("3. Mostra tutti i computer");
            System.out.println("4. Ricerca dati per codice seriale");
            System.out.println("5. Ricerca per caratteristiche di velocità del processore (maggiore uguale all'input)");
            System.out.println("6. Ricerca per capienza ram (maggiore uguale all'input)");
            System.out.println("7. Ricerca per capienza hard disk (maggiore uguale all'input)");
            System.out.println("0. Esci");

            boolean inserimentoScelta = true;
            eccezioneSollevata = false;
            while (inserimentoScelta == true) {
                try {
                    scelta = 0;
                    System.out.println("Inserisci la sezione del menu alla quale si vuole accedere: ");
                    scelta = input.nextInt();
                } catch (InputMismatchException e) {
                    System.out.println("Errore: Il dato che si è inserito non corrisponde con il tipo previsto.");
                    input.nextLine();
                    eccezioneSollevata = true;
                } finally {
                    if (scelta <= 7 && scelta >= 0) {
                        inserimentoScelta = false;
                    }
                    if (eccezioneSollevata == false && (scelta < 0 || scelta > 7)) {
                        System.out.println("Errore: la tua scelta è al di fuori del range del menu");
                    }
                }
            }

            switch (scelta) {
                case 0:
                    System.out.println("Hai scelto di uscire dal programma.");
                    mostraMenu = false;
                    break;
                case 1:
                    codiceSeriale = generatoreCodiceSeriale(codiceSeriale);

                    String marca = "";
                    String modello = "";
                    float velocitaProcessore = 0;
                    int dimensioneRam = 0;
                    int dimensioneHardDisk = 0;
                    int dimensioneSchermo = 0;
                    int annoAcquisto = 0;

                    boolean inserimentoMarca = true;
                    eccezioneSollevata = false;
                    while (inserimentoMarca == true) {
                        try {
                            marca = "";
                            System.out.println("Inserisci la marca del computer: ");
                            marca = input.next();
                        } catch (InputMismatchException e) {
                            System.out.println("Errore: Il dato che si è inserito non corrisponde con il tipo previsto.");
                            input.nextLine();
                            eccezioneSollevata = true;
                        } finally {
                            if (marca != "") {
                                inserimentoMarca = false;
                            }
                            if (eccezioneSollevata == false && marca == "") {
                                System.out.println("Errore: La marca del computer non può essere vuota.");
                            }
                        }
                    }

                    boolean inserimentoModello = true;
                    eccezioneSollevata = false;
                    while (inserimentoModello == true) {
                        try {
                            modello = "";
                            System.out.println("Inserisci il modello del computer: ");
                            modello = input.next();
                        } catch (InputMismatchException e) {
                            System.out.println("Errore: Il dato che si è inserito non corrisponde con il tipo previsto.");
                            input.nextLine();
                            eccezioneSollevata = true;
                        } finally {
                            if (modello != "") {
                                inserimentoModello = false;
                            }
                            if (eccezioneSollevata == false && modello == "") {
                                System.out.println("Errore: Il modello del computer non può essere vuoto.");
                            }
                        }
                    }

                    boolean inserimentoVelocitaProcessore = true;
                    eccezioneSollevata = false;
                    while (inserimentoVelocitaProcessore == true) {
                        try {
                            velocitaProcessore = 0;
                            System.out.println("Inserisci la velocità del processore del computer: ");
                            velocitaProcessore = input.nextFloat();
                        } catch (InputMismatchException e) {
                            System.out.println("Errore: Il dato che si è inserito non corrisponde con il tipo previsto.");
                            input.nextLine();
                            eccezioneSollevata = true;
                        } finally {
                            if (velocitaProcessore > 0) {
                                inserimentoVelocitaProcessore = false;
                            }
                            if (eccezioneSollevata == false && velocitaProcessore <= 0) {
                                System.out.println("Errore: La velocità del processore del computer non può minore o uguale a 0.");
                            }
                        }
                    }

                    boolean inserimentoDimensioneRam = true;
                    eccezioneSollevata = false;
                    while (inserimentoDimensioneRam == true) {
                        try {
                            dimensioneRam = 0;
                            System.out.println("Inserisci la dimensione della RAM del computer: ");
                            dimensioneRam = input.nextInt();
                        } catch (InputMismatchException e) {
                            System.out.println("Errore: Il dato che si è inserito non corrisponde con il tipo previsto.");
                            input.nextLine();
                            eccezioneSollevata = true;
                        } finally {
                            if (dimensioneRam > 0) {
                                inserimentoDimensioneRam = false;
                            }
                            if (eccezioneSollevata == false && dimensioneRam <= 0) {
                                System.out.println("Errore: La dimensione della RAM del computer non può essere minore o uguale a 0.");
                            }
                        }
                    }

                    boolean inserimentoDimensioneHardDisk = true;
                    eccezioneSollevata = false;
                    while (inserimentoDimensioneHardDisk == true) {
                        try {
                            dimensioneHardDisk = 0;
                            System.out.println("Inserisci la dimensione dell'hard disk del computer: ");
                            dimensioneHardDisk = input.nextInt();
                        } catch (InputMismatchException e) {
                            System.out.println("Errore: Il dato che si è inserito non corrisponde con il tipo previsto.");
                            input.nextLine();
                            eccezioneSollevata = true;
                        } finally {
                            if (dimensioneHardDisk > 0) {
                                inserimentoDimensioneHardDisk = false;
                            }
                            if (eccezioneSollevata == false && dimensioneHardDisk <= 0) {
                                System.out.println("Errore: La dimensione dell'hard disk del computer non può essere minore o uguale a 0.");
                            }
                        }
                    }

                    boolean inserimentoDimensioneSchermo = true;
                    eccezioneSollevata = false;
                    while (inserimentoDimensioneSchermo == true) {
                        try {
                            dimensioneSchermo = 0;
                            System.out.println("Inserisci la dimensione dello schermo del computer: ");
                            dimensioneSchermo = input.nextInt();
                        } catch (InputMismatchException e) {
                            System.out.println("Errore: Il dato che si è inserito non corrisponde con il tipo previsto.");
                            input.nextLine();
                            eccezioneSollevata = true;
                        } finally {
                            if (dimensioneSchermo > 0) {
                                inserimentoDimensioneSchermo = false;
                            }
                            if (eccezioneSollevata == false && dimensioneSchermo <= 0) {
                                System.out.println("Errore: La dimensione dello schermo del computer non può essere minore o uguale a 0.");
                            }
                        }
                    }

                    boolean inserimentoAnnoAcquisto = true;
                    eccezioneSollevata = false;
                    while (inserimentoAnnoAcquisto == true) {
                        try {
                            annoAcquisto = 0;
                            System.out.println("Inserisci l'anno di acquisto del computer: ");
                            annoAcquisto = input.nextInt();
                        } catch (InputMismatchException e) {
                            System.out.println("Errore: Il dato che si è inserito non corrisponde con il tipo previsto.");
                            input.nextLine();
                            eccezioneSollevata = true;
                        } finally {
                            if (annoAcquisto <= 2024 && annoAcquisto >= 1960) {
                                inserimentoAnnoAcquisto = false;
                            }
                            if (eccezioneSollevata == false && (annoAcquisto > 2024 || annoAcquisto < 1960)) {
                                System.out.println("Errore: L'anno di acquisto del computer non può essere maggiore del 2024 e minore del 1960.");
                            }
                        }
                    }
                    slotCompilati++;
                    listaDevice[slotCompilati] = new Computer(codiceSeriale, marca, modello, velocitaProcessore, dimensioneRam, dimensioneHardDisk, dimensioneSchermo, annoAcquisto);
                    System.out.println("Computer inserito con successo. Seguono i dati inseriti: " + listaDevice[slotCompilati].toString());

                    break;
                case 2:
                    inserimento = true;
                    while (inserimento == true) {
                        int codiceSerialeRicerca = 0;
                        try {
                            System.out.println("Inserisci il codice seriale del computer che si vuole eliminare dal database: ");
                            codiceSerialeRicerca = input.nextInt();
                        } catch (InputMismatchException e) {
                            System.out.println("Errore: Il dato che si è inserito non corrisponde con il tipo previsto.");
                            input.nextLine();
                            eccezioneSollevata = true;
                        } finally {
                            if (codiceSerialeRicerca >= 00000 && codiceSerialeRicerca <= 1000) {
                                inserimento = false;
                            }
                            if (eccezioneSollevata == false && (codiceSerialeRicerca <= 00000 || codiceSerialeRicerca > 1000)) {
                                System.out.println("Errore: il codice seriale da te inserito non è presente nel database.");
                            }
                        }
                        for (int i = 0; i < numeroDevice; i++) {
                            if (listaDevice[i].getCodiceSeriale() == codiceSeriale) {
                                listaDevice[i].setCodiceSeriale(99999);
                                listaDevice[i].setMarca(null);
                                listaDevice[i].setModello(null);
                                listaDevice[i].setVelocitaProcessore(0);
                                listaDevice[i].setDimensioneRam(0);
                                listaDevice[i].setDimensioneHardDisk(0);
                                listaDevice[i].setDimensioneSchermo(0);
                                listaDevice[i].setAnnoAcquisto(0);
                                System.out.println("Computer eliminato con successo.");
                            }
                        }
                    }
                    break;
                case 3:
                    for (int i = 0; i < slotCompilati; i++) {
                        try{
                            if (listaDevice[i].getCodiceSeriale() != 99999) {
                                System.out.println(listaDevice[i].toString());
                            }
                        } catch (java.lang.NullPointerException e) {
                            System.out.println("Errore: Non ci sono computer inseriti nel database in questa posizione: " + i);
                        }
                    }
                    break;
                case 4:
                    int codiceSerialeRicerca = 0;
                    try {
                        System.out.println("Inserisci il codice seriale del computer che cui si vuole mostrare nel database: ");
                        codiceSerialeRicerca = input.nextInt();
                    } catch (InputMismatchException e) {
                        System.out.println("Errore: Il dato che si è inserito non corrisponde con il tipo previsto.");
                        input.nextLine();
                        eccezioneSollevata = true;
                    } finally {
                        if (codiceSerialeRicerca >= 00000 && codiceSerialeRicerca <= 1000) {
                            inserimento = false;
                        }
                        if (eccezioneSollevata == false && (codiceSerialeRicerca <= 00000 || codiceSerialeRicerca > 1000)) {
                            System.out.println("Errore: il codice seriale da te inserito non è presente nel database.");
                        }
                    }
                    for (int i = 0; i < numeroDevice; i++) {
                        if (listaDevice[i].getCodiceSeriale() == codiceSeriale) {
                            System.out.println(listaDevice[i].toString());
                        }
                    }
                    break;
                case 5:
                    int velocitaRicerca = 0;
                    try {
                        System.out.println("Inserisci il codice seriale del computer che cui si vuole mostrare nel database: ");
                        codiceSerialeRicerca = input.nextInt();
                    } catch (InputMismatchException e) {
                        System.out.println("Errore: Il dato che si è inserito non corrisponde con il tipo previsto.");
                        input.nextLine();
                        eccezioneSollevata = true;
                    } finally {
                        if (velocitaRicerca >= 0) {
                            inserimento = false;
                        }
                        if (eccezioneSollevata == false && velocitaRicerca <= 0) {
                            System.out.println("Errore: la velocità del processore da te inserita non è presente nel database o è errata.");
                        }
                    }
                    for (int i = 0; i < numeroDevice; i++) {
                        if (listaDevice[i].getVelocitaProcessore() >= velocitaRicerca) {
                            System.out.println(listaDevice[i].toString());
                        }
                    }
                    break;
                case 6:
                    int grandezzaRam = 0;
                    try {
                        System.out.println("Inserisci il codice seriale del computer che cui si vuole mostrare nel database: ");
                        codiceSerialeRicerca = input.nextInt();
                    } catch (InputMismatchException e) {
                        System.out.println("Errore: Il dato che si è inserito non corrisponde con il tipo previsto.");
                        input.nextLine();
                        eccezioneSollevata = true;
                    } finally {
                        if (grandezzaRam > 0) {
                            inserimento = false;
                        }
                        if (eccezioneSollevata == false && grandezzaRam <= 0) {
                            System.out.println("Errore: la grandezza della RAM da te inserita non è presente nel database o è errata.");
                        }
                    }
                    for (int i = 0; i < numeroDevice; i++) {
                        if (listaDevice[i].getVelocitaProcessore() >= grandezzaRam) {
                            System.out.println(listaDevice[i].toString());
                        }
                    }
                    break;
                case 7:
                    int grandezzaHardDisk = 0;
                    try {
                        System.out.println("Inserisci il codice seriale del computer che cui si vuole mostrare nel database: ");
                        codiceSerialeRicerca = input.nextInt();
                    } catch (InputMismatchException e) {
                        System.out.println("Errore: Il dato che si è inserito non corrisponde con il tipo previsto.");
                        input.nextLine();
                        eccezioneSollevata = true;
                    } finally {
                        if (grandezzaHardDisk > 0) {
                            inserimento = false;
                        }
                        if (eccezioneSollevata == false && grandezzaHardDisk <= 0) {
                            System.out.println("Errore: la grandezza del HardHisk da te inserita non è presente nel database o è errata.");
                        }
                    }
                    for (int i = 0; i < numeroDevice; i++) {
                        if (listaDevice[i].getVelocitaProcessore() >= grandezzaHardDisk) {
                            System.out.println(listaDevice[i].toString());
                        }
                    }
                    break;
                default:
                    System.out.println("Hai inserito una scelta non presente nel menu, riprova.");
                    break;
            }
        } while (mostraMenu == true);
    }
}