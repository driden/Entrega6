#include "Ciudad.h"

Ciudad::Ciudad(Cadena nom = "", nat num= 0)
{
	nombre = nom;
	numero = num;
}

Ciudad::~Ciudad()
{
}

Cadena Ciudad::ObtenerNombre() const
{
	return nombre;
}

nat Ciudad::ObtenerNumero() const
{
	return numero;
}
