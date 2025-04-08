//---------------------------------------------------------------------------

#pragma hdrstop

#include "CPoliListaSMem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

int CPoliListaSMem::BuscarExponente( int Exp ){
	int Dir = Pol->Siguiente( Pol->Primero() );
	if( Dir == Nulo ) return Nulo; // Exception Polinomio no tiene T�rminos;

	int DirExp = Nulo;

	while( Dir <= NumeroTerminos() && DirExp == Nulo ){
		if( Pol->Recupera( Dir ) == Exp ){
			DirExp = Dir;
		}

		Dir = Pol->Siguiente( Pol->Siguiente( Dir ) );
	}

	return DirExp;
}

int CPoliListaSMem::BuscarTerminoN( int I ){
	int Dir = Pol->Primero();
	int NumeroTermino = 0;

	if( Dir == Nulo ){} // Exception Polinomio no tiene T�rminos;

	int DirTermino = Nulo;

	while( Dir <= NumeroTerminos() && DirTermino == Nulo ){
		NumeroTermino++;

		if( NumeroTermino == I ){
			DirTermino = Dir;
		}

		Dir = Pol->Siguiente( Pol->Siguiente( Dir ) );
	}

	return DirTermino;
}

void CPoliListaSMem::Crea(){ Pol->Crear(); }
bool CPoliListaSMem::EsCero(){ return Pol->Vacia(); }

int CPoliListaSMem::Grado(){
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

int CPoliListaSMem::Coeficiente( int Exp ){
	int Dir = BuscarExponente( Exp );
	if( Dir == Nulo ){} // Exception Polinomio no tiene T�rminos;

    return Pol->Recupera( Pol->Anterior( Dir ) );
}

void CPoliListaSMem::AsignarCoeficiente( int Coef, int Exp ){
    int Dir = BuscarExponente( Exp );
	if( Dir == Nulo ){} // Exception Polinomio no tiene T�rminos;

	int DirCoef = Pol->Anterior( Dir );
	Pol->Modifica( DirCoef, Coef );

	if( Coef == 0 ){
		Pol->Suprime( Dir );
        Pol->Suprime( DirCoef );
	}
}

void CPoliListaSMem::PonerTermino( int Coef, int Exp ){
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

int CPoliListaSMem::NumeroTerminos(){ return Pol->Longitud / 2; }

int CPoliListaSMem::Exponente( int NroTermino ){
	int Dir = BuscarTerminoN( NroTermino );
    if( Dir == Nulo ){} // Exception No existe ese número de terminos;

    return Pol->Recupera( Pol->Siguiente( Dir ) );
}

void CPoliListaSMem::Evalua( int X ){
	int resultado = 0;
	if( NumeroTerminos() == 0 ) return ShowMessage("No existe ningun término");

	for( int i = 1; i <=  NumeroTerminos(); i++ ){
		int Exp = Exponente( i );
		int Coef = Coeficiente( Exp );

		resultado += Coef * pow( X, Exp );
	}

	AnsiString Message = "Para X = " + IntToStr(X) + " el resultado es: " + IntToStr(resultado);
	ShowMessage( Message );
}

void CPoliListaSMem::MostrarPolinomio(){
	if( NumeroTerminos() == 0 ) return ShowMessage("No existe ningun término");

	AnsiString Polinomio;
	for( int i = 1; i <= NumeroTerminos(); i++ ){
		int Exp = Exponente( i );
		int Coef = Coeficiente( Exp );

		AnsiString signo = Coef > 0 ? "+" : "-";
        Polinomio += signo + IntToStr(Coef) + "X^" + IntToStr(Exp);
	}

    Canvas->Font->Size = 18;
	Canvas->TextOut(50, 500, "Polinomio: " +  Polinomio);
}
