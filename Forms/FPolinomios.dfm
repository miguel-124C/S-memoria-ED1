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
  object LTitlePolinomio: TLabel
    Left = 8
    Top = 432
    Width = 221
    Height = 32
    Caption = 'Polinomio no creado'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Segoe UI'
    Font.Style = []
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
  object ENombreEspacio: TEdit
    Left = 111
    Top = 55
    Width = 98
    Height = 23
    TabOrder = 4
  end
  object ENombreLiberarEspacio: TEdit
    Left = 111
    Top = 102
    Width = 98
    Height = 23
    TabOrder = 5
  end
  object EInicioMemoria: TEdit
    Left = 111
    Top = 149
    Width = 98
    Height = 23
    TabOrder = 6
    Text = '1'
  end
  object EFinMemoria: TEdit
    Left = 215
    Top = 149
    Width = 98
    Height = 23
    TabOrder = 7
    Text = '20'
  end
  object BtnCreatePolinomio: TButton
    Left = 8
    Top = 480
    Width = 97
    Height = 41
    Caption = 'Crear Polinomio'
    TabOrder = 8
    OnClick = BtnCreatePolinomioClick
  end
  object BtnPonerTermino: TButton
    Left = 8
    Top = 527
    Width = 97
    Height = 41
    Caption = 'Poner Termino'
    TabOrder = 9
    OnClick = BtnPonerTerminoClick
  end
  object BtnMostrarPolinomio: TButton
    Left = 111
    Top = 480
    Width = 97
    Height = 41
    Caption = 'Mostrar'
    TabOrder = 10
    OnClick = BtnMostrarPolinomioClick
  end
  object BtnDerivarPolinomio: TButton
    Left = 8
    Top = 574
    Width = 97
    Height = 41
    Caption = 'Derivar'
    TabOrder = 11
  end
  object ECoef: TEdit
    Left = 111
    Top = 527
    Width = 98
    Height = 23
    HelpType = htKeyword
    TabOrder = 12
  end
  object EExp: TEdit
    Left = 215
    Top = 527
    Width = 98
    Height = 23
    TabOrder = 13
  end
  object BtnEvaluaPolinomio: TButton
    Left = 8
    Top = 621
    Width = 97
    Height = 36
    Caption = 'Evalua'
    TabOrder = 14
    OnClick = BtnEvaluaPolinomioClick
  end
  object EIncognita: TEdit
    Left = 111
    Top = 627
    Width = 97
    Height = 23
    TabOrder = 15
  end
  object BtnChangeType: TButton
    Left = 319
    Top = 425
    Width = 113
    Height = 39
    Caption = 'Cambiar Polinomio'
    TabOrder = 16
    Visible = False
    OnClick = BtnChangeTypeClick
  end
  object BtnCreateLista: TButton
    Left = 8
    Top = 248
    Width = 97
    Height = 33
    Caption = 'Crear Lista'
    TabOrder = 17
  end
  object BtnInsertInicio: TButton
    Left = 8
    Top = 287
    Width = 97
    Height = 33
    Caption = 'Insertar Inicio'
    TabOrder = 18
  end
  object EInsertInicio: TEdit
    Left = 111
    Top = 292
    Width = 98
    Height = 23
    TabOrder = 19
  end
  object EInsertFin: TEdit
    Left = 111
    Top = 331
    Width = 98
    Height = 23
    TabOrder = 20
  end
  object BtnInsertFinal: TButton
    Left = 8
    Top = 326
    Width = 97
    Height = 33
    Caption = 'Insertar Final'
    TabOrder = 21
  end
  object BtnMostrarLista: TButton
    Left = 8
    Top = 365
    Width = 97
    Height = 33
    Caption = 'Mostrar Lista'
    TabOrder = 22
  end
end
