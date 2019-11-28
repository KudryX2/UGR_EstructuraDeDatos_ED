/**
  * @file Diccionario.h
  * @brief Fichero cabecera del TDA Diccionario
  *
  */

#ifndef DICCIONARIO
#define DICCIONARIO

#include <string>
#include <vector>
#include <iterator>
#include <set>

#include <fstream>
#include <iostream>

#include <string>


using namespace std;

/**
  * @brief T.D.A. Diccionario
  *
  * Una instancia de la clase es un conjunto de terminos sobre el que se pueden
  * realizar distintas operaciones. 
  *
  * @author Oleksandr Kudryavtsev
  * @date Diciembre 2018
  */

class Diccionario{

private:
	set<string> terminos;

public:

	typedef set<string>::const_iterator Iterator;

	/**
	  * @brief Constructor por defecto de la clase. Crea un diccionario vacio.
	  */
	Diccionario();

	/**
	  * @brief Constructor de la clase por parametros.
	  * @param terminos Conjunto de los terminos con el que crear la instancia.
	  */
	Diccionario(set<string> &terminos);

	
	/**
	  * @brief Obtiene todas las palabras en el diccionario de un longitud dada
	  * @param longitud: la longitud de las palabras de salida
	  * @return un vector con las palabras de longitud especifica en el parametro de entrada
	  */
	vector<string> getPalabrasLongitud(unsigned int longitud);


	/**
	  *	@brief Indica si una palabra está en el diccionario o no
	  *	@param palabra: la palabra que se quiere buscar
	  *	@return true si la palabra esta en el diccionario. False en caso contrario
	  */
	bool esta(string palabra);

	/**
	  * @brief Devuelve el numero de terminos del diccionario.
	  * @return Numero de terminos que tiene el diccionario.
	  */
	int size() const;


	/**
	  * @brief Salida del diccionario por pantalla.
	  * @param stream, flujo de salida.
	  * @param dic, diccionario que se quiere imprimir por pantalla.
	  * @return flujo de salida usado.
	  */
	friend ostream& operator << (ostream& stream, const Diccionario& dic);

	/**
	  * @brief Entrada al diccionario desde un fichero.
	  * @param ifstream stream flujo de entrada.
	  * @param diccionario en el que guardar la informacion leida.
	  * @return flujo de entrada usado.
	  */
	friend ifstream& operator >> (ifstream& stream, Diccionario& dic);
	

	/**
	  * @brief Devuelve el iterador constante al comienzo del conjunto de terminos.
	  * @return devuelve iterador constante al comienzo del contenedor set de terminos.
	  */ 
	Iterator begin() const;	

	/**
	  * @brief Devuelve el iterador constante al final del conjunto de terminos.
	  * @return devuelve iterador constante al final del contenedor set de terminos.
	  */ 
	Iterator end() const;
	

};


#endif