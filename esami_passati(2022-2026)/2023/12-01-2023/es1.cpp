/* Definire una classe templatica Queue<T> che realizza il tipo di dato astratto coda di elementi di tipo T che
permette di inserire un nuovo elemento in coda e di rimuovere un elemento dalla testa della coda.
La classe deve definire:
I un costruttore senza argomenti che crea una coda vuota
I un metodo enqueue che, preso come argomento elem, aggiunge elem in coda
I un metodo dequeue che rimuove l’elemento in testa alla coda e lo restituisce. Se la coda `e vuota, il metodo deve
lanciare un’eccezione.
I un metodo isEmpty che controlla se la coda `e vuota
Si sovraccarichi l’operatore << in modo tale che stampi gli elementi della coda su uno stream di output fout nel formato
[e1, e2, . . . , en]. Non `e consentito utilizzare classi della STL. Se necessario, ridefinire gli opportuni metodi, costruttori e/o
operatori. Specificare opportunamente eventuali metodi e parametri costanti. Massimizzare incapsulamento e information
hiding.*/
#include <iostream>
#include <stdexcept>
using namespace std;
template <typename T>
class Queue{
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
    Queue(){
        num_elem = 0;
        capacity = 10;
        container = new T[capacity];
    }
    Queue(const Queue<T>& other){
        capacity = other.capacity;
        num_elem = other.num_elem;
        container = new T[capacity];
        for(int i = 0; i < num_elem; i++)
            container[i] = other.container[i];
    }
    ~Queue(){
        delete[] container;
    }
    Queue<T>& operator=(const Queue<T>& other){
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
    void enqueue(const T& elemento){
        if(num_elem == capacity)
            enlarge();
        container[num_elem++] = elemento;
    }
    T dequeue(){
        if(num_elem == 0)
            throw out_of_range("Coda vuota");
        T result = container[0];
        for(int i = 1; i < num_elem; i++)
            container[i - 1] = container[i];
        num_elem--;
        return result;
    }
    bool isEmpty() const{
        return num_elem == 0;
    }
    const T& operator[](int index) const{
        if(index >= num_elem)
            throw out_of_range("Indice fuori range");
        return container[index];
    }
    int getSize() const{
        return num_elem;
    }
};
template <typename T>
ostream& operator<<(ostream& fout, const Queue<T>& q){
    fout << "[";
    for(int i = 0; i < q.getSize(); i++){
        fout << q[i];
        if(i < q.getSize() - 1)
            fout << ", ";
    }
    fout << "]";
    return fout;
}