/**
  * @file Termino.h
  * @brief Fichero cabecera del TDA Termino
  *
  */

#ifndef __TERMINO
#define __TERMINO


#include <string>
#include "Array.h"


using namespace std;

/**
  * @brief T.D.A. Termino
  *
  *	Una instancia es un objeto que se refiere a un termino, este consiste  
  *	en una palabra y el conjunto de sus definiciones.
  *
  * @author Oleksandr Kudryavtsev
  * @date Octubre 2018
  */

class Termino{

private:
	string palabra;			// palabra a la que se asocian los terminos.
	Array<string> *definiciones;

public:

	/**
	  * @brief Constructor por defecto de la clase. Crea un termino con la palabra "vacio" sin definiciones.
	  */
	Termino();

	/**
	  * @brief Constructor de la clase.
	  * @param palabra Palabra del termino.
	  * @param definicion Definicion de la palabra.
	  */
	Termino(string p, string definicion);

	/**
	  * @brief Constructor de copias de la clase.
	  * @param termino.palabra Palabra del termino.
	  * @param termino.definiciones Definiciones de la palabra.
	  */
	Termino(const Termino& termino);

	/**
	  * @brief Destructor de la clase.
	  */
	~Termino();

	/**
	  * @brief Devuelve la palabra del termino.
	  * @return devuelve variable palabra.
	  */  
	string getPalabra() const;

	/**
	  * @brief Devuelve las definiciones del termino.
	  * @return devuelve el consjunto de las definiciones.
	  */ 
	Array<string>* getDefiniciones() const;

	/**
	  * @brief Devuelve el numero de definiciones del termino.
	  * @return devuelve el tamaño del conjunto de definiciones.
	  */ 
	int getNumeroDefiniciones();


	/**
	  * @brief Cambia la palabra del termino por la recibida como argumento.
	  * @param palabra Palabra nueva.
	  */
	void setPalabra(string p);

	/**
	  * @brief Añade una nueva definicion al conjunto de definiciones de la palabra.
	  * @param termino.definicione Definicion de la palabra a añadir.
	  */
	void addDefinicion(string definicion);

	/**
	  * @brief Sobrecarga del operador "==", compara dos terminos segun la palabra que definen.
	  * @param t, termino a comparar.
	  */
	bool operator ==(const Termino& t);

	/**
	  * @brief Imprime la palabra y sus definiciones contenidos en el termino.
	  */
	void print();

};


#endif