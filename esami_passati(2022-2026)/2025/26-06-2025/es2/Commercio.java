import java.util.Set;
import java.util.HashSet;
import java.util.List;
public class Commercio {
    private final Set<Confine> confini;
    public Commercio(Set<Confine> confini){
        if(confini == null)
            this.confini = new HashSet<>();
        else
            this.confini = new HashSet<>(confini);
    }
    private Confine cercaConfine(String nationName){
        for(Confine c : this.confini)
            if(c.getNationName().equals(nationName))
                return c;
        return null;
    }
    public double importazione(String exporter, String importer, double amount){
        Confine confineImportatore = cercaConfine(importer);
        if(confineImportatore != null){
            double dazioTasso = confineImportatore.getDazio(exporter);
            return amount * (1.0 + dazioTasso);
        }
        return amount; // se non c'è il confine, l'ammontare resta invariato
    }
    public double saldoTotale(String nation1, String nation2, List<Double> values){
        double saldo = 0.0;
        if(values == null)
            return saldo;
        for(double val : values){
            if(val > 0){
                double valoreTassato = importazione(nation2, nation1, val);
                saldo = saldo + valoreTassato;
            }
            else if(val < 0){
                double valoreAssoluto = Math.abs(val);
                double valoreTassato = importazione(nation1, nation2, valoreAssoluto);
                saldo = saldo - valoreTassato;
            }
        }
        return saldo;
    }
    public Set<Confine> getConfine(){
        return new HashSet<>(this.confini);
    }
}
