/* Deﬁnire una classe templatica MultiSet<T> che realizza il tipo di dato astratto multiinsieme di elementi di tipo T
(informalmente, un multi-insieme `e un insieme che ammette elementi ripetuti).
La classe deve deﬁnire:
I un costruttore senza argomenti che crea un multi-insieme vuoto
I un metodo add che aggiunge un elemento preso come argomento al multi-insieme
I un metodo remove che, preso come argomento elem, rimuove dal multi-insieme tutti gli elementi uguali ad elem.
Se il multi-insieme `e vuoto, il metodo deve lanciare un’eccezione
I un metodo isEmpty che controlla se il multi-insieme `e vuoto
I un metodo cardinality che, preso come argomento elem, ritorna il numero di occorrenze di elem nel multi-insieme
Inoltre, si sovraccarichi l’operatore << in modo tale che stampi gli elementi del multi-insieme su uno stream di output
fout nel formato {e1, e2, . . . , en}.
Non `e consentito utilizzare classi della STL.
Se necessario, rideﬁnire gli opportuni metodi, costruttori e/o operatori.
Speciﬁcare opportunamente eventuali metodi e parametri costanti.
Massimizzare incapsulamento e information hiding.*/
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
        for(int i = 0 ; i < num_elem; i++)
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
    void add(const T& elem){
        if(num_elem == capacity)
            enlarge();
        container[num_elem++] = elem;
    }
    void remove(const T& elem){
        if(num_elem == 0)
            throw runtime_error("MultiSet vuoto");
        T* supp = new T[capacity];
        int j = 0;
        for(int i = 0; i < num_elem; i++)
            if(container[i] != elem)
                supp[j++] = container[i];
        num_elem = j;
        delete[] container;
        container = supp;
    }
    bool isEmpty() const{
        return num_elem == 0;
    }
    int cardinality(const T& elem) const{
        int count = 0;
        for(int i = 0; i < num_elem; i++)
            if(container[i] == elem)
                count++;
        return count;
    }
    int size() const{
        return num_elem;
    }
    const T& operator[](int index) const{
        if(index >= num_elem)
            throw out_of_range("Indice fuori range");
        return container[index];
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

int main() {
    try {
        cout << "=== TEST 1: Inserimenti e Duplicati ===" << endl;
        MultiSet<int> ms;
        ms.add(10);
        ms.add(20);
        ms.add(10);
        ms.add(30);
        ms.add(10);
        
        cout << "Contenuto: " << ms << endl;
        cout << "Dimensione totale: " << ms.size() << " (Atteso: 5)" << endl;
        cout << "Occorrenze di 10 (cardinality): " << ms.cardinality(10) << " (Atteso: 3)" << endl;

        cout << "\n=== TEST 2: Rimozione di tutti gli elementi uguali ===" << endl;
        cout << "Rimuovo tutti i '10'..." << endl;
        ms.remove(10);
        cout << "Contenuto post-rimozione: " << ms << endl;
        cout << "Nuova dimensione: " << ms.size() << " (Atteso: 2 -> {20, 30})" << endl;

        cout << "\n=== TEST 3: Verifica Eccezione su Insieme Vuoto ===" << endl;
        MultiSet<int> msVuoto;
        cout << "Tento di fare remove su un MultiSet vuoto..." << endl;
        msVuoto.remove(99); // Deve lanciare l'eccezione

    } catch (const exception& e) {
        cout << ">>> Eccezione catturata: " << e.what() << endl;
    }
    return 0;
}