//---------------------------------------------------------------------------

#ifndef CListaPunteroH
#define CListaPunteroH
//---------------------------------------------------------------------------

#include "../Interfaces/ITDALista.h"

typedef int TipoElemento;

struct NodoPuntero {
	TipoElemento Elemento;
    NodoPuntero* Sig;
};

class CListaPuntero: public ITDALista<TipoElemento> {
public:

	NodoPuntero* PtrElementos;

    CListaPuntero( TCanvas* canvas );

	void Crear() override;
	NodoPuntero* Fin() override;
	NodoPuntero* Primero() override;
	NodoPuntero* Siguiente( NodoPuntero* direccion ) override;
	NodoPuntero* Anterior( NodoPuntero* direccion ) override;
	bool Vacia() override;
	TipoElemento Recupera( NodoPuntero* direccion ) override;
	int GetLongitud () override;
	void Inserta( NodoPuntero* direccion, TipoElemento elemento ) override;
	void Inserta_primero( TipoElemento elemento ) override;
	void Inserta_ultimo( TipoElemento elemento ) override;
	void Suprime( NodoPuntero* direccion ) override;
	void Modifica( NodoPuntero* direccion, TipoElemento elemento) override;

	void MostrarLista( ) override;
};
#endif
