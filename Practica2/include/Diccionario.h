/**
  * @file Diccionario.h
  * @brief Fichero cabecera del TDA Diccionario
  *
  */

#ifndef __DICCIONARIO
#define __DICCIONARIO


#include <fstream>
#include "Termino.h"


using namespace std;


/**
  * @brief T.D.A. Diccionario
  *
  * Una instancia de la clase es un conjunto de terminos sobre el que se pueden
  * realizar distintas operaciones. 
  *
  * @author Oleksandr Kudryavtsev
  * @date Octubre 2018
  */

class Diccionario{

private:

	Array<Termino> *terminos;	// conjunto de terminos del diccionario.
	int nTerminos;

public:

	/**
	  * @brief Constructor por defecto de la clase. Crea un diccionario vacio.
	  */
	Diccionario();

	/**
	  * @brief Constructor de la clase.
	  * @param terminos Conjunto de los terminos con el que crear la instancia.
	  */
	Diccionario(const Array<Termino>& t);

	/**
	  * @brief Constructor de copias de la clase.
	  * @param diccionario.terminos Conjunto de los terminos del diccionario.
	  */
	Diccionario(const Diccionario& diccionario);

	/**
	  * @brief Constructor que crea una instancia de un diccionario a partir de uno dado,
	  * almacenando en la nueva instancia los terminos que empiecen por las letras contenidas
	  * en el intevalo delimitado por el caracter inicial y el caracter final.
	  * @param diccionario.terminos Conjunto de los terminos del diccionario.
	  * @param caracterInicial El caracter que delimita el inicio del intervalo.
	  * @param caracterFinal El caracter que delimita el fin del intervalo.
	  */
	Diccionario(const Diccionario& diccionario, const char *caracterInicial, const char *caracterFinal);

	/**
	  * @brief Constructor que crea un diccionario con los terminos del diccionario dado que cumplan
	  * la condicion de que una de sus definiciones contiene la palabra clave. Se añade al
	  * diccionario creado el termino y solo la definicion que cumpla esa condicion.
	  * @param diccionario.terminos Conjunto de los terminos del diccionario.
	  * @oaram palabraClave Palabra clave que se busca en las definiciones.
	  */
	Diccionario(const Diccionario& diccionario, string palabraClave);

	/**
	  * @brief Destructor de la clase.
	  */
	~Diccionario();


	/**
	  * @brief Devuelve el conjunto de todos los terminos del diccionario.
	  * @return Conjunto de terminos del diccionario.
	  */
	Array<Termino>* getTerminos() const;

	/**
	  * @brief Devuelve el termino de la lista de terminos localizado en la posicion index.
	  * @return Termino de la posicion index.
	  */
	Termino* getTermino(int index);

	/**
	  * @brief Devuelve el numero de terminos del diccionario.
	  * @return Numero de terminos que tiene el diccionario.
	  */
	int getNumeroTerminos() const;


	/**
	  * @brief Añade un nuevo termino al diccionario.
	  * @param termino.palabra Palabra del termino.
	  * @param termino.definiciones Conjunto de definiciones de la palabra.
	  */
	void addTermino(Termino *termino);

	/**
	  * @brief Añade una definicion al termino que se encuentra en la posicion
	  * index del vector de terminos..
	  * @param index Posicion del termino en el que añadir la definicion.
	  * @param definicion Definicion a añadir en el termino.
	  */
	void addDefinicion(int index, string definicion);

	/**
	  * @brief Elimina los terminos cuya palabra se recibe como parametro.
	  * @param palabra Palabra de los terminos a eliminar.
	  */
	void eraseTermino(string palabra);


	/**
	  * @brief Salida del diccionario a un fichero.
	  * @param fichero Nombre del fichero donde escribir la informacion.
	  * @param dic Diccionario que se quiere guardar en fichero.
	  * @return flujo de salida usado.
	  */
	friend void operator << (string fichero, Diccionario& dic);

	/**
	  * @brief Entrada al diccionario desde un fichero.
	  * @param ifstream stream flujo de entrada.
	  * @param diccionario en el que guardar la informacion leida.
	  * @return flujo de entrada usado.
	  */
	friend ifstream& operator >> (ifstream& stream, Diccionario& dic);


	/**
	  * @brief Filtrado por intervalo, obtiene los terminos cuya palabra este en 
	  * el intervalo especificado por los caracteres recibidos por parametro.
	  * @param ini Caracter de inicio del intervalo.
	  * @param fin Caracter de fin del intervalo.
	  * @return Conjunto de los terminos cuya palabra este en el intervalo.
	  */
	Termino* filtrado(char ini, char fin);

	/**
	  * @brief Filtrado por palabra clave, obtiene los terminos en cuya definicion
	  * aparezca la palabra clave.
	  * @param palabra Palabra clave para la busqueda.
	  * @return Conjunto de los terminos cuya definicion contenga la palabra clave.
	  */
	string* filtrado(string palabra);

	/**
	  * @brief Realiza un recuento de los terminos del diccionario proporcionando
	  * la informacion sobre el numero total de definiciones, el maximo de definiciones
	  * asociadas a una unica palabra y el promedio de las definiciones por palabra.
	  */
	void recuento();


	/**
	  * @brief Muestra por pantalla todas las palabras del diccionario y sus definiciones 
	  */
	void print();

	/**
	  * @brief Muestra por pantalla el conjunto de las definiciones de una palabra dada.
	  */
	void printDefiniciones(string palabra);

};

#endif
