public abstract class Figurina implements Comparable<Figurina>{
    private final int id;
    public Figurina(int id){
        if(id <= 0)
            throw new IllegalArgumentException("L'id deve essere positivo");
        this.id = id;
    }
    public int getId(){
        return this.id;
    }
    @Override
    public boolean equals(Object obj){
        if(this == obj)
            return true;
        if(obj == null || getClass() != obj.getClass())
            return false;
        Figurina other = (Figurina) obj;
        return this.id == other.id;
    }
    @Override
    public int compareTo(Figurina other){
        return Integer.compare(this.id,other.id);
    }
}
