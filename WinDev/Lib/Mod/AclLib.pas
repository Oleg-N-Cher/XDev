////////////////////////////////////////////////////////////////////////////////
//                       PLEASE DO NOT REMOVE THIS HEADER!                    //
//                          PLEASE READ IT CAREFULLY!                         //
////////////////////////////////////////////////////////////////////////////////
//                            API Controls Library                            //
//                   (Win32 API implementation of TWinControl)                //
//                         (c) Alexander B. Bokovikov,                        //
//                         Yekaterinburg, Russia, 2000                        //
//                                version 3.24                                //
//           http://www.apress.ru/pages/bokovikov/delphi/acl/acl.zip          //
//                          E-mail:bokovikov@mail.ru                          //
////////////////////////////////////////////////////////////////////////////////
//                          Changes from version 3.23:                        //
//   1. UTILS unit has been changed to ACLUtils unit                          //
//   2. New code portions have been added (see below)                         //
////////////////////////////////////////////////////////////////////////////////
//   Portion (c) 2000 by Alexander V. Hramov aka fduch                        //
//   e-mail: ahramov@mail.ru, web page: http://fduch.i-connect.com            //
//   Add next features:                                                       //
//   1. Add THotKey class, which implements functionality of HotKey control   //
//   2. Add support fsUnderline in TFont                                      //
//   3. Add procedure TComboBox.DoMouseDown. For use this feature define      //
//      symbol CaptureMouse                                                   //	
//   4. Add for ComboBox WS_VSCROLL as default style                          //
//   5. For add kbd.res resource, define symbol KBD		              //		
////////////////////////////////////////////////////////////////////////////////
//   Portion (c) 2000 by Vladimir V. Kochelev                                 //
//   e-mail: kvv@kvant.novgorod.net                                           //
//   Add next features:                                                       //
//   1. Add menu support.                                                     //
//   2. Add tray icon insertion / deletion functions                          //
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                   IMPORTANT FOR PROJECT PARTICIPATORS!                     //
//                                                                            //
//  If you have some interesting (in your opinion) code portions which you    //
//  consider could be added to ACL library, then you may send modified LAST   //
//  AVAILABLE ON MY SITE ACL version to me via e-mail. Please be guided by    //
//  the next common requirements in such modifications:                       //
//  1. Please choose single abbreviature for your footprints                  //
//    (for example "xxx")                                                     //
//  2. Please make your footprint at the beginning of your code in the shape  //
//    {<xxx>} from the first position in the line.                            //
//  3. Please make your footprint at the end of your code in the shape        //
//    {</xxx>} from the first position in the line.                           //
//  4. Please insert the short annotation in ACL file header as you can see   //
//    above.                                                                  //
//  Please view current ACL text for the examples of how to do that right.    //
////////////////////////////////////////////////////////////////////////////////
//          THIS CODE IS PROVIDED "AS IS" WITHOUT ANY WARRANTIES.             //
//                    YOU MAY USE IT AT YOUR OWN RISK.                        //
////////////////////////////////////////////////////////////////////////////////

unit ACL;

interface

uses Windows, Messages, AclUtils, ShellAPI;

{<fduch> }
{.$DEFINE CaptureMouse}
{.$DEFINE KBD}
{</fduch>}

type
  TBkMode = (bk_Opaque,bk_Transparent,bk_Slide);
  TModalResult = Low(Integer)..High(Integer);

{ TModalResult values }

const
  mrNone     = 0;
  mrOk       = idOk;
  mrCancel   = idCancel;
  mrAbort    = idAbort;
  mrRetry    = idRetry;
  mrIgnore   = idIgnore;
  mrYes      = idYes;
  mrNo       = idNo;
  mrAll      = mrNo + 1;
  mrNoToAll  = mrAll + 1;
  mrYesToAll = mrNoToAll + 1;

{ Cursor identifiers }

type
  TCursor = -32768..32767;

const
  IDC_NODROP =    PChar(32767);
  IDC_DRAG   =    PChar(32766);
  IDC_HSPLIT =    PChar(32765);
  IDC_VSPLIT =    PChar(32764);
  IDC_MULTIDRAG = PChar(32763);
  IDC_SQLWAIT =   PChar(32762);
  IDC_HANDPT =   PChar(32761);

  crDefault     = TCursor(0);
  crNone        = TCursor(-1);
  crArrow       = TCursor(-2);
  crCross       = TCursor(-3);
  crIBeam       = TCursor(-4);
  crSize        = TCursor(-22);
  crSizeNESW    = TCursor(-6);
  crSizeNS      = TCursor(-7);
  crSizeNWSE    = TCursor(-8);
  crSizeWE      = TCursor(-9);
  crUpArrow     = TCursor(-10);
  crHourGlass   = TCursor(-11);
  crDrag        = TCursor(-12);
  crNoDrop      = TCursor(-13);
  crHSplit      = TCursor(-14);
  crVSplit      = TCursor(-15);
  crMultiDrag   = TCursor(-16);
  crSQLWait     = TCursor(-17);
  crNo          = TCursor(-18);
  crAppStart    = TCursor(-19);
  crHelp        = TCursor(-20);
  crHandPoint   = TCursor(-21);
  crSizeAll     = TCursor(-22);

  WM_NOTIFYICON = WM_USER + 4000;

  FormClassName = 'TACLFORM';

  ACL_DEFAULT_CHARSET = DEFAULT_CHARSET;
//  ACL_DEFAULT_CHARSET = RUSSIAN_CHARSET;

type
    TCreateParams = record
      Caption: PChar;
      Style: Longint;
      ExStyle: Longint;
      X, Y: Integer;
      Width, Height: Integer;
      WndParent: HWnd;
      Param: Pointer;
      WindowClass: TWndClass;
      WinClassName: array[0..63] of Char;
    end;

    TWndProc = function (Window: HWnd; AMessage, WParam, LParam: Longint): Longint; stdcall;
    TShiftState = set of (ssShift, ssAlt, ssCtrl,
                          ssLeft, ssRight, ssMiddle, ssDouble);
    TMouseButton = (mbLeft, mbRight, mbMiddle);

{<fduch> }
    THKModifier = (hkAlt, hkCtrl, hkShift, hkExt);
    THKModifiers = set of THKModifier;
    THKInvalidKey = (hcNone, hcShift, hcCtrl, hcAlt, hcShiftCtrl, hcShiftAlt, hcCtrlAlt, hcShiftCtrlAlt);
    THKInvalidKeys = set of THKInvalidKey;
{</fduch>}

    TNotifyEvent = procedure(Sender: TObject) of object;
    TCloseEvent = function(Sender: TObject) : boolean of object;
    TEraseEvent = procedure(Sender: TObject; HD: HDC; R: TRect) of object;
    TMouseEvent = procedure(Sender: TObject; Button: TMouseButton;
                            Shift: TShiftState; X, Y: Integer) of object;
    TMouseMoveEvent = procedure(Sender: TObject; Shift: TShiftState;
                                X, Y: Integer) of object;
    TKeyEvent = procedure(Sender: TObject; Key: Word;
                          Shift: TShiftState) of object;
    TKeyPressEvent = procedure(Sender: TObject; Key: Char) of object;
    THitTestEvent = procedure(Sender: TObject; X, Y : integer;
                              var Result : integer) of object;
{<kvv>}
    TMenuItemEvent = procedure(Sender: TObject; wID: Word) of object;
{</kvv>}

    TWinControl = class;

    TControl = class
    private
      FOwner : TWinControl;
      FLeft : integer;
      FTop : integer;
      FWidth : integer;
      FHeight : integer;
    public
      constructor Create(AOwner : TWinControl);
      procedure Paint(DC : HDC); virtual; abstract;
      destructor Destroy; override;
      property Left : integer read FLeft write FLeft;
      property Top : integer read FTop write FTop;
      property Width : integer read FWidth write FWidth;
      property Height : integer read FHeight write FHeight;
    end;

    PControlList = ^TControlList;
    TControlList = packed record
      Control : TControl;
      Next : PControlList;
    end;

    PWinControlList = ^TWinControlList;
    TWinControlList = packed record
      WinControl : TWinControl;
      Next : PWinControlList;
    end;

    {Font}
    TFontPitch = (fpDefault, fpFixed, fpVariable);
    TFontName = type string;
    TFontCharset = 0..255;
    TFontDataName = string[LF_FACESIZE - 1];
    TFontStyle = (fsBold, fsItalic, fsUnderline, fsStrikeOut);
    TFontStyles = set of TFontStyle;
    TFontStylesBase = set of TFontStyle;

    TFontData = packed record
      Height: Integer;
      Pitch: TFontPitch;
      Style: TFontStylesBase;
      Charset: TFontCharset;
      Name: TFontDataName;
    end;

    TFont = class
    private
      FHandle  : HFont;
      FControl : TWinControl;
      FFontData : TFontData;
      FLogFont : TLogFont;
      FColor: TColor;
      FPixelsPerInch: Integer;
      procedure GetData(const AFont : TLogFont; var Data : TFontData);
      procedure SetData(const Data : TFontData; var AFont : TLogFont);
      procedure UpdateFont;
      procedure SetLogFont(const AFont : TLogFont);
    protected
      function GetHeight : Integer;
      function GetName : TFontName;
      function GetPitch : TFontPitch;
      function  GetSize : Integer;
      function GetStyle : TFontStyles;
      function GetCharset : TFontCharset;
      procedure SetColor(Value: TColor);
      procedure SetHeight(Value: Integer);
      procedure SetName(const Value: TFontName);
      procedure SetPitch(Value: TFontPitch);
      procedure SetSize(Value: Integer);
      procedure SetStyle(Value: TFontStyles);
      procedure SetCharset(Value: TFontCharset);
      procedure SetPixelsPerInch(Value: integer);
    public
      constructor Create;
      destructor Destroy; override;
      property Handle: HFont read FHandle;
      property PixelsPerInch: Integer read FPixelsPerInch write SetPixelsPerInch;
      property Charset: TFontCharset read GetCharset write SetCharset;
      property Color: TColor read FColor write SetColor;
      property Height: Integer read GetHeight write SetHeight;
      property Name: TFontName read GetName write SetName;
      property Pitch: TFontPitch read GetPitch write SetPitch;
      property Size: Integer read GetSize write SetSize;
      property Style: TFontStyles read GetStyle write SetStyle;
    end;

    PFontList = ^TFontList;
    TFontList = array [0..0] of TLogFont;
    TFontSet = (fsAll, fsTrueTypeOnly);

    TFonts = class
    private
      FDC       : HDC;
      FCount    : integer;
      FFonts    : PFontList;
      FSet      : TFontSet;
      FCharSet  : TFontCharSet;
    protected
      procedure SetCharSet(Value : TFontCharSet);
      procedure Enumerate;
      function IsTrueType(const AFont : TLogFont) : boolean;
      function GetFont(i : integer) : TLogFont;
    public
      constructor Create;
      destructor Destroy; override;
      function IndexOf(APitch : TFontPitch;
                 const AName  : string) : integer;
      function IsDefaultPitch(const AFont : TLogFont) : boolean;
      function IsFixedPitch(const AFont : TLogFont) : boolean;
      function IsVariablePitch(const AFont : TLogFont) : boolean;
      function FindFont(AName : TFontName;
                        APitch : TFontPitch) : TLogFont;
      property CharSet : TFontCharSet read FCharSet write SetCharSet;
      property Count : integer read FCount;
      property Font[index : integer] : TLogFont read GetFont;
    end;

    TWinControl = class
    private
     FHandle        : HWnd;
     FParentHandle  : HWnd;
     FClassName     : PChar;
     FDefWndProc    : longint;
     FHelpContext   : DWORD;
     FHelpFile      : shortstring;
     FTextBuf       : shortstring;
     FTextLen       : Cardinal;
     FBrush         : HBrush;
     FCursorHandle  : HCursor;
     FCursor        : TCursor;
     FFont          : TFont;
     FDC            : HDC;
     FColor         : TColor;
     FTextColor     : TColor;
     FBkMode        : TBkMode;
     FStyle         : longint;
     FExStyle       : longint;
     FCtl3D         : boolean;
     FLeft          : integer;
     FTop           : integer;
     FWidth         : integer;
     FHeight        : integer;
     FParent        : TWinControl;
     FCList         : PControlList;
     FWList         : PWinControlList;
     FAutoStop      : boolean;
     FActiveControl : TWinControl;
     FEnabled       : boolean;
     FIsModal       : boolean;
     FModalResult   : TModalResult;
     FTabStop       : boolean;
     FVisible       : boolean;
     FHTest         : longint;
     FOnCreate      : TNotifyEvent;
     FOnClose       : TCloseEvent;
     FOnDestroy     : TNotifyEvent;
     FOnChange      : TNotifyEvent;
     FOnClick       : TNotifyEvent;
     FOnHitTest     : THitTestEvent;
     FOnErase       : TEraseEvent;
     FOnEnter       : TNotifyEvent;
     FOnExit        : TNotifyEvent;
     FOnMouseDown   : TMouseEvent;
     FOnMouseMove   : TMouseMoveEvent;
     FOnMouseUp     : TMouseEvent;
     FOnKeyDown     : TKeyEvent;
     FOnKeyUp       : TKeyEvent;
     FOnKeyPress    : TKeyPressEvent;
     FOnNIMove      : TNotifyEvent;
     FOnNILDown     : TNotifyEvent;
     FOnNILUp       : TNotifyEvent;
     FOnEndSession  : TCloseEvent;
{<kvv>}
     FOnMenuItemSelect: TMenuItemEvent;
{</kvv>}
     procedure Show;
     procedure Hide;
    protected
     function WndProc(AMessage, WParam, LParam : Longint): Longint; virtual; stdcall;
     function GetWndProc : pointer;
     function GetParentHandle : HWnd;
     procedure SetParentHandle(Value: HWnd);
     procedure CreateParams(var Params: TCreateParams); virtual;
     procedure CreateWindowHandle(const Params: TCreateParams);
     procedure DestroyWindowHandle;
     ///////////////////////////////////////////////////////////
     procedure WMClose(var AMsg: TWMClose);
     procedure WMDestroy(var AMsg: TWMDestroy);
     procedure WMPaint(var AMsg: TWMPaint); virtual;
     procedure WMEraseBkgnd(var AMsg : TWMEraseBkgnd); virtual;
     procedure WMCtlcolor(var AMsg : TMessage);
     procedure WMNCHitTest(var AMsg : TMessage);
     procedure WMCommand(var AMsg : TWMCommand);
     procedure WMSetFocus(var AMsg : TWMSetFocus);
     procedure WMKillFocus(var AMsg : TWMKillFocus);
     procedure WMLButtonDown(var AMsg: TWMLButtonDown);
     procedure WMRButtonDown(var AMsg: TWMRButtonDown);
     procedure WMLButtonDblClk(var AMsg: TWMLButtonDblClk);
     procedure WMRButtonDblClk(var AMsg: TWMRButtonDblClk);
     procedure WMMouseMove(var AMsg: TWMMouseMove);
     procedure WMLButtonUp(var AMsg: TWMLButtonUp);
     procedure WMRButtonUp(var AMsg: TWMRButtonUp);
     procedure WMSetCursor(var AMsg: TWMSetCursor);
     procedure WMKeyDown(var AMsg: TWMKeyDown);
     procedure WMSysKeyDown(var AMsg: TWMKeyDown);
     procedure WMKeyUp(var AMsg: TWMKeyUp);
     procedure WMSysKeyUp(var AMsg: TWMKeyUp);
     procedure WMChar(var AMsg: TWMChar);
     procedure WMSysCommand(var AMsg: TWMSysCommand);
     procedure WMNotifyIcon(var AMsg: TMessage);
     procedure WMQueryEndSession(var AMsg: TMessage);
     procedure WMHelp(var AMsg: TMessage);
     procedure ProcessMessage(var AMsg: TMessage); virtual;
     ////////////////////////////////////////////////////
     procedure DoMouseDown(var AMsg: TWMMouse; Button: TMouseButton;
                           Shift: TShiftState); virtual;
     procedure DoMouseUp(var AMsg: TWMMouse; Button: TMouseButton;
                         Shift: TShiftState); virtual;
     function DoKeyDown(var AMsg: TWMKey): Boolean; virtual;
     function DoKeyUp(var AMsg: TWMKey): Boolean; virtual;
     function DoKeyPress(var AMsg: TWMKey): Boolean; virtual;
     procedure SetColor(Value : TColor);
     procedure SetTextColor(Value : TColor);
     procedure Change; virtual;
     procedure Click; virtual;
     procedure DoEnter; virtual;
     procedure DoExit; virtual;
     procedure SetEnabled(Value: boolean);
     procedure SetCursor(Value : TCursor);
     function GetText : shortstring;
     procedure SetText(const Value: shortstring);
     function GetClientRect : TRect;
     function GetClientWidth : integer;
     function GetClientHeight : integer;
     function IsParentHandle(AHandle : HWnd) : boolean;
     procedure SetBounds(R : TRect);
     procedure SetLeft(Value : integer);
     procedure SetTop(Value : integer);
     procedure SetWidth(Value : integer);
     procedure SetHeight(Value : integer);
     procedure Dispatch(var AMsg); override;
     procedure SetVisible(Value : boolean);
    public
     ///////////////////////////////////////////////////////
     constructor Create(AParent : TWinControl); virtual;
     destructor Destroy; override;
     procedure CreateWnd; virtual;
     procedure DestroyWnd;
     procedure Close;
     function ShowModal : TModalResult;
     procedure EndModal(Value : TModalResult);
     function ProcessMsg(var Msg: TMsg): Boolean;
     procedure ProcessMessages;
     procedure Invalidate;
     procedure SetFocus;
     procedure SelectPrev;
     procedure SelectNext;
     procedure SelectFirst;
     procedure SelectLast;
     function IsFirstSelected : boolean;
     function IsLastSelected : boolean;
     procedure InsertWinControl(AControl : TWinControl);
     procedure InsertControl(AControl : TControl);
     procedure SetFont(const AFont : TLogFont);
     ////////////////////////////////////////////////////////////////
     property AutoStop : boolean read FAutoStop write FAutoStop;
     property Caption : shortstring read GetText write SetText;
     property Color : TColor read FColor write SetColor;
     property Cursor : TCursor read FCursor write SetCursor;
     property HelpContext : DWORD read FHelpContext write FHelpContext;
     property HelpFile : shortstring read FHelpFile write FHelpFile;
     property Style : longint read FStyle write FStyle;
     property ExStyle : longint read FExStyle write FExStyle;
     property Ctl3D : boolean read FCtl3D write FCtl3D;
     property TextColor : TColor read FTextColor write SetTextColor;
     property Enabled : boolean read FEnabled write SetEnabled;
     property Handle : HWnd read FHandle;
     property ParentHandle : HWnd read GetParentHandle write SetParentHandle;
     property Brush : HBrush read FBrush write FBrush;
     property Font : TFont read FFont;
     property Left : integer read FLeft write SetLeft;
     property Top : integer read FTop write SetTop;
     property Width : integer read FWidth write SetWidth;
     property Height : integer read FHeight write SetHeight;
     property Parent : TWinControl read FParent;
     property ClientWidth : integer read GetClientWidth;
     property ClientHeight : integer read GetClientHeight;
     property ClientRect : TRect read GetClientRect;
     property HitTestResult : longint read FHTest write FHTest;
     property IsModal : boolean read FIsModal;
     property Visible : boolean read FVisible write SetVisible;
     property TabStop : boolean read FTabStop write FTabStop;
     ////////////////////////////////////////////////////////////////
     property OnCreate : TNotifyEvent read FOnCreate write FOnCreate;
     property OnDestroy : TNotifyEvent read FOnDestroy write FOnDestroy;
     property OnChange : TNotifyEvent read FOnChange write FOnChange;
     property OnClose : TCloseEvent read FOnClose write FOnClose;
     property OnClick : TNotifyEvent read FOnClick write FOnClick;
     property OnErase : TEraseEvent read FOnErase write FOnErase;
     property OnHitTest : THitTestEvent read FOnHitTest write FOnHitTest;
     property OnMouseDown : TMouseEvent read FOnMouseDown write FOnMouseDown;
     property OnMouseMove : TMouseMoveEvent read FOnMouseMove write FOnMouseMove;
     property OnMouseUp : TMouseEvent read FOnMouseUp write FOnMouseUp;
     property OnKeyDown : TKeyEvent read FOnKeyDown write FOnKeyDown;
     property OnKeyUp : TKeyEvent read FOnKeyUp write FOnKeyUp;
     property OnKeyPress : TKeyPressEvent read FOnKeyPress write FOnKeyPress;
     property OnNIMove : TNotifyEvent read FOnNIMove write FOnNIMove;
     property OnNILDown : TNotifyEvent read FOnNILDown write FOnNILDown;
     property OnNILUp : TNotifyEvent read FOnNILUp write FOnNILUp;
     property OnEndSession : TCloseEvent read FOnEndSession write FOnEndSession;
     ////////////////////////////////////////////////////////////////
    end;

    TStdControl = class(TWinControl)
    public
     procedure CreateWnd; override;
    end;

    TLabel = class(TStdControl)
    private
     FFormat : longint;
    protected
     procedure WMPaint(var AMsg: TWMPaint); override;
     procedure WMEraseBkgnd(var AMsg : TWMEraseBkgnd); override;
     procedure HitTest(Sender: TObject; X, Y : integer;
                       var Result : integer);
    public
     constructor Create(AParent : TWinControl); override;
     property BkMode : TBkMode read FBkMode write FBkMode;
     property TextFormat : longint read FFormat write FFormat;
    end;

    TEdit = class(TStdControl)
    protected
     function DoKeyPress(var AMsg: TWMKey): Boolean; override;
     function GetMaxLength : integer;
     procedure SetMaxLength(Value : integer);
     function GetMargin : word;
     procedure SetMargin(Value : word);
    public
     constructor Create(AParent : TWinControl); override;
     property MaxLength : integer read GetMaxLength write SetMaxLength;
     property MarginWidth : word read GetMargin write SetMargin;
     property Text : shortstring read GetText write SetText;
    end;

