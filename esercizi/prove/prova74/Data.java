// package prova74;
public class Data implements Comparable{
    protected int anno;
    protected int mese;
    protected int giorno;

    public Data(int giorno, int mese, int anno){
        if(anno < 0 || mese > 12 || mese < 1 || giorno > 31 || giorno < 1)
            throw new DataNonValida();
        this.anno = anno;
        this.mese = mese;
        this.giorno = giorno;
    }
    public boolean precede(Object other){
        if(getClass() != other.getClass() || other == null)
            throw new OggettoNonValido();
        if(other != this){
            Data d = (Data) other;
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
        }
		return false;
    }
    @Override
    public boolean equals(Object obj) {
        if(getClass() != obj.getClass())
            return false;
        if(obj == null)
            return false;
        if(obj == this)
            return true;

        return giorno == ((Data)obj).giorno && mese == ((Data)obj).mese && anno == ((Data)obj).anno;
    }
    @Override
    public int hashCode() {
        return giorno * mese * anno;
    }
    @Override
    public String toString(){
        return  giorno +  "/" + mese + "/" + anno;
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