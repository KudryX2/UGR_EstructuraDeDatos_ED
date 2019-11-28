#ifndef LETRA
#define LETRA

/**
  * @brief T.D.A. Letra
  *
  * Una instancia de la clase agrupa un caracter, es decir letra, las veces que 
  * se repite y los puntos asociados a esa letra. 
  *
  * @author Oleksandr Kudryavtsev
  * @date Diciembre 2018
  */

class Letra{

	char caracter;
	int cantidad,puntuacion;

public:

	/**
	  * @brief Constructor de la clase. Crea la instancia de una letra
	  * con un caracter, cantidad y puntuacion asociados.
	  */
	Letra(char caracter, int cantidad, int puntuacion);
	
	/**
	  * @brief Devuelve el caracter de la letra.
	  * @return caracter asociado.
	  */
	char getCaracter() const;

	/**
	  * @brief Devuelve la cantidad de la que se dispone.
	  * @return cantidad de letras que tenemos.
	  */
	int getCantidad() const;

	/**
	  * @brief Devuelve los puntos que vale la letra.
	  * @return puntos que vale la letra.
	  */
	int getPuntuacion() const;

};


#endif