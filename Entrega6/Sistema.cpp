#include "Sistema.h"
#include "Lista.h"
#include "ListaEncadenada.h"
#include "EjercicioDegustacion.h"
#include "EjercicioProtectoraAnimales.h"
#include "EjercicioViajero.h"

//#define DEBUG_MATRIZ

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
	EjercicioViajero ejViajero(ciudadesDelMapa, mapa, ciudadPartida, ciudadesPasar, costoMax);
	return ejViajero.Resolver(); //Retorno por defecto
}

// PRE: desde y hasta son indices validos del arreglo con desde <= hasta
// POS: devuelve el SubArray creado con la tira de elementos con indices en el rango [desde, hasta]
template <class T>
Array<T> SubArray(Array<T> arreglo, nat desde, nat hasta)
{
	assert(desde >= 0);
	assert(hasta < arreglo.Largo);
	assert(desde <= hasta);
	
	Array<T> nuevoArr(hasta - desde + 1);
	for (nat i = desde; i <= hasta; i++)
		nuevoArr[i - desde] = arreglo[i];

	return nuevoArr;
}

Array<nat> Sistema::Intercalar(Array<nat> &arreglo, nat i, nat m, nat d)
{
	// Ordenado ascendentemente entre [i, m]
	// y [m +1, d]
	Array<nat> arrIzq = SubArray(arreglo, i, m);
	Array<nat> arrDer = SubArray(arreglo, m+1, d);
	Array<nat> arrIntercalado(d - i + 1);

	Iterador<nat> itIzq = arrIzq.ObtenerIterador();
	Iterador<nat> itDer = arrDer.ObtenerIterador();

	nat x = 0;

	while (itIzq.HayElemento() && itDer.HayElemento())
	{
		nat izq = itIzq.ElementoActual();
		nat der = itDer.ElementoActual();

		if (izq > der)
		{
			arrIntercalado[x++] = der;
			itDer.Avanzar();
		}else
		{
			arrIntercalado[x++] = izq;
			itIzq.Avanzar();
		}			
	}

	while (itIzq.HayElemento())
	{
		arrIntercalado[x++] = itIzq.ElementoActual();
		itIzq.Avanzar();
	}

	while (itDer.HayElemento())
	{
		arrIntercalado[x++] = itDer.ElementoActual();
		itDer.Avanzar();
	}

	Array<nat>::Copiar(arrIntercalado, arreglo, i);
	return arreglo;
}

// PRE: -
// POS: devuelve true sii (x,y) es un punto en la matriz y no se encuentra visitada
bool EsMovimientoValido(nat x, nat y, Matriz<bool> visitados)
{
	nat ancho = visitados.Ancho;
	nat largo = visitados.Largo;

	if (x >= 0 && x < largo)
		if (y >= 0 && y < ancho)
			if (!visitados[x][y])
				return true;
	return false;
}

// PRE:
// POS: devuelve true sii (xM, yM) es un movimiento en el mismo eje que 
//	el de la recta dada por los puntos (x1,y1) e (x,y)
bool MovimientoEsMismoEje(nat x, nat y, nat x1, nat y1, nat xM, nat yM)
{
	bool horizontal = y - y1 == 0;

	if (horizontal)
		return y == yM;

	return x == xM;
}

// PRE:
// POS: devuelve una deep copy de la matriz 
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

// PRE: (xO, yO), (xD, yD) pertenecen al laberinto 
// POS: Mueve el laberinto en 1 posicion valida y evalua si encontro una solucion, sino sigue moviendose
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
			if (cambiosSolucion > cambiosCamino)
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

	if (solucion) {
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
	EjercicioDegustacion degustacion(productos,maxDinero,maxCalorias,maxAlcohol);


	return degustacion.Resolver();
}

Tupla<TipoRetorno, Iterador<nat>> Sistema::Viajero2(Matriz<Tupla<nat, nat, nat>> relacionesCiudades, Iterador<nat> CiudadesPasar, Iterador<nat> CiudadesNoPasar)
{
	//Implementar.

	return Tupla<TipoRetorno, Iterador<nat>>();
}

Tupla<TipoRetorno, Array<nat>> Sistema::ProteccionAnimales(Array<Accion> acciones, nat maxVeterinarios, nat maxVehiculos, nat maxDinero, nat maxVacunas, nat maxVoluntarios)
{
	EjercicioProtectoraAnimales protectora(acciones, maxVeterinarios, maxVehiculos, maxDinero, maxVacunas, maxVoluntarios);
	return Tupla<TipoRetorno, Array<nat>>(OK, protectora.Resolver());
}

Array<nat> Sistema::QuickSort(Array<nat> elementos)
{
	QuickSort(elementos, 0, elementos.Largo - 1);
	return elementos;
}

Matriz<bool> Sistema::CrearMatrizVisitados(const Matriz<int>& tablero)
{
	Matriz<bool> visitados(tablero.Largo);

	for (nat x = 0; x < tablero.Largo; x++)
		for (nat y = 0; y < tablero.Largo; y++)
		{
			if (tablero[x][y] == 0)
				visitados[x][y] = false;
			else if (tablero[x][y] == -1)
				visitados[x][y] = true;
		}
	return visitados;
}

