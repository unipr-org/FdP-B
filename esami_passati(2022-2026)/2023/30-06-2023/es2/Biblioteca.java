import java.util.HashSet;
import java.util.Set;

public class Biblioteca implements Comparable<Biblioteca> {
    private Set<ElementoBibliografico> disponibili;
    private Set<ElementoBibliografico> prestati;
    public Biblioteca(){
        this.disponibili = new HashSet<>();
        this.prestati = new HashSet<>();
    }
    public void add(ElementoBibliografico elemento){
        if(elemento != null)
            this.disponibili.add(elemento);
    }
    public void presta(ElementoBibliografico elemento) throws BibliotecaException{
        if(!this.disponibili.contains(elemento))
            throw new BibliotecaException("l'elemento non e' disponibile");
        this.disponibili.remove(elemento);
        this.prestati.add(elemento);
    }
    public void restituisci(ElementoBibliografico elemento) throws BibliotecaException{
        if(!this.prestati.contains(elemento))
            throw new BibliotecaException("l'elemento non e' prestato");
        this.prestati.remove(elemento);
        this.disponibili.add(elemento);
    }
    public Set<ElementoBibliografico> getDisponibili() {
        return new HashSet<>(this.disponibili);
    }
    public Set<ElementoBibliografico> getPrestati() {
        return new HashSet<>(this.prestati);
    }
    @Override
    public int compareTo(Biblioteca other){
        return Integer.compare(this.disponibili.size(), other.disponibili.size());
    }
}
