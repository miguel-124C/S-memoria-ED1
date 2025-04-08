//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Lab2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;

// Memoria
#include "./Clases/CSMemoria.h"

#include "./Clases/Polinomio/Polinomio-Listas/CPoliListaSMem.h"

//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::BtnCreateMemoriaClick(TObject *Sender)
{
	SMEMORIA = new CSMemoria( 0, Canvas );
	TDALISTA = new CListaSMemoria( SMEMORIA, Canvas );
    MemoriaCreada = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::BtnPedirEspacioClick(TObject *Sender)
{
    if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

	AnsiString nombreEspacio = ENombreEspacio->Text.Trim();
	if( nombreEspacio.Length() == 0 ) return ShowMessage("Ingrese un nombre");

	int direccion = SMEMORIA->NewEspacio( nombreEspacio );
	ENombreEspacio->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm3::BtnLiberarEspacioClick(TObject *Sender)
{
	if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

	AnsiString dirStr = ENombreLiberarEspacio->Text.Trim();
	if( dirStr.Length() == 0 ) return ShowMessage("Ingrese una dirección");

	int dir = StrToInt(dirStr);

	SMEMORIA->DeleteEspacio( dir );
	ENombreLiberarEspacio->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm3::BtnMostrarMemoriaClick(TObject *Sender)
{
	if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

	int inicio = StrToInt(EInicioMemoria->Text);
	int fin    = StrToInt(EFinMemoria->Text);

	SMEMORIA->pagStart = inicio;
	SMEMORIA->pagEnd = fin;

    Repaint();
	SMEMORIA->MostrarMemoria();
}
//---------------------------------------------------------------------------


void __fastcall TForm3::BtnCreatePolinomioClick(TObject *Sender)
{
	TDAPOLINOMIO = new CPoliListaSMem( TDALISTA, Canvas );
    PolinomioCreado = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::BtnPonerTerminoClick(TObject *Sender)
{
	if(!PolinomioCreado) return ShowMessage("Ningun polinomio creado");

	AnsiString coef = ECoef->Text.Trim();
	if( coef.IsEmpty() ) return ShowMessage("Ingrese un valor en Coeficiente");

	AnsiString exp = EExp->Text.Trim();
	if( exp.IsEmpty() ) return ShowMessage("Ingrese un valor en Exponente");

	int Coef = StrToInt(coef);
	int Exp  = StrToInt(exp);
	TDAPOLINOMIO->PonerTermino( Coef, Exp );

	ECoef->Text = "";
	EExp->Text  = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm3::BtnMostrarPolinomioClick(TObject *Sender)
{
	if(!PolinomioCreado) return ShowMessage("Ningun polinomio creado");

	Repaint();
	TDAPOLINOMIO->MostrarPolinomio();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::BtnDerivarPolinomioClick(TObject *Sender)
{
    TDAPOLINOMIO->Derivada( TDAPOLINOMIO, TDAPOLINOMIO );
}
//---------------------------------------------------------------------------

