#include "Sistema.h"
#include "Lista.h"
#include "ListaEncadenada.h"

//#define DEBUG

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

// Esta funcion elije un pivot y manda todos los elementos
// menores al pivot a su izq y los mas grandes a su derecha
template <class T>
int partition(Array<T> arr, int low, int high)
{
	T pivot = arr[high];    // pivot

	int i = low - 1; // Index of smaller element

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
	// Ordenado ascendentemente entre [i, m]
	// y [m +1, d]

	Array<nat> arr(arreglo.Largo);



	return arr;  //Retorno por defecto
}

bool EsMovimientoValido(nat x, nat y, Matriz<bool> visitados)
{
	nat ancho = visitados.Ancho;
	nat largo = visitados.Largo;

	if (x > 0 && x < largo)
		if (y > 0 && y < ancho)
			if (!visitados[x][y])
				return true;
	return false;
}

bool MovimientoEsMismoEje(nat x, nat y, nat x1, nat y1, nat xM, nat yM)
{
	bool horizontal = y - y1 == 0;

	if (horizontal)
		return y == yM;

	return x == xM;
}

template <class T>
Matriz<T> ClonarMatriz(Matriz<T> matriz)
{
	Matriz<T> m(matriz.Largo, matriz.Ancho);

	for (nat x = 0; x < m.Largo; x++)
		for (nat y = 0; y < m.Ancho; y++)
			m[x][y] = matriz[x][y];
	return m;
}

// izq, arriba, derecha, abajo
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void RecorrerLaberinto(nat xO, nat yO, nat xD, nat yD, Matriz<nat> &laberinto, Matriz<bool> &visitados,
	Puntero<Lista<Tupla<nat, nat, nat>>> &camino, int cambios, Puntero<Lista<Tupla<nat, nat, nat>>> &sol)
{
	visitados[xO][yO] = true;

	Tupla<nat, nat, nat> t(xO, yO, cambios);
	camino->Insertar(t);

#ifdef DEBUG
	std::cout << "visitado (" << xO << "," << yO << ") ? : " << visitados[xO][yO] << endl;
	std::cout << "(" << xO << "," << yO << ") cambios: " << cambios << endl;
	std::cout << "Camino hasta aca: ";
	Iterador<Tupla<nat, nat, nat>> itTupla = camino->ObtenerIterador();
	while (itTupla.HayElemento())
	{
		Tupla<nat, nat, nat> ttt = itTupla.ElementoActual();
		std::cout << "(" << ttt.Dato1 << "," << ttt.Dato2 << ") ";
		itTupla.Avanzar();
	}
	std::cout << endl << endl;

#endif

	if ((xO != xD) || (yO != yD))
	{
		for (nat i = 0; i < 4; i++)
		{
			int xM = xO + dx[i];
			int yM = yO + dy[i];

			if (EsMovimientoValido(xM, yM, visitados))
			{
				nat largo = camino->Largo();
				Tupla<nat, nat, nat> ultimoMov = camino->Obtener(largo > 1 ? largo - 2 : largo - 1);

				Tupla<nat, nat, nat> tM(xO, yO, cambios);
				//camino->Insertar(tM);

				if (largo < 2 || MovimientoEsMismoEje(xO, yO, ultimoMov.Dato1, ultimoMov.Dato2, xM, yM))
				{
					Puntero<Lista<Tupla<nat, nat, nat>>> clonCamino1 = camino->Clon();

					Matriz<bool> visitados1 = ClonarMatriz(visitados);
					RecorrerLaberinto(xM, yM, xD, yD, laberinto, visitados1, clonCamino1, cambios, sol);
				}
				else
				{
					Puntero<Lista<Tupla<nat, nat, nat>>> clonCamino2 = camino->Clon();

					Matriz<bool> visitados2 = ClonarMatriz(visitados);
					RecorrerLaberinto(xM, yM, xD, yD, laberinto, visitados2, clonCamino2, cambios + 1, sol);
				}
			}
		}
	}
	else
	{
		if (sol == nullptr)
			sol = camino;
		else
		{
			int cambiosCamino = camino->Obtener(camino->Largo() - 1).Dato3;
			int cambiosSolucion = sol->Obtener(sol->Largo() - 1).Dato3;;
			if (cambiosSolucion > cambiosCamino )
			{
				sol = camino;
			}
		}
	}

}

Iterador<Tupla<nat, nat>> Sistema::Laberinto(Tupla<nat, nat> &inicio, Tupla<nat, nat> &fin, Matriz<nat> &laberinto)
{
	Matriz<bool> visitados(laberinto.Largo, laberinto.Ancho);
	for (nat x = 0; x < laberinto.Largo; x++)
		for (nat y = 0; y < laberinto.Ancho; y++)
		{
			if (laberinto[x][y] == 0)
				visitados[x][y] = true;
			else
				visitados[x][y] = false;
		}

	Puntero<Lista<Tupla<nat, nat, nat>>> lcamino = new ListaEncadenada<Tupla<nat, nat, nat>>(Comparador<Tupla<nat, nat, nat>>::Default);
	Puntero<Lista<Tupla<nat, nat, nat>>> solucion;
	int cambios = 0;

	RecorrerLaberinto(inicio.Dato1, inicio.Dato2, fin.Dato1, fin.Dato2, laberinto, visitados, lcamino, cambios, solucion);

	nat largoSol = solucion == nullptr ? 0 : solucion->Largo();
	Array<Tupla<nat, nat>> camino(largoSol);

	if (solucion){
	Iterador<Tupla<nat, nat, nat>> itCaminos = solucion->ObtenerIterador();

	int aux = 0;
	while (itCaminos.HayElemento())
	{
		Tupla<nat, nat, nat> t = itCaminos.ElementoActual();
		camino[aux] = Tupla<nat, nat>(t.Dato1, t.Dato2);

		itCaminos.Avanzar();
		aux++;
	}
	}
	return camino.ObtenerIterador();
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


