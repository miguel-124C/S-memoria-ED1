//---------------------------------------------------------------------------
#ifndef CSMemoriaH
#define CSMemoriaH

#include "../Interfaces/ISMemoria.h"

typedef int TipoDatoMem;

class CSMemoria : public ISMemoria<TipoDatoMem> {
public:
	// Constructor
	CSMemoria( TipoDatoMem valueDefault, TCanvas* canvas );

	// Métodos heredados
	int NewEspacio(AnsiString cadena) override;
	void DeleteEspacio(int dir) override;
	void PonerDato(int dir, AnsiString cadena_id, TipoDatoMem valor) override;
	TipoDatoMem ObtieneDato(int dir, AnsiString cadena_id) override;
	int EspacioDisponible() override;
	int EspacioOcupado() override;
	bool DirLibre(int dir) override;

	void MostrarMemoria() override;



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


    // Métodos para dibujar memoria
	void DibujarRow( int &x1, int &y1, int index ){
		canvas->Pen->Color = (TColor)0x000000;
		int y2 = HeightFields + y1;

		TColor colorTextBody = (TColor)0x000000;

		DibujarField( x1, y1, BgDir, WidthDir, MEM[index].dir, colorTextBody );
		DibujarField( x1, y1, BgDato, WidthDato, MEM[index].dato, colorTextBody );
		DibujarField( x1, y1, BgId, WidthId, MEM[index].id, colorTextBody );
		DibujarField( x1, y1, BgLink, WidthLink, MEM[index].link, colorTextBody );

		y1 = y2;
	}

	void DibujarField( int &x1, int &y1, TColor color, int width, AnsiString texto, TColor colorText ){
		int y2 = HeightFields + y1;

		canvas->Brush->Color = color;
		int x2 = x1 + width;
		canvas->Rectangle(x1, y1, x2, y2);

		canvas->Font->Size = 14;
		canvas->Font->Color = colorText;
		canvas->TextOut(x1 + 2, y1 + 5, texto);
		x1 = x2;
	}

};

#endif
