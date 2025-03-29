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

	// M�todos
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

	virtual ~ITDALista() {}  // Destructor virtual
};

#endif
