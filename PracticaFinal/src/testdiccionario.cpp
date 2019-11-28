#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>

#include "Diccionario.h"
#include "Bolsa.h"

using namespace std;

int main(int argc, char * argv[]){

	if (argc!=2){
		cout<<"Los parametros son:"<<endl;
		cout<<"1.- El fichero con las palabras";
		return 0;
	}

	ifstream f(argv[1]);

	if(!f){
		cout << "\nNo puedo abrir el fichero" << endl;
		return 0;
	}

	Diccionario d;
	cout << "Cargando diccionario..." << endl;
	f >> d;
	cout << "Diccionario leido" << endl;
	cout << d;


	int longitud;
	cout << "Dime la longitud de palabras que quieras ver" << endl;
	cin >> longitud;
	vector<string> v = d.getPalabrasLongitud(longitud);

	cout << "Palabras de longitud " << longitud << endl;
	for (unsigned int i=0;i<v.size();i++)
		cout<<v[i]<<endl;

	string p;
	cout<<"Dime una palabra: ";
	cin>>p;
	if (d.esta(p)) 
		cout<<"Sí esa palabra existe" << endl;
	else
		cout<<"Esa palabra no existe" << endl;

}
