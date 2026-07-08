import java.util.ArrayList;
import java.util.List;
public class Stack<T> implements Comparable<Stack<T>> {
    private List<T> elementi;
    public Stack() {
        this.elementi = new ArrayList<>();
    }
    public void push(T elemento) {
        this.elementi.add(elemento);
    }
    public T pop() throws EmptyStackException {
        if (this.isEmpty())
            throw new EmptyStackException("Impossibile eseguire pop: la pila è vuota.");
        return this.elementi.remove(this.elementi.size() - 1);
    }
    public T peek() throws EmptyStackException {
        if (this.isEmpty()) {
            throw new EmptyStackException("Impossibile eseguire peek: la pila è vuota.");
        }
        return this.elementi.get(this.elementi.size() - 1);
    }
    public boolean isEmpty() {
        return this.elementi.isEmpty();
    }
    public int size() {
        return this.elementi.size();
    }
    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null || getClass() != obj.getClass())
            return false;
        Stack<?> other = (Stack<?>) obj;
        return this.elementi.equals(other.elementi);
    }
    @Override
    public String toString() {
        return this.elementi.toString();
    }
    @Override
    public int compareTo(Stack<T> other) {
        return Integer.compare(this.size(), other.size());
    }
}