//Movimientos posibles del caballo
int xCaballo[] = { -1, 1, 2,2,1,-1,-2,-2 };
int yCaballo[] = { -2,-2,-1,1,2, 2, 1,-1 };
// PRE: -
// POS: Crea una matriz con -1, 0 y 1s con la siguiente nomenclatura
// No pasar: -1
// Indiferente: 0
// Pasar: 1
Matriz<int> CrearTablero(nat tamTablero, Iterador<Tupla<int, int>>& pasar, Iterador<Tupla<int, int>>& noPasar)
{
	Matriz<int> tablero(tamTablero, tamTablero);

	for (nat x = 0; x < tablero.Largo; x++)
		for (nat y = 0; y < tablero.Largo; y++)
			tablero[x][y] = 0;

	pasar.Reiniciar();
	noPasar.Reiniciar();

	while (pasar.HayElemento())
	{
		Tupla<int, int> t = pasar.ElementoActual();
		int x = t.ObtenerDato1(), y = t.ObtenerDato2();
		tablero[x][y] = 1;
		pasar.Avanzar();
	}

	while (noPasar.HayElemento())
	{
		Tupla<int, int> t = noPasar.ElementoActual();
		int x = t.ObtenerDato1(), y = t.ObtenerDato2();
		tablero[x][y] = -1;
		noPasar.Avanzar();
	}

	pasar.Reiniciar();
	noPasar.Reiniciar();
	return tablero;
}

void Caballero(int xO, int yO, int xD, int yD, Matriz<bool> visitados, Puntero<Lista<Tupla<int, int>>> &camino, Puntero<Lista<Puntero<Lista<Tupla<int, int>>>>> &solucion, int &movSolucion,
	int movimientos, int cantAPasar, Matriz<int> tablero)
{
	if (movimientos > movSolucion) return; //poda
		
	visitados[xO][yO] = true; // Marco como visitado el actual
	// Inserto la coordenada al camino
	camino->Insertar(Tupla<nat, nat>(xO, yO));

#ifdef DEBUG_MATRIZ

	std::cout << "\n(" << xO << "," << yO << ") movimientos: " << movimientos << endl;
	std::cout << "Camino hasta aca: ";
	Iterador<Tupla<nat, nat>> itTupla = camino->ObtenerIterador();
	while (itTupla.HayElemento())
	{
		Tupla<nat, nat> ttt = itTupla.ElementoActual();
		std::cout << "(" << ttt.Dato1 << "," << ttt.Dato2 << ") ";
		itTupla.Avanzar();
	}
	std::cout << endl << endl;

#endif

	// Si no llegue a destino
	if ((xO != xD) || (yO != yD))
	{
		for (nat i = 0; i < 8; i++)
		{
			const int xM = xO + xCaballo[i];
			const int yM = yO + yCaballo[i];

			if (EsMovimientoValido(xM, yM, visitados))
			{
				nat largo = camino->Largo();
				Puntero<Lista<Tupla<int, int>>> clonCamino = camino->Clon();
				Matriz<bool> clonVisitados = ClonarMatriz(visitados);
				Caballero(xM, yM, xD, yD, clonVisitados, clonCamino, solucion,movSolucion ,movimientos + 1, tablero[xM][yM] == 1 ? cantAPasar - 1 : cantAPasar,tablero);
			}
		}
	}
	// Si encontre solucion
	else
	{
		// Para ser solucion tiene que haber pasado por cantAPasar, sino no la considero
		if (cantAPasar < 1) 
		{
			// si tiene la misma cantidad de movimientos
			if (movimientos == movSolucion)
			{
				solucion->Insertar(camino);
			}
			// Si es una mejor solucion
			else if(movimientos < movSolucion)
			{
				solucion = new ListaEncadenada<Puntero<Lista<Tupla<int, int>>>>();
				solucion->Insertar(camino);
				movSolucion = movimientos;
			}			
		}
	}
}

Tupla<TipoRetorno, Iterador<Iterador<Tupla<int, int>>>> Sistema::CaminoCaballo
(Tupla<int, int>& salida, Tupla<int, int>& destino, nat cantAPasar, nat tamTablero, Iterador<Tupla<int, int>>& pasar, Iterador<Tupla<int, int>>& noPasar)
{
	Matriz<int> tablero = CrearTablero(tamTablero, pasar, noPasar);
	Matriz<bool> visitados = CrearMatrizVisitados(tablero);
	int cantidad = static_cast<int>(cantAPasar);
#ifdef DEBUG_MATRIZ
	for (nat y = 0; y < tablero.Ancho; y++)
	{
		for (nat x = 0; x < tablero.Largo; x++)
		{
			std::cout << tablero[x][y] << " ";
		}
		std::cout << endl;
	}
#endif
	
	Puntero<Lista<Tupla<int, int>>> camino = new ListaEncadenada<Tupla<int, int>>();
	Puntero<Lista<Puntero<Lista<Tupla<int, int>>>>> sol = new ListaEncadenada<Puntero<Lista<Tupla<int,int>>>>();
	int movSolucion = 1000;
	int moviMientos = 0;
	Caballero(salida.Dato1, salida.Dato2, destino.Dato1, destino.Dato2, visitados, camino, sol, movSolucion, moviMientos, cantidad, tablero);

	Array<Iterador<Tupla<int, int>>> arrIterador (sol->Largo());
	Iterador<Puntero<Lista<Tupla<int, int>>>> itListaTupla = sol->ObtenerIterador();
	int i = 0;

	while(itListaTupla.HayElemento())
	{
		arrIterador[i] = itListaTupla.ElementoActual()->ObtenerIterador();
		itListaTupla.Avanzar();
		i++;
	}
	
	return Tupla<TipoRetorno, Iterador<Iterador<Tupla<int, int>>>> (OK, arrIterador.ObtenerIterador());
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


