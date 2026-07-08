
public class InventoryList<T extends Comparable<T>>{
    private List<T> inv;
	
	public InventoryList(){
		inv = new List<T>();
    }
	public void add(T item){
		inv.listAdd(item);
	}
	public int count(T item){
		return inv.count(item);
	}
	public T mostCommon(){
		int n = 0;
		T item = null;
		Node<T> tmp = inv.getHead();
		while(tmp != null){
			int n2 = inv.count(tmp.getValue());
			if(n2 > n)
				item = tmp.getValue();
			tmp = tmp.getNext();
	
			}
		return item;
	}
	public void printSelf(){
	    inv.printSelf();
	}
}
