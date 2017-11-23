#include "EjercicioProtectoraAnimales.h"
#include "Mochila.h"

EjercicioProtectoraAnimales::~EjercicioProtectoraAnimales()
{
}

EjercicioProtectoraAnimales::EjercicioProtectoraAnimales(Array<Accion> acciones, int maxVeterinarios, int maxVehiculos,
	int maxDinero, int maxVacunas, int maxVoluntarios)
{
	capacidadOriginal = CapacidadProtectora(maxVeterinarios, maxVehiculos, maxDinero, maxVacunas, maxVoluntarios);
	peso= Array<CapacidadProtectora>(acciones.Largo);
	valor = Array<int>(acciones.Largo);
	cantidad = Array<int>(acciones.Largo);

	for (nat i = 0; i < acciones.Largo; i++)
	{
		Accion a = acciones[i];
		peso[i] = CapacidadProtectora(a.veterinarios,a.vehiculos,a.dinero,a.vacunas,a.voluntarios);
		valor[i] = a.impacto;
		cantidad[i] = (maxDinero/a.dinero);
	}
}

Array<nat> EjercicioProtectoraAnimales::Resolver()
{
	int objActual = cantidad.Largo - 1;
	Array<int> solActual(cantidad.Largo, 0);
	Array<int> solOptima(cantidad.Largo, 0);
	int valorOptimo = -1;
	Resolver(capacidadOriginal, objActual, solActual, solOptima, 0, valorOptimo, peso, valor, cantidad);

	Array<nat> cantidades(cantidad.Largo);
	for (nat i = 0; i < cantidades.Largo; i++)
		cantidades[i] = solOptima[i];

	return cantidades;
}

void EjercicioProtectoraAnimales::Resolver(CapacidadProtectora capacidad, int objectoActual, Array<int> solucionActual,
	Array<int> solucionOptima, int valorActual, int& valorOptimo, Array<CapacidadProtectora> peso, Array<int> valor,
	Array<int> cantidad)
{
	Mochila<CapacidadProtectora> mochilaProtectora = Mochila<CapacidadProtectora>();
	mochilaProtectora.MochilaBT(capacidad, objectoActual, solucionActual, solucionOptima, 
		valorActual, valorOptimo, peso, valor, cantidad);

}
