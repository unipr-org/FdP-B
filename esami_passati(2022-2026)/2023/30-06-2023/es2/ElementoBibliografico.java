public abstract class ElementoBibliografico {
    private final String titolo;
    public ElementoBibliografico(String titolo){
        this.titolo = titolo;
    }
    public abstract float getCosto();
    public String getTitolo(){
        return this.titolo;
    }
    @Override
    public boolean equals(Object obj){
        if(this == obj)
            return true;
        if(obj == null || getClass() != obj.getClass())
            return false;
        ElementoBibliografico other = (ElementoBibliografico) obj;
        return this.titolo.equals(other.titolo);
    }
}
