#pragma once
#include "Tupla.h"
#include "Iterador.h"
#include "Cadena.h"
#include "Lista.h"

enum Turno { MANANA, NOCHE, AMBAS, NINGUNA };
class Materia
{
public:
	Materia(Cadena nom = "", nat credts = 0, nat hrs= 0, Turno horario = NINGUNA)
	{
		nombre = nom;
		creditos = credts;
		horas = hrs;
		turno = horario;
	}
	Cadena nombre;
	nat creditos;
	nat horas;
	Turno turno;
};

class EjercicioMaterias
{
public:
	~EjercicioMaterias(){}
	EjercicioMaterias(
		Iterador<Tupla<Cadena, nat, nat>> matutino = Iterador<Tupla<Cadena, nat, nat>>(),
		Iterador<Tupla<Cadena, nat, nat>> nocturno = Iterador<Tupla<Cadena, nat, nat>>(),
		nat horasM = 0, 
		nat horasN = 0
	);
	Iterador<Tupla<Cadena, bool>> Resolver();
private:
	void MateriasBT(int horasManana, int horasNoche, int objectoActual,
	                Puntero<Lista<Tupla<Materia, bool>>> solucionActual,
	                Puntero<Lista<Tupla<Materia, bool>>>& solucionOptima, int creditosActual, int& creditosOptimos,
		Puntero<Lista<Materia>> materias);
	Puntero<Lista<Tupla<Materia, bool>>> ResolverMaterias();
	Iterador<Tupla<Cadena, bool>> ConvertirSolucion(Puntero<Lista<Tupla<Materia, bool>>> solucion);
	

	Puntero<Lista<Materia>> materias;
	int horasManana;
	int horasNoche;
};
