import java.util.HashSet;
import java.util.Set;
import java.util.Iterator;
public class SistemaPrenotazioni implements Iterable<Prenotazione>{
    private Set<Prenotazione> prenotazioniEffettuate;
    public SistemaPrenotazioni(){
        this.prenotazioniEffettuate = new HashSet<>();
    }
    public Set<Prenotazione> getPrenotazioniEffettuate(){
        return new HashSet<>(this.prenotazioniEffettuate);
    }
    public void aggiungiPrenotazione(Prenotazione p){
        if(p == null)
            return;
        if(!this.prenotazioniEffettuate.add(p))
            throw new AulaOccupataException("Aula occupata");
    }
    public Set<AulaStandard> getAuleStandardPrenotateOn(String data){
        Set<AulaStandard> insieme = new HashSet<>();
        if(data == null)
            return insieme;
        for(Prenotazione p : this.prenotazioniEffettuate){
            if(p.getData().equals(data)){
                Aula a = p.getAula();
                if(a instanceof AulaStandard)
                    insieme.add((AulaStandard) a);
            }
        }
        return insieme;
    }
    @Override
    public Iterator<Prenotazione> iterator(){
        return this.prenotazioniEffettuate.iterator();
    }
}
