//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Forms\FSMemoria.cpp", Form1);
USEFORM("Forms\FPolinomios.cpp", Form2);
USEFORM("Forms\FListas.cpp", Form4);
USEFORM("Forms\FPunteros.cpp", Form3);
USEFORM("Labs\Lab1.cpp", Form5);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;

        UnicodeString seleccion;
		if (
			InputQuery("Seleccionar Formulario",
			"Ingresa el número del formulario:\n1: SMemoria\n2: Polinomios\n3: Listas\n4: Conjuntos",
			seleccion
			)
		)
		{
			int opcion = seleccion.ToIntDef(0); // Convierte el texto a número, si falla devuelve 0

			switch (opcion)
			{
				case 1:
					Application->CreateForm(__classid(TForm1), &Form1);
					break;
				case 2:
					Application->CreateForm(__classid(TForm2), &Form2);
					break;
				case 3:
					Application->CreateForm(__classid(TForm4), &Form4);
					break;
				case 4:
					Application->CreateForm(__classid(TForm3), &Form3);
					break;
				default: ShowMessage("Opción no válida. Cerrando programa."); return 0;
			}

			Application->Run();
		}
		else
		{
			ShowMessage("No se seleccionó ningún formulario. Cerrando programa.");
		}
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
