//---------------------------------------------------------------------------

#pragma hdrstop

#include "CPoliListaVector.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

int CPoliListaVector::BuscarExponente( int Exp ){
	int Dir = Pol->Siguiente( Pol->Primero() );
	if( Dir == Nulo ){} // Exception Polinomio no tiene T�rminos;

	int DirExp = Nulo;

	while( Dir != Nulo && DirExp == Nulo ){
		if( Pol->Recupera( Dir ) == Exp ){
			DirExp = Dir;
		}

		Dir = Pol->Siguiente( Pol->Siguiente( Dir ) );
	}

	return DirExp;
}

int CPoliListaVector::BuscarTerminoN( int I ){
	int Dir = Pol->Primero();
	int NumeroTermino = 0;

	if( Dir == Nulo ){} // Exception Polinomio no tiene T�rminos;

	int DirTermino = Nulo;

	while( Dir != Nulo && DirTermino == Nulo ){
		NumeroTermino++;

		if( NumeroTermino == I ){
			DirTermino = Dir;
		}

		Dir = Pol->Siguiente( Pol->Siguiente( Dir ) );
	}

	return DirTermino;
}

void CPoliListaVector::Crea(){ Pol->Crear(); }
bool CPoliListaVector::EsCero(){ return Pol->Vacia(); }

int CPoliListaVector::Grado(){
	int Dir = Pol->Siguiente( Pol->Primero() );

	if( Dir != Nulo ){} // Exception Polinomio no tiene T�rminos;

	int MaxGrado = Pol->Recupera(Dir);

	while( Dir != Nulo ){
		if( Pol->Recupera(Dir) > MaxGrado ){
			MaxGrado = Pol->Recupera(Dir);
		}

		Dir = Pol->Siguiente(Pol->Siguiente( Dir ));
	}

	return MaxGrado;
}

int CPoliListaVector::Coeficiente( int Exp ){
	int Dir = BuscarExponente( Exp );
	if( Dir == Nulo ){} // Exception Polinomio no tiene T�rminos;

    return Pol->Recupera( Pol->Anterior( Dir ) );
}

void CPoliListaVector::AsignarCoeficiente( int Coef, int Exp ){
    int Dir = BuscarExponente( Exp );
	if( Dir == Nulo ){} // Exception Polinomio no tiene T�rminos;

	int DirCoef = Pol->Anterior( Dir );
	Pol->Modifica( DirCoef, Coef );

	if( Coef == 0 ){
		Pol->Suprime( Dir );
        Pol->Suprime( DirCoef );
	}
}

void CPoliListaVector::PonerTermino( int Coef, int Exp ){
	int DirExp = BuscarExponente( Exp );

	if( DirExp != Nulo ){
		int DirCoef = Pol->Anterior( DirExp );
		Pol->Modifica( DirCoef, Pol->Recupera( DirCoef ) + Coef );

		if( Pol->Recupera( DirCoef ) == 0 ){
			Pol->Suprime( DirExp );
			Pol->Suprime( DirCoef );
		}
	}else{
		if( Coef != 0 ){
			Pol->Inserta_ultimo( Exp );
            Pol->Inserta( Pol->Fin(), Coef );
		}
	}
}

int CPoliListaVector::NumeroTerminos(){ return Pol->Longitud / 2; }

int CPoliListaVector::Exponente( int NroTermino ){
	int Dir = BuscarTerminoN( NroTermino );
    if( Dir == Nulo ){} // Exception No existe ese número de terminos;

    return Pol->Recupera( Pol->Siguiente( Dir ) );
}
