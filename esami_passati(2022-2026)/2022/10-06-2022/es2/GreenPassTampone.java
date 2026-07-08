public class GreenPassTampone extends GreenPass{
    private String tipoTampone;
    public GreenPassTampone(String codiceFiscale, Data dataScadenza, String tipoTampone) {
        super(codiceFiscale, dataScadenza);
        this.tipoTampone = tipoTampone;
    }
    public String getTipoTampone(){
        return this.tipoTampone;
    }
    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null || getClass() != obj.getClass())
            return false;
        if (!super.equals(obj))
            return false;
        GreenPassTampone other = (GreenPassTampone) obj;
        return this.tipoTampone.equals(other.tipoTampone);
    }
    @Override
    public String toString() {
        return super.toString() + " - Tipo Tampone: " + tipoTampone;
    }
}
