//---------------------------------------------------------------------------

#pragma hdrstop

#include "CDiColaV3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void CDiColaV3::Crear(){
	colaVectorV3->Crear();
}

bool CDiColaV3::Vacia(){
	colaVectorV3->Vacia();
}

void CDiColaV3::Poner( int elemento ){
	colaVectorV3->Poner( elemento );
}

void CDiColaV3::Sacar( int elemento ){
	colaVectorV3->Sacar( elemento );
}

int CDiColaV3::Primero(){
	return colaVectorV3->Primero();
}

void CDiColaV3::MostrarCola(){
	colaVectorV3->MostrarCola();
}

int CDiColaV3::Ultimo() {
	if (!Vacia())
		return colaVectorV3->Vector[colaVectorV3->Fin];
	else
		throw Exception("ERROR: Dicola vacia");
}

void CDiColaV3::Poner_frente( int e ) {
	if (colaVectorV3->Siguiente(colaVectorV3->Siguiente(colaVectorV3->Fin)) != colaVectorV3->Ini) {
		if (colaVectorV3->Ini == 0) {
			colaVectorV3->Ini = colaVectorV3->getMax() - 1;
		} else {
			colaVectorV3->Ini--;
		}
		colaVectorV3->Vector[colaVectorV3->Ini] = e;
	} else
		throw Exception("ERROR: NO HAY ESPACIO DISPONIBLE");
}

void CDiColaV3::Sacar_final( int e ) {
	if (!Vacia()) {
		e = colaVectorV3->Vector[colaVectorV3->Fin];
	   if (colaVectorV3->Fin == 0) {
			colaVectorV3->Fin = colaVectorV3->getMax() - 1;
		} else {
			colaVectorV3->Fin--;
		}
	}
	else
		throw Exception("ERROR: Dicola vacia");
}