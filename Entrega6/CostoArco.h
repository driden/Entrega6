#pragma once
#include "Sistema.h"

#ifndef INFINITO
#define INFINITO 100000
#endif
class CostoArco
{
public:
	CostoArco(nat costo = INFINITO, nat distancia = 0, nat tiempo = INFINITO, nat ciudades = INFINITO);
	~CostoArco();

	static CostoArco Cero();

	static CostoArco Infinito();

	CostoArco operator+(const CostoArco& c) const
	{
		CostoArco ret(costo + c.costo, distancia + c.distancia, tiempo + c.tiempo, ciudades+c.ciudades);
		return ret;
	}
	
	nat costo, distancia, tiempo, ciudades;
	
};

inline ostream& operator<<(ostream& out, const CostoArco& c)
{
	return out;
}