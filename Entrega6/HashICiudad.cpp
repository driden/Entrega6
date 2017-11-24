#include "HashICiudad.h"

nat HashICiudad::CodigoDeHash(const Puntero<ICiudad>& dato) const
{
	nat num = dato->ObtenerNumero();
	Cadena nombre = dato->ObtenerNombre();

	nat hash = 0;

	for (nat i = 0; i < nombre.Largo; i++)
		hash += nombre[i] * (i + 1);

	hash += num;

	return hash;
}
