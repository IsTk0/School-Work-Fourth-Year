/**
 * In questo file troviamo l'instanzione della classe Squadra con i suoi attributi e metodi
 * 
 * @author Antonio
 * @version 24/10
 */

public class Squadra
{
    // attributi 
    private String nomeSquadra = "";
    private int partiteVinte = 0, partitePareggiate = 0, partitePerse = 0, goalFatti = 0, goalSubiti = 0, punteggioSquadra = 0;
    
    //costruttore
    public Squadra(String nomeSquadra, int partiteVinte, int partitePareggiate, int partitePerse, int goalFatti, int goalSubiti){
        setNomeSquadra(nomeSquadra); 
        setPartiteVinte(partiteVinte);
        setPartitePareggiate(partitePareggiate);
        setPartitePerse(partitePerse);
        setGoalFatti(goalFatti);
        setGoalSubiti(goalSubiti);
    }
    
    //getter
    public String getNomeSquadra(){return nomeSquadra;}
    public int getPartiteVinte(){return partiteVinte;}
    public int getPartitePareggiate(){return partitePareggiate;}
    public int getPartitePerse(){return partitePerse;}
    public int getGoalFatti(){return goalFatti;}
    public int getGoalSubiti(){return goalSubiti;}
    public int getPunteggioSquadra(){return punteggioSquadra;}
    
    //setter
    public void setNomeSquadra(String nomeSquadra){this.nomeSquadra = nomeSquadra;}
    public void setPartiteVinte(int partiteVinte){this.partiteVinte = partiteVinte;}
    public void setPartitePareggiate(int partitePareggiate){this.partitePareggiate = partitePareggiate;}
    public void setPartitePerse(int partitePerse){this.partitePerse = partitePerse;}
    public void setGoalFatti(int goalFatti){this.goalFatti = goalFatti;}
    public void setGoalSubiti(int goalSubiti){this.goalSubiti = goalSubiti;}
    public void setPunteggioSquadra(int punteggioSquadra){this.punteggioSquadra = punteggioSquadra;}

    //metodi

    public int differenzaReti() {return goalFatti - goalSubiti;}
}
