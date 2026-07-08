import java.util.Objects;
public class Studente {
    private final String nome;
    private final String cognome;
    private final String matricola;
    public Studente(String nome, String cognome, String matricola){
        this.nome = nome;
        this.cognome = cognome;
        this.matricola = matricola;
    }
    public String getNome(){
        return this.nome;
    }
    public String getCognome(){
        return this.cognome;
    }
    public String getMatricola(){
        return this.matricola;
    }
    @Override
    public boolean equals(Object obj){
        if(this == obj)
            return true;
        if(obj == null || getClass() != obj.getClass())
            return false;
        Studente other = (Studente) obj;
        return this.matricola.equals(other.matricola);
    }
    @Override
    public String toString(){
        return "Studente: " + this.nome + " " + this.cognome + ", Matricola: " + this.matricola;
    }
    @Override
    public int hashCode(){
        return Objects.hash(this.matricola);
    }
}
