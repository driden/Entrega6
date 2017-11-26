#include "CasoDePrueba.h"
#include "PruebaMemoria.h"
#include "ConductorPrueba.h"
#include "Sistema.h"

Puntero<ISistema> Inicializar()
{
	return new Sistema();
}

void Laberinto1()
{
	Matriz<nat> laberinto = Matriz<nat>(14, 9);
	for (nat i = 0; i < laberinto.Largo; i++)
	{
		for (nat j = 0; j < laberinto.Ancho; j++)
		{
			laberinto[i][j] = 0;
		}
	}
	laberinto[3][1] = 1;
	laberinto[3][2] = 1;
	laberinto[3][3] = 1;
	laberinto[4][1] = 1;
	laberinto[5][1] = 1;
	laberinto[6][1] = 1;
	laberinto[7][1] = 1;
	laberinto[8][1] = 1;
	laberinto[9][1] = 1;
	laberinto[10][1] = 1;
	laberinto[4][3] = 1;
	laberinto[5][3] = 1;
	laberinto[6][3] = 1;
	laberinto[7][3] = 1;
	laberinto[8][3] = 1;
	laberinto[9][3] = 1;
	laberinto[10][3] = 1;
	laberinto[10][2] = 1;
	laberinto[10][4] = 1;
	laberinto[10][5] = 1;
	laberinto[10][6] = 1;
	laberinto[2][3] = 1;
	laberinto[1][3] = 1;
	laberinto[1][4] = 1;
	laberinto[1][5] = 1;
	laberinto[1][6] = 1;
	laberinto[0][6] = 1;
	laberinto[0][7] = 1;
	laberinto[0][8] = 1;
	laberinto[1][8] = 1;
	laberinto[2][8] = 1;
	laberinto[3][8] = 1;
	laberinto[4][8] = 1;
	laberinto[4][7] = 1;
	laberinto[4][6] = 1;
	laberinto[5][6] = 1;
	laberinto[6][6] = 1;
	laberinto[6][5] = 1;
	laberinto[6][4] = 1;
	laberinto[7][7] = 1;
	laberinto[7][8] = 1;
	laberinto[8][7] = 1;
	laberinto[8][8] = 1;

	Array<Tupla<nat, nat>> resultado = Array<Tupla<nat, nat>>(13);
	resultado[0] = Tupla<nat, nat>(3, 1);
	resultado[1] = Tupla<nat, nat>(4, 1);
	resultado[2] = Tupla<nat, nat>(5, 1);
	resultado[3] = Tupla<nat, nat>(6, 1);
	resultado[4] = Tupla<nat, nat>(7, 1);
	resultado[5] = Tupla<nat, nat>(8, 1);
	resultado[6] = Tupla<nat, nat>(9, 1);
	resultado[7] = Tupla<nat, nat>(10, 1);
	resultado[8] = Tupla<nat, nat>(10, 2);
	resultado[9] = Tupla<nat, nat>(10, 3);
	resultado[10] = Tupla<nat, nat>(10, 4);
	resultado[11] = Tupla<nat, nat>(10, 5);
	resultado[12] = Tupla<nat, nat>(10, 6);

	for (nat y = 0; y < laberinto.Ancho; y++)
	{
		for (nat x = 0; x < laberinto.Largo; x++)
		{
			std::cout << laberinto[x][y] << " ";
		}
		std::cout << endl;
	}

	Iterador<Tupla<nat, nat>> esperado = resultado.ObtenerIterador();

	Puntero<ISistema> interfaz = Inicializar();
	Iterador<Tupla<nat, nat>> obtenido = interfaz->Laberinto(Tupla<nat, nat>(3, 1), Tupla<nat, nat>(10, 6), laberinto);


	resultado = Array<Tupla<nat, nat>>(11);
	resultado[0] = Tupla<nat, nat>(3, 1);
	resultado[1] = Tupla<nat, nat>(3, 2);
	resultado[2] = Tupla<nat, nat>(3, 3);
	resultado[3] = Tupla<nat, nat>(4, 3);
	resultado[4] = Tupla<nat, nat>(5, 3);
	resultado[5] = Tupla<nat, nat>(6, 3);
	resultado[6] = Tupla<nat, nat>(6, 4);
	resultado[7] = Tupla<nat, nat>(6, 5);
	resultado[8] = Tupla<nat, nat>(6, 6);
	resultado[9] = Tupla<nat, nat>(5, 6);
	resultado[10] = Tupla<nat, nat>(4, 6);

	/*esperado = resultado.ObtenerIterador();
	obtenido = interfaz->Laberinto(Tupla<nat, nat>(3, 1), Tupla<nat, nat>(4, 6), laberinto);*/


	esperado = NULL;
	obtenido = interfaz->Laberinto(Tupla<nat, nat>(3, 1), Tupla<nat, nat>(7, 8), laberinto);

}
void Laberinto2()
{
	Matriz<nat> laberinto = Matriz<nat>(14, 9);
	for (nat i = 0; i < laberinto.Largo; i++)
	{
		for (nat j = 0; j < laberinto.Ancho; j++)
		{
			laberinto[i][j] = 0;
		}
	}
	laberinto[3][1] = 1;
	laberinto[3][2] = 1;
	laberinto[3][3] = 1;
	laberinto[4][1] = 1;
	laberinto[5][1] = 1;
	laberinto[6][1] = 1;
	laberinto[7][1] = 1;
	laberinto[8][1] = 1;
	laberinto[9][1] = 1;
	laberinto[10][1] = 1;
	laberinto[4][3] = 1;
	laberinto[5][3] = 1;
	laberinto[6][3] = 1;
	laberinto[7][3] = 1;
	laberinto[8][3] = 1;
	laberinto[9][3] = 1;
	laberinto[10][3] = 1;
	laberinto[10][2] = 1;
	laberinto[10][4] = 1;
	laberinto[10][5] = 1;
	laberinto[10][6] = 1;
	laberinto[2][3] = 1;
	laberinto[1][3] = 1;
	laberinto[1][4] = 1;
	laberinto[1][5] = 1;
	laberinto[1][6] = 1;
	laberinto[0][6] = 1;
	laberinto[0][7] = 1;
	laberinto[0][8] = 1;
	laberinto[1][8] = 1;
	laberinto[2][8] = 1;
	laberinto[3][8] = 1;
	laberinto[4][8] = 1;
	laberinto[4][7] = 1;
	laberinto[4][6] = 1;
	laberinto[5][6] = 1;
	laberinto[6][6] = 1;
	laberinto[6][5] = 1;
	laberinto[6][4] = 1;
	laberinto[7][7] = 1;
	laberinto[7][8] = 1;
	laberinto[8][7] = 1;
	laberinto[8][8] = 1;

	Array<Tupla<nat, nat>> resultado;
	
	for (nat y = 0; y < laberinto.Ancho; y++)
	{
		for (nat x = 0; x < laberinto.Largo; x++)
		{
			std::cout << laberinto[x][y] << " ";
		}
		std::cout << endl;
	}

	Puntero<ISistema> interfaz = Inicializar();
	Iterador<Tupla<nat, nat>> esperado;
	Iterador<Tupla<nat, nat>> obtenido;


	resultado = Array<Tupla<nat, nat>>(11);
	resultado[0] = Tupla<nat, nat>(3, 1);
	resultado[1] = Tupla<nat, nat>(3, 2);
	resultado[2] = Tupla<nat, nat>(3, 3);
	resultado[3] = Tupla<nat, nat>(4, 3);
	resultado[4] = Tupla<nat, nat>(5, 3);
	resultado[5] = Tupla<nat, nat>(6, 3);
	resultado[6] = Tupla<nat, nat>(6, 4);
	resultado[7] = Tupla<nat, nat>(6, 5);
	resultado[8] = Tupla<nat, nat>(6, 6);
	resultado[9] = Tupla<nat, nat>(5, 6);
	resultado[10] = Tupla<nat, nat>(4, 6);

	obtenido = interfaz->Laberinto(Tupla<nat, nat>(3, 1), Tupla<nat, nat>(4, 6), laberinto);
	esperado = resultado.ObtenerIterador();
}
void Caballo()
{
	Puntero<ISistema> interfaz = Inicializar();
	Tupla<TipoRetorno, Iterador<Iterador<Tupla<int, int>>>> obtenido;
	Tupla<TipoRetorno, Iterador<Iterador<Tupla<int, int>>>> esperado;
	Array<Tupla<int, int>> pasar;
	Array<Tupla<int, int>> noPasar;

	Array<Iterador<Tupla<int, int>>> mejoresCaminos;
	Array<Tupla<int, int>> camino;

	pasar = Array<Tupla<int, int>>(1);
	pasar[0] = Tupla<int, int>(1, 2);

	noPasar = Array<Tupla<int, int>>(2);
	noPasar[0] = Tupla<int, int>(2, 2);
	noPasar[1] = Tupla<int, int>(2, 1);

	obtenido = interfaz->CaminoCaballo(Tupla<int, int>(0, 0), Tupla<int, int>(1, 2), 1, 10, pasar.ObtenerIterador(), noPasar.ObtenerIterador());
}

