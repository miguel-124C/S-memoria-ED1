//---------------------------------------------------------------------------

#ifndef FVectorH
#define FVectorH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
// Importando Clases Abstractas
#include "./Interfaces/ITDALista.h"
#include "./Interfaces/ITDAPolinomio.h"


class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *BtnCrearLista;
	TButton *BtnInsertInicio;
	TButton *BtnInsertFin;
	TEdit *EListaInsertInicio;
	TEdit *EListaInsertFin;
	TButton *BtnCreatePolinomio;
	TButton *BtnPonerTermino;
	TButton *BtnMostrarPolinomio;
	TButton *BtnDerivarPolinomio;
	TEdit *ECoef;
	TEdit *EExp;
	TButton *BtnMostrarListaMen;
	TButton *BtnEvaluaPolinomio;
	TEdit *EIncognita;
	void __fastcall BtnCrearListaClick(TObject *Sender);
	void __fastcall BtnMostrarListaMenClick(TObject *Sender);
	void __fastcall BtnInsertInicioClick(TObject *Sender);
	void __fastcall BtnInsertFinClick(TObject *Sender);
	void __fastcall BtnCreatePolinomioClick(TObject *Sender);
	void __fastcall BtnMostrarPolinomioClick(TObject *Sender);
	void __fastcall BtnPonerTerminoClick(TObject *Sender);
	void __fastcall BtnEvaluaPolinomioClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);

    // TDA Lista
	// <int, int> = <TipoDato, Direccion>
	ITDALista<int, int>* TDALISTA;
	bool ListaCreada = false;

	// TDA Polinomio
	ITDAPolinomio* TDAPOLINOMIO;
	bool PolinomioCreado = false;

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
