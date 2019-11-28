/**
  * @file Juego.h
  * @brief Fichero cabecera del TDA Juego
  *
  */

#ifndef JUEGO
#define JUEGO

#include <iostream>
#include <string>

#include "Diccionario.h"
#include "Bolsa.h"


using namespace std;

/**
  * @brief T.D.A. Juego
  *
  * Una instancia de la clase contiene un diccionario con el que jugar, una bolsa de letras disponibles y otros datos necesarios
  * para poder jugar al juego de buscar la palabra mas larga o de mayor puntuacion en el diccionario con las letras disponibles.
  *
  * @author Oleksandr Kudryavtsev
  * @date Diciembre 2018
  */

class Juego{

    Diccionario diccionario;
    Bolsa bolsa;
    int longitud;
    char modoJuego;

    vector<char> aleatorias;


public:

    /**
      * @brief Constructor de la clase por parametros.
      * @param diccionario, el diccionario que contiene las palabras con las que se va a jugar.
      * @param bolsa, la bolsa de letras que contiene las letras con las que vamos a jugar.
      * @param longitud, la longitud de las palabras que se formaran en el juego.
      * @param modoJuego, el modo del juego, buscar palabras mas largas o con mayor puntuacion.
      */
    Juego(Diccionario diccionario, Bolsa bolsa, int longitud, char modoJuego);

    /**
      * @brief Inicia el juego.
      */
    void jugar();

    /**
      * @brief Busca el conjunto de palabras con mayor longitud posible del diccionario que se pueden formar con las letras dadas (la cantidad de letras acaba siendo la maxima longitud posible)
      * @return conjunto de palabras encontradas.
      */
    vector<string> buscarPalabraPorLongitud();
    
    /**
      * @brief Busca la palabra con mayor puntuacion posible que se puede formar con las palabras del diccionario utilizando las letras dadas.
      * @return conjunto de palabras encontradas.
      */
    vector<string> buscarPalabraPorPuntos();

    /**
      * @brief Indica si una palara dada se puede construir usando un conjunto de letras disponibles.
      * @param palabra, la palabra que se quiere comprobar.
      * @param letrasDisponibles, el conjunto de letras con las que comprobar la palabra.
      * @return true si la palabra se puede formar con las letras dadas, false en caso contrario.
      */
    bool puedoFormar(string palabra, vector<char>letrasDisponibles);

};

#endif