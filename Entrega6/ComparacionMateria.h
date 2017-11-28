#pragma once
#include "EjercicioMaterias.h"

class ComparacionMateria : public Comparacion<Materia>
{
public:
	CompRetorno Comparar(const Materia& t1, const Materia& t2) const override;
};
