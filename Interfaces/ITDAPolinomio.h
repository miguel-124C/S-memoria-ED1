#ifndef ITDAPolinomio_H
#define ITDAPolinomio_H

#include <vcl.h>
#include <math.h>

#include "./Utils/PlanoCartesiano.h"

class ITDAPolinomio{
public:

    PlanoCartesiano* plano;
    TCanvas* Canvas;

	virtual void Crea() = 0;
	virtual bool EsCero() = 0;
	virtual int Grado() = 0;
	virtual int Coeficiente( int Exp ) = 0;
	virtual void AsignarCoeficiente( int Coef, int Exp ) = 0;
	virtual void PonerTermino( int Coef, int Exp ) = 0;
	virtual int NumeroTerminos() = 0;
	virtual int Exponente( int NroTermino ) = 0;
	virtual void Evalua( int X ) = 0;

	virtual void MostrarPolinomio() = 0;
	virtual void VaciarPolinomio() = 0;

	void setCanvas( TCanvas* canvas ){
		this->Canvas = canvas;
        plano = new PlanoCartesiano( canvas );
	}

	void Sumar( ITDAPolinomio* P1, ITDAPolinomio* P2 ){
		//Poner polinomio en 0
		VaciarPolinomio();
		for( int i = 1; i <= P1->NumeroTerminos(); i++ ){
			int exp = P1->Exponente( i );
			int coef = P1->Coeficiente( exp );
			PonerTermino( coef, exp );
		}

		for( int i = 1; i <= P2->NumeroTerminos(); i++ ){
			int exp = P2->Exponente( i );
			int coef = P2->Coeficiente( exp );
			PonerTermino( coef, exp );
		}
	}

	void Restar( ITDAPolinomio* P1, ITDAPolinomio* P2 ){
		//Poner polinomio en 0
        VaciarPolinomio();
		for( int i = 1; i <= P1->NumeroTerminos(); i++ ){
			int exp = P1->Exponente( i );
			int coef = P1->Coeficiente( exp );
			PonerTermino( coef, exp );
		}

		for( int i = 1; i <= P2->NumeroTerminos(); i++ ){
			int exp = P2->Exponente( i );
			int coef = P2->Coeficiente( exp ) * -1;
			PonerTermino( coef, exp );
		}
	}

	void Multiplicar( ITDAPolinomio* P1, ITDAPolinomio* P2 ){
		// Desarrollar
		VaciarPolinomio();
        for( int i = 1; i <= P1->NumeroTerminos(); i++ ){
			int ExpP1 = P1->Exponente( i );
			int CoefP1 = P1->Coeficiente( ExpP1 );

			for( int j = 1; j <= P2->NumeroTerminos(); j++ ){
				int ExpP2 = P2->Exponente( j );
				int CoefP2 = P2->Coeficiente( ExpP2 );

				int Coef = CoefP1 * CoefP2;
				int Exp = ExpP1 + ExpP2;

				PonerTermino( Coef, Exp );
			}
		}
	}

	void Derivada( ITDAPolinomio* P1, ITDAPolinomio* P2 ){
		for( int i = 1; i <= P1->NumeroTerminos(); i++ ){
			int exp = P1->Exponente( i );
			int coef = P1->Coeficiente( exp );

			P2->PonerTermino( coef * exp , exp - 1 );
		}
	}

	void MostrarIntegral( ITDAPolinomio* P1 ){
		AnsiString Integral;
		for( int i = 1; i <= P1->NumeroTerminos(); i++ ){
			int exp = P1->Exponente( i );
			int coef = P1->Coeficiente( exp );
			Integral = "("+ IntToStr(coef) + "X^" + IntToStr(exp + 1) + ") /" + IntToStr(exp+1) + "+";
		}

		Integral += "C";
		ShowMessage( Integral );
	}

	void GraficarPolinomio( ITDAPolinomio* P, float x1, float x2, float s ){
		if( x1 > x2 ) return ShowMessage("El limite inferior no puede ser mayor");
        if( x1 == x2 ) return ShowMessage("Rangos iguales");

        plano->GraficaPlano( x1, x2 );

		float y = 0;
		int cantPuntos = 0;
		float coordx1; float coordy1;
//      for( float x = plano->limitePlano * -1; x <= plano->limitePlano; x += s ){
		for( float x = x1; x <= x2; x += s ){
			for( int i = 1; i <= P->NumeroTerminos(); i++ ){
				int exp = P->Exponente( i );
				int coef = P->Coeficiente( exp );

				y += coef * pow( x, exp );
			}

			cantPuntos++;
			if( cantPuntos > 1 ){
				plano->GraficaLinea( coordx1, coordy1, x, y );
			}

			coordx1 = x; coordy1 = y;
			y = 0;
		}
	}

	virtual ~ITDAPolinomio() {}  // Destructor virtual
};

#endif
