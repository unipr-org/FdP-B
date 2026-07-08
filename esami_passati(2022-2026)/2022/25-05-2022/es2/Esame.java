import java.util.HashSet;
import java.util.ArrayList;
import java.util.Set;
import java.util.List;
public class Esame {
    private Set<Studente> iscritti;
    private List<Verbalizzazione> verbalizzazioni;
    public Esame(){
        this.iscritti = new HashSet<>();
        this.verbalizzazioni = new ArrayList<>();
    }
    public void iscrivi(Studente s) throws StudenteGiaIscrittoException{
        if(s == null)
            return;
        if(!this.iscritti.add(s))
            throw new StudenteGiaIscrittoException("è già iscritto");
    }
    public void verbalizza(Studente s, int voto) throws StudenteNonIscrittoException, StudenteGiaVerbalizzatoException{
        if(s == null)
            return;
        if(!this.iscritti.contains(s))
            throw new StudenteNonIscrittoException("lo studente non risulta iscritto a questo esame");
        for(Verbalizzazione v : this.verbalizzazioni)
            if(v.getStudente().equals(s))
                throw new StudenteGiaVerbalizzatoException("esito gia' verbalizzato per questo studente");
        Verbalizzazione nuovaVerbalizzazione = new Verbalizzazione(s, voto);
        this.verbalizzazioni.add(nuovaVerbalizzazione);
    }
    public Set<Studente> getIscritti(){
        return new HashSet<>(this.iscritti);
    }
    public List<Verbalizzazione> getVerbalizzazioni(){
        return new ArrayList<>(this.verbalizzazioni);
    }
}
