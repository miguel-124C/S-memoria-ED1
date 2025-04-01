//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FPunteros.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::BtnCrearListaClick(TObject *Sender)
{
	if(ListaCreada) return ShowMessage("Lista ya creada");

	TDALISTA = new CListaPuntero( Canvas );
	TDALISTA->Crear();
	ListaCreada = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::BtnMostrarListaMenClick(TObject *Sender)
{
	if(!ListaCreada) return ShowMessage("No se creo ninguna lista");

	Repaint();
	TDALISTA->MostrarLista();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::BtnInsertInicioClick(TObject *Sender)
{
	if(!ListaCreada) return ShowMessage("Ninguna lista creada");

	AnsiString valueInicio = EListaInsertInicio->Text.Trim();
	if( valueInicio.IsEmpty() ) return ShowMessage("Ingrese un valor inicial");

	int valor = StrToInt(valueInicio);
	TDALISTA->Inserta_primero( valor );
	EListaInsertInicio->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm3::BtnInsertFinClick(TObject *Sender)
{
	if(!ListaCreada) return ShowMessage("Ninguna lista creada");

	AnsiString valueFin = EListaInsertFin->Text.Trim();
	if( valueFin.IsEmpty() ) return ShowMessage("Ingrese un valor final");

	int valor = StrToInt(valueFin);
	TDALISTA->Inserta_ultimo( valor );
	EListaInsertFin->Text = "";
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//----------------------Métodos TDAPolinomios--------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm3::BtnCreatePolinomioClick(TObject *Sender)
{
	if( PolinomioCreado ) return ShowMessage("Polinomio ya creado");

	TDAPOLINOMIO = new CPoliPuntero( Canvas );
	TDAPOLINOMIO->Crea();
	PolinomioCreado = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::BtnMostrarPolinomioClick(TObject *Sender)
{
	if(!PolinomioCreado) return ShowMessage("Ningun polinomio creado");

	Repaint();
    TDAPOLINOMIO->MostrarPolinomio();
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

void __fastcall TForm3::BtnEvaluaPolinomioClick(TObject *Sender)
{
	if(!PolinomioCreado) return ShowMessage("Ningun polinomio creado");

	AnsiString X = EIncognita->Text.Trim();
	if( X.IsEmpty() ) return ShowMessage("Ingrese un valor a X");

    int Incognita = StrToInt( X );
    TDAPOLINOMIO->Evalua( Incognita );
}
//---------------------------------------------------------------------------
