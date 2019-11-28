#include <algorithm> 

#include "Diccionario.h"

using namespace std;

Diccionario::Diccionario(){

}

Diccionario::Diccionario(set<string> &terminos){
	this->terminos = set<string>(terminos);
}

vector<string> Diccionario::getPalabrasLongitud(unsigned int longitud){
	vector<string> ret;

	for( Iterator iterator = begin() ; iterator != end() ; ++iterator){	
		if( (*iterator).length() == longitud ){
			ret.push_back( (*iterator) );
		}
	}

	return ret;
}

bool Diccionario::esta(string palabra){
	return terminos.find(palabra) != terminos.end();	
}

int Diccionario::size() const{
	return terminos.size();
}



ostream& operator << (ostream& stream, const Diccionario& dic){

	stream << "Diccionario con: " << dic.size() << " entradas" << endl;
	
	for(Diccionario::Iterator iterator = dic.begin(); iterator != dic.end(); ++iterator){
		stream << (*iterator) << endl;
	}

	return stream;
}

ifstream& operator >> (ifstream& stream, Diccionario& dic){

	string linea;
	set<string> terminos;

	while(getline(stream, linea)){
		terminos.insert(linea);
	}

	dic = Diccionario(terminos);
	stream.close();

	return stream;
}

Diccionario::Iterator Diccionario::begin() const{
	return terminos.begin();
}	

Diccionario::Iterator Diccionario::end() const{
	return terminos.end();
}
