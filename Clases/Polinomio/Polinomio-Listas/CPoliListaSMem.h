//---------------------------------------------------------------------------

#ifndef CPoliListaSMemH
#define CPoliListaSMemH
//---------------------------------------------------------------------------

#include "../Clases/Listas/CListaSMemoria.h"
#include "../Interfaces/ITDAPolinomio.h"

class CPoliListaSMem : public ITDAPolinomio{
private:
	int BuscarExponente( int Exp );
	int BuscarTerminoN( int I );
public:

	TCanvas* Canvas;
	CListaSMemoria* Pol;
	CPoliListaSMem( CListaSMemoria* pol, TCanvas* canvas ){
		Canvas = canvas;
		Pol = pol;
		Pol->Crear();
	}
    static const int Nulo = -1;

	void Crea() override;
	bool EsCero() override;
	int Grado() override;
	int Coeficiente( int Exp ) override;
	void AsignarCoeficiente( int Coef, int Exp ) override;
	void PonerTermino( int Coef, int Exp ) override;
	int NumeroTerminos() override;
	int Exponente( int NroTermino ) override;
	void Evalua( int X ) override;

	void MostrarPolinomio() override;
	void VaciarPolinomio() override;
};

#endif
