#pragma once

class CapacidadGranja
{
public:
	~CapacidadGranja(){}
	CapacidadGranja(int D = 0,int T = 0,int A = 0)
	{
		costo = D;
		tierra = T;
		agua = A;
	}

	int costo;	// costo de siembra por hectarea
	int tierra; //  tierra que me queda
	int agua;	// agua que me queda

	bool EsMenorQueCero() const { return costo < 0 || tierra < 0 || agua < 0; }

	CapacidadGranja operator-(const CapacidadGranja &c) const {
		return CapacidadGranja(costo - c.costo, tierra - c.tierra, agua - c.agua);
	}

	CapacidadGranja operator*(const int &c) const {
		return CapacidadGranja(costo*c, c*tierra, c*agua);
	}
};
