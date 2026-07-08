public class Esibizione {
    private Partecipante partecipante;
    private String data;
    private String ora;
    public Esibizione(Partecipante partecipante, String data, String ora){
        this.partecipante = partecipante;
        this.data = data;
        this.ora = ora;
    }
    public String getData(){
        return this.data;
    }
    public String getOra(){
        return this.ora;
    }
    public Partecipante getPartecipante(){
        return this.partecipante;
    }
    
}
