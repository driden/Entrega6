#pragma once
#include "ICiudad.h"

class Ciudad : public ICiudad
{
public:
	Ciudad(Cadena nom, nat num);
	~Ciudad();

	//PRE: -
	//POS: Devuelve la el nombre de la Ciudad
	Cadena ObtenerNombre() const override;

	//PRE: -
	//POS: Devuelve el número interno de esa ciudad en el mapa
	nat ObtenerNumero() const override;
private:
	Cadena nombre;
	nat numero;
};
