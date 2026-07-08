public abstract class Calciatore implements Comparable<Calciatore>{
    private String nome;
    private String cognome;
    private int numMaglia;
    public Calciatore(String nome, String cognome, int numMaglia){
        this.nome = nome;
        this.cognome = cognome;
        this.numMaglia = numMaglia;
    }
    public String getNome(){
        return this.nome;
    }
    public String getCognome(){
        return this.cognome;
    }
    public int getNumMaglia(){
        return this.numMaglia;
    }
    @Override
    public boolean equals(Object obj){
        if(this == obj)
            return true;
        if(obj == null || getClass() != obj.getClass())
            return false;
        Calciatore other = (Calciatore) obj;
        return this.nome.equals(other.nome) && this.cognome.equals(other.cognome) && this.numMaglia == other.numMaglia;
    }
    @Override
    public int compareTo(Calciatore other){
        return Integer.compare(this.numMaglia, other.numMaglia);
    }
}
