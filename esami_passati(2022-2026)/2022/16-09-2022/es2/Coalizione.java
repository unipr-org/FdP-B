import java.util.HashSet;
import java.util.Set;
public class Coalizione implements Eleggibile {
    private String nome;
    private Set<Partito> partiti;

    public Coalizione(String nome, Partito[] partitiArray) {
        this.nome = nome;
        this.partiti = new HashSet<>();
        if (partitiArray != null) {
            for (Partito p : partitiArray) {
                if (p != null) {
                    this.partiti.add(p);
                }
            }
        }
    }

    public Set<Partito> getPartiti() {
        return new HashSet<>(this.partiti); // Copia difensiva per incapsulamento
    }

    @Override
    public String getNome() {
        return this.nome;
    }

    @Override
    public int getVoti() {
        int somma = 0;
        for (Partito p : this.partiti)
            somma += p.getVoti();
        return somma;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null || getClass() != obj.getClass())
            return false;
        Coalizione other = (Coalizione) obj;
        return this.nome.equals(other.nome) && this.partiti.equals(other.partiti);
    }

    @Override
    public String toString() {
        return "Coalizione{nome='" + nome + "', partiti=" + partiti + "}";
    }
}