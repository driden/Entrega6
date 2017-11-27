#include "CostoArco.h"


CostoArco::CostoArco(nat costo, nat distancia, nat tiempo, nat ciudades)
{
	this->costo = costo;
	this->distancia = distancia;
	this->tiempo = tiempo;
	this->ciudades = ciudades;
}

CostoArco::~CostoArco()
{
}

CostoArco CostoArco::Cero() 
{
	return CostoArco(0,0,0,0);
}

CostoArco CostoArco::Infinito()
{
	return CostoArco();
}