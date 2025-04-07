#ifndef ITDALista_H
#define ITDALista_H

#include <vcl.h>

template <typename T>
class ITDALista {
private:
public:
	// Propiedades

	TCanvas* canvas;

	int Longitud;

	// Métodos
	virtual void Crear() = 0;
    virtual void Inserta_primero( T elemento ) = 0;
	virtual void Inserta_ultimo( T elemento ) = 0;
	virtual void MostrarLista( ) = 0;

	void setCanvas( TCanvas* canvas ){
        this->canvas = canvas;
	}

	int GetLongitud (){
		return Longitud;
	}

	bool Vacia(){
		return Longitud == 0;
	}

    // COORDS vector
	int X1 = 50;
	int Y1 = 650;

    int WidthField  = 100;
	int HeightField = 50;

	virtual ~ITDALista() {}  // Destructor virtual
};

#endif
