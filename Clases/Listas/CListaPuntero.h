//---------------------------------------------------------------------------

#ifndef CListaPunteroH
#define CListaPunteroH
//---------------------------------------------------------------------------

#include "../Interfaces/ITDALista.h"
#include "../Interfaces/IListaMethod.h"

typedef int TDElem;

struct NodoPuntero {
	TDElem Elemento;
    NodoPuntero* Sig;
};

class CListaPuntero: public ITDALista<TDElem>, public IListaMethod<TDElem, NodoPuntero*> {
public:

	NodoPuntero* PtrElementos;

    CListaPuntero( TCanvas* canvas );

	void Crear() override;
    void Inserta_primero( TDElem elemento ) override;
	void Inserta_ultimo( TDElem elemento ) override;
	void MostrarLista( ) override;

	NodoPuntero* Fin() override;
	NodoPuntero* Primero() override;
	NodoPuntero* Siguiente( NodoPuntero* direccion ) override;
	NodoPuntero* Anterior( NodoPuntero* direccion ) override;
	TDElem Recupera( NodoPuntero* direccion ) override;
	void Inserta( NodoPuntero* direccion, TDElem elemento ) override;
	void Suprime( NodoPuntero* direccion ) override;
	void Modifica( NodoPuntero* direccion, TDElem elemento) override;
};
#endif
