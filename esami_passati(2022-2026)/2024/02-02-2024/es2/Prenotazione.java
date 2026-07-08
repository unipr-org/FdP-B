public class Prenotazione {
    private Aula aula;
    private String data;
    public Prenotazione(Aula aula, String data){
        this.aula = aula;
        this.data = data;
    }
    public Aula getAula(){
        return this.aula;
    }
    public String getData(){
        return this.data;
    }
    @Override
    public boolean equals(Object obj){
        if(obj == this)
            return true;
        if(obj == null || getClass() != obj.getClass())
            return false;
        Prenotazione other = (Prenotazione) obj;
        return this.aula.equals(other.aula) && this.data.equals(other.data);
    }
}
