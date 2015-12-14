(*//////////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////////*)

MODULE AclLib;

IMPORT SYSTEM, W := WinApi, Ut := AclUtils, Ignore;

(*<fduch> *)
(*.$DEFINE CaptureMouse*)
(*.$DEFINE KBD*)
(*</fduch>*)

TYPE
  Cardinal = INTEGER;
  Char = CHAR;
  DWORD = INTEGER;
  Integer = INTEGER;
  LongInt = INTEGER;
  PChar = ARRAY 256 OF Char;
  Pointer = SYSTEM.PTR;
  ShortString = ARRAY 256 OF Char;
  String = ARRAY OF Char;

CONST bk_Opaque* = 0; bk_Transparent* = 1; bk_Slide* = 2;
TYPE TBkMode* = BYTE; (* bk_Opaque, bk_Transparent, bk_Slide *)

  TModalResult* = Integer; (* Low(Integer)..High(Integer) *)

(* TModalResult values *)

CONST
  mrNone*     = 0;
  mrOk*       = W.IDOK;
  mrCancel*   = W.IDCANCEL;
  mrAbort*    = W.IDABORT;
  mrRetry*    = W.IDRETRY;
  mrIgnore*   = W.IDIGNORE;
  mrYes*      = W.IDYES;
  mrNo*       = W.IDNO;
  mrAll*      = mrNo + 1;
  mrNoToAll*  = mrAll + 1;
  mrYesToAll* = mrNoToAll + 1;

(* Cursor identifiers *)

TYPE
  TCursor* = SHORTINT; (* -32768..32767 *)

CONST
  IDC_NODROP* =    (*PChar*)(32767);
  IDC_DRAG*   =    (*PChar*)(32766);
  IDC_HSPLIT* =    (*PChar*)(32765);
  IDC_VSPLIT* =    (*PChar*)(32764);
  IDC_MULTIDRAG* = (*PChar*)(32763);
  IDC_SQLWAIT* =   (*PChar*)(32762);
  IDC_HANDPT* =   (*PChar*)(32761);

  crDefault*     = (*TCursor*)(0);
  crNone*        = (*TCursor*)(-1);
  crArrow*       = (*TCursor*)(-2);
  crCross*       = (*TCursor*)(-3);
  crIBeam*       = (*TCursor*)(-4);
  crSize*        = (*TCursor*)(-22);
  crSizeNESW*    = (*TCursor*)(-6);
  crSizeNS*      = (*TCursor*)(-7);
  crSizeNWSE*    = (*TCursor*)(-8);
  crSizeWE*      = (*TCursor*)(-9);
  crUpArrow*     = (*TCursor*)(-10);
  crHourGlass*   = (*TCursor*)(-11);
  crDrag*        = (*TCursor*)(-12);
  crNoDrop*      = (*TCursor*)(-13);
  crHSplit*      = (*TCursor*)(-14);
  crVSplit*      = (*TCursor*)(-15);
  crMultiDrag*   = (*TCursor*)(-16);
  crSQLWait*     = (*TCursor*)(-17);
  crNo*          = (*TCursor*)(-18);
  crAppStart*    = (*TCursor*)(-19);
  crHelp*        = (*TCursor*)(-20);
  crHandPoint*   = (*TCursor*)(-21);
  crSizeAll*     = (*TCursor*)(-22);

  WM_NOTIFYICON* = W.WM_USER + 4000;

  FormClassName* = "TACLFORM";

  ACL_DEFAULT_CHARSET* = CHR(W.DEFAULT_CHARSET);
(*  ACL_DEFAULT_CHARSET* = RUSSIAN_CHARSET; *)

TYPE
    TObject* = RECORD(*
      constructor Create;
      procedure Free;
      class function InitInstance(Instance: Pointer): TObject;
      procedure CleanupInstance;
      function ClassType: TClass;
      class function ClassName: ShortString;
      class function ClassNameIs(const Name: string): Boolean;
      class function ClassParent: TClass;
      class function ClassInfo: Pointer;
      class function InstanceSize: Longint;
      class function InheritsFrom(AClass: TClass): Boolean;
      class function MethodAddress(const Name: ShortString): Pointer;
      class function MethodName(Address: Pointer): ShortString;
      function FieldAddress(const Name: ShortString): Pointer;
      function GetInterface(const IID: TGUID; out Obj): Boolean;
      class function GetInterfaceEntry(const IID: TGUID): PInterfaceEntry;
      class function GetInterfaceTable: PInterfaceTable;
      function SafeCallException(ExceptObject: TObject;
        ExceptAddr: Pointer): HResult; virtual;
      procedure AfterConstruction; virtual;
      procedure BeforeDestruction; virtual;
      procedure Dispatch(VAR Message); virtual;
      procedure DefaultHandler(VAR Message); virtual;
      class function NewInstance: TObject; virtual;
      procedure FreeInstance; virtual;
      destructor Destroy; virtual;*)
    END;

    TCreateParams* = RECORD
      Caption: PChar;
      Style: LongInt;
      ExStyle: LongInt;
      X, Y: Integer;
      Width, Height: Integer;
      WndParent: W.HWND;
      Param: Pointer;
      WindowClass: W.WNDCLASS;
      WinClassName: ARRAY 64 OF Char;
    END;

    TWndProc = PROCEDURE (Window: W.HWND; AMessage: LongInt; WParam: W.WPARAM; LParam: W.LPARAM): W.LRESULT;
    TShiftState = SET; (* of (ssShift, ssAlt, ssCtrl,
                          ssLeft, ssRight, ssMiddle, ssDouble) *)
    TMouseButton = BYTE; (* mbLeft, mbRight, mbMiddle *)
(*
(*<fduch> *)
    THKModifier = (hkAlt, hkCtrl, hkShift, hkExt);
    THKModifiers = set of THKModifier;
    THKInvalidKey = (hcNone, hcShift, hcCtrl, hcAlt, hcShiftCtrl, hcShiftAlt, hcCtrlAlt, hcShiftCtrlAlt);
    THKInvalidKeys = set of THKInvalidKey;
(*</fduch>*)

    TNotifyEvent = procedure(Sender: TObject) of object;
    TCloseEvent = function(Sender: TObject) : BOOLEAN of object;
    TEraseEvent = procedure(Sender: TObject; HD: W.HDC; R: TRect) of object;
    TMouseEvent = procedure(Sender: TObject; Button: TMouseButton;
                            Shift: TShiftState; X, Y: Integer) of object;
    TMouseMoveEvent = procedure(Sender: TObject; Shift: TShiftState;
                                X, Y: Integer) of object;
    TKeyEvent = procedure(Sender: TObject; Key: Word;
                          Shift: TShiftState) of object;
    TKeyPressEvent = procedure(Sender: TObject; Key: Char) of object;
    THitTestEvent = procedure(Sender: TObject; X, Y : Integer;
                              VAR Result : Integer) of object;
(*<kvv>*)
    TMenuItemEvent = procedure(Sender: TObject; wID: Word) of object;
(*</kvv>*)

    TWinControl = class;*)
    PWinControl* = POINTER TO TWinControl;

    TControl = RECORD
      FOwner : PWinControl;
      Left* : Integer; (* read FLeft write FLeft *)
      Top* : Integer; (* read FTop write FTop *)
      Width* : Integer; (* read FWidth write FWidth *)
      Height* : Integer; (* read FHeight write FHeight *)
    (*public
      constructor Create(AOwner : TWinControl);
      PROCEDURE Paint(DC : W.HDC); virtual; abstract;
      destructor Destroy; override;*)
    END;

    PControlList = POINTER TO TControlList;
    TControlList = RECORD[1]
      Control : TControl;
      Next : PControlList;
    END;

    PWinControlList = POINTER TO TWinControlList;
    TWinControlList = RECORD[1]
      WinControl : PWinControl;
      Next : PWinControlList;
    END;

    (*Font*)
    CONST fpDefault = 0; fpFixed = 1; fpVariable = 2;
    TYPE TFontPitch = BYTE; (* fpDefault, fpFixed, fpVariable *)
    TFontName = (*type string*) ARRAY OF Char; (*W.PtrSTR*)
    TFontCharSet = CHAR; (* 0..255 *)
    TFontDataName = ARRAY W.LF_FACESIZE OF Char;
    CONST
      fsBold = 0; fsItalic = 1; fsUnderline = 2; fsStrikeOut = 3;
    TYPE
    TFontStyle = BYTE; (* (fsBold, fsItalic, fsUnderline, fsStrikeOut) *)
    TFontStyles = SET;(* of TFontStyle *)
    TFontStylesBase = SET; (* of TFontStyle *)

    TFontData = RECORD[1]
      Height: Integer;
      Pitch: TFontPitch;
      Style: TFontStylesBase;
      CharSet: TFontCharSet;
      Name: TFontDataName;
    END;

    TFont* = RECORD
      Handle-  : W.HFONT; (* read FHandle *)
      FControl : PWinControl;
      FFontData : TFontData;
      FLogFont : W.LOGFONT;
      Color-: Ut.TColor; (* read FColor write SetColor *)
      FPixelsPerInch: Integer;(*
      PROCEDURE GetData(const AFont : W.LOGFONT; VAR Data : TFontData);
      PROCEDURE SetData(const Data : TFontData; VAR AFont : W.LOGFONT);
      PROCEDURE UpdateFont;
      PROCEDURE SetLogFont(const AFont : W.LOGFONT);
    protected
      PROCEDURE GetHeight : Integer;
      PROCEDURE GetName : TFontName;
      PROCEDURE GetPitch : TFontPitch;
      PROCEDURE  GetSize : Integer;
      PROCEDURE GetStyle : TFontStyles;
      PROCEDURE GetCharSet : TFontCharSet;
      PROCEDURE SetColor(Value: Ut.TColor);
      PROCEDURE SetHeight(Value: Integer);
      PROCEDURE SetName(const Value: TFontName);
      PROCEDURE SetPitch(Value: TFontPitch);
      PROCEDURE SetSize(Value: Integer);
      PROCEDURE SetStyle(Value: TFontStyles);
      PROCEDURE SetCharSet(Value: TFontCharSet);
      PROCEDURE SetPixelsPerInch(Value: Integer);
    public
      constructor Create;
      destructor Destroy; override;
      property PixelsPerInch: Integer read FPixelsPerInch write SetPixelsPerInch;
      property CharSet: TFontCharSet read GetCharSet write SetCharSet;
      property Height: Integer read GetHeight write SetHeight;
      property Name: TFontName read GetName write SetName;
      property Pitch: TFontPitch read GetPitch write SetPitch;
      property Size: Integer read GetSize write SetSize;
      property Style: TFontStyles read GetStyle write SetStyle;*)
    END;

    PFontList* = POINTER TO TFontList;
    TFontList* = ARRAY (*[0..0]*) OF W.LOGFONT;
    CONST fsAll* = 0X; fsTrueTypeOnly* = 1X;
    TYPE TFontSet* = CHAR; (* (fsAll, fsTrueTypeOnly) *)

    PFonts = POINTER TO TFonts;
    TFonts* = RECORD
    (*private*)
      FDC     : W.HDC;
      Count-  : Integer; (* read FCount *)
      FFonts  : PFontList;
      FSet    : TFontSet;
      CharSet-: TFontCharSet; (* read FCharSet write SetCharSet *)
    (*protected*)
      (*PROCEDURE SetCharSet(Value : TFontCharSet);
      PROCEDURE Enumerate;
      PROCEDURE IsTrueType(const AFont : W.LOGFONT) : BOOLEAN;
      PROCEDURE GetFont(i : Integer) : W.LOGFONT;*)
    (*public*)
      (*constructor Create;
      destructor Destroy; override;
      PROCEDURE IndexOf(APitch : TFontPitch;
                 const AName  : string) : Integer;
      PROCEDURE IsDefaultPitch(const AFont : W.LOGFONT) : BOOLEAN;
      PROCEDURE IsFixedPitch(const AFont : W.LOGFONT) : BOOLEAN;
      PROCEDURE IsVariablePitch(const AFont : W.LOGFONT) : BOOLEAN;
      PROCEDURE FindFont(AName : TFontName;
                        APitch : TFontPitch) : W.LOGFONT;
      property Font[index : Integer] : W.LOGFONT read GetFont;*)
    END;

    TWinControl* = RECORD
     FHandle        : W.HWND;
     FParentHandle  : W.HWND;
     FClassName     : PChar;
     FDefWndProc    : LongInt;
     FHelpContext   : DWORD;
     FHelpFile      : ShortString;
     FTextBuf       : ShortString;
     FTextLen       : Cardinal;
     Brush*         : W.HBRUSH; (* read FBrush write FBrush *)
     FCursorHandle  : W.HCURSOR;
     Cursor-        : TCursor; (* read FCursor write SetCursor *)
     FFont          : TFont;
     FDC            : W.HDC;
     Color-         : Ut.TColor; (* read FColor write SetColor *)
     TextColor-     : Ut.TColor; (* read FTextColor write SetTextColor *)
     FBkMode        : TBkMode;
     Style*         : SET; (* read FStyle write FStyle *)
     ExStyle*       : SET; (* read FExStyle write FExStyle *)
     FCtl3D         : BOOLEAN;
     Left-          : Integer; (* read FLeft write SetLeft *)
     Top-           : Integer; (* read FTop write SetTop *)
     Width-         : Integer; (* read FWidth write SetWidth *)
     Height-        : Integer; (* read FHeight write SetHeight *)
     Parent-        : PWinControl; (* read FParent *)(*
     FCList         : PControlList;
     FWList         : PWinControlList;*)
     AutoStop*      : BOOLEAN; (* read FAutoStop write FAutoStop *)
     FActiveControl : PWinControl;
     Enabled-       : BOOLEAN; (* read FEnabled write SetEnabled *)
     IsModal-       : BOOLEAN;(* IsModal : BOOLEAN read FIsModal *)
     FModalResult   : TModalResult;
     FTabStop       : BOOLEAN;
     Visible-       : BOOLEAN; (* read FVisible write SetVisible *)
     FHTest         : LongInt;(*
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
(*<kvv>*)
     FOnMenuItemSelect: TMenuItemEvent;
(*</kvv>*)
     PROCEDURE Show;
     PROCEDURE Hide;
    protected
     PROCEDURE WndProc(AMessage, WParam, LParam : Longint): Longint; virtual; stdcall;
     PROCEDURE GetWndProc : pointer;
     PROCEDURE GetParentHandle : HWnd;
     PROCEDURE SetParentHandle(Value: HWnd);
     PROCEDURE CreateParams(VAR Params: TCreateParams); virtual;
     PROCEDURE CreateWindowHandle(const Params: TCreateParams);
     PROCEDURE DestroyWindowHandle;
     ///////////////////////////////////////////////////////////
     PROCEDURE WMClose(VAR AMsg: TWMClose);
     PROCEDURE WMDestroy(VAR AMsg: TWMDestroy);
     PROCEDURE WMPaint(VAR AMsg: TWMPaint); virtual;
     PROCEDURE WMEraseBkgnd(VAR AMsg : TWMEraseBkgnd); virtual;
     PROCEDURE WMCtlcolor(VAR AMsg : TMessage);
     PROCEDURE WMNCHitTest(VAR AMsg : TMessage);
     PROCEDURE WMCommand(VAR AMsg : TWMCommand);
     PROCEDURE WMSetFocus(VAR AMsg : TWMSetFocus);
     PROCEDURE WMKillFocus(VAR AMsg : TWMKillFocus);
     PROCEDURE WMLButtonDown(VAR AMsg: TWMLButtonDown);
     PROCEDURE WMRButtonDown(VAR AMsg: TWMRButtonDown);
     PROCEDURE WMLButtonDblClk(VAR AMsg: TWMLButtonDblClk);
     PROCEDURE WMRButtonDblClk(VAR AMsg: TWMRButtonDblClk);
     PROCEDURE WMMouseMove(VAR AMsg: TWMMouseMove);
     PROCEDURE WMLButtonUp(VAR AMsg: TWMLButtonUp);
     PROCEDURE WMRButtonUp(VAR AMsg: TWMRButtonUp);
     PROCEDURE WMSetCursor(VAR AMsg: TWMSetCursor);
     PROCEDURE WMKeyDown(VAR AMsg: TWMKeyDown);
     PROCEDURE WMSysKeyDown(VAR AMsg: TWMKeyDown);
     PROCEDURE WMKeyUp(VAR AMsg: TWMKeyUp);
     PROCEDURE WMSysKeyUp(VAR AMsg: TWMKeyUp);
     PROCEDURE WMChar(VAR AMsg: TWMChar);
     PROCEDURE WMSysCommand(VAR AMsg: TWMSysCommand);
     PROCEDURE WMNotifyIcon(VAR AMsg: TMessage);
     PROCEDURE WMQueryEndSession(VAR AMsg: TMessage);
     PROCEDURE WMHelp(VAR AMsg: TMessage);
     PROCEDURE ProcessMessage(VAR AMsg: TMessage); virtual;
     ////////////////////////////////////////////////////
     PROCEDURE DoMouseDown(VAR AMsg: TWMMouse; Button: TMouseButton;
                           Shift: TShiftState); virtual;
     PROCEDURE DoMouseUp(VAR AMsg: TWMMouse; Button: TMouseButton;
                         Shift: TShiftState); virtual;
     PROCEDURE DoKeyDown(VAR AMsg: TWMKey): Boolean; virtual;
     PROCEDURE DoKeyUp(VAR AMsg: TWMKey): Boolean; virtual;
     PROCEDURE DoKeyPress(VAR AMsg: TWMKey): Boolean; virtual;
     PROCEDURE SetColor(Value : Ut.TColor);
     PROCEDURE SetTextColor(Value : Ut.TColor);
     PROCEDURE Change; virtual;
     PROCEDURE Click; virtual;
     PROCEDURE DoEnter; virtual;
     PROCEDURE DoExit; virtual;
     PROCEDURE SetEnabled(Value: BOOLEAN);
     PROCEDURE SetCursor(Value : TCursor);
     PROCEDURE GetText : shortstring;
     PROCEDURE SetText(const Value: shortstring);
     PROCEDURE GetClientRect : TRect;
     PROCEDURE GetClientWidth : Integer;
     PROCEDURE GetClientHeight : Integer;
     PROCEDURE IsParentHandle(AHandle : HWnd) : BOOLEAN;
     PROCEDURE SetBounds(R : TRect);
     PROCEDURE SetLeft(Value : Integer);
     PROCEDURE SetTop(Value : Integer);
     PROCEDURE SetWidth(Value : Integer);
     PROCEDURE SetHeight(Value : Integer);
     PROCEDURE Dispatch(VAR AMsg); override;
     PROCEDURE SetVisible(Value : BOOLEAN);
    public
     ///////////////////////////////////////////////////////
     constructor Create(AParent : TWinControl); virtual;
     destructor Destroy; override;
     PROCEDURE CreateWnd; virtual;
     PROCEDURE DestroyWnd;
     PROCEDURE Close;
     PROCEDURE ShowModal : TModalResult;
     PROCEDURE EndModal(Value : TModalResult);
     PROCEDURE ProcessMsg(VAR Msg: TMsg): Boolean;
     PROCEDURE ProcessMessages;
     PROCEDURE Invalidate;
     PROCEDURE SetFocus;
     PROCEDURE SelectPrev;
     PROCEDURE SelectNext;
     PROCEDURE SelectFirst;
     PROCEDURE SelectLast;
     PROCEDURE IsFirstSelected : BOOLEAN;
     PROCEDURE IsLastSelected : BOOLEAN;
     PROCEDURE InsertWinControl(AControl : TWinControl);
     PROCEDURE InsertControl(AControl : TControl);
     PROCEDURE SetFont(const AFont : W.LOGFONT);
     ////////////////////////////////////////////////////////////////
     property HelpContext : DWORD read FHelpContext write FHelpContext;
     property HelpFile : shortstring read FHelpFile write FHelpFile;
     property Ctl3D : BOOLEAN read FCtl3D write FCtl3D;
     property Handle : HWnd read FHandle;
     property ParentHandle : HWnd read GetParentHandle write SetParentHandle;
     property Font : TFont read FFont;
     property ClientWidth : Integer read GetClientWidth;
     property ClientHeight : Integer read GetClientHeight;
     property ClientRect : TRect read GetClientRect;
     property HitTestResult : LongInt read FHTest write FHTest;
     property TabStop : BOOLEAN read FTabStop write FTabStop;
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
    *)END;

    TStdControl* = RECORD (TWinControl)
    (*public
     PROCEDURE CreateWnd; override;*)
    END;

    TLabel* = RECORD (TStdControl)(*
    private
     FFormat : LongInt;
    protected
     PROCEDURE WMPaint(VAR AMsg: TWMPaint); override;
     PROCEDURE WMEraseBkgnd(VAR AMsg : TWMEraseBkgnd); override;
     PROCEDURE HitTest(Sender: TObject; X, Y : Integer;
                       VAR Result : Integer);
    public
     constructor Create(AParent : TWinControl); override;
     property BkMode : TBkMode read FBkMode write FBkMode;
     property TextFormat : LongInt read FFormat write FFormat;*)
    END;(*

    TEdit = class(TStdControl)
    protected
     PROCEDURE DoKeyPress(VAR AMsg: TWMKey): Boolean; override;
     PROCEDURE GetMaxLength : Integer;
     PROCEDURE SetMaxLength(Value : Integer);
     PROCEDURE GetMargin : word;
     PROCEDURE SetMargin(Value : word);
    public
     constructor Create(AParent : TWinControl); override;
     property MaxLength : Integer read GetMaxLength write SetMaxLength;
     property MarginWidth : word read GetMargin write SetMargin;
     property Text : shortstring read GetText write SetText;
    END;

(*<fduch> *)
    (*HotKey*)
    THotKey = class (TStdControl)
    private
      FInvalidKeys: THKInvalidKeys;
      FModifiers: THKModifiers;
      FHotKey: byte;
      FMod: Byte;
      PROCEDURE GetHotKey: Byte;
      PROCEDURE GetModifiers: THKModifiers;
      PROCEDURE GetSHotKey: string;
      PROCEDURE GetModif: byte;
      PROCEDURE SetHotKey(const Value: Byte);
      PROCEDURE SetInvalidKeys(const Value: THKInvalidKeys);
      PROCEDURE SetModifiers(const Value: THKModifiers);
      PROCEDURE SetSHotKey(const Value: string);
      PROCEDURE SetModif(const Value: byte);
    public
      constructor Create(AParent: TWinControl); override;
      property HotKey: byte read GetHotKey write SetHotKey;
      property BModifiers: byte read GetModif write SetModif;
      property InvalidKeys: THKInvalidKeys read FInvalidKeys write SetInvalidKeys;
      property Modifiers: THKModifiers read GetModifiers write SetModifiers;
      property StrHotKey: string read GetSHotKey write SetSHotKey;
    END;
(*</fduch>*)
*)
    TListBox* = RECORD (TStdControl)(*
    private
     FError  : Integer;
     FSorted : BOOLEAN;
    protected
     PROCEDURE GetCount: Integer;
     PROCEDURE Get(Index: Integer): shortstring;
     PROCEDURE GetObject(Index: Integer): TObject;
     PROCEDURE Put(Index: Integer; const S: shortstring);
     PROCEDURE PutObject(Index: Integer; AObject: TObject);
     PROCEDURE GetFocused : Integer;
     PROCEDURE SetFocused(Value: Integer);
     PROCEDURE SetSorted(Value: BOOLEAN);
    public
     constructor Create(AParent : TWinControl); override;
     PROCEDURE Add(const S: shortstring): Integer;
     PROCEDURE Insert(Index: Integer; const S: shortstring);
     PROCEDURE Delete(Index: Integer);
     PROCEDURE Clear;
     PROCEDURE SelectItem(Value: Integer);
     property Count : Integer read GetCount;
     property Focused : Integer read GetFocused write SetFocused;
     property Error : Integer read FError;
     property Items[Index: Integer] : shortstring read Get write Put;
     property Objects[Index: Integer] : TObject read GetObject write PutObject;
     property Sorted : BOOLEAN read FSorted write SetSorted;*)
    END;
(*
    TComboBox = class(TStdControl)
    private
     FError  : Integer;
     FSorted : BOOLEAN;
    protected
     PROCEDURE GetCount: Integer;
     PROCEDURE Get(Index: Integer): shortstring;
     PROCEDURE Put(Index: Integer; const S: shortstring);
     PROCEDURE GetFocused : Integer;
     PROCEDURE SetFocused(Value: Integer);
     PROCEDURE SetSorted(Value: BOOLEAN);
     PROCEDURE DoKeyDown(VAR AMsg: TWMKey): Boolean; override;

     (*<fduch> *)(*$IFDEF CaptureMouse*)
     PROCEDURE TComboBox.DoMouseDown(VAR AMsg: TWMMouse; Button: TMouseButton;
                                     Shift: TShiftState);
     (*$ENDIF*)(*</fduch>*)
    public
     constructor Create(AParent : TWinControl); override;
     PROCEDURE Add(const S: shortstring): Integer;
     PROCEDURE Insert(Index: Integer; const S: shortstring);
     PROCEDURE Delete(Index: Integer);
     PROCEDURE Clear;
     property Count : Integer read GetCount;
     property Error : Integer read FError;
     property ItemIndex : Integer read GetFocused write SetFocused;
     property Items[Index: Integer] : shortstring read Get write Put;
     property Sorted : BOOLEAN read FSorted write SetSorted;
     property Text : shortstring read GetText write SetText;
    END;
*)
    TButton* = RECORD (TStdControl)(*
    protected
     PROCEDURE Click; override;
     PROCEDURE GetModalResult : TModalResult;
     PROCEDURE SetModalResult(Value: TModalResult);
    public
     constructor Create(AParent : TWinControl); override;
     property ModalResult : TModalResult read GetModalResult write SetModalResult;*)
    END;

    TCheckBox* = RECORD (TStdControl)(*
    private
     FChecked : BOOLEAN;
    protected
     PROCEDURE Click; override;
     PROCEDURE SetChecked(Value: BOOLEAN);
    public
     constructor Create(AParent : TWinControl); override;
     property Checked : BOOLEAN read FChecked write SetChecked;*)
    END;
(*
    TGroupBox* = class(TStdControl)
    public
     constructor Create(AParent : TWinControl); override;
    END;
*)
    TProgressBar* = RECORD(TStdControl)(*
    private
     FRange : word;
     FPosition : word;
     FStep : word;
    protected
     PROCEDURE GetRange : word;
     PROCEDURE SetRange(Value : word);
     PROCEDURE GetPosition : word;
     PROCEDURE SetPosition(Value : word);
     PROCEDURE GetStep : word;
     PROCEDURE SetStep(Value : word);
    public
     constructor Create(AParent : TWinControl); override;
     property Range : word read GetRange write SetRange;
     property Position : word read GetPosition write SetPosition;
     property Step : word read GetStep write SetStep;*)
    END;
(*
    TSplash = class(TWinControl)
    private
      FTextColor : Ut.TColor;
      FHCenter : BOOLEAN;
      FVCenter : BOOLEAN;
      PROCEDURE UpdateText(Value : string);
      PROCEDURE HitTest(Sender : TObject; X,Y : Integer;
                        VAR Result : Integer);
      PROCEDURE SetHCenter(Value : BOOLEAN);
      PROCEDURE SetVCenter(Value : BOOLEAN);
    public
     L          : TLabel;
     constructor Create(AParent : TWinControl); override;
     PROCEDURE CreateWnd; override;
     property TextColor : Ut.TColor read FTextColor write FTextColor;
     property Text : string write UpdateText;
     property HCenter : BOOLEAN read FHCenter write SetHCenter;
     property VCenter : BOOLEAN read FVCenter write SetVCenter;
    END;

    TKeyboardPosition = (kpLeftTop,kpRightTop,kpLeftBottom,kpRightBottom);
    TKeyboard = class(TLabel)
    private
     FPos      : TKeyboardPosition;
     FLayout0  : Integer;
     FLayout1  : Integer;
     FCharSet0 : Integer;
     FCharSet1 : Integer;
     FLay0     : HICON;
     FLay1     : HICON;
     FLayout   : Integer;
     FCharSet  : Integer;
     PROCEDURE InstallHook;
     PROCEDURE RemoveHook;
     PROCEDURE InitParams;
     PROCEDURE WMPaint(VAR AMsg: TWMPaint); message WM_PAINT;
     PROCEDURE LayoutChanged(ACharSet,ALayout : Integer);
     PROCEDURE SetCharSet0(Value : Integer);
     PROCEDURE SetCharSet1(Value : Integer);
     PROCEDURE SetPos(Value : TKeyboardPosition);
    public
     constructor Create(AParent : TWinControl); override;
     destructor Destroy; override;
     property Layout0 : Integer read FLayout0 write FLayout0;
     property Layout1 : Integer read FLayout1 write FLayout1;
     property CharSet0: Integer read FCharSet0 write SetCharSet0;
     property CharSet1: Integer read FCharSet1 write SetCharSet1;
     property Position : TKeyboardPosition read FPos write SetPos;
    END;

    TTimer = class;

    TTimerWindow = class(TWinControl)
    private
      FTimer : TTimer;
    protected
      PROCEDURE ProcessMessage(VAR AMsg: TMessage); override;
    END;

    TTimer = class
    private
      FInterval: Cardinal;
      FWindow : TTimerWindow;
      FWindowHandle: HWND;
      FOnTimer: TNotifyEvent;
      FEnabled: Boolean;
      PROCEDURE UpdateTimer;
      PROCEDURE SetEnabled(Value: Boolean);
      PROCEDURE SetInterval(Value: Cardinal);
      PROCEDURE SetOnTimer(Value: TNotifyEvent);
    protected
      PROCEDURE Timer; dynamic;
    public
      constructor Create;
      destructor Destroy; override;
      property Enabled: Boolean read FEnabled write SetEnabled;
      property Interval: Cardinal read FInterval write SetInterval;
      property OnTimer: TNotifyEvent read FOnTimer write SetOnTimer;
    END;
*)
    TScreen = RECORD[1]
                Width : Integer;
                Height : Integer;
                DesktopLeft : Integer;
                DesktopTop : Integer;
                DesktopWidth : Integer;
                DesktopHeight : Integer;
              END;
VAR
  Screen : TScreen;
(*
PROCEDURE NewLabel(AParent : TWinControl;
                  ACaption : string;
                  ALeft,Atop,AWidth,AHeight : Integer;
                  AALignment : Integer;
                  ABkMode : TBkMode;
                  ABkColor,
                  ATextColor : Ut.TColor) : TLabel;

PROCEDURE NewEdit(AParent : TWinControl;
                 AText : shortstring;
                 ALeft,Atop,AWidth,AHeight : Integer;
                 AStyle : Integer;
                 ABkColor,
                 ATextColor : Ut.TColor) : TEdit;
(*<fduch> *)
PROCEDURE NewHotKey(AParent : TWinControl;
                   AHotKey : Word;
                   AModifiers : THKModifiers;
                   ALeft,Atop,AWidth,AHeight : Integer;
                   ABkColor,
                   ATextColor : Ut.TColor) : THotKey;
(*</fduch>*)

PROCEDURE NewListBox(AParent : TWinControl;
                    ALeft,Atop,AWidth,AHeight : Integer;
                    ASorted : BOOLEAN;
                    ABkColor,
                    ATextColor : Ut.TColor) : TListBox;

PROCEDURE NewComboBox(AParent : TWinControl;
                    ALeft,Atop,AWidth,AHeight : Integer;
                    AStyle : Integer;
                    ASorted : BOOLEAN;
                    ABkColor,
                    ATextColor : Ut.TColor) : TComboBox;

PROCEDURE NewButton(AParent : TWinControl;
                 ACaption : string;
                 AResult : TModalResult;
                 ALeft,Atop,AWidth,AHeight : Integer;
                 ABkColor,
                 ATextColor : Ut.TColor) : TButton;

PROCEDURE NewCheckBox(AParent : TWinControl;
                     ACaption : string;
                     ALeft,Atop,AWidth,AHeight : Integer;
                     ABkColor,
                     ATextColor : Ut.TColor) : TCheckBox;

PROCEDURE NewGroupBox(AParent : TWinControl;
                     ACaption : string;
                     ALeft,Atop,AWidth,AHeight : Integer;
                     ABkColor,
                     ATextColor : Ut.TColor) : TGroupBox;

PROCEDURE NewProgressBar(AParent : TWinControl;
                        ALeft,Atop,AWidth,AHeight : Integer;
                        AMin, AMax : Integer;
                        ABkColor,
                        ATextColor : Ut.TColor) : TProgressBar;


(*<kvv>*)
// MenuItem adding function
PROCEDURE NewMenuItem(Var Menu: HMenu; 
          iType,State,ID : DWord; 
          Caption: ShortString; By_pos: BOOLEAN): BOOLEAN;

// Insert icon into system tray
PROCEDURE SetTrayIcon(AWnd: Hwnd; ID: Longint; Icon : HIcon;
                            text: ShortString): BOOLEAN;

// Delete icon from system tray
PROCEDURE DeleteTrayIcon(AWnd: Hwnd; ID: Longint): BOOLEAN;
(*</kvv>*)
(*<fduch> *)
PROCEDURE HotKeyToStr(Key: word; DModifiers: THKModifiers): shortstring;
PROCEDURE StrToHotKey(const Value: string; VAR Key: word; VAR Modifiers: THKModifiers);
(*</fduch> *)
*)
VAR
  Fonts : TFonts;
  ScreenLogPixels : Integer;
  (*log : text;

implementation

uses CommCtrl, multimon;
*)
CONST
  NUL = NIL;

(*$H+*)
(*$O+*)
(*$R CTRLS.RES*)
(*$IFDEF KBD*)
 (*$R KBD.RES*)
(*$ENDIF*)

CONST ID_SELF = '__SELF__'; (* constant used in GetProp()/SetProp() *)
                            (* change it if You want. *)
VAR
  HInstance: W.HINSTANCE;
  MainWindow: TWinControl;
  CmdShow: Integer; (* CmdShow parameter for CreateWindow *)

PROCEDURE ^ (VAR w: TWinControl) Show;
PROCEDURE ^ (VAR w: TWinControl) Hide;

PROCEDURE GetCmdShow(): Integer;
VAR
  SI: W.STARTUPINFO; result: Integer;
BEGIN
  result := 10;            (* SW_SHOWDEFAULT *)
  W.GetStartupInfo(SI);
  IF 0 IN SI.dwFlags THEN (* STARTF_USESHOWWINDOW *)
    result := SI.wShowWindow;
  END;
  RETURN result
END GetCmdShow;
(*
PROCEDURE KeysToShiftState(Keys: Word): TShiftState;
BEGIN
  Result := [];
  IF Keys and MK_SHIFT <> 0 THEN Include(Result, ssShift);
  IF Keys and MK_CONTROL <> 0 THEN Include(Result, ssCtrl);
  IF Keys and MK_LBUTTON <> 0 THEN Include(Result, ssLeft);
  IF Keys and MK_RBUTTON <> 0 THEN Include(Result, ssRight);
  IF Keys and MK_MBUTTON <> 0 THEN Include(Result, ssMiddle);
  IF GetKeyState(VK_MENU) < 0 THEN Include(Result, ssAlt);
END;

(* Convert keyboard message data to TShiftState *)

PROCEDURE KeyDataToShiftState(KeyData: Longint): TShiftState;
const
  AltMask = $20000000;
BEGIN
  Result := [];
  IF GetKeyState(VK_SHIFT) < 0 THEN Include(Result, ssShift);
  IF GetKeyState(VK_CONTROL) < 0 THEN Include(Result, ssCtrl);
  IF KeyData and AltMask <> 0 THEN Include(Result, ssAlt);
END;

// TControl

constructor TControl.Create(AOwner : TWinControl);
BEGIN
  inherited Create;
  FOwner := AOwner;
END;

destructor TControl.Destroy;
BEGIN
  inherited Destroy;
END;*)

(* TFont *)

PROCEDURE ^ (VAR f: TFont) SetName (IN value: TFontName);
PROCEDURE ^ (VAR f: TFont) SetSize (value: Integer);
PROCEDURE ^ (VAR f: TFont) SetStyle (value: TFontStyles);
PROCEDURE ^ (VAR f: TFont) SetPitch (value: TFontPitch);
PROCEDURE ^ (VAR f: TFont) SetCharSet (value: TFontCharSet);

PROCEDURE InitScreenLogPixels;
VAR
  DC: W.HDC;
BEGIN
  DC := W.GetDC(NUL);
  ScreenLogPixels := W.GetDeviceCaps(DC, W.LOGPIXELSY);
  Ignore.Int( W.ReleaseDC(NUL,DC) );
END InitScreenLogPixels;

PROCEDURE (VAR f: TFont) Create;
BEGIN
  (*f.Create^;*)
  f.Handle := NUL;
  f.Color := Ut.clBlack;
  f.FPixelsPerInch := 96;
  f.SetPitch(fpVariable);
  f.SetStyle({});
  f.SetCharSet(ACL_DEFAULT_CHARSET);
  f.SetName("Arial");
  (*f.FPixelsPerInch := ScreenLogPixels;*)
  f.SetSize(10);
END Create;

PROCEDURE (VAR f: TFont) Destroy;
BEGIN
  IF f.Handle # NUL THEN Ignore.Int( W.DeleteObject(f.Handle) ) END;
  (*inherited Destroy;*)
END Destroy;

PROCEDURE (VAR f: TFont) GetData (IN aFont: W.LOGFONT; VAR data: TFontData);
BEGIN
  data.Height := aFont.lfHeight;
  IF aFont.lfWeight >= W.FW_BOLD THEN INCL(data.Style, fsBold) END;
  IF aFont.lfItalic = 1X THEN INCL(data.Style, fsItalic) END;
  IF aFont.lfUnderline = 1X THEN INCL(data.Style, fsUnderline) END;
  IF aFont.lfStrikeOut = 1X THEN INCL(data.Style, fsStrikeOut) END;
  data.CharSet := aFont.lfCharSet;
  COPY(aFont.lfFaceName, data.Name);
  CASE ORD(BITS(ORD(aFont.lfPitchAndFamily)) * BITS(0FH)) OF
  | W.VARIABLE_PITCH: data.Pitch := fpVariable;
  | W.FIXED_PITCH:    data.Pitch := fpFixed;
  ELSE
    data.Pitch := fpDefault;
  END;
END GetData;

PROCEDURE (VAR f: TFont) SetLogFont (IN aFont: W.LOGFONT);
BEGIN
  SYSTEM.MOVE(
    SYSTEM.VAL(SYSTEM.PTR, SYSTEM.ADR(aFont)),
    SYSTEM.VAL(SYSTEM.PTR, SYSTEM.ADR(f.FLogFont)),
    SIZE(W.LOGFONT)
  );
END SetLogFont;

PROCEDURE (VAR f: TFont) SetData (IN data: TFontData; VAR aFont: W.LOGFONT);
BEGIN
  aFont.lfHeight := data.Height;
  aFont.lfWidth := 0;
  IF fsBold IN data.Style THEN
    aFont.lfWeight := W.FW_BOLD
  ELSE
    aFont.lfWeight := W.FW_NORMAL;
  END;
  IF fsItalic IN data.Style THEN aFont.lfItalic := 1X END;
  IF fsUnderline IN data.Style THEN aFont.lfUnderline := 1X END;
  IF fsStrikeOut IN data.Style THEN aFont.lfStrikeOut := 1X END;
  aFont.lfCharSet := data.CharSet;
  SYSTEM.MOVE(
    SYSTEM.VAL(SYSTEM.PTR, SYSTEM.ADR(data.Name)),
    SYSTEM.VAL(SYSTEM.PTR, SYSTEM.ADR(aFont.lfFaceName)),
    SIZE(TFontDataName)
  );
  CASE data.Pitch OF
  | fpVariable: aFont.lfPitchAndFamily := CHR(ORD(
      BITS(ORD(aFont.lfPitchAndFamily)) + BITS(W.VARIABLE_PITCH)));
  | fpFixed   : aFont.lfPitchAndFamily := CHR(ORD(
      BITS(ORD(aFont.lfPitchAndFamily)) + BITS(W.FIXED_PITCH)));
  ELSE END;
END SetData;

PROCEDURE ^ (VAR w: TWinControl) SetFont (VAR AFont: W.LOGFONT);

PROCEDURE (VAR f: TFont) UpdateFont;
VAR
  OldFont : W.HFONT;
BEGIN
  OldFont := f.Handle;
  f.FLogFont.lfWidth := 0;
  IF (f.FControl # NIL) & (SYSTEM.VAL(LONGINT, f.FControl.FHandle) > 0) THEN
    f.FControl.SetFont(f.FLogFont);
  ELSE
    f.Handle := W.CreateFontIndirect(f.FLogFont);
    IF OldFont # NUL THEN Ignore.Int( W.DeleteObject(OldFont) ) END;
  END;
END UpdateFont;

PROCEDURE (VAR f: TFont) GetHeight() : Integer;
BEGIN
  RETURN f.FFontData.Height
END GetHeight;

PROCEDURE (VAR f: TFont) GetName (VAR result: TFontName);
BEGIN
  COPY(f.FLogFont.lfFaceName, result);
END GetName;

PROCEDURE (VAR f: TFont) GetPitch(): TFontPitch;
BEGIN
  RETURN f.FFontData.Pitch;
END GetPitch;

PROCEDURE (VAR f: TFont) GetStyle(): TFontStyles;
VAR
  styles : TFontStyles;
BEGIN
  styles := {};
  IF f.FLogFont.lfWeight = W.FW_BOLD THEN styles := styles + {fsBold} END;
  IF f.FLogFont.lfItalic > 0X THEN styles := styles + {fsItalic} END;
  RETURN styles
END GetStyle;

PROCEDURE (VAR f: TFont) GetCharSet(): TFontCharSet;
BEGIN
  RETURN f.FFontData.CharSet
END GetCharSet;

PROCEDURE ^ (VAR w: TWinControl) SetTextColor* (value: Ut.TColor);

PROCEDURE (VAR f: TFont) SetColor (value: Ut.TColor);
BEGIN
  IF f.Color # value THEN
    f.Color := value;
    IF (f.FControl # NIL) & (SYSTEM.VAL(LONGINT, f.FControl.FHandle) > 0) THEN
      f.FControl.SetTextColor(value);
    END;
  END;
END SetColor;

PROCEDURE (VAR f: TFont) SetHeight (value: Integer);
BEGIN
  f.FLogFont.lfHeight := value;
  f.UpdateFont;
END SetHeight;

PROCEDURE ^ (VAR f: TFonts) FindFont* (
  IN aName: TFontName; aPitch: TFontPitch; VAR result: W.LOGFONT);

PROCEDURE (VAR f: TFont) SetName (IN value: TFontName);
VAR
  aFont: W.LOGFONT;
BEGIN
  IF Ut.Length(value) > 0 THEN
      Fonts.FindFont(value, f.FFontData.Pitch, aFont);
    IF (f.FControl # NIL) & (f.FControl.FHandle # NUL) THEN
      (* here it needs to store all existing font attributes except for name *)
      aFont.lfHeight := f.FLogFont.lfHeight;
      aFont.lfWeight := f.FLogFont.lfWeight;
      aFont.lfItalic := f.FLogFont.lfItalic;
      aFont.lfUnderline := f.FLogFont.lfUnderline;
(*      aFont.lfCharSet := f.FLogFont.lfCharSet; *)
    END;
    f.SetLogFont(aFont);
    f.UpdateFont;
  END;
END SetName;

PROCEDURE (VAR f: TFont) GetSize(): Integer;
BEGIN
  RETURN -W.MulDiv(f.FFontData.Height, 72, f.FPixelsPerInch)
END GetSize;

PROCEDURE (VAR f: TFont) SetSize (value: Integer);
BEGIN
  f.FFontData.Height := -W.MulDiv(value, f.FPixelsPerInch, 72);
  f.SetHeight(f.FFontData.Height);
END SetSize;

PROCEDURE (VAR f: TFont) SetStyle (value: TFontStyles);
BEGIN
  IF fsBold IN value THEN
    f.FLogFont.lfWeight := W.FW_BOLD;
  ELSE
    f.FLogFont.lfWeight := W.FW_NORMAL;
  END;
  IF fsItalic IN value THEN
    f.FLogFont.lfItalic := 1X;
  ELSE
    f.FLogFont.lfItalic := 0X;
  END;
(*<fduch> *)
  IF fsUnderline IN value THEN
    f.FLogFont.lfUnderline := 1X
  ELSE
    f.FLogFont.lfUnderline := 0X;
  END;
(*</fduch>*)
  f.UpdateFont;
END SetStyle;

PROCEDURE (VAR f: TFont) SetPitch (value: TFontPitch);
BEGIN
  CASE value OF
  | fpDefault :
      f.FLogFont.lfPitchAndFamily := SYSTEM.VAL(CHAR,
        SYSTEM.VAL(SET, f.FLogFont.lfPitchAndFamily) + BITS(W.DEFAULT_PITCH));
  | fpVariable:
      f.FLogFont.lfPitchAndFamily := SYSTEM.VAL(CHAR,
        SYSTEM.VAL(SET, f.FLogFont.lfPitchAndFamily) + BITS(W.VARIABLE_PITCH));
  | fpFixed   :
      f.FLogFont.lfPitchAndFamily := SYSTEM.VAL(CHAR,
        SYSTEM.VAL(SET, f.FLogFont.lfPitchAndFamily) + BITS(W.FIXED_PITCH));
  ELSE END;
  f.FFontData.Pitch := value;
  f.UpdateFont;
END SetPitch;

PROCEDURE (VAR f: TFont) SetCharSet (value: TFontCharSet);
BEGIN
  f.FLogFont.lfCharSet := value;
  f.UpdateFont;
END SetCharSet;

PROCEDURE (VAR f: TFont) SetPixelsPerInch (value: Integer);
VAR
  oldS: Integer;
BEGIN
  oldS := f.GetSize();
  f.FPixelsPerInch := value;
  f.SetSize(oldS);
  f.UpdateFont;
END SetPixelsPerInch;

(* TFonts *)

PROCEDURE ^ (VAR f: TFonts) IsTrueType (IN aFont: W.LOGFONT): BOOLEAN;

PROCEDURE [1] EnumFontsProc0 (
  logFont: W.PtrVoid(*W.ENUMLOGFONTEX*);
  textMetric: W.PtrVoid(*W.NEWTEXTMETRICEX*);
  fontType: Integer; data: W.LPARAM): Integer;
TYPE
  PLogFont = POINTER TO W.ENUMLOGFONTEX;
VAR
  fnt: PFonts; logFnt: PLogFont;
BEGIN
  fnt := SYSTEM.VAL(PFonts, data);
  logFnt := SYSTEM.VAL(PLogFont, logFont);
  IF (fnt.FSet = fsAll) OR fnt.IsTrueType(logFnt.elfLogFont) THEN
    INC(fnt.Count);
  END;
  RETURN 1
END EnumFontsProc0;

PROCEDURE [1] EnumFontsProc (
  LogFont: W.PtrVoid(*W.ENUMLOGFONTEX*);
  TextMetric: W.PtrVoid(*W.NEWTEXTMETRICEX*);
  fontType: Integer; data: W.LPARAM): Integer;
VAR
  Fnt: PFonts;
BEGIN
  (*$R-*)
  Fnt := SYSTEM.VAL(PFonts, data);
  IF (Fnt.FSet = fsAll) (*OR Fnt.IsTrueType(LogFont.elfLogFont)*) THEN
    SYSTEM.MOVE(
      SYSTEM.VAL(SYSTEM.PTR, SYSTEM.ADR(LogFont)),
      SYSTEM.VAL(SYSTEM.PTR, SYSTEM.ADR(Fnt.FFonts^[Fnt.Count])),
      SIZE(W.LOGFONT)
    );
    INC(Fnt.Count);
  END;
  RETURN 1
END EnumFontsProc;

PROCEDURE ^ (VAR f: TFonts) Enumerate;

PROCEDURE (VAR f: TFonts) Create* ;
BEGIN
  (*f.Create^;*)
  f.FFonts := NIL;
  f.FSet := fsTrueTypeOnly;
  f.CharSet := ACL_DEFAULT_CHARSET;
  f.Enumerate;
  f.FDC := NUL;
END Create;

PROCEDURE (VAR f: TFonts) Destroy* ;
BEGIN
  (*GlobalFree(Cardinal(FFonts));
  inherited Destroy;*)
END Destroy;

PROCEDURE (VAR f: TFonts) GetFont* (i: Integer; VAR result: W.LOGFONT);
BEGIN
  SYSTEM.MOVE(
    SYSTEM.VAL(SYSTEM.PTR, SYSTEM.ADR(f.FFonts^[i])),
    SYSTEM.VAL(SYSTEM.PTR, SYSTEM.ADR(result)),
    SIZE(W.LOGFONT)
  );
END GetFont;

PROCEDURE (VAR f: TFonts) IsDefaultPitch* (IN AFont: W.LOGFONT): BOOLEAN;
BEGIN
  RETURN TRUE
END IsDefaultPitch;

PROCEDURE (VAR f: TFonts) IsFixedPitch* (IN AFont: W.LOGFONT): BOOLEAN;
BEGIN
  RETURN ORD(
    BITS(ORD(AFont.lfPitchAndFamily)) * BITS(0FH)) = W.FIXED_PITCH
END IsFixedPitch;

PROCEDURE (VAR f: TFonts) IsVariablePitch* (IN AFont : W.LOGFONT): BOOLEAN;
BEGIN
  RETURN ORD(
    BITS(ORD(AFont.lfPitchAndFamily)) * BITS(0FH)) = W.VARIABLE_PITCH
END IsVariablePitch;

PROCEDURE (VAR f: TFonts) IndexOf* (
  APitch: TFontPitch; IN AName: String): Integer;
VAR
  i: Integer;
BEGIN
  FOR i := 1 TO f.Count DO
    IF Ut.AnsiCompareText(f.FFonts^[i-1].lfFaceName, AName) = 0 THEN
      CASE APitch OF
      | fpDefault: RETURN i-1
      | fpFixed: IF f.IsFixedPitch(f.FFonts^[i-1]) THEN RETURN i-1 END;
      | fpVariable: IF f.IsVariablePitch(f.FFonts^[i-1]) THEN RETURN i-1 END;
      ELSE END;
    END;
  END;
  RETURN 0
END IndexOf;

PROCEDURE (VAR f: TFonts) FindFont* (
  IN aName: TFontName; aPitch: TFontPitch; VAR result: W.LOGFONT);
VAR
  i: Integer;
BEGIN
  i := f.IndexOf(aPitch, aName);
  SYSTEM.MOVE(
    SYSTEM.VAL(SYSTEM.PTR, SYSTEM.ADR(f.FFonts^[i])),
    SYSTEM.VAL(SYSTEM.PTR, SYSTEM.ADR(result)),
    SIZE(W.LOGFONT)
  );
END FindFont;

PROCEDURE (VAR f: TFonts) SetCharSet* (value: TFontCharSet);
BEGIN
  IF f.CharSet # value THEN
    f.CharSet := value;
    f.Enumerate;
  END;
END SetCharSet;

PROCEDURE (VAR f: TFonts) Enumerate;
VAR
  lFont: W.LOGFONT;
BEGIN
  f.FDC := W.GetDC(NUL);
  Ut.FillChar(SYSTEM.VAL(SYSTEM.PTR, SYSTEM.ADR(lFont)), SIZE(W.LOGFONT), 0);
  lFont.lfCharSet := f.CharSet;
  IF f.FFonts # NIL THEN Ignore.Ptr( W.GlobalFree(f.FFonts) ) END;
  f.Count := 0;
  Ignore.Int(
    W.EnumFontFamiliesEx(f.FDC, lFont, EnumFontsProc0,
      SYSTEM.VAL(W.LPARAM, SYSTEM.ADR(f)), 0)
  );
  f.FFonts := SYSTEM.VAL(PFontList,
    W.GlobalAlloc(W.GMEM_FIXED, SIZE(W.LOGFONT) * f.Count));
  f.Count := 0;
  Ignore.Int(
    W.EnumFontFamiliesEx(f.FDC, lFont, EnumFontsProc,
      SYSTEM.VAL(W.LPARAM, SYSTEM.ADR(f)), 0)
  );
  Ignore.Int( W.ReleaseDC(NUL, f.FDC) );
END Enumerate;

PROCEDURE (VAR f: TFonts) IsTrueType (IN aFont: W.LOGFONT): BOOLEAN;
VAR
  Metrics: W.TEXTMETRIC;
  lf: W.LOGFONT;
  oldFont, newFont: W.HFONT;
  result: BOOLEAN;
BEGIN
  lf.lfHeight := 10;
  lf.lfWidth := 10;
  lf.lfEscapement := 0;
  lf.lfWeight := W.FW_REGULAR;
  lf.lfItalic := 0X;
  lf.lfUnderline := 0X;
  lf.lfStrikeOut := 0X;
  lf.lfCharSet := CHR(W.RUSSIAN_CHARSET);
  lf.lfOutPrecision := CHR(W.OUT_DEFAULT_PRECIS);
  lf.lfClipPrecision := CHR(W.CLIP_DEFAULT_PRECIS);
  lf.lfQuality := CHR(W.DEFAULT_QUALITY);
  lf.lfPitchAndFamily := CHR(ORD(
    BITS(W.DEFAULT_PITCH) + BITS(W.FF_DONTCARE)));
  COPY(aFont.lfFaceName, lf.lfFaceName);
  newFont := W.CreateFontIndirect(lf);
  oldFont := W.SelectObject(f.FDC, newFont);
  Ignore.Int( W.GetTextMetrics(f.FDC, Metrics) );
  result := BITS(ORD(Metrics.tmPitchAndFamily)) * BITS(W.TMPF_TRUETYPE) # {};
  Ignore.Ptr( W.SelectObject(f.FDC, oldFont) );
  Ignore.Int( W.DeleteObject(newFont) );
  RETURN result
END IsTrueType;

(*TWinControl*)
(*
PROCEDURE GetWindowInstance(Handle: HWND) : TWinControl;
BEGIN
  Result := TWincontrol(GetProp(Handle,ID_SELF));
END;

PROCEDURE (VAR w: TWinControl) WndProc(AMessage, WParam, LParam : Longint): Longint;
VAR
  self_   : pointer;
  window_ : hWnd;
  AMsg    : TMessage;
BEGIN
  window_ := HWND(Self);
  self_ := Ptr(GetProp(window_,ID_SELF));
  IF self_ <> NIL THEN
  BEGIN
    AMsg.Msg := AMessage;
    AMsg.WParam := WParam;
    AMsg.LParam := LParam;
    AMsg.Result := 0;
    TWinControl(self_).ProcessMessage(AMsg);
  end            ELSE
    AMsg.Result := DefWindowProc(window_, AMessage, WParam, LParam);
  Result := AMsg.Result;
END;

PROCEDURE (VAR w: TWinControl) GetWndProc : pointer; assembler;
asm
  MOV EAX,[EAX]
  MOV EAX,[EAX]
END;
*)
PROCEDURE (VAR w: TWinControl) Create* (VAR [nil] aParent : TWinControl);
BEGIN
  (*w.Constructor^;*)
  w.FHandle := NUL;
  w.FParentHandle := NUL;
  w.FTextBuf := "";
  w.FTextLen := 0;
  w.FClassName := FormClassName;
  w.Style := W.WS_BORDER + W.WS_CAPTION + W.WS_EX_CONTROLPARENT;
  w.ExStyle := {};
  w.FCtl3D := FALSE;
  w.Parent := SYSTEM.VAL(PWinControl, SYSTEM.ADR(aParent));
  w.FDefWndProc := 0;
  w.Left := W.CW_USEDEFAULT;
  w.Top := W.CW_USEDEFAULT;
  w.Width := W.CW_USEDEFAULT;
  w.Height := W.CW_USEDEFAULT;
  w.Color := Ut.clSilver;
  w.FBkMode := bk_Opaque;
  w.Brush := NUL;
  w.Cursor := crDefault;
  w.FCursorHandle := W.LoadCursor(NUL, SYSTEM.VAL(W.PtrSTR, W.IDC_ARROW));
  w.FFont.Create;
  w.FFont.FControl := SYSTEM.VAL(PWinControl, SYSTEM.ADR(w));(*
  w.FCList := NIL;
  w.FWList := NIL;
  w.FEnabled := true;
  w.FOnClick := NIL;
  w.FOnErase := NIL;
  w.FOnHitTest := NIL;
  w.FOnMouseDown := NIL;
(*<kvv>*)
  w.FOnMenuItemSelect := NIL;*)
(*</kvv>*)
END Create;
(*
PROCEDURE (VAR w: TWinControl) GetParentHandle : HWnd;
BEGIN
  IF FParent <> NIL THEN Result := FParent.FHandle
                    ELSE Result := FParentHandle;
END;

PROCEDURE (VAR w: TWinControl) SetParentHandle(Value: HWnd);
BEGIN
  IF FParent = NIL THEN FParentHandle := Value
                   ELSE FParentHandle := FParent.FHandle;
END;
*)
PROCEDURE (VAR w: TWinControl) SetBounds (IN r: W.RECT);
VAR
  flags: SET;
BEGIN
  flags := W.SWP_NOZORDER;
  IF w.Visible THEN flags := flags + W.SWP_DRAWFRAME + W.SWP_SHOWWINDOW END;
  IF w.FHandle # NUL THEN
    Ignore.Int(
      W.SetWindowPos(
        w.FHandle,NUL,r.left,r.top,r.right-r.left,r.bottom-r.top,flags)
    );
  END;
  w.Left := r.left;
  w.Top := r.top;
  w.Width := r.right - r.left;
  w.Height := r.bottom - r.top;
END SetBounds;

PROCEDURE (VAR w: TWinControl) SetLeft* (value: Integer);
VAR
  r: W.RECT;
BEGIN
  IF w.Left # value THEN
    w.Left := value;
    r.left := w.Left; r.right := r.left + w.Width;
    r.top := w.Top; r.bottom := r.top + w.Height;
    w.SetBounds(r);
  END;
END SetLeft;

PROCEDURE (VAR w: TWinControl) SetTop* (value: Integer);
VAR
  r: W.RECT;
BEGIN
  IF w.Top # value THEN
    w.Top := value;
    r.left := w.Left; r.right := r.left + w.Width;
    r.top := w.Top; r.bottom := r.top + w.Height;
    w.SetBounds(r);
  END;
END SetTop;

PROCEDURE (VAR w: TWinControl) SetWidth* (value: Integer);
VAR
  r: W.RECT;
BEGIN
  IF w.Width # value THEN
    w.Width := value;
    r.left := w.Left; r.right := r.left + w.Width;
    r.top := w.Top; r.bottom := r.top + w.Height;
    w.SetBounds(r);
  END;
END SetWidth;

PROCEDURE (VAR w: TWinControl) SetHeight* (value : Integer);
VAR
  r: W.RECT;
BEGIN
  IF w.Height # value THEN
    w.Height := value;
    r.left := w.Left; r.right := r.left + w.Width;
    r.top := w.Top; r.bottom := r.top + w.Height;
    w.SetBounds(r);
  END;
END SetHeight;

PROCEDURE ^ (VAR w: TWinControl) ProcessMessages;

PROCEDURE (VAR w: TWinControl) SetFont (VAR AFont: W.LOGFONT);
VAR
  fOld : W.HFONT;
BEGIN
  IF SYSTEM.VAL(LONGINT, w.FHandle) > 0 THEN
    fOld := W.SendMessage(w.FHandle, W.WM_GETFONT, NUL, NUL);
    w.FFont.Handle := W.CreateFontIndirect(AFont);
    Ignore.Ptr(
      W.SendMessage(w.FHandle, W.WM_SETFONT,
        SYSTEM.VAL(W.WPARAM, w.FFont.Handle),
        SYSTEM.VAL(W.LPARAM, Ut.MakeLong(1(*Word(TRUE)*), 0))
      )
    );
    IF fOld # NUL THEN Ignore.Int( W.DeleteObject(fOld) ) END;
    w.ProcessMessages;
  END;
END SetFont;

PROCEDURE (VAR w: TWinControl) SetEnabled (value: BOOLEAN);
BEGIN
  w.Enabled := value;
  IF SYSTEM.VAL(LONGINT, w.FHandle) > 0 THEN
    Ignore.Int( W.EnableWindow(w.FHandle, SYSTEM.VAL(W.BOOL, value)) );
  END;
END SetEnabled;
(*
PROCEDURE (VAR w: TWinControl) GetCaption() : shortstring;
BEGIN
  IF FHandle > 0 THEN
  BEGIN
   FTextBuf[0] := chr(SendMessage(FHandle,WM_GETTEXTLENGTH,0,0)+1);
   SendMessage(FHandle,WM_GETTEXT,ord(FTextBuf[0]),Longint(@FTextBuf[1]));
   IF FTextBuf[1] = #0 THEN FTextBuf[0] := #0;
  END;
  Result := FTextBuf;
  IF Result[0] > #0 THEN
    IF Result[Ord(Result[0])] = #0 THEN Dec(Result[0]);
END;
*)
PROCEDURE (VAR w: TWinControl) SetCaption* (IN value: ARRAY OF Char);
BEGIN
  COPY(value, w.FTextBuf);
  IF SYSTEM.VAL(LONGINT, w.FHandle) > 0 THEN
    Ignore.Ptr(
      W.SendMessage(w.FHandle, W.WM_SETTEXT, NUL,
        SYSTEM.VAL(W.LPARAM, SYSTEM.ADR(w.FTextBuf))
      )
    );
  END;
END SetCaption;

PROCEDURE (VAR w: TWinControl) GetClientRect (VAR rect: W.RECT);
BEGIN
  Ignore.Int( W.GetClientRect(w.FHandle,rect) );
END GetClientRect;

PROCEDURE (VAR w: TWinControl) GetClientWidth(): Integer;
VAR
  r: W.RECT;
BEGIN
  Ignore.Int( W.GetClientRect(w.FHandle,r) );
  RETURN r.right - r.left
END GetClientWidth;

PROCEDURE (VAR w: TWinControl) GetClientHeight() : Integer;
VAR
  r: W.RECT;
BEGIN
  Ignore.Int( W.GetClientRect(w.FHandle,r) );
  RETURN r.bottom - r.top
END GetClientHeight;

PROCEDURE (VAR w: TWinControl) SetVisible* (value: BOOLEAN);
BEGIN
  w.Visible := value;
  IF w.FHandle # NUL THEN
    IF w.Visible THEN w.Show ELSE w.Hide END;
  END;
END SetVisible;
(*
PROCEDURE (VAR w: TWinControl) SetCursor(Value : TCursor);
const
  CursorMap: array[crSizeAll..crArrow] of PChar = (
    IDC_SIZEALL, IDC_HANDPT, IDC_HELP, IDC_APPSTARTING, IDC_NO, IDC_SQLWAIT,
    IDC_MULTIDRAG, IDC_VSPLIT, IDC_HSPLIT, IDC_NODROP, IDC_DRAG, IDC_WAIT,
    IDC_UPARROW, IDC_SIZEWE, IDC_SIZENWSE, IDC_SIZENS, IDC_SIZENESW, IDC_SIZE,
    IDC_IBEAM, IDC_CROSS, IDC_ARROW);
VAR
  Instance: THandle;
BEGIN
  IF Value = FCursor THEN Exit;
  IF ((Value >= crSqlWait) and (Value <= crDrag)) or
     (Value = crHandPoint) THEN Instance := HInstance
                           ELSE Instance := 0;
  FCursorHandle := LoadCursor(Instance, CursorMap[Value]);
  IF FHandle <> 0 THEN PostMessage(FHandle, WM_SetCursor, FHandle, HTCLIENT);
END;

PROCEDURE (VAR w: TWinControl) Close;
BEGIN
  SendMessage(FHandle, WM_CLOSE, 0, 0);
END;

PROCEDURE (VAR w: TWinControl) WMDestroy(VAR AMsg: TWMDestroy);
BEGIN
  IF Assigned(FOnDestroy) THEN FOnDestroy(Self);
  IF FAutoStop THEN PostQuitMessage(0);
END;

PROCEDURE (VAR w: TWinControl) WMClose(VAR AMsg: TWMClose);
BEGIN
  IF not Assigned(FOnClose) OR FOnClose(Self) THEN
  BEGIN
    IF FModalResult = 0 THEN FModalResult := mrCancel;
    with TMessage(AMsg) do
      DefWindowProc(FHandle, Msg, WParam, LParam);
  END;
  AMsg.Result := 0;
END;

PROCEDURE (VAR w: TWinControl) WMNCHitTest(VAR AMsg : TMessage);
BEGIN
  Dispatch(AMsg);
  IF FHTest <> 0 THEN AMsg.Result := FHTest
                 ELSE
  IF Assigned(FOnHitTest) THEN
    with TWMNCHitTest(AMsg) do  FOnHitTest(Self,XPos,YPos,Result)
                           ELSE
    with AMsg do Result := DefWindowProc(FHandle,Msg,WParam,LParam);
END;

PROCEDURE (VAR w: TWinControl) WMPaint(VAR AMsg: TWMPaint);
VAR
  PaintStruct: TPaintStruct;
  PaintDC: W.HDC;
  pc : PControlList;
BEGIN
  Dispatch(AMsg);
  IF AMsg.Result <> 0 THEN Exit;
  PaintDC := BeginPaint(FHandle, PaintStruct);
  IF FHandle > 0 THEN
  BEGIN
    IF FCList <> NIL THEN
    BEGIN
      pc := FCList;
      repeat
        pc^.Control.Paint(PaintDC);
        IF pc^.Next <> NIL THEN pc := pc^.Next
                           ELSE pc := NIL;
      until (pc = NIL);
    END;
  END;
  EndPaint(FHandle, PaintStruct);
END;

PROCEDURE (VAR w: TWinControl) WMSetFocus(VAR AMsg : TWMSetFocus);
BEGIN
  Dispatch(AMsg);
  IF (FActiveControl <> NIL) and
     (FActiveControl.IsModal) THEN
     BEGIN
       AMsg.Result := 0;
       PostMessage(AMsg.FocusedWnd,WM_SETFOCUS,0,0);
       Exit;
     END;
  IF FParent <> NIL THEN
  FParent.FActiveControl := Self;
END;

PROCEDURE (VAR w: TWinControl) WMKillFocus(VAR AMsg : TWMKillFocus);
VAR r   : TRect;
    s   : shortstring;
    wnd : HWND;
BEGIN
  Dispatch(AMsg);
  IF ((WS_CHILD and FStyle) <> 0) and
    (GetWindowInstance(AMsg.FocusedWnd) <> NIL) and
    not GetWindowInstance(AMsg.FocusedWnd).FEnabled THEN
  BEGIN
    AMsg.Result := 0;
    SetFocus;
    IF FParent <> NIL THEN FParent.FActiveControl := Self;
  end                                               ELSE
  IF GetWindowInstance(AMsg.FocusedWnd) = NIL THEN
  BEGIN // an "external" window receives focus:
        // any such window must have no parent (but may have childs)
        // except for MessageBox window (which is analyzied)
    wnd := AMsg.FocusedWnd;
    repeat
      s[0] := chr(GetClassName(wnd,@s[1],255));
      IF (s[0] > #0) and (s[ord(s[0])] = #0) THEN Dec(s[0]);
      IF (s[1] = '#') THEN break;
      IF GetParent(wnd) <> 0 THEN wnd := GetParent(wnd);
    until (GetParent(wnd) = 0);
    GetWindowRect(wnd,r);
    r.left := (Screen.Width + r.left - r.right) div 2;
    r.top := (Screen.Height + r.top - r.bottom) div 2;
    SetWindowPos(wnd,
                 0,
                 r.left,
                 r.top,
                 0,
                 0,
                 SWP_NOZORDER OR SWP_NOSIZE OR SWP_DRAWFRAME);
    AMsg.Result := 0;
  END;
END;

PROCEDURE (VAR w: TWinControl) WMEraseBkgnd(VAR AMsg : TWMEraseBkgnd);
VAR R : TRect;
    hd : W.HDC;
BEGIN
    Windows.GetClientRect(FHandle,R);
    hd := AMsg.DC;
    IF Assigned(FOnErase) THEN
    BEGIN
      FOnErase(Self, hd, R);
      AMsg.Result := 1;
    end                   ELSE
    IF (FBkMode = bk_OPaque) OR (FParent = NIL) THEN
      IF FBrush = 0 THEN
        Dispatch(TMessage(AMsg))
                    ELSE
      BEGIN
        FillRect(hd,R,FBrush);
        AMsg.Result := 1;
      end                                       ELSE
    IF FBkMode = bk_Transparent THEN
      BEGIN
        FillRect(hd,R,FParent.FBrush);
        AMsg.Result := 1;
      end                       ELSE AMsg.Result := 1;
END;

PROCEDURE (VAR w: TWinControl) WMCtlColor(VAR AMsg : TMessage);
VAR ctl : TWinControl;
BEGIN
  with AMsg do
  BEGIN
   ctl := TWinControl(GetProp(HWND(LParam),ID_SELF));
   IF ctl = NIL THEN Exit;
   Windows.SetBkColor(W.HDC(WParam),ctl.FColor);
   Windows.SetTextColor(W.HDC(WParam),ctl.FTextColor);
   case ctl.FBkMode of
     bk_Opaque:
       BEGIN
         Windows.SetBkMode(W.HDC(WParam),OPAQUE);
         Result := ctl.FBrush;
       END;
     bk_Transparent,bk_Slide:
       BEGIN
         Windows.SetBkMode(W.HDC(WParam),TRANSPARENT);
         repeat
           ctl := ctl.FParent;
         until ctl.FBrush > 0;
         Result := ctl.FBrush;
       END;
   END;
  END;
END;

PROCEDURE (VAR w: TWinControl) WMCommand(VAR AMsg : TWMCommand);
VAR ctrl : TWinControl;
BEGIN
  Dispatch(AMsg);
  with AMsg do
  BEGIN
   ctrl := TWinControl(GetProp(ctl,ID_SELF));
(*<kvv>*)
   IF ctrl = NIL THEN // this is menu command
   BEGIN
     IF Ctl = 0 THEN 
       IF Assigned(FOnMenuItemSelect) THEN 
         FOnMenuItemSelect(Self,TMessage(AMsg).wParam);
     Exit;
   END;
(*</kvv>*)
   case NotifyCode of
     BN_CLICKED,
     LBN_DBLCLK : IF Ctrl.FEnabled THEN ctrl.Click;
   END;
   case NotifyCode of
     EN_CHANGE,
     LBN_SELCHANGE : IF Ctrl.FEnabled THEN ctrl.Change;
   END;
   case NotifyCode of
     BN_SETFOCUS,
     EN_SETFOCUS,
     LBN_SETFOCUS,
     CBN_SETFOCUS  : IF Ctrl.FEnabled THEN ctrl.DoEnter;
   END;
   case NotifyCode of
     BN_KILLFOCUS,
     EN_KILLFOCUS,
     LBN_KILLFOCUS,
     CBN_KILLFOCUS : IF Ctrl.FEnabled THEN ctrl.DoExit;
   END;
  END;
END;

PROCEDURE (VAR w: TWinControl) DoMouseDown(VAR AMsg: TWMMouse; Button: TMouseButton;
  Shift: TShiftState);
BEGIN
  Dispatch(AMsg);
  with AMsg do
    IF Assigned(FOnMouseDown) THEN
      FOnMouseDown(Self,
                   Button,
                   KeysToShiftState(Keys) + Shift,
                   XPos,
                   YPos);
END;

PROCEDURE (VAR w: TWinControl) WMLButtonDown(VAR AMsg: TWMLButtonDown);
BEGIN
  DoMouseDown(AMsg, mbLeft, []);
END;

PROCEDURE (VAR w: TWinControl) WMLButtonDblClk(VAR AMsg: TWMLButtonDblClk);
BEGIN
  DoMouseDown(AMsg, mbLeft, [ssDouble]);
END;

PROCEDURE (VAR w: TWinControl) WMRButtonDown(VAR AMsg: TWMRButtonDown);
BEGIN
  DoMouseDown(AMsg, mbRight, []);
END;

PROCEDURE (VAR w: TWinControl) WMRButtonDblClk(VAR AMsg: TWMRButtonDblClk);
BEGIN
  DoMouseDown(AMsg, mbRight, [ssDouble]);
END;

PROCEDURE (VAR w: TWinControl) WMMouseMove(VAR AMsg: TWMMouseMove);
BEGIN
  Dispatch(AMsg);
  with AMsg do
    IF Assigned(FOnMouseMove) THEN
      FOnMouseMove(Self,
                   KeysToShiftState(Keys),
                   XPos,
                   YPos);
END;

PROCEDURE (VAR w: TWinControl) DoMouseUp(VAR AMsg: TWMMouse; Button: TMouseButton;
  Shift: TShiftState);
BEGIN
  Dispatch(AMsg);
(*$IFDEF CaptureMouse*)
  ReleaseCapture;
(*$ENDIF*)
  with AMsg do
  IF Assigned(FOnMouseUp) THEN
    FOnMouseUp(Self,
               Button,
               KeysToShiftState(Keys) + Shift,
               XPos,
               YPos);
END;

PROCEDURE (VAR w: TWinControl) WMLButtonUp(VAR AMsg: TWMLButtonUp);
BEGIN
  DoMouseUp(AMsg, mbLeft, []);
END;

PROCEDURE (VAR w: TWinControl) WMRButtonUp(VAR AMsg: TWMRButtonUp);
BEGIN
  DoMouseUp(AMsg, mbRight, []);
END;

PROCEDURE (VAR w: TWinControl) WMSetCursor(VAR AMsg: TWMSetCursor);
BEGIN
  IF (FCursor <> crDefault) and
     (AMsg.HitTest = HTCLIENT) THEN
  BEGIN
    Windows.SetCursor(FCursorHandle);
    AMsg.Result := 1;
  end                          ELSE Dispatch(AMsg);
END;

PROCEDURE (VAR w: TWinControl) DoKeyDown(VAR AMsg: TWMKey): Boolean;
VAR
  ShiftState: TShiftState;
  Form: TWinControl;
BEGIN
  Result := TRUE;
  Form := Self;
  WHILE (Form.FClassName <> FormClassName) and
        (Form.Parent <> NIL) DO Form := Form.Parent;
  IF (Form <> Self) and Form.DoKeyDown(AMsg) THEN Exit;
  with AMsg do
  BEGIN
    ShiftState := KeyDataToShiftState(KeyData);
    IF CharCode = VK_Tab  THEN
    BEGIN
      IF (ssShift in ShiftState) THEN
      BEGIN
        WHILE (Form.FClassName <> FormClassName) and
              Form.IsFirstSelected and
              (Form.FParent <> NIL) DO Form := Form.FParent;
        Form.SelectPrev;
        IF Assigned(FOnKeyDown) THEN FOnKeyDown(Self, CharCode, ShiftState);
        Exit;
      end                        ELSE
      BEGIN
        WHILE (Form.FClassName <> FormClassName) and
              Form.IsLastSelected and
              (Form.FParent <> NIL) DO Form := Form.FParent;
        Form.SelectNext;
        IF Assigned(FOnKeyDown) THEN FOnKeyDown(Self, CharCode, ShiftState);
        Exit;
      END;
    END;
    IF Assigned(FOnKeyDown) THEN FOnKeyDown(Self, CharCode, ShiftState);
    IF CharCode = 0 THEN Exit;
  END;
  Result := FALSE;
END;

PROCEDURE (VAR w: TWinControl) WMKeyDown(VAR AMsg: TWMKeyDown);
BEGIN
  IF not DoKeyDown(AMsg) THEN Dispatch(AMsg);
END;

PROCEDURE (VAR w: TWinControl) WMSysKeyDown(VAR AMsg: TWMKeyDown);
BEGIN
  IF not DoKeyDown(AMsg) THEN Dispatch(TMessage(AMsg));
END;

PROCEDURE (VAR w: TWinControl) DoKeyUp(VAR AMsg: TWMKey): Boolean;
VAR
  ShiftState: TShiftState;
  Form: TWinControl;
BEGIN
  Result := TRUE;
  Form := Self;
  WHILE Form.Parent <> NIL DO Form := Form.Parent;
  IF (Form <> Self) and Form.DoKeyUp(AMsg) THEN Exit;
  with AMsg do
  BEGIN
    ShiftState := KeyDataToShiftState(KeyData);
    IF Assigned(FOnKeyUp) THEN FOnKeyUp(Self, CharCode, ShiftState);
    IF CharCode = 0 THEN Exit;
  END;
  Result := FALSE;
END;

PROCEDURE (VAR w: TWinControl) WMKeyUp(VAR AMsg: TWMKeyUp);
BEGIN
  IF not DoKeyUp(AMsg) THEN Dispatch(AMsg);
END;

PROCEDURE (VAR w: TWinControl) WMSysKeyUp(VAR AMsg: TWMKeyUp);
BEGIN
  IF not DoKeyUp(AMsg) THEN Dispatch(AMsg);
END;

PROCEDURE (VAR w: TWinControl) DoKeyPress(VAR AMsg: TWMKey): Boolean;
VAR
  Form: TWinControl;
BEGIN
  Result := TRUE;
  Form := Self;
  WHILE Form.Parent <> NIL DO Form := Form.Parent;
  IF (Form <> Self) and Form.DoKeyPress(AMsg) THEN Exit;
  with AMsg do
  BEGIN
    IF Assigned(FOnKeyPress) THEN FOnKeyPress(Self,Char(CharCode));
    IF Char(CharCode) = #0 THEN Exit;
  END;
  Result := FALSE;
END;

PROCEDURE (VAR w: TWinControl) WMChar(VAR AMsg: TWMChar);
BEGIN
  IF not DoKeyPress(AMsg) THEN Dispatch(AMsg);
END;

PROCEDURE (VAR w: TWinControl) WMSysCommand(VAR AMsg: TWMSysCommand);
BEGIN
  Dispatch(AMsg);
END;

PROCEDURE (VAR w: TWinControl) WMNotifyIcon(VAR AMsg: TMessage);
BEGIN
  case AMsg.LParam of
   WM_MOUSEMOVE   :if Assigned(FOnNIMove) THEN FOnNIMove(Self);
   WM_LBUTTONDOWN :if Assigned(FOnNILDown) THEN FOnNILDown(Self);
   WM_LBUTTONUP   :if Assigned(FOnNILUp) THEN FOnNILUp(Self);
  END;
END;

PROCEDURE (VAR w: TWinControl) WMQueryEndSession(VAR AMsg: TMessage);
BEGIN
  IF Assigned(FOnEndSession) THEN
     IF FOnEndSession(Self) THEN AMsg.Result := 1
                            ELSE AMsg.Result := 0
                             ELSE Dispatch(AMsg);
END;

PROCEDURE (VAR w: TWinControl) Dispatch (VAR AMsg: TMessage);
BEGIN(*
   inherited Dispatch(AMsg);
   with TMessage(AMsg) do
   BEGIN
     IF TMessage(AMsg).Result <> 0 THEN Exit;
     IF FDefWndProc <> 0 THEN
       Result := CallWindowProc(Ptr(FDefWndProc),
                                FHandle,
                                Msg,
                                WParam,
                                LParam)
                         ELSE
       Result := DefWindowProc(FHandle,Msg,WParam,LParam);
   END;
END Dispatch;

PROCEDURE (VAR w: TWinControl) Change;
BEGIN
  IF Assigned(FOnChange) THEN FOnChange(Self);
END;

PROCEDURE (VAR w: TWinControl) Click;
BEGIN
  IF Assigned(FOnClick) THEN FOnClick(Self);
END;

PROCEDURE (VAR w: TWinControl) DoEnter;
BEGIN
  IF Assigned(FOnEnter) THEN FOnEnter(Self);
END;

PROCEDURE (VAR w: TWinControl) DoExit;
BEGIN
  IF Assigned(FOnExit) THEN FOnExit(Self);
END;
*)*)
PROCEDURE (VAR w: TWinControl) SetColor* (value: Ut.TColor);
VAR
  tb, ob: W.HBRUSH;
BEGIN
  IF SYSTEM.VAL(LONGINT, w.FHandle) > 0 THEN
    tb := W.CreateSolidBrush(value);
    ob := W.SelectObject(w.FDC, tb);
    Ignore.Int( W.DeleteObject(ob) );
    w.Brush := tb;
  ELSE
    IF SYSTEM.VAL(LONGINT, w.Brush) > 0 THEN
      Ignore.Int( W.DeleteObject(w.Brush) );
    END;
    w.Brush := W.CreateSolidBrush(value);
  END;
  w.Color := value;
END SetColor;

PROCEDURE (VAR w: TWinControl) SetTextColor* (value: Ut.TColor);
BEGIN
  Ignore.Int( W.SetTextColor(w.FDC, value) );
  w.TextColor := value;
END SetTextColor;
(*
PROCEDURE (VAR w: TWinControl) WMHelp(VAR AMsg: TMessage);
VAR hi : PHelpInfo;
    W  : TWinControl;
    s  : shortstring;
BEGIN
  hi := Ptr(AMsg.lparam);
  IF hi^.dwContextId = 0 THEN // исходная точка
  BEGIN
    W := TWinControl(GetProp(hi^.hItemHandle,ID_SELF));
    IF W.FHelpContext > 0 THEN
    BEGIN
      hi^.dwContextId := W.FHelpContext;
      WHILE (W.FStyle and ws_Child <> 0) and
            (W.FParent <> NIL) DO W := W.FParent;
      SendMessage(W.FHandle,WM_HELP,0,AMsg.lparam);
    END;
  end                    ELSE
  IF FStyle and ws_Child = 0 THEN // если родительское окно
  BEGIN
    s := FHelpFile + #0;
    WinHelp(FHandle,@s[1],HELP_CONTEXT,hi^.dwContextId);
  END;
  AMsg.Result := 1;
END;

PROCEDURE (VAR w: TWinControl) ProcessMessage(VAR AMsg: TMessage);
BEGIN
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
    ELSE Dispatch(AMsg);
  END;
END;

PROCEDURE FindLastControl(VAR ppar,pson : PControlList);
VAR pp,pn : PControlList;
BEGIN
   IF ppar = NIL THEN // if parent = NIL
   BEGIN
     pson := NIL;     // then son = NIL too
   end           ELSE
   IF ppar^.Next = NIL THEN // if last in chain
   BEGIN
     pson := ppar; // this is the last
     ppar := NIL;  // and no parent
   end                ELSE
   IF ppar.Next^.Next = NIL THEN // if pre-last
     BEGIN
       pson := ppar^.Next;
     end                    ELSE // if above then go down...
     BEGIN
       repeat
         pp := ppar^.Next;
         pn := pp^.Next;
         IF pn <> NIL THEN
         BEGIN
           ppar := pp; pson := pn;
         END;
       until pn^.Next = NIL;
     END;
END;

PROCEDURE FindLastWindow(VAR ppar,pson : PWinControlList);
VAR pp,pn : PWinControlList;
BEGIN
   IF ppar = NIL THEN // if parent = NIL
   BEGIN
     pson := NIL;     // then son = NIL too
   end           ELSE
   IF ppar^.Next = NIL THEN // if last in chain
   BEGIN
     pson := ppar; // this is the last
     ppar := NIL;  // and no parent
   end                ELSE
   IF ppar^.Next^.Next = NIL THEN // if pre-last
     BEGIN
       pson := ppar^.Next;
     end                    ELSE // if above then go down...
     BEGIN
       repeat
         pp := ppar^.Next;
         pn := pp^.Next;
         IF pn <> NIL THEN
         BEGIN
           ppar := pp; pson := pn;
         END;
       until pn^.Next = NIL;
     END;
END;

destructor TWinControl.Destroy;
VAR wp,ws,wt : PWinControlList;
    cp,cs,ct : PControlList;
BEGIN
  repeat
    wp := FWList;
    FindLastWindow(wp,ws);
    wt := ws;
    IF ws <> NIL THEN
    BEGIN
      ws^.WinControl.Free;
      dispose(ws);
      IF wp <> NIL THEN wp^.Next := NIL
                   ELSE wt := NIL;
    END;
  until (wt = NIL);
  repeat
    cp := FCList;
    FindLastControl(cp,cs);
    ct := cs;
    IF cs <> NIL THEN
    BEGIN
      cs^.Control.Free;
      dispose(cs);
      IF cp <> NIL THEN cp^.Next := NIL
                   ELSE ct := NIL;
    END;
  until (ct = NIL);
  FFont.Free;
  IF FBrush <> 0 THEN DeleteObject(FBrush);
  DestroyWnd;
  ProcessMessages;
  inherited Destroy;
END;
*)
PROCEDURE (VAR w: TWinControl) CreateParams(VAR Params: TCreateParams);
BEGIN(*
  FillChar(Params, SizeOf(Params), 0);
  IF FTextBuf[ord(FTextBuf[0])] <> #0 THEN FTextBuf := FTextBuf + #0;
  Params.Caption := @FTextBuf[1];
  Params.Style := FStyle;
  Params.ExStyle := FExStyle;
  with Params do
  BEGIN
    X := FLeft;
    Y := FTop;
    Width := FWidth;
    IF (FStyle and WS_CAPTION) > 0 THEN
     FHeight := FHeight + GetSystemMetrics(SM_CYCAPTION);
    Height := FHeight;
    WndParent := 0;
    WndParent := ParentHandle;
    WindowClass.style := CS_VREDRAW + CS_HREDRAW + CS_DBLCLKS;
    WindowClass.lpfnWndProc := GetWndProc;
    WindowClass.hIcon := LoadIcon(HInstance, 'MAINICON');
    WindowClass.hCursor := FCursorHandle;
    IF FBrush = 0 THEN FBrush := CreateSolidBrush(FColor);
    WindowClass.hbrBackground := FBrush;
    StrPCopy(WinClassName, FClassName);
  END;*)
END CreateParams;

PROCEDURE (VAR w: TWinControl) CreateWnd* ;
VAR
  Params: TCreateParams;
  TempClass: W.WNDCLASS;
  ClassRegistered : BOOLEAN;
BEGIN
  w.CreateParams(Params);
  ClassRegistered := 0 # W.GetClassInfo(HInstance,
    SYSTEM.VAL(W.PtrSTR, SYSTEM.ADR(Params.WinClassName)), TempClass);
  IF ~ ClassRegistered THEN
    (*Params.WindowClass.lpfnWndProc := GetWndProc;*)
    Params.WindowClass.hInstance := HInstance;
    (*COPY(Params.WinClassName, Params.WindowClass.lpszClassName);*)
    IF W.RegisterClass(Params.WindowClass) = 0 THEN
      Ignore.Int( W.MessageBox(NUL,
        SYSTEM.VAL(W.PtrSTR, SYSTEM.ADR("WinRegister failed")), NIL, W.MB_OK)
      );
      HALT(0)
    END;
  END;
  (*w.CreateWindowHandle(Params);*)
(*  Invalidate; *)
END CreateWnd;

PROCEDURE (VAR w: TWinControl) CreateWindowHandle (IN Params: TCreateParams);
BEGIN
  w.FHandle := W.CreateWindowEx(
    w.ExStyle,
    SYSTEM.VAL(W.PtrSTR, SYSTEM.ADR(Params.WinClassName)),
    SYSTEM.VAL(W.PtrSTR, SYSTEM.ADR(w.FTextBuf[0])),
    w.Style,
    w.Left, w.Top, w.Width, w.Height,
    Params.WndParent,
    NUL,
    HInstance,
    NIL
  );
  IF w.FHandle = NUL THEN
      Ignore.Int( W.MessageBox(NUL,
        SYSTEM.VAL(W.PtrSTR, SYSTEM.ADR("WinCreate failed")), NIL, W.MB_OK)
      );
      HALT(0)
  END;
  Ignore.Int(
    W.SetProp(w.FHandle,SYSTEM.VAL(W.PtrSTR, SYSTEM.ADR(ID_SELF)),
      SYSTEM.VAL(W.HANDLE, w))
  );
  Ignore.Int(
    W.EnableWindow(w.FHandle, SYSTEM.VAL(W.BOOL, w.Enabled))
  );
  IF (w.Parent = NIL) & (SYSTEM.VAL(PWinControl, MainWindow) = NIL) THEN
    MainWindow := w;
  END;
(*  IF Assigned(FOnCreate) THEN FOnCreate(Self);
  IF w.FFont # NIL THEN w.FFont.UpdateFont END;*)
(*  Windows.SetCursor(FCursorHandle); *)
  IF w.Visible THEN w.Show END;
END CreateWindowHandle;
(*
PROCEDURE (VAR w: TWinControl) DestroyWnd;
BEGIN
  DestroyWindowHandle;
END;

PROCEDURE (VAR w: TWinControl) DestroyWindowHandle;
BEGIN
  RemoveProp(FHandle,ID_SELF);
  DestroyWindow(FHandle);
  IF MainWindow = Self THEN MainWindow := NIL;
END;
*)
PROCEDURE (VAR w: TWinControl) Show;
BEGIN
  Ignore.Int( W.ShowWindow(w.FHandle, W.SW_SHOW) );
  Ignore.Int( W.UpdateWindow(w.FHandle) );
END Show;

PROCEDURE (VAR w: TWinControl) Hide;
BEGIN
  Ignore.Int( W.ShowWindow(w.FHandle, W.SW_HIDE) );
END Hide;

PROCEDURE (VAR w: TWinControl) IsParentHandle (AHandle: W.HWND): BOOLEAN;
(*
  PROCEDURE FindHandle(Ctrl : TWinControl; Wnd : HWnd) : BOOLEAN;
  VAR pp,pn : pointer;
  BEGIN
   Result := false;
   IF Wnd = Ctrl.FHandle THEN // нашли самого
   BEGIN
     Result := true; Exit;
   END;
   IF (Ctrl.FWList = NIL) or
      (Ctrl.FWList^.WinControl = NIL) THEN Exit; // нет детей
   pp := Ctrl.FWList;
   repeat
     IF PWinControlList(pp)^.Wincontrol.FHandle = Wnd THEN // нашли самого
     BEGIN
       Result := true; Exit;
     END;
     IF PWinControlList(pp)^.Wincontrol.FWList <> NIL THEN // есть дети
     BEGIN
       IF FindHandle(PWinControlList(pp)^.Wincontrol, Wnd) THEN
       BEGIN
         Result := true; Exit;
       END;
     END;
     pn := PWinControlList(pp)^.Next;
     IF pn <> NIL THEN pp := pn;
   until (pn = NIL);
  END;

BEGIN
   Result := false;
   IF (AHandle = INVALID_HANDLE_VALUE) or
      (FParent = NIL) or
      (FParent.FWList = NIL) or
      (FParent.FWList^.WinControl = NIL) THEN Exit;
   Result := FindHandle(FParent, AHandle);
*)END IsParentHandle;

PROCEDURE (VAR w: TWinControl) ProcessMsg (VAR Msg: W.MSG): BOOLEAN;
VAR
  result: BOOLEAN;
BEGIN
  result := FALSE;
  IF 0 # W.PeekMessage(Msg, NUL, 0, 0, W.PM_REMOVE) THEN
    result := TRUE;
    IF Msg.message # W.WM_QUIT THEN
      Ignore.Int( W.TranslateMessage(Msg) );
      Ignore.Int( W.DispatchMessage(Msg) );
    ELSE
      (*W.Dispatch(Msg);*)
    END;
  END;
  RETURN result
END ProcessMsg;

PROCEDURE (VAR w: TWinControl) ProcessMessages;
VAR
  Msg: W.MSG;
BEGIN
  WHILE w.ProcessMsg(Msg) DO END; (*loop*)
END ProcessMessages;

PROCEDURE (VAR w: TWinControl) ShowModal* (): TModalResult;
VAR
  aMessage: W.MSG; result: TModalResult;
BEGIN
  w.IsModal := TRUE;
  w.FModalResult := 0;
  WHILE w.FModalResult = 0 DO
    Ignore.Int( W.GetMessage(aMessage, NUL, 0, 0) );
    Ignore.Int( W.TranslateMessage(aMessage) );
    IF (w.Parent = NIL) OR
       (aMessage.message = W.WM_PAINT) OR
       (aMessage.message = W.WM_QUIT) OR
       ~ w.IsParentHandle(aMessage.hwnd)
    THEN
      Ignore.Int( W.DispatchMessage(aMessage) );
    END;
  END;
  IF (w.FModalResult = 0) THEN
    result := SYSTEM.VAL(TModalResult, aMessage.wParam);
  ELSE
    result := w.FModalResult;
  END;
  w.FModalResult := 0;
  w.IsModal := FALSE;
END ShowModal;

PROCEDURE (VAR w: TWinControl) EndModal (value: TModalResult);
BEGIN
  IF w.IsModal THEN w.FModalResult := value END;
END EndModal;

PROCEDURE (VAR w: TWinControl) Invalidate;
BEGIN
  IF w.Parent = NIL THEN
    Ignore.Int( W.ShowWindow(w.FHandle, CmdShow) );
  END;
  Ignore.Int( W.InvalidateRect(w.FHandle,NIL,1 (*TRUE*) ) );
  Ignore.Int( W.UpdateWindow(w.FHandle) );
END Invalidate;

PROCEDURE (VAR w: TWinControl) SetFocus;
BEGIN
  Ignore.Ptr( W.SetFocus(w.FHandle) );
END SetFocus;
(*
PROCEDURE (VAR w: TWinControl) InsertControl(AControl : TControl);
VAR pn : PControlList;
    cp,cs : PControlList;
BEGIN
   pn := new(PControlList);
   pn^.Control := AControl;
   pn^.Next := NIL;
   FindLastControl(cp,cs);
   IF cs = NIL THEN FCList := pn
               ELSE cs^.Next := pn;
   Invalidate;
END;

PROCEDURE (VAR w: TWinControl) InsertWinControl(AControl : TWinControl);
VAR pn : PWinControlList;
    wp,ws : PWinControlList;
BEGIN
  pn := new(PWinControlList);
  pn^.WinControl := AControl;
  pn^.Next := NIL;
  wp := FWList;
  FindLastWindow(wp,ws);
  IF ws = NIL THEN FWList := pn
              ELSE ws^.Next := pn;
END;

PROCEDURE FindWindow(pl    : PWinControlList;
                     pp    : TWinControl;
                 Var pprev : TWinControl;
                 Var pnext : TWinControl);
VAR p,temp : PWinControlList;
BEGIN
   pprev := NIL;
   pnext := NIL;
   IF pl <> NIL THEN
   BEGIN
     IF (pp = NIL) or
        ((pp = pl^.WinControl)and (pl^.Next = NIL)) THEN
     BEGIN
       pprev := pp;
       pnext := pp;
       Exit;
     END;
     p := pl;
     repeat
       IF p^.WinControl = pp THEN // is found
       BEGIN
         IF p^.Next = NIL THEN                    // the last
           pnext := pl^.WinControl                // the first will be next
                          ELSE
           pnext := p^.Next^.WinControl;
          p := pl;
          IF p^.WinControl = pp THEN                 // the first
          BEGIN
            temp := p;
            FindLastWindow(temp,pl);
            pprev := pl^.WinControl  // the last will be previous
          end                   ELSE
          BEGIN
            WHILE (p^.Next^.WinControl <> pp) DO p := p^.Next;
            pprev := p^.WinControl;
          END;
          Exit;
       END;
       p := p^.Next;
     until false;
   END;
END;

PROCEDURE (VAR w: TWinControl) SelectPrev;
VAR pp,pn : TWinControl;
BEGIN
  IF FActiveControl = NIL THEN SelectFirst
                          ELSE
  BEGIN
    FindWindow(FWList,FActiveControl,pp,pn);
    IF pp <> NIL THEN
    BEGIN
      FActiveControl := pp;
      IF pp.FEnabled and  pp.FTabStop THEN pp.SetFocus
                                      ELSE
        WHILE not FActiveControl.FEnabled or
            not FActiveControl.FTabStop DO SelectPrev;
    END;
  END;
END;

PROCEDURE (VAR w: TWinControl) SelectNext;
VAR pp,pn : TWinControl;
BEGIN
  IF FActiveControl = NIL THEN SelectFirst
                          ELSE
  BEGIN
    FindWindow(FWList,FActiveControl,pp,pn);
    IF pn <> NIL THEN
    BEGIN
      FActiveControl := pn;
      IF pn.FEnabled and  pn.FTabStop THEN pn.SetFocus
                     ELSE
      WHILE not FActiveControl.FEnabled or
            not FActiveControl.FTabStop DO SelectNext;
    END;
  END;
END;

PROCEDURE (VAR w: TWinControl) SelectFirst;
VAR pp : PWinControlList;
BEGIN
  IF (FWList <> NIL) THEN
  BEGIN
    pp := FWList;
    FActiveControl := pp^.WinControl;
    IF pp^.WinControl.FEnabled THEN
    BEGIN
      pp^.WinControl.SetFocus;
      FActiveControl := pp^.WinControl;
    end                        ELSE
      WHILE not FActiveControl.FEnabled DO SelectNext;
  END;
END;

PROCEDURE (VAR w: TWinControl) SelectLast;
VAR pp,temp : PWinControlList;
BEGIN
  IF (FWList <> NIL) THEN
  BEGIN
    temp := FWList;
    FindLastWindow(temp,pp);
    IF pp = NIL THEN Exit;
    IF pp^.WinControl <> NIL THEN
    BEGIN
      IF pp^.WinControl.FEnabled THEN
      BEGIN
        pp^.WinControl.SetFocus;
        FActiveControl := pp^.WinControl;
      end                        ELSE
        WHILE not FActiveControl.FEnabled DO SelectPrev;
    END;
  END;
END;

PROCEDURE (VAR w: TWinControl) IsFirstSelected : BOOLEAN;
BEGIN
  Result := (FActiveControl <> NIL) and
            (FActiveControl = FWList^.WinControl);
END;

PROCEDURE (VAR w: TWinControl) IsLastSelected : BOOLEAN;
VAR pp,ps : PWinControlList;
BEGIN
  Result := false;
  IF FActiveControl = NIL THEN Exit;
  pp := FWList;
  FindLastWindow(pp,ps);
  IF ps = NIL THEN Exit;
  Result := ps^.WinControl = FActiveControl;
END;

(*TStdControl*)

PROCEDURE TStdControl.CreateWnd;
BEGIN
    IF FCtl3D THEN
    BEGIN
      FExStyle := FExStyle OR ws_Ex_ClientEdge;
      FStyle := FStyle and not ws_Border;
    END;
    IF FBkMode in [bk_Transparent,bk_Slide] THEN
      FExStyle := FExStyle OR WS_EX_TRANSPARENT;
    IF FTextBuf[ord(FTextBuf[0])] <> #0 THEN FTextBuf := FTextBuf + #0;
    FHandle := CreateWindowEx(
      FExStyle,
      PChar(FClassName),
      @FTextBuf[1],
      FStyle OR ws_Child OR ws_Visible,
      FLeft, FTop, FWidth, FHeight,
      ParentHandle,
      0,
      HInstance,
      NIL);
    IF FHandle = 0 THEN
    BEGIN
      MessageBox(0, 'StdCreate failed', NIL, mb_Ok);
      halt;
    END;
    SetProp(FHandle,ID_SELF,THandle(Self));
    FDefWndProc := GetWindowLong(FHandle,GWL_WNDPROC);
    SetWindowLong(FHandle,GWL_WNDPROC,Longint(GetWndProc));
    Windows.EnableWindow(FHandle, FEnabled);
    IF FFont <> NIL THEN FFont.UpdateFont;
//    Windows.SetCursor(FCursorHandle);
END;

(*TLabel*)

constructor TLabel.Create(AParent: TWinControl);
BEGIN
  inherited Create(AParent);
  FWidth := 121;
  FHeight := 25;
  FBkMode := bk_Transparent;
  FFormat := DT_VCENTER OR DT_WORDBREAK;
  FClassName := 'STATIC';
  FStyle := ws_Child OR ws_Visible;
  FOnHitTest := HitTest;
END;

PROCEDURE TLabel.WMPaint(VAR AMsg: TWMPaint);
VAR
   DC : W.HDC;
   ps : TPaintStruct;
   PC : PChar;
   L  : Cardinal;
   R  : TRect;
   fo : HFont;
BEGIN
  IF FBkMode <> bk_Slide THEN Dispatch(AMsg)
                         ELSE
  BEGIN
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
    IF (FStyle and SS_CENTER) = SS_CENTER THEN
      FFormat := FFormat OR DT_CENTER     ELSE
    IF (FStyle and SS_RIGHT) = SS_RIGHT THEN
      FFormat := FFormat OR DT_RIGHT;
    DrawTextEx(DC,      // handle to device context
               PC,      // pointer to string to draw
               L-1,     // length of string to draw
               R,       // pointer to rectangle coordinates
               FFormat, // formatting options
               NIL      // pointer to structure for more options
               );
    SelectObject(DC,fo);
    EndPaint(FHandle,ps);
    GlobalFree(Cardinal(PC));
  END;
END;

PROCEDURE TLabel.WMEraseBkgnd(VAR AMsg : TWMEraseBkgnd);
BEGIN
  IF FBkMode <> bk_Slide THEN inherited;
END;

PROCEDURE TLabel.HitTest(Sender: TObject; X, Y : Integer;
                         VAR Result : Integer);
BEGIN
  Result := HTTRANSPARENT;
END;

(*TEdit*)

constructor TEdit.Create(AParent: TWinControl);
BEGIN
  inherited Create(AParent);
  FWidth := 121;
  FHeight := 24;
  FClassName := 'EDIT';
  FStyle := ws_Child OR ws_Border;
  FTabStop := true;
END;

PROCEDURE TEdit.DoKeyPress(VAR AMsg: TWMKey): Boolean;
BEGIN
  Result := inherited DoKeyPress(AMsg) OR (Char(AMsg.CharCode) = #9);
END;

PROCEDURE TEdit.GetMaxLength : Integer;
BEGIN
  Result := SendMessage(FHandle,EM_GETLIMITTEXT,0,0);
END;

PROCEDURE TEdit.SetMaxLength(Value : Integer);
BEGIN
  SendMessage(FHandle,EM_SETLIMITTEXT,Value,0);
END;

PROCEDURE TEdit.GetMargin : word;
BEGIN
  Result := Lo(SendMessage(FHandle,EM_GETMARGINS,0,0));
END;

PROCEDURE TEdit.SetMargin(Value: word);
BEGIN
  SendMessage(FHandle,
              EM_SETMARGINS,
              EC_LEFTMARGIN OR EC_RIGHTMARGIN,
              MakeLong(Value,Value));
END;

(*<fduch> *)
(* THotKey *)
constructor THotKey.Create(AParent: TWinControl);
BEGIN
  inherited Create(AParent);
  FWidth := 100;
  FHeight := 24;
  FClassName := HOTKEYCLASS;
  FStyle := ws_Child OR ws_Border;
  FTabStop := true;
END;

PROCEDURE THotKey.GetHotKey: Byte;
VAR
  AHotKey:Word;
BEGIN
  AHotKey:=SendMessage(FHandle, HKM_GETHOTKEY, 0, 0);
  FHotKey:=Lo(AHotKey);
  FMod:=Hi(AhotKey);
  Result:=FHotKey;
END;

PROCEDURE THotKey.GetModifiers: THKModifiers;
BEGIN
  FModifiers:=[];
  IF (FMod and HOTKEYF_ALT)<>0 THEN Include(FModifiers, hkAlt);
  IF (FMod and HOTKEYF_CONTROL)<>0 THEN Include(FModifiers, hkCtrl);
  IF (FMod and HOTKEYF_SHIFT)<>0 THEN Include(FModifiers, hkShift);
  IF (FMod and HOTKEYF_EXT)<>0 THEN Include(FModifiers, hkExt);
  Result:=FModifiers;
END;

PROCEDURE THotKey.GetSHotKey: string;
BEGIN
  IF (hkCtrl in FModifiers) THEN Result:=Result+'Ctrl+';
  IF (hkAlt in FModifiers) THEN Result:=Result+'Alt+';
  IF (hkShift in FModifiers) THEN Result:=Result+'Shift+';
  Result:=Result+char(FHotKey);
END;

PROCEDURE THotKey.SetSHotKey(const Value: string);
VAR
  s, CurToken: string;
BEGIN
  s:=Value;
  WHILE Pos('+', S)>0 DO
  BEGIN
    CurToken:=UpperCase(Copy(S, 1, Pos('+', S)-1));
    Delete(S, 1, Pos('+', S));
    IF CurToken='ALT' THEN Include(FModifiers, hkAlt);
    IF CurToken='CTRL' THEN Include(FModifiers, hkCtrl);
    IF CurToken='SHIFT' THEN Include(FModifiers, hkShift);
  END;
  HotKey:=ord(S[1]);
END;

PROCEDURE THotKey.SetHotKey(const Value: Byte);
BEGIN
  SendMessage(FHandle, HKM_SETHOTKEY, MakeWord(Value, Fmod),0);
  FHotKey:=Value;
END;

PROCEDURE THotKey.SetInvalidKeys(const Value: THKInvalidKeys);
BEGIN
  FInvalidKeys := Value;
  SendMessage(FHandle, HKM_SETRULES, Byte(Value), MakeLong(Byte(FModifiers), 0));
  SendMessage(FHandle, HKM_SETHOTKEY, MakeWord(FHotkey, Fmod),0);
END;

PROCEDURE THotKey.SetModifiers(const Value: THKModifiers);
BEGIN
  FMod:=0;
  IF hkAlt in Value THEN FMod:=FMod OR HOTKEYF_ALT;
  IF hkCtrl in Value THEN FMod:=FMod OR HOTKEYF_CONTROL;
  IF hkShift in Value THEN FMod:=FMod OR HOTKEYF_SHIFT;
  IF hkExt in Value THEN FMod:=FMod OR HOTKEYF_Ext;
END;

PROCEDURE THotKey.GetModif: byte;
VAR
  AHotKey:Word;
BEGIN
  AHotKey:=SendMessage(FHandle, HKM_GETHOTKEY, 0, 0);
  FHotKey:=Lo(AHotKey);
  FMod:=Hi(AHotKey);
  Result:=FMod;
END;

PROCEDURE THotKey.SetModif(const Value: byte);
BEGIN
  SendMessage(FHandle, HKM_SETHOTKEY, MakeWord(FHotKey, Value),0);
  FMod:=Value;
END;
(*</fduch>*)

(*TListBox*)

constructor TListBox.Create(AParent: TWinControl);
BEGIN
  inherited Create(AParent);
  FWidth := 120;
  FHeight := 99;
  FClassName := 'LISTBOX';
  FStyle := ws_child OR ws_Border OR lbs_Notify (*or lbs_Sort*) or
            lbs_NoIntegralHeight OR ws_Visible;
  FTabStop := true;
END;

PROCEDURE TListBox.SetSorted(Value: BOOLEAN);
BEGIN
  IF Value THEN FStyle := FStyle OR lbs_Sort
           ELSE FStyle := FStyle and not lbs_Sort;
END;

PROCEDURE TListBox.GetCount: Integer;
BEGIN
  Result := SendMessage(FHandle, LB_GETCOUNT, 0, 0);
END;

PROCEDURE TListBox.GetFocused: Integer;
BEGIN
  Result := SendMessage(FHandle, LB_GETCARETINDEX, 0, 0);
END;

PROCEDURE TListBox.SetFocused(Value: Integer);
BEGIN
  SendMessage(FHandle, LB_SETCARETINDEX, Value, MAKELPARAM(word(false),0));
  SendMessage(FHandle, LB_SETCURSEL, Value, 0);
END;

PROCEDURE TListBox.SelectItem(Value: Integer);
BEGIN
  SendMessage(FHandle, LB_SETCURSEL, Value, 0);
END;

PROCEDURE TListBox.Get(Index: Integer): shortstring;
VAR
  Text: shortstring;
BEGIN
  Text[0] := chr(SendMessage(FHandle, LB_GETTEXT, Index, Longint(@Text[1])));
  Result := Text;
END;

PROCEDURE TListBox.GetObject(Index: Integer): TObject;
BEGIN
  Result := NIL;
  IF (Index < 0) OR (Index >= Count) THEN Exit;
  Result := TObject(SendMessage(FHandle, LB_GETITEMDATA, Index, 0));
  IF Longint(Result) = LB_ERR THEN FError := -1;
END;

PROCEDURE TListBox.Put(Index: Integer; const S: shortstring);
BEGIN
  IF (Index < 0) OR (Index > Count) THEN Exit;
  IF Index = Count THEN
  BEGIN
    Add(S); Exit;
  END;
  Delete(Index);
  Insert(Index,S);
END;

PROCEDURE TListBox.PutObject(Index: Integer; AObject: TObject);
BEGIN
  IF (Index < 0) OR (Index >= Count) THEN Exit;
  SendMessage(FHandle, LB_SETITEMDATA, Index, Longint(AObject));
END;

PROCEDURE TListBox.Add(const S: shortstring): Integer;
VAR ss : array [1..256] of char;
BEGIN
  Move(s[1],ss[1],Ord(s[0]));
  ss[Ord(s[0])+1] := #0;
  Result := SendMessage(FHandle, LB_ADDSTRING, 0, Longint(@ss));
  IF Result < 0 THEN FError := -1;
  IF Count = 1 THEN Focused := 0;
END;

PROCEDURE TListBox.Insert(Index: Integer; const S: shortstring);
VAR ss : array [1..256] of char;
BEGIN
  IF (Index < 0) OR (Index > Count) THEN Exit;
  Move(s[1],ss[1],Ord(s[0]));
  ss[Ord(s[0])+1] := #0;
  IF SendMessage(FHandle, LB_INSERTSTRING, Index,
    Longint(@Ss)) < 0 THEN FError := -1;
  IF Count = 1 THEN Focused := 0;
END;

PROCEDURE TListBox.Delete(Index: Integer);
VAR cf, cc : Integer;
BEGIN
  IF (Index < 0) OR (Index >= Count) THEN Exit;
  cf := Focused;
  cc := Count;
  SendMessage(FHandle, LB_DELETESTRING, Index, 0);
  IF Count = 0 THEN SelectItem(-1);
  IF cf >= cc - 1 THEN Focused := cc - 2;
END;

PROCEDURE TListBox.Clear;
BEGIN
  IF Count <= 0 THEN Exit;
  SendMessage(FHandle, LB_RESETCONTENT, 0, 0);
  SelectItem(-1);
END;

(*TComboBox*)

constructor TComboBox.Create(AParent: TWinControl);
BEGIN
  inherited Create(AParent);
  FWidth := 120;
  FHeight := 24;
  FClassName := 'COMBOBOX';
  FStyle := ws_child OR ws_Border OR cbs_AutoHScroll or
            cbs_NoIntegralHeight OR ws_Visible
            (*<fduch> *)
            OR ws_VScroll;
            (*</fduch>*)
  FTabStop := true;
END;

PROCEDURE TComboBox.DoKeyDown(VAR AMsg: TWMKey): Boolean;
BEGIN
  Result := false;
  IF (AMsg.CharCode = VK_DOWN) and
     (SendMessage(FHandle,CB_GETDROPPEDSTATE,0,0) = 0) THEN
  BEGIN
    SendMessage(FHandle,CB_SHOWDROPDOWN,WParam(true),0);
    Result := true;
  END;
  inherited DoKeyDown(AMsg);
END;

(*<fduch> *)
(*$IFDEF CaptureMouse*)
PROCEDURE TComboBox.DoMouseDown(VAR AMsg: TWMMouse; Button: TMouseButton;
                      Shift: TShiftState);
BEGIN
  IF (Button=mbLeft) and
     (SendMessage(FHandle,CB_GETDROPPEDSTATE,0,0) = 0) THEN
  BEGIN
    SendMessage(FHandle,CB_SHOWDROPDOWN,WParam(true),0);
    SendMessage(FHandle,CB_SETEXTENDEDUI,WParam(false),0);
  END;
//  inherited DoMouseDown(AMsg, Button, Shift);
END;
(*$ENDIF*)
(*</fduch>*)

PROCEDURE TComboBox.SetSorted(Value: BOOLEAN);
BEGIN
  IF Value THEN FStyle := FStyle OR lbs_Sort
           ELSE FStyle := FStyle and not cbs_Sort;
END;

PROCEDURE TComboBox.GetCount: Integer;
BEGIN
  Result := SendMessage(FHandle, CB_GETCOUNT, 0, 0);
END;

PROCEDURE TComboBox.GetFocused: Integer;
BEGIN
  Result := SendMessage(FHandle, CB_GETCURSEL, 0, 0);
END;

PROCEDURE TComboBox.SetFocused(Value: Integer);
BEGIN
  SendMessage(FHandle, CB_SETCURSEL, Value, 0);
END;

PROCEDURE TComboBox.Get(Index: Integer): shortstring;
VAR
  Text: shortstring;
BEGIN
  Text[0] := chr(SendMessage(FHandle, CB_GETLBTEXT, Index, Longint(@Text[1])));
  Result := Text;
END;

PROCEDURE TComboBox.Put(Index: Integer; const S: shortstring);
BEGIN
  IF (Index < 0) OR (Index > Count) THEN Exit;
  IF Index = Count THEN
  BEGIN
    Add(S); Exit;
  END;
  Delete(Index);
  Insert(Index,S);
END;

PROCEDURE TComboBox.Add(const S: shortstring): Integer;
VAR ss : array [1..256] of char;
BEGIN
  Move(s[1],ss[1],Ord(s[0]));
  ss[Ord(s[0])+1] := #0;
  Result := SendMessage(FHandle, CB_ADDSTRING, 0, Longint(@ss));
  IF Result < 0 THEN FError := -1;
  IF Count = 1 THEN SetFocused(0);
END;

PROCEDURE TComboBox.Insert(Index: Integer; const S: shortstring);
VAR ss : array [1..256] of char;
BEGIN
  IF (Index < 0) OR (Index > Count) THEN Exit;
  Move(s[1],ss[1],Ord(s[0]));
  ss[Ord(s[0])+1] := #0;
  IF SendMessage(FHandle, CB_INSERTSTRING, Index,
    Longint(@Ss)) < 0 THEN FError := -1;
  IF Count = 1 THEN SetFocused(0);
END;

PROCEDURE TComboBox.Delete(Index: Integer);
VAR cf, cc : Integer;
BEGIN
  IF (Index < 0) OR (Index >= Count) THEN Exit;
  cf := GetFocused;
  cc := Count;
  SendMessage(FHandle, CB_DELETESTRING, Index, 0);
  IF Count = 0 THEN SetFocused(-1);
  IF cf >= cc - 1 THEN SetFocused(cc - 2);
END;

PROCEDURE TComboBox.Clear;
BEGIN
  IF Count <= 0 THEN Exit;
  SendMessage(FHandle, CB_RESETCONTENT, 0, 0);
  SetFocused(-1);
END;

(*TButton*)

constructor TButton.Create(AParent: TWinControl);
BEGIN
  inherited Create(AParent);
  FWidth := 75;
  FHeight := 25;
  FClassName := 'BUTTON';
  FEnabled := true;
  FStyle := ws_Child OR bs_PushButton OR ws_Ex_ControlParent;
  FTabStop := true;
END;

PROCEDURE TButton.GetModalResult : TModalResult;
BEGIN
  Result := FModalResult;
END;

PROCEDURE TButton.SetModalResult(Value: TModalResult);
BEGIN
  FModalResult := Value;
END;

PROCEDURE TButton.Click;
BEGIN
  IF (FModalResult <> 0) and
     (Parent <> NIL) and
      Parent.FIsModal and
     (Parent.FModalResult = 0) THEN
       Parent.FModalResult := Self.FModalResult
                               ELSE
       inherited;
END;

(*TCheckBox*)

constructor TCheckBox.Create(AParent: TWinControl);
BEGIN
  inherited Create(AParent);
  FWidth := 75;
  FHeight := 25;
  FBkMode := bk_Transparent;
  FClassName := 'BUTTON';
  FChecked := false;
  FEnabled := true;
  FStyle := ws_child OR bs_Checkbox OR ws_Ex_ControlParent OR bs_Notify;
  FTabStop := true;
END;

PROCEDURE TCheckBox.SetChecked(Value: BOOLEAN);
VAR code : LongInt;
BEGIN
  FChecked := Value;
  IF FHandle <> INVALID_HANDLE_VALUE THEN
  BEGIN
   code := BST_UNCHECKED;
   IF FChecked THEN code := BST_CHECKED;
   PostMessage(FHandle,BM_SETCHECK,code,0);
   Invalidate;
  END;
END;

PROCEDURE TCheckBox.Click;
BEGIN
  Checked := not Checked;
  inherited;
END;

(*TGroupBox*)

constructor TGroupBox.Create(AParent: TWinControl);
BEGIN
  inherited Create(AParent);
  FWidth := 121;
  FHeight := 121;
  FClassName := 'BUTTON';
  FBkMode := bk_Transparent;
  FEnabled := true;
  FStyle := ws_child OR bs_Groupbox OR ws_Ex_ControlParent;
  FTabStop := true;
END;

(*TProgressBar*)

constructor TProgressBar.Create(AParent: TWinControl);
BEGIN
  inherited Create(AParent);
  InitCommonControls;
  FWidth := 121;
  FHeight := 24;
  FClassName := PROGRESS_CLASS;
  //FBkMode := bk_Transparent;
  FEnabled := true;
  FStyle := ws_child OR ws_Visible;
  FTabStop := false;
  FRange := 100;
  FPosition := 0;
END;

PROCEDURE TProgressBar.GetRange : word;
BEGIN
  Result := FRange;
END;

PROCEDURE TProgressBar.SetRange(Value : word);
BEGIN
  SendMessage(FHandle, PBM_SETRANGE, 0, MAKELPARAM(0,Value));
  FRange := Value;
END;

PROCEDURE TProgressBar.GetPosition : word;
BEGIN
  Result := FPosition;
END;

PROCEDURE TProgressBar.SetPosition(Value : word);
BEGIN
  SendMessage(FHandle, PBM_SETPOS, Value, 0);
  FPosition := Value;
END;

PROCEDURE TProgressBar.GetStep : word;
BEGIN
  Result := FStep;
END;

PROCEDURE TProgressBar.SetStep(Value : word);
BEGIN
  SendMessage(FHandle, PBM_SETSTEP, Value, 0);
  FStep := Value;
END;

constructor TSplash.Create(AParent : TWinControl);
BEGIN
  inherited Create(AParent);
  OnHitTest := HitTest;
  FHCenter := true;
  FVCenter := true;
END;

PROCEDURE TSplash.SetHCenter(Value : BOOLEAN);
BEGIN
  FHCenter := Value;
  IF Value THEN Left := (GetSystemMetrics(SM_CXSCREEN)-Width) div 2;
END;

PROCEDURE TSplash.SetVCenter(Value : BOOLEAN);
BEGIN
  FVCenter := Value;
  IF Value THEN Top := (GetSystemMetrics(SM_CYSCREEN)-Height) div 2;
END;

PROCEDURE TSplash.HitTest(Sender : TObject; X,Y : Integer;
                          VAR Result : Integer);
BEGIN
  Result := HTNOWHERE;
END;

PROCEDURE TSplash.CreateWnd;
VAR st  : LongInt;
    i,j : Integer;
    ss  : shortstring;
BEGIN
  j := 1;
  for i := 1 to Length(Caption) do
    IF Caption[j] = #10 THEN Inc(j);
  Style := ws_Border;
  ExStyle := WS_EX_DLGMODALFRAME;
  AutoStop := false;
  IF FHCenter and FVCenter THEN
  BEGIN
    ss := #13#10#13#10;
    Height := 18 * (j + 4);
    Height := Height - GetSystemMetrics(SM_CYCAPTION);
  END;
  IF FHCenter THEN SetHCenter(true);
  IF FVCenter THEN SetVCenter(true);
  inherited CreateWnd;
  st := GetWindowLong(FHandle,GWL_STYLE);
  st := st and not WS_CAPTION;
  SetWindowLong(FHandle,GWL_STYLE,st);
    SetWindowPos(FHandle,0,0,0,0,0,
                 SWP_NOMOVE OR SWP_NOSIZE OR SWP_NOZORDER OR SWP_DRAWFRAME);
  ss := ss + Caption;
  L := NewLabel(Self,
                ss,
                0,0,ClientWidth,ClientHeight,
                SS_CENTER,
                bk_Transparent,
                0,
                TextColor);
  Caption := '';
  IF Visible THEN Show;
END;

PROCEDURE TSplash.UpdateText(Value : string);
VAR p : PChar;
BEGIN
  p := PChar(GlobalAlloc(GMEM_FIXED,Length(Value)+1));
  StrPCopy(p,Value);
  SendMessage(L.Handle,wm_settext,0,LongInt(p));
  GlobalFree(Cardinal(p));
END;

(* TKeyboard *)

VAR KbdHook : HHook;
    Kbd     : TKeyboard;

constructor TKeyboard.Create(AParent : TWinControl);
VAR kl : HKL;
BEGIN
  IF Kbd <> NIL THEN Exit;
  inherited Create(AParent);
  Visible := false;
  CharSet0 := 0;
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
END;

destructor TKeyboard.Destroy;
BEGIN
  RemoveHook;
  Kbd := NIL;
  inherited Destroy;
END;

PROCEDURE TKeyboard.InitParams;
VAR st : LongInt;
BEGIN
END;

PROCEDURE TKeyboard.SetPos(Value : TKeyboardPosition);
BEGIN
  FPos := Value;
  case Value of
    kpLeftTop    : BEGIN Left := 2; Top := 2; END;
    kpRightTop   : BEGIN Left := FParent.ClientWidth - 24; Top := 2; END;
    kpLeftBottom : BEGIN Left := 2; Top := FParent.ClientHeight - 24; END;
    kpRightBottom : BEGIN
                      Left := FParent.ClientWidth - 24;
                      Top := FParent.ClientHeight - 24;
                    END;
  END;
END;

PROCEDURE TKeyboard.SetCharSet0(Value : Integer);
BEGIN
  FCharSet0 := Value;
  FLay0 := LoadIcon(HInstance,MakeIntResource(1000+Value));
END;

PROCEDURE TKeyboard.SetCharSet1(Value : Integer);
BEGIN
  FCharSet1 := Value;
  FLay1 := LoadIcon(HInstance,MakeIntResource(1000+Value));
END;

PROCEDURE HookPrc(nCode : INTEGER;
                 wParam : WParam;
                 lParam : LParam) : INTEGER; stdcall;
VAR
  pcwr : PCWPRetStruct;
BEGIN
  pcwr := POINTER(lParam);
  IF pcwr^.message = WM_INPUTLANGCHANGE THEN
  BEGIN
    IF Kbd <> NIL THEN Kbd.LayoutChanged(pcwr^.wParam,pcwr^.lParam);
  END;
  IF nCode = HC_ACTION THEN
    Result := 0
                       ELSE
    Result := CallNextHookEx(KbdHook, nCode, wParam, lParam);
END;

PROCEDURE TKeyboard.InstallHook;
BEGIN
  KbdHook := SetWindowsHookEx(WH_CALLWNDPROCRET,
                              HookPrc,
                              hInstance,
                              GetCurrentThreadID);
END;

PROCEDURE TKeyboard.RemoveHook;
BEGIN
  IF KbdHook <> 0 THEN UnhookWindowsHookEx(KbdHook);
  KbdHook := 0;
  ProcessMessages;
END;

PROCEDURE TKeyboard.WMPaint(VAR AMsg: TWMPaint);
VAR
   DC : W.HDC;
   ps : TPaintStruct;
BEGIN
  DC := BeginPaint(FHandle,ps);
  SetBkMode(DC,TRANSPARENT);
  IF FCharSet = FCharSet0 THEN
  BEGIN
    DrawIconEx(DC,(ClientWidth-16) div 2,
                  (ClientHeight-16) div 2,FLay0,16,16,0,0,DI_NORMAL);
  end                   ELSE
  IF FCharSet = FCharSet1 THEN
  BEGIN
    DrawIconEx(DC,(ClientWidth-16) div 2,
                  (ClientHeight-16) div 2,FLay1,16,16,0,0,DI_NORMAL);
  END;
  EndPaint(FHandle,ps);
  AMsg.Result := 1;
END;

PROCEDURE TKeyboard.LayoutChanged(ACharSet,ALayout : Integer);
const s  : shortstring = '';
      s1 : shortstring = '';
BEGIN
  FLayout := ALayout;
  FCharSet := ACharSet;
  IF Visible THEN Invalidate;
END;

(* TTimer *)

PROCEDURE TTimerWindow.ProcessMessage(VAR AMsg: TMessage);
BEGIN
  with AMsg do
    IF Msg = WM_TIMER THEN FTimer.Timer
                      ELSE Result := DefWindowProc(FHandle, Msg, wParam, lParam);
END;

constructor TTimer.Create;
BEGIN
  inherited Create;
  FEnabled := false;
  FInterval := 1000;
  FWindow := TTimerWindow.Create(NIL);
  FWindow.FTimer := Self;
  FWindow.Visible := false;
  FWindow.CreateWnd;
  FWindowHandle := FWindow.FHandle;;
END;

destructor TTimer.Destroy;
BEGIN
  FEnabled := FALSE;
  UpdateTimer;
  FWindow.Free;
  inherited Destroy;
END;

PROCEDURE TTimer.UpdateTimer;
BEGIN
  KillTimer(FWindowHandle, 1);
  IF (FInterval <> 0) and FEnabled and Assigned(FOnTimer) THEN
    IF SetTimer(FWindowHandle, 1, FInterval, NIL) = 0 THEN
      MessageBox(0,'Out Of Resources','Error',MB_OK+MB_ICONSTOP);
END;

PROCEDURE TTimer.SetEnabled(Value: Boolean);
BEGIN
  IF Value <> FEnabled THEN
  BEGIN
    FEnabled := Value;
    UpdateTimer;
  END;
END;

PROCEDURE TTimer.SetInterval(Value: Cardinal);
BEGIN
  IF Value <> FInterval THEN
  BEGIN
    FInterval := Value;
    UpdateTimer;
  END;
END;

PROCEDURE TTimer.SetOnTimer(Value: TNotifyEvent);
BEGIN
  FOnTimer := Value;
  UpdateTimer;
END;

PROCEDURE TTimer.Timer;
BEGIN
  IF Assigned(FOnTimer) THEN FOnTimer(Self);
END;

(* Procedures *)

PROCEDURE NewLabel(AParent : TWinControl;
                  ACaption : string;
                  ALeft,Atop,AWidth,AHeight : Integer;
                  AALignment : Integer;
                  ABkMode : TBkMode;
                  ABkColor,
                  ATextColor : Ut.TColor) : TLabel;
VAR Wnd : TLabel;
BEGIN
  IF AParent = NIL THEN halt;
  Wnd := TLabel.Create(AParent);
  with Wnd do
  BEGIN
    Left := ALeft;
    Top := ATop;
    Width := AWidth;
    Height := AHeight;
    Color := ABkColor;
    TextColor := ATextColor;
    Caption := ACaption;
    FBkMode := ABkMode;
    FStyle := FStyle OR AALignment;
  END;
  Wnd.CreateWnd;
  Wnd.ProcessMessages;
  AParent.InsertWinControl(Wnd);
  Result := Wnd;
END;

PROCEDURE NewEdit(AParent : TWinControl;
                 AText : shortstring;
                 ALeft,Atop,AWidth,AHeight : Integer;
                 AStyle : Integer;
                 ABkColor,
                 ATextColor : Ut.TColor) : TEdit;
VAR Wnd : TEdit;
BEGIN
  IF AParent = NIL THEN halt;
  Wnd := TEdit.Create(AParent);
  with Wnd do
  BEGIN
    FStyle := FStyle OR AStyle;
    Left := ALeft;
    Top := ATop;
    Width := AWidth;
    Height := AHeight;
    Color := ABkColor;
    TextColor := ATextColor;
    Text := AText;
    FCtl3d := true;
  END;
  Wnd.CreateWnd;
  AParent.InsertWinControl(Wnd);
  Wnd.SetMargin(2);
  Result := Wnd;
END;

(*<fduch> *)
PROCEDURE NewHotKey(AParent : TWinControl;
                   AHotKey : Word;
                   AModifiers : THKModifiers;
                   ALeft,Atop,AWidth,AHeight : Integer;
                   ABkColor,
                   ATextColor : Ut.TColor) : THotKey;
VAR Wnd : THotKey;
BEGIN
  IF AParent = NIL THEN halt;
  Wnd := THotKey.Create(AParent);
  with Wnd do
  BEGIN
    Left := ALeft;
    Top := ATop;
    Width := AWidth;
    Height := AHeight;
    Color := ABkColor;
    TextColor := ATextColor;
    FCtl3d := true;
  END;
  Wnd.CreateWnd;
  Wnd.Modifiers := AModifiers;
  Wnd.HotKey := AHotKey;
  Wnd.InvalidKeys := [hcNone, hcShift];
  AParent.InsertWinControl(Wnd);
  Result := Wnd;
END;
(*</fduch> *)

PROCEDURE NewListBox(AParent : TWinControl;
                    ALeft,Atop,AWidth,AHeight : Integer;
                    ASorted : BOOLEAN;
                    ABkColor,
                    ATextColor : Ut.TColor) : TListBox;
VAR Wnd : TListBox;
BEGIN
  IF AParent = NIL THEN halt;
  Wnd := TListBox.Create(AParent);
  with Wnd do
  BEGIN
    Left := ALeft;
    Top := ATop;
    Width := AWidth;
    Height := AHeight;
    Color := ABkColor;
    TextColor := ATextColor;
    FCtl3d := true;
    Sorted := ASorted;
    //Font.Style := [fsBold];
  END;
  Wnd.CreateWnd;
  AParent.InsertWinControl(Wnd);
  Result := Wnd;
END;

PROCEDURE NewComboBox(AParent : TWinControl;
                     ALeft,Atop,AWidth,AHeight : Integer;
                     AStyle : Integer;
                     ASorted : BOOLEAN;
                     ABkColor,
                     ATextColor : Ut.TColor) : TComboBox;
VAR Wnd : TComboBox;
BEGIN
  IF AParent = NIL THEN halt;
  Wnd := TComboBox.Create(AParent);
  with Wnd do
  BEGIN
    Left := ALeft;
    Top := ATop;
    Width := AWidth;
    Height := AHeight;
    Color := ABkColor;
    TextColor := ATextColor;
    FCtl3d := true;
    FStyle := FStyle OR AStyle;
    Sorted := ASorted;
    //Font.Style := [fsBold];
  END;
  Wnd.CreateWnd;
  AParent.InsertWinControl(Wnd);
  Result := Wnd;
END;

PROCEDURE NewButton(AParent : TWinControl;
                 ACaption : string;
                 AResult : TModalResult;
                 ALeft,Atop,AWidth,AHeight : Integer;
                 ABkColor,
                 ATextColor : Ut.TColor) : TButton;
VAR Wnd : TButton;
BEGIN
  IF AParent = NIL THEN halt;
  Wnd := TButton.Create(AParent);
  with Wnd do
  BEGIN
    Left := ALeft;
    Width := AWidth;
    Height := AHeight;
    Top := ATop;
    Color := ABkColor;
    TextColor := ATextColor;
    Caption := ACaption;
    FModalResult := AResult;
  END;
  Wnd.CreateWnd;
  AParent.InsertWinControl(Wnd);
  Result := Wnd;
END;

PROCEDURE NewCheckBox(AParent : TWinControl;
                     ACaption : string;
                     ALeft,Atop,AWidth,AHeight : Integer;
                     ABkColor,
                     ATextColor : Ut.TColor) : TCheckBox;
VAR Wnd : TCheckBox;
BEGIN
  IF AParent = NIL THEN halt;
  Wnd := TCheckBox.Create(AParent);
  with Wnd do
  BEGIN
    Left := ALeft;
    Top := ATop;
    Width := AWidth;
    Height := AHeight;
    Color := ABkColor;
    TextColor := ATextColor;
    Caption := ACaption;
    //Font.Style := [fsBold];
  END;
  Wnd.CreateWnd;
  AParent.InsertWinControl(Wnd);
  Result := Wnd;
END;

PROCEDURE NewGroupBox(AParent : TWinControl;
                     ACaption : string;
                     ALeft,Atop,AWidth,AHeight : Integer;
                     ABkColor,
                     ATextColor : Ut.TColor) : TGroupBox;
VAR Wnd : TGroupBox;
BEGIN
  IF AParent = NIL THEN halt;
  Wnd := TGroupBox.Create(AParent);
  with Wnd do
  BEGIN
    Left := ALeft;
    Top := ATop;
    Width := AWidth;
    Height := AHeight;
    Color := ABkColor;
    TextColor := ATextColor;
    Caption := ACaption;
    //Font.Style := [fsBold];
  END;
  Wnd.CreateWnd;
  AParent.InsertWinControl(Wnd);
  Result := Wnd;
END;

PROCEDURE NewProgressBar(AParent : TWinControl;
                        ALeft,Atop,AWidth,AHeight : Integer;
                        AMin, AMax : Integer;
                        ABkColor,
                        ATextColor : Ut.TColor) : TProgressBar;
VAR Wnd : TProgressBar;
BEGIN
  IF AParent = NIL THEN halt;
  Wnd := TProgressBar.Create(AParent);
  with Wnd do
  BEGIN
    Left := ALeft;
    Top := ATop;
    Width := AWidth;
    Height := AHeight;
    Color := ABkColor;
    TextColor := ATextColor;
    Range := AMax;
  END;
  Wnd.CreateWnd;
  AParent.InsertWinControl(Wnd);
  Result := Wnd;
END;
*)
PROCEDURE InitScreen;
BEGIN
  Screen.Width := W.GetSystemMetrics(W.SM_CXSCREEN);
  Screen.Height := W.GetSystemMetrics(W.SM_CYSCREEN);
  Screen.DesktopLeft := W.GetSystemMetrics(W.SM_XVIRTUALSCREEN);
  Screen.DesktopTop := W.GetSystemMetrics(W.SM_YVIRTUALSCREEN);
  Screen.DesktopWidth := W.GetSystemMetrics(W.SM_CXVIRTUALSCREEN);
  IF Screen.DesktopWidth = 0 THEN Screen.DesktopWidth := Screen.Width END;
  Screen.DesktopHeight := W.GetSystemMetrics(W.SM_CYVIRTUALSCREEN);
  IF Screen.DesktopHeight = 0 THEN Screen.DesktopHeight := Screen.Height END;
END InitScreen;(*

(*<fduch> *)
PROCEDURE HotKeyToStr(Key: word; DModifiers: THKModifiers): shortstring;
VAR
  s: string[15];
BEGIN
  S[0]:=#0;
  IF (hkCtrl in DModifiers) THEN
    s:=s+'Ctrl+';
  IF (hkAlt in DModifiers) THEN
    s:=s+'Alt+';
  IF (hkShift in DModifiers) THEN
    s:=s+'Shift+';
  Result:=S+char(Key);
END;

PROCEDURE StrToHotKey(const Value: string; VAR Key: word; VAR Modifiers: THKModifiers);
VAR
  s, CurToken: string;
BEGIN
  IF Value<>'' THEN
  BEGIN
    s:=Value;
    WHILE Pos('+', S)>0 DO
    BEGIN
      CurToken:=UpperCase(Copy(S, 1, Pos('+', S)-1));
      Delete(S, 1, Pos('+', S));
      IF CurToken='ALT' THEN Include(Modifiers, hkAlt);
      IF CurToken='CTRL' THEN Include(Modifiers, hkCtrl);
      IF CurToken='SHIFT' THEN Include(Modifiers, hkShift);
    END;
    Key:=ord(S[1]);
  end
  ELSE
  BEGIN
    Key:=0;
    Modifiers:=[];
  END;
END;
(*</fduch>*)

(*<kvv>*)
PROCEDURE NewMenuItem(Var Menu: HMenu; 
          iType,State,ID : DWord; 
          Caption: ShortString; By_pos: BOOLEAN): BOOLEAN;

VAR mii: menuiteminfo;
BEGIN
  zeromemory(@mii,sizeof(mii));
  Caption := Caption + #0;
  with mii do
  BEGIN
    cbSize   := SizeOF(mii);
    fMask    := MIIM_ID OR MIIM_STATE OR MIIM_TYPE;
    fType    := iType;
    wID      := ID;
    fState   := State;
    dwTypeData := @Caption[1];
    cch      := Length(Caption);
  END;
  Result := InsertMenuItem(Menu,ID,By_pos,mii);
END;

PROCEDURE SetTrayIcon(AWnd: Hwnd; ID: Longint; Icon : HIcon;
                            text: ShortString): BOOLEAN;
VAR NiD: NOTIFYICONDATA;
BEGIN
  IF Length(text)>63 THEN text[0] := #62;
  text := text + #0;
  with NiD do
  BEGIN
    cbSize := SizeOf(NiD);
    Wnd := AWnd;
    uId := ID;
    uFlags := NIF_ICON OR NIF_TIP OR NIF_MESSAGE;
    hIcon := Icon;
    uCallBackMessage := wm_NotifyIcon;
    Move(text[1], szTip,length(text));
  END;
  Result := Shell_notifyicon(NIM_ADD,@NiD);
  IF icon<>0 THEN DestroyIcon(Icon);
END;

PROCEDURE DeleteTrayIcon(AWnd: Hwnd; ID: Longint): BOOLEAN;
VAR NiD: NOTIFYICONDATA;
BEGIN
  with NiD do
  BEGIN
    cbSize := SizeOf(NiD);
    Wnd := AWnd;
    uId := ID;
    uFlags := 0;
    hIcon := 0;
    uCallBackMessage := 0;
  END;
  Result := Shell_notifyicon(NIM_DELETE,@NiD);
END;
(*</kvv>*)
*)

BEGIN

  HInstance := W.GetModuleHandle(NIL);
  CmdShow := GetCmdShow(); (*
  Kbd := NIL;
  KbdHook := 0;*)
  InitScreenLogPixels;
  Fonts.Create;
  InitScreen;
(*
finalization

  Fonts.Free;*)

END AclLib.
