public class Data {
    private final int giorno ;
    private final int mese ;
    private final int anno ;
    public Data ( int giorno , int mese , int anno ) {
        if ( valida ( giorno , mese , anno )) {
            this . giorno = giorno ;
            this . mese = mese ;
            this . anno = anno ;
        } else
            throw new RuntimeException ();
    }
    private boolean valida (int giorno , int mese , int anno ) {
        // controllo sulla validita ’ di giorno , mese e anno
    }
    @Override
    public String toString () {
        return giorno + " / " + mese + " / " + anno ;
    }
    @Override
    public int hashCode () {
        // implementazione di hashCode coerente con il metodo equals
    }
    @Override
    public boolean equals ( Object obj ) {
        if ( this == obj )
            return true ;
        if ( obj == null )
            return false ;
        if ( getClass () != obj . getClass ())
            return false ;
        Data other = ( Data ) obj ;
        return anno == other . anno && giorno == other . giorno && mese == other . mese ;
    }
}