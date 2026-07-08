#include <iostream>
using namespace std;

class Studente{
	private:
		string nome;
		string cognome;
		string matricola;

	public:
		Studente(){
			
		}
		Studente(string nome, string cognome, string matricola){
			this->nome = nome;
			this->cognome = cognome;
			this->matricola = matricola;
		}
		void operator=(const Studente& s){
			this->nome = s.nome;
			this->cognome = s.cognome;
			this->matricola = s.matricola;
		}
		bool operator==(const Studente& other) const{
			return this->matricola == other.matricola;
		}

		ostream& stampa(ostream& dest) const{
			dest<<this->nome + " " + this->cognome + " " + this->matricola;
			return dest;
		}
		int hashCode() const{
			return matricola.length() * 31;
		}
		
};

class Verbalizzazione{
	private:
		
		Studente studente;
		int esito;
	
	public:
		Verbalizzazione(){
			
		}
		Verbalizzazione(const Studente& s, int esito){
			this->studente = s;
			if(esito < 0 || esito > 30)
				throw string("Esito non accettato");
			this->esito =  esito;
		}
		
		Studente getStudente() const{
			return this->studente;
		}
		
		int getEsito() const{
			return this->esito;
		}
		
		bool operator==(const Verbalizzazione& v) const{
			return (this->studente == v.studente) && (this->esito == v.esito);
		}
		void setStudente(const Studente& s){
			this->studente = s;
		}
		void setEsito(int e){
			this->esito = e;
		}
		
		int hasCode() const{
			return studente.hashCode() + esito;
		}
		
		ostream& stampa(ostream& dest) const{
			dest<<"\n"<<esito<<" ";
			return studente.stampa(dest);
		}
		
};

class Esame{
	
	private:
		Studente* iscritti;
		Verbalizzazione* verbalizzati;
		int cursorI;
		int cursorV;
		int dimI;
		int dimV;
		
		void expandsIscritti(){
			dimI += 10;
			Studente* tmp = new Studente[dimI];
			for(int i = 0; i < cursorI; i++)
				tmp[i] = iscritti[i];
			delete[] iscritti;
			iscritti = tmp;
		}
		
		void expandsVerbalizzati(){
			dimV += 10;
			Studente* tmp = new Studente[dimV];
			for(int i = 0; i < cursorV; i++)
				tmp[i] = iscritti[i];
			delete[] iscritti;
			iscritti = tmp;
		}
		bool containsIscritti(const Studente& s)const{
			for(int i = 0; i < cursorI; i++)
				if(iscritti[i] == s)
					return true;
			return false;
		}
		
		bool containsVerbalizzati(const Studente& s)const{
			for(int i = 0; i < cursorV; i++)
				if(verbalizzati[i].getStudente() == s)
					return true;
			return false;
		}
		
	public:
		Esame(){
			dimI = 10;
			dimV = 10;
			iscritti = new Studente[dimI];
			verbalizzati = new Verbalizzazione[dimV];
			cursorI = 0;
			cursorV = 0;
		}
		~Esame(){
			delete [] iscritti;
			delete [] verbalizzati;
		}
		
		void iscrivi(const Studente& s){
			if(cursorI < dimI){
				if(containsIscritti(s))
					throw string("Studente gia' iscritto");
				iscritti[cursorI] = s;
				cursorI++;
			}else{
				expandsIscritti();
				iscrivi(s);
			}
		}
		
		void verbalizza(const Studente& s, int v){
			if(cursorV < dimV){
				if(!containsIscritti(s))
					throw string("Studente non iscritto");
				if(containsVerbalizzati(s))
					throw string("Studente gia' verbalizzato");
					
				verbalizzati[cursorV].setEsito(v);
				verbalizzati[cursorV].setStudente(s);
				cursorV++;
			}else{
				expandsVerbalizzati();
				verbalizza(s, v);
			}
			
		}
		void stampaIscritti(ostream& dest){
			for(int i = 0; i < cursorI; i++)
				dest<<iscritti[i].stampa(dest)<<"";
		}
		void stampaVerbalizzati(ostream& dest){
			for(int i = 0; i < cursorI; i++)
				dest<<verbalizzati[i].stampa(dest)<<"";
		}
};



ostream& operator<<(ostream& dest, const Studente s){
	return s.stampa(dest);
}


int main(){
	Studente s1("Simone", "Colli", "8888888");
	cout<<s1<<"\n";
	Studente s2("Simone", "Colli", "6666666");
	cout<<s2<<"\n";
	cout<<(s1==s2)<<"\n";
	Studente s3("Chiara", "Angelini", "8888888");
	cout<<s3<<"\n";
	cout<<(s1==s3)<<"\n";
	
	Esame matematica;
	try{
		matematica.iscrivi(s1);
	}catch(string& e){
		cout<<e;
	}
	
	matematica.stampaIscritti(cout);

}
