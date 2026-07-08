#include <iostream>

using namespace std;

class Data{
	protected:
		int giorno;
		int mese;
		int anno;
		
	public:
		Data(int g, int m, int a){
			if(g<1 || g>31 || m<1 || m>12 || a<0)
				throw string("Data non valida");
			giorno = g;
			mese = m;
			anno = a;
		}
		bool operator<(Data& other){
			if(this->anno < other->anno)
				return true;
			if(this->anno > other->anno)
				return false;
			
			if(this->mese < other->mese)
					return true;
			
			if(this->mese > other->mese)
				return false;
			
			if(this->giorno < other->giorno)
				return true;
			
			return false;
		}
		bool operator==(Data& other){
			return this->anno == other->anno && this->mese == other->mese && this->anno == other->anno;
		}
		
		void stampa(ostream& dest) const{
			dest<<"\n"<<giorno<<"/"<<mese<<"/"<<anno<<"\n";
		}
		
};

class DataConOrario : public Data{
	private:
		int ora;
		int minuti;
	
	public:
		DataConOrario(int g, int m, int a, int ora, int minuti):Data(g, m, a){
			if(ora<0 || ora>23 || minuti<0 || minuti>59)
				throw string("Orario non valido");
			this->ora = ora;
			this->minuti = minuti;
		}
		bool operator<(DataConOrario& other){
			if()
		}
		void stampa(ostream& dest){
			Data->stampa(dest);
			dest<<ora<<":"<<minuti<<"\n";
		}
};
