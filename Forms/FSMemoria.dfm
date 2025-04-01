object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'SMemoria'
  ClientHeight = 817
  ClientWidth = 1205
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object LLibre: TLabel
    Left = 536
    Top = 768
    Width = 57
    Height = 32
    Caption = 'Libre'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object LDisponible: TLabel
    Left = 744
    Top = 768
    Width = 216
    Height = 32
    Caption = 'Espacio Disponible'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object BtnCreateMemoria: TButton
    Left = 8
    Top = 8
    Width = 97
    Height = 41
    Caption = 'Crear Memoria'
    TabOrder = 0
    OnClick = BtnCreateMemoriaClick
  end
  object BtnPedirEspacio: TButton
    Left = 8
    Top = 55
    Width = 97
    Height = 41
    Caption = 'Pedir Espacio'
    TabOrder = 1
    OnClick = BtnPedirEspacioClick
  end
  object BtnLiberarEspacio: TButton
    Left = 8
    Top = 102
    Width = 97
    Height = 41
    Caption = 'Liberar Espacio'
    TabOrder = 2
    OnClick = BtnLiberarEspacioClick
  end
  object BtnMostrarMemoria: TButton
    Left = 8
    Top = 149
    Width = 97
    Height = 41
    Caption = 'Mostrar Memoria'
    TabOrder = 3
    OnClick = BtnMostrarMemoriaClick
  end
  object BtnPonerDato: TButton
    Left = 8
    Top = 196
    Width = 97
    Height = 41
    Caption = 'Poner Dato'
    TabOrder = 4
    OnClick = BtnPonerDatoClick
  end
  object ENombreEspacio: TEdit
    Left = 111
    Top = 55
    Width = 98
    Height = 23
    TabOrder = 5
  end
  object ENombreLiberarEspacio: TEdit
    Left = 111
    Top = 102
    Width = 98
    Height = 23
    TabOrder = 6
  end
  object EInicioMemoria: TEdit
    Left = 111
    Top = 149
    Width = 98
    Height = 23
    TabOrder = 7
    Text = '1'
  end
  object EFinMemoria: TEdit
    Left = 215
    Top = 149
    Width = 98
    Height = 23
    TabOrder = 8
    Text = '20'
  end
  object EDireccionPonerDato: TEdit
    Left = 111
    Top = 196
    Width = 98
    Height = 23
    TabOrder = 9
  end
  object EIdPonerDato: TEdit
    Left = 215
    Top = 196
    Width = 98
    Height = 23
    TabOrder = 10
  end
  object EValorPonerDato: TEdit
    Left = 319
    Top = 196
    Width = 98
    Height = 23
    TabOrder = 11
  end
  object BtnCrearLista: TButton
    Left = 8
    Top = 256
    Width = 97
    Height = 41
    Caption = 'Crear Lista'
    TabOrder = 12
    OnClick = BtnCrearListaClick
  end
  object BtnInsertInicio: TButton
    Left = 8
    Top = 303
    Width = 97
    Height = 41
    Caption = 'Insertar Inicio'
    TabOrder = 13
    OnClick = BtnInsertInicioClick
  end
  object BtnInsertFin: TButton
    Left = 8
    Top = 350
    Width = 97
    Height = 41
    Caption = 'Insertar Final'
    TabOrder = 14
    OnClick = BtnInsertFinClick
  end
  object EListaInsertInicio: TEdit
    Left = 111
    Top = 303
    Width = 98
    Height = 23
    TabOrder = 15
  end
  object EListaInsertFin: TEdit
    Left = 111
    Top = 350
    Width = 98
    Height = 23
    TabOrder = 16
  end
  object BtnCreatePolinomio: TButton
    Left = 8
    Top = 416
    Width = 97
    Height = 41
    Caption = 'Crear Polinomio'
    TabOrder = 17
    OnClick = BtnCreatePolinomioClick
  end
  object BtnPonerTermino: TButton
    Left = 8
    Top = 463
    Width = 97
    Height = 41
    Caption = 'Poner Termino'
    TabOrder = 18
    OnClick = BtnPonerTerminoClick
  end
  object BtnMostrarPolinomio: TButton
    Left = 111
    Top = 416
    Width = 97
    Height = 41
    Caption = 'Mostrar Polinomio'
    TabOrder = 19
    OnClick = BtnMostrarPolinomioClick
  end
  object BtnDerivarPolinomio: TButton
    Left = 8
    Top = 510
    Width = 97
    Height = 41
    Caption = 'Derivar'
    TabOrder = 20
  end
  object ECoef: TEdit
    Left = 111
    Top = 463
    Width = 98
    Height = 23
    HelpType = htKeyword
    TabOrder = 21
  end
  object EExp: TEdit
    Left = 215
    Top = 463
    Width = 98
    Height = 23
    TabOrder = 22
  end
  object BtnMostrarListaMen: TButton
    Left = 111
    Top = 256
    Width = 97
    Height = 41
    Caption = 'Mostrar Lista'
    TabOrder = 23
    OnClick = BtnMostrarListaMenClick
  end
  object BtnEvaluaPolinomio: TButton
    Left = 8
    Top = 557
    Width = 97
    Height = 36
    Caption = 'Evalua'
    TabOrder = 24
    OnClick = BtnEvaluaPolinomioClick
  end
  object EIncognita: TEdit
    Left = 111
    Top = 563
    Width = 97
    Height = 23
    TabOrder = 25
  end
end
