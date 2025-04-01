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

	for( int i = 1; i <= NroTerminos; i++ ){
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
	if( Lug == -1 ){
		NroTerminos++;
		VC[NroTerminos] = Coef;
		VE[NroTerminos] = Exp;
	}else{
		VC[Lug] = VC[Lug] + Coef;
		if( VC[Lug] == 0 ){
			// desplazar 1 elemento hacia la posicion lug
			for( int i = Lug; i <= NroTerminos; i++ ){
				VC[i] = VC[i + 1];
				VE[i] = VE[i + 1];
			}
			NroTerminos--;
		}
	}
}

int CPoliVector::NumeroTerminos(){ return NroTerminos; }

int CPoliVector::Exponente( int NroTermino ){
    if( NroTermino > 0 && NroTermino <= NumeroTerminos() ){} // Exception No existe ese número de terminos;

    return VE[NroTermino];
}

void CPoliVector::Evalua( int X ){
	int resultado = 0;
	if( NroTerminos == 0 ) return ShowMessage("No existe ningun término");

	for( int i = 1; i <= NroTerminos; i++ ){
		int Coef = VC[i];
		int Exp = VE[i];

		resultado += Coef * pow( X, Exp );
	}

	AnsiString Message = "Para X = " + IntToStr(X) + " el resultado es: " + IntToStr(resultado);
	ShowMessage( Message );
}

void CPoliVector::MostrarPolinomio(){
	if( NroTerminos == 0 ) return ShowMessage("No existe ningun término");

	AnsiString Polinomio;
	for( int i = 1; i <= NroTerminos; i++ ){
		int Coef = VC[i];
		int Exp = VE[i];

		AnsiString signo = Coef > 0 ? "+" : "-";
        Polinomio += signo + IntToStr(Coef) + "X^" + IntToStr(Exp);
	}

    Canvas->Font->Size = 18;
	Canvas->TextOut(50, 700, "Polinomio: " +  Polinomio);
}