{<fduch> }
    {HotKey}
    THotKey = class (TStdControl)
    private
      FInvalidKeys: THKInvalidKeys;
      FModifiers: THKModifiers;
      FHotKey: byte;
      FMod: Byte;
      function GetHotKey: Byte;
      function GetModifiers: THKModifiers;
      function GetSHotKey: string;
      function GetModif: byte;
      procedure SetHotKey(const Value: Byte);
      procedure SetInvalidKeys(const Value: THKInvalidKeys);
      procedure SetModifiers(const Value: THKModifiers);
      procedure SetSHotKey(const Value: string);
      procedure SetModif(const Value: byte);
    public
      constructor Create(AParent: TWinControl); override;
      property HotKey: byte read GetHotKey write SetHotKey;
      property BModifiers: byte read GetModif write SetModif;
      property InvalidKeys: THKInvalidKeys read FInvalidKeys write SetInvalidKeys;
      property Modifiers: THKModifiers read GetModifiers write SetModifiers;
      property StrHotKey: string read GetSHotKey write SetSHotKey;
    end;
{</fduch>}

    TListBox = class(TStdControl)
    private
     FError  : integer;
     FSorted : boolean;
    protected
     function GetCount: Integer;
     function Get(Index: Integer): shortstring;
     function GetObject(Index: Integer): TObject;
     procedure Put(Index: Integer; const S: shortstring);
     procedure PutObject(Index: Integer; AObject: TObject);
     function GetFocused : integer;
     procedure SetFocused(Value: integer);
     procedure SetSorted(Value: boolean);
    public
     constructor Create(AParent : TWinControl); override;
     function Add(const S: shortstring): Integer;
     procedure Insert(Index: Integer; const S: shortstring);
     procedure Delete(Index: Integer);
     procedure Clear;
     procedure SelectItem(Value: integer);
     property Count : integer read GetCount;
     property Focused : integer read GetFocused write SetFocused;
     property Error : integer read FError;
     property Items[Index: integer] : shortstring read Get write Put;
     property Objects[Index: integer] : TObject read GetObject write PutObject;
     property Sorted : boolean read FSorted write SetSorted;
    end;

    TComboBox = class(TStdControl)
    private
     FError  : integer;
     FSorted : boolean;
    protected
     function GetCount: Integer;
     function Get(Index: Integer): shortstring;
     procedure Put(Index: Integer; const S: shortstring);
     function GetFocused : integer;
     procedure SetFocused(Value: integer);
     procedure SetSorted(Value: boolean);
     function DoKeyDown(var AMsg: TWMKey): Boolean; override;

     {<fduch> }{$IFDEF CaptureMouse}
     procedure TComboBox.DoMouseDown(var AMsg: TWMMouse; Button: TMouseButton;
                                     Shift: TShiftState);
     {$ENDIF}{</fduch>}
    public
     constructor Create(AParent : TWinControl); override;
     function Add(const S: shortstring): Integer;
     procedure Insert(Index: Integer; const S: shortstring);
     procedure Delete(Index: Integer);
     procedure Clear;
     property Count : integer read GetCount;
     property Error : integer read FError;
     property ItemIndex : integer read GetFocused write SetFocused;
     property Items[Index: integer] : shortstring read Get write Put;
     property Sorted : boolean read FSorted write SetSorted;
     property Text : shortstring read GetText write SetText;
    end;

    TButton = class(TStdControl)
    protected
     procedure Click; override;
     function GetModalResult : TModalResult;
     procedure SetModalResult(Value: TModalResult);
    public
     constructor Create(AParent : TWinControl); override;
     property ModalResult : TModalResult read GetModalResult write SetModalResult;
    end;

    TCheckBox = class(TStdControl)
    private
     FChecked : boolean;
    protected
     procedure Click; override;
     procedure SetChecked(Value: boolean);
    public
     constructor Create(AParent : TWinControl); override;
     property Checked : boolean read FChecked write SetChecked;
    end;

    TGroupBox = class(TStdControl)
    public
     constructor Create(AParent : TWinControl); override;
    end;

    TProgressBar = class(TStdControl)
    private
     FRange : word;
     FPosition : word;
     FStep : word;
    protected
     function GetRange : word;
     procedure SetRange(Value : word);
     function GetPosition : word;
     procedure SetPosition(Value : word);
     function GetStep : word;
     procedure SetStep(Value : word);
    public
     constructor Create(AParent : TWinControl); override;
     property Range : word read GetRange write SetRange;
     property Position : word read GetPosition write SetPosition;
     property Step : word read GetStep write SetStep;
    end;

    TSplash = class(TWinControl)
    private
      FTextColor : TColor;
      FHCenter : boolean;
      FVCenter : boolean;
      procedure UpdateText(Value : string);
      procedure HitTest(Sender : TObject; X,Y : integer;
                        var Result : integer);
      procedure SetHCenter(Value : boolean);
      procedure SetVCenter(Value : boolean);
    public
     L          : TLabel;
     constructor Create(AParent : TWinControl); override;
     procedure CreateWnd; override;
     property TextColor : TColor read FTextColor write FTextColor;
     property Text : string write UpdateText;
     property HCenter : boolean read FHCenter write SetHCenter;
     property VCenter : boolean read FVCenter write SetVCenter;
    end;

    TKeyboardPosition = (kpLeftTop,kpRightTop,kpLeftBottom,kpRightBottom);
    TKeyboard = class(TLabel)
    private
     FPos      : TKeyboardPosition;
     FLayout0  : integer;
     FLayout1  : integer;
     FCharSet0 : integer;
     FCharSet1 : integer;
     FLay0     : HICON;
     FLay1     : HICON;
     FLayout   : integer;
     FCharSet  : integer;
     procedure InstallHook;
     procedure RemoveHook;
     procedure InitParams;
     procedure WMPaint(var AMsg: TWMPaint); message WM_PAINT;
     procedure LayoutChanged(ACharSet,ALayout : integer);
     procedure SetCharSet0(Value : integer);
     procedure SetCharSet1(Value : integer);
     procedure SetPos(Value : TKeyboardPosition);
    public
     constructor Create(AParent : TWinControl); override;
     destructor Destroy; override;
     property Layout0 : integer read FLayout0 write FLayout0;
     property Layout1 : integer read FLayout1 write FLayout1;
     property CharSet0: integer read FCharSet0 write SetCharSet0;
     property CharSet1: integer read FCharSet1 write SetCharSet1;
     property Position : TKeyboardPosition read FPos write SetPos;
    end;

    TTimer = class;

    TTimerWindow = class(TWinControl)
    private
      FTimer : TTimer;
    protected
      procedure ProcessMessage(var AMsg: TMessage); override;
    end;

    TTimer = class
    private
      FInterval: Cardinal;
      FWindow : TTimerWindow;
      FWindowHandle: HWND;
      FOnTimer: TNotifyEvent;
      FEnabled: Boolean;
      procedure UpdateTimer;
      procedure SetEnabled(Value: Boolean);
      procedure SetInterval(Value: Cardinal);
      procedure SetOnTimer(Value: TNotifyEvent);
    protected
      procedure Timer; dynamic;
    public
      constructor Create;
      destructor Destroy; override;
      property Enabled: Boolean read FEnabled write SetEnabled;
      property Interval: Cardinal read FInterval write SetInterval;
      property OnTimer: TNotifyEvent read FOnTimer write SetOnTimer;
    end;

    TScreen = packed record
                Width : integer;
                Height : integer;
                DesktopLeft : integer;
                DesktopTop : integer;
                DesktopWidth : integer;
                DesktopHeight : integer;
              end;
var
  Screen : TScreen;

function NewLabel(AParent : TWinControl;
                  ACaption : string;
                  ALeft,Atop,AWidth,AHeight : integer;
                  AALignment : integer;
                  ABkMode : TBkMode;
                  ABkColor,
                  ATextColor : TColor) : TLabel;

