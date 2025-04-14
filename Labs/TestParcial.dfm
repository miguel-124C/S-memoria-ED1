object Form6: TForm6
  Left = 0
  Top = 0
  Caption = 'Form6'
  ClientHeight = 817
  ClientWidth = 1205
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object BtnCreateMemoria: TButton
    Left = 24
    Top = 40
    Width = 137
    Height = 33
    Caption = 'Crear Memoria'
    TabOrder = 0
    OnClick = BtnCreateMemoriaClick
  end
  object BtnPedirEspacio: TButton
    Left = 24
    Top = 88
    Width = 137
    Height = 33
    Caption = 'Pedir Espacio'
    TabOrder = 1
    OnClick = BtnPedirEspacioClick
  end
  object BtnLiberarEspacio: TButton
    Left = 24
    Top = 136
    Width = 137
    Height = 33
    Caption = 'Liberar Espacio'
    TabOrder = 2
    OnClick = BtnLiberarEspacioClick
  end
  object BtnCreatePoli: TButton
    Left = 24
    Top = 217
    Width = 137
    Height = 33
    Caption = 'Crear Polinomio'
    TabOrder = 3
    OnClick = BtnCreatePoliClick
  end
  object BtnPonerTermino: TButton
    Left = 24
    Top = 264
    Width = 137
    Height = 33
    Caption = 'Poner Termino'
    TabOrder = 4
    OnClick = BtnPonerTerminoClick
  end
  object BtnDerivada: TButton
    Left = 24
    Top = 312
    Width = 137
    Height = 33
    Caption = 'Derivada'
    TabOrder = 5
    OnClick = BtnDerivadaClick
  end
  object BtnGraficar: TButton
    Left = 24
    Top = 416
    Width = 137
    Height = 33
    Caption = 'Gr'#225'ficar Polinomio'
    TabOrder = 6
  end
  object BtnMostrarMemoria: TButton
    Left = 24
    Top = 512
    Width = 137
    Height = 33
    Caption = 'Mostrar Memoria'
    TabOrder = 7
    OnClick = BtnMostrarMemoriaClick
  end
  object BtnMostrarPoli: TButton
    Left = 24
    Top = 559
    Width = 137
    Height = 33
    Caption = 'Mostrar Polinomio'
    TabOrder = 8
    OnClick = BtnMostrarPoliClick
  end
  object ENombreEspacio: TEdit
    Left = 176
    Top = 88
    Width = 129
    Height = 33
    TabOrder = 9
  end
  object ENombreLiberarEspacio: TEdit
    Left = 176
    Top = 141
    Width = 129
    Height = 28
    TabOrder = 10
  end
  object ECreateNombrePoli: TEdit
    Left = 176
    Top = 217
    Width = 49
    Height = 33
    TabOrder = 11
  end
  object ENombrePoliPonerTerm: TEdit
    Left = 176
    Top = 264
    Width = 49
    Height = 33
    TabOrder = 12
  end
  object ECoef: TEdit
    Left = 240
    Top = 264
    Width = 49
    Height = 33
    TabOrder = 13
  end
  object EExp: TEdit
    Left = 304
    Top = 264
    Width = 49
    Height = 33
    TabOrder = 14
  end
  object ENombrePoliDerivada: TEdit
    Left = 176
    Top = 312
    Width = 49
    Height = 33
    TabOrder = 15
  end
  object Edit8: TEdit
    Left = 176
    Top = 416
    Width = 49
    Height = 33
    TabOrder = 16
  end
  object Edit9: TEdit
    Left = 240
    Top = 416
    Width = 49
    Height = 33
    TabOrder = 17
  end
  object Edit10: TEdit
    Left = 304
    Top = 416
    Width = 49
    Height = 33
    TabOrder = 18
  end
  object ENombrePoliMostrar: TEdit
    Left = 176
    Top = 559
    Width = 49
    Height = 33
    TabOrder = 19
  end
  object Edit1: TEdit
    Left = 368
    Top = 416
    Width = 49
    Height = 33
    TabOrder = 20
  end
end
