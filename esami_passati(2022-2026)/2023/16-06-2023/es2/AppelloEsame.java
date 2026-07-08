import java.util.HashSet;
import java.util.Set;
public class AppelloEsame implements Comparable<AppelloEsame>{
    private String nome;
    private String annoAccademico;
    private Set<Immatricolabile> iscritti;
    public AppelloEsame(String nome, String annoAccademico){
        this.nome = nome;
        this.annoAccademico = annoAccademico;
        this.iscritti = new HashSet<>();
    }
    public String getNome(){
        return this.nome;
    }
    public String getAnnoAccademico(){
        return this.annoAccademico;
    }
    public Set<Immatricolabile> getIscritti(){
        return new HashSet<>(this.iscritti);
    }
    public void iscrivi(Immatricolabile studente) throws AppelloEsameException{
        if(studente == null)
            return;
        if(this.iscritti.contains(studente))
            throw new AppelloEsameException("Errore: Lo studente è già iscritto a questo appello.");
        if(studente instanceof StudenteOrdinario){
            int ordinari = 0;
            for(Immatricolabile i : this.iscritti)
                if(i instanceof StudenteOrdinario)
                    ordinari++;
            if(ordinari >= 50)
                throw new AppelloEsameException("Errore: Raggiunto il limite massimo di 50 studenti ordinari.");
        }
        else if(studente instanceof StudenteLavoratore){
            int lavoratori = 0;
            for(Immatricolabile i : this.iscritti)
                if( i instanceof StudenteLavoratore)
                    lavoratori++;
            if(lavoratori >= 50)
                throw new AppelloEsameException("Errore: Raggiunto il limite massimo di 50 studenti lavoratori.");
        }
        this.iscritti.add(studente);
    }
    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null || getClass() != obj.getClass())
            return false;
        AppelloEsame other = (AppelloEsame) obj;
        return this.nome.equals(other.nome) &&
            this.annoAccademico.equals(other.annoAccademico) &&
            this.iscritti.equals(other.iscritti);
    }
    @Override
    public int compareTo(AppelloEsame other){
        int mieiLavoratori = 0;
        for (Immatricolabile i : this.iscritti) {
            if (i instanceof StudenteLavoratore) {
                mieiLavoratori++;
            }
        }
        int altriLavoratori = 0;
        for (Immatricolabile i : other.iscritti) {
            if (i instanceof StudenteLavoratore) {
                altriLavoratori++;
            }
        }
        return Integer.compare(mieiLavoratori, altriLavoratori);
    }
}
