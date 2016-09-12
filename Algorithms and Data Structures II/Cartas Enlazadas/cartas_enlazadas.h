#ifndef CARTAS_ENLAZADAS_H_
#define CARTAS_ENLAZADAS_H_

#include <iostream>
#include <cassert>
using namespace std;

/* 
 * Se puede asumir que el tipo T tiene constructor por copia y operator==
 * No se puede asumir que el tipo T tenga operator=
 */
template<typename T>
class CartasEnlazadas {

  public:

	/**
	 * Crea un nuevo juego.
	 */	
	CartasEnlazadas();

	/**
	 * Una vez copiada, ambos juegos deben ser independientes, 
	 * es decir, cuando se borre una no debe borrar la otra.
	 */	
	CartasEnlazadas(const CartasEnlazadas<T>& c);
	
	/**
	 * Acordarse de liberar toda la memoria!
	 */	 
	~CartasEnlazadas();  
	
	/**
	* Agrega un jugador a la mesa. El mismo debe sentarse en la posición 
	* siguiente a la posición del jugador con el mazo azul. Por ejemplo si en la
	* mesa hay 3 jugadores sentados de la siguiente forma: [j1 j2 j3], y el 
	* mazo azul lo tiene el jugador j3, la mesa debe quedar: [j1 j2 j3 j4].
	* PRE: el jugador a agregar no existe.
	*/
	void agregarJugador(const T& Adelanta);
	
	/**
	* j el mazo rojo n posiciones. Por ejemplo: si en la mesa hay 3 
	* jugadores sentados de la siguiente forma: [j1 j2 j3] y el jugador j2
	* tiene el mazo rojo, si se adelanta 1 posicion el mazo rojo pasa al jugador j3. En
	* cambio si el mazo rojo se adelanta 2 posiciones el mazo rojo pasa al jugador j1.
	* En caso de que n sea negativo debe retroceder el mazo rojo -n posiciones.
	* PRE: existe al menos un jugador
	*/
	void adelantarMazoRojo(int n);
	
	/**
	* Adelanta el mazo azul n posiciones. Por ejemplo: si en la mesa hay 3 
	* jugadores sentados de la siguiente forma: [j1 j2 j3] y el jugador j2
	* tiene el mazo azul, si se adelanta 1 posicion el mazo azul pasa al jugador j3. En
	* cambio si el mazo azul se adelanta 2 posiciones el mazo azul pasa al jugador j1.
	* En caso de que n sea negativo debe retroceder el mazo azul -n posiciones.
	* PRE: existe al menos un jugador
	*/
	void adelantarMazoAzul(int n);
	
	/**
	* Devuelve el jugador que tiene el mazo Rojo actualmente.
	* PRE: existe al menos un jugador
	*/
	const T& dameJugadorConMazoRojo() const;
	
	/**
	* Devuelve el jugador que tiene el mazo Azul actualmente.
	* PRE: existe al menos un jugador
	*/
	const T& dameJugadorConMazoAzul() const;
	
	/**
	* Devuelve el jugador que se encuentra n posiciones adelante a la posicion 
	* del jugador con el mazo rojo. En caso de que n sea negativo deberia devolver 
	* el jugador que se encuentra -n posiciones atrás.
	* PRE: existe al menos un jugador
	*/
	const T& dameJugador(int n) const;
	
	/**
	* Devuelve el jugador que se encuentra enfreantado al jugador que tiene el 
	* mazo rojo. Por ejemplo si en la mesa hay cuatros jugadores sentados de la
	* siguiente forma: [J1 J2 J3 J4] y el el jugador J2 tiene el mazo rojo, el
	* resultado debe ser J4.
	* PRE: cantidad de jugadores par, al menos un jugador
	*/
	const T& dameJugadorEnfrentado() const;
	
	/**
	* Elimina el jugador pasado como parámetro.
	* En el caso de que el jugador no exista, el método no debe hacer nada.
	* En el caso de que el jugador tenga algún mazo, se le pasa el mazo al 
	* siguiente jugador en la ronda.
	*/
	void eliminarJugador(const T&);
	
