public class CartaDiCredito implements MetodoPagamento{
    private String numCarta;
    private double saldo;
    public CartaDiCredito(String numCarta, double saldo){
        this.numCarta = numCarta;
        this.saldo = saldo;
    }
    public String getNumCarta(){
        return this.numCarta;
    }
    @Override
    public double verificaSaldo(){
        return this.saldo;
    }
    @Override
    public void incrementa(double importo){
        this.saldo += importo;
    }
    @Override
    public void decrementa(double importo){
        if(this.saldo < importo)
            throw new SaldoNonSufficienteException("Saldo insufficiente");
        this.saldo -= importo;
    }
    @Override
    public boolean equals(Object obj){
        if(this == obj)
            return true;
        if(obj == null || getClass() != obj.getClass())
            return false;
        CartaDiCredito other = (CartaDiCredito) obj;
        return this.numCarta.equals(other.numCarta) && this.saldo == other.saldo;
    }
}
