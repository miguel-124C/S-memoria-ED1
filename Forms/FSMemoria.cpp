//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FSMemoria.h"

//----------- Implementaciones-------------------
// Memoria
#include "./Clases/CSMemoria.h"
// Listas
#include "./Clases/Listas/CListaSMemoria.h"
// Polinomio
#include "./Clases/Polinomio/CPoliSMemoria.h"
//-----------------------------------------------

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//----------------------Métodos CSMemoria------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm2::BtnCreateMemoriaClick(TObject *Sender)
{
	if(!CreateMemoria()){
		ShowMessage("Memoria ya creada");
	}
}
bool TForm2::CreateMemoria(){
	if(MemoriaCreada) return false;

	SMEMORIA = new CSMemoria( 0, Canvas );
	MemoriaCreada = true;
	UpdateLibreDisponible();

	return true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BtnPedirEspacioClick(TObject *Sender)
{
    if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

	AnsiString nombreEspacio = ENombreEspacio->Text.Trim();
	if( nombreEspacio.Length() == 0 ) return ShowMessage("Ingrese un nombre");

	int direccion = SMEMORIA->NewEspacio( nombreEspacio );
	ENombreEspacio->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BtnLiberarEspacioClick(TObject *Sender)
{
    if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

	AnsiString dirStr = ENombreLiberarEspacio->Text.Trim();
	if( dirStr.Length() == 0 ) return ShowMessage("Ingrese una dirección");

	int dir = StrToInt(dirStr);

	SMEMORIA->DeleteEspacio( dir );
	ENombreLiberarEspacio->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BtnPonerDatoClick(TObject *Sender)
{
    if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

	int dir 		= StrToInt(EDireccionPonerDato->Text);
	AnsiString id 	= EIdPonerDato->Text;
	int valor 		= StrToInt(EValorPonerDato->Text);

	SMEMORIA->PonerDato(dir, id, valor);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BtnMostrarMemoriaClick(TObject *Sender)
{
	if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

	int inicio = StrToInt(EInicioMemoria->Text);
	int fin    = StrToInt(EFinMemoria->Text);

	SMEMORIA->pagStart = inicio;
	SMEMORIA->pagEnd = fin;

    Repaint();
	SMEMORIA->MostrarMemoria();
    UpdateLibreDisponible();
}

void TForm2::UpdateLibreDisponible(){
	int libre = SMEMORIA->getLibre();
	int disponible = SMEMORIA->EspacioDisponible();
   	LLibre->Caption = "Libre " + IntToStr(libre);
	LDisponible->Caption = "Espacio Disponible " + IntToStr(disponible);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//----------------------Métodos TDALista-------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm2::BtnCrearListaClick(TObject *Sender)
{
	if(ListaCreada) return ShowMessage("Lista ya creada");

	CreateMemoria();
	TDALISTA = new CListaSMemoria( SMEMORIA, Canvas );
	TDALISTA->Crear();
	ListaCreada = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BtnInsertInicioClick(TObject *Sender)
{
	if(!ListaCreada) return ShowMessage("Ninguna lista creada");

	AnsiString valueInicio = EListaInsertInicio->Text.Trim();
	if( valueInicio.IsEmpty() ) return ShowMessage("Ingrese un valor inicial");

	int valor = StrToInt(valueInicio);
	TDALISTA->Inserta_primero( valor );
	EListaInsertInicio->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BtnInsertFinClick(TObject *Sender){
	if(!ListaCreada) return ShowMessage("Ninguna lista creada");

	AnsiString valueFin = EListaInsertFin->Text.Trim();
	if( valueFin.IsEmpty() ) return ShowMessage("Ingrese un valor final");

	int valor = StrToInt(valueFin);
	TDALISTA->Inserta_ultimo( valor );
	EListaInsertFin->Text = "";
}

void __fastcall TForm2::BtnMostrarListaMenClick(TObject *Sender)
{
	if(!ListaCreada) return ShowMessage("No se creo ninguna lista");

    Repaint();
	TDALISTA->MostrarLista();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//----------------------Métodos TDAPolinomios--------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void __fastcall TForm2::BtnCreatePolinomioClick(TObject *Sender)
{
	if( PolinomioCreado ) return ShowMessage("Polinomio ya creado");

	CreateMemoria();
	TDAPOLINOMIO = new CPoliSMemoria( SMEMORIA, Canvas );
	TDAPOLINOMIO->Crea();
	PolinomioCreado = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BtnPonerTerminoClick(TObject *Sender)
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

void __fastcall TForm2::BtnMostrarPolinomioClick(TObject *Sender)
{
	if(!PolinomioCreado) return ShowMessage("Ningun polinomio creado");

	Repaint();
    TDAPOLINOMIO->MostrarPolinomio();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::BtnEvaluaPolinomioClick(TObject *Sender)
{
	if(!PolinomioCreado) return ShowMessage("Ningun polinomio creado");

	AnsiString X = EIncognita->Text.Trim();
	if( X.IsEmpty() ) return ShowMessage("Ingrese un valor a X");

    int Incognita = StrToInt( X );
    TDAPOLINOMIO->Evalua( Incognita );
}
//---------------------------------------------------------------------------

