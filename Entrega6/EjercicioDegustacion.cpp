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

void EjercicioDegustacion::Resolver(CapacidadDegustacion capacidad, int objectoActual, Array<int> solucionActual,
	Array<int> solucionOptima, int valorActual, int& valorOptimo, Array<int> peso, Array<int> valor, Array<int> cantidad)
{
	Mochila<CapacidadDegustacion> ejmochila();
	ejmochila().MochilaBT(capacidad, objectoActual, solucionActual, solucionOptima, valorActual, valorOptimo, peso, valor, cantidad);

}
#endif
