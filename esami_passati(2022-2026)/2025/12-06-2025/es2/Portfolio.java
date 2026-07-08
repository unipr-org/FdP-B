import java.util.HashSet;
import java.util.Set;
import java.util.Iterator;
public class Portfolio implements Iterable<InvestmentAsset>{
    private String id;
    private String owner;
    private Set<InvestmentAsset> assets;
    public Portfolio(String id, String owner){
        this.id = id;
        this.owner = owner;
        this.assets = new HashSet<>();
    }
    public void addAsset(InvestmentAsset asset){
        if(asset == null)
            return;
        if(!this.assets.add(asset))
            throw new PortfolioException("Asset già presente nel portafoglio");
    }
    public double calculateTotalValue(){
        double somma = 0;
        for(InvestmentAsset as : assets)
            somma += as.getCurrentValue();
        return somma;
    }
    public Set<InvestmentAsset> getAssetsByRiskLevel(int level){
        Set<InvestmentAsset> res = new HashSet<>();
        for(InvestmentAsset ia : this.assets)
            if(ia.getRiskLevel() == level)
                res.add(ia);
        return res;
    }
    @Override
    public Iterator<InvestmentAsset> iterator(){
        return this.assets.iterator();
    }
}
