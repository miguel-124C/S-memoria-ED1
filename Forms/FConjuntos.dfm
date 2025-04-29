object Form7: TForm7
  Left = 0
  Top = 0
  Caption = 'Form7'
  ClientHeight = 817
  ClientWidth = 1205
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object LTitleConj: TLabel
    Left = 8
    Top = 298
    Width = 213
    Height = 32
    Caption = 'Conjunto no creado'
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
  object ENombreEspacio: TEdit
    Left = 111
    Top = 55
    Width = 98
    Height = 23
    TabOrder = 2
  end
  object BtnMostrarMemoria: TButton
    Left = 8
    Top = 102
    Width = 97
    Height = 41
    Caption = 'Mostrar Memoria'
    TabOrder = 3
    OnClick = BtnMostrarMemoriaClick
  end
  object EInicioMemoria: TEdit
    Left = 111
    Top = 102
    Width = 98
    Height = 23
    TabOrder = 4
    Text = '1'
  end
  object EFinMemoria: TEdit
    Left = 215
    Top = 102
    Width = 98
    Height = 23
    TabOrder = 5
    Text = '20'
  end
  object BtnCreaConjA: TButton
    Left = 8
    Top = 336
    Width = 97
    Height = 41
    Caption = 'Crear Conj A'
    TabOrder = 6
    OnClick = BtnCreaConjAClick
  end
  object BtnCreaConjB: TButton
    Left = 8
    Top = 383
    Width = 97
    Height = 41
    Caption = 'Crear Conj B'
    TabOrder = 7
    OnClick = BtnCreaConjBClick
  end
  object BtnCreaConjC: TButton
    Left = 8
    Top = 430
    Width = 97
    Height = 41
    Caption = 'Crear Conj C'
    TabOrder = 8
    OnClick = BtnCreaConjCClick
  end
  object BtnInsertElem: TButton
    Left = 8
    Top = 477
    Width = 97
    Height = 41
    Caption = 'Insertar Elemento'
    TabOrder = 9
  end
  object BtnShowConj: TButton
    Left = 8
    Top = 524
    Width = 97
    Height = 41
    Caption = 'Mostrar Conjunto'
    TabOrder = 10
  end
  object BtnUnir: TButton
    Left = 8
    Top = 571
    Width = 97
    Height = 41
    Caption = 'Unir'
    TabOrder = 11
  end
  object BrnIntersecta: TButton
    Left = 8
    Top = 618
    Width = 97
    Height = 41
    Caption = 'Intersecta'
    TabOrder = 12
  end
  object ENombreElem: TEdit
    Left = 111
    Top = 477
    Width = 98
    Height = 23
    TabOrder = 13
  end
  object ENomMostrar: TEdit
    Left = 111
    Top = 524
    Width = 98
    Height = 23
    TabOrder = 14
  end
  object BtnChangeType: TButton
    Left = 8
    Top = 253
    Width = 113
    Height = 39
    Caption = 'Crear Conjunto'
    TabOrder = 15
  end
end
