public class ImpiegatoBase extends Impiegato{
    public ImpiegatoBase(String nome, String cognome, int ore){
        super(nome, cognome, ore);
    }
    @Override
    public double getStipendioAnnuale(){
        return this.getOre() * 15.50;
    }
    @Override
    public boolean equals(Object obj){
        if(this == obj)
            return true;
        if(obj == null || getClass() != obj.getClass())
            return false;
        ImpiegatoBase other = (ImpiegatoBase) obj;
        return super.equals(obj);
    }
}
