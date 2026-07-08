#include <iostream>
#include <stdexcept>

using namespace std;

class Data{
	
	private:
		
		int giorno;
		int mese;
		int anno;
	
	public:
		
		Data(int g, int m, int a){
			if(g<1 || g>31 || m<1 || m>12 ||a<0)
				throw invalid_argument("Data non valida");
			this->giorno = g;
			this->mese = m;
			this->anno = a;
		}
		
		
		
		
};


int main(){
	
}
