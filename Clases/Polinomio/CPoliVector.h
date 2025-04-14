//---------------------------------------------------------------------------

#ifndef CPoliVectorH
#define CPoliVectorH
//---------------------------------------------------------------------------
#include "../Interfaces/ITDAPolinomio.h"

class CPoliVector : public ITDAPolinomio{
private:
public:

    static const int MAX = 100;

	int VC[MAX]; // Coeficientes
	int VE[MAX]; // Exponentes

	int NroTerminos;

	TCanvas* Canvas;
	CPoliVector( TCanvas* canvas ){
        Canvas = canvas;
	};

	void Crea() override ;
	bool EsCero() override;
	int Grado() override;
	int Coeficiente( int Exp ) override;
	void AsignarCoeficiente( int Coef, int Exp ) override;
	void PonerTermino( int Coef, int Exp ) override;
	int NumeroTerminos() override;
	int Exponente( int NroTermino ) override;
	void Evalua( int X ) override;

	void MostrarPolinomio() override;
  void VaciarPolinomio() override;

	int GetLugarExp( int Exp ){
    	if( !(Exp >= 0 && Exp <= Grado()) ) return -1;

        int Lugar = -1;
		for( int i = 1; i <= NroTerminos; i++ ){
			if( VE[i] == Exp ){
                Lugar = i;
				break;
			}
		}

        return Lugar;
	}
};

#endif
