#include "EjercicioMaterias.h"
#include "ListaEncadenada.h"
#include "ComparacionMateria.h"
#include "ComparacionTuplaMateriaBool.h"

EjercicioMaterias::EjercicioMaterias(
	Iterador<Tupla<Cadena, nat, nat>> matutino,
	Iterador<Tupla<Cadena, nat, nat>> nocturno, nat horasM, nat horasN)
{
	Puntero<Comparacion<Materia>> comp = new ComparacionMateria();
	materias = new ListaEncadenada<Materia>(comp);

	while (matutino.HayElemento())
	{
		Tupla<Cadena, nat, nat> t = matutino.ElementoActual();
		matutino.Avanzar();
		materias->Insertar(Materia(t.Dato1, t.Dato2, t.Dato3, MANANA));
	}

	while (nocturno.HayElemento())
	{
		Tupla<Cadena, nat, nat> t = nocturno.ElementoActual();
		nocturno.Avanzar();
		Materia m(t.Dato1, t.Dato2, t.Dato3, AMBAS);

		if (materias->Pertenece(m))
		{
			materias->Eliminar(m);
			materias->Insertar(m);
		}
		else
		{
			Materia m2(t.Dato1, t.Dato2, t.Dato3, NOCHE);
			materias->Insertar(m2);
		}
	}

	horasManana = horasM;
	horasNoche = horasN;
}

void EjercicioMaterias::MateriasBT(
	int horasManana, int horasNoche,
	int objectoActual,
	Puntero<Lista<Tupla<Materia, bool>>> solucionActual,
	Puntero<Lista<Tupla<Materia, bool>>> &solucionOptima,
	int creditosActual,
	int &creditosOptimos,
	Puntero<Lista<Materia>> materias)
{
	if (horasManana < 0) return;
	if (horasNoche < 0) return;

	if (objectoActual == -1 && creditosActual > creditosOptimos)
	{
		solucionOptima = solucionActual->Clon();
		creditosOptimos = creditosActual;
	}
	else if (objectoActual == -1) return;
	else {
		// 3 opciones: no tomo la materia, tomo de manana o de noche
		Materia mActual = materias->Obtener(objectoActual);

		switch (mActual.turno)
		{
		case AMBAS:
			// manana
			solucionActual->Insertar(Tupla<Materia, bool>(mActual, true));
			MateriasBT(horasManana - mActual.horas, horasNoche, objectoActual - 1, solucionActual, solucionOptima, creditosActual + mActual.creditos, creditosOptimos, materias);
			solucionActual->Eliminar(Tupla<Materia, bool>(mActual, true));

			// noche
			solucionActual->Insertar(Tupla<Materia, bool>(mActual, false));
			MateriasBT(horasManana, horasNoche - mActual.horas, objectoActual - 1, solucionActual, solucionOptima, creditosActual + mActual.creditos, creditosOptimos, materias);
			solucionActual->Eliminar(Tupla<Materia, bool>(mActual, false));
			break;
		case NOCHE:
			// noche
			solucionActual->Insertar(Tupla<Materia, bool>(mActual, false));
			MateriasBT(horasManana, horasNoche - mActual.horas, objectoActual - 1, solucionActual, solucionOptima, creditosActual + mActual.creditos, creditosOptimos, materias);
			solucionActual->Eliminar(Tupla<Materia, bool>(mActual, false));
			break;
		case MANANA:
			//manana
			solucionActual->Insertar(Tupla<Materia, bool>(mActual, true));
			MateriasBT(horasManana - mActual.horas, horasNoche, objectoActual - 1, solucionActual, solucionOptima, creditosActual + mActual.creditos, creditosOptimos, materias);
			solucionActual->Eliminar(Tupla<Materia, bool>(mActual, true));
			break;
		default: break;
		}
		// no tomo la materia
		MateriasBT(horasManana, horasNoche, objectoActual - 1, solucionActual, solucionOptima, creditosActual, creditosOptimos, materias);
	}
}

Puntero<Lista<Tupla<Materia, bool>>> EjercicioMaterias::ResolverMaterias()
{
	Puntero<Lista<Tupla<Materia, bool>>> solucionOptima = nullptr;
	Puntero<Comparacion<Tupla<Materia, bool>>> c = new ComparacionTuplaMateriaBool();
	Comparador<Tupla<Materia, bool>> comparador(c);
	Puntero<Lista<Tupla<Materia, bool>>> solucionActual = new ListaEncadenada<Tupla<Materia, bool>>(comparador);
	int creditosOptimos = -1;

	MateriasBT(horasManana, horasNoche, materias->Largo() - 1, solucionActual, solucionOptima, 0, creditosOptimos, materias);
	return solucionOptima;
}

Iterador<Tupla<Cadena, bool>> EjercicioMaterias::ConvertirSolucion(Puntero<Lista<Tupla<Materia, bool>>> solucion)
{
	Puntero<Lista<Tupla<Cadena, bool>>> pSol = new ListaEncadenada<Tupla<Cadena, bool>>();
	Iterador<Tupla<Materia, bool>> itSolucion = solucion->ObtenerIterador();

	while (itSolucion.HayElemento())
	{
		Tupla<Materia, bool> t = itSolucion.ElementoActual();
		itSolucion.Avanzar();

		Tupla<Cadena, bool> tSol(t.ObtenerDato1().nombre, t.ObtenerDato2());
		pSol->Insertar(tSol);
	}

	return pSol->ObtenerIterador();
}

Iterador<Tupla<Cadena, bool>> EjercicioMaterias::Resolver()
{
	return ConvertirSolucion(ResolverMaterias());
}
