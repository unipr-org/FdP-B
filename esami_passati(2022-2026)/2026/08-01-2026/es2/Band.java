public class Band extends Partecipante{
    private int numeroComponenti;
    public Band(String nome, int anniAttivita, int numeroComponenti){
        super(nome, anniAttivita);
        this.numeroComponenti = numeroComponenti;
    }
    public int getNumeroComponenti(){
        return this.numeroComponenti;
    }
    @Override
    public boolean equals(Object obj){
        if(this == obj)
            return true;
        if(obj == null || getClass() != obj.getClass())
            return false;
        if(!super.equals(obj))
            return false;
        Band other = (Band) obj;
        return this.numeroComponenti == other.numeroComponenti;
    }
}
