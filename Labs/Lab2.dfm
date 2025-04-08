object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 817
  ClientWidth = 1205
  Color = clBtnFace
  CustomTitleBar.CaptionAlignment = taCenter
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  PixelsPerInch = 96
  TextHeight = 15
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
    Top = 272
    Width = 97
    Height = 41
    Caption = 'Crear Polinomio'
    TabOrder = 8
    OnClick = BtnCreatePolinomioClick
  end
  object BtnPonerTermino: TButton
    Left = 8
    Top = 319
    Width = 97
    Height = 41
    Caption = 'Poner Termino'
    TabOrder = 9
    OnClick = BtnPonerTerminoClick
  end
  object BtnMostrarPolinomio: TButton
    Left = 111
    Top = 272
    Width = 97
    Height = 41
    Caption = 'Mostrar'
    TabOrder = 10
    OnClick = BtnMostrarPolinomioClick
  end
  object BtnDerivarPolinomio: TButton
    Left = 8
    Top = 366
    Width = 97
    Height = 41
    Caption = 'Derivar'
    TabOrder = 11
    OnClick = BtnDerivarPolinomioClick
  end
  object ECoef: TEdit
    Left = 111
    Top = 319
    Width = 98
    Height = 23
    HelpType = htKeyword
    TabOrder = 12
  end
  object EExp: TEdit
    Left = 215
    Top = 319
    Width = 98
    Height = 23
    TabOrder = 13
  end
end
