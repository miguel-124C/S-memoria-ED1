//---------------------------------------------------------------------------

#ifndef FPunterosH
#define FPunterosH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
// Importando Clases Abstractas
#include "./Interfaces/ITDALista.h"
#include "./Interfaces/ITDAPolinomio.h"

// Clases
#include "./Clases/Listas/CListaPuntero.h"
#include "./Clases/Polinomio/CPoliPunteros.h"

class TForm3 : public TForm
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
	__fastcall TForm3(TComponent* Owner);

    // TDA Lista
	// <int, int> = <TipoDato, Direccion>
	ITDALista<int, NodoPuntero*>* TDALISTA;
	bool ListaCreada = false;

	// TDA Polinomio
	ITDAPolinomio* TDAPOLINOMIO;
	bool PolinomioCreado = false;

};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