function NewEdit(AParent : TWinControl;
                 AText : shortstring;
                 ALeft,Atop,AWidth,AHeight : integer;
                 AStyle : integer;
                 ABkColor,
                 ATextColor : TColor) : TEdit;
{<fduch> }
function NewHotKey(AParent : TWinControl;
                   AHotKey : Word;
                   AModifiers : THKModifiers;
                   ALeft,Atop,AWidth,AHeight : integer;
                   ABkColor,
                   ATextColor : TColor) : THotKey;
{</fduch>}

function NewListBox(AParent : TWinControl;
                    ALeft,Atop,AWidth,AHeight : integer;
                    ASorted : boolean;
                    ABkColor,
                    ATextColor : TColor) : TListBox;

function NewComboBox(AParent : TWinControl;
                    ALeft,Atop,AWidth,AHeight : integer;
                    AStyle : integer;
                    ASorted : boolean;
                    ABkColor,
                    ATextColor : TColor) : TComboBox;

function NewButton(AParent : TWinControl;
                 ACaption : string;
                 AResult : TModalResult;
                 ALeft,Atop,AWidth,AHeight : integer;
                 ABkColor,
                 ATextColor : TColor) : TButton;

function NewCheckBox(AParent : TWinControl;
                     ACaption : string;
                     ALeft,Atop,AWidth,AHeight : integer;
                     ABkColor,
                     ATextColor : TColor) : TCheckBox;

function NewGroupBox(AParent : TWinControl;
                     ACaption : string;
                     ALeft,Atop,AWidth,AHeight : integer;
                     ABkColor,
                     ATextColor : TColor) : TGroupBox;

function NewProgressBar(AParent : TWinControl;
                        ALeft,Atop,AWidth,AHeight : integer;
                        AMin, AMax : integer;
                        ABkColor,
                        ATextColor : TColor) : TProgressBar;


{<kvv>}
// MenuItem adding function
function NewMenuItem(Var Menu: HMenu; 
          iType,State,ID : DWord; 
          Caption: ShortString; By_pos: boolean): boolean;

// Insert icon into system tray
function SetTrayIcon(AWnd: Hwnd; ID: Longint; Icon : HIcon;
                            text: ShortString): boolean;

// Delete icon from system tray
function DeleteTrayIcon(AWnd: Hwnd; ID: Longint): boolean;
{</kvv>}
{<fduch> }
function HotKeyToStr(Key: word; DModifiers: THKModifiers): shortstring;
procedure StrToHotKey(const Value: string; var Key: word; var Modifiers: THKModifiers);
{</fduch> }

var
  Fonts : TFonts;
  ScreenLogPixels : integer;
  log : text;

implementation

uses CommCtrl, multimon;

{$H+}
{$O+}
{$R CTRLS.RES}
{$IFDEF KBD}
 {$R KBD.RES}
{$ENDIF}

const ID_SELF = '__SELF__'; // constant used in GetProp()/SetProp()
                            // change it if You want.
var
  MainWindow : TWinControl;

function KeysToShiftState(Keys: Word): TShiftState;
begin
  Result := [];
  if Keys and MK_SHIFT <> 0 then Include(Result, ssShift);
  if Keys and MK_CONTROL <> 0 then Include(Result, ssCtrl);
  if Keys and MK_LBUTTON <> 0 then Include(Result, ssLeft);
  if Keys and MK_RBUTTON <> 0 then Include(Result, ssRight);
  if Keys and MK_MBUTTON <> 0 then Include(Result, ssMiddle);
  if GetKeyState(VK_MENU) < 0 then Include(Result, ssAlt);
end;

{ Convert keyboard message data to TShiftState }

function KeyDataToShiftState(KeyData: Longint): TShiftState;
const
  AltMask = $20000000;
begin
  Result := [];
  if GetKeyState(VK_SHIFT) < 0 then Include(Result, ssShift);
  if GetKeyState(VK_CONTROL) < 0 then Include(Result, ssCtrl);
  if KeyData and AltMask <> 0 then Include(Result, ssAlt);
end;

// TControl

constructor TControl.Create(AOwner : TWinControl);
begin
  inherited Create;
  FOwner := AOwner;
end;

destructor TControl.Destroy;
begin
  inherited Destroy;
end;

{ TFont }

procedure InitScreenLogPixels;
var
  DC: HDC;
begin
  DC := GetDC(0);
  ScreenLogPixels := GetDeviceCaps(DC, LOGPIXELSY);
  ReleaseDC(0,DC);
end;

constructor TFont.Create;
begin
  inherited Create;
  FHandle := 0;
  FColor := clBlack;
  FPixelsPerInch := 96;
  Pitch:= fpVariable;
  Style:= [];
  Charset:= ACL_DEFAULT_CHARSET;
  Name := 'Arial';
  //FPixelsPerInch := ScreenLogPixels;
  Size := 10;
end;

destructor TFont.Destroy;
begin
  if FHandle <> 0 then DeleteObject(FHandle);
  inherited Destroy;
end;

procedure TFont.GetData(const AFont : TLogFont; var Data : TFontData);
begin
  with Data, AFont do
  begin
    Height := lfHeight;
    if lfWeight >= FW_BOLD then
      Include(Style, fsBold);
    if lfItalic = 1 then
      Include(Style, fsItalic);
    if lfUnderline = 1 then
      Include(Style, fsUnderline);
    if lfStrikeOut = 1 then
      Include(Style, fsStrikeOut);
    Charset := TFontCharset(lfCharSet);
    Name := lfFaceName;
    case lfPitchAndFamily and $F of
      VARIABLE_PITCH: Pitch := fpVariable;
      FIXED_PITCH:    Pitch := fpFixed;
    else
      Pitch := fpDefault;
    end;
  end;
end;

procedure TFont.SetLogFont(const AFont : TLogFont);
begin
  Move(AFont, FLogFont, SizeOf(AFont));
end;

procedure TFont.SetData(const Data : TFontData; var AFont : TLogFont);
begin
  with Data, AFont do
  begin
    lfHeight := Height;
    lfWidth := 0;
    if fsBold in Style then lfWeight := FW_BOLD
                       else lfWeight := FW_NORMAL;
    if fsItalic in Style then lfItalic := 1;
    if fsUnderline in Style then lfUnderline := 1;
    if fsStrikeOut in Style then lfStrikeOut := 1;
    lfCharset := Charset;
    Move(Name, lfFaceName, SizeOf(Name));
    case Pitch of
      fpVariable : lfPitchAndFamily := lfPitchAndFamily or VARIABLE_PITCH;
      fpFixed    : lfPitchAndFamily := lfPitchAndFamily or FIXED_PITCH;
    end;
  end;
end;

procedure TFont.UpdateFont;
var OldFont : HFont;
begin
  OldFont := FHandle;
  FLogFont.lfWidth := 0;
  if (FControl <> nil) and (FControl.FHandle > 0) then
  begin
    FControl.SetFont(FLogFont);
  end                                             else
  begin
    FHandle := CreateFontIndirect(FLogFont);
    if OldFont <> 0 then DeleteObject(OldFont);
  end;
end;

function TFont.GetHeight : Integer;
begin
  Result := FFontData.Height;
end;

function TFont.GetName: TFontName;
begin
  Result := string(FLogFont.lfFaceName);
end;

function TFont.GetPitch : TFontPitch;
begin
  Result := FFontData.Pitch;
end;

function TFont.GetStyle: TFontStyles;
var Styles : TFontStyles;
begin
  Styles := [];
  with FLogFont do
  begin
    if lfWeight = FW_BOLD then Styles := Styles + [fsBold];
    if lfItalic > 0 then Styles := Styles + [fsItalic];
  end;
  Result := Styles;
end;

function TFont.GetCharset : TFontCharset;
begin
  Result := FFontData.Charset;
end;

procedure TFont.SetColor(Value: TColor);
begin
  if FColor <> Value then
  begin
    FColor := Value;
    if (FControl <> nil) and (FControl.FHandle > 0) then
      FControl.SetTextColor(Value);
  end;
end;

procedure TFont.SetHeight(Value: Integer);
begin
  FLogFont.lfHeight := Value;
  UpdateFont;
end;

procedure TFont.SetName(const Value: TFontName);
var AFont   : TLogFont;
    AHeight : longint;
begin
  if Length(Value) > 0 then
  begin
    AFont := Fonts.FindFont(Value, FFontData.Pitch);
    if Assigned(FControl) and (FControl.Handle <> 0) then
    begin
      // here it needs to store all existing font attributes except for name
      AFont.lfHeight := FLogFont.lfHeight;
      AFont.lfWeight := FLogFont.lfWeight;
      AFont.lfItalic := FLogFont.lfItalic;
      AFont.lfUnderline := FLogFont.lfUnderline;
//      AFont.lfCharSet := FLogFont.lfCharSet;
    end;
    SetLogFont(AFont);
    UpdateFont;
  end;
end;

function TFont.GetSize: Integer;
begin
  Result := -MulDiv(FFontData.Height, 72, FPixelsPerInch);
end;

procedure TFont.SetSize(Value: Integer);
begin
  FFontData.Height := -MulDiv(Value, FPixelsPerInch, 72);
  SetHeight(FFontData.Height);
end;

procedure TFont.SetStyle(Value: TFontStyles);
begin
  with FLogFont do
  begin
    if fsBold in Value then FLogFont.lfWeight := FW_BOLD
                       else FLogFont.lfWeight := FW_NORMAL;
    if fsItalic in Value then FLogFont.lfItalic := 1
                         else FLogFont.lfItalic := 0;
{<fduch> }
    if fsUnderLine in Value then FLogFont.lfUnderline := 1
                            else FLogFont.lfUnderline := 0;
{</fduch>}
  end;
  UpdateFont;
end;

procedure TFont.SetPitch(Value: TFontPitch);
begin
  with FLogFont do
  case Value of
    fpDefault  : lfPitchAndFamily := lfPitchAndFamily or DEFAULT_PITCH;
    fpVariable : lfPitchAndFamily := lfPitchAndFamily or VARIABLE_PITCH;
    fpFixed    : lfPitchAndFamily := lfPitchAndFamily or FIXED_PITCH;
  end;
  FFontData.Pitch := Value;
  UpdateFont;
end;

procedure TFont.SetCharset(Value: TFontCharset);
begin
  FLOgFont.lfCharSet := Value;
  UpdateFont;
end;

procedure TFont.SetPixelsPerInch(Value: integer);
var OldS : integer;
begin
  OldS := GetSize;
  FPixelsPerInch := Value;
  SetSize(OldS);
  UpdateFont;
end;

{ TFonts }

function EnumFontsProc0(var LogFont: TLogFont; var TextMetric: TTextMetric;
  FontType: Integer; Data: Pointer): Integer; stdcall;
var
  Fnt: TFonts;
begin
  Fnt := TFonts(Data);
  if (Fnt.FSet = fsAll) or Fnt.IsTrueType(LogFont) then Inc(Fnt.FCount);
  Result := 1;
end;

function EnumFontsProc(var LogFont: TLogFont; var TextMetric: TTextMetric;
  FontType: Integer; Data: Pointer): Integer; stdcall;
var
  Fnt: TFonts;
begin
  {$R-}
  Fnt := TFonts(Data);
  if (Fnt.FSet = fsAll) or Fnt.IsTrueType(LogFont) then
  begin
    Move(LogFont,Fnt.FFonts^[Fnt.FCount],SizeOf(TLogFont));
    Inc(Fnt.FCount);
  end;
  Result := 1;
end;

constructor TFonts.Create;
begin
  inherited Create;
  FFonts := nil;
  FSet := fsTrueTypeOnly;
  FCharSet := ACL_DEFAULT_CHARSET;
  Enumerate;
  FDC := 0;
end;

destructor TFonts.Destroy;
begin
  GlobalFree(Cardinal(FFonts));
  inherited Destroy;
end;

function TFonts.GetFont(i : integer) : TLogFont;
begin
  Move(FFonts^[i],Result,SizeOf(TLogFont));
end;

function TFonts.IndexOf(APitch : TFontPitch;
                  const AName  : string) : integer;
var i : integer;
begin
  Result := 0;
  for i := 1 to FCount do
    if AnsiCompareText(string(FFonts^[i-1].lfFaceName),AName) = 0 then
    case APitch of
      fpDefault : begin
                    Result := i-1; break;
                  end;
      fpFixed : if IsFixedPitch(FFonts^[i-1]) then
                begin
                  Result := i-1; break;
                end;
      fpVariable : if IsVariablePitch(FFonts^[i-1]) then
                   begin
                     Result := i-1; break;
                   end;
    end;
end;

function TFonts.IsDefaultPitch(const AFont : TLogFont) : boolean;
begin
  Result := true;
end;

function TFonts.IsFixedPitch(const AFont : TLogFont) : boolean;
begin
  Result := (AFont.lfPitchAndFamily and $F) = FIXED_PITCH;
end;

function TFonts.IsVariablePitch(const AFont : TLogFont) : boolean;
begin
  Result := (AFont.lfPitchAndFamily and $F) = VARIABLE_PITCH;
end;

function TFonts.FindFont(AName : TFontName;
                         APitch : TFontPitch) : TLogFont;
var i : integer;
begin
  i := IndexOf(APitch,AName);
  Move(FFonts^[i],Result,SizeOf(TLogFont));
end;

procedure TFonts.SetCharset(Value: TFontCharset);
begin
  if FCharSet <> Value then
  begin
    FCharSet := Value;
    Enumerate;
  end;
end;

procedure TFonts.Enumerate;
var
  LFont: TLogFont;
begin
  FDC := GetDC(0);
  FillChar(LFont, sizeof(LFont), 0);
  LFont.lfCharset := FCharSet;
  if FFonts <> nil then GlobalFree(Cardinal(FFonts));
  FCount := 0;
  EnumFontFamiliesEx(FDC, LFont, @EnumFontsProc0, LongInt(Self), 0);
  FFonts := PFontList(GlobalAlloc(GMEM_FIXED,SizeOf(TLogFont)*FCount));
  FCount := 0;
  EnumFontFamiliesEx(FDC, LFont, @EnumFontsProc, LongInt(Self), 0);
  ReleaseDC(0, FDC);
end;

function TFonts.IsTrueType(const AFont : TLogFont) : boolean;
var
  Metrics: TTextMetric;
  lf: TLogFont;
  oldFont, newFont: HFont;
begin
  with lf do begin
    lfHeight := 10;
    lfWidth := 10;
    lfEscapement := 0;
    lfWeight := FW_REGULAR;
    lfItalic := 0;
    lfUnderline := 0;
    lfStrikeOut := 0;
    lfCharSet := RUSSIAN_CHARSET;
    lfOutPrecision := OUT_DEFAULT_PRECIS;
    lfClipPrecision := CLIP_DEFAULT_PRECIS;
    lfQuality := DEFAULT_QUALITY;
    lfPitchAndFamily := DEFAULT_PITCH or FF_DONTCARE;
    StrPCopy(lfFaceName, AFont.lfFaceName);
  end;
  newFont := CreateFontIndirect(lf);
  oldFont := SelectObject(FDC, newFont);
  GetTextMetrics(FDC, Metrics);
  Result := (Metrics.tmPitchAndFamily and TMPF_TRUETYPE) <> 0;
  SelectObject(FDC, oldFont);
  DeleteObject(newFont);
end;

{TWinControl}

