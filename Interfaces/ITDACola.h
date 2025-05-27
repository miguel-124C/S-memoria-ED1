#ifndef ITDACola_H
#define ITDACola_H

#include <vcl.h>

template <typename T>
class ITDACola {
private:
public:
	// Propiedades

	TCanvas* canvas;

	// Métodos
	virtual void Crear() = 0;
	virtual T Primero( ) = 0;
	virtual void Poner( T elemento ) = 0;
	virtual void Sacar( T elemento ) = 0;
	virtual bool Vacia() = 0;
	virtual void MostrarCola( ) = 0;

	void setCanvas( TCanvas* canvas ){
		this->canvas = canvas;
	}

	virtual ~ITDACola() {}  // Destructor virtual
};
#endif