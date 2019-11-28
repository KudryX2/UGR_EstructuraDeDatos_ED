#ifndef BOLSA
#define BOLSA

#include <string>
#include <vector>
#include <set>

#include "Letra.h"

using namespace std;

/**
  * @brief T.D.A. Bolsa
  *
  * Una instancia de la clase consiste en un conjunto de letras sobre las que se pueden
  * realizar distintas operaciones.
  *
  * @author Oleksandr Kudryavtsev
  * @date Diciembre 2018
  */

class Bolsa{

		vector<Letra> letras;

	public:

		/**
		  * @brief Constructor por defecto de la clase. Crea una bolsa vacia.
		  */
		Bolsa();

		/**
		  * @brief Constructor de la clase por parametros.
		  * @param letras, Conjunto de las letras con las que crear la instancia.
		  */
		Bolsa(vector<Letra> letras);


		/**
		  * @brief Devuelve el conjunto de las letras de la bolsa.
		  * @return conjunto de las letras.
		  */
		vector<Letra> getLetras() const;

		/**
		  * @brief Devuelve la cantidad de letras de al bolsa.
		  * @return cantidad de letras en la bolsa.
		  */
		int getCantidadLetras() const;


		/**
	  	  * @brief Devuelve un conjunto de tamaño dado compuesto por letras aleatorias.
	  	  * @param cantidad, cantidad de letras aleatorias a escoger
	  	  * @return caracter asociado.
	  	  */
		vector<char> escogerAleatorias(int cantidad);

		/**
	  	  * @brief Devuelve los puntos que vale una palabra dada.
	  	  * @param palabra, la palabra cuya puntuacion se quiere calcular.
	  	  * @return puntuacion de la palabra dada.
	  	  */
		int calcularPuntuacion(string palabra);


		/**
		  * @brief Salida de la bolsa por pantalla.
		  * @param stream, flujo de salida.
		  * @param bolsa, bolsa que se quiere imprimir por pantalla.
		  * @return flujo de salida usado.
		  */
		friend ostream& operator << (ostream& stream, const Bolsa& bolsa);

		/**
		  * @brief Entrada de la bolsa desde un fichero.
		  * @param ifstream stream flujo de entrada.
		  * @param bolsa en la que guardar la informacion leida.
		  * @return flujo de entrada usado.
		  */
		friend ifstream& operator >> (ifstream& stream, Bolsa& bolsa);

};

#endif