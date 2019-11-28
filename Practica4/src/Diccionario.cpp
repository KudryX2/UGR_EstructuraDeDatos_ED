#include <algorithm> 

#include "Diccionario.h"

using namespace std;

Diccionario::Diccionario(){

}

Diccionario::Diccionario(set<Termino> &terminos){
	this->terminos = set<Termino>(terminos);
}

Diccionario::Diccionario(const Diccionario &diccionario){
	terminos = set<Termino>(diccionario.getTerminos());
}

Diccionario::Diccionario(const Diccionario &diccionario, char caracter_inicio, char caracter_fin){
	const_iterator iterator;
	bool copiar = false;
	caracter_fin = static_cast<char>(caracter_fin+1);

	for(iterator = diccionario.begin() ; iterator != diccionario.end() ; iterator++){

		if(!copiar && (*iterator).getPalabra().at(0) == caracter_inicio){
			copiar = true;
		}

		if(copiar && (*iterator).getPalabra().at(0) == caracter_fin){
			copiar = false;
		}

		if(copiar){
			terminos.insert((*iterator));
		}

	}
	
}

Diccionario::Diccionario(const Diccionario &diccionario, string palabraClave){
	const_iterator iterator;
	vector<string> definiciones;

	for(iterator = diccionario.begin() ; iterator != diccionario.end() ; iterator++){

		definiciones = (*iterator).getDefiniciones();

		for(unsigned int i = 0 ; i < (*iterator).getDefiniciones().size() ; i++){

			if( definiciones[i].find(palabraClave) != std::string::npos ){
				terminos.insert( (*iterator) );
			}

		}

	}


}

vector<string> Diccionario::getDefiniciones(string palabra){
	return getTermino(palabra).getDefiniciones();
}

set<Termino> Diccionario::getTerminos() const{
	return terminos;
}

Termino Diccionario::getTermino(string palabra) const{
	typedef set<Termino>::const_iterator iterator;

	Termino termino;

	bool encontrada = false;
	for(iterator iter = terminos.begin() ; iter != terminos.end() && !encontrada ; iter++){

		if((*iter).getPalabra() == palabra){
			encontrada = true;
			termino = (*iter);
		}
	}

	return termino;
}

int Diccionario::getNumeroTerminos(){
	return terminos.size();
}


void Diccionario::addTermino(Termino termino){
	terminos.insert(termino);
}

void Diccionario::eliminarTermino(string palabra){
	
	iterator iteratorEliminar;

	for( iterator iterator = terminos.begin() ; iterator != terminos.end() ; ++iterator){
		
		if( (*iterator).getPalabra() == palabra ){
			
			iteratorEliminar = iterator;
			iterator = terminos.end();
		}

	}

	terminos.erase(iteratorEliminar);
}


void Diccionario::recuento(){
	int maximo = 0;
	int nDef;
	int definicionesTotal = 0;

	for(const_iterator iter = terminos.begin() ; iter != terminos.end() ; iter++){
		nDef = (*iter).getNumeroDefiniciones();
		definicionesTotal += nDef;
		if(nDef > maximo){
			maximo = nDef;
		}
	}

	cout << "El diccionario tiene " << terminos.size() << " palabras y " << definicionesTotal << " definiciones " << endl;
	cout << "El maximo de definiciones por palabra es " << maximo << " y la media es " << (float)definicionesTotal/terminos.size() << endl;
}


void operator << (string fichero, const Diccionario& dic){
	
	ofstream outfile("./datos/" + fichero);

	typedef set<Termino>::const_iterator const_iterator;

	for(const_iterator iterator = dic.begin() ; iterator != dic.end() ; ++iterator){
		outfile << (*iterator).getPalabra() << ";";
		for(unsigned int j = 0 ; j < (*iterator).getDefiniciones().size() ; ++j){
			outfile << (*iterator).getDefiniciones()[j] << " ";
		}
		outfile << endl;
	}

	outfile.close();

}

ostream& operator << (ostream& stream, const Diccionario& dic){

	stream << "Diccionario con: " << dic.getTerminos().size() << " entradas" << endl;
	typedef set<Termino>::const_iterator const_iterator;
	for(const_iterator it = dic.begin(); it != dic.end(); it++){
		stream << (*it) << endl;
	}

	return stream;
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

		// Variables
		vector<Termino> palabras;
		set<Termino> terminos;
		int lineas = 0;

		bool encontrada;
		Termino termino;
		
		/*
			Apunto los terminos en un vector
		*/
		do{

			getline(stream, linea);

			palabra = linea.substr(0, linea.find(';'));

			if(!palabra.empty()){
				definicion = linea.substr(linea.find(';')+1);

				palabras.push_back(Termino(palabra, definicion) );	
				lineas++;
			}

		}while(!linea.empty());

		/*
			Les damos la vuelta al vector de palabras anotadas
		*/
			reverse(palabras.begin(), palabras.end() );


		/*
			Recorro el vector de las palabras y sus definiciones
			para cada palabra se crea un termino como el primero leido
			se recorre el vector de palabras y las que sean iguales sus definiciones
			se añaden al termino creado.
			Por ultimo el termino creado se añade al contenedor set de terminos. 
		*/
		for(unsigned int i = 0 ; i < palabras.size() ; ++i){

			encontrada = false;

			typedef set<Termino>::const_iterator iterator;
			for(iterator iter = terminos.begin() ; iter != terminos.end() && !encontrada ; iter++){

				if((*iter).getPalabra() == palabras[i].getPalabra()){
					encontrada = true;
				}

			}

			if(!encontrada){

				termino = Termino(palabras[i]);

				for(unsigned int j = i+1 ; j < palabras.size() ; ++j){
					if(palabras[i].getPalabra() == palabras[j].getPalabra()){
						termino.addDefiniciones(palabras[j].getDefiniciones());
					}
				}			

				terminos.insert(termino);

			}

		}

		cout << "Se han leido " << lineas << " lineas y se han almacenado " << terminos.size() << " terminos" << endl;
		dic = Diccionario(terminos);

		stream.close();

	}else{
		cout << "\nNo se ha podido abrir el archivo" << endl;
	}

	return stream;
}


Diccionario::iterator Diccionario::begin(){
	return terminos.begin();
}	

Diccionario::iterator Diccionario::end(){
	return terminos.end();
}

Diccionario::const_iterator Diccionario::begin() const{
	return terminos.begin();
}	

Diccionario::const_iterator Diccionario::end() const{
	return terminos.end();
}
