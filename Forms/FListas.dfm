object Form4: TForm4
  Left = 0
  Top = 0
  Caption = 'Lista'
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
    Top = 208
    Width = 159
    Height = 32
    Caption = 'Lista no creada'
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
    Top = 373
    Width = 97
    Height = 41
    Caption = 'Mostrar Memoria'
    TabOrder = 3
    OnClick = BtnMostrarMemoriaClick
  end
  object ENombreEspacio: TEdit
    Left = 111
    Top = 64
    Width = 98
    Height = 23
    TabOrder = 4
  end
  object ENombreLiberarEspacio: TEdit
    Left = 111
    Top = 111
    Width = 98
    Height = 23
    TabOrder = 5
  end
  object EInicioMemoria: TEdit
    Left = 111
    Top = 382
    Width = 98
    Height = 23
    TabOrder = 6
    Text = '1'
  end
  object EFinMemoria: TEdit
    Left = 215
    Top = 382
    Width = 98
    Height = 23
    TabOrder = 7
    Text = '20'
  end
  object BtnCreateLista: TButton
    Left = 8
    Top = 256
    Width = 97
    Height = 33
    Caption = 'Crear Lista'
    TabOrder = 8
    OnClick = BtnCreateListaClick
  end
  object BtnInsertInicio: TButton
    Left = 8
    Top = 295
    Width = 97
    Height = 33
    Caption = 'Insertar Inicio'
    TabOrder = 9
    OnClick = BtnInsertInicioClick
  end
  object BtnInsertFinal: TButton
    Left = 8
    Top = 334
    Width = 97
    Height = 33
    Caption = 'Insertar Final'
    TabOrder = 10
    OnClick = BtnInsertFinalClick
  end
  object BtnMostrarLista: TButton
    Left = 8
    Top = 420
    Width = 97
    Height = 33
    Caption = 'Mostrar Lista'
    TabOrder = 11
    OnClick = BtnMostrarListaClick
  end
  object BtnChangeType: TButton
    Left = 271
    Top = 211
    Width = 113
    Height = 39
    Caption = 'Cambiar Lista'
    TabOrder = 12
    Visible = False
    OnClick = BtnChangeTypeClick
  end
  object EInsertInicio: TEdit
    Left = 111
    Top = 300
    Width = 98
    Height = 23
    TabOrder = 13
  end
  object EInsertFin: TEdit
    Left = 111
    Top = 339
    Width = 98
    Height = 23
    TabOrder = 14
  end
end
