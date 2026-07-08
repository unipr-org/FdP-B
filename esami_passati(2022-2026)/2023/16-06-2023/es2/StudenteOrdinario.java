public class StudenteOrdinario implements Immatricolabile{
    private String matricola;
    private String scuolaProvenienza;
    public StudenteOrdinario(String matricola, String scuolaProvenienza){
        this.matricola = matricola;
        this.scuolaProvenienza = scuolaProvenienza;
    }
    @Override
    public String getMatricola(){
        return this.matricola;
    }
    public String getScuolaProvenienza(){
        return this.scuolaProvenienza;
    }
    @Override
    public boolean equals(Object obj){
        if(this == obj)
            return true;
        if(obj == null || getClass() != obj.getClass())
            return false;
        StudenteOrdinario other = (StudenteOrdinario) obj;
        return this.matricola.equals(other.matricola);
    }
}
