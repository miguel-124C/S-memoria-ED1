//---------------------------------------------------------------------------

#ifndef FormH
#define FormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

// Importando Clases Abstractas
#include "./Interfaces/ISMemoria.h"
#include "./Interfaces/ITDALista.h"


//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TButton *BtnCreateMemoria;
	TButton *BtnPedirEspacio;
	TButton *BtnLiberarEspacio;
	TButton *BtnMostrarMemoria;
	TButton *BtnPonerDato;
	TEdit *ENombreEspacio;
	TEdit *ENombreLiberarEspacio;
	TEdit *EInicioMemoria;
	TEdit *EFinMemoria;
	TEdit *EDireccionPonerDato;
	TEdit *EIdPonerDato;
	TEdit *EValorPonerDato;
	TButton *BtnCrearLista;
	TLabel *LabelTipoLista;
	TLabel *LLibre;
	TLabel *LDisponible;
	TButton *BtnInsertInicio;
	TButton *BtnInsertFin;
	TButton *BtnMostrarLista;
	TEdit *EListaInsertInicio;
	TEdit *EListaInsertFin;
	void __fastcall BtnCreateMemoriaClick(TObject *Sender);
	void __fastcall BtnPedirEspacioClick(TObject *Sender);
	void __fastcall BtnLiberarEspacioClick(TObject *Sender);
	void __fastcall BtnPonerDatoClick(TObject *Sender);
	void __fastcall BtnMostrarMemoriaClick(TObject *Sender);
	void __fastcall BtnCrearListaClick(TObject *Sender);
	void __fastcall BtnInsertInicioClick(TObject *Sender);
	void __fastcall BtnInsertFinClick(TObject *Sender);
private:	// User declarations

	// Simulador de memoria
	ISMemoria<int>* SMEMORIA;
	bool MemoriaCreada = false;
	bool CreateMemoria();

    // TDA Lista
	ITDALista<int>* TDALISTA;
    int TipoLista = 1; // 1 = ListaVectores | 2 = ListaMemoria | 3 = ListaPunteros
	bool ListaCreada = false;

    void UpdateLibreDisponible();

	//--------------------------------------------------------------------------
	// CANVAS Memoria
	// Propiedades para dibujar con canvas
	TColor BgDir  = (TColor)0xffffff;
	TColor BgDato = (TColor)0x55dd33;
	TColor BgId   = (TColor)0x22ffff;
	TColor BgLink = (TColor)0x22ffff;

	// Tamaño de cada campo
	int WidthDir  = 40;
	int WidthDato = 300;
	int WidthId   = 270;
	int WidthLink = 60;

	int HeightFields = 35;
    //--------------------------------------------------------------------------



public:		// User declarations
	__fastcall TForm2(TComponent* Owner);

	//--------------------------------------------------------------------------
	// Métodos para dibujar memoria
	void DibujarRow( int &x1, int &y1, int index ){
		Canvas->Pen->Color = (TColor)0x000000;
		int y2 = HeightFields + y1;

		TColor colorTextBody = (TColor)0x000000;

		DibujarField( x1, y1, BgDir, WidthDir, SMEMORIA->MEM[index].dir, colorTextBody );
		DibujarField( x1, y1, BgDato, WidthDato, SMEMORIA->MEM[index].dato, colorTextBody );
		DibujarField( x1, y1, BgId, WidthId, SMEMORIA->MEM[index].id, colorTextBody );
		DibujarField( x1, y1, BgLink, WidthLink, SMEMORIA->MEM[index].link, colorTextBody );

		y1 = y2;
	}

	void DibujarField( int &x1, int &y1, TColor color, int width, AnsiString texto, TColor colorText ){
		int y2 = HeightFields + y1;

		Canvas->Brush->Color = color;
		int x2 = x1 + width;
		Canvas->Rectangle(x1, y1, x2, y2);

		Canvas->Font->Size = 14;
		Canvas->Font->Color = colorText;
		Canvas->TextOut(x1 + 2, y1 + 5, texto);
		x1 = x2;
	}

	void DibujarMemoria( int inicio, int fin ){
	    Repaint();
		int x1 = 500; int y1 = 10;
		int y2 = HeightFields + y1;

		// RGB BGR
		TColor colorTextHeader = (TColor)0x0000ff;

		DibujarField( x1, y1, clBtnFace, WidthDir, "DIR", colorTextHeader);
		DibujarField( x1, y1, clBtnFace, WidthDato, "DATO", colorTextHeader);
		DibujarField( x1, y1, clBtnFace, WidthId, "ID", colorTextHeader);
		DibujarField( x1, y1, clBtnFace, WidthLink, "LINK", colorTextHeader);

		x1 = 500; y1 = y2;
		for( int i = inicio - 1; i < fin; i++ ) {
			DibujarRow(x1, y1, i);
			x1 = 500;
		}
	}
	//--------------------------------------------------------------------------



};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
