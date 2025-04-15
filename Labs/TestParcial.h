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

struct Polinomio {
	AnsiString Nombre;
	ITDAPolinomio* P;
};
//struct Polinomio {
//	AnsiString Nombre;
//	CListaSMemoria* P;
//};

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
	void __fastcall BtnCreateMemoriaClick(TObject *Sender);
	void __fastcall BtnPedirEspacioClick(TObject *Sender);
	void __fastcall BtnLiberarEspacioClick(TObject *Sender);
	void __fastcall BtnMostrarMemoriaClick(TObject *Sender);
	void __fastcall BtnCreatePoliClick(TObject *Sender);
	void __fastcall BtnMostrarPoliClick(TObject *Sender);
	void __fastcall BtnPonerTerminoClick(TObject *Sender);
	void __fastcall BtnDerivadaClick(TObject *Sender);
	void __fastcall BtnGraficarClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm6(TComponent* Owner);

    // Simulador de memoria
	ISMemoria<int>* SMEMORIA;
	bool MemoriaCreada = false;

    ISMemoria<int>* CopySMemoria;

	CListaSMemoria* TDALISTA;
	bool ListaCreada = false;

	const static int Maximo = 100;
	int PosLibrListPoli = 1;
	Polinomio ListPoli[Maximo];

	ITDAPolinomio* TDAPOLINOMIO;
	bool PolinomioCreado = false;

	ITDAPolinomio* CopiarPolinomio( ITDAPolinomio* original );

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

	void AddPolinomio( AnsiString Nombre, ITDAPolinomio* P ){
		if( ExistPoli(Nombre) ) return ShowMessage("Polinomio " + Nombre + " ya existe");
		if(PosLibrListPoli == Maximo) return ShowMessage("Lista de polinomios llena");

		ListPoli[PosLibrListPoli].Nombre = Nombre;
		ListPoli[PosLibrListPoli].P = P;

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
};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif
