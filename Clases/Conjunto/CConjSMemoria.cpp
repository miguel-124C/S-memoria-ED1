//---------------------------------------------------------------------------

#pragma hdrstop

#include "CConjSMemoria.h"

#include <random>
//---------------------------------------------------------------------------
#pragma package(smart_init)

void CConjSMemoria::Crear(){
	Cantidad = 0;
	PtrConj = -1;
}
bool CConjSMemoria::Pertenece( TDConjMem elemento ){
	bool Respuesta = false;
	int Pc = PtrConj;

	while( Pc != -1 ){
		if( M->ObtieneDato(Pc, "Dato") == elemento ){
			Respuesta = true;
			Pc = -1;
		}else{
			Pc = M->ObtieneDato(Pc, "Sig");
        }
	}

    return Respuesta;
}
void CConjSMemoria::Inserta( TDConjMem elemento ){
	if( Pertenece( elemento ) ) return ShowMessage("Elemento ya existe");

	int Dir = M->NewEspacio("Dato,Sig");
	if( Dir == -1 ) return ShowMessage("No existe espacio en memoria");

	M->PonerDato(Dir, "Dato", elemento);
	M->PonerDato(Dir, "Sig", PtrConj);
	PtrConj = Dir;
	Cantidad++;
}
int CConjSMemoria::Cardinal(){
    return Cantidad;
}
int CConjSMemoria::Ordinal( TDConjMem elemento ){
	int Respuesta = 0;
	int Pc = PtrConj;
	while( Pc != -1 ){
		Respuesta++;
		if( M->ObtieneDato(Pc, "Dato") == elemento ){
            Pc = -1;
			break;
		}else{
            Pc = M->ObtieneDato(Pc, "Sig");
        }
	}

    return Respuesta;
}
void CConjSMemoria::Suprime( TDConjMem elemento ){
	int Dir = -1;
	int Pc = PtrConj;

	while( Pc != -1 ){
		if( M->ObtieneDato(Pc, "Dato") == elemento ){
			Dir = Pc;
            Pc = -1;
		}else{
			Pc = M->ObtieneDato(Pc, "Sig");
        }
	}

    M->DeleteEspacio( Dir );
}
TDConjMem CConjSMemoria::Muestrea(){
	if( Cantidad > 0 ){
		int Lugar = 0;
		std::random_device rd;
		std::mt19937 gen(rd()); // Motor Mersenne Twister
		std::uniform_int_distribution<> distrib(1, Cantidad); // Entre 1 y Cantidad

		int LugarBuscado = distrib(gen);
		int Pc = PtrConj;
        TDConjMem Elemento;

		while( Pc != -1 ){
            Lugar++;
			if( LugarBuscado == Lugar ){
				Elemento = M->ObtieneDato(Pc, "Dato");
				Pc = -1;
			}else{
				Pc = M->ObtieneDato(Pc, "Sig");
			}
		}

        return Elemento;
	}

	return 0;
}

void CConjSMemoria::MostrarConjunto(){

}