/* Definire una classe templatica Set<T> che realizza il tipo di dato astratto insieme di elementi
di tipo T. La classe deve definire:
▶ un costruttore senza argomenti che crea un insieme vuoto
▶ un metodo void add(T value) che aggiunge un elemento all’insieme. Se l’elemento `e gi`a presente, il metodo deve
lanciare un’eccezione
▶ un metodo int size() const che ritorna la cardinalit`a dell’insieme
▶ un metodo bool contains(const T& value) const che ritorna true se l’elemento `e presente nell’insieme su cui `e
invocato il metodo, false altrimenti.
▶ un metodo Set<T> intersect(const Set<T>& other) const che ritorna un nuovo insieme che rappresenta l’intersezione
dell’insieme su cui `e invocato il metodo con un altro insieme other.
Si sovraccarichi l’operatore << in modo tale che stampi gli elementi dell’insieme su uno stream di output fout nel for-
mato {e1, e2, . . . , en}. Non `e consentito utilizzare classi della STL. Se necessario, ridefinire gli opportuni metodi, costruttori
e/o operatori. Specificare opportunamente eventuali metodi e parametri costanti. Massimizzare incapsulamento e infor-
mation hiding.*/
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
                throw runtime_error("ELemento gia' presente");
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
            throw out_of_range("Indice fuori range");
        return container[index];
    }
};
template <typename T>
ostream& operator<<(ostream& fout, const Set<T>& s){
    fout << "{";
    for(int i = 0; i < s.size(); i++){
        fout << s[i];
        if( i < s.size() - 1)
            fout << ", ";
    }
    fout << "}";
    return fout;
}

int main() {
    try {
        cout << "=== TEST 1: Creazione e inserimento (add) ===" << endl;
        Set<int> insiemeA;
        insiemeA.add(1);
        insiemeA.add(2);
        insiemeA.add(3);
        insiemeA.add(4);
        
        // Test dell'operatore << e del metodo size()
        cout << "Insieme A: " << insiemeA << " (Cardinalita': " << insiemeA.size() << ")" << endl;

        Set<int> insiemeB;
        insiemeB.add(3);
        insiemeB.add(4);
        insiemeB.add(5);
        insiemeB.add(6);
        cout << "Insieme B: " << insiemeB << " (Cardinalita': " << insiemeB.size() << ")" << endl;

        cout << "\n=== TEST 2: Controllo presenza (contains) ===" << endl;
        cout << "Insieme A contiene 2? " << (insiemeA.contains(2) ? "SI" : "NO") << " (Atteso: SI)" << endl;
        cout << "Insieme A contiene 5? " << (insiemeA.contains(5) ? "SI" : "NO") << " (Atteso: NO)" << endl;

        cout << "\n=== TEST 3: Intersezione (intersect) ===" << endl;
        // Gli elementi in comune tra {1,2,3,4} e {3,4,5,6} sono {3,4}
        Set<int> insiemeIntersezione = insiemeA.intersect(insiemeB);
        cout << "Risultato Intersezione: " << insiemeIntersezione << endl;
        cout << "Nuova cardinalita': " << insiemeIntersezione.size() << " (Atteso: 2)" << endl;

        cout << "\n=== TEST 4: Gestione dell'eccezione duplicati ===" << endl;
        cout << "Tento di aggiungere nuovamente il numero 2 nell'Insieme A..." << endl;
        insiemeA.add(2); // Questa riga lancerà l'eccezione runtime_error

    } catch (const runtime_error& e) {
        cout << ">>> Eccezione catturata con successo: " << e.what() << endl;
    } catch (const exception& e) {
        cout << ">>> Eccezione imprevista: " << e.what() << endl;
    }

    return 0;
}