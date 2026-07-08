public class ContoCorrente implements MetodoPagamento, Comparable<ContoCorrente>{
    private String iban;
    private double saldo;
    public ContoCorrente(String iban, double saldo){
        this.iban = iban;
        this.saldo = saldo;
    }
    public String getIban(){
        return this.iban;
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
        ContoCorrente other = (ContoCorrente) obj;
        return this.iban.equals(other.iban) && this.saldo == other.saldo;
    }
    @Override
    public int compareTo(ContoCorrente other){
        return Double.compare(this.saldo, other.saldo);
    }
}
