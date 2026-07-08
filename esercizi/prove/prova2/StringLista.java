package prova2;
public class StringLista{
    private Node nodo;
    private int n;

    public StringLista(){
        this.n = 0;
        this.nodo = null;
    }
    public void inserisciTesta(String x){
        Node tmp = new Node(x);
        tmp.setNext(this.nodo);
        this.nodo = tmp;
        this.n++;
    }

    public boolean vuota(){
        return this.n == 0;
    }

    public int length(){
        return this.n;
    }
    public String estraiTesta() throws RuntimeException{
        if(n == 0)
            throw new CustomExceptions("Lista vuota");
        String val = this.nodo.getVal();
        nodo = nodo.getNext();
        this.n--;
        return val;
    }
    
    @Override
    public boolean equals(Object obj){
        if(obj.getClass() != this.getClass())
            return false;

        StringLista other = (StringLista) obj;
        if(this.n != other.length())
            return false;
        for(int i = 0; i < this.n; i++)
            if(!this.nodo.getVal().equals(other.nodo.getVal()))
                return false;
            
        return true;
    }
    @Override
    public String toString() {
        String values = "[";
        Node tmp = this.nodo;
        while(tmp != null){
            values += tmp.getVal();
            tmp = tmp.getNext();
            if(tmp != null)
            values += ", ";
        }
        values += "]";
        return values;
    }
    @Override
    
    public StringLista clone(){
        StringLista tmp = new StringLista();
        Node cursor = this.nodo;
        while(cursor != null){
            tmp.inserisciTesta(cursor.getVal());
            cursor = cursor.getNext();
        }
        
        return tmp;
    }
    public boolean contains(StringLista other){
        if(other.length() > this.n)
            return false;

            while(other.nodo != null){
            Node tmp = this.nodo;
            while(tmp != null && !tmp.getVal().equals( other.nodo.getVal())){
                tmp = tmp.getNext();
            }
            if(tmp==null)
                return false;
            
            other.nodo = other.nodo.getNext();
        }
        return true;
    }

    public boolean contains(String other){
        StringLista tmp = new StringLista();
        tmp.inserisciTesta(other);
        return this.contains(tmp);
    }
}