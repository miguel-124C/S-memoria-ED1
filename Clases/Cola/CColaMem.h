//---------------------------------------------------------------------------

#ifndef CColaMemH
#define CColaMemH
//---------------------------------------------------------------------------
#include "./Interfaces/ITDACola.h"
#include "./Interfaces/ISMemoria.h"

class CColaMem : public ITDACola<int> {
private:
public:
	TCanvas* Canvas;

	int Ini;
	int Fin;

    ISMemoria<int>* Mem;

	CColaMem( ISMemoria<int>* Mem, TCanvas* canvas ){
        this->Mem = Mem;
		Canvas = canvas;
	}

	void Crear() override;
	bool Vacia() override;
	void Poner( int elemento ) override;
	void Sacar( int elemento ) override;
	int Primero() override;

	void MostrarCola() override;

};

#endif
