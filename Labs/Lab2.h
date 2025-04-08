//---------------------------------------------------------------------------

#ifndef Lab2H
#define Lab2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
#include "./Interfaces/ISMemoria.h"
// Lista
#include "./Clases/Listas/CListaSMemoria.h"
#include "./Interfaces/ITDAPolinomio.h"


class TForm3 : public TForm
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
	void __fastcall BtnCreateMemoriaClick(TObject *Sender);
	void __fastcall BtnPedirEspacioClick(TObject *Sender);
	void __fastcall BtnLiberarEspacioClick(TObject *Sender);
	void __fastcall BtnMostrarMemoriaClick(TObject *Sender);
	void __fastcall BtnCreatePolinomioClick(TObject *Sender);
	void __fastcall BtnPonerTerminoClick(TObject *Sender);
	void __fastcall BtnMostrarPolinomioClick(TObject *Sender);
	void __fastcall BtnDerivarPolinomioClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);

	// Simulador de memoria
	ISMemoria<int>* SMEMORIA;
	bool MemoriaCreada = false;

	CListaSMemoria* TDALISTA;
	bool ListaCreada = false;

	ITDAPolinomio* TDAPOLINOMIO;
	bool PolinomioCreado = false;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
