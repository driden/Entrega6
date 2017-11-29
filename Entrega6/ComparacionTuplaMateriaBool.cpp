#include "ComparacionTuplaMateriaBool.h"

CompRetorno ComparacionTuplaMateriaBool::Comparar(const Tupla<Materia, bool>& t1, const Tupla<Materia, bool>& t2) const
{
	Puntero<Comparacion<Materia>> m = new ComparacionMateria();
	Comparador<Materia> comp(m);

	if (comp.SonIguales(t1.Dato1, t2.Dato1))
		if (t1.Dato2 == t2.Dato2)
			return IGUALES;
		else
			return DISTINTOS;

	if (comp.SonDistintos(t1.Dato1, t2.Dato1))
		return DISTINTOS;

	assert(false);
	return MAYOR;
}
