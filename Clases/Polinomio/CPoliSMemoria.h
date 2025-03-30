//---------------------------------------------------------------------------

#ifndef CPoliSMemoriaH
#define CPoliSMemoriaH
//---------------------------------------------------------------------------
#include "../Interfaces/ITDAPolinomio.h"
#include "../Clases/CSMemoria.h"

typedef int DirPolSMem;

class CPoliSMemoria : public ITDAPolinomio{
private:
	DirPolSMem BuscarExponente( int Exp );
	DirPolSMem BuscarTerminoN( int I );
public:

	DirPolSMem PtrPoli;
    CSMemoria* Memoria;
	int NroTerminos;

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
