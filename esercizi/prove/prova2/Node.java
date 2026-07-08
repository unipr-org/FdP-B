package prova2;

public class Node{
    private Node next;
    private String val;
    public Node(String s){
        this.val = s;
        this.next = null;
    }
    public void setNext(Node next){
        this.next = next;
    }
    public Node getNext(){
        return this.next;
    }
    public String getVal(){
        return this.val;
    }
}
