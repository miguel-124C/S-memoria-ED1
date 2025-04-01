#ifndef ITDALista_H
#define ITDALista_H

#include <vcl.h>

template <typename T, typename D>
class ITDALista {
private:
public:
	// Propiedades

	TCanvas* canvas;

	int Longitud;

	// Métodos
	virtual void Crear() = 0;
	virtual D Fin()= 0;
	virtual D Primero()= 0;
	virtual D Siguiente( D direccion ) = 0;
	virtual D Anterior( D direccion ) = 0;
	virtual bool Vacia() = 0;
	virtual T Recupera( D direccion ) = 0;
	virtual int GetLongitud () = 0;
	virtual void Inserta( D direccion, T elemento ) = 0;
	virtual void Inserta_primero( T elemento ) = 0;
	virtual void Inserta_ultimo( T elemento ) = 0;
	virtual void Suprime( D direccion ) = 0;
	virtual void Modifica( D direccion, T elemento) = 0;
	virtual void MostrarLista( ) = 0;

	void setCanvas( TCanvas* canvas ){
        this->canvas = canvas;
	}

    // COORDS vector
	int X1 = 50;
	int Y1 = 650;

    int WidthField  = 100;
	int HeightField = 50;

	virtual ~ITDALista() {}  // Destructor virtual
};

#endif
