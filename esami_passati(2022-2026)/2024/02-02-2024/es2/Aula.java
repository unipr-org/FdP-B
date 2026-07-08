public abstract class Aula{
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
}
