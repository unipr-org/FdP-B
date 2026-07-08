/* Deﬁnire una classe templatica Map<K, V> che realizza il tipo di dato astratto mappa con
chiavi di tipo K e valori di tipo V. La classe deve deﬁnire:
I un costruttore senza argomenti che crea una mappa vuota;
I un metodo void insert(const K& key, const V& value) che inserisce una coppia chiave-valore nella mappa; se
la mappa contiene gi`a una coppia con chiave key, il valore corrispondente dovr`a essere aggiornato con value;
I un metodo bool contains(const K& key) const che veriﬁca se una chiave `e presente nella mappa;
I un metodo bool isEmpty() const che controlla se la mappa `e vuota;
I un metodo void remove(const K& key) che rimuove una coppia chiave-valore dalla mappa. Il metodo deve lanciare
un’eccezione se la chiave non `e presente;
I un metodo int size() const che ritorna il numero di coppie chiave-valore nella mappa
Non `e consentito utilizzare le classi relative alle mappe della STL. Se necessario, rideﬁnire gli opportuni metodi, costrut-
tori e/o operatori. Speciﬁcare opportunamente eventuali metodi e parametri costanti. Massimizzare incapsulamento e
information hiding. Hint: deﬁnire una classe templatica Pair<K, V> che modella una coppia di valori di tipo K e V.*/
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename K, typename V>
class Pair{
    private:
    K key;
    V value;
    public:
    Pair(){}
    Pair(const K& k, const V& v){
        key = k;
        value = v;
    }
    const K& getKey() const{
        return key;
    }
    const V& getValue() const{
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
    Map(const Map<K, V>& other){
        capacity = other.capacity;
        num_elem = other.num_elem;
        container = new Pair<K, V>[capacity];
        for(int i = 0; i < num_elem; i++)
            container[i] = other.container[i];
    }
    Map<K, V>& operator=(const Map<K, V>& other){
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
    ~Map(){
        delete[] container;
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
            throw runtime_error("Chiave non presente");
        Pair<K, V>* supp = new Pair<K, V>[capacity];
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
};