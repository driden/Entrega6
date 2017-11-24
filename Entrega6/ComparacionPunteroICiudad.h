#pragma once
#include "Comparacion.h"
#include "ICiudad.h"

class ComparacionPunteroICiudad : public Comparacion<Puntero<ICiudad>>
{
public:
	~ComparacionPunteroICiudad() {}
	CompRetorno Comparar(const Puntero<ICiudad>& t1, const Puntero<ICiudad>& t2) const override;
};
