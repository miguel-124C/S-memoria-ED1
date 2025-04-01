//---------------------------------------------------------------------------

#ifndef CPoliListaVectorH
#define CPoliListaVectorH
//---------------------------------------------------------------------------

#include "../Clases/Listas/CListaVector.h"
#include "../Interfaces/ITDAPolinomio.h"
#include "../Interfaces/ITDALista.h"

class CPoliListaVector : public ITDAPolinomio{
private:
	int BuscarExponente( int Exp );
	int BuscarTerminoN( int I );
public:

	TCanvas* Canvas;
	ITDALista<int, int>* Pol;
	CPoliListaVector( ITDALista<int, int>* pol, TCanvas* canvas ){
		Canvas = canvas;
		Pol = pol;
	}
    static const int Nulo = 0;

	void Crea() override ;
	bool EsCero() override;
	int Grado() override;
	int Coeficiente( int Exp ) override;
	void AsignarCoeficiente( int Coef, int Exp ) override;
	void PonerTermino( int Coef, int Exp ) override;
	int NumeroTerminos() override;
	int Exponente( int NroTermino ) override;
	void Evalua( int X ) override;

	void MostrarPolinomio() override;
};

#endif
