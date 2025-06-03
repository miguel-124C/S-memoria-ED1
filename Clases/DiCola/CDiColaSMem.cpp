//---------------------------------------------------------------------------

#pragma hdrstop

#include "CDiColaSMem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void CDiColaSMem::Crear(){
	colaMem->Crear();
}

bool CDiColaSMem::Vacia(){
	colaMem->Vacia();
}

void CDiColaSMem::Poner( int elemento ){
	colaMem->Poner( elemento );
}

void CDiColaSMem::Sacar( int elemento ){
	colaMem->Sacar( elemento );
}

int CDiColaSMem::Primero(){
	return colaMem->Primero();
}

void CDiColaSMem::MostrarCola(){
	colaMem->MostrarCola();
}

int CDiColaSMem::Ultimo() {
	if (colaMem->Ini == -1)
		throw Exception("ERROR: Dicola vacia");
	else
		return colaMem->Mem->ObtieneDato(colaMem->Fin,"Elemento");
}

void CDiColaSMem::Poner_frente( int e ) {
	int aux = colaMem->Mem->NewEspacio("Elemento,Sig");
	if (aux != -1) {
		colaMem->Mem->PonerDato(aux,"Elemento",e);
		colaMem->Mem->PonerDato(aux,"Sig",colaMem->Ini);
		if (colaMem->Ini == -1)
			colaMem->Fin = aux;
		colaMem->Ini = aux;
	} else
		throw Exception("ERROR: NO HAY ESPACIO DISPONIBLE");
}

void CDiColaSMem::Sacar_final( int e ) {
	if (colaMem->Ini == -1)
		throw Exception("ERROR: Dicola vacia");
	else {
		e = colaMem->Mem->ObtieneDato(colaMem->Fin,"Elemento");
		int x = colaMem->Ini;
		if (colaMem->Ini != colaMem->Fin) {
			while (colaMem->Mem->ObtieneDato(x,"Sig") != colaMem->Fin)
				x = colaMem->Mem->ObtieneDato(x,"Sig");
			colaMem->Mem->PonerDato(x,"Sig",-1);
		} else {
			colaMem->Ini = -1;
		}
		colaMem->Mem->DeleteEspacio(colaMem->Fin);
        colaMem->Fin = x;
	}
}