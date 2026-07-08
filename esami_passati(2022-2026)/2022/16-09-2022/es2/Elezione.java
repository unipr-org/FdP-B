import java.util.HashSet;
import java.util.Set;
public class Elezione {
    private Set<Eleggibile> partecipanti;

    public Elezione() {
        this.partecipanti = new HashSet<>();
    }

    public void add(Eleggibile partecipante) {
        if (partecipante == null) return;

        // 1. Il partito o la coalizione è già iscritto all'elezione
        if (this.partecipanti.contains(partecipante))
            throw new ElezioneException("Partecipante già iscritto all'elezione.");

        if (partecipante instanceof Partito) {
            Partito p = (Partito) partecipante;
            // 2. Il partito fa parte di una coalizione che è già iscritta
            for (Eleggibile esistente : partecipanti)
                if (esistente instanceof Coalizione)
                    if (((Coalizione) esistente).getPartiti().contains(p))
                        throw new ElezioneException("Il partito fa parte di una coalizione già iscritta.");
        }
        else if (partecipante instanceof Coalizione) {
            Coalizione c = (Coalizione) partecipante;
            // 3. La coalizione contiene un partito che è già iscritto all'elezione (da solo o in altra coalizione)
            for (Partito pInC : c.getPartiti()) {
                for (Eleggibile esistente : partecipanti) {
                    if (esistente instanceof Partito && esistente.equals(pInC))
                        throw new ElezioneException("La coalizione contiene un partito già iscritto singolarmente.");
                    if (esistente instanceof Coalizione && ((Coalizione) esistente).getPartiti().contains(pInC))
                        throw new ElezioneException("La coalizione contiene un partito appartenente ad un'altra coalizione iscritta.");
                }
            }
        }
        this.partecipanti.add(partecipante);
    }

    public Eleggibile winner() {
        Eleggibile vincitore = null;
        int maxVoti = -1;

        for (Eleggibile e : partecipanti) {
            if (e.getVoti() > maxVoti) {
                maxVoti = e.getVoti();
                vincitore = e;
            }
        }
        return vincitore;
    }
}