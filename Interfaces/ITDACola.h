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

	// COORDS vector
	int X1 = 50;
	int Y1 = 650;

    int WidthField  = 100;
	int HeightField = 50;


	void setCanvas( TCanvas* canvas ){
		this->canvas = canvas;
	}

	void concatenar(ITDACola &cola1, ITDACola &cola2, ITDACola &cola3) {
		ITDACola colaAux;
		int e;

		// Copiar elementos de cola1 a colaAux
		while (!cola1.Vacia()) {
			cola1.Sacar();
			colaAux.Poner(e);
		}

		// Pasar de colaAux a cola3 y restaurar cola1
		while (!colaAux.Vacia()) {
			colaAux.Sacar();
			cola3.Poner(e);
			cola1.Poner(e);
		}

		// Copiar elementos de cola2 a colaAux
		while (!cola2.Vacia()) {
			cola2.Sacar();
			colaAux.Poner(e);
		}

		// Pasar de colaAux a cola3 y restaurar cola2
		while (!colaAux.Vacia()) {
			colaAux.Sacar();
			cola3.Poner(e);
			cola2.Poner(e);
		}
	}


	virtual ~ITDACola() {}  // Destructor virtual
};
#endif