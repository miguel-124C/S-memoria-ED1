//---------------------------------------------------------------------------

#ifndef CListaSMemoriaH
#define CListaSMemoriaH
//---------------------------------------------------------------------------

#include "../Interfaces/ITDALista.h"
#include "../Interfaces/ISMemoria.h"

typedef int TipoDato;

struct Nodo {
	TipoDato Elemento;
    Nodo* Sig;
};


class CListaSMemoria : public ITDALista<TipoDato> {
public:

	ISMemoria<TipoDato>* Memoria;
	Direccion PtrElementos;

    CListaSMemoria( ISMemoria<TipoDato>* memoria );

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
