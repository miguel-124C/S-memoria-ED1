//---------------------------------------------------------------------------

#pragma hdrstop

#include "CListaVector.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void CListaVector::Crear(){
    Longitud = 0;
}

Direccion CListaVector::Fin(){
	if( !Vacia() ) return Longitud;
    return NULO;
}

Direccion CListaVector::Primero(){
	if( !Vacia() ) return 1;
	return NULO;
}

Direccion CListaVector::Siguiente( Direccion direccion ){
	if( Vacia() ) return NULO; // Llamar exception ListaVacia
	if( direccion == Longitud ) return NULO; // Llamar exception DireccionErr

	return direccion++;
}

Direccion CListaVector::Anterior( Direccion direccion ){
	if( Vacia() ) return NULO; // Llamar exception ListaVacia
	if( direccion == 1 ) return NULO; // Llamar exception DireccionPrimeraErr

	return direccion--;
}

bool CListaVector::Vacia(){
	return Longitud == 0;
}

TipoDato CListaVector::Recupera( Direccion direccion ){
	if( Vacia() ) return NULO; // Llamar exception ListaVacia
	if( !(direccion >= 1 && direccion <= Longitud) ) return NULO; // Llamar exception DireccionErr

    return Elementos[direccion];
}

int CListaVector::GetLongitud (){
    return Longitud;
}

void CListaVector::Inserta( Direccion direccion, TipoDato elemento ){
	if( Longitud == MAX ) return; // Llamar exception listallena
	if(!(direccion >= 1 && direccion <= Longitud)) return; // Llamar exception DireccionErr

	for( int i = (Longitud + 1); i >= direccion + 1; i-- ){
		Elementos[i] = Elementos[i - 1];
	}

	Elementos[direccion] = elemento;
	Longitud = Longitud + 1;
}

void CListaVector::Inserta_primero( TipoDato elemento ){
	if( Longitud == MAX ) return; // Llamar exception listallena

	for( int i = (Longitud + 1); i >= 2; i-- ){
		Elementos[i] = Elementos[i - 1];
	}

	Elementos[1] = elemento;
    Longitud = Longitud + 1;
}

void CListaVector::Inserta_ultimo( TipoDato elemento ){
	if( Longitud == MAX ) return; // Llamar exception listallena

	Longitud = Longitud + 1;
	Elementos[Longitud] = elemento;
}

void CListaVector::Suprime( Direccion direccion ){
	if( Vacia() ) return; // Llamar exception ListaVacia
	if( !(direccion >= 1 && direccion <= Longitud) ) return; // Llamar exception DireccionErr

	for( int i = direccion; i <= Longitud - 1; i++ ){
		Elementos[i] = Elementos[i + 1];
	}

	Longitud = Longitud - 1;
}

void CListaVector::Modifica( Direccion direccion, TipoDato elemento){
	if( Vacia() ) return; // Llamar exception ListaVacia
	if( !(direccion >= 1 && direccion <= Longitud) ) return; // Llamar exception DireccionErr

	Elementos[direccion] = elemento;
}
