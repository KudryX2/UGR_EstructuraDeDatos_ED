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

	if(cola.empty()){
		cola.push_back(make_pair(elemento,elemento));	
	
	}else{
		if(cola[0].second > elemento){
			cola.insert(cola.begin(), make_pair(elemento,cola[0].second));
		}else{
			actualizarMaximo(elemento);
			cola.insert(cola.begin(), make_pair(elemento,elemento));
		}

	}
	

}

template <class T>
void ColaMax<T>::quitar(){
	cola.pop_back();
	actualizarMaximo();
}

template <class T>
void ColaMax<T>::actualizarMaximo(){

	T maximo = cola[0].first;

	for(unsigned int i = 0 ; i < cola.size() ; ++i){
		if(cola[i].first > maximo)
			maximo = cola[i].first;
	}

	actualizarMaximo(maximo);

}

template <class T>
void ColaMax<T>::actualizarMaximo(T maximo){

	for(unsigned int i = 0 ; i < cola.size() ; ++i){
		cola[i].second = maximo;
	}

}

/*
	Consultas
*/
template <class T>
T ColaMax<T>::frente(){
	return cola[cola.size()-1].first;
}

template <class T>
bool ColaMax<T>::vacia(){
	return cola.empty();
}

template <class T>
T ColaMax<T>::maximo(){
	return cola[0].second;
}

template <class T>
int ColaMax<T>::numElementos(){
	return cola.size();
}

/*
	Adiccional
*/
template <class T>
void ColaMax<T>::print(){
	for(unsigned int i = 0 ; i < cola.size() ; ++i){
		cout << cola[i].first << " " << cola[i].second << endl;
	}
	cout << endl;
}


