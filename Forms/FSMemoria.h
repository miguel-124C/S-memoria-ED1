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
#include "./Interfaces/ITDALista.h"
#include "./Interfaces/ITDAPolinomio.h"


//---------------------------------------------------------------------------
class TForm2 : public TForm
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
	TButton *BtnCrearLista;
	TLabel *LLibre;
	TLabel *LDisponible;
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
	void __fastcall BtnCreateMemoriaClick(TObject *Sender);
	void __fastcall BtnPedirEspacioClick(TObject *Sender);
	void __fastcall BtnLiberarEspacioClick(TObject *Sender);
	void __fastcall BtnPonerDatoClick(TObject *Sender);
	void __fastcall BtnMostrarMemoriaClick(TObject *Sender);
	void __fastcall BtnCrearListaClick(TObject *Sender);
	void __fastcall BtnInsertInicioClick(TObject *Sender);
	void __fastcall BtnInsertFinClick(TObject *Sender);
	void __fastcall BtnCreatePolinomioClick(TObject *Sender);
	void __fastcall BtnPonerTerminoClick(TObject *Sender);
	void __fastcall BtnMostrarPolinomioClick(TObject *Sender);
	void __fastcall BtnMostrarListaMenClick(TObject *Sender);
	void __fastcall BtnEvaluaPolinomioClick(TObject *Sender);
private:	// User declarations

	// Simulador de memoria
	ISMemoria<int>* SMEMORIA;
	bool MemoriaCreada = false;
	bool CreateMemoria();

	// TDA Lista
	// <int, int> = <TipoDato, Direccion>
	ITDALista<int, int>* TDALISTA;
	bool ListaCreada = false;

	// TDA Polinomio
	ITDAPolinomio* TDAPOLINOMIO;
	bool PolinomioCreado = false;

	void UpdateLibreDisponible();
    //--------------------------------------------------------------------------
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
