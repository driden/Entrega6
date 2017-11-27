#pragma once
#include "Matriz.h"
#include "Tupla.h"
#include "Grafo.h"
#include "CostoArco.h"

class EjercicioViajero2
{
public:
	EjercicioViajero2(Matriz<Tupla<nat, nat, nat>> relacionesCiudades, Iterador<nat> CiudadesPasar, Iterador<nat> CiudadesNoPasar);
	Iterador<nat> Recorrer();
private:
	Iterador<nat> itPasar;
	Iterador<nat> itNoPasar;

	Puntero<Grafo<nat, Tupla<nat,nat,nat>>> grafo;

	// PRE:
	// POS: devuelve true sii se puede pasar por esta ciudad
	bool SePuedePasarPorEstaCiudad(const nat ciudad);

	// PRE:
	// POS: devuelve true sii ya visite todas las ciudades que queria visitar
	bool PasePorTodasLasCiudades(Iterador<nat> ciudades, Array<bool> visitadas);

	// PRE: Existe un camino entre vO y vD
	// POS: devuelve el camino mas barato entre los dos vertices
	Iterador<nat> CaminoMasCorto(nat vO, nat vD);

	// PRE:
	// POS: Devuelve la lista de ciudades a visitar
	Array<nat> Ciudades(Iterador<nat> itPasar);
	
	
	
};
