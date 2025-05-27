//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LabCola.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm9 *Form9;

#include "./Clases/CSMemoria.h"

#include "./Clases/Cola/CColaVectores.h"
#include "./Clases/Cola/CColaVectorV2.h"
#include "./Clases/Cola/CColaVectorV3.h"

#include "./Clases/Cola/CColaMem.h"
#include "./Clases/Cola/CColaLista.h"

//---------------------------------------------------------------------------
__fastcall TForm9::TForm9(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm9::BtnCreateMemoriaClick(TObject *Sender)
{
	if(MemoriaCreada) return ShowMessage("Memoria ya creada");

	SMEMORIA = new CSMemoria( 0, Canvas );
	MemoriaCreada = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm9::BtnPedirEspacioClick(TObject *Sender)
{
    if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

	AnsiString nombreEspacio = ENombreEspacio->Text.Trim();
	if( nombreEspacio.Length() == 0 ) return ShowMessage("Ingrese un nombre");

	int direccion = SMEMORIA->NewEspacio( nombreEspacio );
	ENombreEspacio->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm9::BtnLiberarEspacioClick(TObject *Sender)
{
	if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

	AnsiString dirStr = ENombreLiberarEspacio->Text.Trim();
	if( dirStr.Length() == 0 ) return ShowMessage("Ingrese una dirección");

	int dir = StrToInt(dirStr);

	SMEMORIA->DeleteEspacio( dir );
	ENombreLiberarEspacio->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm9::BtnMostrarMemoriaClick(TObject *Sender)
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
void __fastcall TForm9::BtnPonerClick(TObject *Sender)
{
	if(!ColaCreada) return ShowMessage("No se creo ninguna cola");

	AnsiString dato = EPoner->Text.Trim();
	if( dato.Length() == 0 ) return ShowMessage("Ingrese un dato");

	int elemento = StrToInt(dato);
	Cola->Poner( elemento );
}
//---------------------------------------------------------------------------
void __fastcall TForm9::BtnSacarClick(TObject *Sender)
{
	if(!ColaCreada) return ShowMessage("No se creo ninguna cola");

    Cola->Sacar( 1 );
}
//---------------------------------------------------------------------------
void __fastcall TForm9::BtnMostrarColaClick(TObject *Sender)
{
	if(!ColaCreada) return ShowMessage("No se creo ninguna cola");

    Repaint();
    Cola->MostrarCola();
}
//---------------------------------------------------------------------------
void __fastcall TForm9::BtnCrearColaVectorV2Click(TObject *Sender)
{
	Cola = new CColaVectorV2( Canvas );
	Cola->Crear();
	ColaCreada = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm9::BtnCrearVectorMemClick(TObject *Sender)
{
    if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");
	Cola = new CColaMem( SMEMORIA, Canvas );
    Cola->Crear();
	ColaCreada = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm9::BtnCrearColaVectorV3Click(TObject *Sender)
{
	Cola = new CColaVectorV3( Canvas );
	Cola->Crear();
	ColaCreada = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm9::BtnCrearColaListaClick(TObject *Sender)
{
    if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");
    ListaMem = new CListaSMemoria( SMEMORIA, Canvas );
	Cola = new CColaLista( ListaMem, Canvas );
	Cola->Crear();
	ColaCreada = true;
}
//---------------------------------------------------------------------------

