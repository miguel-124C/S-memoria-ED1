#ifndef ISMemoria_H
#define ISMemoria_H

#include <vcl.h>

template <typename G>
struct NodoM {
	int dir;
	G dato;
	AnsiString id;
	int link;
};

template <typename T>
class ISMemoria {
private:
	static const int MAX = 20;
	static const int NULO = -1;

	int libre;
public:
	// Propiedades
	NodoM<T> MEM[MAX];

	TCanvas* canvas;

	//RangoPaginado
	int pagStart = 1;
    int pagEnd   = 20;

	// Getters y setters
	int getLibre() const { return libre; }
	void setLibre(int value) { libre = value; }

	int Max() const { return MAX; }
    int Nulo() const { return NULO; }


	// Métodos
    virtual int NewEspacio(AnsiString cadena) = 0;
    virtual void DeleteEspacio(int dir) = 0;
    virtual void PonerDato(int dir, AnsiString cadena_id, T valor) = 0;
	virtual T ObtieneDato(int dir, AnsiString cadena_id) = 0;
    virtual int EspacioDisponible() = 0;
    virtual int EspacioOcupado() = 0;
	virtual bool DirLibre(int dir) = 0;

	virtual void MostrarMemoria( ) = 0;

	void setCanvas( TCanvas* canvas ){
        this->canvas = canvas;
	}

	// "nombre,correo,contra" => 3 ids
	int NumeroIds( AnsiString cadena ){
		int cantidad = 1;
		for (int i = 1; i <= cadena.Length(); i++) {
			char c = cadena[i];
			if( c == ',' ){
                cantidad++;
			}
		}

		return cantidad;
	}

	// "nombre,correo,contra", 1 => "nombre"
	// "nombre,correo,contra", 2 => "correo"
    // x => x
	AnsiString ObtenerId( AnsiString cadena, int index ){
		AnsiString id = "";
		short cantidadComas = 0;
		for (int i = 1; i <= cadena.Length(); i++) {
			if( cadena[i] == ',' ){
				cantidadComas++;
			}

			if( index - 1 == cantidadComas && cadena[i] != ',' ){
				id += cadena[i];
			}
		}

        return id;
	}

	virtual ~ISMemoria() {}  // Destructor virtual
};

#endif
