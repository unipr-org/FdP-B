public class Main{
    public static void main(String[] args){
        InventoryList<Integer> i = new InventoryList();
        
        i.add(1);
        i.add(1);
        i.add(2);
        i.add(5);
        i.add(6);
        i.add(6);
        i.add(6);
        i.printSelf();
        
        System.out.println(i.count(1));//2
        System.out.println(i.count(2));//1
        System.out.println(i.count(7));//0
        System.out.println(i.mostCommon());//6
    }
}
