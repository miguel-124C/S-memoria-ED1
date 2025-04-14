//---------------------------------------------------------------------------

#pragma hdrstop

#include "CPoliSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

CPoliSMemoria::CPoliSMemoria( ISMemoria<DirPolSMem>* memoria, TCanvas* canvas ){
	Memoria = memoria;
    Canvas = canvas;
}

int CPoliSMemoria::BuscarExponente( int Exp ){
	DirPolSMem Dir = PtrPoli;
	if( Dir == Memoria->Nulo() ){
        return Memoria->Nulo();
	} // exception no existe ese termino

	DirPolSMem DirExp = Memoria->Nulo();

	while( Dir != Memoria->Nulo() && DirExp == Memoria->Nulo() ){
		if( Memoria->ObtieneDato(Dir, "Exp") == Exp ){
			DirExp = Dir;
		}

		Dir = Memoria->ObtieneDato(Dir, "Sig");
	}

	return DirExp;
}

int CPoliSMemoria::BuscarTerminoN( int I ){
	DirPolSMem Dir = PtrPoli;

	if( Dir == Memoria->Nulo() ){} // exception no existe ese termino

	int DirTermino = Memoria->Nulo();
    int NroTerminos = 0;

	while( Dir != Memoria->Nulo() && DirTermino == Memoria->Nulo() ){
		NroTerminos++;

		if( NroTerminos == I ){
			DirTermino = Dir;
		}

		Dir = Memoria->ObtieneDato(Dir, "Sig");
	}

	return DirTermino;
}

int CPoliSMemoria::BuscarDirTerminoAnterior( int DirActual ){
	DirPolSMem Dir = PtrPoli;

	if( Dir == Memoria->Nulo() ){} // exception no existe ese termino

	int DirTermino = Memoria->Nulo();

	while( Dir != Memoria->Nulo() && DirTermino == Memoria->Nulo() ){
		if( Memoria->ObtieneDato(Dir, "Sig") == DirActual ){
			DirTermino = Dir;
		}

		Dir = Memoria->ObtieneDato(Dir, "Sig");
	}

	return DirTermino;
}

void CPoliSMemoria::Crea(){
	NroTerminos = 0;
	PtrPoli = Memoria->Nulo();
}

bool CPoliSMemoria::EsCero(){ return NroTerminos == 0; }

int CPoliSMemoria::Grado(){
	DirPolSMem Dir = PtrPoli;
    if( Dir == Memoria->Nulo() ){} // exception no existe ese termino

	int MaxGrado = Memoria->ObtieneDato(Dir, "Exp");

	while( Dir != Memoria->Nulo()){
		if( Memoria->ObtieneDato(Dir, "Exp") > MaxGrado ){
			MaxGrado = Memoria->ObtieneDato(Dir, "Exp");
		}

		Dir = Memoria->ObtieneDato(Dir, "Sig");
	}

	return MaxGrado;
}

int CPoliSMemoria::Coeficiente( int Exp ){
    DirPolSMem Dir = BuscarExponente( Exp );
	if( Dir == Memoria->Nulo() ){} // exception no existe ese termino

	return Memoria->ObtieneDato(Dir, "Coef");
}

void CPoliSMemoria::AsignarCoeficiente( int Coef, int Exp ){
	DirPolSMem Dir = BuscarExponente( Exp );
	if( Dir == Memoria->Nulo() ){} // exception no existe ese termino

	Memoria->PonerDato(Dir, "Coef", Coef);
	if( Coef == 0 ){
		int DirNuevoSig = Memoria->ObtieneDato( Dir, "Sig" );
		if( Dir == PtrPoli ){
			PtrPoli = DirNuevoSig;
		}else{
			int DirAnterior = BuscarDirTerminoAnterior( Dir );
			Memoria->PonerDato( DirAnterior, "Sig", DirNuevoSig );
		}

		Memoria->DeleteEspacio( Dir );
		NroTerminos--;
	}
}

