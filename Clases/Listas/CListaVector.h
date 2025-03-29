//---------------------------------------------------------------------------

#ifndef CListaVectorH
#define CListaVectorH
//---------------------------------------------------------------------------

#include "../Interfaces/ITDALista.h"

typedef int TipoDatoListVec;
typedef int DireccionListVec;

class CListaVector : public ITDALista<TipoDatoListVec, DireccionListVec> {
public:

	// Propiedades
	static const int MAX = 100;
	static const int NULO = 0;

	TipoDatoListVec Elementos[MAX];

    CListaVector( TCanvas* canvas );

	void Crear() override;
	DireccionListVec Fin() override;
	DireccionListVec Primero() override;
	DireccionListVec Siguiente( DireccionListVec direccion ) override;
	DireccionListVec Anterior( DireccionListVec direccion ) override;
	bool Vacia() override;
	TipoDatoListVec Recupera( DireccionListVec direccion ) override;
	int GetLongitud () override;
	void Inserta( DireccionListVec direccion, TipoDatoListVec elemento ) override;
	void Inserta_primero( TipoDatoListVec elemento ) override;
	void Inserta_ultimo( TipoDatoListVec elemento ) override;
	void Suprime( DireccionListVec direccion ) override;
	void Modifica( DireccionListVec direccion, TipoDatoListVec elemento) override;

	void MostrarLista( ) override;

	// COORDS vector
	int X1 = 50;
	int Y1 = 650;

    int WidthField  = 100;
	int HeightField = 50;

};

#endif
