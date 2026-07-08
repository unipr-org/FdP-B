public abstract class Eleggibile {
    private String nome;
    private int numVoti;
    public Eleggibile(String nome, int numVoti){
        this.nome = nome;
        this.numVoti = numVoti;
    }
    public String getNome(){
        return this.nome;
    }
    public int getVoti(){
        return this.numVoti;
    }
    public void setVoti(int voti){
        this.numVoti = voti;
    }
    @Override
    public boolean equals(Object obj){
        if(this == obj)
            return true;
        if(obj == null || getClass() != obj.getClass())
            return false;
        Eleggibile other = (Eleggibile) obj;
        return this.nome.equals(other.nome) && this.numVoti == other.numVoti;
    }
}
