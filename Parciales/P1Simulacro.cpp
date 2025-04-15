//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "P1Simulacro.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;

// Memoria
#include "./Clases/CSMemoria.h"
#include "./Clases/Polinomio/CPoliSMemoria.h"

#include "./Clases/Polinomio/Polinomio-Listas/CPoliListaSMem.h"

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//-------------------Implementado con Polinomio SMemoria---------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm6::BtnCreateMemoriaClick(TObject *Sender)
{
	SMEMORIA = new CSMemoria( 0, Canvas );
	MemoriaCreada = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm6::BtnPedirEspacioClick(TObject *Sender)
{
	if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

	AnsiString nombreEspacio = ENombreEspacio->Text.Trim();
	if( nombreEspacio.Length() == 0 ) return ShowMessage("Ingrese un nombre");

	int direccion = SMEMORIA->NewEspacio( nombreEspacio );
	ENombreEspacio->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm6::BtnLiberarEspacioClick(TObject *Sender)
{
	if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

	AnsiString dirStr = ENombreLiberarEspacio->Text.Trim();
	if( dirStr.Length() == 0 ) return ShowMessage("Ingrese una dirección");

	int dir = StrToInt(dirStr);

	SMEMORIA->DeleteEspacio( dir );
	ENombreLiberarEspacio->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm6::BtnMostrarMemoriaClick(TObject *Sender)
{
	if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

//	int inicio = StrToInt(EInicioMemoria->Text);
//	int fin    = StrToInt(EFinMemoria->Text);

//	SMEMORIA->pagStart = inicio;
//	SMEMORIA->pagEnd = fin;

	Repaint();
	SMEMORIA->MostrarMemoria();
}
//---------------------------------------------------------------------------
ITDAPolinomio* TForm6::CreatePolinomio( bool ListaOrMem ){
	ITDAPolinomio* Polinomio = nullptr;

	if( ListaOrMem ){
        TDALISTA = new CListaSMemoria( SMEMORIA, Canvas );
		Polinomio = new CPoliListaSMem( TDALISTA, Canvas );
	}else{
		Polinomio = new CPoliSMemoria( SMEMORIA, Canvas );
		Polinomio->Crea();
	}

    return Polinomio;
}

void __fastcall TForm6::BtnCreatePoliClick(TObject *Sender)
{
	if(!MemoriaCreada) return ShowMessage("No se creo ninguna memoria");

	AnsiString nombrePolinomio = ECreateNombrePoli->Text.Trim();
	if(nombrePolinomio.IsEmpty()) return ShowMessage("Ingrese un nombre a su polinomio");

	TDAPOLINOMIO = CreatePolinomio( true );
	if(TDAPOLINOMIO == nullptr){ return ShowMessage("No se pudo crear el polinomio"); }

	AddPolinomio( nombrePolinomio, TDAPOLINOMIO, true );

	PolinomioCreado = true;

	ECreateNombrePoli->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm6::BtnMostrarPoliClick(TObject *Sender)
{
	if(!PolinomioCreado) return ShowMessage("Ningun polinomio creado");

	AnsiString nombrePolinomio = ENombrePoliMostrar->Text.Trim();
	if(nombrePolinomio.IsEmpty()) return ShowMessage("Ingrese un nombre a su polinomio");

	TDAPOLINOMIO = GetPolinomio( nombrePolinomio );
	if( TDAPOLINOMIO == nullptr ) return ShowMessage("Polinomio " + nombrePolinomio + " no encontrado");

	Repaint();
	TDAPOLINOMIO->MostrarPolinomio();
}
//---------------------------------------------------------------------------
void __fastcall TForm6::BtnPonerTerminoClick(TObject *Sender)
{
	if(!PolinomioCreado) return ShowMessage("Ningun polinomio creado");

	AnsiString nombrePolinomio = ENombrePoliPonerTerm->Text.Trim();
	if(nombrePolinomio.IsEmpty()) return ShowMessage("Ingrese un nombre a su polinomio");

	AnsiString coef = ECoef->Text.Trim();
	if( coef.IsEmpty() ) return ShowMessage("Ingrese un valor en Coeficiente");

	AnsiString exp = EExp->Text.Trim();
	if( exp.IsEmpty() ) return ShowMessage("Ingrese un valor en Exponente");

	TDAPOLINOMIO = GetPolinomio( nombrePolinomio );
	if( TDAPOLINOMIO == nullptr ) return ShowMessage("Polinomio " + nombrePolinomio + " no encontrado");

	int Coef = StrToInt(coef);
	int Exp  = StrToInt(exp);
	TDAPOLINOMIO->PonerTermino( Coef, Exp );

	ECoef->Text = "";
	EExp->Text  = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm6::BtnDerivadaClick(TObject *Sender)
{
	AnsiString nombrePolinomio = ENombrePoliDerivada->Text.Trim();
	if(nombrePolinomio.IsEmpty()) return ShowMessage("Ingrese un nombre a su polinomio");

	TDAPOLINOMIO = GetPolinomio( nombrePolinomio );
	if( TDAPOLINOMIO == nullptr ) return ShowMessage("Polinomio " + nombrePolinomio + " no encontrado");
    bool isLista = IsLista( nombrePolinomio );

	ITDAPolinomio* PoliAux;
	if(isLista){
		PoliAux = CopiarPolinomioLista(TDAPOLINOMIO);
	}else{
		PoliAux = CopiarPolinomio(TDAPOLINOMIO);
    }

	TDAPOLINOMIO->VaciarPolinomio();
	TDAPOLINOMIO->Derivada( PoliAux, TDAPOLINOMIO );

	delete( PoliAux );
	delete( CopySMemoria );

	if(isLista) delete( CopyLista );
}
//---------------------------------------------------------------------------

ITDAPolinomio* TForm6::CopiarPolinomio( ITDAPolinomio* original ){
	CopySMemoria = new CSMemoria( 0, Canvas );

	ITDAPolinomio* copia = new CPoliSMemoria( CopySMemoria, Canvas );
	copia->Crea();

	for (int i = 1; i <= original->NumeroTerminos(); i++) {
		int exp = original->Exponente(i);
		int coef = original->Coeficiente(exp);
		copia->PonerTermino(coef, exp);
	}

	return copia;
}

ITDAPolinomio* TForm6::CopiarPolinomioLista( ITDAPolinomio* original ){
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

void __fastcall TForm6::BtnGraficarClick(TObject *Sender)
{
	if(!PolinomioCreado) return ShowMessage("Ningun polinomio creado");

	AnsiString nombrePolinomio = EGrafNombrePoli->Text.Trim();
	if(nombrePolinomio.IsEmpty()) return ShowMessage("Ingrese un nombre a su polinomio");

	AnsiString limiteInf = ELimiteInf->Text.Trim();
	if( limiteInf.IsEmpty() ) return ShowMessage("Ingrese un limite inferior");

	AnsiString limiteSup = ELimiteSup->Text.Trim();
	if( limiteSup.IsEmpty() ) return ShowMessage("Ingrese un limite superior");

	AnsiString variable = EVariable->Text.Trim();
	if( variable.IsEmpty() ) return ShowMessage("Ingrese una variable");

	float LimI = StrToFloat( limiteInf );
	float LimSup = StrToFloat( limiteSup );
	float Variable = StrToFloat( variable );

   	TDAPOLINOMIO = GetPolinomio( nombrePolinomio );
	if( TDAPOLINOMIO == nullptr ) return ShowMessage("Polinomio " + nombrePolinomio + " no encontrado");

    Repaint();
	TDAPOLINOMIO->GraficarPolinomio( TDAPOLINOMIO, LimI, LimSup, Variable );
}
//---------------------------------------------------------------------------

void __fastcall TForm6::BtnMultiplicaClick(TObject *Sender)
{
	if(!PolinomioCreado) return ShowMessage("Ningun polinomio creado");

	AnsiString A = EPoliA->Text.Trim();
	if(A.IsEmpty()) return ShowMessage("Ingrese un polinomio A");

	AnsiString B = EPoliB->Text.Trim();
	if( B.IsEmpty() ) return ShowMessage("Ingrese un polinomio B");

	AnsiString Result = EPoliResultMulti->Text.Trim();
	if( Result.IsEmpty() ) return ShowMessage("Ingrese un polinomio donde guardar");

	ITDAPolinomio* PoliA = GetPolinomio( A );
	if( PoliA == nullptr ) return ShowMessage("Polinomio " + A + " no encontrado");
	ITDAPolinomio* PoliB = GetPolinomio( B );
    if( PoliB == nullptr ) return ShowMessage("Polinomio " + B + " no encontrado");

	ITDAPolinomio* PoliC = GetPolinomio( Result );
	if( PoliC == nullptr ) return ShowMessage("Polinomio " + Result + " no encontrado");

    PoliC->Multiplicar( PoliA, PoliB );
}
//---------------------------------------------------------------------------

