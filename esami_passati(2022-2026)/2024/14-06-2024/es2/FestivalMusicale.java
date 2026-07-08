import java.util.HashSet;
import java.util.Set;
import java.util.Iterator;
public class FestivalMusicale implements Iterable<Esibizione>{
    private Set<Esibizione> esibizioni;
    public FestivalMusicale(){
        this.esibizioni = new HashSet<>();
    }
    public void aggiungiEsibizione(Esibizione e) throws EsibizioneEsistenteException{
        if(e == null)
            return;
        for(Esibizione esistente : this.esibizioni)
            if(esistente.getPartecipante().equals(e.getPartecipante()))
                throw new EsibizioneEsistenteException("Il partecipante è già presente nel festival!");
        this.esibizioni.add(e);
    }
    public Set<Partecipante> getPartecipantiInData(String data){
        Set<Partecipante> risultati = new HashSet<>();
        if(data == null)
            return risultati;
        for(Esibizione esib : this.esibizioni)
            if(esib.getData().equals(data))
                risultati.add(esib.getPartecipante());
        return risultati;
    }
    public int numeroEsibizioniRegistrate(){
        return this.esibizioni.size();
    }
    @Override
    public Iterator<Esibizione> iterator(){
        return this.esibizioni.iterator();
    }
}
