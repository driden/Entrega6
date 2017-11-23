#pragma once
#include "ISistema.h"
#include "CapacidadProtectora.h"

class EjercicioProtectoraAnimales
{
public:
	~EjercicioProtectoraAnimales();
	EjercicioProtectoraAnimales(Array<Accion> acciones, int maxVeterinarios, int maxVehiculos,
		int maxDinero, int maxVacunas, int maxVoluntarios);
	
	Array<nat> Resolver();

private:
	CapacidadProtectora capacidadOriginal;
	Array<CapacidadProtectora> peso;
	Array<int> valor;
	Array<int> cantidad;
	void Resolver(CapacidadProtectora capacidad, int objectoActual, Array<int> solucionActual, Array<int> solucionOptima,
		int valorActual, int& valorOptimo, Array<CapacidadProtectora> peso, Array<int> valor, Array<int> cantidad);
};

