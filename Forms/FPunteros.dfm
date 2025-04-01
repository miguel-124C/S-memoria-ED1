object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 817
  ClientWidth = 1205
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object BtnCrearLista: TButton
    Left = 8
    Top = 24
    Width = 97
    Height = 41
    Caption = 'Crear Lista'
    TabOrder = 0
    OnClick = BtnCrearListaClick
  end
  object BtnInsertInicio: TButton
    Left = 8
    Top = 71
    Width = 97
    Height = 41
    Caption = 'Insertar Inicio'
    TabOrder = 1
    OnClick = BtnInsertInicioClick
  end
  object BtnInsertFin: TButton
    Left = 8
    Top = 118
    Width = 97
    Height = 41
    Caption = 'Insertar Final'
    TabOrder = 2
    OnClick = BtnInsertFinClick
  end
  object EListaInsertInicio: TEdit
    Left = 111
    Top = 71
    Width = 98
    Height = 23
    TabOrder = 3
  end
  object EListaInsertFin: TEdit
    Left = 111
    Top = 118
    Width = 98
    Height = 23
    TabOrder = 4
  end
  object BtnCreatePolinomio: TButton
    Left = 8
    Top = 184
    Width = 97
    Height = 41
    Caption = 'Crear Polinomio'
    TabOrder = 5
    OnClick = BtnCreatePolinomioClick
  end
  object BtnPonerTermino: TButton
    Left = 8
    Top = 231
    Width = 97
    Height = 41
    Caption = 'Poner Termino'
    TabOrder = 6
    OnClick = BtnPonerTerminoClick
  end
  object BtnMostrarPolinomio: TButton
    Left = 111
    Top = 184
    Width = 97
    Height = 41
    Caption = 'Mostrar Polinomio'
    TabOrder = 7
    OnClick = BtnMostrarPolinomioClick
  end
  object BtnDerivarPolinomio: TButton
    Left = 8
    Top = 278
    Width = 97
    Height = 41
    Caption = 'Derivar'
    TabOrder = 8
  end
  object ECoef: TEdit
    Left = 111
    Top = 231
    Width = 98
    Height = 23
    HelpType = htKeyword
    TabOrder = 9
  end
  object EExp: TEdit
    Left = 215
    Top = 231
    Width = 98
    Height = 23
    TabOrder = 10
  end
  object BtnMostrarListaMen: TButton
    Left = 111
    Top = 24
    Width = 97
    Height = 41
    Caption = 'Mostrar Lista'
    TabOrder = 11
    OnClick = BtnMostrarListaMenClick
  end
  object BtnEvaluaPolinomio: TButton
    Left = 8
    Top = 325
    Width = 97
    Height = 36
    Caption = 'Evalua'
    TabOrder = 12
    OnClick = BtnEvaluaPolinomioClick
  end
  object EIncognita: TEdit
    Left = 111
    Top = 331
    Width = 97
    Height = 23
    TabOrder = 13
  end
end
