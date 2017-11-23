#pragma once
#include "Array.h"
#include "Producto.h"
#include "CapacidadDegustacion.h"


class EjercicioDegustacion
{
public:
	EjercicioDegustacion(Array<Producto> productos, nat maxDinero, nat maxCalorias, nat maxAlcohol);

	~EjercicioDegustacion(){}
	Array<nat> Resolver();
private:
	CapacidadDegustacion capacidadOriginal;
	Array<CapacidadDegustacion> peso;
	Array<int> valor;
	Array<int> cantidad;
	void Resolver(CapacidadDegustacion capacidad, int objectoActual, Array<int> solucionActual, Array<int> solucionOptima,
		int valorActual, int& valorOptimo, Array<CapacidadDegustacion> peso, Array<int> valor, Array<int> cantidad);
	
};
