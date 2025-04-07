//---------------------------------------------------------------------------

#ifndef CListaVectorH
#define CListaVectorH
//---------------------------------------------------------------------------

#include "../Interfaces/ITDALista.h"
#include "../Interfaces/IListaMethod.h"

typedef int TDListVec;

class CListaVector : public ITDALista<TDListVec>, public IListaMethod<TDListVec, int> {
public:

	// Propiedades
	static const int MAX = 100;
	static const int NULO = 0;

	TDListVec Elementos[MAX];

	CListaVector( TCanvas* canvas );
	CListaVector( ){}

	void Crear() override;
    void Inserta_primero( TDListVec elemento ) override;
	void Inserta_ultimo( TDListVec elemento ) override;
	void MostrarLista( ) override;

	int Fin() override;
	int Primero() override;
	int Siguiente( int direccion ) override;
	int Anterior( int direccion ) override;
	TDListVec Recupera( int direccion ) override;
	void Inserta( int direccion, TDListVec elemento ) override;
	void Suprime( int direccion ) override;
	void Modifica( int direccion, TDListVec elemento) override;
};

#endif
