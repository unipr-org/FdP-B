/* Deﬁnire una classe templatica Set<T> che realizza il tipo di dato astratto insieme di elementi di tipo T.
La classe deve deﬁnire:
I un costruttore senza argomenti che crea un insieme vuoto
I un metodo add che aggiunge un elemento di tipo T all’insieme. Se l’elemento `e gi`a presente, il metodo deve lanciare
  un’eccezione
I un metodo contains che veriﬁca se un elemento appartiene all’insieme
I un metodo size che ritorna la cardinalit`a dell’insieme
Si sovraccarichi l’operatore - in modo tale che restituisca un nuovo insieme ottenuto dall’intersezione fra l’insieme su
cui `e chiamato il metodo e l’insieme passato come parametro. 
Si sovraccarichi l’operatore << in modo tale che stampi
gli elementi dell’insieme su uno stream di output fout nel formato {e1, e2, . . . , en}.
Non `e consentito utilizzare classi della STL. Se necessario, rideﬁnire gli opportuni metodi, costruttori e/o operatori.
Speciﬁcare opportunamente eventuali metodi e parametri costanti. Massimizzare incapsulamento e information hiding.*/
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
    Set<T> operator-(const Set<T>& other) const{
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
        cout << "=== TEST 1: Creazione Insiemi ===" << endl;
        Set<int> s1;
        s1.add(1);
        s1.add(2);
        s1.add(3);
        s1.add(4);
        
        Set<int> s2;
        s2.add(3);
        s2.add(4);
        s2.add(5);
        s2.add(6);

        cout << "Insieme 1: " << s1 << endl;
        cout << "Insieme 2: " << s2 << endl;

        cout << "\n=== TEST 2: Intersezione tramite operatore '-' ===" << endl;
        // Eseguiamo l'operazione richiesta dalla traccia
        Set<int> sIntersezione = s1 - s2;
        
        // Risultato atteso dell'intersezione: {3, 4}
        cout << "Risultato di (s1 - s2): " << sIntersezione << endl;
        cout << "Cardinalita' del risultato: " << sIntersezione.size() << " (Atteso: 2)" << endl;

        cout << "\n=== TEST 3: Verifica Eccezione Duplicati ===" << endl;
        cout << "Provo ad aggiungere un elemento gia' presente (2) in Insieme 1..." << endl;
        s1.add(2);

    } catch (const exception& e) {
        cout << ">>> Eccezione intercettata: " << e.what() << endl;
    }

    return 0;
}