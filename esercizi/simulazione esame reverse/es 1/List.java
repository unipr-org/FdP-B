

public class List<T extends Comparable<T>>{

	private Node<T> head;
	private Node<T> tail;
	private int lenght;
	
	public List(){
		lenght = 0;
		head = null;
		tail = null;
	}
	
	public void listAdd(T item){
		if(head == null){
			head = new Node<T>(item);
			tail = head;
		}else{
			Node<T> temp = new Node<T>(item);
			tail.connectTo(temp);
			tail = temp;
		}
		lenght++;
	}
	public int count(T item){
		Node<T> tmp = head;
		int n = 0;
		while(tmp != null){
			if(tmp.compare(item))
				n++;
			tmp = tmp.getNext();
		}
		return n;
	}
	public Node<T> getHead(){
		return this.head;
	}
	public void printSelf(){
	    Node<T> tmp = head;
	    System.out.println("");
	    while(tmp != null){
	        System.out.print(tmp.getValue() + " ");
	        tmp = tmp.getNext();
	    }
	    System.out.println("");
	}
}
