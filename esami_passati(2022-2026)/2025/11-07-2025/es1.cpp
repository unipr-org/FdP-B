/* Definire una classe templatica Set<T> che realizza il tipo di dato astratto insieme di elementi di tipo T.
La classe deve definire:
1- un costruttore senza argomenti che crea un insieme vuoto
2- un metodo void add(T value) che aggiunge un elemento all’insieme. 
   Se l’elemento `e gi`a presente, il metodo deve lanciare un’eccezione
3- un metodo int size() const che ritorna la cardinalit`a dell’insieme
4- un metodo bool contains(const T& value) const che ritorna true se l’elemento `e presente nell’insieme su cui `e
   invocato il metodo, false altrimenti.
5- un metodo Set<T> intersect(const Set<T>& other) const che ritorna un nuovo insieme che rappresenta l’intersezione
   dell’insieme su cui `e invocato il metodo con un altro insieme other.
6- Si sovraccarichi l’operatore << in modo tale che stampi gli elementi dell’insieme su uno stream di output fout nel
formato {e1, e2, . . . , en}.
Non `e consentito utilizzare classi della STL. Se necessario, ridefinire gli opportuni metodi, costruttori
e/o operatori. Specificare opportunamente eventuali metodi e parametri costanti. Massimizzare incapsulamento e
information hiding.*/
#include <iostream>
#include <stdexcept>
using namespace std;
template <typename T>
class Set{
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
    Set(){
        num_elem = 0;
        capacity = 10;
        container = new T[capacity];
    }
    Set(const Set<T>& other){
        capacity = other.capacity;
        num_elem = other.num_elem;
        container = new T[capacity];
        for(int i = 0; i < num_elem; i++)
            container[i] = other.container[i];
    }
    Set<T>& operator=(const Set<T>& other){
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
    ~Set(){
        delete[] container;
    }
    void add(T value){
        for(int i = 0; i < num_elem; i++)
            if(container[i] == value)
                throw runtime_error("Elemento già presente");
        if(num_elem == capacity)
            enlarge();
        container[num_elem++] = value;
    }
    int size() const{
        return num_elem;
    }
    bool contains(const T& value) const{
        for(int i = 0; i < num_elem; i++)
            if(container[i] == value)
                return true;
        return false;
    }
    Set<T> intersect(const Set<T>& other) const{
        Set<T> result;
        for(int i = 0; i < num_elem; i++)
            if(other.contains(container[i]))
                result.add(container[i]);
        return result;
    }
    const T& operator[](int index) const{
        if(index >= num_elem)
            throw out_of_range("Elemento non esiste");
        return container[index];
    }
};
template <typename T>
ostream& operator<<(ostream& fout, const Set<T>& s){
    fout << "{";
    for(int i = 0; i < s.size(); i++){
        fout << s[i];
        if(i < s.size() - 1)
            fout << ", ";
    }
    fout << "}";
    return fout;
}
int main() {
    try {
        Set<string> insieme1;
        insieme1.add("Mela");
        insieme1.add("Banana");
        insieme1.add("Pera");
        insieme1.add("Arancia");
        cout << "Insieme 1: " << insieme1 << " (Size: " << insieme1.size() << ")" << endl;

        Set<string> insieme2;
        insieme2.add("Banana");
        insieme2.add("Kiwi");
        insieme2.add("Arancia");
        insieme2.add("Uva");
        cout << "Insieme 2: " << insieme2 << " (Size: " << insieme2.size() << ")" << endl;

        // Test dell'intersezione
        cout << "\nCalcolo l'intersezione..." << endl;
        Set<string> intersezione = insieme1.intersect(insieme2);
        
        // Risultato atteso: {Banana, Arancia}
        cout << "Insieme Intersezione: " << intersezione << " (Size: " << intersezione.size() << ")" << endl;

        // Test eccezione duplicati
        cout << "\nTento di riaggiungere 'Mela' nell'Insieme 1..." << endl;
        insieme1.add("Mela");

    } catch (const exception& e) {
        cout << ">>> Eccezione catturata correttamente: " << e.what() << endl;
    }

    return 0;
}
