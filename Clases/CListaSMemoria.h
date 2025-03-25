//---------------------------------------------------------------------------

#ifndef CListaSMemoriaH
#define CListaSMemoriaH
//---------------------------------------------------------------------------

#include "../Interfaces/ITDALista.h"
#include "../Interfaces/ISMemoria.h"

typedef int TipoDatoListMem;
typedef int Direccion;

//struct Nodo {
//	TipoDato Elemento;
//    Nodo* Sig;
//};


class CListaSMemoria : public ITDALista<TipoDatoListMem> {
public:

	ISMemoria<TipoDatoListMem>* Memoria;
	Direccion PtrElementos;

	CListaSMemoria( ISMemoria<TipoDatoListMem>* memoria, TCanvas* canvas );

	void Crear() override;
	Direccion Fin() override;
	Direccion Primero() override;
	Direccion Siguiente( Direccion direccion ) override;
	Direccion Anterior( Direccion direccion ) override;
	bool Vacia() override;
	TipoDatoListMem Recupera( Direccion direccion ) override;
	int GetLongitud () override;
	void Inserta( Direccion direccion, TipoDatoListMem elemento ) override;
	void Inserta_primero( TipoDatoListMem elemento ) override;
	void Inserta_ultimo( TipoDatoListMem elemento ) override;
	void Suprime( Direccion direccion ) override;
	void Modifica( Direccion direccion, TipoDatoListMem elemento) override;

	void MostrarLista( ) override;
};

#endif
