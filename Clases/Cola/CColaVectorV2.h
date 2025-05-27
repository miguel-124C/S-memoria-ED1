//---------------------------------------------------------------------------

#ifndef CColaVectorV2H
#define CColaVectorV2H
//---------------------------------------------------------------------------
#include "./Interfaces/ITDACola.h"

class CColaVectorV2 : public ITDACola<int> {
private:
	static int const MAX = 100;
public:

	int Vector[MAX];
	int Ini;
	int Fin;

	CColaVectorV2( TCanvas* canvas ){
		setCanvas( canvas );
	}

    void Desplazar( int indice );

	void Crear() override;
	bool Vacia() override;
	void Poner( int elemento ) override;
	void Sacar( int elemento ) override;
	int Primero() override;

	void MostrarCola() override;

};

#endif
