import java.util.HashSet;
import java.util.Set;

public class Registro {
    private Set<Iscrizione> iscrizioni;

    public Registro() {
        this.iscrizioni = new HashSet<>();
    }

    public void add(Iscrizione nuova) {
        if (nuova == null) return;

        // Controlla se l'utente ha già iscrizioni sovrapposte nel registro corrente
        for (Iscrizione i : this.iscrizioni) {
            if (i.getUtente().equals(nuova.getUtente()) && i.overlapsWith(nuova)) {
                throw new IscrizioneNonValidaException("Errore: L'utente ha già un'iscrizione attiva in questo periodo.");
            }
        }
        this.iscrizioni.add(nuova);
    }
    public Registro project(int anno) {
        Registro filtrato = new Registro();
        for (Iscrizione i : this.iscrizioni) {
            // Un'iscrizione "si riferisce" ad un anno se coinvolge quell'anno (sia all'inizio che alla fine)
            if (anno >= i.getAnnoInizio() && anno <= i.getAnnoFine()) {
                filtrato.iscrizioni.add(i); // Aggiungiamo direttamente al set del nuovo registro
            }
        }
        return filtrato;
    }
}