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
    return ( Ini > Fin );
}

void CColaVectores::Poner( int elemento ){
	if( !Vacia() ){
		if( Siguiente( Siguiente( Fin ) != Ini ) ){
			Fin = Siguiente( Fin );
			Vector[Fin] = elemento;
		}
	}else {
		ShowMessage("El vector está vacio");
	}
}

void CColaVectores::Sacar( int elemento ){
	if( !Vacia() ){
		elemento = Vector[Ini];
        Ini = Siguiente( Ini );
	}else {
		ShowMessage("El vector está vacio");
	}
}
void CColaVectores::Desplazar( int indice ){
    if( indice > Fin ) return;
	if( !Vacia() ){
		for( int i = indice; i <= Fin; i++ ){
			int a = Vector[i + 1];
            Vector[i + 1] = 0;
            Vector[i] = a;
		}
	}
}
int CColaVectores::Siguiente( int direccion ){
	if( direccion == MAX ) return 1;

    return direccion + 1;
}

int CColaVectores::Primero(){
	if( Vacia() ){
        ShowMessage("La cola está vacia");
		return -1;
	}

	return Vector[Ini];
}

void CColaVectores::MostrarCola(){

}
