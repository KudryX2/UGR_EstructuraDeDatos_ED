/**
  * @file Cola_max_vd.h
  * @brief Fichero cabecera del TDA Cola con maximo version dos pilas
  *
  */

#ifndef ARRAY
#define ARRAY

#include <iostream>
#include <stack>
#include <utility>


using namespace std;


/**
  * @brief T.D.A. Cola con maximo version pilas
  *
  * Cola de elementos que a su vez registra el mayor elemento que contiene.
  * Se implementa haciendo uso de dos pilas, una destinada a la inserccion
  * de los elementos y otra a su modificacion y consulta.
  *
  * @author Oleksandr Kudryavtsev
  * @date Octubre 2018
  */

template <class T>
class ColaMax{

	private:
		stack<pair<T,T>> pilaInsercion,pilaModificacion;

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

		void rellenarPilaModificacion();

};

	#include "ColaMaxPila.tpp"

#endif
