import java.util.HashSet;
import java.util.Set;
import java.util.Iterator;
public class Coalizione extends Eleggibile implements Iterable<Partito>{
    private Set<Partito> partiti;
    public Coalizione(String nome, Partito[] partitiArray){
        super(nome,0);
        this.partiti = new HashSet<>();
        if(partitiArray != null)
            for(Partito p : partitiArray)
                if(p != null)
                    this.partiti.add(p);
    }
    public Set<Partito> getPartiti(){
        return new HashSet<>(this.partiti);
    }
    @Override
    public int getVoti() {
        int somma = 0;
        for (Partito p : this.partiti) {
            somma += p.getVoti();
        }
        return somma;
    }
    @Override
    public boolean equals(Object obj){
        if(this == obj)
            return true;
        if(obj == null || getClass() != obj.getClass())
            return false;
        Coalizione other = (Coalizione) obj;
        return this.getNome().equals(other.getNome()) && this.partiti.equals(other.partiti);
    }
    @Override
    public Iterator<Partito> iterator(){
        return this.partiti.iterator();
    }
}
