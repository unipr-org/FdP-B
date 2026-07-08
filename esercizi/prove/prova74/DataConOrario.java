public class DataConOrario extends Data implements Comparable{

    private int ora;
    public DataConOrario(int giorno, int mese, int anno, int ora){
        super(giorno, mese, anno);
        if(ora < 0 || ora > 23)
            throw new OraNonValida();
        this.ora = ora;
    }
    @Override
    public boolean precede(Object other){
        if(getClass() != other.getClass() || other == null)
            throw new OggettoNonValido();
            if(other != this){
                DataConOrario d = (DataConOrario) other;
                if(this.anno < d.anno)
                    return true;
                if(this.anno > d.anno)
                    return false;
                if(this.mese < d.mese)
                    return true;
                if(this.mese > d.mese)
                    return false;
                if(this.giorno < d.giorno)
                    return true;
                if(this.giorno > d.giorno)
                    return false;
                if(this.ora < d.ora)
                    return true;
            }
		return false;
    }
    @Override
    public boolean equals(Object obj) {
        return super.equals(obj) && ora == ((DataConOrario)obj).ora;
    }
    @Override
    public String toString() {
        return super.toString() + " - h:" + ora;
    }

    @Override
    public int hashCode() {
        return super.hashCode() * ora;
    }
    @Override
    public int compareTo(Object o) {
        if(o == null)
            throw new NullPointerException();
        if(this.equals(o))
            return 0;
        if(this.precede(o))
            return -1;
        else
            return 1;
    }
}
