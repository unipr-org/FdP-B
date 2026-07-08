import java.util.Set;
import java.util.HashSet;
import java.util.Iterator;
public class Confine implements Iterable<Dazio>{
    private final String nationName;
    private final  Set<Dazio> dazi;
    public Confine(String nationName){
        this.nationName = nationName;
        this.dazi = new HashSet<>();
    }
    public String getNationName(){
        return this.nationName;
    }
    public void addDazio(Dazio dazio){
        if(dazio != null)
            this.dazi.add(dazio);
    }
    public double getDazio(String nationName){
        for(Dazio d : this.dazi)
            if(d.getNationName().equals(nationName))
                return d.getRate();
        return 0;
    }
    void updateDazio(String nationName, double newRate){
        for(Dazio d : this.dazi){
            if(d.getNationName().equals(nationName)){
                d.setRate(newRate);
                return;
            }
        }
    }
    public Set<Dazio> getDazi() {
        return new HashSet<>(this.dazi);
    }
    @Override
    public boolean equals(Object obj){
        if(this == obj)
            return true;
        if(obj == null || getClass() != obj.getClass())
            return false;
        Confine other = (Confine) obj;
        return this.nationName.equals(other.getNationName()) && this.dazi.equals(other.dazi);
    }
    @Override
    public Iterator<Dazio> iterator(){
        return this.dazi.iterator();
    }
}
