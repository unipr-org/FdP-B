public class Libro extends ElementoBibliografico {
    private final String autore;
    private final float costoLibro;
    public Libro(String titolo, String autore, float costoLibro){
        super(titolo);
        this.autore = autore;
        this.costoLibro = costoLibro;
    }
    @Override
    public float getCosto(){
        return this.costoLibro;
    }
    public String getAutore(){
        return this.autore;
    }
    @Override
    public boolean equals(Object obj){
        if(this == obj)
            return true;
        if(obj == null || getClass() != obj.getClass())
            return false;
        Libro other = (Libro) obj;
        return this.getTitolo().equals(other.getTitolo()) && this.autore.equals(other.autore);
    }
}
