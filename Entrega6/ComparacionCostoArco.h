﻿#pragma once
#include "Comparacion.h"
#include "CostoArco.h"

class ComparacionCostoArco : public Comparacion<CostoArco>
{
public:
	CompRetorno Comparar(const CostoArco& t1, const CostoArco& t2) const override;
};
