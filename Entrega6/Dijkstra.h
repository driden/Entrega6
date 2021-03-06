#pragma once

#include "GrafoListaAdy.h"
#include "CostoArco.h"


template <class V, class Costo>
class TablaAlgoritmo
{
public:
	TablaAlgoritmo(const V &vengoDe, const Costo costoArco);
	TablaAlgoritmo();
	~TablaAlgoritmo() {}

	Costo costo;
	V vengo;
	bool conocido;
};

template<class V, class A, class Costo>
class Dijkstra
{
public:
	Dijkstra(
		Puntero <Grafo<V, A>> g,
		Comparador<Costo> c,
		Comparador<V> cv,
		Puntero<FuncionHash<V>> funcHash,
		Costo(*fCosto)(Puntero <Grafo<V, A>>, int, int),
		Array<nat> noVisitar)
	{
		grafo = g;
		compCosto = c;
		CalcularCosto = fCosto;
		fHash = funcHash;
		ciudadesNoVisitar = noVisitar;
	}
	~Dijkstra(){}

	Iterador<V> CaminoMasCorto(V origen, V destino);

private:
	Array<TablaAlgoritmo<V, Costo>> tabla;
	Puntero <Grafo<V, A>> grafo;
	Comparador<Costo> compCosto;
	Comparador<V> compVertice;
	Costo(*CalcularCosto)(Puntero <Grafo<V, A>>, int, int);
	Puntero<FuncionHash<V>> fHash;
	Array<nat> ciudadesNoVisitar;
	void InicializarTabla(V origen);
	void AlgoritmoDijkstra(V origen);
};


#include "Dijkstra.cpp"

