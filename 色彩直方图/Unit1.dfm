object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 519
  ClientWidth = 776
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 409
    Height = 517
    ActivePage = ImagePage
    TabOrder = 0
    object ImagePage: TTabSheet
      Caption = 'Image'
      object Image: TImage
        Left = 0
        Top = 32
        Width = 394
        Height = 417
      end
    end
  end
  object PageControl2: TPageControl
    Left = 400
    Top = 0
    Width = 377
    Height = 521
    ActivePage = LevelsPage
    TabOrder = 1
    object LevelsPage: TTabSheet
      Caption = 'Levels'
      ExplicitLeft = 15
      ExplicitTop = 48
      object LevelsImage: TImage
        Left = 56
        Top = 32
        Width = 256
        Height = 256
      end
      object InputMinLabel: TLabel
        Left = 48
        Top = 328
        Width = 52
        Height = 13
        Caption = 'InputMin : '
      end
      object InputMaxLabel: TLabel
        Left = 200
        Top = 328
        Width = 56
        Height = 13
        Caption = 'InputMax : '
      end
      object OutputMinLabel: TLabel
        Left = 48
        Top = 368
        Width = 60
        Height = 13
        Caption = 'OutputMin : '
      end
      object OutputMaxLabel: TLabel
        Left = 200
        Top = 368
        Width = 64
        Height = 13
        Caption = 'OutputMax : '
      end
      object InputMin: TEdit
        Left = 114
        Top = 325
        Width = 47
        Height = 21
        TabOrder = 0
        Text = 'InputMin'
      end
      object InputMax: TEdit
        Left = 270
        Top = 325
        Width = 51
        Height = 21
        TabOrder = 1
        Text = 'InputMax'
      end
      object OutputMin: TEdit
        Left = 114
        Top = 365
        Width = 47
        Height = 21
        TabOrder = 2
        Text = 'OutputMin'
      end
      object OutputMax: TEdit
        Left = 270
        Top = 365
        Width = 51
        Height = 21
        TabOrder = 3
        Text = 'OutputMax'
      end
      object ResetButton: TButton
        Left = 64
        Top = 408
        Width = 75
        Height = 25
        Caption = 'Reset'
        TabOrder = 4
      end
      object OkButton: TButton
        Left = 232
        Top = 408
        Width = 75
        Height = 25
        Caption = 'Ok'
        TabOrder = 5
      end
    end
    object CurvePage: TTabSheet
      Caption = 'Curve'
      ImageIndex = 1
      object CurveImage: TImage
        Left = 56
        Top = 32
        Width = 256
        Height = 256
      end
      object FormerLabel: TLabel
        Left = 80
        Top = 320
        Width = 59
        Height = 13
        Caption = 'FormerLabel'
      end
      object ArrowLabel: TLabel
        Left = 152
        Top = 320
        Width = 24
        Height = 13
        Caption = '---->'
      end
      object FinalLabel: TLabel
        Left = 192
        Top = 320
        Width = 47
        Height = 13
        Caption = 'FinalLabel'
      end
      object CurveResetButton: TButton
        Left = 152
        Top = 368
        Width = 75
        Height = 25
        Caption = 'Reset'
        TabOrder = 0
      end
    end
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Left = 736
    Top = 32
  end
  object MainMenu1: TMainMenu
    Left = 744
    Top = 80
    object FileMenu: TMenuItem
      Caption = 'File'
      object OpenMenu: TMenuItem
        Caption = 'Open'
      end
    end
    object ImageMenu: TMenuItem
      Caption = 'Image'
    end
  end
end
