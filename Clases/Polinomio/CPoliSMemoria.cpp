//---------------------------------------------------------------------------

#pragma hdrstop

#include "CPoliSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

int CPoliSMemoria::BuscarExponente( int Exp ){
	DirPolSMem Dir = PtrPoli;
	if( Dir == Memoria->Nulo() ){} // exception no existe ese termino

	DirPolSMem DirExp = Memoria->Nulo();

	while( Dir != Memoria->Nulo() && DirExp == Memoria->Nulo() ){
		if( Memoria->ObtieneDato(Dir, 'Exp') == Exp ){
			DirExp = Dir;
		}

		Dir = Memoria->ObtieneDato(Dir, 'Sig');
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

		Dir = Memoria->ObtieneDato(Dir, 'Sig');
	}

	return DirTermino;
}

void CPoliSMemoria::Crea(){
	NroTerminos = 0;
	PtrPoli = Memoria->Nulo();
    Memoria = new CSMemoria();
}

bool CPoliSMemoria::EsCero(){ return NroTerminos == 0; }

int CPoliSMemoria::Grado(){
	DirPolSMem Dir = PtrPoli;
    if( Dir == Memoria->Nulo() ){} // exception no existe ese termino

	int MaxGrado = Memoria->ObtieneDato(Dir, 'Exp');

	while( Dir != Memoria->Nulo()){
		if( Memoria->ObtieneDato(Dir, 'Exp') > MaxGrado ){
			MaxGrado = Memoria->ObtieneDato(Dir, 'Exp');
		}

		Dir = Memoria->ObtieneDato(Dir, 'Sig');
	}

	return MaxGrado;
}

int CPoliSMemoria::Coeficiente( int Exp ){
    DirPolSMem Dir = BuscarExponente( Exp );
	if( Dir == Memoria->Nulo() ){} // exception no existe ese termino

	return Memoria->ObtieneDato(Dir, 'Coef');
}

void CPoliSMemoria::AsignarCoeficiente( int Coef, int Exp ){
	DirPolSMem Dir = BuscarExponente( Exp );
	if( Dir == Memoria->Nulo() ){} // exception no existe ese termino

	Memoria->PonerDato(Dir, 'Coef', Coef);
	if( Coef == 0 ){
        Memoria->DeleteEspacio( Dir );
		NroTerminos--;
	}
}

void CPoliSMemoria::PonerTermino( int Coef, int Exp ){
	DirPolSMem Dir = BuscarExponente( Exp );
	if( Dir == Memoria->Nulo() ){
		int Aux = Memoria->NewEspacio("Coef,Exp,Sig");
        if( Aux == Memoria->Nulo() ){} //error espacio memoria

		Memoria->PonerDato( Aux, "Coef", Coef );
		Memoria->PonerDato( Aux, "Exp", Exp );
		Memoria->PonerDato( Aux, "Sig", PtrPoli );
		PtrPoli = Aux;
        NroTerminos++;
	}else{
		int NuevoCoef = Memoria->ObtieneDato( Dir, "Coef" ) + Coef;
		Memoria->PonerDato( Dir, "Coef", NuevoCoef );

		if( NuevoCoef == 0 ){
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
