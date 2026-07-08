public class DVD extends ElementoBibliografico {
    private final String regista;
    private final float costoDVD;
    public DVD(String titolo, String regista, float costoDVD){
        super(titolo);
        this.regista = regista;
        this.costoDVD = costoDVD;
    }
    @Override
    public float getCosto(){
        return this.costoDVD;
    }
    public String getRegistra(){
        return this.regista;
    }
    @Override
    public boolean equals(Object obj){
        if(this == obj)
            return true;
        if(obj == null || getClass() != obj.getClass())
            return false;
        DVD other = (DVD) obj;
        return this.getTitolo().equals(other.getTitolo()) && this.regista.equals(other.regista);
    }
}
