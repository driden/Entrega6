#pragma once
#include "HashAbiertoImpl.h"

#define INFINITO 100000

template <class Capacidad>
class Coordenada {
public:
	Coordenada(Capacidad c, int o) {
		cap = c;
		objetoHasta = o;
	}
	Capacidad cap;
	int objetoHasta;

	bool operator==(const Coordenada<Capacidad>& c) const {
		return cap == c.cap && objetoHasta == c.objetoHasta;
	}
};

template <class Capacidad>
class Mochila
{
public:
	Mochila()
	{
		
	}
	~Mochila(){}

	void MochilaBT(Capacidad capacidad, int objectoActual, Array<int> solucionActual, Array<int> solucionOptima,
	               int valorActual, int& valorOptimo, Array<Capacidad> peso, Array<int> valor, Array<int> cantidad);

	//int ValorMochila(Capacidad capacidad, int objetoHasta, Array<Capacidad> peso, Array<int> valor,
	//                 Puntero<Tabla<Coordenada<Capacidad>, int>> bdMochila);
private:
	bool FueCalculado(Capacidad capcidad, int objetoHasta, Puntero<Tabla<Coordenada<Capacidad>, int>> bdMochila);
	bool EncontreUnaSolucionMejor(const int valorActual, const int valorOptimo);
	bool Termine(const int objetoActual);
};

#include "Mochila.cpp"

