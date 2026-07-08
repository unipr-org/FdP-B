public abstract class Aula implements Comparable<Aula>{
    private String nome;
    private int capienzaMassima;
    public Aula(String nome, int capienzaMassima){
        this.nome = nome;
        this.capienzaMassima = capienzaMassima;
    }
    public String getNome(){
        return this.nome;
    }
    public int getCapienzaMassima(){
        return this.capienzaMassima;
    }
    @Override
    public boolean equals(Object obj){
        if(obj == this)
            return true;
        if(obj == null || getClass() != obj.getClass())
            return false;
        Aula other = (Aula) obj;
        return this.nome.equals(other.nome) && this.capienzaMassima == other.capienzaMassima;
    }
    @Override
    public int compareTo(Aula other){
        return Integer.compare(this.capienzaMassima, other.capienzaMassima);
    }
}