void CPoliSMemoria::PonerTermino( int Coef, int Exp ){
    if( Coef == 0 ) return;

	DirPolSMem Dir = BuscarExponente( Exp );
	if( Dir == Memoria->Nulo() ){
		int Aux = Memoria->NewEspacio("Coef,Exp,Sig");
        if( Aux == Memoria->Nulo() ) return ShowMessage("Error espacio memoria");

		Memoria->PonerDato( Aux, "Coef", Coef );
		Memoria->PonerDato( Aux, "Exp", Exp );
		Memoria->PonerDato( Aux, "Sig", PtrPoli );
		PtrPoli = Aux;
        NroTerminos++;
	}else{
		int NuevoCoef = Memoria->ObtieneDato( Dir, "Coef" ) + Coef;
		Memoria->PonerDato( Dir, "Coef", NuevoCoef );

		if( NuevoCoef == 0 ){
			int DirNuevoSig = Memoria->ObtieneDato( Dir, "Sig" );
			if( Dir == PtrPoli ){
				PtrPoli = DirNuevoSig;
			}else{
				int DirAnterior = BuscarDirTerminoAnterior( Dir );
				Memoria->PonerDato( DirAnterior, "Sig", DirNuevoSig );
			}

			Memoria->DeleteEspacio( Dir );
			NroTerminos--;
		}
	}
}

int CPoliSMemoria::NumeroTerminos(){ return NroTerminos; }

int CPoliSMemoria::Exponente( int NroTermino ){
    DirPolSMem Dir = BuscarTerminoN( NroTermino );
    if( Dir == Memoria->Nulo() ){} // no existe ese termino

    return Memoria->ObtieneDato(Dir, "Exp");
}

void CPoliSMemoria::Evalua( int X ){
	int resultado = 0;

	DirPolSMem Dir = PtrPoli;

	if( Dir == Memoria->Nulo() ) return ShowMessage("No existe ningun término");

	while( Dir != Memoria->Nulo()){
		int Coef = Memoria->ObtieneDato(Dir, "Coef");
		int Exp = Memoria->ObtieneDato(Dir, "Exp");

		resultado += Coef * pow( X, Exp );

		Dir = Memoria->ObtieneDato(Dir, "Sig");
	}

    AnsiString Message = "Para X = " + IntToStr(X) + " el resultado es: " + IntToStr(resultado);
	ShowMessage( Message );
}

void CPoliSMemoria::MostrarPolinomio(){
	DirPolSMem Dir = PtrPoli;

	if( Dir == Memoria->Nulo() ) return ShowMessage("No existe ningun término");

	AnsiString Polinomio;
	while( Dir != Memoria->Nulo()){
		int Coef = Memoria->ObtieneDato(Dir, "Coef");
		int Exp = Memoria->ObtieneDato(Dir, "Exp");

		AnsiString signo = Coef > 0 ? "+" : "-";

		Polinomio += signo + IntToStr(Coef) + "X^" + IntToStr(Exp);

		Dir = Memoria->ObtieneDato(Dir, "Sig");
	}

    Canvas->Font->Size = 18;
	Canvas->TextOut(50, 700, "Polinomio: " +  Polinomio);
}

void CPoliSMemoria::VaciarPolinomio( ){
	DirPolSMem Dir = PtrPoli;
    int DirDelete;

	if( Dir == Memoria->Nulo() ){} // exception no existe ese termino

	while( Dir != Memoria->Nulo()){
	    DirDelete = Dir;
		Memoria->PonerDato( Dir, "Coef", 0 );
		Memoria->PonerDato( Dir, "Exp", 0 );

		Dir = Memoria->ObtieneDato(Dir, "Sig");

		Memoria->PonerDato( DirDelete, "Sig", 0 );
        Memoria->DeleteEspacio( DirDelete );
	}

    Crea();
}
