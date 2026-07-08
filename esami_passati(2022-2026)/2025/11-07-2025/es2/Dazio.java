public class Dazio {
    private final String nationName;
    private double rate;
    public Dazio(String nationName, double rate){
        this.nationName = nationName;
        this.rate = rate;
    }
    public String getNationName(){
        return this.nationName;
    }
    public double getRate(){
        return this.rate;
    }
    public void setRate(double rate){
        this.rate = rate;
    }
    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Dazio other = (Dazio) obj;
        return this.nationName.equals(other.nationName) && Double.compare(this.rate, other.rate) == 0;
    }
}
