#ifndef  EJERCICIO_DEGUSTACION_CPP
#define EJERCICIO_DEGUSTACION_CPP

#include "EjercicioDegustacion.h"
#include "Mochila.h"

EjercicioDegustacion::EjercicioDegustacion(Array<Producto> productos, nat maxDinero, nat maxCalorias,
	nat maxAlcohol)
{
	peso = Array<CapacidadDegustacion>(productos.Largo);
	valor = Array<int>(productos.Largo);
	cantidad = Array<int>(productos.Largo);

	for (nat i = 0; i < productos.Largo; i++)
	{
		Producto p = productos[i];
		peso[i] = CapacidadDegustacion(p.alcohol, p.precio, p.calorias);
		valor[i] = p.preferencia;
		cantidad[i] = p.maxUnidades;
	}

	capacidadOriginal = CapacidadDegustacion(maxAlcohol, maxDinero, maxCalorias);
}

Array<nat> EjercicioDegustacion::Resolver()
{
	int objActual = cantidad.Largo - 1;
	Array<int> solActual(cantidad.Largo,0);
	Array<int> solOptima(cantidad.Largo,0);
	int valorOptimo = -1;
	Resolver(capacidadOriginal, objActual, solActual, solOptima, 0, valorOptimo, peso, valor, cantidad);

	Array<nat> cantidades(cantidad.Largo);
	for (nat i = 0; i < cantidades.Largo; i++)
		cantidades[i] = solOptima[i];

	return cantidades;
}

void EjercicioDegustacion::Resolver(CapacidadDegustacion capacidad, int objectoActual, Array<int> solucionActual,
	Array<int> solucionOptima, int valorActual, int& valorOptimo, Array<CapacidadDegustacion> peso, Array<int> valor, Array<int> cantidad)
{
	Mochila<CapacidadDegustacion> ejmochila = Mochila<CapacidadDegustacion>();
	ejmochila.MochilaBT(capacidad, objectoActual, solucionActual, solucionOptima, valorActual, valorOptimo, peso, valor, cantidad);

}
#endif
