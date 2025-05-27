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
	Lista->Inserta_ultimo(elemento);
}

void CColaLista::Sacar( TElementoCola elemento ){
	Lista->Recupera( Lista->Primero() );
    Lista->Suprime( Lista->Primero() );
}

TElementoCola CColaLista::Primero(){
	TElementoCola elemento = Lista->Recupera( Lista->Fin() );
	return elemento;
}

void CColaLista::MostrarCola(){
	if( Vacia() ) return ShowMessage("Lista Vacia");

	int x = Lista->PtrElementos;

	while( x != -1 ){
		int Elemento = Lista->Memoria->ObtieneDato( x, "Elemento" );

        int x2 = X1 + WidthField;
		int y2 = Y1 + HeightField;
		canvas->Brush->Color = (TColor)0xffffff;
		canvas->Rectangle(X1, Y1, x2, y2);

		canvas->Font->Size = 16;
		canvas->TextOut( X1 + 5, Y1 + 5, Elemento );

		X1 += WidthField;

		x = Lista->Memoria->ObtieneDato( x, "Sig" );
	}

	X1 = 50;
}