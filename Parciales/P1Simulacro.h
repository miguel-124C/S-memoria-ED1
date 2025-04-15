//---------------------------------------------------------------------------

#ifndef P1SimulacroH
#define P1SimulacroH
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

struct Polinomio {
	AnsiString Nombre;
	ITDAPolinomio* P;
    bool IsLista;
};

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
	TEdit *EGrafNombrePoli;
	TEdit *ELimiteInf;
	TEdit *ELimiteSup;
	TEdit *ENombrePoliMostrar;
	TEdit *EVariable;
	TButton *BtnMultiplica;
	TEdit *EPoliA;
	TEdit *EPoliB;
	TEdit *EPoliResultMulti;
	void __fastcall BtnCreateMemoriaClick(TObject *Sender);
	void __fastcall BtnPedirEspacioClick(TObject *Sender);
	void __fastcall BtnLiberarEspacioClick(TObject *Sender);
	void __fastcall BtnMostrarMemoriaClick(TObject *Sender);
	void __fastcall BtnCreatePoliClick(TObject *Sender);
	void __fastcall BtnMostrarPoliClick(TObject *Sender);
	void __fastcall BtnPonerTerminoClick(TObject *Sender);
	void __fastcall BtnDerivadaClick(TObject *Sender);
	void __fastcall BtnGraficarClick(TObject *Sender);
	void __fastcall BtnMultiplicaClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm6(TComponent* Owner);

    // Simulador de memoria
	ISMemoria<int>* SMEMORIA;
	bool MemoriaCreada = false;
    ISMemoria<int>* CopySMemoria;

	CListaSMemoria* TDALISTA;
	bool ListaCreada = false;
	CListaSMemoria* CopyLista;

	const static int Maximo = 100;
	int PosLibrListPoli = 1;
	Polinomio ListPoli[Maximo];

	ITDAPolinomio* TDAPOLINOMIO;
	bool PolinomioCreado = false;

	ITDAPolinomio* CreatePolinomio( bool ListaOrMem );

	ITDAPolinomio* CopiarPolinomio( ITDAPolinomio* original );
	ITDAPolinomio* CopiarPolinomioLista( ITDAPolinomio* original );

	bool ExistPoli( AnsiString Nombre ){
		bool exists = false;
		for(int i = 1; i <= PosLibrListPoli; i++){
			if( ListPoli[i].Nombre == Nombre ){
				exists = true;
                break;
			}
		}

		return exists;
	}

	void AddPolinomio( AnsiString Nombre, ITDAPolinomio* P, bool IsLista ){
		if( ExistPoli(Nombre) ) return ShowMessage("Polinomio " + Nombre + " ya existe");
		if(PosLibrListPoli == Maximo) return ShowMessage("Lista de polinomios llena");

		ListPoli[PosLibrListPoli].Nombre = Nombre;
		ListPoli[PosLibrListPoli].P = P;
        ListPoli[PosLibrListPoli].IsLista = IsLista;

		PosLibrListPoli++;
	}

	ITDAPolinomio* GetPolinomio( AnsiString Nombre ){
		ITDAPolinomio* P = nullptr;
		for(int i = 1; i <= PosLibrListPoli; i++){
			if( ListPoli[i].Nombre == Nombre ){
				P = ListPoli[i].P;
				break;
			}
		}

		return P;
	}

	bool IsLista( AnsiString Nombre ){
		bool islista = false;
		for(int i = 1; i <= PosLibrListPoli; i++){
			if( ListPoli[i].Nombre == Nombre ){
				islista = ListPoli[i].IsLista;
				break;
			}
		}

		return islista;
	}

};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif
