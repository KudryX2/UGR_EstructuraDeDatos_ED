/*
	Constructores de la clase
*/
template <class T>
Array<T>::Array(){
	tam = 0;
}

template <class T>
Array<T>::Array(int tam){
	this->tam = tam;
	array = new T[tam];
}

template <class T>
Array<T>::Array(const Array<T>& array){
	tam = array.getSize();
	this->array = new T[tam];

	T* p = this->array;
	T* p2 = array.getArray();
	int i;

	for(i = 0 ; i < tam ; ++i){
		*p = *p2;
		p++;
		p2++;
	}
}

template <class T>
Array<T>::Array(const Array<T>& array, int ini, int fin){
	tam = fin-ini;
	this->array = new T[tam];

	T* p = this->array;
	T* p2 = array.getArray();
	p2+=ini;
	int i;

	for(i = 0 ; i < tam ; ++i){
		*p = *p2;
		p++;
		p2++;
	}
}

/*
	Destructor de la clase
*/
template <class T>
Array<T>::~Array(){

	if(tam > 0){
		delete [] array;
	}

}

/*
	Metodos para modificar el array
*/
template <class T>
void Array<T>::add(T elemento){
		
	T* arrayNuevo = new T[tam+1];

	for(int i = 0 ; i < tam ; ++i){
		arrayNuevo[i] = array[i];
	}

	arrayNuevo[tam] = elemento;
	tam++; 

	array = arrayNuevo;	
}

template <class T>
void Array<T>::set(T elemento, int index){

	if(index < tam){
		array[index] = elemento;
	}

}

template <class T>
void Array<T>::erasePosicion(int posicion){

	T* arrayNuevo = new T[tam];

	for(int i = 0 ; i < tam ; ++i){
		
		if(i < posicion){
			arrayNuevo[i] = array[i];
		}else{
			arrayNuevo[i] = array[i+1];	
		}
		
	}
	delete[] array;
	tam--;

	array = arrayNuevo;

}

template <class T>
void Array<T>::eraseElemento(T elemento){

	for(int i = 0 ; i < tam ; ++i){
		if(array[i] == elemento){
			erasePosicion(i);
			i = tam;
		}
	}

}

template <class T>
void Array<T>::clear(){
	array = new T[1];
	tam = 0;
}


/*
	Getters
*/
template <class T>
int Array<T>::getSize() const{
	return tam;
}

template <class T>
T* Array<T>::getArray() const{
	return array;
}

template <class T>
T* Array<T>::get(int index){
	return &array[index];
}

/*
	Metodos adiccionales
*/
template <class T>
void Array<T>::print(){

	cout << endl;
	for(int i = 0 ; i < tam ; ++i){
		cout << array[i] << endl;
	}
	cout << endl;

}
