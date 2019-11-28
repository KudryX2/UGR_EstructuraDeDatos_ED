#include "Diccionario.h"

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

	Diccionario mi_diccionario,subdiccionario1,subdiccionario2;
	f>>mi_diccionario; //Cargamos en memoria el diccionario

	//Usamos un iterador para recorrer los terminos del diccionario e imprimirlos
	/* */
	Diccionario::const_iterator it; 
	for(it = mi_diccionario.begin(); it != mi_diccionario.end(); it++){
		cout << (*it) << endl;
	}
	/* */

	/* Exhibir aqui la funcionalidad programada para el TDA Diccionario / TDA Termino  	*/

	//	- Obtener las definiciones asociadas a una palabra   
	cout << "\nDefiniciones asociadas a la palabra anderson" << endl;
	vector<string> definiciones = mi_diccionario.getDefiniciones("anderson");
	for(unsigned int i = 0 ; i != definiciones.size() ; ++i){
		cout << definiciones[i] << endl;
	}

	//	- Obtener el (sub)diccionario de términos comprendidos en [caracter_inicial, caracter_final]
	cout << "\nSubdiccionario de terminos entre dos caracteres" << endl;
	subdiccionario1 = Diccionario(mi_diccionario, 'y', 'y');
	cout << subdiccionario1;

	//	- Obtener el (sub)diccionario de términos asociados a una palabra clave. Ejemplo: el diccionario de terminos asociados a "color"   
	cout << "\nSubdiccionario de terminos asociados a una palabra clave" << endl;
	subdiccionario2 = Diccionario(mi_diccionario, "color");
	cout << subdiccionario2;

	//	- Obtener el numero total de definiciones, el maximo de definiciones asociadas a una unica palabra y el promedio de definiciones por palabra
	cout << "\nNumero total de definiciones, el maximo de definiciones asociadas a una unica palabra y el promedio de definiciones por palabra" << endl;
	mi_diccionario.recuento();

	//	- Cualquier otra funcionalidad que considereis de interes 
	cout << "\nGuardar un diccionario en un fichero sobrecargando el eperador salida" << endl;
	"ficheroPrueba.txt" << subdiccionario1;

	cout << "\nEliminar el termino young del diccionario (subdiccionario1, terminos entre dos caracteres)" << endl;
	subdiccionario1.eliminarTermino("young");
	cout << subdiccionario1;

	cout << "\nAñadir el termino yegua al diccionario (subdiccionario1, terminos entre dos caracteres)" << endl;
	subdiccionario1.addTermino(Termino("yegua","caballo hembra"));
	cout << subdiccionario1;
/* */
}
