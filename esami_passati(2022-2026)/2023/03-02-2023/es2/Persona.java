import java.util.HashSet;
import java.util.Set;
public class Persona {
    private String nome;
    private String cognome;
    private Set<MetodoPagamento> metodiPagamento;
    public Persona(String nome, String cognome){
        this.nome = nome;
        this.cognome = cognome;
        this.metodiPagamento = new HashSet<>();
    }
    public String getNome(){
        return this.nome;
    }
    public String getCognome(){
        return this.cognome;
    }
    public Set<MetodoPagamento> getMetodiPagamento(){
        return new HashSet<>(this.metodiPagamento);
    }
    public void aggiungiMetodoPagamento(MetodoPagamento m){
        if(m != null)
            this.metodiPagamento.add(m);
    }
    public void paga(MetodoPagamento m, double importo){
        if (m == null)
            return;
        for (MetodoPagamento mp : this.metodiPagamento) {
            if (mp.equals(m)) {
                mp.decrementa(importo);
                return;
            }
        }
    }
}
