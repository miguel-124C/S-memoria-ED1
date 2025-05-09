//---------------------------------------------------------------------------

#ifndef FSMemoriaH
#define FSMemoriaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

// Importando Clases Abstractas
#include "./Interfaces/ISMemoria.h"

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *BtnCreateMemoria;
	TButton *BtnPedirEspacio;
	TButton *BtnLiberarEspacio;
	TButton *BtnMostrarMemoria;
	TButton *BtnPonerDato;
	TEdit *ENombreEspacio;
	TEdit *ENombreLiberarEspacio;
	TEdit *EInicioMemoria;
	TEdit *EFinMemoria;
	TEdit *EDireccionPonerDato;
	TEdit *EIdPonerDato;
	TEdit *EValorPonerDato;
	void __fastcall BtnCreateMemoriaClick(TObject *Sender);
	void __fastcall BtnPedirEspacioClick(TObject *Sender);
	void __fastcall BtnLiberarEspacioClick(TObject *Sender);
	void __fastcall BtnPonerDatoClick(TObject *Sender);
	void __fastcall BtnMostrarMemoriaClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);

	// Simulador de memoria
	ISMemoria<int>* SMEMORIA;
	bool MemoriaCreada = false;
	bool CreateMemoria();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
