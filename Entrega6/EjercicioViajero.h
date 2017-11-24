#pragma once
#include <cassert>
#include "Array.h"
#include "ICiudad.h"
#include "Matriz.h"
#include "GrafoListaAdy.h"

class EjercicioViajero
{
public:
	~EjercicioViajero();
	EjercicioViajero() { assert(false); }
	EjercicioViajero(
		Array<Puntero<ICiudad>> &ciudadesDelMapa, 
		Matriz<nat> &mapa, 
		Puntero<ICiudad> &ciudadPartida, 
		Iterador<Puntero<ICiudad>> ciudades, nat costo);

	void Resolver(Puntero<Lista<ICiudad>> &camino, nat costo, nat costoSolucion, Puntero<Lista<ICiudad>> &caminoSolucion);
private:
	Puntero<Grafo<Puntero<ICiudad>, nat>> grafo;
	nat costoMax;
	Iterador<Puntero<ICiudad>> ciudadesPasar;
	Puntero<ICiudad> ciudadPart;
	Comparador<Puntero<ICiudad>> comparadorV;
};

