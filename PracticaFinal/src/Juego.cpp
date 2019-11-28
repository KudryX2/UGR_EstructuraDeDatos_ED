#include "Juego.h"

Juego::Juego(Diccionario diccionario, Bolsa bolsa, int longitud, char modoJuego){
	this->diccionario = diccionario;
	this->bolsa = bolsa;
	this->longitud = longitud;
	this->modoJuego = modoJuego;
}

void Juego::jugar(){

	string miSolucion;
	int puntosMiSolucion;
	char entrada;

	vector<string> busqueda;


	do{
		/*
			Escogemos las letras con las que jugar, sean aleatorias o de prueba
		*/
		cout << "\n_________________________________________________________" << endl;
		cout << "Las letras son: ";
		aleatorias = bolsa.escogerAleatorias(longitud);
		/* * /
			//Prueba (8 letras)
			aleatorias.clear();
			aleatorias.push_back('T');
			aleatorias.push_back('I');
			aleatorias.push_back('E');
			aleatorias.push_back('O');
			aleatorias.push_back('I');
			aleatorias.push_back('T');
			aleatorias.push_back('U');
			aleatorias.push_back('S');			
		/* */

		/* * /	
			//Prueba 2 (8 letras)
			aleatorias.clear();
			aleatorias.push_back('N');
			aleatorias.push_back('S');
			aleatorias.push_back('A');
			aleatorias.push_back('O');
			aleatorias.push_back('T');
			aleatorias.push_back('O');
			aleatorias.push_back('A');
			aleatorias.push_back('I');
		/* */
		for(unsigned int i = 0 ; i < aleatorias.size() ; ++i ){
			cout << aleatorias[i] << "  ";
		}
		cout << endl;


		/*
			El jugador introduce su solucion y se calcula la puntuacion de esta.			
		*/
		cout << "\nDime tu solucion: ";
		cin >> miSolucion;
		if(diccionario.esta(miSolucion)){
			puntosMiSolucion = bolsa.calcularPuntuacion(miSolucion); 
			cout << "\t" << miSolucion << " Puntuacion: " << puntosMiSolucion << endl;
		}else{
			cout << "\t" << "Esta palabra no existe" << endl;
		}	


		/*
			Segun la modalidad del juego el programa busca la/las palabras mas largas o con mayor
			puntuacion
		*/
		cout << "\nMis soluciones son:" << endl;
		if( modoJuego == 'L'){
			busqueda = buscarPalabraPorLongitud();
		}else if( modoJuego == 'P'){
			busqueda = buscarPalabraPorPuntos();
		}


		/*
			Se calcula cual es la mejor solucion entre la encontrada por el jugador y el programa
		*/
		string mejor;
		int mejorEncontrada = 0;
		int aux;
		for(unsigned int i = 0 ; i < busqueda.size() ; ++i){
			aux = bolsa.calcularPuntuacion(busqueda[i]);
			if(aux >= mejorEncontrada){
				mejor = busqueda[i];
				mejorEncontrada = aux;
			}
			cout << "\t"<< busqueda[i] << " Puntuacion: " << aux << endl;
		}

		if(mejorEncontrada < puntosMiSolucion){
			mejor = miSolucion;
		}
		cout << "\nMejor solucion: " << mejor << endl;


		cout << "_________________________________________________________" << endl;
		cout << "\n¿Quieres seguir jugando [S/N]? ";
		cin >> entrada;


	}while(toupper(entrada) != 'N');

}

vector<string> Juego::buscarPalabraPorLongitud(){
	vector<string>resultados, buscadas;
	int longitudMaxima = 0;

	/* 
		Recorro diccionario por palabras mas largas a mas cortas hasta que encuentra 
		una palabra que pueda formar, entonces solo busca mas palabras de la misma 
		longitud que la encontrada.
	*/
	for( int i = longitud ; i > 1 && longitudMaxima == 0 ; --i){
		buscadas = diccionario.getPalabrasLongitud(i);
	
		// Recorro vector de palabras y averiguo si se pueden formar con las letras dadas
		for(unsigned int j = 0 ; j < buscadas.size() ; ++j){

			if(puedoFormar(buscadas[j], aleatorias) ){
				resultados.push_back( buscadas[j] );
			}				
		}

		/*
			Si encontramos una palabra que podamos formar guardamos su longitud
			para buscar otras palabras de la misma longitud.
		*/
		if(longitudMaxima == 0 && !resultados.empty()){
			longitudMaxima = i;
		}
	}

	return resultados;
}

vector<string> Juego::buscarPalabraPorPuntos(){
	vector<string>resultados, buscadas, palabrasPosibles;

	/*
		Recorro vector de palabras y guardo las que se pueden formar con las letras dadas
	*/
	for( int i = longitud ; i > 1 ; --i){
		buscadas = diccionario.getPalabrasLongitud(i);
	
		for(unsigned int j = 0 ; j < buscadas.size() ; ++j){

			if(puedoFormar(buscadas[j], aleatorias) ){
				palabrasPosibles.push_back( buscadas[j] );
			}				
		}
	}

	string palabraMasPuntos;
	int puntos = 0;
	int aux;
	for(unsigned int i = 0 ; i < palabrasPosibles.size() ; ++i){
		aux = bolsa.calcularPuntuacion(palabrasPosibles[i]);
		if(aux > puntos){
			puntos = aux;
			palabraMasPuntos = palabrasPosibles[i];
		}
	}
	resultados.push_back(palabraMasPuntos);

	return resultados;
}

bool Juego::puedoFormar(string palabra, vector<char>letrasDisponibles){
	bool puedo = true;
	bool letraEncontrada;

	// Recorro palabra letra a letra
	for(unsigned int p = 0 ; p < palabra.length() && puedo  ; ++p){
		/*
			Recorro el vector de letras disponibles y si una letra coincide con 
			una de la palabra a formar, elimino esa letra del vector de letras
			disponibles. De esta forma cuando no encuentre una letra necesaria
			para formar la palabra en el vector de disponibles se sabra que
			esa palabra no se puede formar.
		*/
		letraEncontrada = false;
		for(unsigned int l = 0 ; l < letrasDisponibles.size() && !letraEncontrada ; ++l){

			if(toupper(palabra.at(p)) == letrasDisponibles[l]){
				letraEncontrada = true;
				letrasDisponibles.erase(letrasDisponibles.begin()+l);
			}
		}

		if(!letraEncontrada){
			puedo = false;
		}

	}

	return puedo;
}