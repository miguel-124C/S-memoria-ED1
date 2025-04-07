//---------------------------------------------------------------------------

#ifndef CListaSMemoriaH
#define CListaSMemoriaH
//---------------------------------------------------------------------------

#include "../Interfaces/ITDALista.h"
#include "../Interfaces/IListaMethod.h"

#include "../Interfaces/ISMemoria.h"

typedef int TDListMem;

//struct Nodo {
//	TipoDato Elemento;
//    Nodo* Sig;
//};


class CListaSMemoria : public ITDALista<TDListMem>, public IListaMethod<TDListMem, int> {
public:

	ISMemoria<TDListMem>* Memoria;
	int PtrElementos;

	CListaSMemoria( ISMemoria<TDListMem>* memoria, TCanvas* canvas );

	// ITDALista
	void Crear() override;
    void Inserta_primero( TDListMem elemento ) override;
	void Inserta_ultimo( TDListMem elemento ) override;
    void MostrarLista( ) override;

    // IListaMethod
	int Fin() override;
	int Primero() override;
	int Siguiente( int direccion ) override;
	int Anterior( int direccion ) override;
	TDListMem Recupera( int direccion ) override;
	void Inserta( int direccion, TDListMem elemento ) override;
	void Suprime( int direccion ) override;
	void Modifica( int direccion, TDListMem elemento) override;
};

#endif
