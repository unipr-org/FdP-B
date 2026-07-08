package es2;

public class Studente{
    private final String nome;
    private final String cognome;
    private final String matricola;

    public Studente(String nome, String cognome, String matricola){
        this.nome = nome;
        this.cognome = cognome;
        this.matricola = matricola;
    }
    @Override
    public boolean equals(Object obj){
        if(obj == this)
            return true;
        else if(obj == null)
            return false;
        else if(this.getClass() != obj.getClass())
            return false;
        Studente other = (Studente) obj;
        return this.matricola.equals(other.matricola);
    }
    @Override
    public String toString(){
        return this.nome + " " + this.cognome + " " + this.matricola;
    }
    @Override
    public int hashCode(){
        return matricola.hashCode();
    }

}