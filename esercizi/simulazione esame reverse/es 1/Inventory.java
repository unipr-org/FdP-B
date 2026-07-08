import java.util.HashSet;

public class Inventory<T extends Comparable<T>>{

    private HashSet<T> inventory;

    public Inventory(){
        inventory = new HashSet<T>();
    }
    public void add(T item){
        inventory.add(item);
    }

    public int count(T item){
        if(inventory.isEmpty())
            throw new RuntimeException("Empity inventory");
        
        int tmp = 0;
        for (T el : inventory)
            if(item.compareTo(el) == 0)
                tmp++;
        
                // System.out.println("tmp " + tmp);
        return tmp;
    }

    public T getMostCommon(){
        int counter = 0;
        T tmp = null;
        for(T item : inventory){
            int c = count(item);
            if(c > counter){
                tmp = item;
                counter = c;
            }
        }

        return tmp;
    }
    public void print(){
        for(T item : inventory)
            System.out.print(item + " ");
    }
    public static void main(String[] args){
        Inventory<Integer> i = new Inventory<Integer>();

        i.add(10);
        i.add(10);
        i.add(10);
        i.add(10);
        i.add(10);
        i.add(1);
        i.add(0);
        i.add(20);
        i.print();
        // System.out.println(i.count(1));//1
        // System.out.println(i.count(10));//5
        // System.out.println(i.count(30));//0
        // System.out.println(i.getMostCommon());//10

        System.out.println("");
        Inventory<String> i2 = new Inventory<String>();
        i2.add("Pietro");
        i2.add("Luca");
        i2.add("Pietro");
        i2.add("Alessandro");
        i2.add("Chiara");
        i2.add("Giovanni");

            i2.print();
        // System.out.println(i2.count("Pietro"));//2
        // System.out.println(i2.count("Luca"));//1
        // System.out.println(i2.count("Simone"));//0
        // System.out.println(i2.getMostCommon());//"Pietro"
        


    }
}