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

DireccionListVec CListaVector::Fin(){
	if( !Vacia() ) return Longitud;
    return NULO;
}

DireccionListVec CListaVector::Primero(){
	if( !Vacia() ) return 1;
	return NULO;
}

DireccionListVec CListaVector::Siguiente( DireccionListVec direccion ){
	if( Vacia() ) return NULO; // Llamar exception ListaVacia
	if( direccion == Longitud ) return NULO; // Llamar exception DireccionErr

	return direccion++;
}

DireccionListVec CListaVector::Anterior( DireccionListVec direccion ){
	if( Vacia() ) return NULO; // Llamar exception ListaVacia
	if( direccion == 1 ) return NULO; // Llamar exception DireccionPrimeraErr

	return direccion--;
}

bool CListaVector::Vacia(){
	return Longitud == 0;
}

TipoDatoListVec CListaVector::Recupera( DireccionListVec direccion ){
	if( Vacia() ) return NULO; // Llamar exception ListaVacia
	if( !(direccion >= 1 && direccion <= Longitud) ) return NULO; // Llamar exception DireccionErr

    return Elementos[direccion];
}

int CListaVector::GetLongitud (){
    return Longitud;
}

void CListaVector::Inserta( DireccionListVec direccion, TipoDatoListVec elemento ){
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

	for( int i = Longitud + 1; i >= 2; i-- ){
		Elementos[i] = Elementos[i - 1];
	}

	Elementos[1] = elemento;
    Longitud = Longitud + 1;
}

void CListaVector::Inserta_ultimo( TipoDatoListVec elemento ){
	if( Longitud == MAX ) return ShowMessage("listallena");

	Longitud = Longitud + 1;
	Elementos[Longitud] = elemento;
}

void CListaVector::Suprime( DireccionListVec direccion ){
	if( Vacia() ) return; // Llamar exception ListaVacia
	if( !(direccion >= 1 && direccion <= Longitud) ) return; // Llamar exception DireccionErr

	for( int i = direccion; i <= Longitud - 1; i++ ){
		Elementos[i] = Elementos[i + 1];
	}

	Longitud = Longitud - 1;
}

void CListaVector::Modifica( DireccionListVec direccion, TipoDatoListVec elemento){
	if( Vacia() ) return; // Llamar exception ListaVacia
	if( !(direccion >= 1 && direccion <= Longitud) ) return; // Llamar exception DireccionErr

	Elementos[direccion] = elemento;
}

void CListaVector::MostrarLista( ){
	for( int i = 1; i <= Longitud; i++ ){
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
