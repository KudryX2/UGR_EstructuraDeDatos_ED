#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <set>

using namespace std;

struct Letra{
	char letra;
	int fAbsoluta;
	float fRelativa;

	Letra(char letra){
		this->letra = letra;
		
		fAbsoluta = 0;
	}

	void calcularFrecuencia(int total){
		fRelativa = (float)fAbsoluta/total;
	}

	friend ostream& operator << (ostream& stream, const Letra& letra){
		stream << letra.letra << " " << " " << letra.fAbsoluta << " " << letra.fRelativa <<  endl;
		return stream;
	}

};


int main(int argc, char * argv[]){

	if (argc!=4){
		cout << "Los parametros son:" << endl;
		cout << "1.- El nombre del fichero con el diccionario" << endl;
		cout << "2.- El nombre del fichero con las letras" << endl;
		cout << "3.- El nombre del fichero de salida" << endl;
		return 0;
	}


	/*	
		Leemos las letras y las ordenamos usando un set 
	*/
	ifstream stream(argv[2]);
	if(!stream){
		cout << "\nNo puedo abrir el fichero de las letras" << endl;
		return 0;
	}

	string linea;
	set<char> letras;

	
	getline(stream, linea); // Nos saltamos la primera linea ya que no son datos validos
	while(getline(stream, linea)){
		letras.insert(linea.at(0));
	}
	stream.close();


	/*
		Creamos un vector de letras (struct Letra)
	*/
	vector<Letra> repeticionesLetras;
	for(set<char>::iterator iter = letras.begin() ; iter != letras.end() ; ++iter){
		repeticionesLetras.push_back(Letra((*iter)));
	}


	/*
		Leemos el diccionario y calculamos las repeticiones de las letras
	*/	
	ifstream stream2(argv[1]);
	if(!stream2){
		cout << "\nNo puedo abrir el fichero del diccionario" << endl;
		return 0;
	}

	int totalLetras = 0;

	while(getline(stream2, linea)){
		for(unsigned int i = 0 ; i < linea.length() ; ++i){
			for(unsigned int l = 0 ; l < repeticionesLetras.size() ; ++l){
				if(toupper(linea.at(i)) == repeticionesLetras[l].letra){
					repeticionesLetras[l].fAbsoluta++;
				}
			}
			totalLetras++;
		}
	}
	stream.close();

	/*
		Calculamos la frecuencia relativa
	*/
	for(unsigned int i = 0 ; i < repeticionesLetras.size(); ++i){
		repeticionesLetras[i].calcularFrecuencia(totalLetras);
	}

	/*
		Salida del resultado por pantalla.
	*/
	for(unsigned int i = 0 ; i < repeticionesLetras.size() ; ++i){
		cout << repeticionesLetras[i];
	}

	/*
		Salida del resultado a un fichero
	*/
	ofstream stream3;
	stream3.open(argv[3]);

	for(unsigned int i = 0 ; i < repeticionesLetras.size() ; ++i){
		stream3 << repeticionesLetras[i];
	}
	cout << "\nLa salida anterior se ha guardado en: " << argv[3] << endl;

}