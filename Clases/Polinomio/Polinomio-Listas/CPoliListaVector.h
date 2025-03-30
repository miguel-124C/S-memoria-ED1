//---------------------------------------------------------------------------

#ifndef CPoliListaVectorH
#define CPoliListaVectorH
//---------------------------------------------------------------------------

#include "../Clases/Listas/CListaVector.h"
#include "../Interfaces/ITDAPolinomio.h"

class CPoliListaVector : public ITDAPolinomio{
private:
	int BuscarExponente( int Exp ) override;
	int BuscarTerminoN( int I ) override;
public:

	CListaVector* Pol = new CListaVector();
    static const int Nulo = 0;

	void Crea() override ;
	bool EsCero() override;
	int Grado() override;
	int Coeficiente( int Exp ) override;
	void AsignarCoeficiente( int Coef, int Exp ) override;
	void PonerTermino( int Coef, int Exp ) override;
	int NumeroTerminos() override;
	int Exponente( int NroTermino ) override;
};

#endif
