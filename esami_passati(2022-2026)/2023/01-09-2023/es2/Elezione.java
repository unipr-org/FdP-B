import java.util.HashSet;
import java.util.Set;
public class Elezione {
    private Set<Coalizione> partecipanti;
    public Elezione(){
        this.partecipanti = new HashSet<>();
    }
    public Set<Coalizione> getPartecipanti(){
        return new HashSet<>(this.partecipanti);
    }
    public void add(Coalizione coalizione){
        if(coalizione == null)
            return;
        if(!this.partecipanti.add(coalizione))
            throw new ElezioneException("La coalizione è già iscritta a questa elezione");
    }
    public Coalizione winner(){
        int max = -1;
        Coalizione vincitore = null;
        for(Coalizione c : partecipanti){
            if(c.getVoti() > max){
                max = c.getVoti();
                vincitore = c;
            }
        }
        return vincitore;
    }
}
