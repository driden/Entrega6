#include "ComparacionPunteroICiudad.h"

CompRetorno ComparacionPunteroICiudad::Comparar(const Puntero<ICiudad>& t1, const Puntero<ICiudad>& t2) const
{
	nat num1 = t1->ObtenerNumero(), num2 = t2->ObtenerNumero();

	if (num1 > num2) return MAYOR;
	if (num1 < num2) return MENOR;
	if (num1 == num2) return IGUALES;
	assert(false);
	return DISTINTOS;
}
