//---------------------------------------------------------------------------

#ifndef FConjuntosH
#define FConjuntosH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

// Importando Clases Abstractas
#include "./Interfaces/ISMemoria.h"
#include "./Interfaces/ITDAConjuntos.h"

//---------------------------------------------------------------------------
class TForm7 : public TForm
{
__published:	// IDE-managed Components
	TButton *BtnCreateMemoria;
	TButton *BtnPedirEspacio;
	TEdit *ENombreEspacio;
	TButton *BtnMostrarMemoria;
	TEdit *EInicioMemoria;
	TEdit *EFinMemoria;
	TButton *BtnCreaConjA;
	TButton *BtnCreaConjB;
	TButton *BtnCreaConjC;
	TButton *BtnInsertElem;
	TButton *BtnShowConj;
	TButton *BtnUnir;
	TButton *BrnIntersecta;
	TEdit *ENombreElem;
	TEdit *ENomMostrar;
	TLabel *LTitleConj;
	TButton *BtnChangeType;
	void __fastcall BtnCreateMemoriaClick(TObject *Sender);
	void __fastcall BtnPedirEspacioClick(TObject *Sender);
	void __fastcall BtnMostrarMemoriaClick(TObject *Sender);
	void __fastcall BtnCreaConjAClick(TObject *Sender);
	void __fastcall BtnCreaConjBClick(TObject *Sender);
	void __fastcall BtnCreaConjCClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm7(TComponent* Owner);

	// Simulador de memoria
	ISMemoria<int>* SMEMORIA;
	bool MemoriaCreada = false;

	// TDA Conjuntos
	ITDAConjunto<int>* ConjuntoA;
	ITDAConjunto<int>* ConjuntoB;
	ITDAConjunto<int>* ConjuntoC;

	ITDAConjunto<int>* TDACONJUNTO;
	bool ConjuntoCreado = false;
	void CreateConjunto( AnsiString TypeConj );
	void SelectedTypeConj();

    AnsiString Type;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm7 *Form7;
//---------------------------------------------------------------------------
#endif
