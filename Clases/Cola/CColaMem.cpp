//---------------------------------------------------------------------------

#pragma hdrstop

#include "CColaMem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

#pragma hdrstop

#include "CColaVectores.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void CColaMem::Crear(){
	Fin = -1;
    Ini = -1;
}

bool CColaMem::Vacia(){
    return Ini == -1;
}

void CColaMem::Poner( int elemento ){
	int aux = Mem->NewEspacio("Elemento");
	if( aux == -1 ) return ShowMessage("Error");

	Mem->PonerDato( aux, "Elemento", elemento );
	Mem->PonerDato( aux, "Sig", -1 );
	if( Vacia() ){
		Ini = aux;
		Fin = aux;
	}else {
		Mem->PonerDato( Fin, "Sig", aux );
        Fin = aux;
    }
}

void CColaMem::Sacar( int elemento ){
	if( !Vacia() ){
		elemento = Mem->ObtieneDato( Ini, "Elemento" );
		int x = Ini;
        Ini = Mem->ObtieneDato( Ini, "Sig" );
        Mem->DeleteEspacio( x );
	}else {
		ShowMessage("El vector est� vacio");
	}
}

int CColaMem::Primero(){
	if( Vacia() ){
        ShowMessage("La cola esta vacia");
		return -1;
	}

	return Mem->ObtieneDato( Ini, "Elemento" );
}

void CColaMem::MostrarCola(){

}