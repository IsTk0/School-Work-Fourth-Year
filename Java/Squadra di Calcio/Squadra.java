/**
 * Creazione classe Squadra
 *
 * @author Antonio
 * @version 12/11
 */
public class Squadra {
    final int GIOCATORI_MAX = 20;
    private Atleta giocatori[];

    public Squadra() {
        this.giocatori = new Atleta[GIOCATORI_MAX];
    }

    public int setGiocatore(Atleta giocatore, int posizione) {
        if (posizione < 0 || posizione >= GIOCATORI_MAX) {
            return 0;
        }
        if (giocatori[posizione] != null) {
            return 1;
        }
        giocatori[posizione] = giocatore;
        return posizione;
    }

    public Atleta[] getGiocatori() {
        return giocatori;
    }

    public int printGiocatori() {
        for (int i = 0; i < GIOCATORI_MAX; i++) {
            System.out.println(giocatori[i].toString());
        }
        return 1;
    }

    public int riordinaGiocatori() {
        for (int i = 0; i < GIOCATORI_MAX; i++) {
            int cicloMinimo = i;
            for (int j = i + 1; j < GIOCATORI_MAX; j++)
                if (giocatori[j].getCognome().equals(giocatori[cicloMinimo].getCognome()))
                    cicloMinimo = j;

            Atleta temp = giocatori[cicloMinimo];
            giocatori[cicloMinimo] = giocatori[i];
            giocatori[i] = temp;
            System.out.println(giocatori[i].toString());
        }
        return 1;
    }
}
