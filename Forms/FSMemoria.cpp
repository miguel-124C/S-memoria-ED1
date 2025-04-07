//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// Memoria
#include "./Clases/CSMemoria.h"

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnCreateMemoriaClick(TObject *Sender)
{
	if(!CreateMemoria()){
		ShowMessage("Memoria ya creada");
	}
}
//---------------------------------------------------------------------------
bool TForm1::CreateMemoria(){
	if(MemoriaCreada) return false;

	SMEMORIA = new CSMemoria( 0, Canvas );
	MemoriaCreada = true;

	return true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnPedirEspacioClick(TObject *Sender)
{
    if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

	AnsiString nombreEspacio = ENombreEspacio->Text.Trim();
	if( nombreEspacio.Length() == 0 ) return ShowMessage("Ingrese un nombre");

	int direccion = SMEMORIA->NewEspacio( nombreEspacio );
	ENombreEspacio->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnLiberarEspacioClick(TObject *Sender)
{
    if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

	AnsiString dirStr = ENombreLiberarEspacio->Text.Trim();
	if( dirStr.Length() == 0 ) return ShowMessage("Ingrese una dirección");

	int dir = StrToInt(dirStr);

	SMEMORIA->DeleteEspacio( dir );
	ENombreLiberarEspacio->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnPonerDatoClick(TObject *Sender)
{
    if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

	int dir 		= StrToInt(EDireccionPonerDato->Text);
	AnsiString id 	= EIdPonerDato->Text;
	int valor 		= StrToInt(EValorPonerDato->Text);

	SMEMORIA->PonerDato(dir, id, valor);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnMostrarMemoriaClick(TObject *Sender)
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
