import java.util.HashSet;
import java.util.Set;
import java.util.Iterator;
public class Album implements Iterable<Figurina>{
    private String nome;
    private Set<Figurina> figurine;
    public Album(String nome){
        this.nome = nome;
        this.figurine = new HashSet<>();
    }
    public String getNome(){
        return this.nome;
    }
    public Set<Figurina> getFigurine(){
        return new HashSet<>(this.figurine);
    }
    public void add(Figurina f) {
        if (f == null)
            return;
        if (!this.puoContenere(f))
            throw new IllegalArgumentException("Impossibile aggiungere la figurina: vincoli violati o duplicato.");
        this.figurine.add(f);
    }
    public boolean puoContenere(Figurina f) {
        if (f == null)
            return false;
        if (this.figurine.contains(f))
            return false;
        int contaSportive = 0;
        int contaStoriche = 0;
        for (Figurina fig : this.figurine) {
            if (fig instanceof FigurinaSportiva)
                contaSportive++;
            if (fig instanceof FigurinaStorica)
                contaStoriche++;
        }
        if (f instanceof FigurinaSportiva && contaSportive >= 100)
            return false;
        if (f instanceof FigurinaStorica && contaStoriche >= 50)
            return false;
        return true;
    }
    public void remove(Figurina f) {
        if (f != null)
            this.figurine.remove(f);
    }
    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null || getClass() != obj.getClass())
            return false;
        Album other = (Album) obj;
        return this.nome.equals(other.nome) && this.figurine.equals(other.figurine);
    }
    @Override
    public Iterator<Figurina> iterator() {
        return this.figurine.iterator();
    }
}
