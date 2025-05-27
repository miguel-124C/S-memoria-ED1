//---------------------------------------------------------------------------

#ifndef FColaH
#define FColaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
#include "./Interfaces/ISMemoria.h"
#include "./Interfaces/ITDACola.h"

class TForm8 : public TForm
{
__published:	// IDE-managed Components
	TButton *BtnCreateMemoria;
	TButton *BtnPedirEspacio;
	TButton *BtnLiberarEspacio;
	TEdit *ENombreEspacio;
	TEdit *ENombreLiberarEspacio;
	TLabel *LTitleLista;
	TButton *BtnMostrarMemoria;
	TEdit *EInicioMemoria;
	TEdit *EFinMemoria;
	TButton *BtnPoner;
	TButton *BtnSacar;
	TButton *BtnCrearColaVector;
	TEdit *EPoner;
	TButton *BtnMostrarCola;
	TButton *BtnCrearVectorMem;
	void __fastcall BtnCreateMemoriaClick(TObject *Sender);
	void __fastcall BtnPedirEspacioClick(TObject *Sender);
	void __fastcall BtnLiberarEspacioClick(TObject *Sender);
	void __fastcall BtnMostrarMemoriaClick(TObject *Sender);
	void __fastcall BtnPonerClick(TObject *Sender);
	void __fastcall BtnSacarClick(TObject *Sender);
	void __fastcall BtnCrearColaVectorClick(TObject *Sender);
	void __fastcall BtnMostrarColaClick(TObject *Sender);
	void __fastcall BtnCrearVectorMemClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm8(TComponent* Owner);

	// Simulador de memoria
	ISMemoria<int>* SMEMORIA;
	bool MemoriaCreada = false;

	ITDACola<int>* Cola;
    bool ColaCreada = false;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm8 *Form8;
//---------------------------------------------------------------------------
#endif
