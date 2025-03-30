//---------------------------------------------------------------------------

#pragma hdrstop

#include "CPoliVector.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
void CPoliVector::Crea(){ NroTerminos = 0; }
bool CPoliVector::EsCero(){ return NroTerminos == 0; }

int CPoliVector::Grado(){
	if( EsCero() ){} // Exception Polinomio no tiene T�rminos;

	int MaxGrado = VE[1];

	for( int i = 1; i < NroTerminos; i++ ){
		if( VE[i] > MaxGrado ){
            MaxGrado = VE[i];
		}
	}

	return MaxGrado;
}

int CPoliVector::Coeficiente( int Exp ){
	if( !(Exp >= 0 && Exp <= Grado()) ){} // No existe termino con este Exponente

	for( int i = 1; i < NroTerminos; i++ ){
		if( VE[i] == Exp ) return VC[i];
	}
}

void CPoliVector::AsignarCoeficiente( int Coef, int Exp ){
	int Lug = GetLugarExp( Exp );
	if( Lug == -1 ){} // Exception no existe termino con ese exp;

	VC[Lug] = Coef;
	if( VC[Lug] == 0 ){
		// desplazar 1 elemento hacia la posicion lug 
		NroTerminos--;
	}
}

void CPoliVector::PonerTermino( int Coef, int Exp ){
	int Lug = GetLugarExp( Exp );
	if( Lug != -1 ){
		VC[Lug] = VC[Lug] + Coef;
		if( VC[Lug] == 0 ){
			// desplazar 1 elemento hacia la posicion lug 
			NroTerminos--;
		}
	}else{
		NroTerminos++;
		VC[NroTerminos] = Coef;
		VE[NroTerminos] = Exp;
	}
}

int CPoliVector::NumeroTerminos(){ return NroTerminos; }

int CPoliVector::Exponente( int NroTermino ){
    if( NroTermino > 0 && NroTermino <= NumeroTerminos() ){} // Exception No existe ese número de terminos;

    return VE[NroTermino];
}
