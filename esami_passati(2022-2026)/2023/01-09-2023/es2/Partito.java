public class Partito extends Eleggibile {
    public Partito(String nome){
        super(nome, 0);
    }
    public void vota(){
        int votoAggiornato = this.getVoti() + 1;
        this.setVoti(votoAggiornato);
    }
    @Override
    public boolean equals(Object obj){
        if(this == obj)
            return true;
        if(obj == null || getClass() != obj.getClass())
            return false;
        return super.equals(obj);
    }
    
}
