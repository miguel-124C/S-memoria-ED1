//---------------------------------------------------------------------------

#pragma hdrstop

#include "CSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

// Constructor
CSMemoria::CSMemoria( TipoDatoMem valueDefault, TCanvas* canvas ) {
	for( int i = 0; i < Max(); i++ ) {
        MEM[i].dir 	= i;
		MEM[i].link = i +1;
        MEM[i].dato = valueDefault;
	}

	MEM[Max() - 1].link = Nulo();
	setLibre(0);
    setCanvas( canvas );
}

int CSMemoria::NewEspacio(AnsiString cadena) {
	int cantidadIds = NumeroIds( cadena );

    if( EspacioDisponible() == 0 ){
		ShowMessage("Memoria llena, no hay espacios disponibles");
		return Nulo();
	}
	if( cantidadIds > EspacioDisponible() ){
		ShowMessage( "No hay espacio para reservar " + IntToStr(cantidadIds) + " espacio/s" );
		return Nulo();
	}

	int DIR = getLibre();
	int D 	= getLibre();
	for( int i = 1; i <= cantidadIds - 1; i++ ) {
		MEM[D].id = ObtenerId(cadena, i);
		D = MEM[D].link;
	}
	setLibre(MEM[D].link);
	MEM[D].link = -1;
	MEM[D].id = ObtenerId(cadena, cantidadIds);

    return DIR;
}

void CSMemoria::DeleteEspacio(int dir) {
	if(DirLibre(dir)) return ShowMessage("Dir ya estaba liberado");

    int x = dir;
	while( MEM[x].link != -1 ) {
		x = MEM[x].link;
	}

	MEM[x].link = getLibre();
	setLibre( dir );
    ShowMessage("Espacio en memoria liberado");
}

void CSMemoria::PonerDato(int dir, AnsiString cadena_id, TipoDatoMem valor) {
	if(DirLibre(dir)) return ShowMessage("Dir está libre");

	int z = dir;
	bool idEncontrado = false;
	while( z != -1 ){
		if( MEM[z].id == cadena_id ){
			MEM[z].dato = valor;
            idEncontrado = true;
		}
		z = MEM[z].link;
	}

    if( !idEncontrado ) ShowMessage("No se pudo añadir el dato, ya que no existe un espacio en memoria llamado " + cadena_id);
}

TipoDatoMem CSMemoria::ObtieneDato(int dir, AnsiString cadena_id) {
	TipoDatoMem dato;
	int z = dir;
	while( z != -1 ){
		if( MEM[z].id == cadena_id ){
			dato = MEM[z].dato;
		}
		z = MEM[z].link;
	}

    return dato;
}

int CSMemoria::EspacioDisponible() {
	int x = getLibre();
	int c = 0;

	while( x != -1 ){
		c++;
		x = MEM[x].link;
	}

	return c;
}

int CSMemoria::EspacioOcupado() {
	return Max() - EspacioDisponible();
}

bool CSMemoria::DirLibre(int dir) {
	int x = getLibre();
	int c = false;

	while( x != -1 && !c ){
		if( dir == x ){
			c = true;
            break;
		}
		x = MEM[x].link;
	}

	return c;
}

void CSMemoria::MostrarMemoria(){
	int x1 = 500; int y1 = 10;
	int y2 = HeightFields + y1;

	// RGB BGR
	TColor colorTextHeader = (TColor)0x0000ff;

	DibujarField( x1, y1, clBtnFace, WidthDir, "DIR", colorTextHeader);
	DibujarField( x1, y1, clBtnFace, WidthDato, "DATO", colorTextHeader);
	DibujarField( x1, y1, clBtnFace, WidthId, "ID", colorTextHeader);
	DibujarField( x1, y1, clBtnFace, WidthLink, "LINK", colorTextHeader);

	if(pagStart == 0 || pagEnd == 0) return ShowMessage("No hay valor en inicio y fin");
	if( !(pagStart > 0 && pagEnd <= Max() ) ) return ShowMessage("Fuera de rango");

	x1 = 500; y1 = y2;
	for( int i = pagStart - 1; i < pagEnd; i++ ) {
		DibujarRow(x1, y1, i);
		x1 = 500;
	}
}
