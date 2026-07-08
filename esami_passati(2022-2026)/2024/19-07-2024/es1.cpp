/* Definire una classe templatica MultiSet<T> che realizza il tipo di dato astratto multi-
insieme di elementi di tipo T (informalmente, un multi-insieme `e un insieme che ammette elementi ripetuti).
La classe deve definire:
▶ un costruttore senza argomenti che crea un multi-insieme vuoto
▶ un metodo bool isEmpty() const che verifica se il multi-insieme `e vuoto
▶ un metodo void add(T value) che aggiunge un elemento al multi-insieme
▶ un metodo int cardinality(const T& value) const che, preso come argomento value, ritorna il numero di
occorrenze di value nel multi-insieme
▶ un metodo MultiSet<T> intersection(const MultiSet<T>& other) const che ritorna un nuovo multi-insieme
contenente gli elementi presenti in entrambi i multi-insiemi, con il numero di occorrenze minore per ciascun elemento.
Ad esempio, se un multi-insieme contiene {1, 2, 2, 3} e un altro multi-insieme contiene {2, 4}, l’intersezione di
questi due multi-insiemi `e essere {2}.
Si sovraccarichi l’operatore << in modo tale che stampi gli elementi del multi-insieme su uno stream di output fout
nel formato {e1, e2, . . . , en}. Non `e consentito utilizzare classi della STL. Se necessario, ridefinire gli opportuni metodi,
costruttori e/o operatori. Specificare opportunamente eventuali metodi e parametri costanti*/
#include <iostream>
#include <stdexcept>
using namespace std;
template <typename T>
class MultiSet{
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
    MultiSet(){
        num_elem = 0;
        capacity = 10;
        container = new T[capacity];
    }
    MultiSet(const MultiSet<T>& other){
        capacity = other.capacity;
        num_elem = other.num_elem;
        container = new T[capacity];
        for(int i = 0; i < num_elem; i++)
            container[i] = other.container[i];
    }
    MultiSet<T>& operator=(const MultiSet<T>& other){
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
    ~MultiSet(){
        delete[] container;
    }
    bool isEmpty() const{
        return num_elem == 0;
    }
    void add(const T& elem){
        if(num_elem == capacity)
            enlarge();
        container[num_elem++] = elem;
    }
    int cardinality(const T& value) const{
        int count = 0;
        for(int i = 0; i < num_elem; i++)
            if(container[i] == value)
                count++;
        return count;
    }
    MultiSet<T> intersection(const MultiSet<T>& other) const{
        MultiSet<T> result;
        for(int i = 0; i < num_elem; i++){
            if(result.cardinality(container[i]) == 0){
                int count1 = cardinality(container[i]);
                int count2 = other.cardinality(container[i]);
                int min_count = count1 < count2 ? count1 : count2;
                for(int j = 0; j < min_count; j++)
                    result.add(container[i]);
            }
        }
        return result;
    }
    const T& operator[](int index) const{
        if(index >= num_elem)
            throw out_of_range("Elemento non esiste");
        return container[index];
    }
    int size() const{
        return num_elem;
    }
};
template <typename T>
ostream& operator<<(ostream& fout, const MultiSet<T>& ms){
    fout << "{";
    for(int i = 0; i < ms.size(); i++){
        fout << ms[i];
        if(i < ms.size() - 1)
            fout << ", ";
    }
    fout << "}";
    return fout;
}
