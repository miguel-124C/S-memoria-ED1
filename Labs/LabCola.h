//---------------------------------------------------------------------------

#ifndef LabColaH
#define LabColaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

#include "./Interfaces/ISMemoria.h"
#include "./Interfaces/ITDACola.h"
#include "./Clases/Listas/CListaSMemoria.h"

//---------------------------------------------------------------------------
class TForm9 : public TForm
{
__published:	// IDE-managed Components
	TLabel *LTitleLista;
	TButton *BtnCreateMemoria;
	TButton *BtnPedirEspacio;
	TButton *BtnLiberarEspacio;
	TEdit *ENombreEspacio;
	TEdit *ENombreLiberarEspacio;
	TButton *BtnMostrarMemoria;
	TEdit *EInicioMemoria;
	TEdit *EFinMemoria;
	TButton *BtnPoner;
	TButton *BtnSacar;
	TButton *BtnCrearColaVectorV2;
	TEdit *EPoner;
	TButton *BtnMostrarCola;
	TButton *BtnCrearVectorMem;
	TButton *BtnCrearColaVectorV3;
	TButton *BtnCrearColaLista;
	TButton *BtnCrearColaPunteros;
	void __fastcall BtnCreateMemoriaClick(TObject *Sender);
	void __fastcall BtnPedirEspacioClick(TObject *Sender);
	void __fastcall BtnLiberarEspacioClick(TObject *Sender);
	void __fastcall BtnMostrarMemoriaClick(TObject *Sender);
	void __fastcall BtnPonerClick(TObject *Sender);
	void __fastcall BtnSacarClick(TObject *Sender);
	void __fastcall BtnMostrarColaClick(TObject *Sender);
	void __fastcall BtnCrearColaVectorV2Click(TObject *Sender);
	void __fastcall BtnCrearVectorMemClick(TObject *Sender);
	void __fastcall BtnCrearColaVectorV3Click(TObject *Sender);
	void __fastcall BtnCrearColaListaClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm9(TComponent* Owner);

	// Simulador de memoria
	ISMemoria<int>* SMEMORIA;
	bool MemoriaCreada = false;

	// Listaa
    CListaSMemoria* ListaMem;

	ITDACola<int>* Cola;
    bool ColaCreada = false;

};
//---------------------------------------------------------------------------
extern PACKAGE TForm9 *Form9;
//---------------------------------------------------------------------------
#endif
