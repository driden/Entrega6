#include "EjercicioGranja.h"
#include "Mochila.h"

Array<nat> EjercicioGranja::Resolver()
{
	CapacidadGranja capacidadInicial(maxDinero, maxTierra, maxAgua);
	Array<int> solucionActual(semillas.Largo);
	Array<int> solucionOptimo(semillas.Largo);
	int valorRef;
	Resolver(capacidadInicial, semillas.Largo - 1, solucionActual, solucionOptimo, 0, valorRef, peso, valor, cantidad);

	Array<nat> cantidades(semillas.Largo);
	for (nat i = 0; i < cantidades.Largo; i++)
		cantidades[i] = solucionOptimo[i];

	return cantidades;
}

void EjercicioGranja::Resolver(CapacidadGranja capacidad, int objectoActual, Array<int> solucionActual,
	Array<int> &solucionOptima, int valorActual, int& valorOptimo, Array<CapacidadGranja> peso, Array<int> valor,
	Array<int> cantidad)
{
	Mochila<CapacidadGranja> mochila = Mochila<CapacidadGranja>();
	mochila.MochilaBT(capacidad, objectoActual, solucionActual, solucionOptima, valorActual, valorOptimo, peso, valor, cantidad);
}
