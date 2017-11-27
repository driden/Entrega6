#include "ComparacionCostoArco.h"

CompRetorno ComparacionCostoArco::Comparar(const CostoArco& t1, const CostoArco& t2) const
{
	nat ciudades1 = t1.ciudades;
	nat distancia1 = t1.distancia;
	nat costo1 = t1.costo;
	nat tiempo1 = t1.tiempo;

	nat ciudades2 = t2.ciudades;
	nat distancia2 = t2.distancia;
	nat costo2 = t2.costo;
	nat tiempo2 = t2.tiempo;


	if (costo1 < costo2) return MENOR;
	if (costo1 > costo2) return MAYOR;

	// Si costo es igual
	if (distancia1 < distancia2) return MENOR; // prefiere el de mayor distancia
	if (distancia1 > distancia2) return MAYOR;

	//si distancia es la misma
	if (tiempo1 < tiempo2) return MENOR;
	if (tiempo1 > tiempo2) return MAYOR;

	//si el tiempo es el mismo
	if (ciudades1 < ciudades2) return MENOR;
	if (ciudades1 > ciudades2) return MAYOR;
	if (ciudades1 == ciudades2) return IGUALES;

	assert(false);
	return DISTINTOS;
}
