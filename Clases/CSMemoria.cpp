//---------------------------------------------------------------------------

#pragma hdrstop

#include "CSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

// Constructor
CSMemoria::CSMemoria( TipoDato valueDefault ) {
	for( int i = 0; i < Max(); i++ ) {
        MEM[i].dir 	= i;
		MEM[i].link = i +1;
        MEM[i].dato = valueDefault;
	}

	MEM[Max() - 1].link = Nulo();
    setLibre(0);
}

int CSMemoria::NewEspacio(AnsiString cadena) {
	int cantidadIds = NumeroIds( cadena );
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
    int x = dir;
	while( MEM[x].link != -1 ) {
		x = MEM[x].link;
	}

	MEM[x].link = getLibre();
    setLibre( dir );
}

void CSMemoria::PonerDato(int dir, AnsiString cadena_id, TipoDato valor) {
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

TipoDato CSMemoria::ObtieneDato(int dir, AnsiString cadena_id) {
	TipoDato dato;
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
