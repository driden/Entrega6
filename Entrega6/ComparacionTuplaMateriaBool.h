#pragma once
#include "ComparacionMateria.h"

class ComparacionTuplaMateriaBool : public Comparacion<Tupla<Materia,bool>>
{
public:
	ComparacionTuplaMateriaBool(){}
	~ComparacionTuplaMateriaBool(){}
	CompRetorno Comparar(const Tupla<Materia, bool>& t1, const Tupla<Materia, bool>& t2) const override;
};
