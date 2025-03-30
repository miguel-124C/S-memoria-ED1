#ifndef ITDAPolinomio_H
#define ITDAPolinomio_H

#include <vcl.h>

class ITDAPolinomio{
private:
	virtual int BuscarExponente( int Exp ) = 0;
	virtual int BuscarTerminoN( int I ) = 0;
public:

	virtual void Crea() = 0;
	virtual bool EsCero() = 0;
	virtual int Grado() = 0;
	virtual int Coeficiente( int Exp ) = 0;
	virtual void AsignarCoeficiente( int Coef, int Exp ) = 0;
	virtual void PonerTermino( int Coef, int Exp ) = 0;
	virtual int NumeroTerminos() = 0;
	virtual int Exponente( int NroTermino ) = 0;

	void Sumar( ITDAPolinomio* P1, ITDAPolinomio* P2 ){
		//Poner polinomio en 0
		for( int i = 1; i < P1->NumeroTerminos(); i++ ){
			int exp = P1->Exponente( i );
			int coef = P1->Coeficiente( exp );
			PonerTermino( coef, exp );
		}

		for( int i = 1; i < P2->NumeroTerminos(); i++ ){
			int exp = P2->Exponente( i );
			int coef = P2->Coeficiente( exp );
			PonerTermino( coef, exp );
		}
	}
	void Restar( ITDAPolinomio* P1, ITDAPolinomio* P2 ){
		//Poner polinomio en 0
		for( int i = 1; i < P1->NumeroTerminos(); i++ ){
			int exp = P1->Exponente( i );
			int coef = P1->Coeficiente( exp );
			PonerTermino( coef, exp );
		}

		for( int i = 1; i < P2->NumeroTerminos(); i++ ){
			int exp = P2->Exponente( i );
			int coef = P2->Coeficiente( exp ) * -1;
			PonerTermino( coef, exp );
		}
	}
	void Multiplicar( ITDAPolinomio* P1, ITDAPolinomio* P2 ){
		// Desarrollar
	}

	virtual ~ITDAPolinomio() {}  // Destructor virtual
};

#endif
