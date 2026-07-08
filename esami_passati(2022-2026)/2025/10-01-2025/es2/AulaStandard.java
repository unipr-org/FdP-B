public class AulaStandard extends Aula{
    private int numeroLavagne;
    public AulaStandard(String nome, int capienzaMassima, int numeroLavagne){
        super(nome, capienzaMassima);
        this.numeroLavagne = numeroLavagne;
    }
    public int getNumeroLavagne(){
        return this.numeroLavagne;
    }
    @Override
    public boolean equals(Object obj){
        if(obj == this)
            return true;
        if(obj == null || getClass() != obj.getClass())
            return false;
        if(!super.equals(obj))
            return false;
        AulaStandard other = (AulaStandard) obj;
        return this.numeroLavagne == other.numeroLavagne;
    }
}
