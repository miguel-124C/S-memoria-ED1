object Form8: TForm8
  Left = 0
  Top = 0
  Caption = 'Cola'
  ClientHeight = 817
  ClientWidth = 1205
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object LTitleLista: TLabel
    Left = 8
    Top = 216
    Width = 159
    Height = 32
    Caption = 'Cola no creada'
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
  object ENombreEspacio: TEdit
    Left = 111
    Top = 64
    Width = 98
    Height = 23
    TabOrder = 3
  end
  object ENombreLiberarEspacio: TEdit
    Left = 111
    Top = 111
    Width = 98
    Height = 23
    TabOrder = 4
  end
  object BtnMostrarMemoria: TButton
    Left = 8
    Top = 149
    Width = 97
    Height = 41
    Caption = 'Mostrar Memoria'
    TabOrder = 5
    OnClick = BtnMostrarMemoriaClick
  end
  object EInicioMemoria: TEdit
    Left = 111
    Top = 158
    Width = 98
    Height = 23
    TabOrder = 6
    Text = '1'
  end
  object EFinMemoria: TEdit
    Left = 215
    Top = 158
    Width = 98
    Height = 23
    TabOrder = 7
    Text = '20'
  end
  object BtnPoner: TButton
    Left = 8
    Top = 493
    Width = 97
    Height = 41
    Caption = 'Poner'
    TabOrder = 8
    OnClick = BtnPonerClick
  end
  object BtnSacar: TButton
    Left = 8
    Top = 540
    Width = 97
    Height = 41
    Caption = 'Sacar'
    TabOrder = 9
    OnClick = BtnSacarClick
  end
  object BtnCrearColaVector: TButton
    Left = 8
    Top = 269
    Width = 97
    Height = 41
    Caption = 'Cola con vector'
    TabOrder = 10
    OnClick = BtnCrearColaVectorClick
  end
  object EPoner: TEdit
    Left = 111
    Top = 493
    Width = 98
    Height = 23
    TabOrder = 11
  end
  object BtnMostrarCola: TButton
    Left = 8
    Top = 587
    Width = 97
    Height = 41
    Caption = 'MostrarCola'
    TabOrder = 12
    OnClick = BtnMostrarColaClick
  end
  object BtnCrearVectorMem: TButton
    Left = 111
    Top = 269
    Width = 114
    Height = 41
    Caption = 'Cola con memoria'
    TabOrder = 13
    OnClick = BtnCrearVectorMemClick
  end
end
