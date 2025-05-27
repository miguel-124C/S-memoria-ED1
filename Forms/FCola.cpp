//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FCola.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;

#include "./Clases/CSMemoria.h"

#include "./Clases/Cola/CColaVectores.h"
#include "./Clases/Cola/CColaMem.h"

//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//----------------------Métodos CSMemoria------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm8::BtnCreateMemoriaClick(TObject *Sender)
{
	if(MemoriaCreada) return ShowMessage("Memoria ya creada");

	SMEMORIA = new CSMemoria( 0, Canvas );
	MemoriaCreada = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm8::BtnPedirEspacioClick(TObject *Sender)
{
    if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

	AnsiString nombreEspacio = ENombreEspacio->Text.Trim();
	if( nombreEspacio.Length() == 0 ) return ShowMessage("Ingrese un nombre");

	int direccion = SMEMORIA->NewEspacio( nombreEspacio );
	ENombreEspacio->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm8::BtnLiberarEspacioClick(TObject *Sender)
{
	if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

	AnsiString dirStr = ENombreLiberarEspacio->Text.Trim();
	if( dirStr.Length() == 0 ) return ShowMessage("Ingrese una dirección");

	int dir = StrToInt(dirStr);

	SMEMORIA->DeleteEspacio( dir );
	ENombreLiberarEspacio->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm8::BtnMostrarMemoriaClick(TObject *Sender)
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



void __fastcall TForm8::BtnCrearColaVectorClick(TObject *Sender)
{
	Cola = new CColaVectores( Canvas );
	Cola->Crear();
    ColaCreada = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm8::BtnPonerClick(TObject *Sender)
{
	if(!ColaCreada) return ShowMessage("No se creo ninguna cola");

	AnsiString dato = EPoner->Text.Trim();
	if( dato.Length() == 0 ) return ShowMessage("Ingrese un dato");

	int elemento = StrToInt(dato);
	Cola->Poner( elemento );
}
//---------------------------------------------------------------------------
void __fastcall TForm8::BtnSacarClick(TObject *Sender)
{
	if(!ColaCreada) return ShowMessage("No se creo ninguna cola");

    Cola->Sacar( 1 );
}
//---------------------------------------------------------------------------
void __fastcall TForm8::BtnMostrarColaClick(TObject *Sender)
{
	if(!ColaCreada) return ShowMessage("No se creo ninguna cola");

    Repaint();
    Cola->MostrarCola();
}
//---------------------------------------------------------------------------

void __fastcall TForm8::BtnCrearVectorMemClick(TObject *Sender)
{
    if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");
	Cola = new CColaMem( SMEMORIA, Canvas );
    Cola->Crear();
	ColaCreada = true;
}
//---------------------------------------------------------------------------

