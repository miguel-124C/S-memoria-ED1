#ifndef ITDAPolinomio_H
#define ITDAPolinomio_H

#include <vcl.h>

template<typename T, typename D>
class ITDAPolinomio{
private:
	D BuscarExponente( int Exp );
    D BuscarTerminoN( int I );
public:

	void Crea();
	bool EsCero();
	int Grado();
	int Coeficiente( int Exp );
	void AsignarCoeficiente( int Coef, int Exp );
	void PonerTermino( int Coef, int Exp );
	int NumeroTerminos();
	int Exponente( int NroTerminos );
	void Sumar( T P1, T P2 );
	void Restar( T P1, T P2 );
	void Multiplicar( T P1, T P2 );

	virtual ~ITDAPolinomio() {}  // Destructor virtual
};

#endif
