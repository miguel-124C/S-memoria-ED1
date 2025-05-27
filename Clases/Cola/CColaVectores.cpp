//---------------------------------------------------------------------------

#pragma hdrstop

#include "CColaVectores.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void CColaVectores::Crear(){
	Fin = 0;
    Ini = 1;
}

bool CColaVectores::Vacia(){
    return Ini > Fin;
}

void CColaVectores::Poner( int elemento ){
	if( Fin < MAX ){
		Fin++;
		Vector[Fin] = elemento;
	}else {
		ShowMessage("El vector está vacio");
	}
}

void CColaVectores::Sacar( int elemento ){
	if( !Vacia() ){
		elemento = Vector[Ini];
        Ini++;
	}else {
		ShowMessage("El vector está vacio");
	}
}

int CColaVectores::Primero(){
	if( Vacia() ){
        ShowMessage("La cola está vacia");
		return -1;
	}

	return Vector[Ini];
}

void CColaVectores::MostrarCola(){
	for( int i = Ini; i <= Fin; i++ ){
    	int x2 = X1 + WidthField;
        int y2 = Y1 + HeightField;
		canvas->Brush->Color = (TColor)0xffffff;
		canvas->Rectangle(X1, Y1, x2, y2);

		canvas->Font->Size = 16;
		canvas->TextOut( X1 + 5, Y1 + 5, Vector[i] );

		X1 += WidthField;
	}

	X1 = 50;
}
