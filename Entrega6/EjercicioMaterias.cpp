#include "EjercicioMaterias.h"
#include "ListaEncadenada.h"
#include "ComparacionMateria.h"

EjercicioMaterias::EjercicioMaterias(
	Iterador<Tupla<Cadena, nat, nat>> matutino,
	Iterador<Tupla<Cadena, nat, nat>> nocturno, nat horasM, nat horasN)
{
	Puntero<Comparacion<Materia>> comp = new ComparacionMateria();
	materias = new ListaEncadenada<Materia>(comp);

	while(matutino.HayElemento())
	{
		Tupla<Cadena, nat, nat> t = matutino.ElementoActual();
		matutino.Avanzar();
		materias->Insertar(Materia(t.Dato1, t.Dato2, t.Dato3, MANANA));
	}

	while(nocturno.HayElemento())
	{
		Tupla<Cadena, nat, nat> t = nocturno.ElementoActual();
		nocturno.Avanzar();
		Materia m(t.Dato1, t.Dato2, t.Dato3,AMBAS);
		
		if(materias->Pertenece(m))
		{
			materias->Eliminar(m);
			materias->Insertar(m);
		}else
		{
			Materia m2(t.Dato1, t.Dato2, t.Dato3, NOCHE);
			materias->Insertar(m2);
		}
	}
}
