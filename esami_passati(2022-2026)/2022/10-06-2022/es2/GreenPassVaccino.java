public class GreenPassVaccino extends GreenPass{
    private String tipoVaccino;
    public GreenPassVaccino(String CF, Data ds, String tipoVaccino){
        super(CF, ds);
        this.tipoVaccino = tipoVaccino;
    }
    public String getTipoVaccino(){
        return this.tipoVaccino;
    }
    @Override
    public boolean equals(Object obj){
        if(obj == this)
            return true;
        if(obj == null || getClass() != obj.getClass())
            return false;
        if(!super.equals(obj))
            return false;
        GreenPassVaccino other = (GreenPassVaccino) obj;
        return this.tipoVaccino.equals(other.tipoVaccino);
    }
    @Override
    public String toString() {
        return super.toString() + " - Tipo Vaccino: " + tipoVaccino;
    }
}
