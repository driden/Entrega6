#pragma once
#include "Array.h"
#include "Tupla.h"
#include "CapacidadGranja.h"

class EjercicioGranja
{
public:
	~EjercicioGranja() {}
	EjercicioGranja(
		Array<Tupla<nat, nat, nat>> sem = Array<Tupla<nat, nat, nat>>(0), 
		int D = 0, 
		int T = 0, 
		int A = 0
	)
	{
		semillas = sem;
		maxDinero = D;
		maxTierra = T;
		maxAgua = A;

		peso = Array<CapacidadGranja>(semillas.Largo);
		valor = Array<int>(semillas.Largo);
		cantidad = Array<int>(semillas.Largo, semillas.Largo);
		for (nat i = 0; i < semillas.Largo; i++)
		{
			Tupla<nat, nat, nat> t = semillas[i];
			int costo = t.ObtenerDato1();
			int agua = t.ObtenerDato2();
			int ganancia = t.ObtenerDato3();

			CapacidadGranja cg(costo, 1, agua);
			peso[i] = cg;

			valor[i] = ganancia;
		}
	}

	Array<nat> Resolver();

private:
	void Resolver(CapacidadGranja capacidad, int objectoActual, Array<int> solucionActual, Array<int>& solucionOptima,
	              int valorActual, int& valorOptimo, Array<CapacidadGranja> peso, Array<int> valor, Array<int> cantidad);


	Array<CapacidadGranja> peso;
	Array<int> valor;
	Array<int> cantidad;

	Array<Tupla<nat, nat, nat>> semillas;
	int maxDinero;
	int maxTierra;
	int maxAgua;
};

