//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Forms\FSMemoria.cpp", Form1);
USEFORM("Labs\TestParcial.cpp", Form6);
USEFORM("Labs\Lab2.cpp", Form3);
USEFORM("Labs\Lab1.cpp", Form5);
USEFORM("Forms\FPolinomios.cpp", Form2);
USEFORM("Forms\FListas.cpp", Form4);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;

//		UnicodeString seleccion;
//		if (
//			InputQuery("Seleccionar Formulario",
//			"Ingresa el n�mero del formulario:\n1: SMemoria\n2: Polinomios\n3: Listas\n4: Conjuntos",
//			seleccion
//			)
//		)
//		{
//			int opcion = seleccion.ToIntDef(0); // Convierte el texto a n�mero, si falla devuelve 0
//
//			switch (opcion)
//			{
//				case 1:
//					Application->CreateForm(__classid(TForm1), &Form1);
//		Application->CreateForm(__classid(TForm2), &Form2);
//		Application->CreateForm(__classid(TForm4), &Form4);
//		Application->CreateForm(__classid(TForm3), &Form3);
//		break;
//				default: ShowMessage("Opci�n no v�lida. Cerrando programa."); return 0;
//			}
//
//			Application->Run();
//		}
//		else
//		{
//			ShowMessage("No se seleccion� ning�n formulario. Cerrando programa.");
//		}

//		Application->CreateForm(__classid(TForm3), &Form3);
		Application->CreateForm(__classid(TForm6), &Form6);
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