//---------------------------------------------------------------------------

#ifndef PlanoCartesianoH
#define PlanoCartesianoH
//---------------------------------------------------------------------------

class PlanoCartesiano {
private:
public:
	TCanvas* Canvas;

	PlanoCartesiano( TCanvas* canvas );

	float Centerx = 800;
	float Centery = 405;

	int limitePlano = 10;
    int SizeSeparacion = 30;

	float TransformCoordX( float coordX );
    float TransformCoordY( float coordY );

	void GraficaPlano( float limiteInf, float limiteSup );
    void GraficaLinea( float x1, float y1, float x2, float y2 );
};
#endif
