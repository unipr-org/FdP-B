/*Deﬁnire una classe templatica MultiSet<T> che realizza il tipo di dato astratto multi-insieme di elementi 
di tipo T (informalmente, un multi-insieme `e un insieme che ammette elementi ripetuti). 
La classe deve deﬁnire:
I un costruttore senza argomenti che crea un multi-insieme vuoto
I un metodo add che aggiunge un elemento preso come argomento al multi-insieme
I un metodo remove che, preso come argomento elem, rimuove dal multi-insieme tutti gli elementi uguali ad elem. 
  Se il multi-insieme `e vuoto, il metodo deve lanciare un’eccezione
I un metodo isEmpty che controlla se il multi-insieme `e vuoto
I un metodo cardinality che, preso come argomento elem, ritorna il numero di occorrenze di elem nel multi-insieme
Inoltre, si sovraccarichi l’operatore << in modo tale che stampi gli elementi del multi-insieme su uno stream di 
output fout nel formato [e1, e2, . . . , en]. 
Non `e consentito utilizzare classi della STL. Se necessario, rideﬁnire gli opportuni metodi, costruttori e/o
operatori. Speciﬁcare opportunamente eventuali metodi e parametri costanti. Massimizzare incapsulamento e 
information hiding.*/
#include <iostream>
using namespace std;

template <typename T>
class MultiSet{
    private:
    T* container;
    int num_elem;
    int capacity;

    void enlarge(){
        capacity *=2;
        T* supp = new T[capacity];
        for(int i = 0; i < num_elem; i++)
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
    // costruttore di copia
    MultiSet(const MultiSet<T>& other){
        capacity = other.capacity;
        num_elem = other.num_elem;
        container = new T[capacity];
        for(int i = 0; i < num_elem; i++)
            container[i] = other.container[i];
    }
    // distruttore
    ~MultiSet(){
        delete[] container;
    }
    //costruttore di assegnamento
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
    const T& operator[](int index) const{
        if(index >= num_elem)
            throw out_of_range("Elemento non esiste");
        return container[index];
    }
    int getSize() const{
        return num_elem;
    }
    int getCapacity() const{
        return capacity;
    }
};
template <typename T>
ostream& operator<<(ostream& fout, const MultiSet<T>& ms){
    fout << "[";
    for(int i = 0; i < ms.getSize(); i++){
        fout << ms[i];
        if(i < ms.getSize() - 1)
            fout << ", ";
    }
    fout << "]";
    return fout;
}




int main() {
    try {
        cout << "--- TEST 1: Creazione e Inserimenti (add) ---" << endl;
        MultiSet<int> ms;
        
        cout << "Il MultiSet e' vuoto? " << (ms.isEmpty() ? "SI" : "NO") << endl;

        // Inseriamo elementi, inclusi i duplicati (ammessi nel MultiSet)
        ms.add(10);
        ms.add(20);
        ms.add(10);
        ms.add(30);
        ms.add(10);
        ms.add(20);

        // Verifica della stampa (Formato atteso: [10, 20, 10, 30, 10, 20])
        cout << "MultiSet corrente: " << ms << endl;
        cout << "Numero totale di elementi (Size): " << ms.getSize() << endl;
        cout << "Il MultiSet e' vuoto? " << (ms.isEmpty() ? "SI" : "NO") << endl;

        cout << "\n--- TEST 2: Conteggio Occorrenze (cardinality) ---" << endl;
        cout << "Occorrenze di 10: " << ms.cardinality(10) << " (Atteso: 3)" << endl;
        cout << "Occorrenze di 20: " << ms.cardinality(20) << " (Atteso: 2)" << endl;
        cout << "Occorrenze di 99 (non presente): " << ms.cardinality(99) << " (Atteso: 0)" << endl;

        cout << "\n--- TEST 3: Rimozione (remove) ---" << endl;
        cout << "Rimozoione di TUTTE le occorrenze di 10..." << endl;
        ms.remove(10);
        cout << "MultiSet dopo remove(10): " << ms << " (Atteso: [20, 30, 20])" << endl;
        cout << "Nuova cardinality di 10: " << ms.cardinality(10) << " (Atteso: 0)" << endl;

        cout << "\n--- TEST 4: Gestione Memoria (Copia e Assegnamento) ---" << endl;
        MultiSet<int> msCopia(ms); // Costruttore di copia
        msCopia.add(50);
        cout << "Originale ms: " << ms << endl;
        cout << "Copia msCopia: " << msCopia << " (Atteso: [20, 30, 20, 50])" << endl;

        MultiSet<int> msAssegnato;
        msAssegnato = ms; // Operatore di assegnamento
        msAssegnato.remove(20);
        cout << "Originale ms: " << ms << endl;
        cout << "Assegnato msAssegnato: " << msAssegnato << " (Atteso: [30])" << endl;

        cout << "\n--- TEST 5: Controllo Eccezione su MultiSet Vuoto ---" << endl;
        MultiSet<string> msStringhe;
        cout << "Creato msStringhe vuoto: " << msStringhe << endl;
        
        // Questo blocco DEVE catturare l'errore poiché msStringhe non ha elementi
        try {
            cout << "Tentativo di rimozione da msStringhe vuoto..." << endl;
            msStringhe.remove("C++");
        } catch (const runtime_error& e) {
            cout << ">>> Eccezione intercettata con successo: " << e.what() << endl;
        }

    } catch (const exception& e) {
        cerr << "ERRORE IMPREVISTO NEL MAIN: " << e.what() << endl;
    }

    return 0;
}