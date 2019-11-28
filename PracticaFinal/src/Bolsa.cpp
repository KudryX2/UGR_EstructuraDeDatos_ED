#include "Bolsa.h"

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

Bolsa::Bolsa(){

}

Bolsa::Bolsa(vector<Letra> letras){
	this->letras = vector<Letra>(letras);
}

vector<Letra> Bolsa::getLetras() const{
	return letras;
}

int Bolsa::getCantidadLetras() const{
	return letras.size();
}


vector<char> Bolsa::escogerAleatorias(int cantidad){
	vector<char> aleatorias;

	srand (time(NULL));

	for(int i = 0 ; i < cantidad ; ++i){
		aleatorias.push_back(letras[rand()%letras.size()].getCaracter());
	}

	return aleatorias;
}

int Bolsa::calcularPuntuacion(string palabra){

	int puntuacion = 0;
	bool encontrada;

	for(unsigned int i = 0 ; i < palabra.length() ; ++i){

		encontrada = false;

		for(unsigned int j = 0 ; j < letras.size() && !encontrada ; ++j){

			if( toupper(palabra.at(i)) == letras[j].getCaracter() ){
				encontrada = true;
				puntuacion += letras[j].getPuntuacion();
			}

		}
	}

	return puntuacion;

}


ostream& operator << (ostream& stream, const Bolsa& bolsa){
	
	vector<Letra> letras = bolsa.getLetras();

	for(int i = 0 ; i < bolsa.getCantidadLetras() ; ++i){
		stream << "Letra: " << letras[i].getCaracter() << "  Cantidad:" << letras[i].getCantidad() << "  Puntos: " << letras[i].getPuntuacion() << endl;
	}

	return stream;
}


ifstream& operator >> (ifstream& stream, Bolsa& bolsa){

	string linea;
	vector<Letra> letras;
	
	cout << "Leemos la bolsa de letras y la almacenamos" << endl;

	char letra;
	int cantidad;
	int puntos;

	getline(stream, linea); // Nos saltamos la primera linea ya que no son datos validos

	string cant;
	string punt;
	bool cantidadEncontrada;

	while(getline(stream, linea)){
		
		letra = linea.at(0);	 

		
		cantidadEncontrada = false;

		for(unsigned int i = 1 ; i < linea.length() ; ++i){
		
			cant = "  ";
			punt = "  ";

			if(linea.at(i) != '\t'){

				if(!cantidadEncontrada){
					cant.at(0) = linea.at(i);
					if(linea.at(i+1) != '\t'){
						cant.at(1) = linea.at(i+1);
						i++;
					}
					cantidad = stoi(cant, nullptr,0);
					cantidadEncontrada = true;
				}else{

					punt.at(0) = linea.at(i);
					if(i < linea.length() - 1 && linea.at(i+1) != '\t'){
						punt.at(1) = linea.at(i+1);
						i++;
					}
					puntos = stoi(punt, nullptr,0);
					
				}

			}


		}
	//	cout << "Letra: " << letra << " Cantidad:" << cantidad << " Puntos: " << puntos << endl;
		
		letras.push_back(Letra(letra, cantidad, puntos));

	}


	bolsa = Bolsa(letras);

	stream.close();

	return stream;
}


