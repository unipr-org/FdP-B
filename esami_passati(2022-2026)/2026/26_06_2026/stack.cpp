template <class T>
class Stack {
private:
    T* pila;
    int top;
    int dim_tot;

    void estendi() {
        dim_tot = dim_tot * 2;
        T* new_arr = new T[dim_tot];
        for (int i = 0; i < top; i++) {
            new_arr[i] = pila[i];
        }
        delete[] pila;
        pila = new_arr;
    }

public:

    Stack() {
        top = 0;
        dim_tot = 1;
        pila = new T[dim_tot];
    }


    Stack(const Stack& s) {
        pila = new T[s.dim_tot];
        for (int i = 0; i < s.top; i++)
            pila[i] = s.pila[i];
        top = s.top;
        dim_tot = s.dim_tot;
    }


    ~Stack() {
        delete[] pila;
    }

    bool isEmpty() const {
        return top == 0;
    }


    bool operator==(const Stack<T>& s) const {
        if (this->top != s.top) {
            return false;
        }
        for (int i = 0; i < this->top; i++) {
            if (this->pila[i] != s.pila[i]) {
                return false;
            }
        }
        return true;
    }


    void push(const T& x) {
        if (top == dim_tot) {
            estendi();
        }
        pila[top++] = x;
    }


    T pop() {
        if (!isEmpty()) {
            T ultimo = pila[top-1];
            top--;
            return ultimo;
        } else {
            throw out_of_range("Stack vuoto");
        }
    }


    Stack<T>& operator=(const Stack<T>& s) {
        if (this != &s) {
            delete[] pila;
            pila = new T[s.dim_tot];
            for (int i = 0; i < s.top; i++)
                pila[i] = s.pila[i];
            top = s.top;
            dim_tot = s.dim_tot;
        }
        return *this;
    }

    T getElem(int i) const {

        if (i < 0 || i >= top) throw out_of_range("Indice non valido");
        return pila[i];
    }

    int getSize() const {
        return top;
    }
};

template <typename T>
ostream& operator<<(ostream& dest, const Stack<T>& s) {
    dest << "[top->";
    for (int i = s.getSize() - 1; i >= 0; i--) {
        dest << s.getElem(i);
        if (i > 0)
            dest << ", ";
    }
    dest<<"]";
    return dest;
}
