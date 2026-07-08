import java.util.HashSet;
import java.util.Set;
import java.util.Iterator;
public class Manager extends Impiegato implements Comparable<Manager>, Iterable<Impiegato>{
    private Set<ImpiegatoBase> team;
    public Manager(String nome, String cognome, int ore){
        super(nome, cognome, ore);
        this.team = new HashSet<>();
    }
    public Set<ImpiegatoBase> getTeam(){
        return new HashSet<>(this.team);
    }
    @Override
    public double getStipendioAnnuale(){
        return this.getOre() * 25.90;
    }
    public void aggiungiAlTeam(Impiegato im) throws TeamManagerException{
        if(im == null)
            return;
        if(im.getOre() < 20)
            throw new TeamManagerException("L'impiegato ha lavorato meno di 20 ore.");
        if(im instanceof Manager)
            throw new TeamManagerException("Un manager non può gestire un altro manager!");
        ImpiegatoBase ib = (ImpiegatoBase) im;
        if(!this.team.add(ib))
            throw new TeamManagerException("L'impiegato fa già parte del team.");
    }
    @Override
    public boolean equals(Object obj){
        if(this == obj)
            return true;
        if(obj == null || getClass() != obj.getClass())
            return false;
        if(!super.equals(obj))
            return false;
        Manager other = (Manager) obj;
        return this.team.equals(other.team);
    }
    @Override
    public int compareTo(Manager other){
        return Integer.compare(this.team.size(), other.team.size());
    }
    @Override
    public Iterator<Impiegato> iterator() {
        // Poiché il team contiene ImpiegatoBase (che estende Impiegato),
        // possiamo fare l'upcasting dell'iterator in modo sicuro.
        return (Iterator<Impiegato>) (Iterator<?>) this.team.iterator();
    // Iterator<?> => un iteratore di un tipo qualsiasi che non mi interessa specificare
    }
}
