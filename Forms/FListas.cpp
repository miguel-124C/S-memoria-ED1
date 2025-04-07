//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FListas.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;

#include "./Clases/CSMemoria.h"

#include "./Clases/Listas/CListaSMemoria.h"
#include "./Clases/Listas/CListaVector.h"
#include "./Clases/Listas/CListaPuntero.h"

//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//----------------------Métodos CSMemoria------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm4::BtnCreateMemoriaClick(TObject *Sender)
{
	if(!CreateMemoria()){
		ShowMessage("Memoria ya creada");
	}
}
//---------------------------------------------------------------------------
bool TForm4::CreateMemoria(){
	if(MemoriaCreada) return false;

	SMEMORIA = new CSMemoria( 0, Canvas );
	MemoriaCreada = true;
	UpdateLibreDisponible();

	return true;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::BtnPedirEspacioClick(TObject *Sender)
{
    if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

	AnsiString nombreEspacio = ENombreEspacio->Text.Trim();
	if( nombreEspacio.Length() == 0 ) return ShowMessage("Ingrese un nombre");

	int direccion = SMEMORIA->NewEspacio( nombreEspacio );
	ENombreEspacio->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm4::BtnLiberarEspacioClick(TObject *Sender)
{
	if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

	AnsiString dirStr = ENombreLiberarEspacio->Text.Trim();
	if( dirStr.Length() == 0 ) return ShowMessage("Ingrese una dirección");

	int dir = StrToInt(dirStr);

	SMEMORIA->DeleteEspacio( dir );
	ENombreLiberarEspacio->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm4::BtnMostrarMemoriaClick(TObject *Sender)
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
//---------------------------------------------------------------------------
void TForm4::UpdateLibreDisponible(){
	int libre = SMEMORIA->getLibre();
	int disponible = SMEMORIA->EspacioDisponible();
//   	LLibre->Caption = "Libre " + IntToStr(libre);
//	LDisponible->Caption = "Espacio Disponible " + IntToStr(disponible);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//--------------------------Métodos Listas-----------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm4::BtnCreateListaClick(TObject *Sender)
{
	if(ListaCreada) return ShowMessage("Lista ya creada");
	SelectedTypeLista();
}
//---------------------------------------------------------------------------
void TForm4::SelectedTypeLista(){
	UnicodeString seleccion;
	if( InputQuery("Crear lista con", "1: SMemoria\n2: Vector\n3: Punteros", seleccion) ){
		int opcion = seleccion.ToIntDef(0);
		switch (opcion)
		{
			case 1:{
				if(!MemoriaCreada){
					ShowMessage("Memoria no creada");
                    return;
				}
				delete(TDALISTA);
				TDALISTA = new CListaSMemoria( SMEMORIA, Canvas );
				CreateLista("SMemoria");
				break;
			}
			case 2:{
				delete(TDALISTA);
				TDALISTA = new CListaVector( Canvas );
				CreateLista("Vectores");
				break;
			}
			case 3:{
				delete(TDALISTA);
				TDALISTA = new CListaPuntero( Canvas );
				CreateLista("Punteros");
				break;
			}
			default: ShowMessage("Opción no válida. No se creo ningun polinomio."); break;
		}
	}else{
		ShowMessage("No se creo ningun polinomio");
	}
}

void TForm4::CreateLista( AnsiString TypeLista ){
	LTitleLista->Caption = "Lista con " + TypeLista;
	TDALISTA->Crear();
	ListaCreada = true;
	BtnChangeType->Visible = true;
}
void __fastcall TForm4::BtnChangeTypeClick(TObject *Sender)
{
	SelectedTypeLista();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::BtnMostrarListaClick(TObject *Sender)
{
	if(!ListaCreada) return ShowMessage("Ninguna lista creada");

    Repaint();
    TDALISTA->MostrarLista();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::BtnInsertInicioClick(TObject *Sender)
{
	if(!ListaCreada) return ShowMessage("Ninguna lista creada");

	AnsiString inicio = EInsertInicio->Text.Trim();
	if( inicio.IsEmpty() ) return ShowMessage("Ingrese un dato para añadir al inicio");

	int elemento = StrToInt( inicio );
	TDALISTA->Inserta_primero( elemento );
	EInsertInicio->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm4::BtnInsertFinalClick(TObject *Sender)
{
	if(!ListaCreada) return ShowMessage("Ninguna lista creada");

	AnsiString fin = EInsertFin->Text.Trim();
	if( fin.IsEmpty() ) return ShowMessage("Ingrese un dato para añadir al final");

	int elemento = StrToInt( fin );
	TDALISTA->Inserta_ultimo( elemento );
	EInsertFin->Text = "";
}
//---------------------------------------------------------------------------

