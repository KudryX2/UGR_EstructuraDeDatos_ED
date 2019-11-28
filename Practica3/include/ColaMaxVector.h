/**
  * @file Cola_max_vd.h
  * @brief Fichero cabecera del TDA Cola con maximo version vector
  *
  */

#ifndef ARRAY
#define ARRAY

#include <iostream>
#include <vector>
#include <utility>


using namespace std;


/**
  * @brief T.D.A. Cola con maximo version vector
  *
  * Cola de elementos que a su vez registra el mayor elemento que contiene
  * implementada usando como base un vector de pares, cada uno de estos 
  * almacena un elemento y el elemento maximo de la cola.
  *
  * @author Oleksandr Kudryavtsev
  * @date Octubre 2018
  */

template <class T>
class ColaMax{

	private:
		vector<pair<T,T>> cola;

	public:

		/**
		  * @brief Constructor por defecto de la clase. Crea una cola vacia.
		*/
		ColaMax();
		

		/**
		  * @brief Añade un elemento a la cola.
		  * @param elemento, Elemento a añadir a la cola.
		*/
		void poner(T elemento);

		/**
		  * @brief Quita el elemento que se encuenta en el frente de la cola.
		  */
		void quitar();

		/**
		  * @brief Busca el elemento maximo de la cola y accede a todos los.
		  * elementos para actualizar el maximo que almacenan.
		  */
		void actualizarMaximo();

		/**
		  * @brief Recorre todos los elementos de la cosa y actualiza el maximo
		  * que almacenan con el nuevo elemento.
		  * @param maximo. El nuevo maximo con el que actualizar los elementos.
		  */
		void actualizarMaximo(T maximo);


		/**
		  * @brief Devuelve el elemento que se encuentra en el frente de la cola.
		  * @return elemento del frente de la cola.
		  */
		T frente();
		
		/**
		  * @brief Indica si la cola esta vacia o no.
		  * @return devuelve un booleano que indica si la cola esta vacia o no.
		  */
		bool vacia();	
		
		/**
		  * @brief Devuelve el elemento maximo de la cola.
		  * @return el elemento maximo de la cola.
		  */
		T maximo();
		
		/**
		  * @brief Devuelve el tamaño de la cola.
		  * @return el tamaño de la cola.
		  */
		int numElementos();
		

		/**
		  * @brief Imprime todos los elementos de la cola por pantalla.
		  */
		void print();
};

	#include "ColaMaxVector.tpp"

#endif
