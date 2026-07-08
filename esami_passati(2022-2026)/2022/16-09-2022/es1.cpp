/* Deﬁnire una classe templatica MultiSet<T> che realizza il tipo di dato astratto multi-
insieme di elementi di tipo T (informalmente, un multi-insieme `e un insieme che ammette elementi ripetuti). La classe
deve deﬁnire:
I un costruttore senza argomenti che crea un multi-insieme vuoto
I un metodo add che aggiunge un elemento preso come argomento al multi-insieme
I un metodo contains che, preso come argomento elem, controlla se elem `e contenuto nel multi-insieme
I un metodo isEmpty che controlla se il multi-insieme `e vuoto
Inoltre, si sovraccarichi l’operatore == in modo tale che controlli se il multi-insieme su cui `e chiamato il metodo `e uguale
ad un multi-insieme passato come parametro. Due multi-insiemi sono uguali se hanno gli stessi elementi e appaiono lo stesso
numero di volte.
Si sovraccarichi l’operatore << in modo tale che stampi gli elementi del multi-insieme su uno stream di
output fout nel formato [e1, e2, . . . , en].
Non `e consentito utilizzare classi della STL. Se necessario, rideﬁnire gli opportuni
metodi, costruttori e/o operatori. Speciﬁcare opportunamente eventuali metodi e parametri costanti. Massimizzare
incapsulamento e information hiding.*/
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
        capacity = capacity *2;
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
    ~MultiSet(){
        delete[] container;
    }
    MultiSet<T>& operator=(const MultiSet<T>& other){
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
    void add(const T& elem){
        if(num_elem == capacity)
            enlarge();
        container[num_elem++] = elem;
    }
    bool contains(const T& elem) const{
        for(int i = 0; i < num_elem; i++)
            if(container[i] == elem)
                return true;
        return false;
    }
    bool isEmpty() const{
        return num_elem == 0;
    }
    const T& operator[](int index) const{
        if(index >= num_elem)
            throw out_of_range("Elemento non esiste");
        return container[index];
    }
    int getSize() const{
        return num_elem;
    }
    bool operator==(const MultiSet<T>& other) const{
        if(num_elem != other.num_elem)
            return false;
        for(int i = 0; i < num_elem; i++){
            int count1 = 0;
            int count2 = 0;
            for(int j = 0; j < num_elem; j++){
                if(container[i] == container[j]) // conta quante volte container[i] appare in this
                    count1++;
                if(container[i] == other.container[j]) // conta quante volte container[i] appare in other
                    count2++;
            }
            if(count1 != count2)
                return false;
        }
        return true;
    }
};
template <typename T>
ostream& operator<<(ostream& fout, const MultiSet<T>& ms){
    fout << "[";
    for(int i = 0; i < ms.getSize(); i++){
        fout << ms[i];
        if(i < ms.getSize() - 1)
            fout << ", ";
    }
    fout << "]";
    return fout;
}
