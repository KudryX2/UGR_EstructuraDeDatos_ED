#include <iostream>
#include <ctime>    
#include <cstdlib>

using namespace std;

int main(int argc, char * argv[]){

	int tam=atoi(argv[1]);	// Tamaño de las matrices

/* */
	int m1[tam][tam];
	int m2[tam][tam];
	int mR[tam][tam];

/* * /

	int **m1, **m2, **mR;

	m1 = new int*[tam];
	m2 = new int*[tam];
	mR = new int*[tam];

	for(int i = 0 ; i < tam ; ++i){
		m1[i] = new int[tam];
		m2[i] = new int[tam];
		mR[i] = new int[tam];
	}

/* */

	srand(time(0));            // Inicialización del generador de números pseudoaleatorios
	for(int i = 0 ; i < tam ; ++i){
		for(int j = 0 ; j < tam ; ++j){
			m1[i][j] = rand()%10000;
			m2[i][j] = rand()%10000;
		}
	}

	clock_t tini;    // Anotamos el tiempo de inicio
	tini=clock();

	for(int i = 0 ; i < tam ; ++i){
		for(int j = 0 ; j < tam ; ++j){
			mR[i][j] = 0;
			for(int k = 0 ; k < tam ; ++k){
				mR[i][j]+=m1[i][k]*m2[k][j];
			}
		}
	}

	clock_t tfin;    // Anotamos el tiempo de finalización	
	tfin=clock();

	// Mostramos resultados
	cout << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;

	/* * /
	for(int i = 0 ; i < tam ; ++i){
		delete[] m1[i];
		delete[] m2[i];
		delete[] mR[i];
	}
	delete[] m1;
	delete[] m2;
	delete[] mR;
	/* */


}