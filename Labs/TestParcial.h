//---------------------------------------------------------------------------

#ifndef TestParcialH
#define TestParcialH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------

#include "./Interfaces/ISMemoria.h"
// Lista
//#include "./Clases/Listas/CListaSMemoria.h"
#include "./Interfaces/ITDAPolinomio.h"

class TForm6 : public TForm
{
__published:	// IDE-managed Components
	TButton *BtnCreateMemoria;
	TButton *BtnPedirEspacio;
	TButton *BtnLiberarEspacio;
	TButton *BtnCreatePoli;
	TButton *BtnPonerTermino;
	TButton *BtnDerivada;
	TButton *BtnGraficar;
	TButton *BtnMostrarMemoria;
	TButton *BtnMostrarPoli;
	TEdit *ENombreEspacio;
	TEdit *ENombreLiberarEspacio;
	TEdit *ECreateNombrePoli;
	TEdit *ENombrePoliPonerTerm;
	TEdit *ECoef;
	TEdit *EExp;
	TEdit *ENombrePoliDerivada;
	TEdit *Edit8;
	TEdit *Edit9;
	TEdit *Edit10;
	TEdit *ENombrePoliMostrar;
	TEdit *Edit1;
	void __fastcall BtnCreateMemoriaClick(TObject *Sender);
	void __fastcall BtnPedirEspacioClick(TObject *Sender);
	void __fastcall BtnLiberarEspacioClick(TObject *Sender);
	void __fastcall BtnMostrarMemoriaClick(TObject *Sender);
	void __fastcall BtnCreatePoliClick(TObject *Sender);
	void __fastcall BtnMostrarPoliClick(TObject *Sender);
	void __fastcall BtnPonerTerminoClick(TObject *Sender);
	void __fastcall BtnDerivadaClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm6(TComponent* Owner);

    // Simulador de memoria
	ISMemoria<int>* SMEMORIA;
	bool MemoriaCreada = false;

    ISMemoria<int>* CopySMemoria;

//	CListaSMemoria* TDALISTA;
//	bool ListaCreada = false;

	ITDAPolinomio* TDAPOLINOMIO;
	bool PolinomioCreado = false;

    ITDAPolinomio* CopiarPolinomio( ITDAPolinomio* original );
};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif
