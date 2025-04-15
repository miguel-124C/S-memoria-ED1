//---------------------------------------------------------------------------

#pragma hdrstop

#include "PlanoCartesiano.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

PlanoCartesiano::PlanoCartesiano( TCanvas* canvas ){
	Canvas = canvas;
}

float PlanoCartesiano::TransformCoordX( float coordX ){
	return Centerx + (SizeSeparacion * coordX);
}

float PlanoCartesiano::TransformCoordY( float coordY ){
	return Centery - (SizeSeparacion * coordY);
}

void PlanoCartesiano::GraficaPlano( float limiteInf, float limiteSup ){
//    Canvas->Brush->Color = (TColor)0xff00ff;
	Canvas->Pen->Color = (TColor)0x000000;
	Canvas->Font->Size = 10;
	Canvas->Font->Color = clNone;
	// Plano +x
	int x = Centerx; int y = Centery;
	for( int i = 0; i < limitePlano; i++ ){
		Canvas->MoveTo(x, y);
		Canvas->LineTo( x + SizeSeparacion, y);

		Canvas->MoveTo(x + SizeSeparacion, y - 5);
		Canvas->LineTo(x + SizeSeparacion, y + 5);

		Canvas->TextOut((x + SizeSeparacion) - 2, y + 7, i + 1);

        x = x + SizeSeparacion;
	}

    // Plano -x
	x = Centerx; y = Centery;
	for( int i = 0; i < limitePlano; i++ ){
		Canvas->MoveTo(x, y);
		Canvas->LineTo( x - SizeSeparacion, y);

		Canvas->MoveTo(x - SizeSeparacion, y - 5);
		Canvas->LineTo(x - SizeSeparacion, y + 5);

		Canvas->TextOut((x - SizeSeparacion) - 2, y + 7, (i + 1) * - 1);

		x = x - SizeSeparacion;
	}

	// Plano +y
	x = Centerx; y = Centery;
	for( int i = 0; i < limitePlano; i++ ){
		Canvas->MoveTo(x, y);
		Canvas->LineTo(x, y - SizeSeparacion);

		Canvas->MoveTo(x - 5, y - SizeSeparacion);
		Canvas->LineTo(x + 5, y - SizeSeparacion);

		Canvas->TextOut(x + 7, (y - SizeSeparacion) - 2, i + 1);

		y = y - SizeSeparacion;
	}

    // Plano -y
	x = Centerx; y = Centery;
	for( int i = 0; i < limitePlano; i++ ){
		Canvas->MoveTo(x, y);
		Canvas->LineTo(x, y + SizeSeparacion);

		Canvas->MoveTo(x - 5, y + SizeSeparacion);
		Canvas->LineTo(x + 5, y + SizeSeparacion);

		Canvas->TextOut(x + 7, (y + SizeSeparacion) - 2, (i + 1) * -1);

		y = y + SizeSeparacion;
	}

	Canvas->Pen->Color = (TColor)0x1aaad7;

	float LimIn = TransformCoordX( limiteInf );

	float pa1 = Centery - ( limitePlano * SizeSeparacion );
	float pa2 = Centery + ( limitePlano * SizeSeparacion );

	Canvas->MoveTo(LimIn, pa1);
	Canvas->LineTo(LimIn, pa2);


	float LimSup = TransformCoordX( limiteSup );

	float pb1 = Centery - ( limitePlano * SizeSeparacion );
	float pb2 = Centery + ( limitePlano * SizeSeparacion );

	Canvas->MoveTo(LimSup, pb1);
	Canvas->LineTo(LimSup, pb2);
}

void PlanoCartesiano::GraficaLinea( float x1, float y1, float x2, float y2 ){
    Canvas->Pen->Color = (TColor)0x0000ff;

	float CoordX1 = TransformCoordX( x1 );
	float CoordY1 = TransformCoordY( y1 );
	float CoordX2 = TransformCoordX( x2 );
	float CoordY2 = TransformCoordY( y2 );

	Canvas->MoveTo( CoordX1, CoordY1 );
	Canvas->LineTo( CoordX2, CoordY2 );
}