void Caballo2()
{
	Puntero<ISistema> interfaz = Inicializar();
	Tupla<TipoRetorno, Iterador<Iterador<Tupla<int, int>>>> obtenido;
	Tupla<TipoRetorno, Iterador<Iterador<Tupla<int, int>>>> esperado;
	Array<Tupla<int, int>> pasar;
	Array<Tupla<int, int>> noPasar;

	Array<Iterador<Tupla<int, int>>> mejoresCaminos;
	Array<Tupla<int, int>> camino;

	pasar = Array<Tupla<int, int>>(1);
	pasar[0] = Tupla<int, int>(1, 2);

	noPasar = Array<Tupla<int, int>>(2);
	noPasar[0] = Tupla<int, int>(2, 2);
	noPasar[1] = Tupla<int, int>(2, 1);


	camino = Array<Tupla<int, int>>(2);
	camino[0] = Tupla<int, int>(0, 0);
	camino[1] = Tupla<int, int>(1, 2);

	pasar = Array<Tupla<int, int>>(4);
	pasar[0] = Tupla<int, int>(1, 0);
	pasar[1] = Tupla<int, int>(1, 5);
	pasar[2] = Tupla<int, int>(5, 5);
	pasar[3] = Tupla<int, int>(1, 4);

	noPasar = Array<Tupla<int, int>>(4);
	noPasar[0] = Tupla<int, int>(0, 0);
	noPasar[1] = Tupla<int, int>(1, 1);
	noPasar[2] = Tupla<int, int>(3, 3);
	noPasar[3] = Tupla<int, int>(4, 2);

	obtenido = interfaz->CaminoCaballo(Tupla<int, int>(3, 1), Tupla<int, int>(3, 5), 2, 6, pasar.ObtenerIterador(), noPasar.ObtenerIterador());

	Iterador < Iterador<Tupla<int, int>>> it = obtenido.Dato2;

	while (it.HayElemento())
	{
		Iterador<Tupla<int, int>> it2 = it.ElementoActual();
		std::cout << "Sol: ";
		while (it2.HayElemento())
		{
			int x = it2.ElementoActual().ObtenerDato1();
			int y = it2.ElementoActual().ObtenerDato2();			
			std::cout << "(" << x << "," << y << ") ";

			it2.Avanzar();
		}	
		std::cout << endl << endl;		
		it.Avanzar();
	}
}

