//---------------------------------------------------------------------------

#ifndef CColaVectoresH
#define CColaVectoresH
//---------------------------------------------------------------------------

#include "./Interfaces/ITDACola.h"

class CColaVectores : public ITDACola<int> {
private:
	static int const MAX = 100;
public:

	int Vector[MAX];
	int Ini;
	int Fin;

	CColaVectores( TCanvas* canvas ){
		setCanvas( canvas );
	}

	void Crear() override;
	bool Vacia() override;
	void Poner( int elemento ) override;
	void Sacar( int elemento ) override;
	int Primero() override;

	void MostrarCola() override;

};

#endif
