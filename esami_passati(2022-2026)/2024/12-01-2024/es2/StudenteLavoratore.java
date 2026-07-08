public class StudenteLavoratore implements Immatricolabile{
    private String matricola;
    private String azienda;
    public StudenteLavoratore(String matricola, String azienda){
        this.matricola = matricola;
        this.azienda = azienda;
    }
    @Override
    public String getMatricola(){
        return this.matricola;
    }
    public String getAzienda(){
        return this.azienda;
    }
    @Override
    public boolean equals(Object obj){
        if(this == obj)
            return true;
        if(obj == null || getClass() != obj.getClass())
            return false;
        StudenteLavoratore other = (StudenteLavoratore) obj;
        return this.matricola.equals(other.matricola) && this.azienda.equals(other.azienda);
    }
}
