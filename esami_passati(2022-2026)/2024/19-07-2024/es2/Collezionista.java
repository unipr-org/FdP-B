public class Collezionista {
    private String nome;
    private String cognome;
    private Album album;

    public Collezionista(String nome, String cognome, Album album){
        this.nome = nome;
        this.cognome = cognome;
        this.album = album;
    }
    public String getNome(){
        return this.nome;
    }
    public String getCognome(){
        return this.cognome;
    }
    public Album getAlbum(){
        return this.album;
    }
    public void scambia(Collezionista other, Figurina figThis, Figurina figOther) throws CollezionistaException{
        if (other == null || figThis == null || figOther == null)
            return;
        if (!this.album.getFigurine().contains(figThis))
            throw new CollezionistaException("Errore: Non possiedi la figurina " + figThis.getId());
        if (!other.getAlbum().getFigurine().contains(figOther))
            throw new CollezionistaException("Errore: L'altro collezionista non possiede la figurina " + figOther.getId());
        // 2. CONTROLLO PREVENTIVO: Ora il compilatore trova il metodo in Album!
        if (!this.album.puoContenere(figOther) || !other.getAlbum().puoContenere(figThis))
            throw new CollezionistaException("Scambio fallito: violati i vincoli di capienza negli album.");
        // 3. Esecuzione sicura: Ora il compilatore trova remove() e add() in Album!
        this.album.remove(figThis);
        other.getAlbum().remove(figOther);
        this.album.add(figOther);
        other.getAlbum().add(figThis);
    }
}