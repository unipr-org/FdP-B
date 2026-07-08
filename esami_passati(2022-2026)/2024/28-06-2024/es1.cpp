/* Definire una classe templatica Set<T> che realizza il tipo di dato astratto insieme di elementi di tipo T.
La classe deve definire:
▶ un costruttore senza argomenti che crea un insieme vuoto
▶ un metodo void add(T value) che aggiunge un elemento all’insieme. Se l’elemento `e gi`a presente, il metodo deve
lanciare un’eccezione
▶ un metodo int size() const che ritorna la cardinalit`a dell’insieme
▶ un metodo bool contains(const T& value) const che verifica se value `e contenuto nell’insieme;
▶ un metodo Set<T> findInRange(const T& min, const T& max) const che ritorna un nuovo insieme di valori
compresi fra min e max
Si sovraccarichi l’operatore << in modo tale che stampi gli elementi dell’insieme su uno stream di output fout nel for-
mato {e1, e2, . . . , en}.
Non `e consentito utilizzare classi della STL.
Se necessario, ridefinire gli opportuni metodi, costruttori e/o operatori.
Specificare opportunamente eventuali metodi e parametri costanti. Massimizzare incapsulamento e information hiding*/
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
    Set<T> findInRange(const T& min, const T& max) const{
        Set<T> result;
        for(int i = 0; i < num_elem; i++)
            if(container[i] >= min && container[i] <= max && !result.contains(container[i]))
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
// --- MAIN DI VERIFICA ---
int main() {
    try {
        cout << "=== TEST 1: Inserimento elementi ===" << endl;
        Set<int> insieme;
        insieme.add(5);
        insieme.add(12);
        insieme.add(20);
        insieme.add(25);
        insieme.add(30);
        insieme.add(45);

        cout << "Insieme totale: " << insieme << " (Size: " << insieme.size() << ")" << endl;

        cout << "\n=== TEST 2: Filtro per Range (findInRange) ===" << endl;
        // Cerchiamo i valori compresi tra 10 e 30 (estremi inclusi)
        // Risultato atteso: {12, 20, 25, 30}
        Set<int> rangeFiltrato = insieme.findInRange(10, 30);
        cout << "Elementi nel range [10, 30]: " << rangeFiltrato << endl;
        cout << "Numero di elementi trovati: " << rangeFiltrato.size() << " (Atteso: 4)" << endl;

        cout << "\n=== TEST 3: Verifica eccezione duplicati ===" << endl;
        cout << "Provo ad aggiungere di nuovo il numero 20..." << endl;
        insieme.add(20); // Deve lanciare l'eccezione

    } catch (const exception& e) {
        cout << ">>> Eccezione intercettata correttamente: " << e.what() << endl;
    }
    return 0;
}