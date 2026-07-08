/* Deﬁnire una classe templatica Stack<T> che realizza il tipo di dato astratto pila di elementi
di tipo T (LIFO: Last In First Out). La classe deve deﬁnire un costruttore senza argomenti che crea una pila vuota. La
classe deve deﬁnire un metodo push che aggiunge un elemento di tipo T alla pila. La classe deve deﬁnire un metodo pop
che rimuove dalla pila l’ultimo elemento inserito e lo ritorna come risultato. Il metodo deve lanciare un’eccezione se la pila
`e vuota. La classe deve deﬁnire un metodo isEmpty che controlla se la pila `e vuota. La classe deve deﬁnire un metodo
size che ritorna il numero di elementi memorizzati nella pila. Si sovraccarichi l’operatore << in modo tale che stampi gli
elementi della pila su uno stream di output fout nel formato [e1, e1, . . . , en]. Non `e consentito utilizzare classi della STL.
Se necessario, rideﬁnire gli opportuni metodi, costruttori e/o operatori. Speciﬁcare opportunamente eventuali metodi e
parametri costanti. Massimizzare incapsulamento e information hiding.*/
#include <iostream>
#include <stdexcept>
using namespace std;
template <typename T>
class Stack{
    private:
    T* container;
    int num_elem;
    int capacity;
    void enlarge(){
        capacity *= 2;
        T* supp = new T[capacity];
        for(int i = 0; i < num_elem; i++)
            supp[i] = container[i];
        delete[] container;
        container = supp;
    }
    public:
    Stack(){
        num_elem = 0;
        capacity = 10;
        container = new T[capacity];
    }
    Stack(const Stack<T>& other){
        capacity = other.capacity;
        num_elem = other.num_elem;
        container = new T[capacity];
        for(int i = 0; i < num_elem; i++)
            container[i] = other.container[i];
    }
    Stack<T>& operator=(const Stack<T>& other){
        if(this != &other){
            delete[] container;
            capacity = other.capacity;
            num_elem = other.num_elem;
            container = new T[capacity];
            for(int i = 0; i < num_elem; i++)
                container[i] = other.container[i];
        }
        return *this;
    }
    ~Stack(){
        delete[] container;
    }
    void push(const T& elem){
        if(num_elem == capacity)
            enlarge();
        container[num_elem++] = elem;
    }
    T pop(){
        if(num_elem == 0)
            throw runtime_error("Pila vuota");
        return container[--num_elem];
    }
    bool isEmpty() const{
        return num_elem == 0;
    }
    int size() const{
        return num_elem;
    }
    const T& operator[](int index) const{
        if(index >= num_elem)
            throw out_of_range("Elemento non esiste");
        return container[index];
    }
};
template <typename T>
ostream& operator<<(ostream& fout, const Stack<T>& s){
    fout <<"[";
    for(int i = 0; i < s.size(); i++){
        fout << s[i];
        if(i < s.size() - 1)
            fout << ", ";
    }
    fout <<"]";
    return fout;
}
