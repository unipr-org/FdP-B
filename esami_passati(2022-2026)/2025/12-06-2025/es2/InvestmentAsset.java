public abstract class InvestmentAsset {
    private String nome;
    private double purchasePrice;
    private double quantity;
    public InvestmentAsset(String nome, double purchasePrice, double quantity){
        this.nome = nome;
        this.purchasePrice = purchasePrice;
        this.quantity = quantity;
    }
    public String getNome(){
        return this.nome;
    }
    public double getPurchasePrice(){
        return this.purchasePrice;
    }
    public double getQuantity(){
        return this.quantity;
    }
    public abstract int getRiskLevel();
    public abstract double getCurrentValue();
    public double calculateProfit(){
        return (getCurrentValue()-this.purchasePrice) * this.quantity;
    }
    @Override
    public boolean equals(Object obj){
        if(this == obj)
            return true;
        if(obj == null || getClass() != obj.getClass())
            return false;
        InvestmentAsset other = (InvestmentAsset) obj;
        return this.nome.equals(other.nome);
    }
}
