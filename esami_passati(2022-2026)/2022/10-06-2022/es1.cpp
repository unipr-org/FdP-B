/*Definire una classe templatica Insieme<T> che realizza il tipo di dato astratto insieme di elementi di tipo T.
La classe deve definire:
1- un costruttore senza argomenti che crea un insieme vuoto.
2- Il metodo add aggiunge un elemento di tipo T all’insieme. Se l’elemento `e gi`a presente, il metodo deve lanciare un’eccezione.
3- Il metodo contains verifica se un elemento appartiene all’insieme.
4- Il metodo size ritorna la cardinalit`a dell’insieme.
5- Si sovraccarichi l’operatore + in modo tale che restituisca un nuovo insieme ottenuto dall’unione dell’insieme su cui `e chiamato il metodo e
l’insieme passato come parametro.
6- Si sovraccarichi l’operatore << in modo tale che stampi gli elementi dell’insieme su uno stream di output fout nel formato
{e1, e1, . . . , en}.
Non `e consentito utilizzare classi della STL. Se necessario, ridefinire gli opportuni metodi, costruttori e/o operatori.
Specificare opportunamente eventuali metodi costanti.*/
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Insieme{
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
    Insieme(){
        num_elem = 0;
        capacity = 10;
        container = new T[capacity];
    }
    Insieme(const Insieme<T>& other){
        capacity = other.capacity;
        num_elem = other.num_elem;
        container = new T[capacity];
        for(int i = 0; i < num_elem; i++)
            container[i] = other.container[i];
    }
    Insieme<T>& operator=(const Insieme<T>& other){
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
    ~Insieme(){
        delete[] container;
    }
    void add(const T& elem){
        for(int i = 0; i < num_elem; i++)
            if(container[i] == elem)
                throw runtime_error("Elemento gia' presente");
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
    int size() const{
        return num_elem;
    }
    Insieme<T> operator+(const Insieme<T>& other) const{
        Insieme<T> result;
        for(int i = 0; i < num_elem; i++)
            result.add(container[i]);
        for(int i = 0; i < other.num_elem; i++)
            if(!result.contains(other.container[i]))
                result.add(other.container[i]);
        return result;
    }
    const T& operator[](int index) const{
        if(index >= num_elem)
            throw out_of_range("Indice fuori range");
        return container[index];
    }
};
template <typename T>
ostream& operator<<(ostream& fout, const Insieme<T>& ins){
    fout << "{";
    for(int i = 0; i < ins.size(); i++){
        fout << ins[i];
        if(i < ins.size() - 1)
            fout << ", ";
    }
    fout << "}";
    return fout;
}


int main() {
    try {
        cout << "=== TEST 1: Inserimenti in Insieme A ===" << endl;
        Insieme<int> insiemeA;
        insiemeA.add(10);
        insiemeA.add(20);
        insiemeA.add(30);
        cout << "Insieme A: " << insiemeA << " (Cardinalita': " << insiemeA.size() << ")" << endl;

        cout << "\n=== TEST 2: Verifica presenza (contains) ===" << endl;
        cout << "A contiene 20? " << (insiemeA.contains(20) ? "SI" : "NO") << endl;
        cout << "A contiene 50? " << (insiemeA.contains(50) ? "SI" : "NO") << endl;

        cout << "\n=== TEST 3: Inserimenti in Insieme B ===" << endl;
        Insieme<int> insiemeB;
        insiemeB.add(30); // Elemento duplicato rispetto ad A
        insiemeB.add(40);
        insiemeB.add(50);
        cout << "Insieme B: " << insiemeB << " (Cardinalita': " << insiemeB.size() << ")" << endl;

        cout << "\n=== TEST 4: Unione degli insiemi (operatore +) ===" << endl;
        Insieme<int> insiemeUnione = insiemeA + insiemeB;
        cout << "Insieme Unione (A + B): " << insiemeUnione << endl;
        cout << "Nuova Cardinalita': " << insiemeUnione.size() << " (Atteso: 5)" << endl;

        cout << "\n=== TEST 5: Gestione Eccezione Duplicati ===" << endl;
        cout << "Tento di inserire nuovamente il 10 in Insieme A..." << endl;
        insiemeA.add(10); // Lancia eccezione

    } catch (const exception& e) {
        cout << ">>> Eccezione catturata: " << e.what() << endl;
    }

    return 0;
}