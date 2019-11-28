/**
  * @file Termino.h
  * @brief Fichero cabecera del TDA Termino
  *
  */

#ifndef TERMINO
#define TERMINO

#include <string>
#include <vector>
#include <utility>
#include <iterator>


using namespace std;

/**
  * @brief T.D.A. Termino
  *
  *	Una instancia es un objeto que se refiere a un termino, este consiste  
  *	en una palabra y el conjunto de sus definiciones.
  *
  * @author Oleksandr Kudryavtsev
  * @date Diciembre 2018
  */

class Termino{

private:
	pair<string,vector<string>> termino;

public:

	typedef vector<string>::iterator iterator;
	typedef vector<string>::const_iterator const_iterator;

	/**
	  * @brief Constructor por defecto de la clase. Crea un termino con la palabra "vacio" sin definiciones.
	  */
	Termino();

	/**
	  * @brief Constructor de la clase.
	  * @param palabra Palabra del termino.
	  * @param definicion Definicion de la palabra.
	  */
	Termino(string palabra, string definicion);

	/**
	  * @brief Constructor de copias de la clase.
	  * @param termino.palabra Palabra del termino.
	  * @param termino.definiciones Definiciones de la palabra.
	  */
	Termino(const Termino &termino);


	/**
	  * @brief Cambia la palabra del termino por la recibida como argumento.
	  * @param palabra Palabra nueva.
	  */
	void setPalabra(string palabra);

	/**
	  * @brief Añade una nueva definicion al conjunto de definiciones de la palabra.
	  * @param definicion Definicion de la palabra a añadir.
	  */
	void addDefinicion(string definicion);

	/**
	  * @brief Añade un conjunto de definiciones al conjunto de definiciones de la palabra.
	  * @param definiciones Conjunto de definiciones a añadir.
	  */
	void addDefiniciones(vector<string> definiciones);


	/**
	  * @brief Devuelve la palabra del termino.
	  * @return devuelve el primer elemento del par termino, es decir la palabra.
	  */
	string getPalabra() const;

	/**
	  * @brief Devuelve las definiciones del termino.
	  * @return devuelve el segundo elemento del par termino, es decir el conjunto de las definiciones de la palabra
	  */
	vector<string> getDefiniciones() const;

	/**
	  * @brief Devuelve el numero de definiciones del termino.
	  * @return devuelve el tamaño del conjunto de definiciones.
	  */ 
	int getNumeroDefiniciones() const;


	/**
	  * @brief Sobrecarga del operador "<<", usado para mostrar en pantalla la informacion de un termino.
	  * @param stream, flujo de salida por el que mostrar la informacion.
	  * @param t, termino, termino cuya informacion se va a imprimir por pantalla.
	  */
	friend ostream& operator << (ostream& stream, const Termino& termino);

	/**
	  * @brief Sobrecarga del operador "<", usado para ordenar los terminos alfabeticamente segun la palabra del termino.
	  * @param termino1, primer termino a comparar
	  * @param termino2, segundo termino a comparar
	  */
	friend bool operator < (const Termino &termino1, const Termino &termino2);


	/**
	  * @brief Devuelve el iterador al comienzo del conjunto de definiciones.
	  * @return devuelve el iterador al comienzo del vector de definiciones.
	  */ 
	Termino::iterator begin();

	/**
	  * @brief Devuelve el iterador al final del conjunto de definiciones.
	  * @return devuelve el iterador al final del vector de definiciones.
	  */ 
	Termino::iterator end();

	/**
	  * @brief Devuelve el iterador constante al comienzo del conjunto de definiciones.
	  * @return devuelve el iterador constante al comienzo del vector de definiciones.
	  */ 
	Termino::const_iterator begin() const;

	/**
	  * @brief Devuelve el iterador constante al final del conjunto de definiciones.
	  * @return devuelve el iterador constante al final del vector de definiciones.
	  */ 
	Termino::const_iterator end() const;

};


#endif
