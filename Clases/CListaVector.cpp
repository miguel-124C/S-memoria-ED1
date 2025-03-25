//---------------------------------------------------------------------------

#pragma hdrstop

#include "CListaVector.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

CListaVector::CListaVector( TCanvas* canvas ){
	setCanvas(canvas);
}

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

TipoDatoListVec CListaVector::Recupera( Direccion direccion ){
	if( Vacia() ) return NULO; // Llamar exception ListaVacia
	if( !(direccion >= 1 && direccion <= Longitud) ) return NULO; // Llamar exception DireccionErr

    return Elementos[direccion];
}

int CListaVector::GetLongitud (){
    return Longitud;
}

void CListaVector::Inserta( Direccion direccion, TipoDatoListVec elemento ){
	if( Longitud == MAX ) return; // Llamar exception listallena
	if(!(direccion >= 1 && direccion <= Longitud)) return; // Llamar exception DireccionErr

	for( int i = (Longitud + 1); i >= direccion + 1; i-- ){
		Elementos[i] = Elementos[i - 1];
	}

	Elementos[direccion] = elemento;
	Longitud = Longitud + 1;
}

void CListaVector::Inserta_primero( TipoDatoListVec elemento ){
	if( Longitud == MAX ) return; // Llamar exception listallena

	for( int i = Longitud; i >= 1; i-- ){
		Elementos[i] = Elementos[i - 1];
	}

	Elementos[0] = elemento;
    Longitud = Longitud + 1;
}

void CListaVector::Inserta_ultimo( TipoDatoListVec elemento ){
	if( Longitud == MAX ) return; // Llamar exception listallena

	Longitud = Longitud + 1;
	Elementos[Longitud - 1] = elemento;
}

void CListaVector::Suprime( Direccion direccion ){
	if( Vacia() ) return; // Llamar exception ListaVacia
	if( !(direccion >= 1 && direccion <= Longitud) ) return; // Llamar exception DireccionErr

	for( int i = direccion; i <= Longitud - 1; i++ ){
		Elementos[i] = Elementos[i + 1];
	}

	Longitud = Longitud - 1;
}

void CListaVector::Modifica( Direccion direccion, TipoDatoListVec elemento){
	if( Vacia() ) return; // Llamar exception ListaVacia
	if( !(direccion >= 1 && direccion <= Longitud) ) return; // Llamar exception DireccionErr

	Elementos[direccion] = elemento;
}

void CListaVector::MostrarLista( ){

	for( int i = 0; i < Longitud; i++ ){
    	int x2 = X1 + WidthField;
        int y2 = Y1 + HeightField;
		canvas->Brush->Color = (TColor)0xffffff;
		canvas->Rectangle(X1, Y1, x2, y2);

		canvas->Font->Size = 16;
		canvas->TextOut( X1 + 5, Y1 + 5, Elementos[i] );

		X1 += WidthField;
	}

	X1 = 50;
}
