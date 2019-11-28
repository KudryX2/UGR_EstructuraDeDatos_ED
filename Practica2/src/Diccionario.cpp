#include "Diccionario.h"
#include <iostream>

using namespace std;

/*
	Constructores
*/
Diccionario::Diccionario(){
	nTerminos = 0;
}

Diccionario::Diccionario(const Array<Termino>& t){
	terminos = new Array<Termino>(t);
	nTerminos = t.getSize();
}

Diccionario::Diccionario(const Diccionario& diccionario){
	terminos = new Array<Termino>(*diccionario.getTerminos());
	nTerminos = diccionario.getNumeroTerminos();
}

Diccionario::Diccionario(const Diccionario& diccionario, const char *caracterInicial, const char *caracterFinal){
	int indexIni = -1;
	int indexFin = 0;
	string palabra;
	bool finEncontrado = false;

	for(int i =  0 ; i < diccionario.getTerminos()->getSize() ; ++i){
		palabra = diccionario.getTerminos()->get(i)->getPalabra();

		if(palabra[0] == *caracterInicial && indexIni == -1){
			indexIni = i;
		} 

		if(palabra.at(0) == *caracterFinal && !finEncontrado){
			finEncontrado = true;	
		}

		if(finEncontrado){
			indexFin = i-1;
			finEncontrado = false;
		}

	}

	terminos = new Array<Termino>(*diccionario.getTerminos(), indexIni, indexFin);
	nTerminos = diccionario.getNumeroTerminos();
}

Diccionario::Diccionario(const Diccionario& diccionario, string palabraClave){
	
	terminos = new Array<Termino>(0);
	Termino *termino;

	for(int i =  0 ; i < diccionario.getTerminos()->getSize() ; ++i){
		
		for(int j = 0 ; j < diccionario.getTerminos()->get(i)->getDefiniciones()->getSize() ; ++j){

			if(diccionario.getTerminos()->get(i)->getDefiniciones()->get(j)->find(palabraClave) != std::string::npos ){
				termino = new Termino(diccionario.getTerminos()->get(i)->getPalabra(), *diccionario.getTerminos()->get(i)->getDefiniciones()->get(j) );
				addTermino(termino);
				nTerminos++;
			}

		}
		
	}

}

Diccionario::~Diccionario(){

}


/*
	Getters
*/
Array<Termino>* Diccionario::getTerminos() const{
	return terminos;
}

Termino* Diccionario::getTermino(int index){
	return terminos->get(index);
}


int Diccionario::getNumeroTerminos() const{
	return nTerminos;
}

/*
	Modificaciones
*/
void Diccionario::addTermino(Termino *termino){

	bool encontrada = false;
	for(int i = 0 ; i < terminos->getSize() ; ++i){
		if(terminos->get(i) == termino){
			terminos->get(i)->addDefinicion(*termino->getDefiniciones()->get(0)); //Un termino nuevo suponemos que solo tiene una definicion
			encontrada = true;
			i = terminos->getSize();
		}
	}

	if(!encontrada){
		terminos->add(*termino);	
		nTerminos++;
	}

}

void Diccionario::addDefinicion(int index, string definicion){
	terminos->get(index)->addDefinicion(definicion);
}

void Diccionario::eraseTermino(string palabra){

	for(int i = 0 ; i < terminos->getSize() ; ++i){
		
		if(terminos->get(i)->getPalabra() == palabra){
			terminos->erasePosicion(i);
			nTerminos--;
		}

	}

}

/*
	Sobrecarga de operadores
*/
void operator << (string fichero, Diccionario& dic){

	ofstream outfile("./datos/" + fichero);

	for(int i = 0 ; i < dic.getTerminos()->getSize() ; ++i){
		outfile << dic.getTermino(i)->getPalabra() << ";";
		for(int j = 0 ; j < dic.getTermino(i)->getDefiniciones()->getSize() ; ++j){
			outfile << *(dic.getTermino(i)->getDefiniciones()->get(j)) << " ";
		}
		outfile << endl;
	}

	outfile.close();

}

ifstream& operator >> (ifstream& stream, Diccionario& dic){

	string linea;

	string palabra;
	string definicion;

	if(stream.is_open()){

		// Contamos el tamaño del fichero
		int tam = 0;
		while(getline(stream, linea)){
			tam++;
		}

		// Volvemos al principio del fichero
		stream.clear();
		stream.seekg(0, ios::beg);

		// Creamos el array de tamaño necesario
		Array<Termino> term = Array<Termino>(0);

		// Recorremos el fichero anotando los terminos
		cout << "\nLeyendo de fichero" << endl;

		int lineas = 0;

		do{
			getline(stream, linea);

			palabra = linea.substr(0, linea.find(';'));

			if(!palabra.empty()){

				definicion = linea.substr(linea.find(';')+1);

				bool encontrada = false;
				for(int i = 0 ; i < term.getSize() ; ++i){

					if(term.get(i)->getPalabra() == palabra){
						term.get(i)->addDefinicion(definicion);
						encontrada = true;
						i = term.getSize();
					}

				}

				if(!encontrada){
					term.add(Termino(palabra, definicion));	
				}

				lineas++;	
			}

		}while(!linea.empty());

		cout << "Se han leido " << lineas << " lineas y se han almacenado " << term.getSize() << " terminos" << endl;
		dic = Diccionario(term);

		stream.close();

	}else{
		cout << "\nNo se ha podido abrir el archivo" << endl;
	}

	return stream;
}

/*
	Mas operaciones
*/
Termino* Diccionario::filtrado(char ini, char fin){
	return NULL;
}

string* Diccionario::filtrado(string palabra){
	return NULL;
}
	
void Diccionario::recuento(){

	int maximo = 0;
	int acumulada = 0;
	int nDef;

	for(int i = 0 ; i < terminos->getSize() ; ++i){
		nDef = terminos->get(i)->getNumeroDefiniciones();
		if(nDef > maximo){
			maximo = nDef;
		}
		acumulada+=nDef;
	}

	cout << "El diccionario tiene " << terminos->getSize() << " palabras" << endl;
	cout << "El maximo de definiciones por palabra es " << maximo << " y la media es " << (float)acumulada/terminos->getSize() << endl;
}
	
void Diccionario::print(){
	cout << "\nHay " << terminos->getSize() << " palabras" << endl;
	for(int i = 0 ; i < terminos->getSize() ; ++i){
		terminos->get(i)->print();
	}

}

void Diccionario::printDefiniciones(string palabra){
	for(int i = 0 ; i < terminos->getSize() ; ++i){
		if(terminos->get(i)->getPalabra() == palabra){
			terminos->get(i)->getDefiniciones()->print();
			i = terminos->getSize();
		}
	}
}
