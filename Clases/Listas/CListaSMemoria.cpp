//---------------------------------------------------------------------------

#pragma hdrstop

#include "CListaSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

CListaSMemoria::CListaSMemoria( ISMemoria<TDListMem>* memoria, TCanvas* canvas ){
	setCanvas(canvas);
	Memoria = memoria;
}

void CListaSMemoria::Crear(){
	Longitud = 0;
    PtrElementos = -1;
}

int CListaSMemoria::Fin(){
	if( Vacia() ){ // llamar a exception listavacia;
		ShowMessage("Lista vacia");
		return -1;
	}

	TDListMem x = PtrElementos;
	TDListMem PtrFin;

	while( x != -1 ){
		 PtrFin = x;
		 x = Memoria->ObtieneDato( x, "Sig" );
	}

	return PtrFin;
}

int CListaSMemoria::Primero(){
	if( !Vacia() ) return PtrElementos; // Apunta primer elemento

	return -1; // Llamar exception ListaVacia
}

int CListaSMemoria::Siguiente( int direccion ){
    if( direccion == -1 ) return -1;

	if( Vacia() ) {// Llamar exception ListaVacia
//		ShowMessage("Lista vacia");
		return -1;
	}
	if( direccion == Fin() ) {// Llamar exception DireccionErr
//        ShowMessage("No hay mas datos");
		return -1;
	}

	return Memoria->ObtieneDato( direccion, "Sig" );
}

int CListaSMemoria::Anterior( int direccion ){
	if( Vacia() ) {// Llamar exception ListaVacia
//		ShowMessage("Lista vacia");
		return -1;
	}
	if( direccion == Primero() ) {// Llamar exception DireccionErr
//        ShowMessage("No hay mas datos");
		return -1;
	}

	TDListMem x = PtrElementos;
	TDListMem anterior = -1;

	while( x != -1 ){
		if( x == direccion ) return anterior;

		anterior = x;
		x = Memoria->ObtieneDato( x, "Sig"  );
	}
}

TDListMem CListaSMemoria::Recupera( int direccion ){
	if( Vacia() ) return -1; // Llamar exception ListaVacia

    return Memoria->ObtieneDato( direccion, "Elemento"  );
}

void CListaSMemoria::Inserta( int direccion, TDListMem elemento ){
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

        return;
	}

    return ShowMessage("No hay espacio o direccion invalida"); // llamar a exception existeespaciomemoria
}

void CListaSMemoria::Inserta_primero( TDListMem elemento ){
	// x tendria direcion de memoria si existe espacio
	int x = Memoria->NewEspacio("Elemento,Sig");

	if( x != -1){
		Memoria->PonerDato(x,"Elemento", elemento);
		Memoria->PonerDato(x,"Sig", PtrElementos);
		Longitud = Longitud + 1;
		PtrElementos = x;
	}else{
        return ShowMessage("No hay espacio"); // llamar a exception existeespaciomemoria
	}
}

void CListaSMemoria::Inserta_ultimo( TDListMem elemento ){
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
        return ShowMessage("No existe espacio"); // llamar a exception existeespaciomemoria
	}
}

void CListaSMemoria::Suprime( int direccion ){
	if( Vacia() ) return ShowMessage("Lista vacia"); // llamar a exception listavacia

	int x;
	int anterior;
    if( direccion == PtrElementos ){ // es el primer nodo
		x = PtrElementos;
		PtrElementos = Memoria->ObtieneDato(PtrElementos, "Sig");
		// Liberar espacio de memoria x
        Memoria->DeleteEspacio( x );
	}else{
		anterior = Anterior( direccion );
		Memoria->PonerDato(anterior,"Sig", Siguiente(direccion));
		// Liberar espacio de memoria direccion
        Memoria->DeleteEspacio( direccion );
	}

    Longitud = Longitud - 1;
}

void CListaSMemoria::Modifica( int direccion, TDListMem elemento){
	if( Vacia() ) return ShowMessage("Lista vacia"); // llamar a exception listavacia
	Memoria->PonerDato(direccion,"Elemento", elemento);
}

void CListaSMemoria::MostrarLista( ){
	if( Vacia() ) return ShowMessage("Lista Vacia");

	TDListMem x = PtrElementos;

	while( x != -1 ){
		TDListMem Elemento = Memoria->ObtieneDato( x, "Elemento" );

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
