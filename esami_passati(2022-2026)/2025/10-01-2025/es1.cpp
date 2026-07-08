/* Esercizio 1 [C++] (15pt). Definire una classe templatica Stack<T> che realizza il tipo di dato astratto pila di elementi
di tipo T (accesso di tipo LIFO: Last In First Out).
La classe deve definire:
▶ un costruttore senza argomenti che crea una pila vuota;
▶ un metodo push che aggiunge un elemento di tipo T alla pila;
▶ un metodo isEmpty che controlla se la pila `e vuota.
▶ un metodo pop che rimuove dalla pila l’ultimo elemento inserito e lo ritorna come risultato. Il metodo deve lanciare un’eccezione se la pila `e vuota.
▶ un metodo size che ritorna il numero di elementi nella pila
Si sovraccarichi l’operatore << in modo tale che stampi gli elementi della pila su uno stream di output fout nel formato
[e1, e2, . . . , en]. Non `e consentito utilizzare classi della STL. Se necessario, ridefinire gli opportuni metodi, costruttori e/o
operatori. Specificare opportunamente eventuali metodi e parametri costanti.*/
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Stack{
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
    Stack(){
        num_elem = 0;
        capacity = 10;
        container = new T[capacity];
    }
    Stack(const Stack<T>& other){
        capacity = other.capacity;
        num_elem = other.num_elem;
        container = new T[capacity];
        for(int i = 0; i < num_elem; i++)
            container[i] = other.container[i];
    }
    Stack<T>& operator=(const Stack<T>& other){
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
    ~Stack(){
        delete[] container;
    }
    void push(const T& elem){
        if(num_elem == capacity)
            enlarge();
        container[num_elem++] = elem;
    }
    bool isEmpty() const{
        return num_elem == 0;
    }
    T pop(){
        if(isEmpty())
            throw invalid_argument("Pila vuota");
        num_elem--;
        return container[num_elem];
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
ostream& operator<<(ostream& fout, const Stack<T>& s){
    fout << "[";
    for(int i = 0; i < s.size(); i++){
        fout << s[i];
        if(i < s.size() - 1)
            fout << ", ";
    }
    fout << "]";
    return fout;
}

int main() {
    try {
        cout << "=== TEST 1: Creazione e stato iniziale ===" << endl;
        Stack<string> pila;
        cout << "La pila e' vuota? " << (pila.isEmpty() ? "SI" : "NO") << endl;
        cout << "Dimensione iniziale: " << pila.size() << " (Atteso: 0)" << endl;

        cout << "\n=== TEST 2: Inserimenti (push) ===" << endl;
        pila.push("Documento_1");
        pila.push("Documento_2");
        pila.push("Documento_3");
        cout << "Contenuto della pila: " << pila << endl;
        cout << "Dimensione attuale: " << pila.size() << " (Atteso: 3)" << endl;
        cout << "La pila e' ancora vuota? " << (pila.isEmpty() ? "SI" : "NO") << endl;

        cout << "\n=== TEST 3: Rimozione LIFO (pop) con recupero valore ===" << endl;
        // Il pop deve rimuovere e ritornare l'ultimo inserito ("Documento_3")
        string rimosso1 = pila.pop();
        cout << "Primo pop effettuato! Elemento rimosso: " << rimosso1 << " (Atteso: Documento_3)" << endl;
        cout << "Pila dopo il primo pop: " << pila << endl;

        // Facciamo un altro pop ("Documento_2")
        cout << "Secondo pop effettuato! Elemento rimosso: " << pila.pop() << " (Atteso: Documento_2)" << endl;
        cout << "Pila dopo il secondo pop: " << pila << endl;
        cout << "Dimensione attuale: " << pila.size() << " (Atteso: 1)" << endl;

        cout << "\n=== TEST 4: Svuotamento della pila ===" << endl;
        cout << "Rimuovo l'ultimo elemento rimasto: " << pila.pop() << " (Atteso: Documento_1)" << endl;
        cout << "La pila e' vuota adesso? " << (pila.isEmpty() ? "SI" : "NO") << endl;

        cout << "\n=== TEST 5: Verifica delle Eccezioni ===" << endl;
        cout << "Tento di fare un pop intenzionale su una pila ormai vuota..." << endl;
        pila.pop(); // Questa riga deve lanciare l'eccezione invalid_argument

    } catch (const invalid_argument& e) {
        cout << ">>> Eccezione intercettata correttamente: " << e.what() << endl;
    } catch (const exception& e) {
        cout << ">>> Eccezione generica intercettata: " << e.what() << endl;
    }

    return 0;
}