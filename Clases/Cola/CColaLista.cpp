//---------------------------------------------------------------------------

#pragma hdrstop

#include "CColaLista.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void CColaLista::Crear(){
    Lista->Crear();
}

bool CColaLista::Vacia(){
    return Lista->Vacia();
}

void CColaLista::Poner( TElementoCola elemento ){
	Lista->Inserta( Lista->Primero(), elemento );
}

void CColaLista::Sacar( TElementoCola elemento ){
	Lista->Recupera( Lista->Fin() );
    Lista->Suprime( Lista->Fin() );
}

TElementoCola CColaLista::Primero(){
	TElementoCola elemento = Lista->Recupera( Lista->Fin() );
	return elemento;
}

void CColaLista::MostrarCola(){
	
}