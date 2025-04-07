//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FPolinomios.h"

//----------- Implementaciones-------------------
// Memoria
#include "./Clases/CSMemoria.h"
// Polinomio
#include "./Clases/Polinomio/CPoliSMemoria.h"
#include "./Clases/Polinomio/CPoliVector.h"
#include "./Clases/Polinomio/CPoliPunteros.h"
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

void __fastcall TForm2::BtnMostrarMemoriaClick(TObject *Sender)
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
//---------------------------------------------------------------------------
//----------------------Métodos TDAPolinomios--------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void __fastcall TForm2::BtnCreatePolinomioClick(TObject *Sender)
{
	if( PolinomioCreado ) return ShowMessage("Polinomio ya creado");
	 SelectedTypePolinomio();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BtnChangeTypeClick(TObject *Sender)
{
	SelectedTypePolinomio();
}
//---------------------------------------------------------------------------

void TForm2::SelectedTypePolinomio(){
	UnicodeString seleccion;
	if(
		InputQuery(
			"Crear polinomio con", "1: SMemoria\n2: Vector\n3: Punteros\n4: Lista",
			seleccion
		)
	){
		int opcion = seleccion.ToIntDef(0);
		switch (opcion)
		{
			case 1:{
				if(!MemoriaCreada) return ShowMessage("No se ha creado SMemoria");
				delete(TDAPOLINOMIO);
				TDAPOLINOMIO = new CPoliSMemoria( SMEMORIA, Canvas );
				CreatePolinomio("SMemoria");
				break;
			}
			case 2:{
				delete(TDAPOLINOMIO);
				TDAPOLINOMIO = new CPoliVector( Canvas );
				CreatePolinomio("Vectores");
				break;
			}
			case 3:{
				delete(TDAPOLINOMIO);
				TDAPOLINOMIO = new CPoliPuntero( Canvas );
	            CreatePolinomio("Punteros");
				break;
			}
			default: ShowMessage("Opción no válida. No se creo ningun polinomio."); return;
		}
	}else{
		ShowMessage("No se creo ningun polinomio");
	}
}

void TForm2::CreatePolinomio( AnsiString TypePoli ){
	LTitlePolinomio->Caption = "Polinomio con " + TypePoli;
	TDAPOLINOMIO->Crea();
	PolinomioCreado = true;
    BtnChangeType->Visible = true;
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
