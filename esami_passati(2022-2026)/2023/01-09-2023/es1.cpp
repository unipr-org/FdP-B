/* Definire una classe templatica Set<T> che realizza il tipo di dato astratto insieme di elementi di tipo T.
La classe deve definire:
1 - un costruttore senza argomenti che crea un insieme vuoto
2 - un metodo add che aggiunge un elemento di tipo T all’insieme. Se l’elemento `e gi`a presente, il metodo deve
    lanciare un’eccezione
3 - un metodo contains che verifica se un elemento appartiene all’insieme
4 - un metodo size che ritorna la cardinalit`a dell’insieme
5 - Si sovraccarichi l’operatore - in modo tale che restituisca un nuovo insieme ottenuto dall’intersezione fra
l’insieme su cui `e chiamato il metodo e l’insieme passato come parametro.
6 - Si sovraccarichi l’operatore << in  modo tale che stampi gli elementi dell’insieme su uno stream di output
fout nel formato {e1, e2, . . . , en}.
Non `e consentito utilizzare classi della STL. Se necessario, ridefinire gli opportuni metodi, costruttori e/o
operatori. Specificare opportunamente eventuali metodi e parametri costanti. Massimizzare incapsulamento e
information hiding.*/
#include <iostream>
#include <stdexcept>
#include <string> // Aggiunto esplicitamente per il main

using namespace std;

template <typename T>
class Set {
private:
    T* container;
    int num_elem;
    int capacity;

    void enlarge() {
        capacity = capacity * 2;
        T* supporto = new T[capacity];
        for (int i = 0; i < num_elem; i++)
            supporto[i] = container[i];
        delete[] container;
        container = supporto;
    }

public:
    // Costruttore vuoto
    Set() {
        num_elem = 0;
        capacity = 10;
        container = new T[capacity];
    }
    // Costruttore di copia
    Set(const Set<T>& other) {
        capacity = other.capacity;
        num_elem = other.num_elem;
        container = new T[capacity];
        for (int i = 0; i < num_elem; i++)
            container[i] = other.container[i];
    }
    // Operatore di assegnamento
    Set<T>& operator=(const Set<T>& other) {
        if (this != &other) {
            delete[] container;
            capacity = other.capacity;
            num_elem = other.num_elem;
            container = new T[capacity];
            for (int i = 0; i < other.num_elem; i++)
                container[i] = other.container[i];
        }
        return *this;
    }
    // Distruttore
    ~Set() {
        delete[] container;
    }
    // Metodo add
    void add(const T& elem) {
        for(int i = 0; i < num_elem; i++)
            if(container[i] == elem)
                throw invalid_argument("Errore: elemento gia' presente!!");
        if (num_elem == capacity)
            enlarge();
        container[num_elem++] = elem;
    }
    // Metodo contains
    bool contains(const T& elem) const {
        for (int i = 0; i < num_elem; i++)
            if (container[i] == elem)
                return true;
        return false;
    }
    //  Metodo size
    int size() const {
        return num_elem;
    }
    int getCapacity() const {
        return capacity;
    }
    // 5 - Operatore - (Intersezione)
    Set<T> operator-(const Set<T>& other) const {
        Set<T> result;
        for (int i = 0; i < num_elem; i++)
            if (other.contains(container[i]))
                result.add(container[i]);
        return result;
    }
    // Accesso agli elementi in sola lettura
    const T& operator[](int index) const {
        if (index >= num_elem || index < 0)
            throw out_of_range("Elemento non esiste.");
        return container[index];
    }
};
// Operatore <<
template <typename T>
ostream& operator<<(ostream& fout, const Set<T>& s) {
    fout << "{";
    for (int i = 0; i < s.size(); i++) {
        fout << s[i];
        if (i < s.size() - 1)
            fout << ", ";
    }
    fout << "}";
    return fout;
}

// test
int main() {
    try {
        cout << "--- TEST 1: Funzionalita' Base ---" << endl;
        Set<int> s1;
        s1.add(10);
        s1.add(20);
        s1.add(30);
        cout << "Insieme s1: " << s1 << " (Size: " << s1.size() << ")" << endl;
        cout << "s1 contiene 20? " << (s1.contains(20) ? "SI" : "NO") << endl;
        cout << "s1 contiene 50? " << (s1.contains(50) ? "SI" : "NO") << endl;

        cout << "\n--- TEST 2: Gestione Eccezioni ---" << endl;
        try {
            s1.add(10); // Elemento gia' presente
        } catch (const invalid_argument& e) {
            cout << "Catturata eccezione prevista: " << e.what() << endl;
        }

        cout << "\n--- TEST 3: Intersezione (Operatore -) ---" << endl;
        Set<int> s2;
        s2.add(20);
        s2.add(30);
        s2.add(40);
        cout << "Insieme s2: " << s2 << endl;

        Set<int> sInter = s1 - s2;
        cout << "Intersezione (s1 - s2): " << sInter << " (Atteso: {20, 30})" << endl;

        cout << "\n--- TEST 4: Gestione Memoria (Copia e Assegnamento) ---" << endl;
        Set<int> sCopia(s1);
        sCopia.add(100);
        cout << "s1 originale: " << s1 << endl;
        cout << "sCopia (s1 + 100): " << sCopia << endl;

        Set<int> sAssegn;
        sAssegn = s2;
        sAssegn.add(500);
        cout << "s2 originale: " << s2 << endl;
        cout << "sAssegn (s2 + 500): " << sAssegn << endl;

        cout << "\n--- TEST 5: Tipi diversi (Stringhe) ---" << endl;
        Set<string> sStr;
        sStr.add("C++");
        sStr.add("Java");
        cout << "Insieme stringhe: " << sStr << endl;

    } catch (const exception& e) {
        cerr << "ERRORE INASPETTATO: " << e.what() << endl;
    }

    return 0;
}