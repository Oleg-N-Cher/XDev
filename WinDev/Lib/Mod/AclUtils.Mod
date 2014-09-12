(*//////////////////////////////////////////////////////////////////////////////
//                                ACLUTILS UNIT                               //
//                    Win32 API implementation of TStream etc.                //
//                          (for working with ACL.PAS)                        //
//                                  Version 2.2                               //
//                       (c) Alexander B. Bokovikov, 2000                     //
//       http://a-press.parad.ru/pc/bokovikov/delphi/misc/utils.zip           //
////////////////////////////////////////////////////////////////////////////////
//       Some changes made by Alexander V. Hramov
//       1. Add StrScan function
//	 2. Add QuotedStr function
//       3. Add AnsiExtractQuotedStr function
//	 4. Add Win32Platform variable
//	 5. Add StrToFloat & FloatToStr
////////////////////////////////////////////////////////////////////////////////
//       Rewritten in XDev/Oberon-2 by Oleg N. Cher, VEDAsoft Oberon Club
//       http://zx.oberon2.ru
//////////////////////////////////////////////////////////////////////////////*)

MODULE AclUtils;

IMPORT SYSTEM, W := WinApi, Ignore;

TYPE
  TColor* = INTEGER;
  Cardinal = INTEGER;
  Char = CHAR;
  DWORD = INTEGER;
  Integer = INTEGER;
  LongInt = INTEGER;
  LongWord = INTEGER;
  PChar = W.PtrSTR;
  String = ARRAY OF Char;
  COLORREF = DWORD;

CONST
  NUL = NIL;

  Design_PPI* = 96; (* pixels per inch at design time *)

  (* Colors *)

  clScrollBar* = ORD(BITS(W.COLOR_SCROLLBAR) + BITS(80000000H));
  clBackground* = ORD(BITS(W.COLOR_BACKGROUND) + BITS(80000000H));
  clActiveCaption* = ORD(BITS(W.COLOR_ACTIVECAPTION) + BITS(80000000H));
  clInactiveCaption* = ORD(BITS(W.COLOR_INACTIVECAPTION) + BITS(80000000H));
  clMenu* = ORD(BITS(W.COLOR_MENU) + BITS(80000000H));
  clWindow* = ORD(BITS(W.COLOR_WINDOW) + BITS(80000000H));
  clWindowFrame* = ORD(BITS(W.COLOR_WINDOWFRAME) + BITS(80000000H));
  clMenuText* = ORD(BITS(W.COLOR_MENUTEXT) + BITS(80000000H));
  clWindowText* = ORD(BITS(W.COLOR_WINDOWTEXT) + BITS(80000000H));
  clCaptionText* = ORD(BITS(W.COLOR_CAPTIONTEXT) + BITS(80000000H));
  clActiveBorder* = ORD(BITS(W.COLOR_ACTIVEBORDER) + BITS(80000000H));
  clInactiveBorder* = ORD(BITS(W.COLOR_INACTIVEBORDER) + BITS(80000000H));
  clAppWorkSpace* = ORD(BITS(W.COLOR_APPWORKSPACE) + BITS(80000000H));
  clHighlight* = ORD(BITS(W.COLOR_HIGHLIGHT) + BITS(80000000H));
  clHighlightText* = ORD(BITS(W.COLOR_HIGHLIGHTTEXT) + BITS(80000000H));
  clBtnFace* = ORD(BITS(W.COLOR_BTNFACE) + BITS(80000000H));
  clBtnShadow* = ORD(BITS(W.COLOR_BTNSHADOW) + BITS(80000000H));
  clGrayText* = ORD(BITS(W.COLOR_GRAYTEXT) + BITS(80000000H));
  clBtnText* = ORD(BITS(W.COLOR_BTNTEXT) + BITS(80000000H));
  clInactiveCaptionText* = ORD(BITS(W.COLOR_INACTIVECAPTIONTEXT) + BITS(80000000H));
  clBtnHighlight* = ORD(BITS(W.COLOR_BTNHIGHLIGHT) + BITS(80000000H));
  cl3DDkShadow* = ORD(BITS(W.COLOR_3DDKSHADOW) + BITS(80000000H));
  cl3DLight* = ORD(BITS(W.COLOR_3DLIGHT) + BITS(80000000H));
  clInfoText* = ORD(BITS(W.COLOR_INFOTEXT) + BITS(80000000H));
  clInfoBk* = ORD(BITS(W.COLOR_INFOBK) + BITS(80000000H));

  clBlack* = 000000H;
  clMaroon* = 000080H;
  clGreen* = 008000H;
  clOlive* = 008080H;
  clNavy* = 800000H;
  clPurple* = 800080H;
  clTeal* = 808000H;
  clGray* = 808080H;
  clSilver* = 0C0C0C0H;
  clRed* = 0000FFH;
  clLime* = 00FF00H;
  clYellow* = 00FFFFH;
  clBlue* = 0FF0000H;
  clFuchsia* = 0FF00FFH;
  clAqua* = 0FFFF00H;
  clLtGray* = 0C0C0C0H;
  clDkGray* = 808080H;
  clWhite* = 0FFFFFFH;
  clNone* = 1FFFFFFFH;
  clDefault* = 20000000H;

(* TStream seek origins *)

  soFromBeginning* = 0;
  soFromCurrent* = 1;
  soFromEnd* = 2;

(* TFileStream create mode *)

  fmCreate* = 0FFFFH;

(* File open modes *)

  fmOpenRead*       = 0000H;
  fmOpenWrite*      = 0001H;
  fmOpenReadWrite*  = 0002H;
  fmOpenTruncate*   = 0004H;
  fmShareCompat*    = 0000H;
  fmShareExclusive* = 0010H;
  fmShareDenyWrite* = 0020H;
  fmShareDenyRead*  = 0030H;
  fmShareDenyNone*  = 0040H;

(* File attribute constants *)

  faReadOnly*  = 00000001H;
  faHidden*    = 00000002H;
  faSysFile*   = 00000004H;
  faVolumeID*  = 00000008H;
  faDirectory* = 00000010H;
  faArchive*   = 00000020H;
  faAnyFile*   = 0000003FH;

(* File mode magic numbers *)

  fmClosed* = 0D7B0H;
  fmInput*  = 0D7B1H;
  fmOutput* = 0D7B2H;
  fmInOut*  = 0D7B3H;

(* Seconds and milliseconds per day *)

  SecsPerDay* = 24 * 60 * 60;
  MSecsPerDay* = SecsPerDay * 1000;

(* Days between 1/1/0001 and 12/31/1899 *)

  DateDelta* = 693594;

VAR

(* Win32 platform identifier. *)

  Win32Platform-: Integer;

(* Win32 OS version information -
  see TOSVersionInfo.dwMajorVersion/dwMinorVersion/dwBuildNumber *)

  Win32MajorVersion-: Integer;
  Win32MinorVersion-: Integer;
  Win32BuildNumber-: Integer;

(* Win32 OS extra version info string -
  see TOSVersionInfo.szCSDVersion *)
  Win32CSDVersion-: ARRAY[1] 128 OF Char;
(*
TYPE

(* Standard Character set type *)

  TSysCharSet = set of Char;

(* Type conversion records *)

  WordRec = packed record
    Lo, Hi: Byte;
  END;

  LongRec = packed record
    Lo, Hi: Word;
  END;

  Int64Rec = packed record
    Lo, Hi: DWORD;
  END;

  TMethod = record
    Code, Data: Pointer;
  END;

(* General arrays *)

  PByteArray = ^TByteArray;
  TByteArray = array[0..32767] of Byte;

  PWordArray = ^TWordArray;
  TWordArray = array[0..16383] of Word;

(* Generic procedure pointer *)

  TProcedure = PROCEDURE;

(* Generic filename type *)

(*$IFDEF VirtualPascal*)
  TFileName = string;
  LongWord = Word;
  Int64 = LongWord;
(*$ELSE*)
  TFileName = type string;
(*$ENDIF*)

(* Search record used by FindFirst, FindNext, and FindClose *)

  TSearchRec = record
    Time: Integer;
    Size: Integer;
    Attr: Integer;
    Name: TFileName;
    ExcludeAttr: Integer;
    FindHandle: THandle;
    FindData: TWin32FindData;
  END;

(* Typed-file and untyped-file record *)

  TFileRec = record
    Handle: Integer;
    Mode: Integer;
    RecSize: Cardinal;
    Private: array[1..28] of Byte;
    UserData: array[1..32] of Byte;
    Name: array[0..259] of Char;
  END;

(* Text file record structure used for Text files *)

  PTextBuf = ^TTextBuf;
  TTextBuf = array[0..127] of Char;
  TTextRec = record
    Handle: Integer;
    Mode: Integer;
    BufSize: Cardinal;
    BufPos: Cardinal;
    BufEnd: Cardinal;
    BufPtr: PChar;
    OpenFunc: Pointer;
    InOutFunc: Pointer;
    FlushFunc: Pointer;
    CloseFunc: Pointer;
    UserData: array[1..32] of Byte;
    Name: array[0..259] of Char;
    Buffer: TTextBuf;
  END;

(* FloatToText, FloatToTextFmt, TextToFloat, and FloatToDecimal type codes *)

  TFloatValue = (fvExtended, fvCurrency);

(* FloatToText format codes *)

  TFloatFormat = (ffGeneral, ffExponent, ffFixed, ffNumber, ffCurrency);

(* FloatToDecimal result record *)

  TFloatRec = packed record
    Exponent: Smallint;
    Negative: Boolean;
    Digits: array[0..20] of Char;
  END;

(* Date and time record *)

  TTimeStamp = record
    Time: Integer;      (* Number of milliseconds since midnight *)
    Date: Integer;      (* One plus number of days since 1/1/0001 *)
  END;

(* MultiByte Character Set (MBCS) byte type *)
  TMbcsByteType = (mbSingleByte, mbLeadByte, mbTrailByte);

(* System Locale information record *)
  TSysLocale = packed record
    DefaultLCID: LCID;
    PriLangID: LANGID;
    SubLangID: LANGID;
    FarEast: Boolean;
    MiddleEast: Boolean;
  END;

(* TStream abstract class *)

  TStreamError = (se_None,se_Create,se_Open,se_Read,se_Write,se_Pos);
  TStreamErrorEvent = procedure(Sender : TObject; AError: TStreamError) of object;

  TStream = class(TObject)
  private
    FError : TStreamError;
    FErrorInfo : integer;
    FOnError : TStreamErrorEvent;
    PROCEDURE GetPosition: Longint;
    PROCEDURE SetPosition(Pos: Longint);
    PROCEDURE GetSize: Longint;
    PROCEDURE StreamError;
  public
    PROCEDURE Read(VAR Buffer; Count: Longint): Longint; virtual; abstract;
    PROCEDURE Write(const Buffer; Count: Longint): Longint; virtual; abstract;
    PROCEDURE Seek(Offset: Longint; Origin: Word): Longint; virtual; abstract;
    PROCEDURE ReadBuffer(VAR Buffer; Count: Longint);
    PROCEDURE WriteBuffer(const Buffer; Count: Longint);
    PROCEDURE CopyFrom(Source: TStream; Count: Longint): Longint;
    PROCEDURE SetSize(NewSize: Longint); virtual; abstract;
    property Position: Longint read GetPosition write SetPosition;
    property Size: Longint read GetSize;
    property Error : TStreamError read FError;
    property ErrorInfo : integer read FErrorInfo;
    property OnError : TStreamErrorEvent read FOnError write FOnError;
  END;

(* THandleStream class *)

  THandleStream = class(TStream)
  private
    FHandle: Integer;
  public
    constructor Create(AHandle: Integer);
    PROCEDURE Read(VAR Buffer; Count: Longint): Longint; override;
    PROCEDURE Write(const Buffer; Count: Longint): Longint; override;
    PROCEDURE Seek(Offset: Longint; Origin: Word): Longint; override;
    property Handle: Integer read FHandle;
  END;

(* TFileStream class *)

  TFileStream = class(THandleStream)
  private
    FName : shortstring;
  public
    constructor Create(const FileName: string; Mode: Word);
    destructor Destroy; override;
    PROCEDURE Flush;
    PROCEDURE Truncate;
    PROCEDURE SetSize(NewSize: Longint); override;
    property Name : shortstring read FName;
  END;

(* TCustomMemoryStream abstract class *)

  TCustomMemoryStream = class(TStream)
  private
    FMemory: Pointer;
    FSize, FPosition: Longint;
  protected
    PROCEDURE SetPointer(Ptr: Pointer; Size: Longint);
  public
    PROCEDURE Read(VAR Buffer; Count: Longint): Longint; override;
    PROCEDURE Seek(Offset: Longint; Origin: Word): Longint; override;
    PROCEDURE SaveToStream(Stream: TStream);
    PROCEDURE SaveToFile(const FileName: string);
    property Memory: Pointer read FMemory;
  END;

(* TMemoryStream *)

  TMemoryStream = class(TCustomMemoryStream)
  private
    FCapacity: Longint;
    PROCEDURE SetCapacity(NewCapacity: Longint);
  protected
    PROCEDURE Realloc(VAR NewCapacity: Longint): Pointer; virtual;
    property Capacity: Longint read FCapacity write SetCapacity;
  public
    destructor Destroy; override;
    PROCEDURE Clear;
    PROCEDURE LoadFromStream(Stream: TStream);
    PROCEDURE LoadFromFile(const FileName: string);
    PROCEDURE SetSize(NewSize: Longint); override;
    PROCEDURE Write(const Buffer; Count: Longint): Longint; override;
  END;

(*Graphic routins*)

type
  TFillDirection = (fdTopToBottom, fdBottomToTop, fdLeftToRight, fdRightToLeft);
*)
PROCEDURE ^ WidthOf* (r: W.RECT): Integer;
PROCEDURE ^ HeightOf* (r: W.RECT): Integer;
(*
PROCEDURE ColorToRGB(Color: TColor): Longint;
PROCEDURE GradientFillRect(DC : HDC;
                           ARect: TRect;
                           StartColor, EndColor: TColor;
                           Direction: TFillDirection;
                           Colors: Byte);

(*String management routins*)

PROCEDURE Length* (IN str: ARRAY OF Char): Integer;
PROCEDURE StrPas(Str: PChar): string;
PROCEDURE StrLCopy(Dest, Source: PChar; MaxLen: Cardinal): PChar;
PROCEDURE StrCopy(Dest, Source: PChar): PChar;
PROCEDURE StrEnd(Str: PChar): PChar;
PROCEDURE StrPCopy(Dest: PChar; const Source: string): PChar;
PROCEDURE StrCat(Dest, Source: PChar): PChar;
PROCEDURE StrLen(Str: PChar): Cardinal;
PROCEDURE StrMove(Dest, Source: PChar; Count: Cardinal): PChar;
PROCEDURE StrAlloc(Size: Cardinal): PChar;
PROCEDURE StrNew(Str: PChar): PChar;
PROCEDURE StrScan(const Str: PChar; Chr: Char): PChar;
PROCEDURE StrDispose(Str: PChar);
PROCEDURE CompareMem(P1, P2: Pointer; Length: Integer): Boolean;
PROCEDURE CompareStr(const S1, S2: string): Integer;
PROCEDURE AnsiCompareText(const S1, S2: string): Integer;
PROCEDURE UpperCase(const S: string): string;
PROCEDURE AnsiUpperCase(const S: string): string;
PROCEDURE LowerCase(const S: string): string;
PROCEDURE AnsiLowerCase(const S: string): string;

PROCEDURE Trim(const S: string): string;
PROCEDURE TrimLeft(const S: string): string;
PROCEDURE TrimRight(const S: string): string;

PROCEDURE BinToHex(Binary, Text: PChar; Count: Integer);
PROCEDURE HexToBin(Text, Binary: PChar; Count: Integer);
PROCEDURE IntToStr(i : integer) : string;
PROCEDURE StrToInt(s : string) : integer;
PROCEDURE StrToIntDef(s : string; Default: Integer) : integer;
PROCEDURE StrToFloat(s: String): Real;
PROCEDURE FloatToStr(m: Real): String;

(* Date/time support routines *)

VAR
  CurrencyString: string;
  CurrencyFormat: Byte;
  NegCurrFormat: Byte;
  ThousandSeparator: Char;
  DecimalSeparator: Char;
  CurrencyDecimals: Byte;
  DateSeparator: Char;
  ShortDateFormat: string;
  LongDateFormat: string;
  TimeSeparator: Char;
  TimeAMString: string;
  TimePMString: string;
  ShortTimeFormat: string;
  LongTimeFormat: string;
  ShortMonthNames: array[1..12] of string;
  LongMonthNames: array[1..12] of string;
  ShortDayNames: array[1..7] of string;
  LongDayNames: array[1..7] of string;
  SysLocale: TSysLocale;
  EraNames: array[1..7] of string;
  EraYearOffsets: array[1..7] of Integer;
  TwoDigitYearCenturyWindow: Word = 0;
  ListSeparator: Char;

PROCEDURE EncodeDate(Year, Month, Day: Word): TDateTime;
PROCEDURE EncodeTime(Hour, Min, Sec, MSec: Word): TDateTime;
PROCEDURE DecodeDate(Date: TDateTime; VAR Year, Month, Day: Word);
PROCEDURE DecodeTime(Time: TDateTime; VAR Hour, Min, Sec, MSec: Word);
PROCEDURE Now : TDateTime;

(* File management routines *)
*)
PROCEDURE ^ FileOpen* (IN fileName: String; mode: LongWord): W.HANDLE;
PROCEDURE ^ FileCreate* (IN fileName: String): W.HANDLE;
PROCEDURE ^ FileRead* (
  handle: W.HANDLE; VAR buffer: ARRAY OF BYTE; count: Integer): Integer;
PROCEDURE ^ FileWrite* (
  handle: W.HANDLE; VAR buffer: ARRAY OF BYTE; Count: Integer): Integer;(*
PROCEDURE FileSeek(Handle: Integer; const Offset: Int64; Origin: Integer): Int64;
PROCEDURE FileClose(Handle: Integer);
PROCEDURE FileGetAttr(const FileName: shortstring): Integer;
PROCEDURE FileSetAttr(const FileName: shortstring; Attr: Integer): Integer;
PROCEDURE DeleteFile(const FileName: shortstring): Boolean;
PROCEDURE RenameFile(const OldName, NewName: shortstring): Boolean;
PROCEDURE ChangeFileExt(const FileName, Extension: shortstring): shortstring;
PROCEDURE ExtractFilePath(const FileName: shortstring): shortstring;
PROCEDURE ExtractFileDir(const FileName: shortstring): shortstring;
PROCEDURE ExtractFileDrive(const FileName: shortstring): shortstring;
PROCEDURE ExtractFileName(const FileName: shortstring): shortstring;
PROCEDURE ExtractFileExt(const FileName: shortstring): shortstring;
PROCEDURE DiskFree(Drive: Byte): Int64;
PROCEDURE DiskSize(Drive: Byte): Int64;
PROCEDURE DiskSN(Drive : Byte) : DWORD;
PROCEDURE ExeName : shortstring;
PROCEDURE ExePath : shortstring;
PROCEDURE FindFirst(const Path: string; Attr: Integer;
  VAR F: TSearchRec): Integer;
PROCEDURE FindNext(VAR F: TSearchRec): Integer;
PROCEDURE FindClose(VAR F: TSearchRec);

(*Version routines*)

PROCEDURE GetFileVersion : string;
PROCEDURE GetFullFileVersion : string;

(*Browse for folders*)
type
  TBrowseFolderKind = (bfAll,bfDrives,bfComputers);

PROCEDURE BrowseForFolder(AParent: HWND;
                         ATitle : string;
                         AKind  : TBrowseFolderKind) : string;

PROCEDURE QuotedStr(const S: string; Quote: char): string;
PROCEDURE AnsiExtractQuotedStr(VAR Src: PChar; Quote: Char): string;


(* OS Version *)
VAR
  OSVersionInfo: TOSVersionInfo;

implementation

uses Messages;
*)

PROCEDURE FillChar* (adr: SYSTEM.PTR; count: Integer; fill: BYTE);
BEGIN
  WHILE count > 0 DO
    SYSTEM.PUT(adr, fill);
    IF SIZE(SYSTEM.PTR) = SIZE(INTEGER) THEN
      adr := SYSTEM.VAL(SYSTEM.PTR, SYSTEM.VAL(INTEGER, adr) + 1);
    ELSE
      adr := SYSTEM.VAL(SYSTEM.PTR, SYSTEM.VAL(LONGINT, adr) + 1);
    END;
    DEC(count);
  END;
END FillChar;

PROCEDURE WidthOf* (r: W.RECT): Integer;
BEGIN
  RETURN r.right - r.left
END WidthOf;

PROCEDURE HeightOf* (r: W.RECT): Integer;
BEGIN
  RETURN r.bottom - r.top
END HeightOf;

(*Graphic routines*)

PROCEDURE ColorToRGB* (color: TColor): LongInt;
BEGIN
  IF color < 0 THEN
    RETURN W.GetSysColor(ORD(BITS(color) * BITS(000000FFH)))
  END;
  RETURN color
END ColorToRGB;

PROCEDURE RGB* (r, g, b: BYTE): COLORREF;
BEGIN
  RETURN
    SYSTEM.VAL(COLORREF, r) +
    SYSTEM.VAL(COLORREF, g) * 100H +
    SYSTEM.VAL(COLORREF, b) * 10000H;
END RGB;

PROCEDURE MakeLong* (A, B: Cardinal): LongInt;
BEGIN
  RETURN A + (B * 1000H);
END MakeLong;

(*
PROCEDURE GradientFillRect(DC : HDC; ARect: TRect; StartColor,
  EndColor: TColor; Direction: TFillDirection; Colors: Byte);
VAR
  StartRGB: array[0..2] of Byte;    (* Start RGB values *)
  RGBDelta: array[0..2] of Integer; (* Difference between start and end RGB values *)
  ColorBand: TRect;                 (* Color band rectangular coordinates *)
  I, Delta: Integer;
  Brush: HBrush;
BEGIN
  IF IsRectEmpty(ARect) THEN Exit;
  IF Colors < 2 THEN BEGIN
    Brush := CreateSolidBrush(ColorToRGB(StartColor));
    FillRect(DC, ARect, Brush);
    DeleteObject(Brush);
    Exit;
  END;
  StartColor := ColorToRGB(StartColor);
  EndColor := ColorToRGB(EndColor);
  case Direction of
    fdTopToBottom, fdLeftToRight: BEGIN
      (* Set the Red, Green and Blue colors *)
      StartRGB[0] := GetRValue(StartColor);
      StartRGB[1] := GetGValue(StartColor);
      StartRGB[2] := GetBValue(StartColor);
      (* Calculate the difference between begin and end RGB values *)
      RGBDelta[0] := GetRValue(EndColor) - StartRGB[0];
      RGBDelta[1] := GetGValue(EndColor) - StartRGB[1];
      RGBDelta[2] := GetBValue(EndColor) - StartRGB[2];
    END;
    fdBottomToTop, fdRightToLeft: BEGIN
      (* Set the Red, Green and Blue colors *)
      (* Reverse of TopToBottom and LeftToRight directions *)
      StartRGB[0] := GetRValue(EndColor);
      StartRGB[1] := GetGValue(EndColor);
      StartRGB[2] := GetBValue(EndColor);
      (* Calculate the difference between begin and end RGB values *)
      (* Reverse of TopToBottom and LeftToRight directions *)
      RGBDelta[0] := GetRValue(StartColor) - StartRGB[0];
      RGBDelta[1] := GetGValue(StartColor) - StartRGB[1];
      RGBDelta[2] := GetBValue(StartColor) - StartRGB[2];
    END;
  END; (*case*)
  (* Calculate the color band's coordinates *)
  ColorBand := ARect;
  IF Direction in [fdTopToBottom, fdBottomToTop] THEN BEGIN
    Colors := Max(2, Min(Colors, HeightOf(ARect)));
    Delta := HeightOf(ARect) div Colors;
  end
  ELSE BEGIN
    Colors := Max(2, Min(Colors, WidthOf(ARect)));
    Delta := WidthOf(ARect) div Colors;
  END;
//  Pen := CreatePen(ps_Solid,;
//  with Canvas.Pen do BEGIN (* Set the pen style and mode *)
//    Style := psSolid;
//    Mode := pmCopy;
//  END;
  (* Perform the fill *)
  IF Delta > 0 THEN BEGIN
    for I := 0 to Colors do BEGIN
      case Direction of
        (* Calculate the color band's top and bottom coordinates *)
        fdTopToBottom, fdBottomToTop: BEGIN
          ColorBand.Top := ARect.Top + I * Delta;
          ColorBand.Bottom := ColorBand.Top + Delta;
        END;
        (* Calculate the color band's left and right coordinates *)
        fdLeftToRight, fdRightToLeft: BEGIN
          ColorBand.Left := ARect.Left + I * Delta;
          ColorBand.Right := ColorBand.Left + Delta;
        END;
      END; (*case*)
      (* Calculate the color band's color *)
      Brush := CreateSolidBrush(RGB(
        StartRGB[0] + MulDiv(I, RGBDelta[0], Colors - 1),
        StartRGB[1] + MulDiv(I, RGBDelta[1], Colors - 1),
        StartRGB[2] + MulDiv(I, RGBDelta[2], Colors - 1)));
      FillRect(DC, ColorBand, Brush);
      DeleteObject(Brush);
    END;
  END;
  IF Direction in [fdTopToBottom, fdBottomToTop] THEN
    Delta := HeightOf(ARect) mod Colors
  ELSE Delta := WidthOf(ARect) mod Colors;
  IF Delta > 0 THEN BEGIN
    case Direction of
      (* Calculate the color band's top and bottom coordinates *)
      fdTopToBottom, fdBottomToTop: BEGIN
        ColorBand.Top := ARect.Bottom - Delta;
        ColorBand.Bottom := ColorBand.Top + Delta;
      END;
      (* Calculate the color band's left and right coordinates *)
      fdLeftToRight, fdRightToLeft: BEGIN
        ColorBand.Left := ARect.Right - Delta;
        ColorBand.Right := ColorBand.Left + Delta;
      END;
    END; (*case*)
    case Direction of
      fdTopToBottom, fdLeftToRight:
        Brush := CreateSolidBrush(EndColor);
      ELSE (*fdBottomToTop, fdRightToLeft *)
        Brush := CreateSolidBrush(StartColor);
    END;
    FillRect(DC, ColorBand, Brush);
    DeleteObject(Brush);
  END;
END;
*)
(*String management routins*)

PROCEDURE Length* (IN str: ARRAY OF CHAR): Integer;
VAR
  len: Integer;
BEGIN
  len := 0;
  WHILE (len < SHORT(LEN(str))) & (str[len] # 0X) DO INC(len) END;
  RETURN len
END Length;
(*
PROCEDURE BinToHex(Binary, Text: PChar; Count: Integer);
const
  HexChars: array[0..15] of Char = '0123456789ABCDEF';
VAR
  I: Integer;
BEGIN
  for I := 0 to Count - 1 do
  BEGIN
    Text^ := HexChars[(Byte(Binary[I]) and $F0) SHR 4];
    Inc(Text);
    Text^ := HexChars[(Byte(Binary[I]) and $0F)];
    Inc(Text);
  END;
END;

PROCEDURE HexToBin(Text, Binary: PChar; Count: Integer);
VAR
  I: Integer;

  PROCEDURE Bt(c : char) : byte;
  BEGIN
    IF c < 'A' THEN Result := Ord(c) - 48
               ELSE Result := Ord(c) - 55;
  END;
BEGIN
  for I := 0 to Count - 1 do
    Binary[i] := chr((Bt(Text[2*I]) shl 4) OR Bt(Text[2*I+1]));
END;

PROCEDURE StrPas(Str: PChar): string;
BEGIN
//  Result := Str;
END;

PROCEDURE CompareStr(const S1, S2: string): Integer; assembler;
asm
        PUSH    ESI
        PUSH    EDI
        MOV     ESI,EAX
        MOV     EDI,EDX
        OR      EAX,EAX
        JE      @@1
        MOV     EAX,[EAX-4]
@@1:    OR      EDX,EDX
        JE      @@2
        MOV     EDX,[EDX-4]
@@2:    MOV     ECX,EAX
        CMP     ECX,EDX
        JBE     @@3
        MOV     ECX,EDX
@@3:    CMP     ECX,ECX
        REPE    CMPSB
        JE      @@4
        MOVZX   EAX,BYTE PTR [ESI-1]
        MOVZX   EDX,BYTE PTR [EDI-1]
@@4:    SUB     EAX,EDX
        POP     EDI
        POP     ESI
END;

PROCEDURE CompareMem(P1, P2: Pointer; Length: Integer): Boolean; assembler;
asm
        PUSH    ESI
        PUSH    EDI
        MOV     ESI,P1
        MOV     EDI,P2
        MOV     EDX,ECX
        XOR     EAX,EAX
        AND     EDX,3
        SHR     ECX,1
        SHR     ECX,1
        REPE    CMPSD
        JNE     @@2
        MOV     ECX,EDX
        REPE    CMPSB
        JNE     @@2
@@1:    INC     EAX
@@2:    POP     EDI
        POP     ESI
END;

PROCEDURE CompareText(const S1, S2: string): Integer; assembler;
asm
        PUSH    ESI
        PUSH    EDI
        PUSH    EBX
        MOV     ESI,EAX
        MOV     EDI,EDX
        OR      EAX,EAX
        JE      @@0
        MOV     EAX,[EAX-4]
@@0:    OR      EDX,EDX
        JE      @@1
        MOV     EDX,[EDX-4]
@@1:    MOV     ECX,EAX
        CMP     ECX,EDX
        JBE     @@2
        MOV     ECX,EDX
@@2:    CMP     ECX,ECX
@@3:    REPE    CMPSB
        JE      @@6
        MOV     BL,BYTE PTR [ESI-1]
        CMP     BL,'a'
        JB      @@4
        CMP     BL,'z'
        JA      @@4
        SUB     BL,20H
@@4:    MOV     BH,BYTE PTR [EDI-1]
        CMP     BH,'a'
        JB      @@5
        CMP     BH,'z'
        JA      @@5
        SUB     BH,20H
@@5:    CMP     BL,BH
        JE      @@3
        MOVZX   EAX,BL
        MOVZX   EDX,BH
@@6:    SUB     EAX,EDX
        POP     EBX
        POP     EDI
        POP     ESI
END;

PROCEDURE StrLCopy(Dest, Source: PChar; MaxLen: Cardinal): PChar; assembler;
asm
        PUSH    EDI
        PUSH    ESI
        PUSH    EBX
        MOV     ESI,EAX
        MOV     EDI,EDX
        MOV     EBX,ECX
        XOR     AL,AL
        TEST    ECX,ECX
        JZ      @@1
        REPNE   SCASB
        JNE     @@1
        INC     ECX
@@1:    SUB     EBX,ECX
        MOV     EDI,ESI
        MOV     ESI,EDX
        MOV     EDX,EDI
        MOV     ECX,EBX
        SHR     ECX,2
        REP     MOVSD
        MOV     ECX,EBX
        AND     ECX,3
        REP     MOVSB
        STOSB
        MOV     EAX,EDX
        POP     EBX
        POP     ESI
        POP     EDI
END;

PROCEDURE StrScan(const Str: PChar; Chr: Char): PChar; assembler;
asm
        PUSH    EDI
        PUSH    EAX
        MOV     EDI,Str
        MOV     ECX,0FFFFFFFFH
        XOR     AL,AL
        REPNE   SCASB
        NOT     ECX
        POP     EDI
        MOV     AL,Chr
        REPNE   SCASB
        MOV     EAX,0
        JNE     @@1
        MOV     EAX,EDI
        DEC     EAX
@@1:    POP     EDI
END;

PROCEDURE StrCopy(Dest, Source: PChar): PChar; assembler;
asm
        PUSH    EDI
        PUSH    ESI
        MOV     ESI,EAX
        MOV     EDI,EDX
        MOV     ECX,0FFFFFFFFH
        XOR     AL,AL
        REPNE   SCASB
        NOT     ECX
        MOV     EDI,ESI
        MOV     ESI,EDX
        MOV     EDX,ECX
        MOV     EAX,EDI
        SHR     ECX,2
        REP     MOVSD
        MOV     ECX,EDX
        AND     ECX,3
        REP     MOVSB
        POP     ESI
        POP     EDI
END;

PROCEDURE StrEnd(Str: PChar): PChar; assembler;
asm
        MOV     EDX,EDI
        MOV     EDI,EAX
        MOV     ECX,0FFFFFFFFH
        XOR     AL,AL
        REPNE   SCASB
        LEA     EAX,[EDI-1]
        MOV     EDI,EDX
END;

PROCEDURE StrPCopy(Dest: PChar; const Source: string): PChar;
BEGIN
  Result := StrLCopy(Dest, PChar(Source), 255);
END;

PROCEDURE StrCat(Dest, Source: PChar): PChar;
BEGIN
  StrCopy(StrEnd(Dest), Source);
  Result := Dest;
END;

PROCEDURE StrLen(Str: PChar): Cardinal; assembler;
asm
        MOV     EDX,EDI
        MOV     EDI,EAX
        MOV     ECX,0FFFFFFFFH
        XOR     AL,AL
        REPNE   SCASB
        MOV     EAX,0FFFFFFFEH
        SUB     EAX,ECX
        MOV     EDI,EDX
END;

PROCEDURE StrMove(Dest, Source: PChar; Count: Cardinal): PChar; assembler;
asm
        PUSH    ESI
        PUSH    EDI
        MOV     ESI,EDX
        MOV     EDI,EAX
        MOV     EDX,ECX
        CMP     EDI,ESI
        JG      @@1
        JE      @@2
        SHR     ECX,2
        REP     MOVSD
        MOV     ECX,EDX
        AND     ECX,3
        REP     MOVSB
        JMP     @@2
@@1:    LEA     ESI,[ESI+ECX-1]
        LEA     EDI,[EDI+ECX-1]
        AND     ECX,3
        STD
        REP     MOVSB
        SUB     ESI,3
        SUB     EDI,3
        MOV     ECX,EDX
        SHR     ECX,2
        REP     MOVSD
        CLD
@@2:    POP     EDI
        POP     ESI
END;

PROCEDURE StrAlloc(Size: Cardinal): PChar;
BEGIN
  Inc(Size, SizeOf(Cardinal));
  GetMem(Result, Size);
  Cardinal(Pointer(Result)^) := Size;
  Inc(Result, SizeOf(Cardinal));
END;

PROCEDURE StrNew(Str: PChar): PChar;
VAR
  Size: Cardinal;
BEGIN
  IF Str = NIL THEN Result := NIL ELSE
  BEGIN
    Size := StrLen(Str) + 1;
    Result := StrMove(StrAlloc(Size), Str, Size);
  END;
END;

PROCEDURE StrDispose(Str: PChar);
BEGIN
  IF Str <> NIL THEN
  BEGIN
    Dec(Str, SizeOf(Cardinal));
    FreeMem(Str, Cardinal(Pointer(Str)^));
  END;
END;
*)
PROCEDURE AnsiCompareText* (IN S1, S2: String): Integer;
BEGIN
  RETURN W.CompareString(W.LOCALE_USER_DEFAULT, W.NORM_IGNORECASE,
    SYSTEM.VAL(PChar, SYSTEM.ADR(S1)), Length(S1),
    SYSTEM.VAL(PChar, SYSTEM.ADR(S2)), Length(S2)) - 2
END AnsiCompareText;
(*
PROCEDURE UpperCase(const S: string): string;
VAR
  Ch: Char;
  L: Integer;
  Source, Dest: PChar;
BEGIN
  L := Length(S);
  SetLength(Result, L);
  Source := Pointer(S);
  Dest := Pointer(Result);
  WHILE L <> 0 DO
  BEGIN
    Ch := Source^;
    IF (Ch >= 'a') and (Ch <= 'z') THEN Dec(Ch, 32);
    Dest^ := Ch;
    Inc(Source);
    Inc(Dest);
    Dec(L);
  END;
END;

PROCEDURE LowerCase(const S: string): string;
VAR
  Ch: Char;
  L: Integer;
  Source, Dest: PChar;
BEGIN
  L := Length(S);
  SetLength(Result, L);
  Source := Pointer(S);
  Dest := Pointer(Result);
  WHILE L <> 0 DO
  BEGIN
    Ch := Source^;
    IF (Ch >= 'A') and (Ch <= 'Z') THEN Inc(Ch, 32);
    Dest^ := Ch;
    Inc(Source);
    Inc(Dest);
    Dec(L);
  END;
END;

PROCEDURE AnsiUpperCase(const S: string): string;
VAR
  Len: Integer;
BEGIN
  Len := Length(S);
  SetString(Result, PChar(S), Len);
  IF Len > 0 THEN CharUpperBuff(Pointer(Result), Len);
END;

PROCEDURE AnsiLowerCase(const S: string): string;
VAR
  Len: Integer;
BEGIN
  Len := Length(S);
  SetString(Result, PChar(S), Len);
  IF Len > 0 THEN CharLowerBuff(Pointer(Result), Len);
END;

PROCEDURE IntToStr(i : integer) : string;
BEGIN
  Str(i,Result);
END;

PROCEDURE StrToInt(s : string) : integer;
VAR j : integer;
BEGIN
  Val(s,Result,j);
  IF j > 0 THEN Result := 0;
END;

PROCEDURE StrToIntDef(s : string; Default: Integer) : integer;
VAR j : integer;
BEGIN
  Val(s,Result,j);
  IF j > 0 THEN Result := Default;
END;

PROCEDURE FloatToStr(m:real):string;
BEGIN
 Str(m:4:1, Result);
END;

Function StrToFloat(s:String):real;
VAR
   code:integer;
BEGIN
  Val(S, Result, Code);
  IF code>0 THEN Result:=0;
END;

(* Date/time support routines *)

const
  FMSecsPerDay: Single = MSecsPerDay;
  IMSecsPerDay: Integer = MSecsPerDay;

PROCEDURE DateTimeToTimeStamp(DateTime: TDateTime): TTimeStamp;
asm
        MOV     ECX,EAX
        FLD     DateTime
        FMUL    FMSecsPerDay
        SUB     ESP,8
        FISTP   QWORD PTR [ESP]
        FWAIT
        POP     EAX
        POP     EDX
        OR      EDX,EDX
        JNS     @@1
        NEG     EDX
        NEG     EAX
        SBB     EDX,0
        DIV     IMSecsPerDay
        NEG     EAX
        JMP     @@2
@@1:    DIV     IMSecsPerDay
@@2:    ADD     EAX,DateDelta
        MOV     [ECX].TTimeStamp.Time,EDX
        MOV     [ECX].TTimeStamp.Date,EAX
END;

PROCEDURE TimeStampToDateTime(const TimeStamp: TTimeStamp): TDateTime;
asm
        MOV     ECX,[EAX].TTimeStamp.Time
        MOV     EAX,[EAX].TTimeStamp.Date
        SUB     EAX,DateDelta
        IMUL    IMSecsPerDay
        OR      EDX,EDX
        JNS     @@1
        SUB     EAX,ECX
        SBB     EDX,0
        JMP     @@2
@@1:    ADD     EAX,ECX
        ADC     EDX,0
@@2:    PUSH    EDX
        PUSH    EAX
        FILD    QWORD PTR [ESP]
        FDIV    FMSecsPerDay
        ADD     ESP,8
END;

PROCEDURE MSecsToTimeStamp(MSecs: Comp): TTimeStamp;
asm
        MOV     ECX,EAX
        MOV     EAX,MSecs.Integer[0]
        MOV     EDX,MSecs.Integer[4]
        DIV     IMSecsPerDay
        MOV     [ECX].TTimeStamp.Time,EDX
        MOV     [ECX].TTimeStamp.Date,EAX
END;

PROCEDURE TimeStampToMSecs(const TimeStamp: TTimeStamp): Comp;
asm
        FILD    [EAX].TTimeStamp.Date
        FMUL    FMSecsPerDay
        FIADD   [EAX].TTimeStamp.Time
END;

(* Time encoding and decoding *)

PROCEDURE DoEncodeTime(Hour, Min, Sec, MSec: Word; VAR Time: TDateTime): Boolean;
BEGIN
  Result := FALSE;
  IF (Hour < 24) and (Min < 60) and (Sec < 60) and (MSec < 1000) THEN
  BEGIN
    Time := (Hour * 3600000 + Min * 60000 + Sec * 1000 + MSec) / MSecsPerDay;
    Result := TRUE;
  END;
END;

PROCEDURE ConvertError(s : string);
BEGIN
END;

PROCEDURE EncodeTime(Hour, Min, Sec, MSec: Word): TDateTime;
BEGIN
  IF not DoEncodeTime(Hour, Min, Sec, MSec, Result) THEN
    ConvertError('TimeEncodeError');
END;

PROCEDURE DivMod(Dividend: Integer; Divisor: Word;
  VAR Result, Remainder: Word);
asm
        PUSH    EBX
        MOV     EBX,EDX
        MOV     EDX,EAX
        SHR     EDX,16
        DIV     BX
        MOV     EBX,Remainder
        MOV     [ECX],AX
        MOV     [EBX],DX
        POP     EBX
END;

PROCEDURE DecodeTime(Time: TDateTime; VAR Hour, Min, Sec, MSec: Word);
VAR
  MinCount, MSecCount: Word;
BEGIN
  DivMod(DateTimeToTimeStamp(Time).Time, 60000, MinCount, MSecCount);
  DivMod(MinCount, 60, Hour, Min);
  DivMod(MSecCount, 1000, Sec, MSec);
END;

PROCEDURE Trim(const S: string): string;
VAR
  I, L: Integer;
BEGIN
  L := Length(S);
  I := 1;
  WHILE (I <= L) and (S[I] <= ' ') DO Inc(I);
  IF I > L THEN Result := '' ELSE
  BEGIN
    WHILE S[L] <= ' ' DO Dec(L);
    Result := Copy(S, I, L - I + 1);
  END;
END;

PROCEDURE TrimLeft(const S: string): string;
VAR
  I, L: Integer;
BEGIN
  L := Length(S);
  I := 1;
  WHILE (I <= L) and (S[I] <= ' ') DO Inc(I);
  Result := Copy(S, I, Maxint);
END;

PROCEDURE TrimRight(const S: string): string;
VAR
  I: Integer;
BEGIN
  I := Length(S);
  WHILE (I > 0) and (S[I] <= ' ') DO Dec(I);
  Result := Copy(S, 1, I);
END;

(* Date encoding and decoding *)

PROCEDURE IsLeapYear(Year: Word): Boolean;
BEGIN
  Result := (Year mod 4 = 0) and ((Year mod 100 <> 0) OR (Year mod 400 = 0));
END;

type
  PDayTable = ^TDayTable;
  TDayTable = array[1..12] of Word;

(* The MonthDays array can be used to quickly find the number of
  days in a month:  MonthDays[IsLeapYear(Y), M]      *)

const
  MonthDays: array [Boolean] of TDayTable =
    ((31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31),
     (31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31));

(* DateToStr converts the date part of the given TDateTime value to a string.
  The conversion uses the format specified by the ShortDateFormat global
  variable. *)

PROCEDURE Now: TDateTime;
VAR
  SystemTime: TSystemTime;
BEGIN
  GetLocalTime(SystemTime);
  with SystemTime do
    Result := EncodeDate(wYear, wMonth, wDay) +
      EncodeTime(wHour, wMinute, wSecond, wMilliseconds);
END;

PROCEDURE DoEncodeDate(Year, Month, Day: Word; VAR Date: TDateTime): Boolean;
VAR
  I: Integer;
  DayTable: PDayTable;
BEGIN
  Result := FALSE;
  DayTable := @MonthDays[IsLeapYear(Year)];
  IF (Year >= 1) and (Year <= 9999) and (Month >= 1) and (Month <= 12) and
    (Day >= 1) and (Day <= DayTable^[Month]) THEN
  BEGIN
    for I := 1 to Month - 1 do Inc(Day, DayTable^[I]);
    I := Year - 1;
    Date := I * 365 + I div 4 - I div 100 + I div 400 + Day - DateDelta;
    Result := TRUE;
  END;
END;

PROCEDURE EncodeDate(Year, Month, Day: Word): TDateTime;
BEGIN
  IF not DoEncodeDate(Year, Month, Day, Result) THEN
    ConvertError('SDateEncodeError');
END;

PROCEDURE DecodeDate(Date: TDateTime; VAR Year, Month, Day: Word);
const
  D1 = 365;
  D4 = D1 * 4 + 1;
  D100 = D4 * 25 - 1;
  D400 = D100 * 4 + 1;
VAR
  Y, M, D, I: Word;
  T: Integer;
  DayTable: PDayTable;
BEGIN
  T := DateTimeToTimeStamp(Date).Date;
  IF T <= 0 THEN
  BEGIN
    Year := 0;
    Month := 0;
    Day := 0;
  end ELSE
  BEGIN
    Dec(T);
    Y := 1;
    WHILE T >= D400 DO
    BEGIN
      Dec(T, D400);
      Inc(Y, 400);
    END;
    DivMod(T, D100, I, D);
    IF I = 4 THEN
    BEGIN
      Dec(I);
      Inc(D, D100);
    END;
    Inc(Y, I * 100);
    DivMod(D, D4, I, D);
    Inc(Y, I * 4);
    DivMod(D, D1, I, D);
    IF I = 4 THEN
    BEGIN
      Dec(I);
      Inc(D, D1);
    END;
    Inc(Y, I);
    DayTable := @MonthDays[IsLeapYear(Y)];
    M := 1;
    WHILE TRUE DO
    BEGIN
      I := DayTable^[M];
      IF D < I THEN Break;
      Dec(D, I);
      Inc(M);
    END;
    Year := Y;
    Month := M;
    Day := D + 1;
  END;
END;
*)
(* File management routines *)

PROCEDURE FileOpen* (IN fileName: String; mode: LongWord): W.HANDLE;
VAR
  AccessMode: ARRAY 3 OF SET;
  ShareMode: ARRAY 5 OF SET;
  OpenMode: ARRAY 2 OF LongWord;
BEGIN
  AccessMode[0] := W.GENERIC_READ;
  AccessMode[1] := W.GENERIC_WRITE;
  AccessMode[2] := W.GENERIC_READ + W.GENERIC_WRITE;
  ShareMode[0] := {};
  ShareMode[1] := {};
  ShareMode[2] := W.FILE_SHARE_READ;
  ShareMode[3] := W.FILE_SHARE_WRITE;
  ShareMode[4] := W.FILE_SHARE_READ + W.FILE_SHARE_WRITE;
  OpenMode[0] := W.OPEN_EXISTING;
  OpenMode[1] := W.TRUNCATE_EXISTING;
  RETURN W.CreateFile(SYSTEM.VAL(W.PtrSTR, SYSTEM.ADR(fileName)),
                       AccessMode[ORD(BITS(mode) * BITS(3))],
                       ShareMode[ORD(BITS(mode) * BITS(0F0H)) DIV 10H],
                       NIL,
                       OpenMode[ORD(BITS(mode) * BITS(4)) DIV 4],
                       W.FILE_ATTRIBUTE_NORMAL,
                       NUL)
END FileOpen;

PROCEDURE FileCreate* (IN fileName: String): W.HANDLE;
BEGIN
  RETURN W.CreateFile(SYSTEM.VAL(W.PtrSTR, SYSTEM.ADR(fileName)),
                       W.GENERIC_READ + W.GENERIC_WRITE,
                       {},
                       NIL,
                       W.CREATE_ALWAYS,
                       W.FILE_ATTRIBUTE_NORMAL,
                       NUL)
END FileCreate;

PROCEDURE FileRead* (
  handle: W.HANDLE; VAR buffer: ARRAY OF BYTE; count: Integer): Integer;
VAR
  result: LongWord;
BEGIN
  IF 0 = W.ReadFile(handle, SYSTEM.VAL(W.PtrSTR, SYSTEM.ADR(buffer)),
                    count, result, NIL)
  THEN
    result := -1;
  END;
  RETURN result
END FileRead;

PROCEDURE FileWrite* (
  handle: W.HANDLE; VAR buffer: ARRAY OF BYTE; Count: Integer): Integer;
VAR
  result: LongWord;
BEGIN
  IF 0 = W.WriteFile(handle, SYSTEM.VAL(W.PtrSTR, SYSTEM.ADR(buffer)),
                     Count, result, NIL)
  THEN
    result := -1;
  END;
  RETURN result
END FileWrite;
(*
PROCEDURE FileSeek(Handle: Integer; const Offset: Int64; Origin: Integer): Int64;
BEGIN
  Result := Offset;
  Int64Rec(Result).Lo := SetFilePointer(THandle(Handle), Int64Rec(Result).Lo,
    @Int64Rec(Result).Hi, Origin);
END;
*)
PROCEDURE FileClose* (handle: W.HANDLE);
BEGIN
  Ignore.Int( W.CloseHandle(handle) );
END FileClose;
(*
PROCEDURE FileGetAttr(const FileName: shortstring): Integer;
VAR Buf : array[0..255] of char;
BEGIN
  Move(FileName[1],Buf[0],Ord(FileName[0]));
  Buf[Ord(FileName[0])] := #0;
  Result := GetFileAttributes(PChar(@Buf));
END;

PROCEDURE FileSetAttr(const FileName: shortstring; Attr: Integer): Integer;
VAR Buf : array[0..255] of char;
BEGIN
  Result := 0;
  Move(FileName[1],Buf[0],Ord(FileName[0]));
  Buf[Ord(FileName[0])] := #0;
  IF not SetFileAttributes(PChar(@Buf), Attr) THEN
    Result := GetLastError;
END;

PROCEDURE DeleteFile(const FileName: shortstring): Boolean;
VAR Buf : array[0..255] of char;
BEGIN
  Move(FileName[1],Buf[0],Ord(FileName[0]));
  Buf[Ord(FileName[0])] := #0;
  Result := Windows.DeleteFile(PChar(@Buf));
END;

PROCEDURE RenameFile(const OldName, NewName: shortstring): Boolean;
VAR OldBuf,NewBuf : array[0..255] of char;
BEGIN
  Move(OldName[1],OldBuf[0],Ord(OldName[0]));
  OldBuf[Ord(OldName[0])] := #0;
  Move(NewName[1],NewBuf[0],Ord(NewName[0]));
  NewBuf[Ord(NewName[0])] := #0;
  Result := MoveFile(PChar(@OldBuf[0]), PChar(@NewBuf[0]));
END;

PROCEDURE ChangeFileExt(const FileName, Extension: shortstring): shortstring;
VAR
  I: Integer;
BEGIN
  I := Length(FileName);
  WHILE (I > 1) and not (FileName[I] in ['.', '\', ':']) DO Dec(I);
  IF (I = 1) OR (FileName[I] <> '.') THEN I := MaxInt;
  Result := Copy(FileName, 1, I - 1);
  IF Result[0] > #0 THEN
    IF Result[Ord(Result[0])] = #0 THEN Dec(Result[0]);
  Result := Result + Extension;
END;

PROCEDURE ExtractFilePath(const FileName: shortstring): shortstring;
VAR
  I: Integer;
BEGIN
  I := Length(FileName);
  WHILE (I > 1) and not (FileName[I] in ['\', ':']) DO Dec(I);
  Result := Copy(FileName, 1, I);
  IF Result[0] > #0 THEN
    IF Result[Ord(Result[0])] = #0 THEN Dec(Result[0]);
END;

PROCEDURE ExtractFileDir(const FileName: shortstring): shortstring;
VAR
  I: Integer;
BEGIN
  I := Length(FileName);
  WHILE (I > 2) and not (FileName[I] in ['\', ':']) DO Dec(I);
  IF (I > 2) and (FileName[I] = '\') and
    not (FileName[I - 1] in ['\', ':']) THEN Dec(I);
  Result := Copy(FileName, 1, I);
  IF Result[0] > #0 THEN
    IF Result[Ord(Result[0])] = #0 THEN Dec(Result[0]);
END;

PROCEDURE ExtractFileDrive(const FileName: shortstring): shortstring;
VAR
  I, J: Integer;
BEGIN
  IF (Length(FileName) >= 3) and (FileName[3] = ':') THEN
    Result := Copy(FileName, 1, 2)
  ELSE IF (Length(FileName) >= 2) and (FileName[2] = '\') and
    (FileName[3] = '\') THEN
  BEGIN
    J := 1;
    I := 3;
    While (I < Length(FileName)) and (J < 3) do
    BEGIN
      IF FileName[I] = '\' THEN Inc(J);
      IF J < 3 THEN Inc(I);
    END;
    IF FileName[I] = '\' THEN Dec(I);
    Result := Copy(FileName, 1, I);
  end ELSE Result := '';
  IF Result[0] > #0 THEN
    IF Result[Ord(Result[0])] = #0 THEN Dec(Result[0]);
END;

PROCEDURE ExtractFileName(const FileName: shortstring): shortstring;
VAR
  I: Integer;
BEGIN
  I := Length(FileName);
  WHILE (I >= 1) and not (FileName[I] in ['\', ':']) DO Dec(I);
  Result := Copy(FileName, I + 1, 255);
  IF Result[0] > #0 THEN
    IF Result[Ord(Result[0])] = #0 THEN Dec(Result[0]);
END;

PROCEDURE ExtractFileExt(const FileName: shortstring): shortstring;
VAR
  I: Integer;
BEGIN
  I := Length(FileName);
  WHILE (I > 1) and not (FileName[I] in ['.', '\', ':']) DO Dec(I);
  IF (I > 1) and (FileName[I] = '.') THEN
    Result := Copy(FileName, I, 255) ELSE
    Result := '';
  IF Result[0] > #0 THEN
    IF Result[Ord(Result[0])] = #0 THEN Dec(Result[0]);
END;

(* The GetDiskFreeSpace Win32 API does not support partitions larger than 2GB
  under Win95.  A new Win32 function, GetDiskFreeSpaceEx, supports partitions
  larger than 2GB but only exists on Win NT 4.0 and Win95 OSR2.
  The GetDiskFreeSpaceEx function pointer variable below will be initialized
  at startup to point to either the actual OS API function if it exists on
  the system, or to an internal Delphi function if it does not.  When running
  on Win95 pre-OSR2, the output of this function will still be limited to
  the 2GB range reported by Win95, but at least you don't have to worry
  about which API function to call in code you write.  *)

VAR
  GetDiskFreeSpaceEx: PROCEDURE (Directory: PChar; VAR FreeAvailable,
    TotalSpace: TLargeInteger; TotalFree: PLargeInteger): Bool stdcall = NIL;

// This function is used if the OS doesn't support GetDiskFreeSpaceEx
PROCEDURE BackfillGetDiskFreeSpaceEx(Directory: PChar; VAR FreeAvailable,
    TotalSpace: TLargeInteger; TotalFree: PLargeInteger): Bool; stdcall;
VAR
  SectorsPerCluster, BytesPerSector, FreeClusters, TotalClusters: LongWord;
  Temp: Int64;
  Dir: PChar;
BEGIN
  IF Directory <> NIL THEN
    Dir := Directory
  ELSE
    Dir := NIL;
  Result := GetDiskFreeSpaceA(Dir, SectorsPerCluster, BytesPerSector,
    FreeClusters, TotalClusters);
  Temp := SectorsPerCluster * BytesPerSector;
  FreeAvailable := Temp * FreeClusters;
  TotalSpace := Temp * TotalClusters;
END;

// This routine initializes GetDiskFreeSpaceEx pointer according to
// current OS version

PROCEDURE InitDriveSpacePtr;
VAR
  Kernel: THandle;
BEGIN
  Kernel := GetModuleHandle(Windows.Kernel32);
  IF Kernel <> 0 THEN
    @GetDiskFreeSpaceEx := GetProcAddress(Kernel, 'GetDiskFreeSpaceExA');
  IF not Assigned(GetDiskFreeSpaceEx) THEN
    GetDiskFreeSpaceEx := @BackfillGetDiskFreeSpaceEx;
END;

PROCEDURE InternalGetDiskSpace(Drive: Byte;
  VAR TotalSpace, FreeSpaceAvailable: Int64): Bool;
VAR
  RootPath: array[0..4] of Char;
  RootPtr: PChar;
BEGIN
  RootPtr := NIL;
  IF Drive > 0 THEN
  BEGIN
    RootPath[0] := Char(Drive + $40);
    RootPath[1] := ':';
    RootPath[2] := '\';
    RootPath[3] := #0;
    RootPtr := RootPath;
  END;
  Result := GetDiskFreeSpaceEx(RootPtr, FreeSpaceAvailable, TotalSpace, NIL);
END;

PROCEDURE DiskFree(Drive: Byte): Int64;
VAR
  TotalSpace: Int64;
BEGIN
  IF not InternalGetDiskSpace(Drive, TotalSpace, Result) THEN
    Result := -1;
END;

PROCEDURE DiskSize(Drive: Byte): Int64;
VAR
  FreeSpace: Int64;
BEGIN
  IF not InternalGetDiskSpace(Drive, Result, FreeSpace) THEN
    Result := -1;
END;

PROCEDURE DiskSN(Drive : Byte) : DWORD;
type
  TVolInfo = record
    RPName : PChar;              // address of root directory of the file system
    VolNameBuf : PChar;          // address of name of the volume
    VolNameSize : DWORD;         // length of lpVolumeNameBuffer
    VolSerNum : PDWORD;          // address of volume serial number
    MaxCompLen : DWORD;          // address of system's maximum filename length
    FileSystemFlags : DWORD;     // address of file system flags
    FileSystemNameBuf : PChar;   // address of name of file system
    FileSystemNameSize : DWORD;  // length of lpFileSystemNameBuffer
  END;
Var SS1 : shortstring;
    vi  : TVolInfo;
    sn  : DWORD;
BEGIN
  SS1 := '@:\'#0;
  SS1[1] := chr(Ord(SS1[1])+Drive);
  with vi do
  BEGIN
    RPName := @SS1[1];
    VolNameBuf := NIL;
    VolNameSize := 0;
    VolSerNum := @sn;
    FileSystemNameBuf := NIL;
    FileSystemNameSize := 0;
    GetVolumeInformation(
      RPName,
      VolNameBuf,
      VolNameSize,
      VolSerNum,
      MaxCompLen,
      FileSystemFlags,
      FileSystemNameBuf,
      FileSystemNameSize);
  END;
  Result := sn;
END;

PROCEDURE ExeName : shortstring;
BEGIN
  Result := ParamStr(0);
END;

PROCEDURE ExePath : shortstring;
BEGIN
  Result := ExtractFilePath(ParamStr(0));
END;

PROCEDURE FindMatchingFile(VAR F: TSearchRec): Integer;
VAR
  LocalFileTime: TFileTime;
BEGIN
  with F do
  BEGIN
    WHILE FindData.dwFileAttributes and ExcludeAttr <> 0 DO
      IF not FindNextFile(FindHandle, FindData) THEN
      BEGIN
        Result := GetLastError;
        Exit;
      END;
    FileTimeToLocalFileTime(FindData.ftLastWriteTime, LocalFileTime);
    FileTimeToDosDateTime(LocalFileTime, LongRec(Time).Hi,
      LongRec(Time).Lo);
    Size := FindData.nFileSizeLow;
    Attr := FindData.dwFileAttributes;
    Name := FindData.cFileName;
  END;
  Result := 0;
END;

PROCEDURE FindFirst(const Path: string; Attr: Integer;
  VAR F: TSearchRec): Integer;
const
  faSpecial = faHidden OR faSysFile OR faVolumeID OR faDirectory;
BEGIN
  F.ExcludeAttr := not Attr and faSpecial;
  F.FindHandle := FindFirstFile(PChar(Path), F.FindData);
  IF F.FindHandle <> INVALID_HANDLE_VALUE THEN
  BEGIN
    Result := FindMatchingFile(F);
    IF Result <> 0 THEN FindClose(F);
  end ELSE
    Result := GetLastError;
END;

PROCEDURE FindNext(VAR F: TSearchRec): Integer;
BEGIN
  IF FindNextFile(F.FindHandle, F.FindData) THEN
    Result := FindMatchingFile(F) ELSE
    Result := GetLastError;
END;

PROCEDURE FindClose(VAR F: TSearchRec);
BEGIN
  IF F.FindHandle <> INVALID_HANDLE_VALUE THEN
    Windows.FindClose(F.FindHandle);
END;

(* TStream *)

PROCEDURE TStream.GetPosition: Longint;
BEGIN
  Result := Seek(0, 1);
END;

PROCEDURE TStream.SetPosition(Pos: Longint);
BEGIN
  Seek(Pos, 0);
END;

PROCEDURE TStream.GetSize: Longint;
VAR
  Pos: Longint;
BEGIN
  Pos := Seek(0, 1);
  Result := Seek(0, 2);
  Seek(Pos, 0);
END;

PROCEDURE TStream.StreamError;
BEGIN
  IF Assigned(FOnError) THEN FOnError(Self,FError);
END;

PROCEDURE TStream.ReadBuffer(VAR Buffer; Count: Longint);
BEGIN
  FError := se_None;
  IF (Count = 0) OR (Read(Buffer, Count) = Count) THEN Exit;
  FError := se_Read;
  StreamError;
END;

PROCEDURE TStream.WriteBuffer(const Buffer; Count: Longint);
BEGIN
  FError := se_None;
  IF (Count = 0) OR (Write(Buffer, Count) = Count) THEN Exit;
  FError := se_Write;
  StreamError;
END;

PROCEDURE TStream.CopyFrom(Source: TStream; Count: Longint): Longint;
const
  MaxBufSize = $F000;
VAR
  BufSize, N: Integer;
  Buffer: PChar;
BEGIN
  IF Count = 0 THEN
  BEGIN
    Source.Position := 0;
    Count := Source.Size;
  END;
  Result := Count;
  IF Count > MaxBufSize THEN BufSize := MaxBufSize ELSE BufSize := Count;
  GetMem(Buffer, BufSize);
  WHILE Count <> 0 DO
  BEGIN
    IF Count > BufSize THEN N := BufSize ELSE N := Count;
    Source.ReadBuffer(Buffer^, N);
    WriteBuffer(Buffer^, N);
    Dec(Count, N);
  END;
  FreeMem(Buffer, BufSize);
END;

(* THandleStream *)

constructor THandleStream.Create(AHandle: Integer);
BEGIN
  FHandle := AHandle;
END;

PROCEDURE THandleStream.Read(VAR Buffer; Count: Longint): Longint;
BEGIN
  Result := FileRead(FHandle, Buffer, Count);
  IF Result = -1 THEN Result := 0;
END;

PROCEDURE THandleStream.Write(const Buffer; Count: Longint): Longint;
BEGIN
  Result := FileWrite(FHandle, Buffer, Count);
  IF Result = -1 THEN Result := 0;
END;

PROCEDURE THandleStream.Seek(Offset: Longint; Origin: Word): Longint;
BEGIN
  Result := FileSeek(FHandle, Offset, Origin);
END;

(* TFileStream *)

constructor TFileStream.Create(const FileName: string; Mode: Word);
BEGIN
  FName[0] := chr(Length(FileName));
  Move(FileName[1],FName[1],Length(FileName));
  IF Mode = fmCreate THEN
  BEGIN
    FHandle := FileCreate(FileName);
    IF FHandle < 0 THEN
    BEGIN
      FError := se_Create;
      FErrorInfo := GetLastError;
      StreamError;
    END;
  end ELSE
  BEGIN
    FHandle := FileOpen(FileName, Mode);
    IF FHandle < 0 THEN
    BEGIN
      FError := se_Open;
      FErrorInfo := GetLastError;
      StreamError;
    END;
  END;
END;

destructor TFileStream.Destroy;
BEGIN
  IF FHandle >= 0 THEN FileClose(FHandle);
END;

PROCEDURE TFileStream.Flush;
BEGIN
  IF FHandle >= 0 THEN FlushFileBuffers(FHandle);
END;

PROCEDURE TFileStream.Truncate;
BEGIN
  IF FHandle >= 0 THEN SetEndOfFile(FHandle);
END;

PROCEDURE TFileStream.SetSize(NewSize: Longint);
BEGIN
  Position := NewSize-1;
  Truncate;
END;

(* TCustomMemoryStream *)

PROCEDURE TCustomMemoryStream.SetPointer(Ptr: Pointer; Size: Longint);
BEGIN
  FMemory := Ptr;
  FSize := Size;
END;

PROCEDURE TCustomMemoryStream.Read(VAR Buffer; Count: Longint): Longint;
BEGIN
  IF (FPosition >= 0) and (Count >= 0) THEN
  BEGIN
    Result := FSize - FPosition;
    IF Result > 0 THEN
    BEGIN
      IF Result > Count THEN Result := Count;
      Move(Pointer(Longint(FMemory) + FPosition)^, Buffer, Result);
      Inc(FPosition, Result);
      Exit;
    END;
  END;
  Result := 0;
END;

PROCEDURE TCustomMemoryStream.Seek(Offset: Longint; Origin: Word): Longint;
BEGIN
  case Origin of
    soFromBeginning: FPosition := Offset;
    soFromCurrent: Inc(FPosition, Offset);
    soFromEnd: FPosition := FSize + Offset;
  END;
  Result := FPosition;
END;

PROCEDURE TCustomMemoryStream.SaveToStream(Stream: TStream);
BEGIN
  IF FSize <> 0 THEN Stream.WriteBuffer(FMemory^, FSize);
END;

PROCEDURE TCustomMemoryStream.SaveToFile(const FileName: string);
VAR
  Stream: TStream;
BEGIN
  Stream := TFileStream.Create(FileName, fmCreate);
  try
    SaveToStream(Stream);
  finally
    Stream.Free;
  END;
END;

(* TMemoryStream *)

const
  MemoryDelta = $2000; (* Must be a power of 2 *)

destructor TMemoryStream.Destroy;
BEGIN
  Clear;
  inherited Destroy;
END;

PROCEDURE TMemoryStream.Clear;
BEGIN
  SetCapacity(0);
  FSize := 0;
  FPosition := 0;
END;

PROCEDURE TMemoryStream.LoadFromStream(Stream: TStream);
VAR
  Count: Longint;
BEGIN
  Stream.Position := 0;
  Count := Stream.Size;
  SetSize(Count);
  IF Count <> 0 THEN Stream.ReadBuffer(FMemory^, Count);
END;

PROCEDURE TMemoryStream.LoadFromFile(const FileName: string);
VAR
  Stream: TStream;
BEGIN
  Stream := TFileStream.Create(FileName, fmOpenRead OR fmShareDenyWrite);
  try
    LoadFromStream(Stream);
  finally
    Stream.Free;
  END;
END;

PROCEDURE TMemoryStream.SetCapacity(NewCapacity: Longint);
BEGIN
  SetPointer(Realloc(NewCapacity), FSize);
  FCapacity := NewCapacity;
END;

PROCEDURE TMemoryStream.SetSize(NewSize: Longint);
VAR
  OldPosition: Longint;
BEGIN
  OldPosition := FPosition;
  SetCapacity(NewSize);
  FSize := NewSize;
  IF OldPosition > NewSize THEN Seek(0, soFromEnd);
END;

PROCEDURE TMemoryStream.Realloc(VAR NewCapacity: Longint): Pointer;
BEGIN
  IF NewCapacity > 0 THEN
    NewCapacity := (NewCapacity + (MemoryDelta - 1)) and not (MemoryDelta - 1);
  Result := Memory;
  IF NewCapacity <> FCapacity THEN
  BEGIN
    IF NewCapacity = 0 THEN
    BEGIN
      GlobalFreePtr(Memory);
      Result := NIL;
    end ELSE
    BEGIN
      IF Capacity = 0 THEN
        Result := GlobalAllocPtr(HeapAllocFlags, NewCapacity)
      ELSE
        Result := GlobalReallocPtr(Memory, NewCapacity, HeapAllocFlags);
      IF Result = NIL THEN StreamError;
    END;
  END;
END;

PROCEDURE TMemoryStream.Write(const Buffer; Count: Longint): Longint;
VAR
  Pos: Longint;
BEGIN
  IF (FPosition >= 0) and (Count >= 0) THEN
  BEGIN
    Pos := FPosition + Count;
    IF Pos > 0 THEN
    BEGIN
      IF Pos > FSize THEN
      BEGIN
        IF Pos > FCapacity THEN
          SetCapacity(Pos);
        FSize := Pos;
      END;
      System.Move(Buffer, Pointer(Longint(FMemory) + FPosition)^, Count);
      FPosition := Pos;
      Result := Count;
      Exit;
    END;
  END;
  Result := 0;
END;

(*Version routines*)

PROCEDURE GetFileVersion : string;
Var j,w   : Cardinal;
    s,s1  : shortstring;
    buf   : pointer;
    buf2  : pointer;
    q     : DWord;
//    vsinfo: ^VS_FIXEDFILEINFO;
BEGIN
  s := ParamStr(0) + #0;
  j := GetFileVersionInfoSize(@s[1],w);
  IF j = 0 THEN Exit;
  buf := Ptr(GlobalAlloc(GMEM_FIXED,j));
  GetFileVersionInfo(@s[1], 0, j, buf);
  VerQueryValue(buf,
                '\StringFileInfo\041904E3\ProductVersion',
                buf2,
                q);
  Move(buf2^,s1[1],q-1);
  s1[0] := chr(q-1);
  GlobalFree(Cardinal(buf));
  Result := s1;
END;

PROCEDURE GetFullFileVersion : string;
Var j,w   : Cardinal;
    s     : shortstring;
    buf   : pointer;
    buf2  : pointer;
    q     : DWord;
    vsinfo: ^VS_FIXEDFILEINFO;
    mVer,
    lVer,
    rVer,
    bVer,
    flag  : DWord;
BEGIN
  s := ParamStr(0) + #0;
  j := GetFileVersionInfoSize(@s[1],w);
  IF j = 0 THEN Exit;
  buf := Ptr(GlobalAlloc(GMEM_FIXED,j));
  GetFileVersionInfo(@s[1], 0, j, buf);
  VerQueryValue(buf, '\', buf2, q);
  vsinfo := buf2;
  mVer := vsInfo^.dwProductVersionMS div $FFFF;
  lVer := vsInfo^.dwProductVersionMS mod $10000;
  rVer := vsInfo^.dwProductVersionLS div $FFFF;
  bVer := vsInfo^.dwProductVersionLS mod $10000;
  flag := vsInfo^.dwFileFlags;
  s := IntToStr(mVer) + '.' +
       IntToStr(lVer) + '.' +
       IntToStr(rVer) + '.' +
       IntToStr(bVer);
  IF (flag and VS_FF_DEBUG) > 0        THEN s := s + ' debug ';
  IF (flag and VS_FF_PRERELEASE) > 0   THEN s := s + ' prerelease ';
  IF (flag and VS_FF_PRIVATEBUILD) > 0 THEN s := s + ' private ';
  IF (flag and VS_FF_SPECIALBUILD) > 0 THEN s := s + ' special ';
  Result := s;
  GlobalFree(Cardinal(buf));
END;

(*browsing for folders and computers routines*)

type

(* TSHItemID -- Item ID *)

  PSHItemID = ^TSHItemID;
  TSHItemID = packed record           (* mkid *)
    cb: Word;                         (* Size of the ID (including cb itself) *)
    abID: array[0..0] of Byte;        (* The item ID (variable length) *)
  END;

(* TItemIDList -- List if item IDs (combined with 0-terminator) *)

  PItemIDList = ^TItemIDList;
  TItemIDList = packed record         (* idl *)
     mkid: TSHItemID;
   END;

  TFNBFFCallBack = function(Wnd: HWND; uMsg: UINT; lParam, lpData: LPARAM): Integer stdcall;

  PBrowseInfo = ^TBrowseInfo;
  TBrowseInfo = packed record
    hwndOwner: HWND;
    pidlRoot: PItemIDList;
    pszDisplayName: LPSTR;  (* Return display name of item selected. *)
    lpszTitle: LPCSTR;      (* text to go in the banner over the tree. *)
    ulFlags: UINT;          (* Flags that control the return stuff *)
    lpfn: TFNBFFCallBack;
    lParam: LPARAM;         (* extra info that's passed back in callbacks *)
    iImage: Integer;        (* output var: where to return the Image index. *)
  END;

const
  shell32 = 'shell32.dll';
  ole32    = 'ole32.dll';

(* Browsing for directory *)

  BIF_RETURNONLYFSDIRS   = $0001; (* For finding a folder to start document searching *)
  BIF_DONTGOBELOWDOMAIN  = $0002; (* For starting the Find Computer *)
  BIF_STATUSTEXT         = $0004;
  BIF_RETURNFSANCESTORS  = $0008;

  BIF_BROWSEFORCOMPUTER  = $1000; (* Browsing for Computers *)
  BIF_BROWSEFORPRINTER   = $2000; (* Browsing for Printers *)
  BIF_BROWSEINCLUDEFILES = $4000; (* Browsing for Everything *)

(* message from browser *)

  BFFM_INITIALIZED       = 1;
  BFFM_SELCHANGED        = 2;

(* messages to browser *)

  BFFM_SETSTATUSTEXT      = (WM_USER + 100);
  BFFM_ENABLEOK           = (WM_USER + 101);
  BFFM_SETSELECTION       = (WM_USER + 102);

const
  CSIDL_DRIVES             = $0011;
  CSIDL_NETWORK            = $0012;

PROCEDURE SHBrowseForFolder(VAR lpbi: TBrowseInfo): PItemIDList; stdcall;
  far; external Shell32 name 'SHBrowseForFolder';
PROCEDURE SHGetPathFromIDList(pidl: PItemIDList; pszPath: LPSTR): BOOL; stdcall;
  far; external Shell32 name 'SHGetPathFromIDList';
PROCEDURE SHGetSpecialFolderLocation(hwndOwner: HWND; nFolder: Integer;
  VAR ppidl: PItemIDList): HResult; stdcall; far; external Shell32
  name 'SHGetSpecialFolderLocation';
PROCEDURE CoTaskMemAlloc(cb : DWORD) : pointer; stdcall; external ole32
  name 'CoTaskMemAlloc';
PROCEDURE CoTaskMemFree(pv: Pointer); stdcall; external ole32
  name 'CoTaskMemFree';

PROCEDURE BrowseForFolder(AParent: HWND;
                         ATitle : string;
                         AKind  : TBrowseFolderKind) : string;
VAR pi   : PItemIDList;
    bi   : TBrowseInfo;
    pc   : array[0..MAX_PATH] of char;
BEGIN
  strpcopy(@pc[0],ATitle);
  FillChar(bi,SizeOf(bi),0);
  with bi do
  BEGIN
    hwndOwner := AParent;
    case AKind of
      bfDrives : SHGetSpecialFolderLocation(0, CSIDL_DRIVES,pidlRoot);
      bfComputers : SHGetSpecialFolderLocation(0, CSIDL_NETWORK,pidlRoot);
    END;
    pszDisplayName := NIL;
    lpszTitle := @pc[0];
    case AKind of
      bfAll,
      bfDrives : ulFlags := BIF_RETURNONLYFSDIRS OR BIF_RETURNFSANCESTORS;
      bfComputers : ulFlags := BIF_DONTGOBELOWDOMAIN OR BIF_BROWSEFORCOMPUTER;
    END;
    lpfn := NIL;
    lParam := 0;
    iImage := 0;
  END;
  pi := SHBrowseForFolder(bi);
  IF bi.pidlRoot <> NIL THEN CoTaskMemFree(bi.pidlRoot);
  Result := '';
  IF pi <> NIL THEN
  BEGIN
    SHGetPathFromIDList(pi,@pc);
    CoTaskMemFree(pi);
    Result := StrPas(@pc[0]);
  END;
END;

PROCEDURE QuotedStr;
VAR
  I: Integer;
BEGIN
  Result := S;
  for I := Length(Result) downto 1 do
    IF Result[I] = Quote THEN Insert(Quote, Result, I);
  Result := Quote + Result + Quote;
END;

(* AnsiExtractQuotedStr removes the Quote characters from the beginning and end
  of a quoted string, and reduces pairs of Quote characters within the quoted
  string to a single character. If the first character in Src is not the Quote
  character, the function returns an empty string.  The function copies
  characters from the Src to the result string until the second solitary
  Quote character or the first null character in Src. The Src parameter is
  updated to point to the first character following the quoted string.  If
  the Src string does not contain a matching end Quote character, the Src
  parameter is updated to point to the terminating null character in Src.
  This function supports multibyte character strings (MBCS).  *)

PROCEDURE AnsiExtractQuotedStr(VAR Src: PChar; Quote: Char): string;
VAR
  P, Dest: PChar;
  DropCount: Integer;
BEGIN
  Result := '';
  IF (Src = NIL) OR (Src^ <> Quote) THEN Exit;
  Inc(Src);
  DropCount := 1;
  P := Src;
  Src := StrScan(Src, Quote);
  WHILE Src <> NIL DO   // count adjacent pairs of quote chars
  BEGIN
    Inc(Src);
    IF Src^ <> Quote THEN Break;
    Inc(Src);
    Inc(DropCount);
    Src := StrScan(Src, Quote);
  END;
  IF Src = NIL THEN Src := StrEnd(P);
  IF ((Src - P) <= 1) THEN Exit;
  IF DropCount = 1 THEN
    SetString(Result, P, Src - P - 1)
  ELSE
  BEGIN
    SetLength(Result, Src - P - DropCount);
    Dest := PChar(Result);
    Src := StrScan(P, Quote);
    WHILE Src <> NIL DO
    BEGIN
      Inc(Src);
      IF Src^ <> Quote THEN Break;
      Move(P^, Dest^, Src - P);
      Inc(Dest, Src - P);
      Inc(Src);
      P := Src;
      Src := StrScan(Src, Quote);
    END;
    IF Src = NIL THEN Src := StrEnd(P);
    Move(P^, Dest^, Src - P - 1);
  END;
END;

PROCEDURE InitPlatformId;
BEGIN
  OSVersionInfo.dwOSVersionInfoSize := SizeOf(OSVersionInfo);
  IF GetVersionEx(OSVersionInfo) THEN
(*    with OSVersionInfo do
    BEGIN
      Win32Platform := dwPlatformId;
      Win32MajorVersion := dwMajorVersion;
      Win32MinorVersion := dwMinorVersion;
      Win32BuildNumber := dwBuildNumber;
      Win32CSDVersion := szCSDVersion;
    END;*)
END;

BEGIN
  Win32Platform-: Integer = 0;

(* Win32 OS version information -
  see TOSVersionInfo.dwMajorVersion/dwMinorVersion/dwBuildNumber *)

  Win32MajorVersion*: Integer = 0;
  Win32MinorVersion*: Integer = 0;
  Win32BuildNumber*: Integer = 0;

(* Win32 OS extra version info string -
  see TOSVersionInfo.szCSDVersion *)
  Win32CSDVersion*: string = '';

  InitDriveSpacePtr;
  InitPlatformId;
*)
END AclUtils.
