package es2;

import java.util.Objects;

public class Verbalizzazione {
    private final Studente studente;
    private final int esito;

    public Verbalizzazione(Studente studente , int esito){

        this.studente = studente ;
        if (esito < 0 || esito > 30)
            throw new RuntimeException ();
            this.esito = esito ;
    }

    public Studente getStudente(){
        return studente;
    }
    public int getEsito(){
        return esito;
    }
    
    // una Verbalizzazione e' equals a un 'altra che abbia stesso esito e stesso studente
    @Override
    public boolean equals ( Object other ) {
        return this.studente == other.studente && this.esito == other.esito;
    }
    // implementazione del metodo hashCode coerente con equals
    @Override
    public int hashCode() {
        return Objects.hash(studente, esito);
    }

    @Override
    public String toString () {
        return studente.toString() + "  Esito : " + esito ;
    }
}