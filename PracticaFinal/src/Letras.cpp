#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <set>

#include "Diccionario.h"
#include "Bolsa.h"
#include "Juego.h"

using namespace std;


int main(int argc, char * argv[]){

	if (argc!=5){
		cout << "Los parametros son:" << endl;
		cout << "1.- El fichero con las palabras" << endl;
		cout << "2.- El fichero con las letras" << endl;
		cout << "3.- El numero de letras que se deben generar de forma aleatoria" << endl;
		cout << "4.- Modalidad de juego (L - Palabra mas larga | P - Mayor puntuacion)" << endl;
		return 0;
	}

	/*
		Cargamos el diccionario
	*/
	ifstream f(argv[1]);
	if(!f){
		cout << "\nNo puedo abrir el fichero del diccionario" << endl;
		return 0;
	}

	Diccionario diccionario;
	cout << "Cargando diccionario..." << endl;
	f >> diccionario;
	cout << "Diccionario leido" << endl;
//	cout << d;

	/*	
		Cargamos la bolsa
	*/
	ifstream f2(argv[2]);
	if(!f2){
		cout << "\nNo puedo abrir el fichero de las letras" << endl;
		return 0;
	}

	Bolsa bolsa;
	f2 >> bolsa;
//	cout << bolsa;

	/*
		Comienzo del juego
	*/
	Juego juego = Juego(diccionario, bolsa, stoi(argv[3], nullptr,0), (*argv[4]));

	juego.jugar();
}