//---------------------------------------------------------------------------

#pragma hdrstop

#include "CDiColaV2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void CDiColaV2::Crear(){
	colaVectorV2->Crear();
}

bool CDiColaV2::Vacia(){
	colaVectorV2->Vacia();
}

void CDiColaV2::Poner( int elemento ){
	colaVectorV2->Poner( elemento );
}

void CDiColaV2::Sacar( int elemento ){
	colaVectorV2->Sacar( elemento );
}

int CDiColaV2::Primero(){
	return colaVectorV2->Primero();
}

void CDiColaV2::MostrarCola(){
	colaVectorV2->MostrarCola();
}

int CDiColaV2::Ultimo() {
	if( Vacia() ){
		ShowMessage("La cola está vacia");
		return -1;
	}

	return colaVectorV2->Vector[colaVectorV2->Fin];
}

void CDiColaV2::Poner_frente( int e ) {
	if (colaVectorV2->Fin < colaVectorV2->getMax()) {
		colaVectorV2->Fin++;
		for (int i = colaVectorV2->Fin; i > colaVectorV2->Ini; i--) {
			colaVectorV2->Vector[i] = colaVectorV2->Vector[i-1];
		}
		colaVectorV2->Vector[colaVectorV2->Ini] = e;
	} else
		throw Exception("ERROR: NO HAY ESPACIO DISPONIBLE");
}

void CDiColaV2::Sacar_final( int e ) {
	if (!Vacia()) {
		e = colaVectorV2->Vector[colaVectorV2->Fin];
		colaVectorV2->Fin--;
	}
	else
		throw Exception("ERROR: Dicola vacia");
}
