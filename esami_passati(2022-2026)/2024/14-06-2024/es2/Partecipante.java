public abstract class Partecipante {
    private String nome;
    private int anniAttivita;
    public Partecipante(String nome, int anniAttivita){
        this.nome =nome;
        this.anniAttivita = anniAttivita;
    }
    public String getNome(){
        return this.nome;
    }
    public int getAnniAttivita(){
        return this.anniAttivita;
    }
    @Override
    public boolean equals(Object obj){
        if(this == obj)
            return true;
        if(obj == null || getClass() != obj.getClass())
            return false;
        Partecipante other = (Partecipante) obj;
        return this.nome.equals(other.nome) && this.anniAttivita == other.anniAttivita;
    }
}