	/**
	* Elimina al jugador que tiene el mazo azul.
	* Por ejemplo si los jugadores estan sentadods de la siguiente forma: 
	* [J1 J2 J3 J4 J5] y el mazo lo tiene el jugador J3. Cuando se eliminan al 
	* jugador con  del mazo, la mesa * debería quedar de la siguiente forma 
	* [J1 J2 J4 J5].
	* En el caso de que algún jugador tenga algún mazo, se le pasa el mazo al 
	* siguiente jugador en la ronda.
	* PRE: al menos un jugador
	*/
	void eliminarJugadorConMazoAzul();
	
	/**
	* Dice si el jugador existe.
	*/
	bool existeJugador(const T&) const;

	/**
	* Le suma los puntos al jugador.
	* PRE: el jugador existe
	*/
	void sumarPuntosAlJugador(const T&, int);
	
	/**
	* Devuelve la cantidad de puntos que tiene el jugador pasado como 
	* parámetro.
	* PRE: el jugador existe
	*/
	int puntosDelJugador(const T&) const;
	
	/**
	* Devuelve al jugador que más puntos tiene.
	* PRE: hay un único jugador que tiene más puntos que todos los demás.
	*/
	const T& ganador() const;
	
	/*
	 * Dice si hay jugadores en la mesa.
	 */
	bool esVacia() const;

	/*
	 * Devuelve la cantidad de jugadores.
	 */
	int tamanio() const;	

	/*
	 * Devuelve true si los juegos son iguales.
	 */
	bool operator==(const CartasEnlazadas<T>&) const;	
	
	/*
	 * Debe mostrar la ronda por el ostream (y retornar el mismo).
	 * CartasEnlazadas vacio: []
	 * CartasEnlazadas con 1 elementos (e1 tiene el mazo azul y el rojo, p es el puntaje): [(e1,p)*]
	 * CartasEnlazadas con 2 elementos (e2 tiene el mazo azul y e1 el mazo rojo, p es el puntaje): [(e2,p), (e1,p)*]
	 * CartasEnlazadas con 3 elementos (e1 tiene el mazo, e3 fue agregado después que e2,
	 * e1 fue agregado antes que e2): [(e1, 0)*, (e3, 0), (e2, 0)]
	 */
	ostream& mostrarCartasEnlazadas(ostream&) const;
  private:
  
	/*
	 * No se puede modificar esta funcion.
	 */
	CartasEnlazadas<T>& operator=(const CartasEnlazadas<T>& otra) {
		assert(false);
		return *this;
	}

	/*
	 * Aca va la implementación del nodo.
	 */
    struct Nodo {
    	Nodo* siguiente;
    	Nodo* anterior;
    	T jugador;
    	int puntos;

    	Nodo(T j)
		: jugador(j)
        {
            siguiente = NULL;
            anterior = NULL;
            puntos = 0;
        }
 		
    };

    Nodo* _mazoRojo;
    Nodo* _mazoAzul;
    int _cantJugadores;

// Funciones Auxiliares:

	const bool pertenece(const T& j) const;
	Nodo* dameNodoJugador(const T& j) const;

};




template<class T>
ostream& operator<<(ostream& out, const CartasEnlazadas<T>& a) {
	return a.mostrarCartasEnlazadas(out);
}


// Implementación a hacer por los alumnos.


template<class T>
CartasEnlazadas<T>::CartasEnlazadas() {
	_mazoRojo = NULL;
	_mazoAzul = NULL;
	_cantJugadores = 0;

}

template<class T>
CartasEnlazadas<T>::CartasEnlazadas(const CartasEnlazadas<T>& c) {
	_mazoRojo = NULL;
	_mazoAzul = NULL;
	_cantJugadores = 0;

	if (c._cantJugadores > 0) {

		agregarJugador(c._mazoAzul->jugador);
		_mazoAzul->puntos = c._mazoAzul->puntos;

		Nodo* pos = c._mazoAzul->anterior;

		while (pos != c._mazoAzul) {	
			agregarJugador(pos->jugador);
			sumarPuntosAlJugador(pos->jugador, pos->puntos);
			pos = pos->anterior;
		}

		_mazoRojo = dameNodoJugador(c._mazoRojo->jugador);		
		_mazoAzul = dameNodoJugador(c._mazoAzul->jugador);
		_cantJugadores = c._cantJugadores;
	}
}

