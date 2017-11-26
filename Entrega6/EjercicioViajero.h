#pragma once
#include <cassert>
#include "Array.h"
#include "ICiudad.h"
#include "Matriz.h"
#include "GrafoListaAdy.h"

//#ifndef DEBUG_VIAJERO
//#define DEBUG_VIAJERO
//#endif
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


	Iterador<Iterador<Puntero<ICiudad>>> Resolver();
	


private:
	Puntero<Grafo<Puntero<ICiudad>, nat>> grafo;
	nat costoMax;
	Iterador<Puntero<ICiudad>> ciudadesPasar;
	Puntero<ICiudad> ciudadPart;
	Comparador<Puntero<ICiudad>> comparadorV;
	nat cantVertices;

	void ImprimirDatos(const Puntero<ICiudad>& puntero, const Puntero<Lista<Puntero<ICiudad>>>& camino, nat costo, nat costo_max);
	void Resolver(Puntero<ICiudad> ciudadActual, Puntero<Lista<Puntero<ICiudad>>>& camino,
	              Puntero<Lista<Puntero<Lista<Puntero<ICiudad>>>>>& caminoSolucion, nat costo, nat& costoSolucion,
	              nat cantCiudadesVisitadas, nat& cantCiudadesSolucion, Array<bool> visitados,
	              Array<Puntero<ICiudad>> ciudades);


	Iterador<Iterador<Puntero<ICiudad>>> Solucionar(Puntero<Lista<Puntero<Lista<Puntero<ICiudad>>>>> sol);
};

