public class Node<T extends Comparable<T>>{
	
	private T value;
    private Node next;
	public Node(T x){
		value = x;
		next = null;
	}
	public void connectTo(Node<T> other){
		this.next = other;
	}
		
    public boolean compare(T item){
		if(value.compareTo(item) == 0)
			return true;
		return false;
	}
	public T getValue(){
		return this.value;
	}
    public Node getNext(){
		return this.next;
	}
}