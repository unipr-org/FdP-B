public class GreenPass {
    private String codiceFiscale;
    private Data dataScadenza;
    public GreenPass(String codiceFiscale, Data dataScadenza){
        this.codiceFiscale = codiceFiscale;
        this.dataScadenza = dataScadenza;
    }
    public String getCodiceFiscale(){
        return this.codiceFiscale;
    }
    public Data getDataScadenza(){
        return this.dataScadenza;
    }
    @Override
    public boolean equals(Object obj){
        if(obj == this)
            return true;
        if(obj == null || getClass() != obj.getClass())
            return false;
        GreenPass other = (GreenPass) obj;
        return this.codiceFiscale.equals(other.codiceFiscale) && this.dataScadenza.equals(other.dataScadenza);
    }
    @Override
    public String toString(){
        return "GreenPass [CF: " + this.codiceFiscale + ", Scadenza: " + this.dataScadenza + " ]";
    }
}
