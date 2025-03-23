//---------------------------------------------------------------------------

#ifndef FormH
#define FormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

// Importando Clases Abstractas
#include "./Interfaces/ISMemoria.h"
#include "./Interfaces/ITDALista.h"


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
	TLabel *LabelTipoLista;
	TLabel *LLibre;
	TLabel *LDisponible;
	TButton *BtnInsertInicio;
	TButton *BtnInsertFin;
	TButton *BtnMostrarLista;
	TEdit *EListaInsertInicio;
	TEdit *EListaInsertFin;
	void __fastcall BtnCreateMemoriaClick(TObject *Sender);
	void __fastcall BtnPedirEspacioClick(TObject *Sender);
	void __fastcall BtnLiberarEspacioClick(TObject *Sender);
	void __fastcall BtnPonerDatoClick(TObject *Sender);
	void __fastcall BtnMostrarMemoriaClick(TObject *Sender);
	void __fastcall BtnCrearListaClick(TObject *Sender);
	void __fastcall BtnInsertInicioClick(TObject *Sender);
	void __fastcall BtnInsertFinClick(TObject *Sender);
	void __fastcall BtnMostrarListaClick(TObject *Sender);
private:	// User declarations

	// Simulador de memoria
	ISMemoria<int>* SMEMORIA;
	bool MemoriaCreada = false;
	bool CreateMemoria();

    // TDA Lista
	ITDALista<int>* TDALISTA;
    int TipoLista = 1; // 1 = ListaVectores | 2 = ListaMemoria | 3 = ListaPunteros
	bool ListaCreada = false;

	void UpdateLibreDisponible();
    //--------------------------------------------------------------------------
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
