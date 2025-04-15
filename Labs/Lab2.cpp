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

// Crear Memoria
// Perdir espacio para x
// Perdir espacio para y
// Mostrar Memoria
// Liberar direccion 0
// Mostrar Memoria
// Crear Polinomio
// Poner termino 10 a la 3
// Mostar Polinomio
// Mostrar Memoria
// Derivar
// Mostrar Memoria => El actual debe ser reemplazado no crear uno nuevo
// Mostrar Polinomio => 30x2

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
	ITDAPolinomio* PoliAux = CopiarPolinomio(TDAPOLINOMIO);
	TDAPOLINOMIO->VaciarPolinomio();

	TDAPOLINOMIO->Derivada( PoliAux, TDAPOLINOMIO );

	delete( PoliAux );
	delete( CopySMemoria );
	delete( CopyLista );
}
//---------------------------------------------------------------------------
ITDAPolinomio* TForm3::CopiarPolinomio( ITDAPolinomio* original ){
	CopySMemoria = new CSMemoria( 0, Canvas );
	CopyLista = new CListaSMemoria( CopySMemoria, Canvas );

	ITDAPolinomio* copia = new CPoliListaSMem( CopyLista, Canvas );

	copia->Crea();

	for (int i = 1; i <= original->NumeroTerminos(); i++) {
		int exp = original->Exponente(i);
		int coef = original->Coeficiente(exp);
		copia->PonerTermino(coef, exp);
	}

	return copia;
}
