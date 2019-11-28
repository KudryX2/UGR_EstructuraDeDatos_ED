#include "Termino.h"

#include <iostream>

using namespace std;

/*
	Constructores
*/
Termino::Termino(){
	palabra = "vacio";
}

Termino::Termino(string p, string definicion){
	palabra = p;
	definiciones = new Array<string>(0);
	definiciones->add(definicion);
}

Termino::Termino(const Termino& termino){
	palabra = termino.getPalabra();

	definiciones = new Array<string>(*termino.getDefiniciones());
}

Termino::~Termino(){

}

/*
	Getters
*/	
string Termino::getPalabra() const{
	return palabra;
}

Array<string>* Termino::getDefiniciones() const{
	return definiciones;
}

int Termino::getNumeroDefiniciones(){
	if(definiciones != NULL)
		return definiciones->getSize();
	return 0;
}


/*
	Setters
*/
void Termino::setPalabra(string p){
	palabra = p;
}

void Termino::addDefinicion(string definicion){
//	cout << "Habia "<< getNumeroDefiniciones();	
	
	definiciones->add(definicion);

//	cout << " y ahora hay " << getNumeroDefiniciones() << endl;
}

bool Termino::operator ==(const Termino& t){
	if(t.getPalabra() == palabra){
		return true;
	}else{
		return false;
	}
}

void Termino::print(){
	cout << palabra;
	definiciones->print();
}
