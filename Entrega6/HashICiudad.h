#pragma once

#include "FuncionHash.h"
#include "ICiudad.h"

class HashICiudad : public FuncionHash<Puntero<ICiudad>>
{
public:
	nat CodigoDeHash(const Puntero<ICiudad>& dato) const override;
};
