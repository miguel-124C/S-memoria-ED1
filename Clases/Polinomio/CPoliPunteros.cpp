//---------------------------------------------------------------------------

#pragma hdrstop

#include "CPoliPunteros.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


NodoPoli* CPoliPuntero::BuscarExponente( int Exp ){
	NodoPoli* Dir = PtrPoli;
	if( Dir == nullptr ){} // exception no existe ese termino

	NodoPoli* DirExp = nullptr;

	while( Dir != nullptr && DirExp == nullptr ){
		if( Dir->Exp == Exp ){
			DirExp = Dir;
		}

		Dir = Dir->Sig;
	}

	return DirExp;
}

NodoPoli* CPoliPuntero::BuscarTerminoN( int I ){
	NodoPoli* Dir = PtrPoli;

	if( Dir == nullptr ){} // exception no existe ese termino

	NodoPoli* DirTermino = nullptr;
    int NroTerminos = 0;

	while( Dir != nullptr && DirTermino == nullptr ){
		NroTerminos++;

		if( NroTerminos == I ){
			DirTermino = Dir;
		}

		Dir = Dir->Sig;
	}

	return DirTermino;
}

NodoPoli* CPoliPuntero::BuscarDirTerminoAnterior( NodoPoli* DirActual ){
	NodoPoli* Dir = PtrPoli;

	if( Dir == nullptr ){} // exception no existe ese termino

	NodoPoli* DirTermino = nullptr;

	while( Dir != nullptr && DirTermino == nullptr ){
		if( Dir->Sig == DirActual ){
			DirTermino = Dir;
		}

		Dir = Dir->Sig;
	}

	return DirTermino;
}

void CPoliPuntero::Crea(){
	NroTerminos = 0;
	PtrPoli = nullptr;
}

bool CPoliPuntero::EsCero(){ return NroTerminos == 0; }

int CPoliPuntero::Grado(){
	NodoPoli* Dir = PtrPoli;
    if( Dir == nullptr ){} // exception no existe ese termino

	int MaxGrado = Dir->Exp;

	while( Dir != nullptr){
		if( Dir->Exp > MaxGrado ){
			MaxGrado = Dir->Exp;
		}

		Dir = Dir->Sig;
	}

	return MaxGrado;
}

int CPoliPuntero::Coeficiente( int Exp ){
    NodoPoli* Dir = BuscarExponente( Exp );
	if( Dir == nullptr ){} // exception no existe ese termino

	return Dir->Coef;
}

void CPoliPuntero::AsignarCoeficiente( int Coef, int Exp ){
	NodoPoli* Dir = BuscarExponente( Exp );
	if( Dir == nullptr ){} // exception no existe ese termino

	Dir->Coef = Coef;
	if( Coef == 0 ){
        delete( Dir );
		NroTerminos--;
	}
}

void CPoliPuntero::PonerTermino( int Coef, int Exp ){
	NodoPoli* Dir = BuscarExponente( Exp );
	if( Dir == nullptr ){
		NodoPoli* Aux = new NodoPoli;
        if( Aux == nullptr ) return ShowMessage("Error espacio memoria");

		Aux->Coef = Coef;
		Aux->Exp = Exp;
		Aux->Sig = PtrPoli;
		PtrPoli = Aux;
        NroTerminos++;
	}else{
		int NuevoCoef = Dir->Coef + Coef;
		Dir->Coef = NuevoCoef;

		if( NuevoCoef == 0 ){
			NodoPoli* DirNuevoSig = Dir->Sig;
			if( Dir == PtrPoli ){
				PtrPoli = DirNuevoSig;
			}else{
				NodoPoli* DirAnterior = BuscarDirTerminoAnterior( Dir );
				DirAnterior->Sig = DirNuevoSig;
			}

			delete( Dir );
			NroTerminos--;
		}
	}
}

int CPoliPuntero::NumeroTerminos(){ return NroTerminos; }

int CPoliPuntero::Exponente( int NroTermino ){
    NodoPoli* Dir = BuscarTerminoN( NroTermino );
	if( Dir == nullptr ){} // no existe ese termino

    return Dir->Exp;
}

void CPoliPuntero::Evalua( int X ){
	int resultado = 0;

	NodoPoli* Dir = PtrPoli;

	if( Dir == nullptr ) return ShowMessage("No existe ningun t�rmino");

	while( Dir != nullptr){
		int Coef = Dir->Coef;
		int Exp = Dir->Exp;

		resultado += Coef * pow( X, Exp );

		Dir = Dir->Sig;
	}

    AnsiString Message = "Para X = " + IntToStr(X) + " el resultado es: " + IntToStr(resultado);
	ShowMessage( Message );
}

void CPoliPuntero::MostrarPolinomio(){
	NodoPoli* Dir = PtrPoli;

	if( Dir == nullptr ) return ShowMessage("No existe ningun t�rmino");

	AnsiString Polinomio;
	while( Dir != nullptr){
		int Coef = Dir->Coef;
		int Exp = Dir->Exp;

		AnsiString signo = Coef > 0 ? "+" : "-";

		Polinomio += signo + IntToStr(Coef) + "X^" + IntToStr(Exp);

		Dir = Dir->Sig;
	}

    Canvas->Font->Size = 18;
	Canvas->TextOut(50, 700, "Polinomio: " +  Polinomio);
}

void CPoliPuntero::VaciarPolinomio(){
}
