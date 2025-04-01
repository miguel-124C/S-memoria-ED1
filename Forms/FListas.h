//---------------------------------------------------------------------------

#ifndef FListasH
#define FListasH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------

// Importando Clases Abstractas
#include "./Interfaces/ITDALista.h"
#include "./Interfaces/ITDAPolinomio.h"

class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TButton *BtnCreatePolinomio;
	TButton *BtnPonerTermino;
	TButton *BtnMostrarPolinomio;
	TButton *BtnDerivarPolinomio;
	TEdit *ECoef;
	TEdit *EExp;
	TButton *BtnEvaluaPolinomio;
	TEdit *EIncognita;
private:	// User declarations
public:		// User declarations
	__fastcall TForm4(TComponent* Owner);

    int TipoLista = 1;

	// TDA Lista
	// <int, int> = <TipoDato, Direccion>
	ITDALista<int, int>* TDALISTA;
	bool ListaCreada = false;

	// TDA Polinomio
	ITDAPolinomio* TDAPOLINOMIO;
	bool PolinomioCreado = false;

};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
