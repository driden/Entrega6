#include "Sistema.h"

Sistema::Sistema()
{

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


Iterador<Tupla<nat,nat>> Sistema::Laberinto(Tupla<nat,nat> &inicio, Tupla<nat,nat> &fin, Matriz<nat> &laberinto)
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

Tupla<TipoRetorno,  Array<nat>> Sistema::ProteccionAnimales(Array<Accion> acciones, nat maxVeterinarios, nat maxVehiculos, nat maxDinero, nat maxVacunas, nat maxVoluntarios)
{
	//Implementar.

	return Tupla<TipoRetorno,  Array<nat>>();
}

Array<nat> Sistema::QuickSort(Array<nat> elementos)
{
	//Implementar.

	return Array<nat>();
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


