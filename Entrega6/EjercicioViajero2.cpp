#include "EjercicioViajero2.h"
#include "GrafoListaAdy.h"
#include "NaturalFuncionHash.h"
#include "Dijkstra.h"
#include "ComparacionCostoArco.h"

EjercicioViajero2::EjercicioViajero2(Matriz<Tupla<nat, nat, nat>> relacionesCiudades, Iterador<nat> CiudadesPasar,
	Iterador<nat> CiudadesNoPasar)
{
	itPasar = CiudadesPasar;
	itNoPasar = CiudadesNoPasar;
	Puntero<FuncionHash<nat>> fHash = new NaturalFuncionHash();
	grafo = new GrafoListaAdy<nat, Tupla<nat, nat, nat>>(relacionesCiudades.Largo, fHash, Comparador<nat>::Default);

	for (nat i = 0; i < relacionesCiudades.Largo; i++)
	{
		grafo->AgregarVertice(i);
	}

	for (nat i = 0; i < relacionesCiudades.Largo; i++)
		for (nat j = 0; j < relacionesCiudades.Ancho; j++)
		{
			Tupla<nat, nat, nat> t = relacionesCiudades[i][j];
			if (t.Dato1 != 0 || t.Dato2 != 0 || t.Dato3 != 0)
				grafo->AgregarArco(i, j, t);
		}
}

bool EjercicioViajero2::SePuedePasarPorEstaCiudad(const nat ciudad)
{
	itNoPasar.Reiniciar();
	bool sePuede = true;

	while (itNoPasar.HayElemento())
	{
		if (ciudad == itNoPasar.ElementoActual())
		{
			sePuede = false;
			break;
		}
		itNoPasar.Avanzar();
	}

	itNoPasar.Reiniciar();
	return sePuede;
}

bool EjercicioViajero2::PasePorTodasLasCiudades(Iterador<nat> ciudades, Array<bool> visitadas)
{
	ciudades.Reiniciar();

	foreach(nat ciudad, ciudades)
	{
		if (!visitadas[ciudad]) return false;
	}
	itNoPasar.Reiniciar();
	return true;
}

CostoArco CalcularCosto(Puntero<Grafo<nat, Tupla<nat, nat, nat>>> grafo, int vO, int vD)
{
	assert(grafo->ExisteArco(vO, vD));
	Tupla<nat, nat, nat> t = grafo->ObtenerArco(vO, vD);
	nat costo = t.ObtenerDato1();
	nat distancia = t.ObtenerDato2();
	nat tiempo = t.ObtenerDato3();
	return CostoArco(costo, distancia, tiempo, 1);
}

Iterador<nat> EjercicioViajero2::CaminoMasCorto(nat vO, nat vD)
{
	Puntero<Comparacion<CostoArco>> pComp = new ComparacionCostoArco();
	Comparador<CostoArco> compArco(pComp);
	Puntero<FuncionHash<nat>> natHash = new NaturalFuncionHash();
	Array<nat> ciudadesNoVisitar = Ciudades(itNoPasar);
	Dijkstra<nat, Tupla<nat, nat, nat>, CostoArco> dijkstra(grafo, compArco, Comparador<nat>::Default, natHash, &CalcularCosto, ciudadesNoVisitar);

	return dijkstra.CaminoMasCorto(vO, vD);

}

Array<nat> EjercicioViajero2::Ciudades(Iterador<nat> itPasar)
{
	nat largo = 0;
	itPasar.Reiniciar();
	while (itPasar.HayElemento())
	{
		largo++;
		itPasar.Avanzar();
	}
	itPasar.Reiniciar();

	Array<nat> arr(largo);

	for (nat i = 0; i < largo; i++)
	{
		arr[i] = itPasar.ElementoActual();
		itPasar.Avanzar();
	}
	itPasar.Reiniciar();

	return arr;
}

Iterador<nat> EjercicioViajero2::Recorrer()
{
	Array<nat> ciudadesVisitar = Ciudades(itPasar);
	Array<bool> visitadas(grafo->CantidadVertices(), false);
	Puntero<Lista<nat>> pLista = new ListaEncadenada<nat>();

	nat i = 0;

	while (!PasePorTodasLasCiudades(itPasar, visitadas))
	{
		Iterador<nat> it = CaminoMasCorto(ciudadesVisitar[i], ciudadesVisitar[i + 1]);

		while (it.HayElemento())
		{
			nat vActual = it.ElementoActual();
			pLista->Insertar(vActual);
			visitadas[vActual] = true;

			it.Avanzar();
		}

		i++;
	}

	return pLista->ObtenerIterador();
}
