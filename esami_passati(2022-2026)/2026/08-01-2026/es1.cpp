/* Definire una classe templatica Map<K, V> che realizza il tipo di dato astratto mappa con chiavi di tipo K 
e valori di tipo V.
La classe deve definire:
▶ un costruttore senza argomenti che crea una mappa vuota;
▶ un metodo void insert(const K& key, const V& value) che inserisce una coppia chiave-valore nella mappa; 
   se la mappa contiene gi`a una coppia con chiave key, il valore corrispondente dovr`a essere aggiornato con value;
▶ un metodo bool contains(const K& key) const che verifica se una chiave `e presente nella mappa;
▶ un metodo bool isEmpty() const che controlla se la mappa `e vuota;
▶ un metodo void remove(const K& key) che rimuove una coppia chiave-valore dalla mappa. Il metodo deve lanciare
   un’eccezione se la chiave non `e presente;
▶ un metodo int size() const che ritorna il numero di coppie chiave-valore nella mappa
Non `e consentito utilizzare le classi relative alle mappe della STL. Se necessario, ridefinire gli opportuni metodi, 
costruttori e/o operatori. Specificare opportunamente eventuali metodi e parametri costanti. Massimizzare 
incapsulamento e information hiding. 
Hint: definire una classe templatica Pair<K, V> che modella una coppia di valori di tipo K e V.*/
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename K, typename V>
class Pair{
    private:
    K key;
    V value;
    public:
    Pair(){} // servono per la gestione dinamica della memoria e l'operatore di assegnamento
    Pair(const K& k, const V& v){
        key = k;
        value = v;
    }
    K getKey() const{
        return key;
    }
    V getValue() const{
        return value;
    }
    void setValue(const V& v){
        value = v;
    }
};
template <typename K, typename V>
class Map{
    private:
    Pair<K, V>* container;
    int num_elem;
    int capacity;

    void enlarge(){
        capacity *= 2;
        Pair<K, V>* supp = new Pair<K, V>[capacity];
        for(int i = 0; i < num_elem; i++)
            supp[i] = container[i];
        delete[] container;
        container = supp;
    }
    public:
    Map(){
        num_elem = 0;
        capacity = 10;
        container = new Pair<K, V>[capacity];
    }
    Map(const Map<K, V> &other){
        capacity = other.capacity;
        num_elem = other.num_elem;
        container = new Pair<K, V>[capacity];
        for(int i = 0; i < num_elem; i++)
            container[i] = other.container[i];
    }
    ~Map(){
        delete[] container;
    }
    Map<K, V>& operator=(const Map<K, V> &other){
        if(this != &other){
            delete[] container;
            capacity = other.capacity;
            num_elem = other.num_elem;
            container = new Pair<K, V>[capacity];
            for(int i = 0; i < num_elem; i++)
                container[i] = other.container[i];
        }
        return *this;
    }
    void insert(const K& key, const V& value){
        for(int i = 0; i < num_elem; i++){
            if(container[i].getKey() == key){
                container[i].setValue(value);
                return;
            }
        }
        if(num_elem == capacity)
            enlarge();
        container[num_elem++] = Pair<K, V>(key, value);
    }
    bool contains(const K& key) const{
        for(int i = 0; i < num_elem; i++)
            if(container[i].getKey() == key)
                return true;
        return false;
    }
    bool isEmpty() const{
        return num_elem == 0;
    }
    void remove(const K& key){
        if(!contains(key))
            throw invalid_argument("Non esiste");
        Pair<K,V>* supp = new Pair<K,V>[capacity];
        int j = 0;
        for(int i = 0; i < num_elem; i++)
            if(container[i].getKey() != key)
                supp[j++] = container[i];
        num_elem = j;
        delete[] container;
        container = supp;
    }
    int size() const{
        return num_elem;
    }
    // Metodi di supporto per permettere la stampa esterna rispettando l'information hiding
    K getKeyAt(int index) const {
        if (index < 0 || index >= num_elem)
            throw out_of_range("Indice fuori range");
        return container[index].getKey();
    }
    V getValueAt(int index) const {
        if (index < 0 || index >= num_elem)
            throw out_of_range("Indice fuori range");
        return container[index].getValue();
    }
};

// Sovraccarico di << per stampare la mappa in modo leggibile
template <typename K, typename V>
ostream& operator<<(ostream& out, const Map<K, V>& m) {
    out << "{";
    for(int i = 0; i < m.size(); i++) {
        out << m.getKeyAt(i) << ": " << m.getValueAt(i);
        if(i < m.size() - 1) out << ", ";
    }
    out << "}";
    return out;
}

// --- MAIN DI VERIFICA ---
int main() {
    try {
        cout << "--- TEST 1: Creazione e verifica mappa vuota ---" << endl;
        Map<string, int> rubrica;
        cout << "La mappa e' vuota? " << (rubrica.isEmpty() ? "SI" : "NO") << endl;
        cout << "Dimensione iniziale: " << rubrica.size() << endl;

        cout << "\n--- TEST 2: Inserimento di nuove coppie ---" << endl;
        rubrica.insert("Alice", 12345);
        rubrica.insert("Bob", 67890);
        rubrica.insert("Charlie", 55555);
        cout << "Contenuto rubrica: " << rubrica << endl;
        cout << "Nuova dimensione: " << rubrica.size() << endl;

        cout << "\n--- TEST 3: Aggiornamento di una chiave esistente ---" << endl;
        cout << "Aggiorno il valore di 'Bob'..." << endl;
        rubrica.insert("Bob", 99999); // Deve sovrascrivere 67890
        cout << "Contenuto rubrica aggiornato: " << rubrica << endl;
        cout << "La dimensione e' rimasta invariata? " << rubrica.size() << " (Atteso: 3)" << endl;

        cout << "\n--- TEST 4: Verifica presenza chiavi (contains) ---" << endl;
        cout << "Contiene 'Alice'? " << (rubrica.contains("Alice") ? "SI" : "NO") << endl;
        cout << "Contiene 'Zorro'? " << (rubrica.contains("Zorro") ? "SI" : "NO") << endl;

        cout << "\n--- TEST 5: Rimozione di un elemento (remove) ---" << endl;
        cout << "Rimuovo 'Bob'..." << endl;
        rubrica.remove("Bob");
        cout << "Contenuto dopo rimozione: " << rubrica << endl;
        cout << "Dimensione finale: " << rubrica.size() << endl;

        cout << "\n--- TEST 6: Gestione delle Eccezioni ---" << endl;
        cout << "Tento di rimuovere una chiave che non esiste ('Zorro')..." << endl;
        rubrica.remove("Zorro"); // Lancia eccezione

    } catch (const invalid_argument& e) {
        cout << ">>> Eccezione intercettata con successo: " << e.what() << endl;
    } catch (const exception& e) {
        cout << "Errore imprevisto: " << e.what() << endl;
    }

    return 0;
}