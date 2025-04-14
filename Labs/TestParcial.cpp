//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TestParcial.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;

// Memoria
#include "./Clases/CSMemoria.h"
#include "./Clases/Polinomio/CPoliSMemoria.h"

//#include "./Clases/Polinomio/Polinomio-Listas/CPoliListaSMem.h"

//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm6::BtnCreateMemoriaClick(TObject *Sender)
{
	SMEMORIA = new CSMemoria( 0, Canvas );
//	TDALISTA = new CListaSMemoria( SMEMORIA, Canvas );
	MemoriaCreada = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm6::BtnPedirEspacioClick(TObject *Sender)
{
	if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

	AnsiString nombreEspacio = ENombreEspacio->Text.Trim();
	if( nombreEspacio.Length() == 0 ) return ShowMessage("Ingrese un nombre");

	int direccion = SMEMORIA->NewEspacio( nombreEspacio );
	ENombreEspacio->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm6::BtnLiberarEspacioClick(TObject *Sender)
{
	if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

	AnsiString dirStr = ENombreLiberarEspacio->Text.Trim();
	if( dirStr.Length() == 0 ) return ShowMessage("Ingrese una dirección");

	int dir = StrToInt(dirStr);

	SMEMORIA->DeleteEspacio( dir );
	ENombreLiberarEspacio->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm6::BtnMostrarMemoriaClick(TObject *Sender)
{
	if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

//	int inicio = StrToInt(EInicioMemoria->Text);
//	int fin    = StrToInt(EFinMemoria->Text);

//	SMEMORIA->pagStart = inicio;
//	SMEMORIA->pagEnd = fin;

	Repaint();
	SMEMORIA->MostrarMemoria();
}
//---------------------------------------------------------------------------
void __fastcall TForm6::BtnCreatePoliClick(TObject *Sender)
{
	if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

	AnsiString nombrePolinomio = ECreateNombrePoli->Text.Trim();
	if(nombrePolinomio.IsEmpty()) return ShowMessage("Ingrese un nombre a su polinomio");

	TDAPOLINOMIO = new CPoliSMemoria( SMEMORIA, Canvas );
	TDAPOLINOMIO->Crea();
	PolinomioCreado = true;

	ECreateNombrePoli->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm6::BtnMostrarPoliClick(TObject *Sender)
{
	if(!PolinomioCreado) return ShowMessage("Ningun polinomio creado");

	AnsiString nombrePolinomio = ENombrePoliMostrar->Text.Trim();
	if(nombrePolinomio.IsEmpty()) return ShowMessage("Ingrese un nombre a su polinomio");

	Repaint();
	TDAPOLINOMIO->MostrarPolinomio();

//	ENombrePoliMostrar->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm6::BtnPonerTerminoClick(TObject *Sender)
{
	if(!PolinomioCreado) return ShowMessage("Ningun polinomio creado");

	AnsiString nombrePolinomio = ENombrePoliPonerTerm->Text.Trim();
	if(nombrePolinomio.IsEmpty()) return ShowMessage("Ingrese un nombre a su polinomio");

	AnsiString coef = ECoef->Text.Trim();
	if( coef.IsEmpty() ) return ShowMessage("Ingrese un valor en Coeficiente");

	AnsiString exp = EExp->Text.Trim();
	if( exp.IsEmpty() ) return ShowMessage("Ingrese un valor en Exponente");

	int Coef = StrToInt(coef);
	int Exp  = StrToInt(exp);
	TDAPOLINOMIO->PonerTermino( Coef, Exp );

//    ENombrePoliPonerTerm->Text = "";
	ECoef->Text = "";
	EExp->Text  = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm6::BtnDerivadaClick(TObject *Sender)
{
	AnsiString nombrePolinomio = ENombrePoliDerivada->Text.Trim();
	if(nombrePolinomio.IsEmpty()) return ShowMessage("Ingrese un nombre a su polinomio");

	ITDAPolinomio* PoliAux = CopiarPolinomio(TDAPOLINOMIO);
    TDAPOLINOMIO->VaciarPolinomio();
	//new CPoliSMemoria( SMEMORIA, Canvas )
	TDAPOLINOMIO->Derivada( PoliAux, TDAPOLINOMIO );

	delete( PoliAux );
	delete( CopySMemoria );
//    ENombrePoliDerivada->Text = "";
}
//---------------------------------------------------------------------------

ITDAPolinomio* TForm6::CopiarPolinomio( ITDAPolinomio* original ){
	CopySMemoria = new CSMemoria( 0, Canvas );

	ITDAPolinomio* copia = new CPoliSMemoria( CopySMemoria, Canvas );
	copia->Crea();

	for (int i = 1; i <= original->NumeroTerminos(); i++) {
		int exp = original->Exponente(i);
		int coef = original->Coeficiente(exp);
		copia->PonerTermino(coef, exp);
	}

	return copia;
}