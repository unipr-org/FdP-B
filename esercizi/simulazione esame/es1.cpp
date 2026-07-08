#include <iostream>
using namespace std;
template <class T>

class Inventory{
	private:
		
		T* mem;
		int cursor;
		int dim;
		
		void expands(){
			dim += 10;
			T* newMem = new T[dim];
			for(int i = 0; i < cursor + 1; i++)
				newMem[i] = mem[i];
			delete[] mem;
			mem = newMem;
		}
		
	public:
		//costruttore
		Inventory(){
			dim = 10;
			mem = new T[dim];
			cursor = 0;
			
		}
		//distruttore
		~Inventory(){
			delete[] mem;
		}
		//costruttore di copia
		Inventory(const Inventory<T>& other){
			
			this->cursor = other -> cursor;
			this->dim = other->dim;
			this->mem = new T[this->dim];
			for(int i = 0; i < this->cursor; i++)
				this->mem[i] = other->mem[i];
		
		}
		
		//operator=
		
		Inventory<T>& operator=(const Inventory<T>& other){
			if(this!=other){
				
				this->~Inventory();
				this->cursor = other->cursor;
				this->dim = other->dim;
				this->mem = new T[this->dim];
				for(int i = 0; i < this->cursor; i++)
					this->mem[i] = other->mem[i];
			}
			return *this;
		}
		
		void add(const T& item){
			if(cursor < dim){
				mem[cursor] = item;
				cursor++;
			}else{
				expands();
				add(item);
			}
		}
		
		int count(const T& item) const{
			int tmp = 0;
			for(int i = 0; i < cursor; i++)
				if(mem[i] == item)
					tmp++;
			return tmp;
		}
		
		T getMostCommon() const{
//			bool check[cursor];
			T most = mem[0];
			int mostNumber = 0;
//			for(int i = 0; i < cursor; i++)
//				check = false;
			
			for(int i = 0; i < cursor; i++){
				int tmp = count(mem[i]);
				if(tmp > mostNumber){
					most = mem[i];
					mostNumber = tmp;
				}
			}
			return most;
		}
};

int main(){
	Inventory <int > inv0 ;
	Inventory <string> inv1 ;
	inv0 . add (1); inv0 . add (2); inv0 .add (1); inv0 .add (3);
	inv1 . add(" hello "); inv1 . add (" hello "); inv1 .add (" ciao "); inv1 .add (" hello ");
	cout << inv0 . count (7) << endl ; // output : 0
	cout << inv0 . count (1) << endl ; // output : 2
	cout << inv1 . count (" ciao ") << endl ; // output : 1
	cout << inv0 . getMostCommon () << endl ; // output : 1
	
	return 0;
}
