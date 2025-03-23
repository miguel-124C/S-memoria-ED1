object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 817
  ClientWidth = 1205
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object LabelTipoLista: TLabel
    Left = 8
    Top = 288
    Width = 172
    Height = 32
    Alignment = taCenter
    Caption = 'Lista no creada'
    Color = clHotLight
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
    Transparent = False
    Layout = tlCenter
  end
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
    Top = 24
    Width = 97
    Height = 41
    Caption = 'Crear Memoria'
    TabOrder = 0
    OnClick = BtnCreateMemoriaClick
  end
  object BtnPedirEspacio: TButton
    Left = 8
    Top = 71
    Width = 97
    Height = 41
    Caption = 'Pedir Espacio'
    TabOrder = 1
    OnClick = BtnPedirEspacioClick
  end
  object BtnLiberarEspacio: TButton
    Left = 8
    Top = 118
    Width = 97
    Height = 41
    Caption = 'Liberar Espacio'
    TabOrder = 2
    OnClick = BtnLiberarEspacioClick
  end
  object BtnMostrarMemoria: TButton
    Left = 8
    Top = 165
    Width = 97
    Height = 41
    Caption = 'Mostrar Memoria'
    TabOrder = 3
    OnClick = BtnMostrarMemoriaClick
  end
  object BtnPonerDato: TButton
    Left = 8
    Top = 212
    Width = 97
    Height = 41
    Caption = 'Poner Dato'
    TabOrder = 4
    OnClick = BtnPonerDatoClick
  end
  object ENombreEspacio: TEdit
    Left = 111
    Top = 71
    Width = 98
    Height = 23
    TabOrder = 5
  end
  object ENombreLiberarEspacio: TEdit
    Left = 111
    Top = 118
    Width = 98
    Height = 23
    TabOrder = 6
  end
  object EInicioMemoria: TEdit
    Left = 111
    Top = 165
    Width = 98
    Height = 23
    TabOrder = 7
    Text = '1'
  end
  object EFinMemoria: TEdit
    Left = 215
    Top = 165
    Width = 98
    Height = 23
    TabOrder = 8
    Text = '20'
  end
  object EDireccionPonerDato: TEdit
    Left = 111
    Top = 212
    Width = 98
    Height = 23
    TabOrder = 9
  end
  object EIdPonerDato: TEdit
    Left = 215
    Top = 212
    Width = 98
    Height = 23
    TabOrder = 10
  end
  object EValorPonerDato: TEdit
    Left = 319
    Top = 212
    Width = 98
    Height = 23
    TabOrder = 11
  end
  object BtnCrearLista: TButton
    Left = 8
    Top = 344
    Width = 97
    Height = 41
    Caption = 'Crear Lista'
    TabOrder = 12
    OnClick = BtnCrearListaClick
  end
  object BtnInsertInicio: TButton
    Left = 8
    Top = 391
    Width = 97
    Height = 41
    Caption = 'Insertar Inicio'
    TabOrder = 13
    OnClick = BtnInsertInicioClick
  end
  object BtnInsertFin: TButton
    Left = 8
    Top = 438
    Width = 97
    Height = 41
    Caption = 'Insertar Final'
    TabOrder = 14
    OnClick = BtnInsertFinClick
  end
  object BtnMostrarLista: TButton
    Left = 8
    Top = 485
    Width = 97
    Height = 41
    Caption = 'MostrarLista'
    TabOrder = 15
    OnClick = BtnMostrarListaClick
  end
  object EListaInsertInicio: TEdit
    Left = 111
    Top = 391
    Width = 98
    Height = 23
    TabOrder = 16
  end
  object EListaInsertFin: TEdit
    Left = 111
    Top = 438
    Width = 98
    Height = 23
    TabOrder = 17
  end
end
