public class Partita {
    private Squadra squadra1;
    private Squadra squadra2;
    private String data;
    public Partita(Squadra squadra1, Squadra squadra2, String data){
        this.squadra1 = squadra1;
        this.squadra2 = squadra2;
        this.data = data;
    }
    public Squadra getSquadra1(){
        return this.squadra1;
    }
    public Squadra getSquadra2(){
        return this.squadra2;
    }
    public String getData(){
        return this.data;
    }
}
