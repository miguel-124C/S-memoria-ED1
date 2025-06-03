//---------------------------------------------------------------------------

#ifndef CDiColaV3H
#define CDiColaV3H
//---------------------------------------------------------------------------
#include "./Interfaces/ITDADiCola.h"
#include "./Clases/Cola/CColaVectorV3.h"

class CDiColaV3 : public ITDADiCola<int> {
private:
	CColaVectorV3* colaVectorV3;
public:

	CDiColaV3( TCanvas* canvas ){
		colaVectorV3 = new  CColaVectorV3( canvas );
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
