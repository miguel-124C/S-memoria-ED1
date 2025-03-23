//---------------------------------------------------------------------------
#ifndef CSMemoriaH
#define CSMemoriaH

#include "../Interfaces/ISMemoria.h"

typedef int TipoDato;

class CSMemoria : public ISMemoria<TipoDato> {
public:
	// Constructor
	CSMemoria( TipoDato valueDefault );

	// Métodos heredados
	int NewEspacio(AnsiString cadena) override;
	void DeleteEspacio(int dir) override;
	void PonerDato(int dir, AnsiString cadena_id, TipoDato valor) override;
	TipoDato ObtieneDato(int dir, AnsiString cadena_id) override;
	int EspacioDisponible() override;
	int EspacioOcupado() override;
	bool DirLibre(int dir) override;
};

#endif
