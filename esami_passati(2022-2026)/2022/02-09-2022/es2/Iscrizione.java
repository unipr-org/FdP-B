public class Iscrizione implements Comparable<Iscrizione> {
    private Utente utente;
    private int meseInizio, annoInizio;
    private int meseFine, annoFine;

    public Iscrizione(Utente u, int meseInizio, int annoInizio, int meseFine, int annoFine) {
        // Linearizzazione in mesi totali per semplificare i calcoli cronologici
        int inizioTotale = annoInizio * 12 + meseInizio;
        int fineTotale = annoFine * 12 + meseFine;
        // VINCOLO 1: L'inizio non può venire dopo la fine
        if (inizioTotale > fineTotale)
            throw new IscrizioneNonValidaException("Errore: La data di inizio è successiva alla data di fine.");
        // VINCOLO 2: Non può superare i 12 mesi
        int durataMesi = fineTotale - inizioTotale + 1;
        if (durataMesi > 12)
            throw new IscrizioneNonValidaException("Errore: L'iscrizione non può superare i 12 mesi di durata.");
        this.utente = u;
        this.meseInizio = meseInizio;
        this.annoInizio = annoInizio;
        this.meseFine = meseFine;
        this.annoFine = annoFine;
    }
    public Utente getUtente() { return this.utente; }
    public int getAnnoInizio() { return this.annoInizio; }
    public int getAnnoFine() { return this.annoFine; }
    public boolean overlapsWith(Iscrizione other) {
        if (other == null) return false;
        int startThis = this.annoInizio * 12 + this.meseInizio;
        int endThis = this.annoFine * 12 + this.meseFine;
        int startOther = other.annoInizio * 12 + other.meseInizio;
        int endOther = other.annoFine * 12 + other.meseFine;
        return startThis <= endOther && startOther <= endThis;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Iscrizione other = (Iscrizione) obj;
        return this.utente.equals(other.utente) &&
            this.meseInizio == other.meseInizio && this.annoInizio == other.annoInizio &&
            this.meseFine == other.meseFine && this.annoFine == other.annoFine;
    }

    @Override
    public String toString() {
        return "Iscrizione [" + utente + "] Dal: " + meseInizio + "/" + annoInizio + " Al: " + meseFine + "/" + annoFine;
    }
    @Override
    public int compareTo(Iscrizione other) {
        int fineThis = this.annoFine * 12 + this.meseFine;
        int fineOther = other.annoFine * 12 + other.meseFine;
        return Integer.compare(fineThis, fineOther);
    }
}