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

#include "Termino.h"


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
	set<Termino> terminos;

public:

	typedef set<Termino>::iterator iterator;
	typedef set<Termino>::const_iterator const_iterator;

	/**
	  * @brief Constructor por defecto de la clase. Crea un diccionario vacio.
	  */
	Diccionario();

	/**
	  * @brief Constructor de la clase.
	  * @param terminos Conjunto de los terminos con el que crear la instancia.
	  */
	Diccionario(set<Termino> &terminos);

	/**
	  * @brief Constructor de copias de la clase.
	  * @param diccionario.terminos Conjunto de los terminos del diccionario.
	  */
	Diccionario(const Diccionario &diccionario);

	/**
	  * @brief Constructor que crea una instancia de un diccionario a partir de uno dado,
	  * almacenando en la nueva instancia los terminos que empiecen por las letras contenidas
	  * en el intevalo delimitado por el caracter inicial y el caracter final.
	  * @param diccionario.terminos Conjunto de los terminos del diccionario.
	  * @param caracter_inicio El caracter que delimita el inicio del intervalo.
	  * @param caracter_fin El caracter que delimita el fin del intervalo.
	  */
	Diccionario(const Diccionario &diccionario, char caracter_inicio, char caracter_fin);

	/**
	  * @brief Constructor que crea un diccionario con los terminos del diccionario dado que cumplan
	  * la condicion de que una de sus definiciones contenga la palabra clave. 
	  * @param diccionario.terminos Conjunto de los terminos del diccionario.
	  * @oaram palabraClave Palabra clave que se busca en las definiciones.
	  */
	Diccionario(const Diccionario &diccionario, string palabraClave);


	/**
	  * @brief Devuelve el conjunto de definiciones asociadas a una palabra.
	  * @return conjunto de definiciones.
	  */
	vector<string> getDefiniciones(string palabra);

	/**
	  * @brief Devuelve el conjunto de todos los terminos del diccionario.
	  * @return Conjunto de terminos del diccionario.
	  */
	set<Termino> getTerminos() const;

	/**
	  * @brief Devuelve el termino que define la palabra dada.
	  * @return termino que esta definido por palabra.
	  */
	Termino getTermino(string palabra) const;

	/**
	  * @brief Devuelve el numero de terminos del diccionario.
	  * @return Numero de terminos que tiene el diccionario.
	  */
	int getNumeroTerminos();


	/**
	  * @brief Añade un nuevo termino al diccionario.
	  * @param termino.first Palabra del termino.
	  * @param termino.second Conjunto de definiciones de la palabra.
	  */
	void addTermino(Termino termino);

	/**
	  * @brief Elimina el termino que define la palabra dada.
	  * @param palabra, palabra del termino que se quiere eliminar.
	  */
	void eliminarTermino(string palabra);


	/**
	 * @brief Realiza el recuento del diccionario imprimiento por pantalla: el numero total de definiciones, el maximo de definiciones asociadas a una palabra y el promedio de definiciones por palabra
	 */
	void recuento();


	/**
	  * @brief Salida del diccionario a un fichero.
	  * @param fichero Nombre del fichero donde escribir la informacion.
	  * @param dic Diccionario que se quiere guardar en fichero.
	  */
	friend void operator << (string fichero, const Diccionario& dic);

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
	  * @brief Devuelve el iterador al comienzo del conjunto de terminos.
	  * @return devuelve iterador al comienzo del contenedor set de terminos.
	  */ 
	Diccionario::iterator begin();	

	/**
	  * @brief Devuelve el iterador al final del conjunto de terminos.
	  * @return devuelve iterador al final del contenedor set de terminos.
	  */ 
	Diccionario::iterator end();

	/**
	  * @brief Devuelve el iterador constante al comienzo del conjunto de terminos.
	  * @return devuelve iterador constante al comienzo del contenedor set de terminos.
	  */ 
	Diccionario::const_iterator begin() const;	

	/**
	  * @brief Devuelve el iterador constante al final del conjunto de terminos.
	  * @return devuelve iterador constante al final del contenedor set de terminos.
	  */ 
	Diccionario::const_iterator end() const;

};


#endif