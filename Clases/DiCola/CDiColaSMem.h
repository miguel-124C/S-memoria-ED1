//---------------------------------------------------------------------------

#ifndef CDiColaSMemH
#define CDiColaSMemH
//---------------------------------------------------------------------------
#include "./Interfaces/ITDADiCola.h"
#include "./Clases/Cola/CColaMem.h"

class CDiColaSMem : public ITDADiCola<int> {
private:
	CColaMem* colaMem;
public:

	CDiColaSMem( ISMemoria<int>* Mem, TCanvas* canvas ){
		colaMem = new CColaMem( Mem, canvas );
	}

	void Crear() override;
	bool Vacia() override;
	void Poner( int elemento ) override;
	void Sacar( int elemento ) override;
	int Primero() override;

	int Ultimo() override;
	void Poner_frente( int e ) override;
	void Sacar_final( int e ) override;

	void MostrarCola() override;

};

#endif
