//---------------------------------------------------------------------------

#ifndef CConjSMemoriaH
#define CConjSMemoriaH
//---------------------------------------------------------------------------
#include "./Interfaces/ITDAConjuntos.h"
#include "./Interfaces/ISMemoria.h"

typedef int TDConjMem;

class CConjSMemoria : public ITDAConjunto<TDConjMem>{
private:
public:
	TCanvas* Canvas;
	ISMemoria<TDConjMem>* M;
	CConjSMemoria( ISMemoria<TDConjMem>* Memoria, TCanvas* canvas ){
		Canvas = canvas;
        M = Memoria;
	}

	int PtrConj;

	void Crear() override ;
	bool Pertenece( TDConjMem elemento ) override;
	void Inserta( TDConjMem elemento ) override;
	int Cardinal() override;
	int Ordinal( TDConjMem elemento ) override;
	void Suprime( TDConjMem elemento ) override;
	TDConjMem Muestrea() override;

	void MostrarConjunto() override;


};
#endif
