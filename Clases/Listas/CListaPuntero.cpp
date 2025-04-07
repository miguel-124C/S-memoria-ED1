//---------------------------------------------------------------------------

#pragma hdrstop

#include "CListaPuntero.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
CListaPuntero::CListaPuntero( TCanvas* canvas ){
	setCanvas(canvas);
}

void CListaPuntero::Crear(){
	Longitud = 0;
    PtrElementos = nullptr;
}

NodoPuntero* CListaPuntero::Fin(){
	if( Vacia() ) return nullptr; // llamar a exception listavacia;

	NodoPuntero* x = PtrElementos;
	NodoPuntero* PtrFin;

	while( x != nullptr ){
		 PtrFin = x;
		 x = x->Sig;
	}

	return PtrFin;
}

NodoPuntero* CListaPuntero::Primero(){
	if( !Vacia() ) return PtrElementos; // Apunta primer elemento

	return nullptr; // Llamar exception ListaVacia
}

NodoPuntero* CListaPuntero::Siguiente( NodoPuntero* direccion ){
	if( Vacia() ) return nullptr; // Llamar exception ListaVacia
	if( direccion == Fin() ) return nullptr; // Llamar exception DireccionErr

	return direccion->Sig;
}

NodoPuntero* CListaPuntero::Anterior( NodoPuntero* direccion ){
	if( Vacia() ) return nullptr; // Llamar exception ListaVacia
	if( direccion == Primero() ) return nullptr; // Llamar exception DireccionPrimeraErr

	NodoPuntero* x = PtrElementos;
	NodoPuntero* anterior = nullptr;

	while( x != nullptr ){
		if( x == direccion ) return anterior;

		anterior = x;
		x = x->Sig;
	}

//	return direccion--;
}

TDElem CListaPuntero::Recupera( NodoPuntero* direccion ){
	if( Vacia() ) return 0; // Llamar exception ListaVacia

    return direccion->Elemento;
}

void CListaPuntero::Inserta( NodoPuntero* direccion, TDElem elemento ){
	// X tendria direccion de memoria si existe espacio
	NodoPuntero* x = new NodoPuntero;
	if( x != nullptr ){
		x->Elemento = elemento; // Memoria->PonerDato(x, "Elemento", elemento);
		x->Sig = nullptr; // Memoria->PonerDato(x, "Sig", -1);

		if( Vacia() ){
			PtrElementos = x;
			Longitud = 1;
			return;
		}

		if( direccion == Primero() ){
			x->Sig = direccion;
			PtrElementos = x;
		}else{
			NodoPuntero* anterior = Anterior( direccion );
			anterior->Sig = x; // Memoria->PonerDato(anterior, "Sig", x);
			x->Sig = direccion; // Memoria->PonerDato(x, "Sig", direccion);
		}

		Longitud = Longitud + 1;
	}

    return; // llamar a exception existeespaciomemoria
}

void CListaPuntero::Inserta_primero( TDElem elemento ){
	// x tendria direcion de memoria si existe espacio
	NodoPuntero* x = new NodoPuntero;//	int x = Memoria->NewEspacio("Elemento,Sig");

	if( x != nullptr){
		x->Elemento = elemento;// Memoria->PonerDato(x,"Elemento", elemento);
		x->Sig = PtrElementos;// Memoria->PonerDato(x,"Sig", PtrElementos);
		Longitud = Longitud + 1;
		PtrElementos = x;
	}else{
		return; // llamar a exception existeespaciomemoria
	}
}

void CListaPuntero::Inserta_ultimo( TDElem elemento ){
	// x tendria direcion de memoria si existe espacio
	NodoPuntero* x = new NodoPuntero;//	int x = Memoria->NewEspacio("Elemento,Sig");

	if( x != nullptr){
		x->Elemento = elemento;// Memoria->PonerDato(x,"Elemento", elemento);
		x->Sig = nullptr;//	Memoria->PonerDato(x,"Sig", -1);
		if (Longitud != 0){
            Fin()->Sig = x;// Memoria->PonerDato(Fin(),"Sig", x);
		}else{
            PtrElementos = x;
        }

		Longitud = Longitud + 1;
	}else{
        return; // llamar a exception existeespaciomemoria
	}
}

void CListaPuntero::Suprime( NodoPuntero* direccion ){
	if( Vacia() ) return; // llamar a exception listavacia

	NodoPuntero* x;
	NodoPuntero* anterior;
    if( direccion == PtrElementos ){ // es el primer nodo
		x = PtrElementos;
		PtrElementos = PtrElementos->Sig; // Memoria->ObtieneDato(PtrElementos, "Sig");
		// Liberar espacio de memoria x
	}else{
		anterior = Anterior( direccion );
		anterior->Sig = Siguiente(direccion);//	Memoria->PonerDato(anterior,"Sig", Siguiente(direccion));
        // Liberar espacio de memoria direccion
	}

    Longitud = Longitud - 1;
}

void CListaPuntero::Modifica( NodoPuntero* direccion, TDElem elemento){
	if( Vacia() ) return; // llamar a exception listavacia
	direccion->Elemento = elemento;// Memoria->PonerDato(direccion,"Elemento", elemento);
}

void CListaPuntero::MostrarLista( ){
	if( Vacia() ) return ShowMessage("Lista Vacia");

	NodoPuntero* x = PtrElementos;

	while( x != nullptr ){
		TDElem Elemento = x->Elemento;

        int x2 = X1 + WidthField;
		int y2 = Y1 + HeightField;
		canvas->Brush->Color = (TColor)0xffffff;
		canvas->Rectangle(X1, Y1, x2, y2);

		canvas->Font->Size = 16;
		canvas->TextOut( X1 + 5, Y1 + 5, Elemento );

		X1 += WidthField;

		x = x->Sig;
	}

	X1 = 50;
}
