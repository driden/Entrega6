﻿#include "Sistema.h"

Sistema::Sistema()
{

}
// PRE: orig y dest son indices validos del Array<T> 'arr'
// POS: los elementos en los indices orig y dest son intercambiados
template<class T>
void Swap(Array<T> arr, int orig, int dest)
{
	T aux = arr[dest];
	arr[dest] = arr[orig];
	arr[orig] = aux;
}
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
template <class T>
int partition(Array<T> arr, int low, int high)
{
	T pivot = arr[high];    // pivot

	int i = low - 1 ; // Index of smaller element

	for (int j = low; j < high; j++)
	{
		// si el elemento actual es menor o igual al pivot elegido
		if (arr[j] <= pivot)
		{
			i++; // Aumento el indice del elemento mas chico
			Swap(arr, i, j); // swap posiciones i y j
			
		}
	}
	Swap(arr, i + 1, high);
	return i + 1;
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low  --> Starting index,
high  --> Ending index */
template <class T>
void Sistema::QuickSort(Array<T> arr, int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		QuickSort(arr, low, pi - 1);
		QuickSort(arr, pi + 1, high);
	}
}

Iterador<Iterador<Puntero<ICiudad>>> Sistema::Viajero(Array<Puntero<ICiudad>> &ciudadesDelMapa, Matriz<nat> &mapa, Puntero<ICiudad> &ciudadPartida, Iterador<Puntero<ICiudad>> &ciudadesPasar, nat costoMax)
{
	/*
   Codigo de implementacion de la solucion
   */
	return NULL; //Retorno por defecto
}

Array<nat> Sistema::Intercalar(Array<nat> &arreglo, nat i, nat m, nat d)
{
	/*
   Codigo de implementacion de la solucion
   */
	return Array<nat>(arreglo.Largo);  //Retorno por defecto
}


Iterador<Tupla<nat, nat>> Sistema::Laberinto(Tupla<nat, nat> &inicio, Tupla<nat, nat> &fin, Matriz<nat> &laberinto)
{
	/*
	Codigo de implementacion de la solucion
	*/
	return NULL;  //Retorno por defecto
}

Array<nat> Sistema::Degustacion(Array<Producto> productos, nat maxDinero, nat maxCalorias, nat maxAlcohol)
{
	/*
	Codigo de implementacion de la solucion
	*/
	return Array<nat>(productos.Largo);  //Retorno por defecto
}

Tupla<TipoRetorno, Iterador<nat>> Sistema::Viajero2(Matriz<Tupla<nat, nat, nat>> relacionesCiudades, Iterador<nat> CiudadesPasar, Iterador<nat> CiudadesNoPasar)
{
	//Implementar.

	return Tupla<TipoRetorno, Iterador<nat>>();
}

Tupla<TipoRetorno, Array<nat>> Sistema::ProteccionAnimales(Array<Accion> acciones, nat maxVeterinarios, nat maxVehiculos, nat maxDinero, nat maxVacunas, nat maxVoluntarios)
{
	//Implementar.

	return Tupla<TipoRetorno, Array<nat>>();
}

Array<nat> Sistema::QuickSort(Array<nat> elementos)
{
	QuickSort(elementos, 0, elementos.Largo - 1);
	return elementos;
}

Tupla<TipoRetorno, Iterador<Iterador<Tupla<int, int>>>> Sistema::CaminoCaballo(Tupla<int, int>& salida, Tupla<int, int>& destino, nat cantAPasar, nat tamTablero, Iterador<Tupla<int, int>>& pasar, Iterador<Tupla<int, int>>& noPasar)
{
	//Implementar.

	return Tupla<TipoRetorno, Iterador<Iterador<Tupla<int, int>>>>();
}

Tupla<TipoRetorno, Array<nat>> Sistema::OptimizarGranja(Array<Tupla<nat, nat, nat>>& semillas, nat dinero, nat tierra, nat agua)
{
	//Implementar.

	return Tupla<TipoRetorno, Array<nat>>();
}

Tupla<TipoRetorno, Iterador<Tupla<Cadena, bool>>> Sistema::InscribirMaterias(Iterador<Tupla<Cadena, nat, nat>> matutino, Iterador<Tupla<Cadena, nat, nat>> nocturno, nat horasM, nat horasN)
{
	//Implementar.

	return Tupla<TipoRetorno, Iterador<Tupla<Cadena, bool>>>();
}


