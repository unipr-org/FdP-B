import java.util.Set;
import java.util.HashSet;
import java.util.Iterator;
public class Torneo implements Iterable<Partita> {
    private Set<Partita> partiteEffettuate;
    public Torneo(){
        this.partiteEffettuate = new HashSet<>();
    }
    public void aggiungiPartita(Partita nuovaPartita) throws TorneoException {
        if (nuovaPartita == null) return;

        Squadra sq1 = nuovaPartita.getSquadra1();
        Squadra sq2 = nuovaPartita.getSquadra2();

        for (Calciatore c : sq1.getCalciatori()) {
            if (sq2.getCalciatori().contains(c)) {
                throw new TorneoException("Errore: Il calciatore " + c.getNome() + " figura in entrambe le squadre della partita");
            }
        }

        for (Partita p : this.partiteEffettuate) {
            // Controllo 1: Partita duplicata tra le stesse squadre
            if ((p.getSquadra1().equals(sq1) && p.getSquadra2().equals(sq2)) ||
                (p.getSquadra1().equals(sq2) && p.getSquadra2().equals(sq1))) {
                throw new TorneoException("Partita duplicata");
            }

            Squadra vecchiaSq1 = p.getSquadra1();
            Squadra vecchiaSq2 = p.getSquadra2();

            // Controllo 2: Un calciatore gioca in più squadre registrate nel torneo
            for (Calciatore c : sq1.getCalciatori()) {
                if (vecchiaSq1.getCalciatori().contains(c) || vecchiaSq2.getCalciatori().contains(c)) {
                    throw new TorneoException("Il calciatore " + c.getNome() + " gioca gia' in un'altra squadra del torneo");
                }
            }
            for (Calciatore c : sq2.getCalciatori()) {
                if (vecchiaSq1.getCalciatori().contains(c) || vecchiaSq2.getCalciatori().contains(c)) {
                    throw new TorneoException("Il calciatore " + c.getNome() + " gioca gia' in un'altra squadra del torneo");
                }
            }
        }

        this.partiteEffettuate.add(nuovaPartita);
    }
    public Set<Partita> getPartiteInData(String data){
        Set<Partita> risultato = new HashSet<>();
        for(Partita p : this.partiteEffettuate)
            if(p.getData().equals(data))
                risultato.add(p);
        return risultato;
    }
    @Override
    public Iterator<Partita> iterator(){
        return this.partiteEffettuate.iterator();
    }
}
