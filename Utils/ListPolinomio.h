//---------------------------------------------------------------------------

#ifndef ListPolinomioH
#define ListPolinomioH
//---------------------------------------------------------------------------
#include "./Interfaces/ITDAPolinomio.h"
#include "./Utils/PlanoCartesiano.h"

struct Polinomio {
	AnsiString Nombre;
	ITDAPolinomio* P;
    bool IsLista;
};

class ListPolinomio {
private:
public:
	PlanoCartesiano* plano;

	const static int Maximo = 100;
	int PosLibrListPoli = 0;
	Polinomio ListPoli[Maximo];

	void setCanvas( TCanvas* canvas ){
        plano = new PlanoCartesiano( canvas );
	}

	bool ExistPoli( AnsiString Nombre );
	void AddPolinomio( AnsiString Nombre, ITDAPolinomio* P, bool IsLista );
	ITDAPolinomio* GetPolinomio( AnsiString Nombre );
	bool IsLista( AnsiString Nombre );

    void GraficarPolinomios( float x1, float x2, float s );

	ITDAPolinomio* GetFirtsPolinomio(){
		if( PosLibrListPoli == 0 ) return nullptr;

		return ListPoli[0].P;
	}
};
#endif
