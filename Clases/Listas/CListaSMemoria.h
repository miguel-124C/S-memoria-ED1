//---------------------------------------------------------------------------

#ifndef CListaSMemoriaH
#define CListaSMemoriaH
//---------------------------------------------------------------------------

#include "../Interfaces/ITDALista.h"
#include "../Interfaces/ISMemoria.h"

typedef int TipoDatoListMem;
typedef int DireccionListMem;

//struct Nodo {
//	TipoDato Elemento;
//    Nodo* Sig;
//};


class CListaSMemoria : public ITDALista<TipoDatoListMem, DireccionListMem> {
public:

	ISMemoria<TipoDatoListMem>* Memoria;
	DireccionListMem PtrElementos;

	CListaSMemoria( ISMemoria<TipoDatoListMem>* memoria, TCanvas* canvas );

	void Crear() override;
	DireccionListMem Fin() override;
	DireccionListMem Primero() override;
	DireccionListMem Siguiente( DireccionListMem direccion ) override;
	DireccionListMem Anterior( DireccionListMem direccion ) override;
	bool Vacia() override;
	TipoDatoListMem Recupera( DireccionListMem direccion ) override;
	int GetLongitud () override;
	void Inserta( DireccionListMem direccion, TipoDatoListMem elemento ) override;
	void Inserta_primero( TipoDatoListMem elemento ) override;
	void Inserta_ultimo( TipoDatoListMem elemento ) override;
	void Suprime( DireccionListMem direccion ) override;
	void Modifica( DireccionListMem direccion, TipoDatoListMem elemento) override;

	void MostrarLista( ) override;
};

#endif
