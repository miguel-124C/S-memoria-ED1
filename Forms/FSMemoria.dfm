object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
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
end
