package es2;

import java.util.HashSet;

public class Esame{
    private HashSet<Studente> iscritti;
    private HashSet<Verbalizzazione> verbalizzati;
    private int numeroIscritti;
    public Esame(){
        numeroIscritti = 0;
        iscritti = new HashSet<Studente>();
        verbalizzati = new HashSet<Verbalizzazione>();
    }
    public void iscrivi(Studente s) throws Exception{
        numeroIscritti++;
        if(iscritti.contains(s))
            throw new StudenteGiaIscrittoException();
        
        iscritti.add(s);
    }
    public void verbalizza(Studente s, int voto) throws Exception{
        if(!iscritti.contains(s))
            throw new StudenteNonIscrittoException();
        if(verbalizzati.contains(new Verbalizzazione(s, voto)))
            throw new StudenteGiaVerbalizzatoException();
        else
            verbalizzati.add(new Verbalizzazione(s, voto));
    }

}
