#include <iostream>

#include "Termino.h"

using namespace std;

Termino::Termino(){
	termino.first = "vacio";
}

Termino::Termino(string palabra, string definicion){
	vector<string> def;
	def.push_back(definicion);
	termino = make_pair(palabra, def);
}

Termino::Termino(const Termino &termino){
	this->termino = make_pair(termino.getPalabra(), vector<string>(termino.getDefiniciones()));
}


void Termino::setPalabra(string palabra){
	termino.first = palabra;
}

void Termino::addDefinicion(string definicion){
	termino.second.push_back(definicion);
}

void Termino::addDefiniciones(vector<string> definiciones){
	for(unsigned int i = 0 ; i < definiciones.size() ; ++i ){
		termino.second.push_back(definiciones[i]);	
	}
}


string Termino::getPalabra() const{
	return termino.first;
}

vector<string> Termino::getDefiniciones() const{
	return termino.second;
}

int Termino::getNumeroDefiniciones() const{
	return termino.second.size();
}


ostream& operator << (ostream& stream, const Termino& termino){
	stream << termino.getPalabra() << ":" << endl;
	
	typedef vector<string>::const_iterator const_iterator;

	for(const_iterator iter = termino.begin() ; iter != termino.end() ; iter++){
		stream << " - " << (*iter) << endl;
	}

	return stream;
}

bool operator < (const Termino &termino1, const Termino &termino2){

	int longitud1 = termino1.getPalabra().length();
	int longitud2 = termino2.getPalabra().length();
	int longitud;

	bool resultado = true;

	if(longitud1 > longitud2)
		longitud = longitud2;
	else
		longitud = longitud1;

	for( int i = 0 ; i < longitud ; ++i){
		if(termino1.getPalabra().at(i) != termino2.getPalabra().at(i)){
			if(termino1.getPalabra().at(i) < termino2.getPalabra().at(i)){
				resultado = true;
				i = longitud;
			}else{
				resultado = false;
				i = longitud;
			}
		}

	}

/* * /
	if(termino1.getPalabra().at(0) <= termino2.getPalabra().at(0)){
		return true;
	}else{
		return false;
	}
/* */
	return resultado;
}


Termino::iterator Termino::begin(){
	return termino.second.begin();
}	

Termino::iterator Termino::end(){
	return termino.second.end();
}

Termino::const_iterator Termino::begin() const{
	return termino.second.begin();
}	

Termino::const_iterator Termino::end() const{
	return termino.second.end();
}