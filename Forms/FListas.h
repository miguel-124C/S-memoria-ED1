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
#include "./Interfaces/ISMemoria.h"

class TForm4 : public TForm
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
	TButton *BtnCreateLista;
	TButton *BtnInsertInicio;
	TButton *BtnInsertFinal;
	TButton *BtnMostrarLista;
	TLabel *LTitleLista;
	TButton *BtnChangeType;
	TEdit *EInsertInicio;
	TEdit *EInsertFin;
	void __fastcall BtnCreateMemoriaClick(TObject *Sender);
	void __fastcall BtnPedirEspacioClick(TObject *Sender);
	void __fastcall BtnLiberarEspacioClick(TObject *Sender);
	void __fastcall BtnMostrarMemoriaClick(TObject *Sender);
	void __fastcall BtnCreateListaClick(TObject *Sender);
	void __fastcall BtnChangeTypeClick(TObject *Sender);
	void __fastcall BtnMostrarListaClick(TObject *Sender);
	void __fastcall BtnInsertInicioClick(TObject *Sender);
	void __fastcall BtnInsertFinalClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm4(TComponent* Owner);

	// Simulador de memoria
	ISMemoria<int>* SMEMORIA;
	bool MemoriaCreada = false;
	bool CreateMemoria();

	// TDA Lista
	// <int> = <TipoDato>
	ITDALista<int>* TDALISTA;
	bool ListaCreada = false;


	void UpdateLibreDisponible();
	void SelectedTypeLista();
	void CreateLista( AnsiString TypeLista );
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
