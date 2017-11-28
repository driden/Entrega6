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

	Puntero<Lista<Materia>> materias;
	nat horasManana;
	nat horasNoche;
};
