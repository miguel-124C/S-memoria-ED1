//---------------------------------------------------------------------------

#ifndef CPoliPunterosH
#define CPoliPunterosH
//---------------------------------------------------------------------------
#include "../Interfaces/ITDAPolinomio.h"

struct NodoPoli{
	int Coef;
	int Exp;
	NodoPoli* Sig;
};

class CPoliPuntero : public ITDAPolinomio{
private:
	NodoPoli* BuscarExponente( int Exp );
	NodoPoli* BuscarTerminoN( int I );
	NodoPoli* BuscarDirTerminoAnterior( NodoPoli* DirActual );
public:

	TCanvas* Canvas;
	CPoliPuntero( TCanvas* canvas ){
        Canvas = canvas;
	}

	NodoPoli* PtrPoli;
	int NroTerminos;

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