void Viajero1()
{
	Puntero<ISistema> interfaz = Inicializar();
	Array<Puntero<ICiudad>> ciudadesDelMapa = Array<Puntero<ICiudad>>(5);
	ciudadesDelMapa[0] = new CiudadMock("Artigas", 0);
	ciudadesDelMapa[1] = new CiudadMock("Paysandu", 1);
	ciudadesDelMapa[2] = new CiudadMock("Montevideo", 2);
	ciudadesDelMapa[3] = new CiudadMock("Salto", 3);
	ciudadesDelMapa[4] = new CiudadMock("Punta del Este", 4);

	Matriz<nat> mapa = Matriz<nat>(5, 5);
	for (nat i = 0; i < mapa.Largo; i++)
	{
		for (nat j = 0; j < mapa.Ancho; j++)
		{
			mapa[i][j] = 0;
		}
	}

	mapa[0][1] = 20;
	mapa[0][2] = 40;
	mapa[1][2] = 100;
	mapa[2][3] = 190;
	mapa[2][4] = 100;
	mapa[3][0] = 30;
	mapa[4][3] = 50;

	Array<Puntero<ICiudad>> ciudadesPasar = Array<Puntero<ICiudad>>(2);
	ciudadesPasar[0] = ciudadesDelMapa[0];
	ciudadesPasar[1] = ciudadesDelMapa[3];

	Array<Iterador<Puntero<ICiudad>>> resultados = Array<Iterador<Puntero<ICiudad>>>(1);
	Array<Puntero<ICiudad>> resultado = Array<Puntero<ICiudad>>(4);
	resultado[0] = ciudadesDelMapa[2];
	resultado[1] = ciudadesDelMapa[4];
	resultado[2] = ciudadesDelMapa[3];
	resultado[3] = ciudadesDelMapa[0];

	resultados[0] = resultado.ObtenerIterador();

	Iterador<Iterador<Puntero<ICiudad>>> esperado = resultados.ObtenerIterador();
	Iterador<Iterador<Puntero<ICiudad>>> obtenido = interfaz->Viajero(ciudadesDelMapa, mapa, ciudadesDelMapa[2], ciudadesPasar.ObtenerIterador(), 255);
}

void main()
{
	Puntero<ConductorPrueba> cp = new ConductorPrueba();
	Array<Puntero<Prueba>> pruebas = Array<Puntero<Prueba>>(3);
	pruebas[0] = new PruebaMemoria();
	pruebas[1] = new CasoDePrueba(Inicializar);
	pruebas[2] = pruebas[0];
	cp->CorrerPruebas(pruebas.ObtenerIterador());
	
	//Laberinto2();
	//Caballo();
	//Caballo2();
	/*Viajero1();*/

	system("pause");
}
