#ifndef MOCHILA_CPP_
#define MOCHILA_CPP_
#include "Mochila.h"
#include <algorithm>

template<class Capacidad>
bool Mochila<Capacidad>::FueCalculado(Capacidad capacidad, int objetoHasta, 
	Puntero<Tabla<Coordenada<Capacidad>, int>> bdMochila) 
{
	Coordenada<Capacidad> co(capacidad, objetoHasta);
	return bdMochila->EstaDefinida(co);
}


//template <class Capacidad>
//int Mochila<Capacidad>::ValorMochila(Capacidad capacidad, int objetoHasta, Array<Capacidad> peso, Array<int> valor,
//	Puntero<Tabla<Coordenada<Capacidad>, int>> bdMochila)
//{
//	Coordenada<Capacidad> co(capacidad, objetoHasta);
//	if (capacidad.EsMenorQueCero()) return -INFINITO;
//	if (objetoHasta < 0) return 0;
//	if (!FueCalculado(capacidad, objetoHasta, bdMochila))
//	{
//		int incluyendo = valor[objetoHasta] + ValorMochila(capacidad - peso[objetoHasta], objetoHasta - 1, peso, valor);
//		int noIncluyendo = ValorMochila(capacidad, objetoHasta - 1, peso, valor);
//		assert(!bdMochila->EstaDefinido(co));
//			bdMochila->Agregar(co, max(incluyendo, noIncluyendo));
//	}
//	assert(!bdMochila->EstaDefinida(co));
//		return bdMochila->Obtener(co);
//
//}

bool EncontreUnaSolucionMejor(const int valorActual, const int valorOptimo)
{
	return valorActual > valorOptimo;
}

bool Termine(const int objetoActual)
{
	return objetoActual < 0;
}

template <class Capacidad>
void Mochila<Capacidad>::MochilaBT(Capacidad capacidad, int objectoActual, Array<int> solucionActual,
	Array<int> solucionOptima, int valorActual, int &valorOptimo, Array<int> peso, Array<int> valor, Array<int> cantidad)
{
	if (Termine(objectoActual))
	{
		if (EncontreUnaSolucionMejor(valorActual, valorOptimo))
		{
			//Array<int> solucion(cantidad.Largo);
			Array<int>::Copiar(solucionActual, solucionOptima);
			//copiar(solucionActual, solucionOptima);
			valorOptimo = valorActual;
		}
	}
	else {
		for (int k = 0; k <= cantidad[objectoActual]; k++)
		{
			Capacidad capacidadAux = capacidad - k * peso[objectoActual];
			int valorAux = valorActual + k* valor[objectoActual];

			if (capacidadAux.EsMenorQueCero()) break;

			solucionActual[objectoActual] = k;
			MochilaBT(capacidadAux, objectoActual - 1, solucionActual, solucionOptima, valorAux, valorOptimo, peso, valor,cantidad);
		}
	}
}

#endif
