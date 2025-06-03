#ifndef ITDADiCola_H
#define ITDADiCola_H

#include <vcl.h>
#include "./Interfaces/ITDACola.h"

template <typename T>
class ITDADiCola : public ITDACola<T> {
private:
public:

	virtual T Ultimo() = 0;
	virtual void Poner_frente( T e ) = 0;
	virtual void Sacar_final( T e ) = 0;

	virtual ~ITDADiCola() {}  // Destructor virtual
};
#endif