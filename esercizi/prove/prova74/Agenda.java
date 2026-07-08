import java.util.HashSet;
public class Agenda{
    HashSet<Impegno> impegni;
    public Agenda(){
        impegni = new HashSet<Impegno>();
    }
    public void add(Object o, String info){
        if(!(o instanceof DataConOrario))
            throw new OggettoNonValido();
        if(impegni.contains(o))
            throw new ImpegnoGiaPresente();
        
            impegni.add(new Impegno(((DataConOrario)o), info));
    }
    @Override
    public String toString(){
        String tmp = "";
        for(Impegno i : impegni)
            tmp += i.toString() + "\n";
        return tmp;
    }
}
