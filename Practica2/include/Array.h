/**
  * @file Array.h
  * @brief Fichero cabecera del TDA Array
  *
  */

#ifndef ARRAY
#define ARRAY

#include <iostream>


using namespace std;


/**
  * @brief T.D.A. Array
  *
  * Una instancia de la clase es un conjunto de elementos sobre los que se pueden
  * realizar distintas operaciones.
  *
  * @author Oleksandr Kudryavtsev
  * @date Octubre 2008
  */

template <class T>
class Array{

private:

	T *array;
	int tam;

public:

	/**
	  * @brief Constructor por defecto de la clase.
	  */
	Array();

	/**
	  * @brief Constructor que recibe el tamaño inicial del vector.
	  * @param tam, tamaño del vector al crearse la instancia.
	  */
	Array(int tam);

	/**
	  * @brief Constructor de copias de la clase.
	  * @param array, vector a partir del que hacer la copia.
	  */
	Array(const Array<T>& array);

	/**
	  * @brief Constructor de copias por un intervalo determinado.
	  * @param ini, posicion inicial del intervalo.
	  * @param fin, posicion final del intervalo.
	  */
	Array(const Array<T>& array, int ini, int fin);

	/**
	  * @brief Destructor por defecto de la clase.
	  */	
	~Array();


	/**
	  * @brief Añade un elemento nuevo al vector.
	  * @param elemento, elemento a añadir al vector.
	  */
	void add(T elemento);

	/**
	  * @brief Sobreescribe el elemento de la posicion dada con un elemento nuevo.
	  * @param elemento, elemento nuevo.
	  * @param index, posicion en la que se sobreescribe el elemento.
	  */
	void set(T elemento, int index);

	/**
	  * @brief Elimina el elemento del vector que esta en la posicion dada.
	  * @param posicion, posicion del elemento a eliminar.
	  */
	void erasePosicion(int posicion);

	/**
	  * @brief Elimina un elemento del vector.
	  * @param elemento, elemento a eliminar del vector.
	  */
	void eraseElemento(T elemento);

	/**
	  * @brief Limpia el vector.
	  */
	void clear();

	/**
	  * @brief Devuelve el tamaño del vector.
	  * @return Tamaño del vector.
	  */
	int getSize() const;

	/**
	  * @brief Devuelve el vector de elementos.
	  * @return vector de elementos.
	  */
	T* getArray() const;

	/**
	  * @brief Devuelve el elemento del vector de la posicion dada.
	  * @param index, Posicion del elemento del vector a devolver.
	  * @return Elemento del vector de la posicion dada.
	  */
	T* get(int index);

	/**
	  * @brief Imprime por pantalla el contenido del vector.
	  */
	void print();


};

	#include "Array.tpp"


#endif
