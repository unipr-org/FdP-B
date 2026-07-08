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
}
