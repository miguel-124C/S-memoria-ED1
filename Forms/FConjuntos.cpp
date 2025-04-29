//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FConjuntos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//----------- Implementaciones-------------------
// Memoria
#include "./Clases/CSMemoria.h"
#include "./Clases/Conjunto/CConjSMemoria.h"

TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm7::BtnCreateMemoriaClick(TObject *Sender)
{
	if(MemoriaCreada) return ShowMessage("Memoria ya creada");
	SMEMORIA = new CSMemoria( 0, Canvas );
    MemoriaCreada = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm7::BtnPedirEspacioClick(TObject *Sender)
{
    if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

	AnsiString nombreEspacio = ENombreEspacio->Text.Trim();
	if( nombreEspacio.Length() == 0 ) return ShowMessage("Ingrese un nombre");

	int direccion = SMEMORIA->NewEspacio( nombreEspacio );
	ENombreEspacio->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm7::BtnMostrarMemoriaClick(TObject *Sender)
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//----------------------Métodos TDAConjunto----------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void TForm7::CreateConjunto( AnsiString TypePoli ){
	Type = TypePoli;
	LTitleConj->Caption = "Conjunto con " + TypePoli;
	TDACONJUNTO->Crear();
	ConjuntoCreado = true;
	BtnChangeType->Caption = "Cambiar conjunto";
}
//---------------------------------------------------------------------------
void TForm7::SelectedTypeConj(){
	UnicodeString seleccion;
	if(
		InputQuery(
			"Crear Conjunto con", "1: SMemoria\n2: Vector\n3: Punteros\n4: Lista",
			seleccion
		)
	){
		int opcion = seleccion.ToIntDef(0);
		switch (opcion)
		{
			case 1:{
				if(!MemoriaCreada) return ShowMessage("No se ha creado SMemoria");
				delete(TDACONJUNTO);
				CreateConjunto("SMemoria");
				break;
			}
//			case 2:{
//				delete(TDACONJUNTO);
//				TDACONJUNTO = new CPoliVector( Canvas );
//				CreatePolinomio("Vectores");
//				break;
//			}
//			case 3:{
//				delete(TDACONJUNTO);
//				TDACONJUNTO = new CPoliPuntero( Canvas );
//	            CreatePolinomio("Punteros");
//				break;
//			}
			default: ShowMessage("Opción no válida. No se creo ningun conjunto."); return;
		}
	}else{
		ShowMessage("No se creo ningun conjunto");
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm7::BtnCreaConjAClick(TObject *Sender)
{
	if( Type == "SMemoria" ){
		if(!MemoriaCreada) return ShowMessage("NO se creo ninguna Memoria");
		ConjuntoA = new CConjSMemoria( SMEMORIA, Canvas );
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm7::BtnCreaConjBClick(TObject *Sender)
{
	if( Type == "SMemoria" ){
		if(!MemoriaCreada) return ShowMessage("NO se creo ninguna Memoria");
		ConjuntoB = new CConjSMemoria( SMEMORIA, Canvas );
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm7::BtnCreaConjCClick(TObject *Sender)
{
	if( Type == "SMemoria" ){
		if(!MemoriaCreada) return ShowMessage("NO se creo ninguna Memoria");
		ConjuntoC = new CConjSMemoria( SMEMORIA, Canvas );
		return;
	}
}
//---------------------------------------------------------------------------

