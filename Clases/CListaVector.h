//---------------------------------------------------------------------------

#ifndef CListaVectorH
#define CListaVectorH
//---------------------------------------------------------------------------

#include "../Interfaces/ITDALista.h"

typedef int TipoDato;

class CListaVector : public ITDALista<TipoDato> {
public:

	// Propiedades
	static const int MAX = 100;
	static const int NULO = 0;

	TipoDato Elementos[MAX];

	void Crear() override;
	Direccion Fin() override;
	Direccion Primero() override;
	Direccion Siguiente( Direccion direccion ) override;
	Direccion Anterior( Direccion direccion ) override;
	bool Vacia() override;
	TipoDato Recupera( Direccion direccion ) override;
	int GetLongitud () override;
	void Inserta( Direccion direccion, TipoDato elemento ) override;
	void Inserta_primero( TipoDato elemento ) override;
	void Inserta_ultimo( TipoDato elemento ) override;
	void Suprime( Direccion direccion ) override;
	void Modifica( Direccion direccion, TipoDato elemento) override;
};

#endif
