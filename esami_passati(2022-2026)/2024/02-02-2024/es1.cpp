/* Definire una classe templatica Stack<T> che realizza il tipo di dato astratto pila di elementi
di tipo T (accesso di tipo LIFO: Last In First Out). La classe deve definire:
I un costruttore senza argomenti che crea una pila vuota;
I un metodo push che aggiunge un elemento di tipo T alla pila;
I un metodo pop che rimuove dalla pila l’ultimo elemento inserito e lo ritorna come risultato. Il metodo deve lanciare
un’eccezione se la pila `e vuota.
I un metodo isEmpty che controlla se la pila `e vuota.
I un metodo size che ritorna il numero di elementi nella pila
Non `e consentito utilizzare classi della STL. Se necessario, ridefinire gli opportuni metodi, costruttori e/o operatori.
Specificare opportunamente eventuali metodi e parametri costanti. Massimizzare incapsulamento e information hiding.*/
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
        capacity = capacity *2;
        T* supp = new T[capacity];
        for(int i = 0; i < num_elem; i++)
            supp[i] = container[i];
        delete[] container;
        container = supp;
    }
public:
    // costruttore vuoto
    Stack(){
        num_elem = 0;
        capacity = 10;
        container = new T[capacity];
    }
    // costruttore di copia
    Stack(const Stack<T>& other){
        capacity = other.capacity;
        num_elem = other.num_elem;
        container = new T[capacity];
        for(int i = 0; i < num_elem; i++)
            container[i] = other.container[i];
    }
    // distruttore
    ~Stack(){
        delete[] container;
    }
    // operatore di assegnamento
    Stack<T>& operator=(const Stack<T>& other){
        if(this != &other){
            delete[] container;
            capacity = other.capacity;
            num_elem = other.num_elem;
            container = new T[capacity];
            for(int i = 0; i < other.num_elem; i++)
                container[i] = other.container[i];
        }
        return *this;
    }
    void push(const T& elem){
        if(num_elem == capacity)
            enlarge();
        container[num_elem++] = elem;
    }
    T pop(){
        if(num_elem == 0)
            throw out_of_range("Pila vuota");
        num_elem--;
        return container[num_elem];
    }
    bool isEmpty() const{
        return num_elem == 0;
    }
    int size() const{
        return num_elem;
    }
};