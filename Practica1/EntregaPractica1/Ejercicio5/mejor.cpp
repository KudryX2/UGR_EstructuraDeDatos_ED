#include <iostream>
#include <ctime>    

using namespace std;

void ordenar(int *v, int n) {
	bool cambio=true;
	
	for (int i=0; i<n-1 && cambio; i++) {
		cambio=false;
		
		for (int j=0; j<n-i-1; j++){
			if (v[j]>v[j+1]) {
				cambio=true;
				int aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
		}

	}
}

int main(int argc, char * argv[]){
	// Lectura de parámetros
	int tam=atoi(argv[1]);     // Tamaño del vector

	// Generación del vector aleatorio
	int *v=new int[tam];       // Reserva de memoria
	
	for (int i=0; i<tam; i++)  // Recorrer vector
		v[i] = i;

	clock_t tini;    // Anotamos el tiempo de inicio
	tini=clock();

	ordenar(v,tam); // de esta forma forzamos el peor caso

	clock_t tfin;    // Anotamos el tiempo de finalización
	tfin=clock();

	// Mostramos resultados
	cout << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;

	delete [] v;     // Liberamos memoria dinámica

}
