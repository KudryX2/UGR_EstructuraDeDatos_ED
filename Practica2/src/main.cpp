#include <iostream>
#include <fstream>
#include <Diccionario.h>

using namespace std;

int main(int argc, char * argv[]){

	if (argc!=2){
		cout<<"Dime el nombre del fichero con el diccionario"<<endl;
		return 0;
	}

	ifstream f (argv[1]);

	if (!f){
		cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
		return 0;
	}
	
	Diccionario mi_diccionario, diccionario;
	/* */ 
	f>>mi_diccionario; //Cargamos en memoria el diccionario
	//mi_diccionario.print();
	/* */

	/* Exhibir aqui la funcionalidad programada para el TDA Diccionario / TDA
	Termino
	Algunas sugerencias: */
	
	//	- Obtener las definiciones asociadas a una palabra 
	cout << "\nDefiniciones de una palabra (abel)" << endl; 
	mi_diccionario.printDefiniciones("abel"); 

	//	- Obtener el (sub)diccionario de términos comprendidos en [caracter_inicial, caracter_final]
	cout << "\nSubdiccionario a partir de un caracter inicial y uno final (y y z)" << endl;
	diccionario = Diccionario(mi_diccionario,"y","z");
	diccionario.print();

	//	- Obtener el (sub)diccionario de términos asociados a una palabra clave.
	cout << "\nSubdiccionario a partir de definiciones que tengan una palabra clave (color)" << endl;
	diccionario = Diccionario(mi_diccionario, "color");
	diccionario.print();
	
	//	- Obtener el numero total de definiciones, el maximo de definiciones asociadas a una unica palabra y el promedio de definiciones por palabra 
	cout << "\nObtener n·total de definiciones, maximo y la media de de definiciones por palabra" << endl;
	mi_diccionario.recuento();

	// - Cualquier otra funcionalidad que considereis de interes
	cout << "\nEl diccionario obtenido de la penultima pregunta se guarda en un fichero" << endl;
	"nombre.txt" << diccionario;


}