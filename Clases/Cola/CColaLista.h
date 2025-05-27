//---------------------------------------------------------------------------

#ifndef CColaListaH
#define CColaListaH
//---------------------------------------------------------------------------
#include "./Cola/CColaLista.h"
#include "./Clases/Listas/CListaSMemoria.h"
#include "./Interfaces/ITDACola.h"

typedef int TElementoCola;

class CColaLista : public ITDACola<TElementoCola> {
private:
public:
	TCanvas* Canvas;
    CListaSMemoria* Lista;

	CColaLista( CListaSMemoria* ListaMem, TCanvas* canvas ){
		setCanvas( canvas );
		this->Lista = ListaMem;
	}

	void Crear() override;
	bool Vacia() override;
	void Poner( TElementoCola elemento ) override;
	void Sacar( TElementoCola elemento ) override;
	TElementoCola Primero() override;

	void MostrarCola() override;


};
#endif