function GetWindowInstance(Handle: HWND) : TWinControl;
begin
  Result := TWincontrol(GetProp(Handle,ID_SELF));
end;

function TWinControl.WndProc(AMessage, WParam, LParam : Longint): Longint;
var
  self_   : pointer;
  window_ : hWnd;
  AMsg    : TMessage;
begin
  window_ := HWND(Self);
  self_ := Ptr(GetProp(window_,ID_SELF));
  if self_ <> nil then
  begin
    AMsg.Msg := AMessage;
    AMsg.WParam := WParam;
    AMsg.LParam := LParam;
    AMsg.Result := 0;
    TWinControl(self_).ProcessMessage(AMsg);
  end            else
    AMsg.Result := DefWindowProc(window_, AMessage, WParam, LParam);
  Result := AMsg.Result;
end;

function TWinControl.GetWndProc : pointer; assembler;
asm
  MOV EAX,[EAX]
  MOV EAX,[EAX]
end;

constructor TWinControl.Create(AParent : TWinControl);
begin
  inherited Create;
  FHandle := 0;
  FParentHandle := 0;
  FTextBuf := '';
  FTextLen := 0;
  FClassName := FormClassName;
  FStyle := ws_Border or ws_Caption or ws_Ex_ControlParent;
  FExStyle := 0;
  FCtl3D := false;
  FParent := AParent;
  FDefWndProc := 0;
  FLeft := cw_UseDefault;
  FTop := cw_UseDefault;
  FWidth := cw_UseDefault;
  FHeight := cw_UseDefault;
  FColor := clSilver;
  FBkMode := bk_Opaque;
  FBrush := 0;
  FCursor := crDefault;
  FCursorHandle := LoadCursor(0,IDC_ARROW);
  FFont := TFont.Create;
  FFont.FControl := Self;
  FCList := nil;
  FWList := nil;
  FEnabled := true;
  FOnClick := nil;
  FOnErase := nil;
  FOnHitTest := nil;
  FOnMouseDown := nil;
{<kvv>}
  FOnMenuItemSelect := nil;
{</kvv>}
end;

function TWinControl.GetParentHandle : HWnd;
begin
  if FParent <> nil then Result := FParent.FHandle
                    else Result := FParentHandle;
end;

procedure TWinControl.SetParentHandle(Value: HWnd);
begin
  if FParent = nil then FParentHandle := Value
                   else FParentHandle := FParent.FHandle;
end;

procedure TWinControl.SetBounds(R : TRect);
var flags : DWORD;
begin
  flags := SWP_NOZORDER;
  if FVisible then flags := flags or SWP_DRAWFRAME or SWP_SHOWWINDOW;
  if FHandle <> 0 then
    SetWindowPos(FHandle,0,R.Left,R.Top,R.Right-R.Left,R.Bottom-R.Top,flags);
  FLeft := R.Left;
  FTop := R.Top;
  FWidth := R.Right - R.Left;
  FHeight := R.Bottom - R.Top;
end;

procedure TWinControl.SetLeft(Value : integer);
var R : TRect;
begin
  if FLeft = Value then Exit;
  FLeft := Value;
  R.Left := FLeft; R.Right := R.Left + FWidth;
  R.Top := FTop; R.Bottom := R.Top + FHeight;
  SetBounds(R);
end;

procedure TWinControl.SetTop(Value : integer);
var R : TRect;
begin
  if FTop = Value then Exit;
  FTop := Value;
  R.Left := FLeft; R.Right := R.Left + FWidth;
  R.Top := FTop; R.Bottom := R.Top + FHeight;
  SetBounds(R);
end;

procedure TWinControl.SetWidth(Value : integer);
var R : TRect;
begin
  if FWidth = Value then Exit;
  FWidth := Value;
  R.Left := FLeft; R.Right := R.Left + FWidth;
  R.Top := FTop; R.Bottom := R.Top + FHeight;
  SetBounds(R);
end;

procedure TWinControl.SetHeight(Value : integer);
var R : TRect;
begin
  if FHeight = Value then Exit;
  FHeight := Value;
  R.Left := FLeft; R.Right := R.Left + FWidth;
  R.Top := FTop; R.Bottom := R.Top + FHeight;
  SetBounds(R);
end;

procedure TWinControl.SetFont(const AFont : TLogFont);
var fOld : hFont;
begin
  if FHandle <= 0 then Exit;
  fOld := SendMessage(FHandle, WM_GETFONT, 0, 0);
  FFont.FHandle := CreateFontIndirect(AFont);
  SendMessage(FHandle,WM_SETFONT,WParam(FFont.FHandle),MAKELPARAM(Word(TRUE),0));
  if fOld <> 0 then DeleteObject(fOld);
  ProcessMessages;
end;

procedure TWinControl.SetEnabled(Value: boolean);
begin
  FEnabled := Value;
  if FHandle > 0 then Windows.EnableWindow(FHandle, Value);
end;

function TWinControl.GetText : shortstring;
begin
  if FHandle > 0 then
  begin
   FTextBuf[0] := chr(SendMessage(FHandle,WM_GETTEXTLENGTH,0,0)+1);
   SendMessage(FHandle,WM_GETTEXT,ord(FTextBuf[0]),Longint(@FTextBuf[1]));
   if FTextBuf[1] = #0 then FTextBuf[0] := #0;
  end;
  Result := FTextBuf;
  if Result[0] > #0 then
    if Result[Ord(Result[0])] = #0 then Dec(Result[0]);
end;

procedure TWinControl.SetText(const Value : shortstring);
begin
  FTextBuf := Value;
  if FHandle > 0 then
  begin
    FTextBuf := FTextBuf + #0;
    SendMessage(FHandle,WM_SETTEXT,0,Longint(@FTextBuf[1]));
  end;
end;

function TWinControl.GetClientRect : TRect;
begin
  Windows.GetClientRect(FHandle,Result);
end;

function TWinControl.GetClientWidth : integer;
var R : TRect;
begin
  Windows.GetClientRect(FHandle,R);
  Result := R.Right - R.Left;
end;

function TWinControl.GetClientHeight : integer;
var R : TRect;
begin
  Windows.GetClientRect(FHandle,R);
  Result := R.Bottom - R.Top;
end;

procedure TWinControl.SetVisible(Value : boolean);
begin
  FVisible := Value;
  if FHandle = 0 then Exit;
  if FVisible then Show
              else Hide;
end;

procedure TWinControl.SetCursor(Value : TCursor);
const
  CursorMap: array[crSizeAll..crArrow] of PChar = (
    IDC_SIZEALL, IDC_HANDPT, IDC_HELP, IDC_APPSTARTING, IDC_NO, IDC_SQLWAIT,
    IDC_MULTIDRAG, IDC_VSPLIT, IDC_HSPLIT, IDC_NODROP, IDC_DRAG, IDC_WAIT,
    IDC_UPARROW, IDC_SIZEWE, IDC_SIZENWSE, IDC_SIZENS, IDC_SIZENESW, IDC_SIZE,
    IDC_IBEAM, IDC_CROSS, IDC_ARROW);
var
  Instance: THandle;
begin
  if Value = FCursor then Exit;
  if ((Value >= crSqlWait) and (Value <= crDrag)) or
     (Value = crHandPoint) then Instance := HInstance
                           else Instance := 0;
  FCursorHandle := LoadCursor(Instance, CursorMap[Value]);
  if FHandle <> 0 then PostMessage(FHandle, WM_SetCursor, FHandle, HTCLIENT);
end;

procedure TWinControl.Close;
begin
  SendMessage(FHandle, WM_CLOSE, 0, 0);
end;

procedure TWinControl.WMDestroy(var AMsg: TWMDestroy);
begin
  if Assigned(FOnDestroy) then FOnDestroy(Self);
  if FAutoStop then PostQuitMessage(0);
end;

procedure TWinControl.WMClose(var AMsg: TWMClose);
begin
  if not Assigned(FOnClose) or FOnClose(Self) then
  begin
    if FModalResult = 0 then FModalResult := mrCancel;
    with TMessage(AMsg) do
      DefWindowProc(FHandle, Msg, WParam, LParam);
  end;
  AMsg.Result := 0;
end;

procedure TWinControl.WMNCHitTest(var AMsg : TMessage);
begin
  Dispatch(AMsg);
  if FHTest <> 0 then AMsg.Result := FHTest
                 else
  if Assigned(FOnHitTest) then
    with TWMNCHitTest(AMsg) do  FOnHitTest(Self,XPos,YPos,Result)
                           else
    with AMsg do Result := DefWindowProc(FHandle,Msg,WParam,LParam);
end;

procedure TWinControl.WMPaint(var AMsg: TWMPaint);
var
  PaintStruct: TPaintStruct;
  PaintDC: HDC;
  pc : PControlList;
begin
  Dispatch(AMsg);
  if AMsg.Result <> 0 then Exit;
  PaintDC := BeginPaint(FHandle, PaintStruct);
  if FHandle > 0 then
  begin
    if FCList <> nil then
    begin
      pc := FCList;
      repeat
        pc^.Control.Paint(PaintDC);
        if pc^.Next <> nil then pc := pc^.Next
                           else pc := nil;
      until (pc = nil);
    end;
  end;
  EndPaint(FHandle, PaintStruct);
end;

procedure TWinControl.WMSetFocus(var AMsg : TWMSetFocus);
begin
  Dispatch(AMsg);
  if (FActiveControl <> nil) and
     (FActiveControl.IsModal) then
     begin
       AMsg.Result := 0;
       PostMessage(AMsg.FocusedWnd,WM_SETFOCUS,0,0);
       Exit;
     end;
  if FParent <> nil then
  FParent.FActiveControl := Self;
end;

procedure TWinControl.WMKillFocus(var AMsg : TWMKillFocus);
var r   : TRect;
    s   : shortstring;
    wnd : HWND;