template<class T>
CartasEnlazadas<T>::~CartasEnlazadas() {
	if (_cantJugadores > 0) {

		Nodo*  borrame = _mazoAzul->siguiente;

		while (borrame!= _mazoAzul) {
			eliminarJugador(borrame->jugador);
			borrame = _mazoAzul->siguiente;
		}

	 delete _mazoAzul;
	 _mazoRojo = NULL;
	}
}

template<class T>
void CartasEnlazadas<T>::agregarJugador(const T& j) {
	Nodo* nuevo = new Nodo(j);
	nuevo->puntos = 0;

	if (_cantJugadores == 0) {  // Primero pongo al azul
		_mazoAzul = nuevo;
		_mazoRojo = nuevo;
		nuevo->siguiente = nuevo;
		nuevo->anterior = nuevo;		
	} else if (_cantJugadores == 1) { // Después del azul, pongo al último del círculo
		nuevo->siguiente = _mazoAzul;
		nuevo->anterior = _mazoAzul;
		_mazoAzul->siguiente = nuevo;
		_mazoAzul->anterior = nuevo;
	} else { // Los siguientes que agrego, van entre el último y el azul.
		nuevo->siguiente = _mazoAzul->siguiente;
		nuevo->anterior = _mazoAzul;
		_mazoAzul->siguiente->anterior = nuevo;
		_mazoAzul->siguiente = nuevo;
	}
	_cantJugadores++;
}

template<class T>
void CartasEnlazadas<T>::adelantarMazoRojo(int n) {
	if (n > 0) { // Si es > 0, lo adelanto. Si no, retrocede.
		for (int i = 0; i < n; i++) {
			_mazoRojo = _mazoRojo->siguiente;
		}
	} 

	if (n < 0) {
		for (int i = 0; i > n; i--) {
			_mazoRojo = _mazoRojo->anterior;
		}

	}

}

template<class T>
void CartasEnlazadas<T>::adelantarMazoAzul(int n) {
	if (n > 0) { // Si es > 0, lo adelanto. Si no, retrocede.
		for (int i = 0; i < n; i++) {
			_mazoAzul = _mazoAzul->siguiente;
		}
	} 

	if (n < 0) {
		for (int i = 0; i > n; i--) {
			_mazoAzul = _mazoAzul->anterior;
		}

	}	

}

template<class T>
const T& CartasEnlazadas<T>::dameJugadorConMazoRojo() const {
	return _mazoRojo->jugador;
}

template<class T>
const T& CartasEnlazadas<T>::dameJugadorConMazoAzul() const {
	return _mazoAzul->jugador;
}

template<class T>
const T& CartasEnlazadas<T>::dameJugador(int n) const {
	Nodo* nodo = _mazoRojo;
	if (n > 0) { // Si es > 0, lo adelanto. Si no, retrocede.
		for (int i = 0; i < n; i++) {
			nodo = _mazoRojo->siguiente;
		}
	} 

	if (n < 0) {
		for (int i = 0; i > n; i--) {
			nodo = _mazoRojo->anterior;
		}

	}

	return nodo->jugador;	
}

template<class T>
const T& CartasEnlazadas<T>::dameJugadorEnfrentado() const {
	// El enfrentado, va a estar n/2 posiciones adelante.
	Nodo* enfrentado = _mazoRojo;

	for (int i = 0; i < _cantJugadores/2; i++) {
			enfrentado = enfrentado->siguiente;
		}

	return enfrentado->jugador;
}

template<class T>
void CartasEnlazadas<T>::eliminarJugador(const T& j) {
	if (existeJugador(j)) {

		Nodo* eliminame = dameNodoJugador(j);
		if (eliminame == _mazoAzul && _cantJugadores > 1) _mazoAzul = eliminame->siguiente;
		if (eliminame == _mazoRojo && _cantJugadores > 1) _mazoRojo = eliminame->siguiente;

		eliminame->anterior->siguiente = eliminame->siguiente;  // Ahora, el siguiente del anterior a "Eliminame", es quien era el siguiente de "Eliminame".
		eliminame->siguiente->anterior = eliminame->anterior; // Ahora, el anterior del siguiente de "Eliminame", es quien era el anterior de "Eliminame".

		delete eliminame;
		_cantJugadores--;
	
	}

}

