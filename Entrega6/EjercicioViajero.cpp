#include "EjercicioViajero.h"
#include "ComparacionPunteroICiudad.h"
#include "HashICiudad.h"

EjercicioViajero::~EjercicioViajero()
{
}

EjercicioViajero::EjercicioViajero(Array<Puntero<ICiudad>>& ciudadesDelMapa, Matriz<nat>& mapa,
	Puntero<ICiudad>& ciudadPartida, Iterador<Puntero<ICiudad>> ciudades, nat costo)
{
	Puntero<Comparacion<Puntero<ICiudad>>> pComparacion = new ComparacionPunteroICiudad();
	comparadorV = Comparador<Puntero<ICiudad>>(pComparacion);

	Puntero<FuncionHash<Puntero<ICiudad>>> fHash = new HashICiudad();

	grafo = new GrafoListaAdy<Puntero<ICiudad>, nat>(ciudadesDelMapa.Largo, fHash, pComparacion);

	for (nat c = 0; c < ciudadesDelMapa.Largo; c++)
		grafo->AgregarVertice(ciudadesDelMapa[c]);

	for (nat x = 0; x < mapa.Largo; x++)
		for (nat y = 0; y < mapa.Ancho; y++)
		{
			Puntero<ICiudad> desde = ciudadesDelMapa[x];
			Puntero<ICiudad> hasta = ciudadesDelMapa[y];

			grafo->AgregarArco(desde, hasta, mapa[x][y]);
		}


	costoMax = costo;
	ciudadesPasar = ciudades;
	ciudadPart = ciudadPartida;
}

void EjercicioViajero::Resolver(Puntero<Lista<ICiudad>>& camino, nat costo, nat costoSolucion,
	Puntero<Lista<ICiudad>>& caminoSolucion)
{
}




