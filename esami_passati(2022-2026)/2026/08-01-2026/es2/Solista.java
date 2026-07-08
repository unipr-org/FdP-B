public class Solista extends Partecipante{
    private String strumentoPrincipale;
    public Solista(String nome, int anniAttivita, String strumentoPrincipale){
        super(nome, anniAttivita);
        this.strumentoPrincipale = strumentoPrincipale;
    }
    public String getStrumentoPrincipale(){
        return this.strumentoPrincipale;
    }
    @Override
    public boolean equals(Object obj){
        if(this == obj)
            return true;
        if(obj == null || getClass() != obj.getClass())
            return false;
        if(!super.equals(obj))
            return false;
        Solista other = (Solista) obj;
        return this.strumentoPrincipale.equals(other.strumentoPrincipale);
    }
}
