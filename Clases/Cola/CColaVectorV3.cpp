//---------------------------------------------------------------------------

#pragma hdrstop

#include "CColaVectorV3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
void CColaVectorV3::Crear(){
	Fin = 0;
    Ini = 1;
}

bool CColaVectorV3::Vacia(){
    return Siguiente( Fin ) == Ini;
}

void CColaVectorV3::Poner( int elemento ){
	if( Siguiente( Siguiente( Fin ) != Ini ) ){
		Fin = Siguiente( Fin );
		Vector[Fin] = elemento;
	}else {
		ShowMessage("El vector está vacio");
	}
}

void CColaVectorV3::Sacar( int elemento ){
	if( !Vacia() ){
		elemento = Vector[Ini];
        Ini = Siguiente( Ini );
	}else {
		ShowMessage("El vector está vacio");
	}
}
int CColaVectorV3::Siguiente( int direccion ){
	if( direccion == MAX ) return 1;

    return direccion + 1;
}

int CColaVectorV3::Primero(){
	if( Vacia() ){
        ShowMessage("La cola est� vacia");
		return -1;
	}

	return Vector[Ini];
}

void CColaVectorV3::MostrarCola(){
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