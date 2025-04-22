//---------------------------------------------------------------------------

#pragma hdrstop
#include "ListPolinomio.h"
#include <vector>  // para std::vector
#include <cmath>   // para std::pow, std::fabs y demás funciones matemáticas
//---------------------------------------------------------------------------
#pragma package(smart_init)

bool ListPolinomio::ExistPoli( AnsiString Nombre ){
	bool exists = false;
	for(int i = 0; i < PosLibrListPoli; i++){
		if( ListPoli[i].Nombre == Nombre ){
			exists = true;
			break;
		}
	}

	return exists;
}

void ListPolinomio::AddPolinomio( AnsiString Nombre, ITDAPolinomio* P, bool IsLista ){
	if( ExistPoli(Nombre) ) return ShowMessage("Polinomio " + Nombre + " ya existe");
	if(PosLibrListPoli == Maximo) return ShowMessage("Lista de polinomios llena");

	ListPoli[PosLibrListPoli].Nombre = Nombre;
	ListPoli[PosLibrListPoli].P = P;
	ListPoli[PosLibrListPoli].IsLista = IsLista;

	PosLibrListPoli++;
}

ITDAPolinomio* ListPolinomio::GetPolinomio( AnsiString Nombre ){
	ITDAPolinomio* P = nullptr;
	for(int i = 0; i < PosLibrListPoli; i++){
		if( ListPoli[i].Nombre == Nombre ){
			P = ListPoli[i].P;
			break;
		}
	}

	return P;
}

bool ListPolinomio::IsLista( AnsiString Nombre ){
	bool islista = false;
	for(int i = 0; i < PosLibrListPoli; i++){
		if( ListPoli[i].Nombre == Nombre ){
			islista = ListPoli[i].IsLista;
			break;
		}
	}

	return islista;
}

void ListPolinomio::GraficarPolinomios( float x1, float x2, float s ){
	if( PosLibrListPoli == 0 )
		return ShowMessage("No hay polinomios para graficar");

	if( x1 > x2 )
		return ShowMessage("El límite inferior no puede ser mayor que el superior");
	if( x1 == x2 )
		return ShowMessage("Los límites no pueden ser iguales");

	// Dibuja el plano una sola vez
	plano->GraficaPlano( x1, x2 );

	const int N = PosLibrListPoli;
	std::vector<float> prevX(N), prevY(N), currY(N);
	const float epsilon = 1e-3f;  // tolerancia para comparar floats
	AnsiString intersecciones = "";

	bool firstPoint = true;
	// Recorremos el eje X
	for( float x = x1; x <= x2; x += s ){
		// 1) Calculamos todas las Ys en este x
		for( int j = 0; j < N; j++ ){
			ITDAPolinomio* P = ListPoli[j].P;
			float y = 0;
			for( int i = 1; i <= P->NumeroTerminos(); i++ ){
				int exp  = P->Exponente(i);
				int coef = P->Coeficiente(exp);
				y += coef * std::pow( x, exp );
			}
			currY[j] = y;
		}

		// 2) Dibujamos línea desde el punto anterior hasta el actual
		if( !firstPoint ){
			for( int j = 0; j < N; j++ ){
				// Opcional: cambiar color según j
				// plano->SetColor( Colores[j % ColoresCount] );
				plano->GraficaLinea( prevX[j], prevY[j], x, currY[j] );
			}
		} else {
			firstPoint = false;
		}

		// 3) Detectamos intersecciones: si currY[i] == currY[j]
		for( int i = 0; i < N; i++ ){
			for( int j = i+1; j < N; j++ ){
				if( std::fabs(currY[i] - currY[j]) < epsilon ){
					intersecciones +=
					  Format("Intersección entre '%s' y '%s' en x=%.3f, y≈%.3f\r\n",
							 ARRAYOFCONST((
							   ListPoli[i].Nombre,
							   ListPoli[j].Nombre,
							   x,
							   currY[i]
							 )));
				}
			}
		}

		// 4) Guardamos este punto como “anterior” para la siguiente iteración
		for( int j = 0; j < N; j++ ){
			prevX[j] = x;
			prevY[j] = currY[j];
		}
	}

	// 5) Mostramos todas las intersecciones (si hubo)
	if( !intersecciones.IsEmpty() )
		ShowMessage(intersecciones);
	else
		ShowMessage("No se encontraron intersecciones discretas.");
}
