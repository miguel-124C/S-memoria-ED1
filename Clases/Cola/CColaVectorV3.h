//---------------------------------------------------------------------------

#ifndef CColaVectorV3H
#define CColaVectorV3H
//---------------------------------------------------------------------------
#include "./Interfaces/ITDACola.h"

class CColaVectorV3 : public ITDACola<int> {
private:
	static int const MAX = 100;
public:

	int Vector[MAX];
	int Ini;
	int Fin;

	CColaVectorV3( TCanvas* canvas ){
		setCanvas( canvas );
	}

    int Siguiente( int direccion );

	void Crear() override;
	bool Vacia() override;
	void Poner( int elemento ) override;
	void Sacar( int elemento ) override;
	int Primero() override;

	void MostrarCola() override;

	int getMax(){
        return MAX;
	}

};

#endif
