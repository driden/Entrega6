#pragma once

class CapacidadProtectora
{
public:
	~CapacidadProtectora() {}
	CapacidadProtectora(int vets = 0, int vehi = 0, int din = 0, int vac = 0, int vol = 0)
	{
		veterinarios = vets;
		vehiculos = vehi;
		dinero = din;
		vacunas = vac;
		voluntarios = vol;
	}

	int veterinarios;
	int vehiculos;
	int dinero;
	int vacunas;
	int voluntarios;

	bool EsMenorQueCero() const
	{
		return veterinarios < 0 || vehiculos < 0 || dinero < 0 || vacunas < 0 || voluntarios < 0;
	}

	CapacidadProtectora operator-(const CapacidadProtectora &c) const {
		return CapacidadProtectora(
			veterinarios - c.veterinarios,
			vehiculos - c.vehiculos,
			dinero - c.dinero,
			vacunas - c.vacunas,
			voluntarios - c.voluntarios);
	}

	CapacidadProtectora operator*(const int &c) const {
		return CapacidadProtectora(
			veterinarios*c,
			vehiculos*c,
			dinero*c,
			vacunas*c,
			voluntarios*c
		);
	}
};
