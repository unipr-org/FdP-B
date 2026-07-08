public interface MetodoPagamento {
    double verificaSaldo();
    void incrementa(double importo);
    void decrementa(double importo);
}
