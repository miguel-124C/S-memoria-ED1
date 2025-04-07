#ifndef IListaMethod_H
#define IListaMethod_H

template <typename T, typename D>
class IListaMethod {
private:
public:
	// Métodos

	virtual D Fin() = 0;
	virtual D Primero() = 0;
	virtual D Siguiente( D direccion ) = 0;
	virtual D Anterior( D direccion ) = 0;
	virtual T Recupera( D direccion ) = 0;
	virtual void Inserta( D direccion, T elemento ) = 0;
	virtual void Suprime( D direccion ) = 0;
	virtual void Modifica( D direccion, T elemento) = 0;

	virtual ~IListaMethod() {}  // Destructor virtual
};

#endif
