public class Stock extends InvestmentAsset{
    private String sector;
    private double currentPrice;
    public Stock(String nome, double purchasePrice, double quantity, String sector, double currentPrice){
        super(nome, purchasePrice, quantity);
        this.sector = sector;
        this.currentPrice = currentPrice;
    }
    @Override
    public double getCurrentValue(){
        return currentPrice * this.getQuantity();
    }
    @Override
    public int getRiskLevel(){
        if(this.sector.equals("Tech"))
            return 3;
        else if(this.sector.equals("Healthcare"))
            return 2;
        else
            return 1;
    }
}