begin
  Dispatch(AMsg);
  if ((WS_CHILD and FStyle) <> 0) and
    (GetWindowInstance(AMsg.FocusedWnd) <> nil) and
    not GetWindowInstance(AMsg.FocusedWnd).FEnabled then
  begin
    AMsg.Result := 0;
    SetFocus;
    if FParent <> nil then FParent.FActiveControl := Self;
  end                                               else
  if GetWindowInstance(AMsg.FocusedWnd) = nil then
  begin // an "external" window receives focus:
        // any such window must have no parent (but may have childs)
        // except for MessageBox window (which is analyzied)
    wnd := AMsg.FocusedWnd;
    repeat
      s[0] := chr(GetClassName(wnd,@s[1],255));
      if (s[0] > #0) and (s[ord(s[0])] = #0) then Dec(s[0]);
      if (s[1] = '#') then break;
      if GetParent(wnd) <> 0 then wnd := GetParent(wnd);
    until (GetParent(wnd) = 0);
    GetWindowRect(wnd,r);
    r.Left := (Screen.Width + r.Left - r.Right) div 2;
    r.Top := (Screen.Height + r.Top - r.Bottom) div 2;
    SetWindowPos(wnd,
                 0,
                 r.Left,
                 r.Top,
                 0,
                 0,
                 SWP_NOZORDER or SWP_NOSIZE or SWP_DRAWFRAME);
    AMsg.Result := 0;
  end;
end;

procedure TWinControl.WMEraseBkgnd(var AMsg : TWMEraseBkgnd);
var R : TRect;
    hd : HDC;
begin
    Windows.GetClientRect(FHandle,R);
    hd := AMsg.DC;
    if Assigned(FOnErase) then
    begin
      FOnErase(Self, hd, R);
      AMsg.Result := 1;
    end                   else
    if (FBkMode = bk_OPaque) or (FParent = nil) then
      if FBrush = 0 then
        Dispatch(TMessage(AMsg))
                    else
      begin
        FillRect(hd,R,FBrush);
        AMsg.Result := 1;
      end                                       else
    if FBkMode = bk_Transparent then
      begin
        FillRect(hd,R,FParent.FBrush);
        AMsg.Result := 1;
      end                       else AMsg.Result := 1;
end;

procedure TWinControl.WMCtlColor(var AMsg : TMessage);
var ctl : TWinControl;
begin
  with AMsg do
  begin
   ctl := TWinControl(GetProp(HWND(LParam),ID_SELF));
   if ctl = nil then Exit;
   Windows.SetBkColor(HDC(WParam),ctl.FColor);
   Windows.SetTextColor(HDC(WParam),ctl.FTextColor);
   case ctl.FBkMode of
     bk_Opaque:
       begin
         Windows.SetBkMode(HDC(WParam),OPAQUE);
         Result := ctl.FBrush;
       end;
     bk_Transparent,bk_Slide:
       begin
         Windows.SetBkMode(HDC(WParam),TRANSPARENT);
         repeat
           ctl := ctl.FParent;
         until ctl.FBrush > 0;
         Result := ctl.FBrush;
       end;
   end;
  end;
end;

procedure TWinControl.WMCommand(var AMsg : TWMCommand);
var ctrl : TWinControl;
begin
  Dispatch(AMsg);
  with AMsg do
  begin
   ctrl := TWinControl(GetProp(ctl,ID_SELF));
{<kvv>}
   if ctrl = nil then // this is menu command
   begin
     if Ctl = 0 then 
       if Assigned(FOnMenuItemSelect) then 
         FOnMenuItemSelect(Self,TMessage(AMsg).wParam);
     Exit;
   end;
{</kvv>}
   case NotifyCode of
     BN_CLICKED,
     LBN_DBLCLK : if Ctrl.FEnabled then ctrl.Click;
   end;
   case NotifyCode of
     EN_CHANGE,
     LBN_SELCHANGE : if Ctrl.FEnabled then ctrl.Change;
   end;
   case NotifyCode of
     BN_SETFOCUS,
     EN_SETFOCUS,
     LBN_SETFOCUS,
     CBN_SETFOCUS  : if Ctrl.FEnabled then ctrl.DoEnter;
   end;
   case NotifyCode of
     BN_KILLFOCUS,
     EN_KILLFOCUS,
     LBN_KILLFOCUS,
     CBN_KILLFOCUS : if Ctrl.FEnabled then ctrl.DoExit;
   end;
  end;
end;

procedure TWinControl.DoMouseDown(var AMsg: TWMMouse; Button: TMouseButton;
  Shift: TShiftState);
begin
  Dispatch(AMsg);
  with AMsg do
    if Assigned(FOnMouseDown) then
      FOnMouseDown(Self,
                   Button,
                   KeysToShiftState(Keys) + Shift,
                   XPos,
                   YPos);
end;

procedure TWinControl.WMLButtonDown(var AMsg: TWMLButtonDown);
begin
  DoMouseDown(AMsg, mbLeft, []);
end;

procedure TWinControl.WMLButtonDblClk(var AMsg: TWMLButtonDblClk);
begin
  DoMouseDown(AMsg, mbLeft, [ssDouble]);
end;

procedure TWinControl.WMRButtonDown(var AMsg: TWMRButtonDown);
begin
  DoMouseDown(AMsg, mbRight, []);
end;

procedure TWinControl.WMRButtonDblClk(var AMsg: TWMRButtonDblClk);
begin
  DoMouseDown(AMsg, mbRight, [ssDouble]);
end;

procedure TWinControl.WMMouseMove(var AMsg: TWMMouseMove);
begin
  Dispatch(AMsg);
  with AMsg do
    if Assigned(FOnMouseMove) then
      FOnMouseMove(Self,
                   KeysToShiftState(Keys),
                   XPos,
                   YPos);
end;

procedure TWinControl.DoMouseUp(var AMsg: TWMMouse; Button: TMouseButton;
  Shift: TShiftState);
begin
  Dispatch(AMsg);
{$IFDEF CaptureMouse}
  ReleaseCapture;
{$ENDIF}
  with AMsg do
  if Assigned(FOnMouseUp) then
    FOnMouseUp(Self,
               Button,
               KeysToShiftState(Keys) + Shift,
               XPos,
               YPos);
end;

procedure TWinControl.WMLButtonUp(var AMsg: TWMLButtonUp);
begin
  DoMouseUp(AMsg, mbLeft, []);
end;

procedure TWinControl.WMRButtonUp(var AMsg: TWMRButtonUp);
begin
  DoMouseUp(AMsg, mbRight, []);
end;

procedure TWinControl.WMSetCursor(var AMsg: TWMSetCursor);
begin
  if (FCursor <> crDefault) and
     (AMsg.HitTest = HTCLIENT) then
  begin
    Windows.SetCursor(FCursorHandle);
    AMsg.Result := 1;
  end                          else Dispatch(AMsg);
end;

function TWinControl.DoKeyDown(var AMsg: TWMKey): Boolean;
var
  ShiftState: TShiftState;
  Form: TWinControl;
begin
  Result := True;
  Form := Self;
  while (Form.FClassName <> FormClassName) and
        (Form.Parent <> nil) do Form := Form.Parent;
  if (Form <> Self) and Form.DoKeyDown(AMsg) then Exit;
  with AMsg do
  begin
    ShiftState := KeyDataToShiftState(KeyData);
    if CharCode = VK_Tab  then
    begin
      if (ssShift in ShiftState) then
      begin
        while (Form.FClassName <> FormClassName) and
              Form.IsFirstSelected and
              (Form.FParent <> nil) do Form := Form.FParent;
        Form.SelectPrev;
        if Assigned(FOnKeyDown) then FOnKeyDown(Self, CharCode, ShiftState);
        Exit;
      end                        else
      begin
        while (Form.FClassName <> FormClassName) and
              Form.IsLastSelected and
              (Form.FParent <> nil) do Form := Form.FParent;
        Form.SelectNext;
        if Assigned(FOnKeyDown) then FOnKeyDown(Self, CharCode, ShiftState);
        Exit;
      end;
    end;
    if Assigned(FOnKeyDown) then FOnKeyDown(Self, CharCode, ShiftState);
    if CharCode = 0 then Exit;
  end;
  Result := False;
end;

procedure TWinControl.WMKeyDown(var AMsg: TWMKeyDown);
begin
  if not DoKeyDown(AMsg) then Dispatch(AMsg);
end;

procedure TWinControl.WMSysKeyDown(var AMsg: TWMKeyDown);
begin
  if not DoKeyDown(AMsg) then Dispatch(TMessage(AMsg));
end;

function TWinControl.DoKeyUp(var AMsg: TWMKey): Boolean;
var
  ShiftState: TShiftState;
  Form: TWinControl;
begin
  Result := True;
  Form := Self;
  while Form.Parent <> nil do Form := Form.Parent;
  if (Form <> Self) and Form.DoKeyUp(AMsg) then Exit;
  with AMsg do
  begin
    ShiftState := KeyDataToShiftState(KeyData);
    if Assigned(FOnKeyUp) then FOnKeyUp(Self, CharCode, ShiftState);
    if CharCode = 0 then Exit;
  end;
  Result := False;
end;

procedure TWinControl.WMKeyUp(var AMsg: TWMKeyUp);
begin
  if not DoKeyUp(AMsg) then Dispatch(AMsg);
end;

procedure TWinControl.WMSysKeyUp(var AMsg: TWMKeyUp);
begin
  if not DoKeyUp(AMsg) then Dispatch(AMsg);
end;

function TWinControl.DoKeyPress(var AMsg: TWMKey): Boolean;
var
  Form: TWinControl;
begin
  Result := True;
  Form := Self;
  while Form.Parent <> nil do Form := Form.Parent;
  if (Form <> Self) and Form.DoKeyPress(AMsg) then Exit;
  with AMsg do
  begin
    if Assigned(FOnKeyPress) then FOnKeyPress(Self,Char(CharCode));
    if Char(CharCode) = #0 then Exit;
  end;
  Result := False;
end;

procedure TWinControl.WMChar(var AMsg: TWMChar);
begin
  if not DoKeyPress(AMsg) then Dispatch(AMsg);
end;

procedure TWinControl.WMSysCommand(var AMsg: TWMSysCommand);
begin
  Dispatch(AMsg);
end;

procedure TWinControl.WMNotifyIcon(var AMsg: TMessage);
begin
  case AMsg.LParam of
   WM_MOUSEMOVE   :if Assigned(FOnNIMove) then FOnNIMove(Self);
   WM_LBUTTONDOWN :if Assigned(FOnNILDown) then FOnNILDown(Self);
   WM_LBUTTONUP   :if Assigned(FOnNILUp) then FOnNILUp(Self);
  end;
end;

procedure TWinControl.WMQueryEndSession(var AMsg: TMessage);
begin
  if Assigned(FOnEndSession) then
     if FOnEndSession(Self) then AMsg.Result := 1
                            else AMsg.Result := 0
                             else Dispatch(AMsg);
end;

procedure TWinControl.Dispatch(var AMsg);
begin
   inherited Dispatch(AMsg);
   with TMessage(AMsg) do
   begin
     if TMessage(AMsg).Result <> 0 then Exit;
     if FDefWndProc <> 0 then
       Result := CallWindowProc(Ptr(FDefWndProc),
                                FHandle,
                                Msg,
                                WParam,
                                LParam)
                         else
       Result := DefWindowProc(FHandle,Msg,WParam,LParam);
   end;
end;

procedure TWinControl.Change;
begin
  if Assigned(FOnChange) then FOnChange(Self);
end;

procedure TWinControl.Click;
begin
  if Assigned(FOnClick) then FOnClick(Self);
end;

procedure TWinControl.DoEnter;
begin
  if Assigned(FOnEnter) then FOnEnter(Self);
end;

procedure TWinControl.DoExit;
begin
  if Assigned(FOnExit) then FOnExit(Self);
end;

procedure TWinControl.SetColor(Value: TColor);
var tb,ob : HBrush;
begin
  if FHandle > 0 then
  begin
    tb := CreateSolidBrush(Value);
    ob := SelectObject(FDC,tb);
    DeleteObject(ob);
    FBrush := tb;
  end            else
  begin
    if FBrush > 0 then DeleteObject(FBrush);
    FBrush := CreateSolidBrush(Value);
  end;
  FColor := Value;
end;

procedure TWinControl.SetTextColor(Value: TColor);
begin
  Windows.SetTextColor(FDC,Value);
  FTextColor := Value;
end;

procedure TWinControl.WMHelp(var AMsg: TMessage);
var hi : PHelpInfo;
    W  : TWinControl;
    s  : shortstring;
begin
  hi := Ptr(AMsg.lparam);
  if hi^.dwContextId = 0 then // исходная точка
  begin
    W := TWinControl(GetProp(hi^.hItemHandle,ID_SELF));
    if W.FHelpContext > 0 then
    begin
      hi^.dwContextId := W.FHelpContext;
      while (W.FStyle and ws_Child <> 0) and
            (W.FParent <> nil) do W := W.FParent;
      SendMessage(W.FHandle,WM_HELP,0,AMsg.lparam);
    end;
  end                    else
  if FStyle and ws_Child = 0 then // если родительское окно
  begin
    s := FHelpFile + #0;
    WinHelp(FHandle,@s[1],HELP_CONTEXT,hi^.dwContextId);
  end;
  AMsg.Result := 1;
end;

procedure TWinControl.ProcessMessage(var AMsg: TMessage);
begin
  case AMsg.Msg of
    wm_Destroy: WMDestroy(TWMDestroy(AMsg));
    wm_Close: WMClose(TWMClose(AMsg));
    wm_Paint: WMPaint(TWMPaint(AMsg));
    wm_EraseBkgnd: WMEraseBkgnd(TWMEraseBkgnd(AMsg));
    wm_CtlColorBtn,
    wm_CtlColorListBox,
    wm_CtlColorStatic,
    wm_CtlColorEdit: WMCtlColor(AMsg);
    wm_NCHitTest : WMNCHitTest(AMsg);
    wm_Command: WMCommand(TWMCommand(AMsg));
    wm_SEtFocus: WMSetFocus(TWMSetFocus(AMsg));
    wm_KillFocus: WMKillFocus(TWMKillFocus(AMsg));
    wm_LButtonDown: WMLButtonDown(TWMLButtonDown(AMsg));
    wm_RButtonDown: WMRButtonDown(TWMRButtonDown(AMsg));
    wm_LButtonDblClk: WMLButtonDblClk(TWMLButtonDblClk(AMsg));
    wm_RButtonDblClk: WMRButtonDblClk(TWMRButtonDblClk(AMsg));
    wm_MouseMove: WMMouseMove(TWMMouseMove(AMsg));
    wm_LButtonUp: WMLButtonUp(TWMLButtonUp(AMsg));
    wm_RButtonUp: WMRButtonUp(TWMRButtonUp(AMsg));
    wm_SetCursor: WMSetCursor(TWMSetCursor(AMsg));
    wm_KeyDown: WMKeyDown(TWMKeyDown(AMsg));
    wm_SysKeyDown: WMSysKeyDown(TWMKeyDown(AMsg));
    wm_KeyUp: WMKeyUp(TWMKeyUp(AMsg));
    wm_SysKeyUp: WMSysKeyUp(TWMKeyUp(AMsg));
    wm_Char: WMChar(TWMChar(AMsg));
    wm_SysCommand: WMSysCommand(TWMSysCommand(AMsg));
    wm_NotifyIcon: WMNotifyIcon(AMsg);
    wm_QueryEndSession: WMQueryEndSession(AMsg);
    wm_Help: WMHelp(AMsg);
    else Dispatch(AMsg);
  end;
end;

procedure FindLastControl(var ppar,pson : PControlList);
var pp,pn : PControlList;
begin
   if ppar = nil then // if parent = nil
   begin
     pson := nil;     // then son = nil too
   end           else
   if ppar^.Next = nil then // if last in chain
   begin
     pson := ppar; // this is the last
     ppar := nil;  // and no parent
   end                else
   if ppar.Next^.Next = nil then // if pre-last
     begin
       pson := ppar^.Next;
     end                    else // if above then go down...
     begin
       repeat
         pp := ppar^.Next;
         pn := pp^.Next;
         if pn <> nil then
         begin
           ppar := pp; pson := pn;
         end;
       until pn^.Next = nil;
     end;
end;

procedure FindLastWindow(var ppar,pson : PWinControlList);
var pp,pn : PWinControlList;
begin
   if ppar = nil then // if parent = nil
   begin
     pson := nil;     // then son = nil too
   end           else
   if ppar^.Next = nil then // if last in chain
   begin
     pson := ppar; // this is the last
     ppar := nil;  // and no parent
   end                else
   if ppar^.Next^.Next = nil then // if pre-last
     begin
       pson := ppar^.Next;
     end                    else // if above then go down...
     begin
       repeat
         pp := ppar^.Next;
         pn := pp^.Next;
         if pn <> nil then
         begin
           ppar := pp; pson := pn;
         end;
       until pn^.Next = nil;
     end;
end;

destructor TWinControl.Destroy;
var wp,ws,wt : PWinControlList;
    cp,cs,ct : PControlList;
begin
  repeat
    wp := FWList;
    FindLastWindow(wp,ws);
    wt := ws;
    if ws <> nil then
    begin
      ws^.WinControl.Free;
      dispose(ws);
      if wp <> nil then wp^.Next := nil
                   else wt := nil;
    end;
  until (wt = nil);
  repeat
    cp := FCList;
    FindLastControl(cp,cs);
    ct := cs;
    if cs <> nil then
    begin
      cs^.Control.Free;
      dispose(cs);
      if cp <> nil then cp^.Next := nil
                   else ct := nil;
    end;
  until (ct = nil);
  FFont.Free;
  if FBrush <> 0 then DeleteObject(FBrush);
  DestroyWnd;
  ProcessMessages;
  inherited Destroy;
end;

procedure TWinControl.CreateParams(var Params: TCreateParams);
begin
  FillChar(Params, SizeOf(Params), 0);
  if FTextBuf[ord(FTextBuf[0])] <> #0 then FTextBuf := FTextBuf + #0;
  Params.Caption := @FTextBuf[1];
  Params.Style := FStyle;
  Params.ExStyle := FExStyle;
  with Params do
  begin
    X := FLeft;
    Y := FTop;
    Width := FWidth;
    if (FStyle and WS_CAPTION) > 0 then
     FHeight := FHeight + GetSystemMetrics(SM_CYCAPTION);
    Height := FHeight;
    WndParent := 0;
    WndParent := ParentHandle;
    WindowClass.style := CS_VREDRAW + CS_HREDRAW + CS_DBLCLKS;
    WindowClass.lpfnWndProc := GetWndProc;
    WindowClass.hIcon := LoadIcon(HInstance, 'MAINICON');
    WindowClass.hCursor := FCursorHandle;
    if FBrush = 0 then FBrush := CreateSolidBrush(FColor);
    WindowClass.hbrBackground := FBrush;
    StrPCopy(WinClassName, FClassName);
  end;
end;

procedure TWinControl.CreateWnd;
var
  Params: TCreateParams;
  TempClass: TWndClass;
  ClassRegistered : boolean;
begin
  CreateParams(Params);
  with Params do
  begin
    ClassRegistered := GetClassInfo(HInstance, WinClassName, TempClass);
    if not ClassRegistered then
    begin
      WindowClass.lpfnWndProc := GetWndProc;
      WindowClass.hInstance := HInstance;
      WindowClass.lpszClassName := WinClassName;
      if Windows.RegisterClass(WindowClass) = 0 then
      begin
        MessageBox(0, 'WinRegister failed', nil, mb_Ok);
        halt;
      end;
    end;
    CreateWindowHandle(Params);
  end;
//  Invalidate;
end;

procedure TWinControl.CreateWindowHandle(const Params: TCreateParams);
begin
  FHandle := CreateWindowEx(
    FExStyle,
    Params.WinClassName,
    @FTextBuf[1],
    FStyle,
    FLeft, FTop, FWidth, FHeight,
    Params.WndParent,
    0,
    HInstance,
    nil
  );
  if FHandle = 0 then
  begin
      MessageBox(0, 'WinCreate failed', nil, mb_Ok);
      halt;
  end;
  SetProp(FHandle,ID_SELF,THandle(Self));
  Windows.EnableWindow(FHandle, FEnabled);
  if (FParent = nil) and (MainWindow = nil) then MainWindow := Self;
  if Assigned(FOnCreate) then FOnCreate(Self);
  if FFont <> nil then
    FFont.UpdateFont;
//  Windows.SetCursor(FCursorHandle);
  if Visible then Show;
end;

procedure TWinControl.DestroyWnd;
begin
  DestroyWindowHandle;
end;

procedure TWinControl.DestroyWindowHandle;
begin
  RemoveProp(FHandle,ID_SELF);
  DestroyWindow(FHandle);
  if MainWindow = Self then MainWindow := nil;
end;

procedure TWinControl.Show;
begin
  ShowWindow(FHandle, SW_SHOW);
  UpdateWindow(FHandle);
end;

procedure TWinControl.Hide;
begin
  ShowWindow(FHandle, SW_HIDE);
end;

function TWinControl.IsParentHandle(AHandle : HWnd) : boolean;

  function FindHandle(Ctrl : TWinControl; Wnd : HWnd) : boolean;
  var pp,pn : pointer;
  begin
   Result := false;
   if Wnd = Ctrl.FHandle then // нашли самого
   begin
     Result := true; Exit;
   end;
   if (Ctrl.FWList = nil) or
      (Ctrl.FWList^.WinControl = nil) then Exit; // нет детей
   pp := Ctrl.FWList;
   repeat
     if PWinControlList(pp)^.Wincontrol.FHandle = Wnd then // нашли самого
     begin
       Result := true; Exit;
     end;
     if PWinControlList(pp)^.Wincontrol.FWList <> nil then // есть дети
     begin
       if FindHandle(PWinControlList(pp)^.Wincontrol, Wnd) then
       begin
         Result := true; Exit;
       end;
     end;
     pn := PWinControlList(pp)^.Next;
     if pn <> nil then pp := pn;
   until (pn = nil);
  end;

begin
   Result := false;
   if (AHandle = INVALID_HANDLE_VALUE) or
      (FParent = nil) or
      (FParent.FWList = nil) or
      (FParent.FWList^.WinControl = nil) then Exit;
   Result := FindHandle(FParent, AHandle);
end;

function TWinControl.ProcessMsg(var Msg: TMsg): Boolean;
begin
  Result := False;
  if PeekMessage(Msg, 0, 0, 0, PM_REMOVE) then
  begin
    Result := True;
    if Msg.Message <> WM_QUIT then
    begin
      TranslateMessage(Msg);
      DispatchMessage(Msg);
    end
    else
      Dispatch(Msg);
  end;
end;

procedure TWinControl.ProcessMessages;
var
  Msg: TMsg;
begin
  while ProcessMsg(Msg) do {loop};
end;

function TWinControl.ShowModal : TModalResult;
var AMessage : TMsg;
begin
  FIsModal := true;
  FModalResult := 0;
  while FModalResult = 0 do
  begin
    GetMessage(AMessage, 0, 0, 0);
    TranslateMessage(AMessage);
    if (FParent = nil) or
       (AMessage.message = WM_PAINT) or
       (AMessage.message = WM_QUIT) or
       not IsParentHandle(AMessage.hwnd) then DispatchMessage(AMessage);
  end;
  if (FModalResult = 0) then Result := TModalResult(AMessage.WParam)
                        else Result := FModalResult;
  FModalResult := 0;
  FIsModal := false;
end;

procedure TWinControl.EndModal(Value : TModalResult);
begin
  if FIsModal then FModalresult := Value;
end;

procedure TWinControl.Invalidate;
begin
  if Self.FParent = nil then
     ShowWindow(FHandle, CmdShow);
  InvalidateRect(FHandle,nil,true);
  UpdateWindow(FHandle);
end;

procedure TWinControl.SetFocus;
begin
  Windows.SetFocus(FHandle);
end;

procedure TWinControl.InsertControl(AControl : TControl);
var pn : PControlList;
    cp,cs : PControlList;
begin
   pn := new(PControlList);
   pn^.Control := AControl;
   pn^.Next := nil;
   FindLastControl(cp,cs);
   if cs = nil then FCList := pn
               else cs^.Next := pn;
   Invalidate;
end;

procedure TWinControl.InsertWinControl(AControl : TWinControl);
var pn : PWinControlList;
    wp,ws : PWinControlList;
begin
  pn := new(PWinControlList);
  pn^.WinControl := AControl;
  pn^.Next := nil;
  wp := FWList;
  FindLastWindow(wp,ws);
  if ws = nil then FWList := pn
              else ws^.Next := pn;
end;

procedure FindWindow(pl    : PWinControlList;
                     pp    : TWinControl;
                 Var pprev : TWinControl;
                 Var pnext : TWinControl);
var p,temp : PWinControlList;
begin
   pprev := nil;
   pnext := nil;
   if pl <> nil then
   begin
     if (pp = nil) or
        ((pp = pl^.WinControl)and (pl^.Next = nil)) then
     begin
       pprev := pp;
       pnext := pp;
       Exit;
     end;
     p := pl;
     repeat
       if p^.WinControl = pp then // is found
       begin
         if p^.Next = nil then                    // the last
           pnext := pl^.WinControl                // the first will be next
                          else
           pnext := p^.Next^.WinControl;
          p := pl;
          if p^.WinControl = pp then                 // the first
          begin
            temp := p;
            FindLastWindow(temp,pl);
            pprev := pl^.WinControl  // the last will be previous
          end                   else
          begin
            while (p^.Next^.WinControl <> pp) do p := p^.Next;
            pprev := p^.WinControl;
          end;
          Exit;
       end;
       p := p^.Next;
     until false;
   end;
end;

procedure TWinControl.SelectPrev;
var pp,pn : TWinControl;
begin
  if FActiveControl = nil then SelectFirst
                          else
  begin
    FindWindow(FWList,FActiveControl,pp,pn);
    if pp <> nil then
    begin
      FActiveControl := pp;
      if pp.FEnabled and  pp.FTabStop then pp.SetFocus
                                      else
        while not FActiveControl.FEnabled or
            not FActiveControl.FTabStop do SelectPrev;
    end;
  end;
end;

procedure TWinControl.SelectNext;
var pp,pn : TWinControl;
begin
  if FActiveControl = nil then SelectFirst
                          else
  begin
    FindWindow(FWList,FActiveControl,pp,pn);
    if pn <> nil then
    begin
      FActiveControl := pn;
      if pn.FEnabled and  pn.FTabStop then pn.SetFocus
                     else
      while not FActiveControl.FEnabled or
            not FActiveControl.FTabStop do SelectNext;
    end;
  end;
end;

procedure TWinControl.SelectFirst;
var pp : PWinControlList;
begin
  if (FWList <> nil) then
  begin
    pp := FWList;
    FActiveControl := pp^.WinControl;
    if pp^.WinControl.FEnabled then
    begin
      pp^.WinControl.SetFocus;
      FActiveControl := pp^.WinControl;
    end                        else
      while not FActiveControl.FEnabled do SelectNext;
  end;
end;

procedure TWinControl.SelectLast;
var pp,temp : PWinControlList;
begin
  if (FWList <> nil) then
  begin
    temp := FWList;
    FindLastWindow(temp,pp);
    if pp = nil then Exit;
    if pp^.WinControl <> nil then
    begin
      if pp^.WinControl.FEnabled then
      begin
        pp^.WinControl.SetFocus;
        FActiveControl := pp^.WinControl;
      end                        else
        while not FActiveControl.FEnabled do SelectPrev;
    end;
  end;
end;

function TWinControl.IsFirstSelected : boolean;
begin
  Result := (FActiveControl <> nil) and
            (FActiveControl = FWList^.WinControl);
end;

function TWinControl.IsLastSelected : boolean;
var pp,ps : PWinControlList;
begin
  Result := false;
  if FActiveControl = nil then Exit;
  pp := FWList;
  FindLastWindow(pp,ps);
  if ps = nil then Exit;
  Result := ps^.WinControl = FActiveControl;
end;

{TStdControl}

procedure TStdControl.CreateWnd;
begin
    if FCtl3D then
    begin
      FExStyle := FExStyle or ws_Ex_ClientEdge;
      FStyle := FStyle and not ws_Border;
    end;
    if FBkMode in [bk_Transparent,bk_Slide] then
      FExStyle := FExStyle or WS_EX_TRANSPARENT;
    if FTextBuf[ord(FTextBuf[0])] <> #0 then FTextBuf := FTextBuf + #0;
    FHandle := CreateWindowEx(
      FExStyle,
      PChar(FClassName),
      @FTextBuf[1],
      FStyle or ws_Child or ws_Visible,
      FLeft, FTop, FWidth, FHeight,
      ParentHandle,
      0,
      HInstance,
      nil);
    if FHandle = 0 then
    begin
      MessageBox(0, 'StdCreate failed', nil, mb_Ok);
      halt;
    end;
    SetProp(FHandle,ID_SELF,THandle(Self));
    FDefWndProc := GetWindowLong(FHandle,GWL_WNDPROC);
    SetWindowLong(FHandle,GWL_WNDPROC,Longint(GetWndProc));
    Windows.EnableWindow(FHandle, FEnabled);
    if FFont <> nil then FFont.UpdateFont;
//    Windows.SetCursor(FCursorHandle);
end;

{TLabel}

constructor TLabel.Create(AParent: TWinControl);
begin
  inherited Create(AParent);
  FWidth := 121;
  FHeight := 25;
  FBkMode := bk_Transparent;
  FFormat := DT_VCENTER or DT_WORDBREAK;
  FClassName := 'STATIC';
  FStyle := ws_Child or ws_Visible;
  FOnHitTest := HitTest;
end;

procedure TLabel.WMPaint(var AMsg: TWMPaint);
var
   DC : HDC;
   ps : TPaintStruct;
   PC : PChar;
   L  : Cardinal;
   R  : TRect;
   fo : HFont;
begin
  if FBkMode <> bk_Slide then Dispatch(AMsg)
                         else
  begin
    L := SendMessage(FHandle,WM_GETTEXTLENGTH,0,0)+1;
    PC := PChar(GlobalAlloc(GMEM_FIXED, L));
    SendMessage(FHandle,WM_GETTEXT,L,Longint(PC));
    R.Left := 0;        R.Top := 0;
    R.Right := Width-1; R.Bottom := Height-1;
    DC := BeginPaint(FHandle,ps);
    SetBkMode(DC,TRANSPARENT);
    fo :=SelectObject(DC,FFont.FHandle);
    Windows.SetBkColor(DC,FColor);
    Windows.SetTextColor(DC,FTextColor);
    if (FStyle and SS_CENTER) = SS_CENTER then
      FFormat := FFormat or DT_CENTER     else
    if (FStyle and SS_RIGHT) = SS_RIGHT then
      FFormat := FFormat or DT_RIGHT;
    DrawTextEx(DC,      // handle to device context
               PC,      // pointer to string to draw
               L-1,     // length of string to draw
               R,       // pointer to rectangle coordinates
               FFormat, // formatting options
               nil      // pointer to structure for more options
               );
    SelectObject(DC,fo);
    EndPaint(FHandle,ps);
    GlobalFree(Cardinal(PC));
  end;
end;

procedure TLabel.WMEraseBkgnd(var AMsg : TWMEraseBkgnd);
begin
  if FBkMode <> bk_Slide then inherited;
end;

procedure TLabel.HitTest(Sender: TObject; X, Y : integer;
                         var Result : integer);
begin
  Result := HTTRANSPARENT;
end;

{TEdit}

constructor TEdit.Create(AParent: TWinControl);
begin
  inherited Create(AParent);
  FWidth := 121;
  FHeight := 24;
  FClassName := 'EDIT';
  FStyle := ws_Child or ws_Border;
  FTabStop := true;
end;

function TEdit.DoKeyPress(var AMsg: TWMKey): Boolean;
begin
  Result := inherited DoKeyPress(AMsg) or (Char(AMsg.CharCode) = #9);
end;

function TEdit.GetMaxLength : integer;
begin
  Result := SendMessage(FHandle,EM_GETLIMITTEXT,0,0);
end;

procedure TEdit.SetMaxLength(Value : integer);
begin
  SendMessage(FHandle,EM_SETLIMITTEXT,Value,0);
end;

function TEdit.GetMargin : word;
begin
  Result := Lo(SendMessage(FHandle,EM_GETMARGINS,0,0));
end;

procedure TEdit.SetMargin(Value: word);
begin
  SendMessage(FHandle,
              EM_SETMARGINS,
              EC_LEFTMARGIN or EC_RIGHTMARGIN,
              MakeLong(Value,Value));
end;

{<fduch> }
{ THotKey }
constructor THotKey.Create(AParent: TWinControl);
begin
  inherited Create(AParent);
  FWidth := 100;
  FHeight := 24;
  FClassName := HOTKEYCLASS;
  FStyle := ws_Child or ws_Border;
  FTabStop := true;
end;

function THotKey.GetHotKey: Byte;
var
  AHotKey:Word;
begin
  AHotKey:=SendMessage(FHandle, HKM_GETHOTKEY, 0, 0);
  FHotKey:=Lo(AHotKey);
  FMod:=Hi(AhotKey);
  Result:=FHotKey;
end;

function THotKey.GetModifiers: THKModifiers;
begin
  FModifiers:=[];
  if (FMod and HOTKEYF_ALT)<>0 then Include(FModifiers, hkAlt);
  if (FMod and HOTKEYF_CONTROL)<>0 then Include(FModifiers, hkCtrl);
  if (FMod and HOTKEYF_SHIFT)<>0 then Include(FModifiers, hkShift);
  if (FMod and HOTKEYF_EXT)<>0 then Include(FModifiers, hkExt);
  Result:=FModifiers;
end;

function THotKey.GetSHotKey: string;
begin
  if (hkCtrl in FModifiers) then Result:=Result+'Ctrl+';
  if (hkAlt in FModifiers) then Result:=Result+'Alt+';
  if (hkShift in FModifiers) then Result:=Result+'Shift+';
  Result:=Result+char(FHotKey);
end;

procedure THotKey.SetSHotKey(const Value: string);
var
  s, CurToken: string;
begin
  s:=Value;
  while Pos('+', S)>0 do
  begin
    CurToken:=UpperCase(Copy(S, 1, Pos('+', S)-1));
    Delete(S, 1, Pos('+', S));
    if CurToken='ALT' then Include(FModifiers, hkAlt);
    if CurToken='CTRL' then Include(FModifiers, hkCtrl);
    if CurToken='SHIFT' then Include(FModifiers, hkShift);
  end;
  HotKey:=ord(S[1]);
end;

procedure THotKey.SetHotKey(const Value: Byte);
begin
  SendMessage(FHandle, HKM_SETHOTKEY, MakeWord(Value, Fmod),0);
  FHotKey:=Value;
end;

procedure THotKey.SetInvalidKeys(const Value: THKInvalidKeys);
begin
  FInvalidKeys := Value;
  SendMessage(FHandle, HKM_SETRULES, Byte(Value), MakeLong(Byte(FModifiers), 0));
  SendMessage(FHandle, HKM_SETHOTKEY, MakeWord(FHotkey, Fmod),0);
end;

procedure THotKey.SetModifiers(const Value: THKModifiers);
begin
  FMod:=0;
  if hkAlt in Value then FMod:=FMod or HOTKEYF_ALT;
  if hkCtrl in Value then FMod:=FMod or HOTKEYF_CONTROL;
  if hkShift in Value then FMod:=FMod or HOTKEYF_SHIFT;
  if hkExt in Value then FMod:=FMod or HOTKEYF_Ext;
end;

function THotKey.GetModif: byte;
var
  AHotKey:Word;
begin
  AHotKey:=SendMessage(FHandle, HKM_GETHOTKEY, 0, 0);
  FHotKey:=Lo(AHotKey);
  FMod:=Hi(AHotKey);
  Result:=FMod;
end;

procedure THotKey.SetModif(const Value: byte);
begin
  SendMessage(FHandle, HKM_SETHOTKEY, MakeWord(FHotKey, Value),0);
  FMod:=Value;
end;
{</fduch>}

{TListBox}

constructor TListBox.Create(AParent: TWinControl);
begin
  inherited Create(AParent);
  FWidth := 120;
  FHeight := 99;
  FClassName := 'LISTBOX';
  FStyle := ws_child or ws_Border or lbs_Notify {or lbs_Sort} or
            lbs_NoIntegralHeight or ws_Visible;
  FTabStop := true;
end;

procedure TListBox.SetSorted(Value: boolean);
begin
  if Value then FStyle := FStyle or lbs_Sort
           else FStyle := FStyle and not lbs_Sort;
end;

function TListBox.GetCount: Integer;
begin
  Result := SendMessage(FHandle, LB_GETCOUNT, 0, 0);
end;

function TListBox.GetFocused: Integer;
begin
  Result := SendMessage(FHandle, LB_GETCARETINDEX, 0, 0);
end;

procedure TListBox.SetFocused(Value: Integer);
begin
  SendMessage(FHandle, LB_SETCARETINDEX, Value, MAKELPARAM(word(false),0));
  SendMessage(FHandle, LB_SETCURSEL, Value, 0);
end;

procedure TListBox.SelectItem(Value: integer);
begin
  SendMessage(FHandle, LB_SETCURSEL, Value, 0);
end;

function TListBox.Get(Index: Integer): shortstring;
var
  Text: shortstring;
begin
  Text[0] := chr(SendMessage(FHandle, LB_GETTEXT, Index, Longint(@Text[1])));
  Result := Text;
end;

function TListBox.GetObject(Index: Integer): TObject;
begin
  Result := nil;
  if (Index < 0) or (Index >= Count) then Exit;
  Result := TObject(SendMessage(FHandle, LB_GETITEMDATA, Index, 0));
  if Longint(Result) = LB_ERR then FError := -1;
end;

procedure TListBox.Put(Index: Integer; const S: shortstring);
begin
  if (Index < 0) or (Index > Count) then Exit;
  if Index = Count then
  begin
    Add(S); Exit;
  end;
  Delete(Index);
  Insert(Index,S);
end;

procedure TListBox.PutObject(Index: Integer; AObject: TObject);
begin
  if (Index < 0) or (Index >= Count) then Exit;
  SendMessage(FHandle, LB_SETITEMDATA, Index, Longint(AObject));
end;

function TListBox.Add(const S: shortstring): Integer;
var ss : array [1..256] of char;
begin
  Move(s[1],ss[1],Ord(s[0]));
  ss[Ord(s[0])+1] := #0;
  Result := SendMessage(FHandle, LB_ADDSTRING, 0, Longint(@ss));
  if Result < 0 then FError := -1;
  if Count = 1 then Focused := 0;
end;

procedure TListBox.Insert(Index: Integer; const S: shortstring);
var ss : array [1..256] of char;
begin
  if (Index < 0) or (Index > Count) then Exit;
  Move(s[1],ss[1],Ord(s[0]));
  ss[Ord(s[0])+1] := #0;
  if SendMessage(FHandle, LB_INSERTSTRING, Index,
    Longint(@Ss)) < 0 then FError := -1;
  if Count = 1 then Focused := 0;
end;

procedure TListBox.Delete(Index: Integer);
var cf, cc : integer;
begin
  if (Index < 0) or (Index >= Count) then Exit;
  cf := Focused;
  cc := Count;
  SendMessage(FHandle, LB_DELETESTRING, Index, 0);
  if Count = 0 then SelectItem(-1);
  if cf >= cc - 1 then Focused := cc - 2;
end;

procedure TListBox.Clear;
begin
  if Count <= 0 then Exit;
  SendMessage(FHandle, LB_RESETCONTENT, 0, 0);
  SelectItem(-1);
end;

{TComboBox}

constructor TComboBox.Create(AParent: TWinControl);
begin
  inherited Create(AParent);
  FWidth := 120;
  FHeight := 24;
  FClassName := 'COMBOBOX';
  FStyle := ws_child or ws_Border or cbs_AutoHScroll or
            cbs_NoIntegralHeight or ws_Visible
            {<fduch> }
            or ws_VScroll;
            {</fduch>}
  FTabStop := true;
end;

function TComboBox.DoKeyDown(var AMsg: TWMKey): Boolean;
begin
  Result := false;
  if (AMsg.CharCode = VK_DOWN) and
     (SendMessage(FHandle,CB_GETDROPPEDSTATE,0,0) = 0) then
  begin
    SendMessage(FHandle,CB_SHOWDROPDOWN,WParam(true),0);
    Result := true;
  end;
  inherited DoKeyDown(AMsg);
end;

{<fduch> }
{$IFDEF CaptureMouse}
procedure TComboBox.DoMouseDown(var AMsg: TWMMouse; Button: TMouseButton;
                      Shift: TShiftState);
begin
  if (Button=mbLeft) and
     (SendMessage(FHandle,CB_GETDROPPEDSTATE,0,0) = 0) then
  begin
    SendMessage(FHandle,CB_SHOWDROPDOWN,WParam(true),0);
    SendMessage(FHandle,CB_SETEXTENDEDUI,WParam(false),0);
  end;
//  inherited DoMouseDown(AMsg, Button, Shift);
end;
{$ENDIF}
{</fduch>}

procedure TComboBox.SetSorted(Value: boolean);
begin
  if Value then FStyle := FStyle or lbs_Sort
           else FStyle := FStyle and not cbs_Sort;
end;

function TComboBox.GetCount: Integer;
begin
  Result := SendMessage(FHandle, CB_GETCOUNT, 0, 0);
end;

function TComboBox.GetFocused: Integer;
begin
  Result := SendMessage(FHandle, CB_GETCURSEL, 0, 0);
end;

procedure TComboBox.SetFocused(Value: integer);
begin
  SendMessage(FHandle, CB_SETCURSEL, Value, 0);
end;

function TComboBox.Get(Index: Integer): shortstring;
var
  Text: shortstring;
begin
  Text[0] := chr(SendMessage(FHandle, CB_GETLBTEXT, Index, Longint(@Text[1])));
  Result := Text;
end;

procedure TComboBox.Put(Index: Integer; const S: shortstring);
begin
  if (Index < 0) or (Index > Count) then Exit;
  if Index = Count then
  begin
    Add(S); Exit;
  end;
  Delete(Index);
  Insert(Index,S);
end;

function TComboBox.Add(const S: shortstring): Integer;
var ss : array [1..256] of char;
begin
  Move(s[1],ss[1],Ord(s[0]));
  ss[Ord(s[0])+1] := #0;
  Result := SendMessage(FHandle, CB_ADDSTRING, 0, Longint(@ss));
  if Result < 0 then FError := -1;
  if Count = 1 then SetFocused(0);
end;

procedure TComboBox.Insert(Index: Integer; const S: shortstring);
var ss : array [1..256] of char;
begin
  if (Index < 0) or (Index > Count) then Exit;
  Move(s[1],ss[1],Ord(s[0]));
  ss[Ord(s[0])+1] := #0;
  if SendMessage(FHandle, CB_INSERTSTRING, Index,
    Longint(@Ss)) < 0 then FError := -1;
  if Count = 1 then SetFocused(0);
end;

procedure TComboBox.Delete(Index: Integer);
var cf, cc : integer;
begin
  if (Index < 0) or (Index >= Count) then Exit;
  cf := GetFocused;
  cc := Count;
  SendMessage(FHandle, CB_DELETESTRING, Index, 0);
  if Count = 0 then SetFocused(-1);
  if cf >= cc - 1 then SetFocused(cc - 2);
end;

procedure TComboBox.Clear;
begin
  if Count <= 0 then Exit;
  SendMessage(FHandle, CB_RESETCONTENT, 0, 0);
  SetFocused(-1);
end;

{TButton}

constructor TButton.Create(AParent: TWinControl);
begin
  inherited Create(AParent);
  FWidth := 75;
  FHeight := 25;
  FClassName := 'BUTTON';
  FEnabled := true;
  FStyle := ws_Child or bs_PushButton or ws_Ex_ControlParent;
  FTabStop := true;
end;

function TButton.GetModalResult : TModalResult;
begin
  Result := FModalResult;
end;

procedure TButton.SetModalResult(Value: TModalResult);
begin
  FModalResult := Value;
end;

procedure TButton.Click;
begin
  if (FModalResult <> 0) and
     (Parent <> nil) and
      Parent.FIsModal and
     (Parent.FModalResult = 0) then
       Parent.FModalResult := Self.FModalResult
                               else
       inherited;
end;

{TCheckBox}

constructor TCheckBox.Create(AParent: TWinControl);
begin
  inherited Create(AParent);
  FWidth := 75;
  FHeight := 25;
  FBkMode := bk_Transparent;
  FClassName := 'BUTTON';
  FChecked := false;
  FEnabled := true;
  FStyle := ws_child or bs_Checkbox or ws_Ex_ControlParent or bs_Notify;
  FTabStop := true;
end;

procedure TCheckBox.SetChecked(Value: boolean);
var code : longint;
begin
  FChecked := Value;
  if FHandle <> INVALID_HANDLE_VALUE then
  begin
   code := BST_UNCHECKED;
   if FChecked then code := BST_CHECKED;
   PostMessage(FHandle,BM_SETCHECK,code,0);
   Invalidate;
  end;
end;

procedure TCheckBox.Click;
begin
  Checked := not Checked;
  inherited;
end;

{TGroupBox}

constructor TGroupBox.Create(AParent: TWinControl);
begin
  inherited Create(AParent);
  FWidth := 121;
  FHeight := 121;
  FClassName := 'BUTTON';
  FBkMode := bk_Transparent;
  FEnabled := true;
  FStyle := ws_child or bs_Groupbox or ws_Ex_ControlParent;
  FTabStop := true;
end;

{TProgressBar}

constructor TProgressBar.Create(AParent: TWinControl);
begin
  inherited Create(AParent);
  InitCommonControls;
  FWidth := 121;
  FHeight := 24;
  FClassName := PROGRESS_CLASS;
  //FBkMode := bk_Transparent;
  FEnabled := true;
  FStyle := ws_child or ws_Visible;
  FTabStop := false;
  FRange := 100;
  FPosition := 0;
end;

function TProgressBar.GetRange : word;
begin
  Result := FRange;
end;

procedure TProgressBar.SetRange(Value : word);
begin
  SendMessage(FHandle, PBM_SETRANGE, 0, MAKELPARAM(0,Value));
  FRange := Value;
end;

function TProgressBar.GetPosition : word;
begin
  Result := FPosition;
end;

procedure TProgressBar.SetPosition(Value : word);
begin
  SendMessage(FHandle, PBM_SETPOS, Value, 0);
  FPosition := Value;
end;

function TProgressBar.GetStep : word;
begin
  Result := FStep;
end;

procedure TProgressBar.SetStep(Value : word);
begin
  SendMessage(FHandle, PBM_SETSTEP, Value, 0);
  FStep := Value;
end;

constructor TSplash.Create(AParent : TWinControl);
begin
  inherited Create(AParent);
  OnHitTest := HitTest;
  FHCenter := true;
  FVCenter := true;
end;

procedure TSplash.SetHCenter(Value : boolean);
begin
  FHCenter := Value;
  if Value then Left := (GetSystemMetrics(SM_CXSCREEN)-Width) div 2;
end;

procedure TSplash.SetVCenter(Value : boolean);
begin
  FVCenter := Value;
  if Value then Top := (GetSystemMetrics(SM_CYSCREEN)-Height) div 2;
end;

procedure TSplash.HitTest(Sender : TObject; X,Y : integer;
                          var Result : integer);
begin
  Result := HTNOWHERE;
end;

procedure TSplash.CreateWnd;
var st  : longint;
    i,j : integer;
    ss  : shortstring;
begin
  j := 1;
  for i := 1 to Length(Caption) do
    if Caption[j] = #10 then Inc(j);
  Style := ws_Border;
  ExStyle := WS_EX_DLGMODALFRAME;
  AutoStop := false;
  if FHCenter and FVCenter then
  begin
    ss := #13#10#13#10;
    Height := 18 * (j + 4);
    Height := Height - GetSystemMetrics(SM_CYCAPTION);
  end;
  if FHCenter then SetHCenter(true);
  if FVCenter then SetVCenter(true);
  inherited CreateWnd;
  st := GetWindowLong(FHandle,GWL_STYLE);
  st := st and not WS_CAPTION;
  SetWindowLong(FHandle,GWL_STYLE,st);
    SetWindowPos(FHandle,0,0,0,0,0,
                 SWP_NOMOVE or SWP_NOSIZE or SWP_NOZORDER or SWP_DRAWFRAME);
  ss := ss + Caption;
  L := NewLabel(Self,
                ss,
                0,0,ClientWidth,ClientHeight,
                SS_CENTER,
                bk_Transparent,
                0,
                TextColor);
  Caption := '';
  if Visible then Show;
end;

procedure TSplash.UpdateText(Value : string);
var p : PChar;
begin
  p := PChar(GlobalAlloc(GMEM_FIXED,Length(Value)+1));
  StrPCopy(p,Value);
  SendMessage(L.Handle,wm_settext,0,longint(p));
  GlobalFree(Cardinal(p));
end;

{ TKeyboard }

var KbdHook : HHook;
    Kbd     : TKeyboard;

constructor TKeyboard.Create(AParent : TWinControl);
var kl : HKL;
begin
  if Kbd <> nil then Exit;
  inherited Create(AParent);
  Visible := false;
  Charset0 := 0;
  CharSet1 := RUSSIAN_CHARSET;
  ExStyle := ws_ex_clientedge;
  Position := kpRightBottom;
  Width := 22;
  Height := 22;
  Color := clSilver;
  CreateWnd;
  AParent.InsertWinControl(Self);
  InitParams;
  Kbd := Self;
  InstallHook;
  ActivateKeyboardLayout(HKL_NEXT,0);
  ActivateKeyboardLayout(HKL_PREV,0);
  ProcessMessages;
  Visible := true;
end;

destructor TKeyboard.Destroy;
begin
  RemoveHook;
  Kbd := nil;
  inherited Destroy;
end;

procedure TKeyboard.InitParams;
var st : longint;
begin
end;

procedure TKeyboard.SetPos(Value : TKeyboardPosition);
begin
  FPos := Value;
  case Value of
    kpLeftTop    : begin Left := 2; Top := 2; end;
    kpRightTop   : begin Left := FParent.ClientWidth - 24; Top := 2; end;
    kpLeftBottom : begin Left := 2; Top := FParent.ClientHeight - 24; end;
    kpRightBottom : begin
                      Left := FParent.ClientWidth - 24;
                      Top := FParent.ClientHeight - 24;
                    end;
  end;
end;

procedure TKeyboard.SetCharSet0(Value : integer);
begin
  FCharSet0 := Value;
  FLay0 := LoadIcon(HInstance,MakeIntResource(1000+Value));
end;

procedure TKeyboard.SetCharSet1(Value : integer);
begin
  FCharSet1 := Value;
  FLay1 := LoadIcon(HInstance,MakeIntResource(1000+Value));
end;

function HookPrc(nCode : INTEGER;
                 wParam : WParam;
                 lParam : LParam) : INTEGER; stdcall;
var
  pcwr : PCWPRetStruct;
begin
  pcwr := POINTER(lParam);
  if pcwr^.message = WM_INPUTLANGCHANGE then
  begin
    if Kbd <> nil then Kbd.LayoutChanged(pcwr^.wParam,pcwr^.lParam);
  end;
  if nCode = HC_ACTION then
    Result := 0
                       else
    Result := CallNextHookEx(KbdHook, nCode, wParam, lParam);
end;

procedure TKeyboard.InstallHook;
begin
  KbdHook := SetWindowsHookEx(WH_CALLWNDPROCRET,
                              HookPrc,
                              hInstance,
                              GetCurrentThreadID);
end;

procedure TKeyboard.RemoveHook;
begin
  if KbdHook <> 0 then UnhookWindowsHookEx(KbdHook);
  KbdHook := 0;
  ProcessMessages;
end;

procedure TKeyboard.WMPaint(var AMsg: TWMPaint);
var
   DC : HDC;
   ps : TPaintStruct;
begin
  DC := BeginPaint(FHandle,ps);
  SetBkMode(DC,TRANSPARENT);
  if FCharSet = FCharSet0 then
  begin
    DrawIconEx(DC,(ClientWidth-16) div 2,
                  (ClientHeight-16) div 2,FLay0,16,16,0,0,DI_NORMAL);
  end                   else
  if FCharSet = FCharSet1 then
  begin
    DrawIconEx(DC,(ClientWidth-16) div 2,
                  (ClientHeight-16) div 2,FLay1,16,16,0,0,DI_NORMAL);
  end;
  EndPaint(FHandle,ps);
  AMsg.Result := 1;
end;

procedure TKeyboard.LayoutChanged(ACharSet,ALayout : integer);
const s  : shortstring = '';
      s1 : shortstring = '';
begin
  FLayout := ALayout;
  FCharSet := ACharSet;
  if Visible then Invalidate;
end;

{ TTimer }

procedure TTimerWindow.ProcessMessage(var AMsg: TMessage);
begin
  with AMsg do
    if Msg = WM_TIMER then FTimer.Timer
                      else Result := DefWindowProc(FHandle, Msg, wParam, lParam);
end;

constructor TTimer.Create;
begin
  inherited Create;
  FEnabled := false;
  FInterval := 1000;
  FWindow := TTimerWindow.Create(nil);
  FWindow.FTimer := Self;
  FWindow.Visible := false;
  FWindow.CreateWnd;
  FWindowHandle := FWindow.FHandle;;
end;

destructor TTimer.Destroy;
begin
  FEnabled := False;
  UpdateTimer;
  FWindow.Free;
  inherited Destroy;
end;

procedure TTimer.UpdateTimer;
begin
  KillTimer(FWindowHandle, 1);
  if (FInterval <> 0) and FEnabled and Assigned(FOnTimer) then
    if SetTimer(FWindowHandle, 1, FInterval, nil) = 0 then
      MessageBox(0,'Out Of Resources','Error',MB_OK+MB_ICONSTOP);
end;

procedure TTimer.SetEnabled(Value: Boolean);
begin
  if Value <> FEnabled then
  begin
    FEnabled := Value;
    UpdateTimer;
  end;
end;

procedure TTimer.SetInterval(Value: Cardinal);
begin
  if Value <> FInterval then
  begin
    FInterval := Value;
    UpdateTimer;
  end;
end;

procedure TTimer.SetOnTimer(Value: TNotifyEvent);
begin
  FOnTimer := Value;
  UpdateTimer;
end;

procedure TTimer.Timer;
begin
  if Assigned(FOnTimer) then FOnTimer(Self);
end;

{ Procedures }

function NewLabel(AParent : TWinControl;
                  ACaption : string;
                  ALeft,Atop,AWidth,AHeight : integer;
                  AALignment : integer;
                  ABkMode : TBkMode;
                  ABkColor,
                  ATextColor : TColor) : TLabel;
var Wnd : TLabel;
begin
  if AParent = nil then halt;
  Wnd := TLabel.Create(AParent);
  with Wnd do
  begin
    Left := ALeft;
    Top := ATop;
    Width := AWidth;
    Height := AHeight;
    Color := ABkColor;
    TextColor := ATextColor;
    Caption := ACaption;
    FBkMode := ABkMode;
    FStyle := FStyle or AALignment;
  end;
  Wnd.CreateWnd;
  Wnd.ProcessMessages;
  AParent.InsertWinControl(Wnd);
  Result := Wnd;
end;

function NewEdit(AParent : TWinControl;
                 AText : shortstring;
                 ALeft,Atop,AWidth,AHeight : integer;
                 AStyle : integer;
                 ABkColor,
                 ATextColor : TColor) : TEdit;
var Wnd : TEdit;
begin
  if AParent = nil then halt;
  Wnd := TEdit.Create(AParent);
  with Wnd do
  begin
    FStyle := FStyle or AStyle;
    Left := ALeft;
    Top := ATop;
    Width := AWidth;
    Height := AHeight;
    Color := ABkColor;
    TextColor := ATextColor;
    Text := AText;
    FCtl3d := true;
  end;
  Wnd.CreateWnd;
  AParent.InsertWinControl(Wnd);
  Wnd.SetMargin(2);
  Result := Wnd;
end;

{<fduch> }
function NewHotKey(AParent : TWinControl;
                   AHotKey : Word;
                   AModifiers : THKModifiers;
                   ALeft,Atop,AWidth,AHeight : integer;
                   ABkColor,
                   ATextColor : TColor) : THotKey;
var Wnd : THotKey;
begin
  if AParent = nil then halt;
  Wnd := THotKey.Create(AParent);
  with Wnd do
  begin
    Left := ALeft;
    Top := ATop;
    Width := AWidth;
    Height := AHeight;
    Color := ABkColor;
    TextColor := ATextColor;
    FCtl3d := true;
  end;
  Wnd.CreateWnd;
  Wnd.Modifiers := AModifiers;
  Wnd.HotKey := AHotKey;
  Wnd.InvalidKeys := [hcNone, hcShift];
  AParent.InsertWinControl(Wnd);
  Result := Wnd;
end;
{</fduch> }

function NewListBox(AParent : TWinControl;
                    ALeft,Atop,AWidth,AHeight : integer;
                    ASorted : boolean;
                    ABkColor,
                    ATextColor : TColor) : TListBox;
var Wnd : TListBox;
begin
  if AParent = nil then halt;
  Wnd := TListBox.Create(AParent);
  with Wnd do
  begin
    Left := ALeft;
    Top := ATop;
    Width := AWidth;
    Height := AHeight;
    Color := ABkColor;
    TextColor := ATextColor;
    FCtl3d := true;
    Sorted := ASorted;
    //Font.Style := [fsBold];
  end;
  Wnd.CreateWnd;
  AParent.InsertWinControl(Wnd);
  Result := Wnd;
end;

function NewComboBox(AParent : TWinControl;
                     ALeft,Atop,AWidth,AHeight : integer;
                     AStyle : integer;
                     ASorted : boolean;
                     ABkColor,
                     ATextColor : TColor) : TComboBox;
var Wnd : TComboBox;
begin
  if AParent = nil then halt;
  Wnd := TComboBox.Create(AParent);
  with Wnd do
  begin
    Left := ALeft;
    Top := ATop;
    Width := AWidth;
    Height := AHeight;
    Color := ABkColor;
    TextColor := ATextColor;
    FCtl3d := true;
    FStyle := FStyle or AStyle;
    Sorted := ASorted;
    //Font.Style := [fsBold];
  end;
  Wnd.CreateWnd;
  AParent.InsertWinControl(Wnd);
  Result := Wnd;
end;

function NewButton(AParent : TWinControl;
                 ACaption : string;
                 AResult : TModalResult;
                 ALeft,Atop,AWidth,AHeight : integer;
                 ABkColor,
                 ATextColor : TColor) : TButton;
var Wnd : TButton;
begin
  if AParent = nil then halt;
  Wnd := TButton.Create(AParent);
  with Wnd do
  begin
    Left := ALeft;
    Width := AWidth;
    Height := AHeight;
    Top := ATop;
    Color := ABkColor;
    TextColor := ATextColor;
    Caption := ACaption;
    FModalResult := AResult;
  end;
  Wnd.CreateWnd;
  AParent.InsertWinControl(Wnd);
  Result := Wnd;
end;

function NewCheckBox(AParent : TWinControl;
                     ACaption : string;
                     ALeft,Atop,AWidth,AHeight : integer;
                     ABkColor,
                     ATextColor : TColor) : TCheckBox;
var Wnd : TCheckBox;
begin
  if AParent = nil then halt;
  Wnd := TCheckBox.Create(AParent);
  with Wnd do
  begin
    Left := ALeft;
    Top := ATop;
    Width := AWidth;
    Height := AHeight;
    Color := ABkColor;
    TextColor := ATextColor;
    Caption := ACaption;
    //Font.Style := [fsBold];
  end;
  Wnd.CreateWnd;
  AParent.InsertWinControl(Wnd);
  Result := Wnd;
end;

function NewGroupBox(AParent : TWinControl;
                     ACaption : string;
                     ALeft,Atop,AWidth,AHeight : integer;
                     ABkColor,
                     ATextColor : TColor) : TGroupBox;
var Wnd : TGroupBox;
begin
  if AParent = nil then halt;
  Wnd := TGroupBox.Create(AParent);
  with Wnd do
  begin
    Left := ALeft;
    Top := ATop;
    Width := AWidth;
    Height := AHeight;
    Color := ABkColor;
    TextColor := ATextColor;
    Caption := ACaption;
    //Font.Style := [fsBold];
  end;
  Wnd.CreateWnd;
  AParent.InsertWinControl(Wnd);
  Result := Wnd;
end;

function NewProgressBar(AParent : TWinControl;
                        ALeft,Atop,AWidth,AHeight : integer;
                        AMin, AMax : integer;
                        ABkColor,
                        ATextColor : TColor) : TProgressBar;
var Wnd : TProgressBar;
begin
  if AParent = nil then halt;
  Wnd := TProgressBar.Create(AParent);
  with Wnd do
  begin
    Left := ALeft;
    Top := ATop;
    Width := AWidth;
    Height := AHeight;
    Color := ABkColor;
    TextColor := ATextColor;
    Range := AMax;
  end;
  Wnd.CreateWnd;
  AParent.InsertWinControl(Wnd);
  Result := Wnd;
end;

procedure InitScreen;
begin
  with Screen do
  begin
    Width := GetSystemMetrics(SM_CXSCREEN);
    Height := GetSystemMetrics(SM_CYSCREEN);
    DesktopLeft := GetSystemMetrics(SM_XVIRTUALSCREEN);
    DesktopTop := GetSystemMetrics(SM_YVIRTUALSCREEN);
    DesktopWidth := GetSystemMetrics(SM_CXVIRTUALSCREEN);
    if DeskTopWidth = 0 then DesktopWidth := Width;
    DesktopHeight := GetSystemMetrics(SM_CYVIRTUALSCREEN);
    if DeskTopHeight = 0 then DesktopHeight := Height;
  end;
end;

{<fduch> }
function HotKeyToStr(Key: word; DModifiers: THKModifiers): shortstring;
var
  s: string[15];
begin
  S[0]:=#0;
  if (hkCtrl in DModifiers) then
    s:=s+'Ctrl+';
  if (hkAlt in DModifiers) then
    s:=s+'Alt+';
  if (hkShift in DModifiers) then
    s:=s+'Shift+';
  Result:=S+char(Key);
end;

procedure StrToHotKey(const Value: string; var Key: word; var Modifiers: THKModifiers);
var
  s, CurToken: string;
begin
  if Value<>'' then
  begin
    s:=Value;
    while Pos('+', S)>0 do
    begin
      CurToken:=UpperCase(Copy(S, 1, Pos('+', S)-1));
      Delete(S, 1, Pos('+', S));
      if CurToken='ALT' then Include(Modifiers, hkAlt);
      if CurToken='CTRL' then Include(Modifiers, hkCtrl);
      if CurToken='SHIFT' then Include(Modifiers, hkShift);
    end;
    Key:=ord(S[1]);
  end
  else
  begin
    Key:=0;
    Modifiers:=[];
  end;
end;
{</fduch>}

{<kvv>}
function NewMenuItem(Var Menu: HMenu; 
          iType,State,ID : DWord; 
          Caption: ShortString; By_pos: boolean): boolean;

var mii: menuiteminfo;
begin
  zeromemory(@mii,sizeof(mii));
  Caption := Caption + #0;
  with mii do
  begin
    cbSize   := SizeOF(mii);
    fMask    := MIIM_ID or MIIM_STATE or MIIM_TYPE;
    fType    := iType;
    wID      := ID;
    fState   := State;
    dwTypeData := @Caption[1];
    cch      := Length(Caption);
  end;
  Result := InsertMenuItem(Menu,ID,By_pos,mii);
end;

function SetTrayIcon(AWnd: Hwnd; ID: Longint; Icon : HIcon;
                            text: ShortString): boolean;
var NiD: NOTIFYICONDATA;
begin
  if Length(text)>63 then text[0] := #62;
  text := text + #0;
  with NiD do
  begin
    cbSize := SizeOf(NiD);
    Wnd := AWnd;
    uId := ID;
    uFlags := NIF_ICON or NIF_TIP or NIF_MESSAGE;
    hIcon := Icon;
    uCallBackMessage := wm_NotifyIcon;
    Move(text[1], szTip,length(text));
  end;
  Result := Shell_notifyicon(NIM_ADD,@NiD);
  if icon<>0 then DestroyIcon(Icon);
end;

function DeleteTrayIcon(AWnd: Hwnd; ID: Longint): boolean;
var NiD: NOTIFYICONDATA;
begin
  with NiD do
  begin
    cbSize := SizeOf(NiD);
    Wnd := AWnd;
    uId := ID;
    uFlags := 0;
    hIcon := 0;
    uCallBackMessage := 0;
  end;
  Result := Shell_notifyicon(NIM_DELETE,@NiD);
end;
{</kvv>}

initialization

  Kbd := nil;
  KbdHook := 0;
  InitScreenLogPixels;
  Fonts := TFonts.Create;
  InitScreen;

finalization

  Fonts.Free;

end.

