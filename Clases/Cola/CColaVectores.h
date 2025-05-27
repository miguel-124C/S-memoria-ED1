//---------------------------------------------------------------------------

#ifndef CColaVectoresH
#define CColaVectoresH
//---------------------------------------------------------------------------

#include "./Interfaces/ITDACola.h"

class CColaVectores : public ITDACola<int> {
private:
	static int const MAX = 100;
public:
	TCanvas* Canvas;

	int Vector[MAX];
	int Ini;
	int Fin;

	CColaVectores( TCanvas* canvas ){
		Canvas = canvas;
	}

	void Desplazar( int indice );
    int Siguiente( int direccion );

	void Crear() override;
	bool Vacia() override;
	void Poner( int elemento ) override;
	void Sacar( int elemento ) override;
	int Primero() override;

	void MostrarCola() override;

};

#endif
