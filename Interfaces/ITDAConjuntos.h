#ifndef ITDAConjunto_H
#define ITDAConjunto_H

#include <vcl.h>


template< typename T >
class ITDAConjunto {
private:
public:
	// Propiedades
	int Cantidad;

	// Métodos
	virtual void Crear() = 0;
	virtual bool Pertenece( T elemento ) = 0;
	virtual void Inserta( T elemento ) = 0;
	virtual int Cardinal() = 0;
	virtual int Ordinal( T elemento ) = 0;
	virtual void Suprime( T elemento ) = 0;
    virtual T Muestrea() = 0;

	virtual void MostrarConjunto( ) = 0;

	bool Vacio(){
		return Cantidad == 0;
	}

	virtual ~ITDAConjunto() {}  // Destructor virtual
};

#endif
