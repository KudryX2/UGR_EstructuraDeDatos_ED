/*
	Constructor
*/
template <class T>
ColaMax<T>::ColaMax(){

}

/*
	Modificaciones
*/
template <class T>
void ColaMax<T>::poner(T elemento){


	if(pilaInsercion.empty() && pilaModificacion.empty()){
		pilaInsercion.push(make_pair(elemento, elemento));
	
	}else{

		T maximo = elemento;

		if(!pilaInsercion.empty() && pilaInsercion.top().second > maximo){
			maximo = pilaInsercion.top().second;
		}

		if(!pilaModificacion.empty() && pilaModificacion.top().second > maximo){
			maximo = pilaModificacion.top().second;
		}

		pilaInsercion.push(make_pair(elemento, maximo));

	}


}

template <class T>
void ColaMax<T>::quitar(){
	if(!pilaInsercion.empty()){
		rellenarPilaModificacion();
	}

	pilaModificacion.pop();
}

/*
	Consultas
*/
template <class T>
T ColaMax<T>::frente(){
	
	T elemento;

	rellenarPilaModificacion();

	if(!pilaModificacion.empty()){
		elemento = pilaModificacion.top().first;
	}

	return elemento;

}

template <class T>
bool ColaMax<T>::vacia(){
	return (pilaInsercion.empty() && pilaModificacion.empty()); 
} 

template <class T>
T ColaMax<T>::maximo(){
	T maximo = 0;
	
	rellenarPilaModificacion();

	if(!pilaModificacion.empty()){
		if(pilaModificacion.top().second > maximo){
			maximo = pilaModificacion.top().second;
		}
	}

	return maximo;
}

template <class T>
int ColaMax<T>::numElementos(){
	int num = 0;
	num+=pilaInsercion.size();
	num+=pilaModificacion.size();

	return num;
}


/*
	Adiccional
*/
template <class T>
void ColaMax<T>::print(){
	stack<pair<T,T>> aux = pilaModificacion;
	stack<pair<T,T>> auxI = pilaInsercion;

	cout << "Pila inserccion" << endl;
	while(!auxI.empty()){
		cout << auxI.top().first << " " << auxI.top().second << endl;
		auxI.pop();
	}

	cout << "Pila Modificacion" << endl;
	while(!aux.empty()){
		cout << aux.top().first << " " << aux.top().second << endl;
		aux.pop();
	}
	cout << endl;

}

template <class T>
void ColaMax<T>::rellenarPilaModificacion(){

	while(!pilaInsercion.empty()){
		pilaModificacion.push(pilaInsercion.top());
		pilaInsercion.pop();
	}
}




