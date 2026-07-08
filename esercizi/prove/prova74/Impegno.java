public class Impegno implements Comparable{
    private String nota;
    private DataConOrario data;

    public Impegno(DataConOrario data, String nota){
        this.data = data;
        this.nota = nota;
    }

    @Override
    public String toString() {
        return data.toString() + " " + nota;
    }
    @Override

    public int compareTo(Object o) {
        if(getClass() != o.getClass() || o == null)
            throw new OggettoNonValido();
        return data.compareTo(((Impegno)o).data);
    }
}
