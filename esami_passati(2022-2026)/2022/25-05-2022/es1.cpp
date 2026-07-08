/* Deﬁnire una classe templatica Inventory che rappresenta un inventario di elementi di
tipo T. La classe deve deﬁnire un costruttore senza argomenti che crea un inventario vuoto. Il metodo add aggiunge un
elemento di tipo T all’inventario. Il metodo count prende come argomento un elemento di tipo T e restituisce il numero
di occorrenza dell’elemento passato come argomento. Il metodo getMostCommon restituisce l’elemento che occorre pi`u
spesso nell’inventario. Un inventario ha dimensione indeﬁnita. Non `e consentito usare la STL. Se necessario, rideﬁnire gli
opportuni metodi, costruttori e/o operatori.
Inventory < int > inv0 ;
Inventory < string > inv1 ;
inv0 . add (1); inv0 . add (2); inv0 . add (1); inv0 . add (3);
inv1 . add ( " hello " ); inv1 . add ( " hello " ); inv1 . add ( " ciao " ); inv1 . add ( " hello " );
cout << inv0 . count (7) << endl ; // output : 0
cout << inv0 . count (1) << endl ; // output : 2
cout << inv1 . count ( " ciao " ) << endl ; // output : 1
cout << inv0 . getMostCommon () << endl ; // output : 1*/
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
template <typename T>
class Inventory{
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
    Inventory(){
        num_elem = 0;
        capacity = 10;
        container = new T[capacity];
    }
    Inventory(const Inventory<T>& other){
        capacity = other.capacity;
        num_elem = other.num_elem;
        container = new T[capacity];
        for(int i = 0; i < num_elem; i++)
            container[i] = other.container[i];
    }
    Inventory<T>& operator=(const Inventory<T>& other){
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
    ~Inventory(){
        delete[] container;
    }
    void add(const T& elem){
        if(num_elem == capacity)
            enlarge();
        container[num_elem++] = elem;
    }
    int count(const T& elem) const{
        int count = 0;
        for(int i = 0; i < num_elem; i++)
            if(container[i] == elem)
                count++;
        return count;
    }
    T getMostCommon() const{
        if(num_elem == 0)
            throw runtime_error("Inventario vuoto");
        T most_common = container[0];
        int max_count = 0;
        for(int i = 0; i < num_elem; i++){
            int current_count = count(container[i]);
            if(current_count > max_count){
                max_count = current_count;
                most_common = container[i];
            }
        }
        return most_common;
    }
};
int main() {
    Inventory<int> inv0;
    Inventory<string> inv1;

    inv0.add(1);
    inv0.add(2);
    inv0.add(1);
    inv0.add(3);

    inv1.add("hello");
    inv1.add("hello");
    inv1.add("ciao");
    inv1.add("hello");

    cout << inv0.count(7) << endl;           // output: 0
    cout << inv0.count(1) << endl;           // output: 2
    cout << inv1.count("ciao") << endl;      // output: 1
    cout << inv0.getMostCommon() << endl;    // output: 1

    return 0;
}