template<class T>
void CartasEnlazadas<T>::eliminarJugadorConMazoAzul() {
	eliminarJugador(_mazoAzul->jugador);
}

template<class T>
bool CartasEnlazadas<T>::existeJugador(const T& j) const {
	bool encontrado = false;
	Nodo* pos = _mazoAzul;

	for (int i = 0; i < _cantJugadores && !encontrado; i++) {
			if (pos->jugador == j) encontrado = true;
			pos = pos->siguiente;
	}	

	return encontrado;
}

template<class T>
void CartasEnlazadas<T>::sumarPuntosAlJugador(const T& j, int n) {
	Nodo* jugador = dameNodoJugador(j);
	jugador->puntos = jugador->puntos + n;
}

template<class T>
int CartasEnlazadas<T>::puntosDelJugador(const T& j) const {
	Nodo* jugador = dameNodoJugador(j);
	return jugador->puntos;
}

template<class T>
const T& CartasEnlazadas<T>::ganador() const {
	Nodo* ganador = _mazoAzul;
	Nodo* pos = _mazoAzul;

	for (int i = 0; i < _cantJugadores; i++) {
			if (ganador->puntos > pos->puntos) ganador = pos;
			pos = pos->siguiente;
	}	

	return ganador->jugador;	

}

template<class T>
bool CartasEnlazadas<T>::esVacia() const {
	return _cantJugadores == 0;

}

template <class T>
int CartasEnlazadas<T>::tamanio() const {
	return _cantJugadores;
}

template<class T>
bool CartasEnlazadas<T>::operator==(const CartasEnlazadas<T>& c) const {
	bool mismosJugadores;
	bool mismaCantidad = _cantJugadores == c._cantJugadores;
	bool mismosMazos;
	bool result = mismaCantidad;

	if (!esVacia() && !c.esVacia() && mismaCantidad) {
		mismosMazos = _mazoAzul->jugador == c._mazoAzul->jugador && 
					  _mazoRojo->jugador == c._mazoRojo->jugador &&
					  _mazoAzul->puntos == c._mazoAzul->puntos && 
					  _mazoRojo->puntos == c._mazoRojo->puntos;		
		
		bool nodosIguales = mismosMazos;

		Nodo* pos_1 = _mazoAzul->siguiente;
		Nodo* pos_2 = c._mazoAzul->siguiente;

		while (mismosMazos && pos_1 != _mazoAzul && pos_2 != c._mazoAzul) {
			nodosIguales = pos_1->jugador == pos_2->jugador &&
						   pos_1->puntos == pos_2->puntos;

			pos_1 = pos_1->siguiente;
			pos_2 = pos_2->siguiente;

		}

		result = mismosMazos && nodosIguales;
	}


	return result;
}

template<class T>
ostream& CartasEnlazadas<T>::mostrarCartasEnlazadas(ostream& os) const {

if (_cantJugadores == 0) os << "[]";

else {
	Nodo* pos = _mazoAzul;
	os << "[("<<pos->jugador<<", " <<pos->puntos<<")";
	if (pos == _mazoRojo) { os <<"*"; }
	
	pos = pos->siguiente;

	while (pos != _mazoAzul) {
		os << ", ("<<pos->jugador<<", " <<pos->puntos<<")";
		if (pos == _mazoRojo) { os <<"*"; }
		pos = pos->siguiente;
	}	
	os << "]";
}


}

// Funciones auxiliares:

template <class T>
const bool CartasEnlazadas<T>::pertenece(const T& c) const{
	bool result;
	
	if (!esVacia()) {
		Nodo* pos = _mazoAzul;

		for (int i = 0; i < _cantJugadores && !result; i++) {
			if (c == pos->jugador) result = true;
			pos = pos->siguiente;
		}	

	}

	return result;
}


template <class T>
typename CartasEnlazadas<T>::Nodo* CartasEnlazadas<T>::dameNodoJugador(const T& c) const{
	Nodo* result = _mazoAzul;

	while (!(result->jugador == c)) { result = result->siguiente; }

	return result;

}


#endif //CARTAS_ENLAZADAS_H_