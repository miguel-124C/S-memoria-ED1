//---------------------------------------------------------------------------

#ifndef CDiColaV2H
#define CDiColaV2H
//---------------------------------------------------------------------------

#include "./Interfaces/ITDADiCola.h"
#include "./Clases/Cola/CColaVectorV2.h"

class CDiColaV2 : public ITDADiCola<int> {
private:
	CColaVectorV2* colaVectorV2;
public:

	CDiColaV2( TCanvas* canvas ){
		colaVectorV2 = new  CColaVectorV2( canvas );
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