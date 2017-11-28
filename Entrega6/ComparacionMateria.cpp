#include "ComparacionMateria.h"

CompRetorno ComparacionMateria::Comparar(const Materia& t1, const Materia& t2) const
{
	Comparador<Cadena> comparador = Comparador<Cadena>::Default;
	return comparador.Comparar(t1.nombre, t2.nombre);
}
