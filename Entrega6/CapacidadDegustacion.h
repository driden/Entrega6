#pragma once

class CapacidadDegustacion
{
public:
	int alcohol;
	int dinero;
	int calorias;

	CapacidadDegustacion(int a = 0, int d = 0, int c = 0) {
		alcohol = a;
		dinero = d;
		calorias = c;
	}
	~CapacidadDegustacion(){}
	bool EsMenorQueCero() const { return alcohol < 0 || dinero < 0 || calorias < 0; }

	CapacidadDegustacion operator-(const CapacidadDegustacion &c) const {
		return CapacidadDegustacion(alcohol - c.alcohol, dinero - c.dinero, calorias - c.calorias);	
	}

	CapacidadDegustacion operator*(const int &c) const {
		return CapacidadDegustacion(alcohol*c, c*dinero, c*calorias);
	}

};