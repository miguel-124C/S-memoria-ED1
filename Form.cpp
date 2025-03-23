//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Form.h"

//----------- Implementaciones-------------------
// Memoria
#include "./Clases/CSMemoria.h"
// Listas
#include "./Clases/CListaVector.h"
#include "./Clases/CListaSMemoria.h"
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

	SMEMORIA = new CSMemoria( 0 );
	MemoriaCreada = true;
	UpdateLibreDisponible();

	return true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BtnPedirEspacioClick(TObject *Sender)
{
    if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

	AnsiString nombreEspacio = ENombreEspacio->Text.Trim();
	int disponible = SMEMORIA->EspacioDisponible();

	if( disponible == 0 ){
		ShowMessage("Memoria llena, no hay espacios disponibles");
		return;
	}
	if( nombreEspacio.Length() == 0 ){
		ShowMessage("Ingrese un nombre");
		return;
	}

	int cantidadIds = SMEMORIA->NumeroIds(nombreEspacio);
	if( cantidadIds > disponible ){
		ShowMessage( "No hay espacio para reservar " + IntToStr(cantidadIds) + " espacio/s" );
		return;
	}

	int direccion = SMEMORIA->NewEspacio( nombreEspacio );

	ENombreEspacio->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BtnLiberarEspacioClick(TObject *Sender)
{
    if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

	AnsiString dirStr = ENombreLiberarEspacio->Text.Trim();
	if( dirStr.Length() == 0 ){
		ShowMessage("Ingrese una dirección");
		return;
	}

	int dir = StrToInt(dirStr);
	bool estaLibre = SMEMORIA->DirLibre(dir);

	if(estaLibre){
		ShowMessage("Dir ya estaba liberado");
        ENombreLiberarEspacio->Text = "";
		return;
	}

	SMEMORIA->DeleteEspacio( dir );
	ShowMessage("Espacio en memoria liberado");
	ENombreLiberarEspacio->Text = "";
}
//---------------------------------------------------------------------------


void __fastcall TForm2::BtnPonerDatoClick(TObject *Sender)
{
    if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

	int dir 		= StrToInt(EDireccionPonerDato->Text);
	AnsiString id 	= EIdPonerDato->Text;
	int valor 		= StrToInt(EValorPonerDato->Text);

	// Validar
	bool estaLibre = SMEMORIA->DirLibre(dir);

	if(estaLibre){
    	ShowMessage("Dir está libre");
		return;
	}

	SMEMORIA->PonerDato(dir, id, valor);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BtnMostrarMemoriaClick(TObject *Sender)
{
    if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

	int inicio = StrToInt(EInicioMemoria->Text);
	int fin    = StrToInt(EFinMemoria->Text);

	if( !(inicio > 0 && fin <= SMEMORIA->Max() ) ) return ShowMessage("Fuera de rango");

	DibujarMemoria( inicio, fin );
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

	AnsiString question = "Ingrese\n1 = lista de vectores\n2 = lista SMemoria\n3 = lista con punteros\n";
	AnsiString dato = InputBox("Entrada de datos", question, 1);

	TipoLista = StrToInt(dato);

	if( TipoLista == 1){
		TDALISTA = new CListaVector();
		ListaCreada = true;
		LabelTipoLista->Caption = "Lista con vectores";
		return;
	}
	if( TipoLista == 2){
		CreateMemoria();
		TDALISTA = new CListaSMemoria( SMEMORIA );
		ListaCreada = true;
		LabelTipoLista->Caption = "Lista con Memoria";
		return;
	}
	if( TipoLista == 3){
		ListaCreada = true;
		LabelTipoLista->Caption = "Lista con Punteros";
		return;
	}

    return ShowMessage("Valor no valido, no se creo la lista");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BtnInsertInicioClick(TObject *Sender)
{
	AnsiString valueInicio = EListaInsertInicio->Text.Trim();
	if( valueInicio.IsEmpty() ){
        ShowMessage("Ingrese un valor inicial");
		return;
	}

    int valor = StrToInt(valueInicio);
	TDALISTA->Inserta_primero( valor );
	EListaInsertInicio->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BtnInsertFinClick(TObject *Sender)
{
	AnsiString valueFin = EListaInsertFin->Text.Trim();
	if( valueFin.IsEmpty() ){
		ShowMessage("Ingrese un valor final");
		return;
	}

	int valor = StrToInt(valueFin);
	TDALISTA->Inserta_ultimo( valor );
	EListaInsertFin->Text = "";
}
//---------------------------------------------------------------------------



