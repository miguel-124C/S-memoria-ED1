//---------------------------------------------------------------------------

#ifndef FPolinomiosH
#define FPolinomiosH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

// Importando Clases Abstractas
#include "./Interfaces/ISMemoria.h"
#include "./Interfaces/ITDAPolinomio.h"

//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TButton *BtnCreateMemoria;
	TButton *BtnPedirEspacio;
	TButton *BtnLiberarEspacio;
	TButton *BtnMostrarMemoria;
	TEdit *ENombreEspacio;
	TEdit *ENombreLiberarEspacio;
	TEdit *EInicioMemoria;
	TEdit *EFinMemoria;
	TButton *BtnCreatePolinomio;
	TButton *BtnPonerTermino;
	TButton *BtnMostrarPolinomio;
	TButton *BtnDerivarPolinomio;
	TEdit *ECoef;
	TEdit *EExp;
	TButton *BtnEvaluaPolinomio;
	TEdit *EIncognita;
	TLabel *LTitlePolinomio;
	TButton *BtnChangeType;
	TButton *BtnCreateLista;
	TButton *BtnInsertInicio;
	TEdit *EInsertInicio;
	TEdit *EInsertFin;
	TButton *BtnInsertFinal;
	TButton *BtnMostrarLista;
	void __fastcall BtnCreateMemoriaClick(TObject *Sender);
	void __fastcall BtnPedirEspacioClick(TObject *Sender);
	void __fastcall BtnLiberarEspacioClick(TObject *Sender);
	void __fastcall BtnMostrarMemoriaClick(TObject *Sender);
	void __fastcall BtnCreatePolinomioClick(TObject *Sender);
	void __fastcall BtnPonerTerminoClick(TObject *Sender);
	void __fastcall BtnMostrarPolinomioClick(TObject *Sender);
	void __fastcall BtnEvaluaPolinomioClick(TObject *Sender);
	void __fastcall BtnChangeTypeClick(TObject *Sender);
private:	// User declarations

	// Simulador de memoria
	ISMemoria<int>* SMEMORIA;
	bool MemoriaCreada = false;
	bool CreateMemoria();

	// TDA Polinomio
	ITDAPolinomio* TDAPOLINOMIO;
	bool PolinomioCreado = false;
	void CreatePolinomio( AnsiString TypePoli );
    void SelectedTypePolinomio();
    //--------------------------------------------------------------------------
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
