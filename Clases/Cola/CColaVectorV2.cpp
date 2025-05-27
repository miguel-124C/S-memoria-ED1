//---------------------------------------------------------------------------

#pragma hdrstop

#include "CColaVectorV2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
void CColaVectorV2::Crear(){
	Fin = 0;
    Ini = 1;
}

bool CColaVectorV2::Vacia(){
    return Ini > Fin;
}

void CColaVectorV2::Poner( int elemento ){
	if( Fin < MAX ){
		Fin++;
		Vector[Fin] = elemento;
	}else {
		ShowMessage("El vector est� vacio");
	}
}

void CColaVectorV2::Sacar( int elemento ){
	if( !Vacia() ){
		elemento = Vector[1];
		Desplazar(1);
		Fin--;
	}else {
		ShowMessage("El vector est� vacio");
	}
}
void CColaVectorV2::Desplazar( int indice ){
    if( indice > Fin ) return;
	if( !Vacia() ){
		for( int i = indice; i <= Fin; i++ ){
			int a = Vector[i + 1];
            Vector[i + 1] = 0;
            Vector[i] = a;
		}
	}
}

int CColaVectorV2::Primero(){
	if( Vacia() ){
        ShowMessage("La cola est� vacia");
		return -1;
	}

	return Vector[1];
}

void CColaVectorV2::MostrarCola(){
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