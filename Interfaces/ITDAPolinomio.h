#ifndef ITDAPolinomio_H
#define ITDAPolinomio_H

#include <vcl.h>
#include <math.h>

class ITDAPolinomio{
public:

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

	void Sumar( ITDAPolinomio* P1, ITDAPolinomio* P2 ){
		//Poner polinomio en 0
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

	void GraficarPolinomio( ITDAPolinomio* P int x1, int x2, int x ){

	}

	virtual ~ITDAPolinomio() {}  // Destructor virtual
};

#endif
