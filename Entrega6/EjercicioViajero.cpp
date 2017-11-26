#include "EjercicioViajero.h"
#include "ComparacionPunteroICiudad.h"
#include "HashICiudad.h"

EjercicioViajero::~EjercicioViajero()
{
}

EjercicioViajero::EjercicioViajero(Array<Puntero<ICiudad>>& ciudadesDelMapa, Matriz<nat>& mapa,
	Puntero<ICiudad>& ciudadPartida, Iterador<Puntero<ICiudad>> ciudades, nat costo)
{
	Puntero<Comparacion<Puntero<ICiudad>>> pComparacion = new ComparacionPunteroICiudad();
	comparadorV = Comparador<Puntero<ICiudad>>(pComparacion);

	Puntero<FuncionHash<Puntero<ICiudad>>> fHash = new HashICiudad();

	grafo = new GrafoListaAdy<Puntero<ICiudad>, nat>(ciudadesDelMapa.Largo, fHash, pComparacion);

	for (nat c = 0; c < ciudadesDelMapa.Largo; c++)
		grafo->AgregarVertice(ciudadesDelMapa[c]);

	for (nat x = 0; x < mapa.Largo; x++)
		for (nat y = 0; y < mapa.Ancho; y++)
		{
			if (mapa[x][y] == 0) continue;

			Puntero<ICiudad> desde = ciudadesDelMapa[x];
			Puntero<ICiudad> hasta = ciudadesDelMapa[y];

			grafo->AgregarArco(desde, hasta, mapa[x][y]);
		}


	costoMax = costo;
	ciudadesPasar = ciudades;
	ciudadPart = ciudadPartida;
	cantVertices = ciudadesDelMapa.Largo;
}

bool PasePorTodasLasCiudades(Array<Puntero<ICiudad>> ciudades, Array<bool> visitados)
{
	for (nat i = 0; i < ciudades.Largo; i++)
	{
		Puntero<ICiudad> pCiudad = ciudades[i];
		nat pos = pCiudad->ObtenerNumero();
		if (!visitados[pos]) return false;
	}
	return true;
}

bool CiudadFueVisitada(Puntero<ICiudad> ciudad, Array<bool> visitados)
{
	nat pos = ciudad->ObtenerNumero();
	return visitados[pos];
}
void VisitarCiudad(Puntero<ICiudad> ciudad, Array<bool> &visitados, bool visitado = true)
{
	nat pos = ciudad->ObtenerNumero();
	visitados[pos] = visitado;
}

void EjercicioViajero::ImprimirDatos(const Puntero<ICiudad>& puntero, const Puntero<Lista<Puntero<ICiudad>>>& camino,
	nat costo, nat costo_max)
{
	std::cout << "Ciudad actual: " << puntero->ObtenerNombre() << " con costo: " << costo << "/" << costo_max;
	std::cout << "\nCamino: ";

	Iterador<Puntero<ICiudad>> itCamino = camino->ObtenerIterador();

	std::cout << itCamino.ElementoActual()->ObtenerNombre();
	itCamino.Avanzar();
	while (itCamino.HayElemento())
	{
		std::cout << " -> " << itCamino.ElementoActual()->ObtenerNombre();
		itCamino.Avanzar();
	}
	std::cout << endl << endl;
}

void EjercicioViajero::Resolver(
	Puntero<ICiudad> ciudadActual,
	Puntero<Lista<Puntero<ICiudad>>>& camino, Puntero<Lista<Puntero<Lista<Puntero<ICiudad>>>>>& caminoSolucion,
	nat costo, nat &costoSolucion, nat cantCiudadesVisitadas, nat &cantCiudadesSolucion,
	Array<bool> visitados, Array<Puntero<ICiudad>> ciudades)
{
	if (CiudadFueVisitada(ciudadActual, visitados)) return;
	if (costo > costoSolucion) return;
	VisitarCiudad(ciudadActual, visitados);
	camino->Insertar(ciudadActual); // Inserta al final

#ifdef DEBUG_VIAJERO
	ImprimirDatos(ciudadActual, camino, costo, costoMax);
#endif


	if (PasePorTodasLasCiudades(ciudades, visitados))
	{
		if (costo == costoSolucion)
		{
			if (cantCiudadesVisitadas < cantCiudadesSolucion)
			{
				cantCiudadesSolucion = camino->Largo();
				caminoSolucion = new ListaEncadenada<Puntero<Lista<Puntero<ICiudad>>>>();
			}				
			caminoSolucion->Insertar(camino->Clon());			
		}
		else if (costo < costoSolucion)
		{
			caminoSolucion = new ListaEncadenada<Puntero<Lista<Puntero<ICiudad>>>>();
			caminoSolucion->Insertar(camino->Clon());	
			cantCiudadesSolucion = camino->Largo();
		}
		costoSolucion = costo;
	}
	else
	{
		if (costo <= costoSolucion && costo <= costoMax) // Poda
		{
			Iterador<Puntero<ICiudad>> vecinos = grafo->Adyacentes(ciudadActual);
			while (vecinos.HayElemento())
			{
				Puntero<ICiudad> vecino = vecinos.ElementoActual();
				nat costoDeIrAVecino = grafo->ObtenerArco(ciudadActual, vecino);


				Resolver(vecino, camino, caminoSolucion, costo + costoDeIrAVecino, costoSolucion, cantCiudadesVisitadas + 1,cantCiudadesSolucion , visitados, ciudades);
				vecinos.Avanzar();
			}
		}
	}
	
	camino->Eliminar(ciudadActual);
	VisitarCiudad(ciudadActual, visitados,false);
}

Iterador<Iterador<Puntero<ICiudad>>> EjercicioViajero::Resolver()
{
	Puntero<Lista<Puntero<ICiudad>>> c = new ListaEncadenada<Puntero<ICiudad>>(comparadorV);

	Puntero<Lista<Puntero<Lista<Puntero<ICiudad>>>>> solucion = new ListaEncadenada<Puntero<Lista<Puntero<ICiudad>>>>();

	Array<bool> visited(cantVertices, false);

	nat cantVisitar = 0;

	Iterador<Puntero<ICiudad>> ciudadesVisitar = ciudadesPasar;
	while (ciudadesVisitar.HayElemento())
	{
		cantVisitar++;
		ciudadesVisitar.Avanzar();
	}

	ciudadesVisitar.Reiniciar();
	Array<Puntero<ICiudad>> ciudades(cantVisitar);
	for (nat i = 0; i < cantVisitar; i++)
	{
		ciudades[i] = ciudadesVisitar.ElementoActual();
#ifdef DEBUG_VIAJERO
		std::cout << ciudades[i]->ObtenerNombre() << "\n";
#endif
		ciudadesVisitar.Avanzar();
	}

	nat inf = INFINITO, inf2 = INFINITO;
	Resolver(ciudadPart, c, solucion, 0, inf, 1, inf2, visited, ciudades);

	return Solucionar(solucion);
}

Iterador<Iterador<Puntero<ICiudad>>> EjercicioViajero::Solucionar(Puntero<Lista<Puntero<Lista<Puntero<ICiudad>>>>> sol)
{
	Puntero<Lista<Iterador<Puntero<ICiudad>>>> pLista = new ListaEncadenada<Iterador<Puntero<ICiudad>>>();

	nat largo = sol->Largo();

	for (nat i = 0; i < largo; i++)
	{
		Iterador<Puntero<ICiudad>> iter = sol->Obtener(i)->ObtenerIterador();
		pLista->Insertar(iter);
	}
	return pLista->ObtenerIterador();
}




