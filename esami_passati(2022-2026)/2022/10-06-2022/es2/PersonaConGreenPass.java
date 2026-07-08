import java.util.HashSet;
import java.util.Set;
public class PersonaConGreenPass implements Comparable<PersonaConGreenPass>{
    private String codiceFiscale;
    private Set<GreenPass> certificati;
    public PersonaConGreenPass(String codiceFiscale) {
        this.codiceFiscale = codiceFiscale;
        this.certificati = new HashSet<>();
    }
    public String getCodiceFiscale(){
        return this.codiceFiscale;
    }
    public void addGreenPass(GreenPass gp) throws GreenPassException{
        if(gp == null)
            return;
        if(!gp.getCodiceFiscale().equals(this.codiceFiscale))
            throw new GreenPassException("Errore: Il Green Pass appartiene a un codice fiscale diverso.");
        if(gp instanceof GreenPassVaccino)
            for(GreenPass esistente : this.certificati)
                if(esistente instanceof GreenPassVaccino)
                    throw new GreenPassException("Errore: La persona possiede già un Green Pass da vaccino.");
        this.certificati.add(gp);
    }
    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null || getClass() != obj.getClass())
            return false;
        PersonaConGreenPass other = (PersonaConGreenPass) obj;
        return this.codiceFiscale.equals(other.codiceFiscale) && this.certificati.equals(other.certificati);
    }
    @Override
    public String toString() {
        return "Persona [CF: " + codiceFiscale + ", Numero Certificati: " + certificati.size() + "]";
    }
    @Override
    public int compareTo(PersonaConGreenPass other){
        return Integer.compare(this.certificati.size(), other.certificati.size());
    }
}
