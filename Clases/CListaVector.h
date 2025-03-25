//---------------------------------------------------------------------------

#ifndef CListaVectorH
#define CListaVectorH
//---------------------------------------------------------------------------

#include "../Interfaces/ITDALista.h"

typedef int TipoDatoListVec;

class CListaVector : public ITDALista<TipoDatoListVec> {
public:

	// Propiedades
	static const int MAX = 100;
	static const int NULO = 0;

	TipoDatoListVec Elementos[MAX];

    CListaVector( TCanvas* canvas );

	void Crear() override;
	Direccion Fin() override;
	Direccion Primero() override;
	Direccion Siguiente( Direccion direccion ) override;
	Direccion Anterior( Direccion direccion ) override;
	bool Vacia() override;
	TipoDatoListVec Recupera( Direccion direccion ) override;
	int GetLongitud () override;
	void Inserta( Direccion direccion, TipoDatoListVec elemento ) override;
	void Inserta_primero( TipoDatoListVec elemento ) override;
	void Inserta_ultimo( TipoDatoListVec elemento ) override;
	void Suprime( Direccion direccion ) override;
	void Modifica( Direccion direccion, TipoDatoListVec elemento) override;

	void MostrarLista( ) override;

	// COORDS vector
	int X1 = 50;
	int Y1 = 650;

    int WidthField  = 100;
	int HeightField = 50;

};

#endif
