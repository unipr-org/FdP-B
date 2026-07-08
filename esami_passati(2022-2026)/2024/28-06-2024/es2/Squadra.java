import java.util.HashSet;
import java.util.Set;
public class Squadra {
    private String nome;
    private Set<Calciatore> calciatori;
    public Squadra(String nome, Set<Calciatore> calciatori){
        this.nome = nome;
        if(calciatori.size() > 22)
            throw new IllegalArgumentException("La squadra non può superare i 22 calciatori");
        int contaP = 0;
        int contaA = 0;
        for(Calciatore c : calciatori){
            if(c instanceof Portiere) contaP++;
            if(c instanceof Attaccante) contaA++;
        }
        if(contaP > 3)
            throw new IllegalArgumentException("La squadra non può avere piu' di 3 portieri");
        if(contaA > 5)
            throw new IllegalArgumentException("La squadra non può avere piu' di 5 attaccanti");
        this.calciatori = new HashSet<>(calciatori);
    }
    public String getNome(){
        return this.nome;
    }
    public Set<Calciatore> getCalciatori(){
        return new HashSet<>(this.calciatori);
    }
    @Override
    public boolean equals(Object obj){
        if(this == obj)
            return true;
        if(obj == null || getClass() != obj.getClass())
            return false;
        Squadra other = (Squadra) obj;
        return this.nome.equals(other.nome) && this.calciatori.equals(other.calciatori);
    }
}
