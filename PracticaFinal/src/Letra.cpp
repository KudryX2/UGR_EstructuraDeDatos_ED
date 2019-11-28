#include "Letra.h"

Letra::Letra(char caracter, int cantidad, int puntuacion){
	this->caracter = caracter;
	this->cantidad = cantidad;
	this->puntuacion = puntuacion;
}

char Letra::getCaracter() const{
	return caracter;
}

int Letra::getCantidad() const{
	return cantidad;
}

int Letra::getPuntuacion() const{
	return puntuacion;
}