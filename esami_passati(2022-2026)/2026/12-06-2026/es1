#include <iostream>

using namespace std;


template<class T>
class Bag {
private:
    int num_elem;
    int capacita;
    T* arr;
    void resize() {
        capacita *= 2;
        T* b = new T[capacita];
        for (int i = 0;i < num_elem;i++) {
            b[i] = arr[i];
        }
        delete [] arr;
        arr = b;
    }
    int findPosElem(const T& elem) {
        for (int i = 0;i < num_elem;i++) {
            if (arr[i] == elem)
                return i;
        }
        return -1;
    }
public:
    Bag() {
        num_elem = 0;
        capacita = 1;
        arr = new T[capacita];
    }
    ~Bag() {
        delete [] arr;
    }
    Bag(const Bag& other) {
        capacita = other.capacita;
        num_elem = other.num_elem;
        arr = new T[capacita];
        for (int i = 0;i < num_elem;i++) {
            arr[i] = other.arr[i];
        }
    }
    Bag& operator=(const Bag& other) {
        if (this != &other) {
            delete [] arr;
            capacita = other.capacita;
            num_elem = other.num_elem;
            arr = new T[capacita];
            for (int i = 0;i < num_elem;i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }


    void add(const T& elem) {
        if (num_elem == capacita)
            resize();
        arr[num_elem++] = elem;
    }
    int count(const T& elem) const {
        int cont=0;
        for (int i = 0;i < num_elem;i++) {
            if (arr[i] == elem)
                cont++;
        }
        return cont;
    }
    bool contains(const T& elem) const {
        for (int i = 0;i < num_elem;i++) {
            if (arr[i] == elem)
                return true;
        }
        return false;
    }
    int size() const {
        return num_elem;
    }
    void removeOne(const T& elem) {
        int pos = findPosElem(elem);
        if (pos == -1) {
            throw invalid_argument("non è presente");
        }
        arr[pos] = arr[num_elem -1];
        num_elem--;
    }

    Bag<T> operator+(const Bag& other) {
        Bag<T> b;
        for (int i = 0;i < num_elem;i++) {
            b.add(arr[i]);
        }
        for (int i = 0;i < other.num_elem;i++) {
            b.add(other.arr[i]);
        }
        return b;
    }
    const T& getElem(int i) const {
        return arr[i];
    }
};
template<class T>
ostream& operator<<(ostream& fout,const Bag<T>& b) {
    fout<<"{";
    for (int i = 0;i < b.size();i++) {
        fout<<b.getElem(i);
        if (i < b.size() - 1)
            fout<<", ";
    }
    fout << "}";
    return fout;
}
