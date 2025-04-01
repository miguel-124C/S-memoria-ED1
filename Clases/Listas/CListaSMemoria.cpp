//---------------------------------------------------------------------------

#pragma hdrstop

#include "CListaSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

CListaSMemoria::CListaSMemoria( ISMemoria<TipoDatoListMem>* memoria, TCanvas* canvas ){
	setCanvas(canvas);
	Memoria = memoria;
}

void CListaSMemoria::Crear(){
	Longitud = 0;
    PtrElementos = -1;
}

DireccionListMem CListaSMemoria::Fin(){
	if( Vacia() ) return -1; // llamar a exception listavacia;

	TipoDatoListMem x = PtrElementos;
	TipoDatoListMem PtrFin;

	while( x != -1 ){
		 PtrFin = x;
		 x = Memoria->ObtieneDato( x, "Sig" );
	}

	return PtrFin;
}

DireccionListMem CListaSMemoria::Primero(){
	if( !Vacia() ) return PtrElementos; // Apunta primer elemento

	return -1; // Llamar exception ListaVacia
}

DireccionListMem CListaSMemoria::Siguiente( DireccionListMem direccion ){
	if( Vacia() ) return 0; // Llamar exception ListaVacia
	if( direccion == Fin() ) return 0; // Llamar exception DireccionErr

	return Memoria->ObtieneDato( direccion, "Sig" );
}

DireccionListMem CListaSMemoria::Anterior( DireccionListMem direccion ){
	if( Vacia() ) return 0; // Llamar exception ListaVacia
	if( direccion == Primero() ) return 0; // Llamar exception DireccionPrimeraErr

	TipoDatoListMem x = PtrElementos;
	TipoDatoListMem anterior = -1;

	while( x != -1 ){
		if( x == direccion ) return anterior;

		anterior = x;
		x = Memoria->ObtieneDato( x, "Sig"  );
	}

	return direccion--;
}

bool CListaSMemoria::Vacia(){
	return Longitud == 0;
}

TipoDatoListMem CListaSMemoria::Recupera( DireccionListMem direccion ){
	if( Vacia() ) return 0; // Llamar exception ListaVacia

    return Memoria->ObtieneDato( direccion, "Elemento"  );
}

int CListaSMemoria::GetLongitud (){
    return Longitud;
}

void CListaSMemoria::Inserta( DireccionListMem direccion, TipoDatoListMem elemento ){
	// X tendria direccion de memoria si existe espacio
	int x = Memoria->NewEspacio("Elemento,Sig");
	int anterior;
	if( x != -1 ){
		Memoria->PonerDato(x, "Elemento", elemento);
		Memoria->PonerDato(x, "Sig", -1);

		if( Vacia() ){
			PtrElementos = x;
			Longitud = 1;
			return;
		}

		Longitud = Longitud + 1;
		if( direccion == Primero() ){
			Memoria->PonerDato(x, "Sig", direccion);
            PtrElementos = x;
		}else{
			anterior = Anterior( direccion );
			Memoria->PonerDato(anterior, "Sig", x);
			Memoria->PonerDato(x, "Sig", direccion);
        }
	}

    return; // llamar a exception existeespaciomemoria
}

void CListaSMemoria::Inserta_primero( TipoDatoListMem elemento ){
	// x tendria direcion de memoria si existe espacio
	int x = Memoria->NewEspacio("Elemento,Sig");

	if( x != -1){
		Memoria->PonerDato(x,"Elemento", elemento);
		Memoria->PonerDato(x,"Sig", PtrElementos);
		Longitud = Longitud + 1;
		PtrElementos = x;
	}else{
        return; // llamar a exception existeespaciomemoria
	}
}

void CListaSMemoria::Inserta_ultimo( TipoDatoListMem elemento ){
	// x tendria direcion de memoria si existe espacio
	int x = Memoria->NewEspacio("Elemento,Sig");

	if( x != -1){
		Memoria->PonerDato(x,"Elemento", elemento);
		Memoria->PonerDato(x,"Sig", -1);
		if (Longitud != 0){
			Memoria->PonerDato(Fin(),"Sig", x);
		}else{
            PtrElementos = x;
        }

		Longitud = Longitud + 1;
	}else{
        return; // llamar a exception existeespaciomemoria
	}
}

void CListaSMemoria::Suprime( DireccionListMem direccion ){
	if( Vacia() ) return; // llamar a exception listavacia

	int x;
	int anterior;
    if( direccion == PtrElementos ){ // es el primer nodo
		x = PtrElementos;
		PtrElementos = Memoria->ObtieneDato(PtrElementos, "Sig");
		// Liberar espacio de memoria x
	}else{
		anterior = Anterior( direccion );
		Memoria->PonerDato(anterior,"Sig", Siguiente(direccion));
        // Liberar espacio de memoria direccion
	}

    Longitud = Longitud - 1;
}

void CListaSMemoria::Modifica( DireccionListMem direccion, TipoDatoListMem elemento){
	if( Vacia() ) return; // llamar a exception listavacia
	Memoria->PonerDato(direccion,"Elemento", elemento);
}

void CListaSMemoria::MostrarLista( ){
	if( Vacia() ) return ShowMessage("Lista Vacia");

	TipoDatoListMem x = PtrElementos;

	while( x != -1 ){
		TipoDatoListMem Elemento = Memoria->ObtieneDato( x, "Elemento" );

        int x2 = X1 + WidthField;
		int y2 = Y1 + HeightField;
		canvas->Brush->Color = (TColor)0xffffff;
		canvas->Rectangle(X1, Y1, x2, y2);

		canvas->Font->Size = 16;
		canvas->TextOut( X1 + 5, Y1 + 5, Elemento );

		X1 += WidthField;

		x = Memoria->ObtieneDato( x, "Sig" );
	}

	X1 = 50;
}
