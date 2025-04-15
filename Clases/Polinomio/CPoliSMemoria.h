//---------------------------------------------------------------------------

#ifndef CPoliSMemoriaH
#define CPoliSMemoriaH
//---------------------------------------------------------------------------
#include "../Interfaces/ITDAPolinomio.h"
#include "../Interfaces/ISMemoria.h"

typedef int DirPolSMem;

class CPoliSMemoria : public ITDAPolinomio{
private:
	DirPolSMem BuscarExponente( int Exp );
	DirPolSMem BuscarTerminoN( int I );
	DirPolSMem BuscarDirTerminoAnterior( int DirActual );
public:

	CPoliSMemoria( ISMemoria<DirPolSMem>* memoria, TCanvas* canvas );

	DirPolSMem PtrPoli; // Puntero, siempre apunta al primer elemento
    ISMemoria<DirPolSMem>* Memoria;
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
	void VaciarPolinomio() override;
};

#endif
