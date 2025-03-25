#ifndef ITDALista_H
#define ITDALista_H

#include <vcl.h>

typedef int Direccion;

template <typename T>
class ITDALista {
private:
public:
	// Propiedades

	TCanvas* canvas;

	int Longitud;

	// Métodos
	virtual void Crear() = 0;
	virtual Direccion Fin()= 0;
	virtual Direccion Primero()= 0;
	virtual Direccion Siguiente( Direccion direccion ) = 0;
	virtual Direccion Anterior( Direccion direccion ) = 0;
	virtual bool Vacia() = 0;
	virtual T Recupera( Direccion direccion ) = 0;
	virtual int GetLongitud () = 0;
	virtual void Inserta( Direccion direccion, T elemento ) = 0;
	virtual void Inserta_primero( T elemento ) = 0;
	virtual void Inserta_ultimo( T elemento ) = 0;
	virtual void Suprime( Direccion direccion ) = 0;
	virtual void Modifica( Direccion direccion, T elemento) = 0;
	virtual void MostrarLista( ) = 0;

	void setCanvas( TCanvas* canvas ){
        this->canvas = canvas;
	}

	virtual ~ITDALista() {}  // Destructor virtual
};

#endif
