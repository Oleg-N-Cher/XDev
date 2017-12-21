PROGRAM AclUtils;

interface

uses Windows;

type
  TColor = -$7FFFFFFF -1..$7FFFFFFF;

const

  Design_PPI = 96; // pixels per inch at design time

  { Colors }

  clScrollBar = COLOR_SCROLLBAR or $80000000;
  clBackground = COLOR_BACKGROUND or $80000000;
  clActiveCaption = COLOR_ACTIVECAPTION or $80000000;
  clInactiveCaption = COLOR_INACTIVECAPTION or $80000000;
  clMenu = COLOR_MENU or $80000000;
  clWindow = COLOR_WINDOW or $80000000;
  clWindowFrame = COLOR_WINDOWFRAME or $80000000;
  clMenuText = COLOR_MENUTEXT or $80000000;
  clWindowText = COLOR_WINDOWTEXT or $80000000;
  clCaptionText = COLOR_CAPTIONTEXT or $80000000;
  clActiveBorder = COLOR_ACTIVEBORDER or $80000000;
  clInactiveBorder = COLOR_INACTIVEBORDER or $80000000;
  clAppWorkSpace = COLOR_APPWORKSPACE or $80000000;
  clHighlight = COLOR_HIGHLIGHT or $80000000;
  clHighlightText = COLOR_HIGHLIGHTTEXT or $80000000;
  clBtnFace = COLOR_BTNFACE or $80000000;
  clBtnShadow = COLOR_BTNSHADOW or $80000000;
  clGrayText = COLOR_GRAYTEXT or $80000000;
  clBtnText = COLOR_BTNTEXT or $80000000;
  clInactiveCaptionText = COLOR_INACTIVECAPTIONTEXT or $80000000;
  clBtnHighlight = COLOR_BTNHIGHLIGHT or $80000000;
  cl3DDkShadow = COLOR_3DDKSHADOW or $80000000;
  cl3DLight = COLOR_3DLIGHT or $80000000;
  clInfoText = COLOR_INFOTEXT or $80000000;
  clInfoBk = COLOR_INFOBK or $80000000;

  clBlack = TColor($000000);
  clMaroon = TColor($000080);
  clGreen = TColor($008000);
  clOlive = TColor($008080);
  clNavy = TColor($800000);
  clPurple = TColor($800080);
  clTeal = TColor($808000);
  clGray = TColor($808080);
  clSilver = TColor($C0C0C0);
  clRed = TColor($0000FF);
  clLime = TColor($00FF00);
  clYellow = TColor($00FFFF);
  clBlue = TColor($FF0000);
  clFuchsia = TColor($FF00FF);
  clAqua = TColor($FFFF00);
  clLtGray = TColor($C0C0C0);
  clDkGray = TColor($808080);
  clWhite = TColor($FFFFFF);
  clNone = TColor($1FFFFFFF);
  clDefault = TColor($20000000);

{ TStream seek origins }

  soFromBeginning = 0;
  soFromCurrent = 1;
  soFromEnd = 2;

{ TFileStream create mode }

  fmCreate = $FFFF;

{ File open modes }

  fmOpenRead       = $0000;
  fmOpenWrite      = $0001;
  fmOpenReadWrite  = $0002;
  fmOpenTruncate   = $0004;
  fmShareCompat    = $0000;
  fmShareExclusive = $0010;
  fmShareDenyWrite = $0020;
  fmShareDenyRead  = $0030;
  fmShareDenyNone  = $0040;

{ File attribute constants }

  faReadOnly  = $00000001;
  faHidden    = $00000002;
  faSysFile   = $00000004;
  faVolumeID  = $00000008;
  faDirectory = $00000010;
  faArchive   = $00000020;
  faAnyFile   = $0000003F;

{ File mode magic numbers }

  fmClosed = $D7B0;
  fmInput  = $D7B1;
  fmOutput = $D7B2;
  fmInOut  = $D7B3;

{ Seconds and milliseconds per day }

  SecsPerDay = 24 * 60 * 60;
  MSecsPerDay = SecsPerDay * 1000;

{ Days between 1/1/0001 and 12/31/1899 }

  DateDelta = 693594;

{ Win32 platform identifier. }

  Win32Platform: Integer = 0;

{ Win32 OS version information -
  see TOSVersionInfo.dwMajorVersion/dwMinorVersion/dwBuildNumber }

  Win32MajorVersion: Integer = 0;
  Win32MinorVersion: Integer = 0;
  Win32BuildNumber: Integer = 0;

{ Win32 OS extra version info string -
  see TOSVersionInfo.szCSDVersion }
  Win32CSDVersion: string = '';

type

{ Standard Character set type }

  TSysCharSet = set of Char;

{ Type conversion records }

  WordRec = packed record
    Lo, Hi: Byte;
  end;

  LongRec = packed record
    Lo, Hi: Word;
  end;

  Int64Rec = packed record
    Lo, Hi: DWORD;
  end;

  TMethod = record
    Code, Data: Pointer;
  end;

{ General arrays }

  PByteArray = ^TByteArray;
  TByteArray = array[0..32767] of Byte;

  PWordArray = ^TWordArray;
  TWordArray = array[0..16383] of Word;

{ Generic procedure pointer }

  TProcedure = procedure;

{ Generic filename type }

{$IFDEF VirtualPascal}
  TFileName = string;
  LongWord = Word;
  Int64 = LongWord;
{$ELSE}
  TFileName = type string;
{$ENDIF}

{ Search record used by FindFirst, FindNext, and FindClose }

  TSearchRec = record
    Time: Integer;
    Size: Integer;
    Attr: Integer;
    Name: TFileName;
    ExcludeAttr: Integer;
    FindHandle: THandle;
    FindData: TWin32FindData;
  end;

{ Typed-file and untyped-file record }

  TFileRec = record
    Handle: Integer;
    Mode: Integer;
    RecSize: Cardinal;
    Private: array[1..28] of Byte;
    UserData: array[1..32] of Byte;
    Name: array[0..259] of Char;
  end;

{ Text file record structure used for Text files }

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
  end;

{ FloatToText, FloatToTextFmt, TextToFloat, and FloatToDecimal type codes }

  TFloatValue = (fvExtended, fvCurrency);

{ FloatToText format codes }

  TFloatFormat = (ffGeneral, ffExponent, ffFixed, ffNumber, ffCurrency);

{ FloatToDecimal result record }

  TFloatRec = packed record
    Exponent: Smallint;
    Negative: Boolean;
    Digits: array[0..20] of Char;
  end;

{ Date and time record }

  TTimeStamp = record
    Time: Integer;      { Number of milliseconds since midnight }
    Date: Integer;      { One plus number of days since 1/1/0001 }
  end;

{ MultiByte Character Set (MBCS) byte type }
  TMbcsByteType = (mbSingleByte, mbLeadByte, mbTrailByte);

{ System Locale information record }
  TSysLocale = packed record
    DefaultLCID: LCID;
    PriLangID: LANGID;
    SubLangID: LANGID;
    FarEast: Boolean;
    MiddleEast: Boolean;
  end;

{ TStream abstract class }

  TStreamError = (se_None,se_Create,se_Open,se_Read,se_Write,se_Pos);
  TStreamErrorEvent = procedure(Sender : TObject; AError: TStreamError) of object;

  TStream = class(TObject)
  private
    FError : TStreamError;
    FErrorInfo : integer;
    FOnError : TStreamErrorEvent;
    function GetPosition: Longint;
    procedure SetPosition(Pos: Longint);
    function GetSize: Longint;
    procedure StreamError;
  public
    function Read(var Buffer; Count: Longint): Longint; virtual; abstract;
    function Write(const Buffer; Count: Longint): Longint; virtual; abstract;
    function Seek(Offset: Longint; Origin: Word): Longint; virtual; abstract;
    procedure ReadBuffer(var Buffer; Count: Longint);
    procedure WriteBuffer(const Buffer; Count: Longint);
    function CopyFrom(Source: TStream; Count: Longint): Longint;
    procedure SetSize(NewSize: Longint); virtual; abstract;
    property Position: Longint read GetPosition write SetPosition;
    property Size: Longint read GetSize;
    property Error : TStreamError read FError;
    property ErrorInfo : integer read FErrorInfo;
    property OnError : TStreamErrorEvent read FOnError write FOnError;
  end;

{ THandleStream class }

  THandleStream = class(TStream)
  private
    FHandle: Integer;
  public
    constructor Create(AHandle: Integer);
    function Read(var Buffer; Count: Longint): Longint; override;
    function Write(const Buffer; Count: Longint): Longint; override;
    function Seek(Offset: Longint; Origin: Word): Longint; override;
    property Handle: Integer read FHandle;
  end;

{ TFileStream class }

  TFileStream = class(THandleStream)
  private
    FName : shortstring;
  public
    constructor Create(const FileName: string; Mode: Word);
    destructor Destroy; override;
    procedure Flush;
    procedure Truncate;
    procedure SetSize(NewSize: Longint); override;
    property Name : shortstring read FName;
  end;

{ TCustomMemoryStream abstract class }

  TCustomMemoryStream = class(TStream)
  private
    FMemory: Pointer;
    FSize, FPosition: Longint;
  protected
    procedure SetPointer(Ptr: Pointer; Size: Longint);
  public
    function Read(var Buffer; Count: Longint): Longint; override;
    function Seek(Offset: Longint; Origin: Word): Longint; override;
    procedure SaveToStream(Stream: TStream);
    procedure SaveToFile(const FileName: string);
    property Memory: Pointer read FMemory;
  end;

{ TMemoryStream }

  TMemoryStream = class(TCustomMemoryStream)
  private
    FCapacity: Longint;
    procedure SetCapacity(NewCapacity: Longint);
  protected
    function Realloc(var NewCapacity: Longint): Pointer; virtual;
    property Capacity: Longint read FCapacity write SetCapacity;
  public
    destructor Destroy; override;
    procedure Clear;
    procedure LoadFromStream(Stream: TStream);
    procedure LoadFromFile(const FileName: string);
    procedure SetSize(NewSize: Longint); override;
    function Write(const Buffer; Count: Longint): Longint; override;
  end;

{Graphic routins}

type
  TFillDirection = (fdTopToBottom, fdBottomToTop, fdLeftToRight, fdRightToLeft);

function WidthOf(R: TRect): Integer;
function HeightOf(R: TRect): Integer;

function ColorToRGB(Color: TColor): Longint;
procedure GradientFillRect(DC : HDC;
                           ARect: TRect;
                           StartColor, EndColor: TColor;
                           Direction: TFillDirection;
                           Colors: Byte);

{String management routins}

function StrPas(Str: PChar): string;
function StrLCopy(Dest, Source: PChar; MaxLen: Cardinal): PChar;
function StrCopy(Dest, Source: PChar): PChar;
function StrEnd(Str: PChar): PChar;
function StrPCopy(Dest: PChar; const Source: string): PChar;
function StrCat(Dest, Source: PChar): PChar;
function StrLen(Str: PChar): Cardinal;
function StrMove(Dest, Source: PChar; Count: Cardinal): PChar;
function StrAlloc(Size: Cardinal): PChar;
function StrNew(Str: PChar): PChar;
function StrScan(const Str: PChar; Chr: Char): PChar;
procedure StrDispose(Str: PChar);
function CompareMem(P1, P2: Pointer; Length: Integer): Boolean;
function CompareStr(const S1, S2: string): Integer;
function AnsiCompareText(const S1, S2: string): Integer;
function UpperCase(const S: string): string;
function AnsiUpperCase(const S: string): string;
function LowerCase(const S: string): string;
function AnsiLowerCase(const S: string): string;

function Trim(const S: string): string;
function TrimLeft(const S: string): string;
function TrimRight(const S: string): string;

procedure BinToHex(Binary, Text: PChar; Count: Integer);
procedure HexToBin(Text, Binary: PChar; Count: Integer);
function IntToStr(i : integer) : string;
function StrToInt(s : string) : integer;
function StrToIntDef(s : string; Default: Integer) : integer;
function StrToFloat(s: String): Real;
function FloatToStr(m: Real): String;

{ Date/time support routines }

var
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

function EncodeDate(Year, Month, Day: Word): TDateTime;
function EncodeTime(Hour, Min, Sec, MSec: Word): TDateTime;
procedure DecodeDate(Date: TDateTime; var Year, Month, Day: Word);
procedure DecodeTime(Time: TDateTime; var Hour, Min, Sec, MSec: Word);
function Now : TDateTime;

{ File management routines }

function FileOpen(const FileName: string; Mode: LongWord): Integer;
function FileCreate(const FileName: string): Integer;
function FileRead(Handle: Integer; var Buffer; Count: Integer): Integer;
function FileWrite(Handle: Integer; const Buffer; Count: Integer): Integer;
function FileSeek(Handle: Integer; const Offset: Int64; Origin: Integer): Int64;
procedure FileClose(Handle: Integer);
function FileGetAttr(const FileName: shortstring): Integer;
function FileSetAttr(const FileName: shortstring; Attr: Integer): Integer;
function DeleteFile(const FileName: shortstring): Boolean;
function RenameFile(const OldName, NewName: shortstring): Boolean;
function ChangeFileExt(const FileName, Extension: shortstring): shortstring;
function ExtractFilePath(const FileName: shortstring): shortstring;
function ExtractFileDir(const FileName: shortstring): shortstring;
function ExtractFileDrive(const FileName: shortstring): shortstring;
function ExtractFileName(const FileName: shortstring): shortstring;
function ExtractFileExt(const FileName: shortstring): shortstring;
function DiskFree(Drive: Byte): Int64;
function DiskSize(Drive: Byte): Int64;
function DiskSN(Drive : Byte) : DWORD;
function ExeName : shortstring;
function ExePath : shortstring;
function FindFirst(const Path: string; Attr: Integer;
  var F: TSearchRec): Integer;
function FindNext(var F: TSearchRec): Integer;
procedure FindClose(var F: TSearchRec);

{Version routines}

function GetFileVersion : string;
function GetFullFileVersion : string;

{Browse for folders}
type
  TBrowseFolderKind = (bfAll,bfDrives,bfComputers);

function BrowseForFolder(AParent: HWND;
                         ATitle : string;
                         AKind  : TBrowseFolderKind) : string;

function QuotedStr(const S: string; Quote: char): string;
function AnsiExtractQuotedStr(var Src: PChar; Quote: Char): string;


{ OS Version }
var
  OSVersionInfo: TOSVersionInfo;

implementation

uses Messages;

function Min(Val1, Val2 : integer) : integer;
begin
  if Val2 < Val1 then Result := Val2
                 else Result := Val1;
end;

function Max(Val1, Val2 : integer) : integer;
begin
  if Val2 > Val1 then Result := Val2
                 else Result := Val1;
end;

function WidthOf(R: TRect): Integer;
begin
  Result := R.Right - R.Left;
end;

function HeightOf(R: TRect): Integer;
begin
  Result := R.Bottom - R.Top;
end;

{Graphic routines}

function ColorToRGB(Color: TColor): Longint;
begin
  if Color < 0 then
    Result := GetSysColor(Color and $000000FF) else
    Result := Color;
end;

procedure GradientFillRect(DC : HDC; ARect: TRect; StartColor,
  EndColor: TColor; Direction: TFillDirection; Colors: Byte);
var
  StartRGB: array[0..2] of Byte;    { Start RGB values }
  RGBDelta: array[0..2] of Integer; { Difference between start and end RGB values }
  ColorBand: TRect;                 { Color band rectangular coordinates }
  I, Delta: Integer;
  Brush: HBrush;
begin
  if IsRectEmpty(ARect) then Exit;
  if Colors < 2 then begin
    Brush := CreateSolidBrush(ColorToRGB(StartColor));
    FillRect(DC, ARect, Brush);
    DeleteObject(Brush);
    Exit;
  end;
  StartColor := ColorToRGB(StartColor);
  EndColor := ColorToRGB(EndColor);
  case Direction of
    fdTopToBottom, fdLeftToRight: begin
      { Set the Red, Green and Blue colors }
      StartRGB[0] := GetRValue(StartColor);
      StartRGB[1] := GetGValue(StartColor);
      StartRGB[2] := GetBValue(StartColor);
      { Calculate the difference between begin and end RGB values }
      RGBDelta[0] := GetRValue(EndColor) - StartRGB[0];
      RGBDelta[1] := GetGValue(EndColor) - StartRGB[1];
      RGBDelta[2] := GetBValue(EndColor) - StartRGB[2];
    end;
    fdBottomToTop, fdRightToLeft: begin
      { Set the Red, Green and Blue colors }
      { Reverse of TopToBottom and LeftToRight directions }
      StartRGB[0] := GetRValue(EndColor);
      StartRGB[1] := GetGValue(EndColor);
      StartRGB[2] := GetBValue(EndColor);
      { Calculate the difference between begin and end RGB values }
      { Reverse of TopToBottom and LeftToRight directions }
      RGBDelta[0] := GetRValue(StartColor) - StartRGB[0];
      RGBDelta[1] := GetGValue(StartColor) - StartRGB[1];
      RGBDelta[2] := GetBValue(StartColor) - StartRGB[2];
    end;
  end; {case}
  { Calculate the color band's coordinates }
  ColorBand := ARect;
  if Direction in [fdTopToBottom, fdBottomToTop] then begin
    Colors := Max(2, Min(Colors, HeightOf(ARect)));
    Delta := HeightOf(ARect) div Colors;
  end
  else begin
    Colors := Max(2, Min(Colors, WidthOf(ARect)));
    Delta := WidthOf(ARect) div Colors;
  end;
//  Pen := CreatePen(ps_Solid,;
//  with Canvas.Pen do begin { Set the pen style and mode }
//    Style := psSolid;
//    Mode := pmCopy;
//  end;
  { Perform the fill }
  if Delta > 0 then begin
    for I := 0 to Colors do begin
      case Direction of
        { Calculate the color band's top and bottom coordinates }
        fdTopToBottom, fdBottomToTop: begin
          ColorBand.Top := ARect.Top + I * Delta;
          ColorBand.Bottom := ColorBand.Top + Delta;
        end;
        { Calculate the color band's left and right coordinates }
        fdLeftToRight, fdRightToLeft: begin
          ColorBand.Left := ARect.Left + I * Delta;
          ColorBand.Right := ColorBand.Left + Delta;
        end;
      end; {case}
      { Calculate the color band's color }
      Brush := CreateSolidBrush(RGB(
        StartRGB[0] + MulDiv(I, RGBDelta[0], Colors - 1),
        StartRGB[1] + MulDiv(I, RGBDelta[1], Colors - 1),
        StartRGB[2] + MulDiv(I, RGBDelta[2], Colors - 1)));
      FillRect(DC, ColorBand, Brush);
      DeleteObject(Brush);
    end;
  end;
  if Direction in [fdTopToBottom, fdBottomToTop] then
    Delta := HeightOf(ARect) mod Colors
  else Delta := WidthOf(ARect) mod Colors;
  if Delta > 0 then begin
    case Direction of
      { Calculate the color band's top and bottom coordinates }
      fdTopToBottom, fdBottomToTop: begin
        ColorBand.Top := ARect.Bottom - Delta;
        ColorBand.Bottom := ColorBand.Top + Delta;
      end;
      { Calculate the color band's left and right coordinates }
      fdLeftToRight, fdRightToLeft: begin
        ColorBand.Left := ARect.Right - Delta;
        ColorBand.Right := ColorBand.Left + Delta;
      end;
    end; {case}
    case Direction of
      fdTopToBottom, fdLeftToRight:
        Brush := CreateSolidBrush(EndColor);
      else {fdBottomToTop, fdRightToLeft }
        Brush := CreateSolidBrush(StartColor);
    end;
    FillRect(DC, ColorBand, Brush);
    DeleteObject(Brush);
  end;
end;

{String management routins}

procedure BinToHex(Binary, Text: PChar; Count: Integer);
const
  HexChars: array[0..15] of Char = '0123456789ABCDEF';
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
  begin
    Text^ := HexChars[(Byte(Binary[I]) and $F0) SHR 4];
    Inc(Text);
    Text^ := HexChars[(Byte(Binary[I]) and $0F)];
    Inc(Text);
  end;
end;

procedure HexToBin(Text, Binary: PChar; Count: Integer);
var
  I: Integer;

  function Bt(c : char) : byte;
  begin
    if c < 'A' then Result := Ord(c) - 48
               else Result := Ord(c) - 55;
  end;
begin
  for I := 0 to Count - 1 do
    Binary[i] := chr((Bt(Text[2*I]) shl 4) or Bt(Text[2*I+1]));
end;

function StrPas(Str: PChar): string;
begin
//  Result := Str;
end;

function CompareStr(const S1, S2: string): Integer; assembler;
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
end;

function CompareMem(P1, P2: Pointer; Length: Integer): Boolean; assembler;
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
end;

function CompareText(const S1, S2: string): Integer; assembler;
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
end;

function StrLCopy(Dest, Source: PChar; MaxLen: Cardinal): PChar; assembler;
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
end;

function StrScan(const Str: PChar; Chr: Char): PChar; assembler;
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
end;

function StrCopy(Dest, Source: PChar): PChar; assembler;
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
end;

function StrEnd(Str: PChar): PChar; assembler;
asm
        MOV     EDX,EDI
        MOV     EDI,EAX
        MOV     ECX,0FFFFFFFFH
        XOR     AL,AL
        REPNE   SCASB
        LEA     EAX,[EDI-1]
        MOV     EDI,EDX
end;

function StrPCopy(Dest: PChar; const Source: string): PChar;
begin
  Result := StrLCopy(Dest, PChar(Source), 255);
end;

function StrCat(Dest, Source: PChar): PChar;
begin
  StrCopy(StrEnd(Dest), Source);
  Result := Dest;
end;

function StrLen(Str: PChar): Cardinal; assembler;
asm
        MOV     EDX,EDI
        MOV     EDI,EAX
        MOV     ECX,0FFFFFFFFH
        XOR     AL,AL
        REPNE   SCASB
        MOV     EAX,0FFFFFFFEH
        SUB     EAX,ECX
        MOV     EDI,EDX
end;

function StrMove(Dest, Source: PChar; Count: Cardinal): PChar; assembler;
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
end;

function StrAlloc(Size: Cardinal): PChar;
begin
  Inc(Size, SizeOf(Cardinal));
  GetMem(Result, Size);
  Cardinal(Pointer(Result)^) := Size;
  Inc(Result, SizeOf(Cardinal));
end;

function StrNew(Str: PChar): PChar;
var
  Size: Cardinal;
begin
  if Str = nil then Result := nil else
  begin
    Size := StrLen(Str) + 1;
    Result := StrMove(StrAlloc(Size), Str, Size);
  end;
end;

procedure StrDispose(Str: PChar);
begin
  if Str <> nil then
  begin
    Dec(Str, SizeOf(Cardinal));
    FreeMem(Str, Cardinal(Pointer(Str)^));
  end;
end;

function AnsiCompareText(const S1, S2: string): Integer;
begin
  Result := CompareString(LOCALE_USER_DEFAULT, NORM_IGNORECASE,
    PChar(S1), Length(S1), PChar(S2), Length(S2)) - 2;
end;

function UpperCase(const S: string): string;
var
  Ch: Char;
  L: Integer;
  Source, Dest: PChar;
begin
  L := Length(S);
  SetLength(Result, L);
  Source := Pointer(S);
  Dest := Pointer(Result);
  while L <> 0 do
  begin
    Ch := Source^;
    if (Ch >= 'a') and (Ch <= 'z') then Dec(Ch, 32);
    Dest^ := Ch;
    Inc(Source);
    Inc(Dest);
    Dec(L);
  end;
end;

function LowerCase(const S: string): string;
var
  Ch: Char;
  L: Integer;
  Source, Dest: PChar;
begin
  L := Length(S);
  SetLength(Result, L);
  Source := Pointer(S);
  Dest := Pointer(Result);
  while L <> 0 do
  begin
    Ch := Source^;
    if (Ch >= 'A') and (Ch <= 'Z') then Inc(Ch, 32);
    Dest^ := Ch;
    Inc(Source);
    Inc(Dest);
    Dec(L);
  end;
end;

function AnsiUpperCase(const S: string): string;
var
  Len: Integer;
begin
  Len := Length(S);
  SetString(Result, PChar(S), Len);
  if Len > 0 then CharUpperBuff(Pointer(Result), Len);
end;

function AnsiLowerCase(const S: string): string;
var
  Len: Integer;
begin
  Len := Length(S);
  SetString(Result, PChar(S), Len);
  if Len > 0 then CharLowerBuff(Pointer(Result), Len);
end;

function IntToStr(i : integer) : string;
begin
  Str(i,Result);
end;

function StrToInt(s : string) : integer;
var j : integer;
begin
  Val(s,Result,j);
  if j > 0 then Result := 0;
end;

function StrToIntDef(s : string; Default: Integer) : integer;
var j : integer;
begin
  Val(s,Result,j);
  if j > 0 then Result := Default;
end;

function FloatToStr(m:real):string;
begin
 Str(m:4:1, Result);
end;

Function StrToFloat(s:String):real;
var
   code:integer;
begin
  Val(S, Result, Code);
  if code>0 then Result:=0;
end;

{ Date/time support routines }

const
  FMSecsPerDay: Single = MSecsPerDay;
  IMSecsPerDay: Integer = MSecsPerDay;

function DateTimeToTimeStamp(DateTime: TDateTime): TTimeStamp;
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
end;

function TimeStampToDateTime(const TimeStamp: TTimeStamp): TDateTime;
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
end;

function MSecsToTimeStamp(MSecs: Comp): TTimeStamp;
asm
        MOV     ECX,EAX
        MOV     EAX,MSecs.Integer[0]
        MOV     EDX,MSecs.Integer[4]
        DIV     IMSecsPerDay
        MOV     [ECX].TTimeStamp.Time,EDX
        MOV     [ECX].TTimeStamp.Date,EAX
end;

function TimeStampToMSecs(const TimeStamp: TTimeStamp): Comp;
asm
        FILD    [EAX].TTimeStamp.Date
        FMUL    FMSecsPerDay
        FIADD   [EAX].TTimeStamp.Time
end;

{ Time encoding and decoding }

function DoEncodeTime(Hour, Min, Sec, MSec: Word; var Time: TDateTime): Boolean;
begin
  Result := False;
  if (Hour < 24) and (Min < 60) and (Sec < 60) and (MSec < 1000) then
  begin
    Time := (Hour * 3600000 + Min * 60000 + Sec * 1000 + MSec) / MSecsPerDay;
    Result := True;
  end;
end;

procedure ConvertError(s : string);
begin
end;

function EncodeTime(Hour, Min, Sec, MSec: Word): TDateTime;
begin
  if not DoEncodeTime(Hour, Min, Sec, MSec, Result) then
    ConvertError('TimeEncodeError');
end;

procedure DivMod(Dividend: Integer; Divisor: Word;
  var Result, Remainder: Word);
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
end;

procedure DecodeTime(Time: TDateTime; var Hour, Min, Sec, MSec: Word);
var
  MinCount, MSecCount: Word;
begin
  DivMod(DateTimeToTimeStamp(Time).Time, 60000, MinCount, MSecCount);
  DivMod(MinCount, 60, Hour, Min);
  DivMod(MSecCount, 1000, Sec, MSec);
end;

function Trim(const S: string): string;
var
  I, L: Integer;
begin
  L := Length(S);
  I := 1;
  while (I <= L) and (S[I] <= ' ') do Inc(I);
  if I > L then Result := '' else
  begin
    while S[L] <= ' ' do Dec(L);
    Result := Copy(S, I, L - I + 1);
  end;
end;

function TrimLeft(const S: string): string;
var
  I, L: Integer;
begin
  L := Length(S);
  I := 1;
  while (I <= L) and (S[I] <= ' ') do Inc(I);
  Result := Copy(S, I, Maxint);
end;

function TrimRight(const S: string): string;
var
  I: Integer;
begin
  I := Length(S);
  while (I > 0) and (S[I] <= ' ') do Dec(I);
  Result := Copy(S, 1, I);
end;

{ Date encoding and decoding }

function IsLeapYear(Year: Word): Boolean;
begin
  Result := (Year mod 4 = 0) and ((Year mod 100 <> 0) or (Year mod 400 = 0));
end;

type
  PDayTable = ^TDayTable;
  TDayTable = array[1..12] of Word;

{ The MonthDays array can be used to quickly find the number of
  days in a month:  MonthDays[IsLeapYear(Y), M]      }

const
  MonthDays: array [Boolean] of TDayTable =
    ((31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31),
     (31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31));

{ DateToStr converts the date part of the given TDateTime value to a string.
  The conversion uses the format specified by the ShortDateFormat global
  variable. }

function Now: TDateTime;
var
  SystemTime: TSystemTime;
begin
  GetLocalTime(SystemTime);
  with SystemTime do
    Result := EncodeDate(wYear, wMonth, wDay) +
      EncodeTime(wHour, wMinute, wSecond, wMilliseconds);
end;

function DoEncodeDate(Year, Month, Day: Word; var Date: TDateTime): Boolean;
var
  I: Integer;
  DayTable: PDayTable;
begin
  Result := False;
  DayTable := @MonthDays[IsLeapYear(Year)];
  if (Year >= 1) and (Year <= 9999) and (Month >= 1) and (Month <= 12) and
    (Day >= 1) and (Day <= DayTable^[Month]) then
  begin
    for I := 1 to Month - 1 do Inc(Day, DayTable^[I]);
    I := Year - 1;
    Date := I * 365 + I div 4 - I div 100 + I div 400 + Day - DateDelta;
    Result := True;
  end;
end;

function EncodeDate(Year, Month, Day: Word): TDateTime;
begin
  if not DoEncodeDate(Year, Month, Day, Result) then
    ConvertError('SDateEncodeError');
end;

procedure DecodeDate(Date: TDateTime; var Year, Month, Day: Word);
const
  D1 = 365;
  D4 = D1 * 4 + 1;
  D100 = D4 * 25 - 1;
  D400 = D100 * 4 + 1;
var
  Y, M, D, I: Word;
  T: Integer;
  DayTable: PDayTable;
begin
  T := DateTimeToTimeStamp(Date).Date;
  if T <= 0 then
  begin
    Year := 0;
    Month := 0;
    Day := 0;
  end else
  begin
    Dec(T);
    Y := 1;
    while T >= D400 do
    begin
      Dec(T, D400);
      Inc(Y, 400);
    end;
    DivMod(T, D100, I, D);
    if I = 4 then
    begin
      Dec(I);
      Inc(D, D100);
    end;
    Inc(Y, I * 100);
    DivMod(D, D4, I, D);
    Inc(Y, I * 4);
    DivMod(D, D1, I, D);
    if I = 4 then
    begin
      Dec(I);
      Inc(D, D1);
    end;
    Inc(Y, I);
    DayTable := @MonthDays[IsLeapYear(Y)];
    M := 1;
    while True do
    begin
      I := DayTable^[M];
      if D < I then Break;
      Dec(D, I);
      Inc(M);
    end;
    Year := Y;
    Month := M;
    Day := D + 1;
  end;
end;

{ File management routines }

function FileOpen(const FileName: string; Mode: LongWord): Integer;
const
  AccessMode: array[0..2] of LongWord = (
    GENERIC_READ,
    GENERIC_WRITE,
    GENERIC_READ or GENERIC_WRITE);
  ShareMode: array[0..4] of LongWord = (
    0,
    0,
    FILE_SHARE_READ,
    FILE_SHARE_WRITE,
    FILE_SHARE_READ or FILE_SHARE_WRITE);
  OpenMode : array[0..1] of LongWord = (
    OPEN_EXISTING,
    TRUNCATE_EXISTING);
begin
  Result := CreateFile(PChar(FileName),
                       AccessMode[Mode and 3],
                       ShareMode[(Mode and $F0) shr 4],
                       nil,
                       OpenMode[(Mode and 4) shr 2],
                       FILE_ATTRIBUTE_NORMAL,
                       0);
end;

function FileCreate(const FileName: string): Integer;
begin
  Result := CreateFile(PChar(FileName),
                       GENERIC_READ or GENERIC_WRITE,
                       0,
                       nil,
                       CREATE_ALWAYS,
                       FILE_ATTRIBUTE_NORMAL,
                       0);
end;

function FileRead(Handle: Integer; var Buffer; Count: Integer): Integer;
begin
  if not ReadFile(Handle, Buffer, Count, LongWord(Result), nil) then Result := -1;
end;

function FileWrite(Handle: Integer; const Buffer; Count: Integer): Integer;
begin
  if not WriteFile(Handle, Buffer, Count, LongWord(Result), nil) then Result := -1;
end;

function FileSeek(Handle: Integer; const Offset: Int64; Origin: Integer): Int64;
begin
  Result := Offset;
  Int64Rec(Result).Lo := SetFilePointer(THandle(Handle), Int64Rec(Result).Lo,
    @Int64Rec(Result).Hi, Origin);
end;

procedure FileClose(Handle: Integer);
begin
  CloseHandle(THandle(Handle));
end;

function FileGetAttr(const FileName: shortstring): Integer;
var Buf : array[0..255] of char;
begin
  Move(FileName[1],Buf[0],Ord(FileName[0]));
  Buf[Ord(FileName[0])] := #0;
  Result := GetFileAttributes(PChar(@Buf));
end;

function FileSetAttr(const FileName: shortstring; Attr: Integer): Integer;
var Buf : array[0..255] of char;
begin
  Result := 0;
  Move(FileName[1],Buf[0],Ord(FileName[0]));
  Buf[Ord(FileName[0])] := #0;
  if not SetFileAttributes(PChar(@Buf), Attr) then
    Result := GetLastError;
end;

function DeleteFile(const FileName: shortstring): Boolean;
var Buf : array[0..255] of char;
begin
  Move(FileName[1],Buf[0],Ord(FileName[0]));
  Buf[Ord(FileName[0])] := #0;
  Result := Windows.DeleteFile(PChar(@Buf));
end;

function RenameFile(const OldName, NewName: shortstring): Boolean;
var OldBuf,NewBuf : array[0..255] of char;
begin
  Move(OldName[1],OldBuf[0],Ord(OldName[0]));
  OldBuf[Ord(OldName[0])] := #0;
  Move(NewName[1],NewBuf[0],Ord(NewName[0]));
  NewBuf[Ord(NewName[0])] := #0;
  Result := MoveFile(PChar(@OldBuf[0]), PChar(@NewBuf[0]));
end;

function ChangeFileExt(const FileName, Extension: shortstring): shortstring;
var
  I: Integer;
begin
  I := Length(FileName);
  while (I > 1) and not (FileName[I] in ['.', '\', ':']) do Dec(I);
  if (I = 1) or (FileName[I] <> '.') then I := MaxInt;
  Result := Copy(FileName, 1, I - 1);
  if Result[0] > #0 then
    if Result[Ord(Result[0])] = #0 then Dec(Result[0]);
  Result := Result + Extension;
end;

function ExtractFilePath(const FileName: shortstring): shortstring;
var
  I: Integer;
begin
  I := Length(FileName);
  while (I > 1) and not (FileName[I] in ['\', ':']) do Dec(I);
  Result := Copy(FileName, 1, I);
  if Result[0] > #0 then
    if Result[Ord(Result[0])] = #0 then Dec(Result[0]);
end;

function ExtractFileDir(const FileName: shortstring): shortstring;
var
  I: Integer;
begin
  I := Length(FileName);
  while (I > 2) and not (FileName[I] in ['\', ':']) do Dec(I);
  if (I > 2) and (FileName[I] = '\') and
    not (FileName[I - 1] in ['\', ':']) then Dec(I);
  Result := Copy(FileName, 1, I);
  if Result[0] > #0 then
    if Result[Ord(Result[0])] = #0 then Dec(Result[0]);
end;

function ExtractFileDrive(const FileName: shortstring): shortstring;
var
  I, J: Integer;
begin
  if (Length(FileName) >= 3) and (FileName[3] = ':') then
    Result := Copy(FileName, 1, 2)
  else if (Length(FileName) >= 2) and (FileName[2] = '\') and
    (FileName[3] = '\') then
  begin
    J := 1;
    I := 3;
    While (I < Length(FileName)) and (J < 3) do
    begin
      if FileName[I] = '\' then Inc(J);
      if J < 3 then Inc(I);
    end;
    if FileName[I] = '\' then Dec(I);
    Result := Copy(FileName, 1, I);
  end else Result := '';
  if Result[0] > #0 then
    if Result[Ord(Result[0])] = #0 then Dec(Result[0]);
end;

function ExtractFileName(const FileName: shortstring): shortstring;
var
  I: Integer;
begin
  I := Length(FileName);
  while (I >= 1) and not (FileName[I] in ['\', ':']) do Dec(I);
  Result := Copy(FileName, I + 1, 255);
  if Result[0] > #0 then
    if Result[Ord(Result[0])] = #0 then Dec(Result[0]);
end;

function ExtractFileExt(const FileName: shortstring): shortstring;
var
  I: Integer;
begin
  I := Length(FileName);
  while (I > 1) and not (FileName[I] in ['.', '\', ':']) do Dec(I);
  if (I > 1) and (FileName[I] = '.') then
    Result := Copy(FileName, I, 255) else
    Result := '';
  if Result[0] > #0 then
    if Result[Ord(Result[0])] = #0 then Dec(Result[0]);
end;

{ The GetDiskFreeSpace Win32 API does not support partitions larger than 2GB
  under Win95.  A new Win32 function, GetDiskFreeSpaceEx, supports partitions
  larger than 2GB but only exists on Win NT 4.0 and Win95 OSR2.
  The GetDiskFreeSpaceEx function pointer variable below will be initialized
  at startup to point to either the actual OS API function if it exists on
  the system, or to an internal Delphi function if it does not.  When running
  on Win95 pre-OSR2, the output of this function will still be limited to
  the 2GB range reported by Win95, but at least you don't have to worry
  about which API function to call in code you write.  }

var
  GetDiskFreeSpaceEx: function (Directory: PChar; var FreeAvailable,
    TotalSpace: TLargeInteger; TotalFree: PLargeInteger): Bool stdcall = nil;

// This function is used if the OS doesn't support GetDiskFreeSpaceEx
function BackfillGetDiskFreeSpaceEx(Directory: PChar; var FreeAvailable,
    TotalSpace: TLargeInteger; TotalFree: PLargeInteger): Bool; stdcall;
var
  SectorsPerCluster, BytesPerSector, FreeClusters, TotalClusters: LongWord;
  Temp: Int64;
  Dir: PChar;
begin
  if Directory <> nil then
    Dir := Directory
  else
    Dir := nil;
  Result := GetDiskFreeSpaceA(Dir, SectorsPerCluster, BytesPerSector,
    FreeClusters, TotalClusters);
  Temp := SectorsPerCluster * BytesPerSector;
  FreeAvailable := Temp * FreeClusters;
  TotalSpace := Temp * TotalClusters;
end;

// This routine initializes GetDiskFreeSpaceEx pointer according to
// current OS version

procedure InitDriveSpacePtr;
var
  Kernel: THandle;
begin
  Kernel := GetModuleHandle(Windows.Kernel32);
  if Kernel <> 0 then
    @GetDiskFreeSpaceEx := GetProcAddress(Kernel, 'GetDiskFreeSpaceExA');
  if not Assigned(GetDiskFreeSpaceEx) then
    GetDiskFreeSpaceEx := @BackfillGetDiskFreeSpaceEx;
end;

function InternalGetDiskSpace(Drive: Byte;
  var TotalSpace, FreeSpaceAvailable: Int64): Bool;
var
  RootPath: array[0..4] of Char;
  RootPtr: PChar;
begin
  RootPtr := nil;
  if Drive > 0 then
  begin
    RootPath[0] := Char(Drive + $40);
    RootPath[1] := ':';
    RootPath[2] := '\';
    RootPath[3] := #0;
    RootPtr := RootPath;
  end;
  Result := GetDiskFreeSpaceEx(RootPtr, FreeSpaceAvailable, TotalSpace, nil);
end;

function DiskFree(Drive: Byte): Int64;
var
  TotalSpace: Int64;
begin
  if not InternalGetDiskSpace(Drive, TotalSpace, Result) then
    Result := -1;
end;

function DiskSize(Drive: Byte): Int64;
var
  FreeSpace: Int64;
begin
  if not InternalGetDiskSpace(Drive, Result, FreeSpace) then
    Result := -1;
end;

function DiskSN(Drive : Byte) : DWORD;
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
  end;
Var SS1 : shortstring;
    vi  : TVolInfo;
    sn  : DWORD;
begin
  SS1 := '@:\'#0;
  SS1[1] := chr(Ord(SS1[1])+Drive);
  with vi do
  begin
    RPName := @SS1[1];
    VolNameBuf := nil;
    VolNameSize := 0;
    VolSerNum := @sn;
    FileSystemNameBuf := nil;
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
  end;
  Result := sn;
end;

function ExeName : shortstring;
begin
  Result := ParamStr(0);
end;

function ExePath : shortstring;
begin
  Result := ExtractFilePath(ParamStr(0));
end;

function FindMatchingFile(var F: TSearchRec): Integer;
var
  LocalFileTime: TFileTime;
begin
  with F do
  begin
    while FindData.dwFileAttributes and ExcludeAttr <> 0 do
      if not FindNextFile(FindHandle, FindData) then
      begin
        Result := GetLastError;
        Exit;
      end;
    FileTimeToLocalFileTime(FindData.ftLastWriteTime, LocalFileTime);
    FileTimeToDosDateTime(LocalFileTime, LongRec(Time).Hi,
      LongRec(Time).Lo);
    Size := FindData.nFileSizeLow;
    Attr := FindData.dwFileAttributes;
    Name := FindData.cFileName;
  end;
  Result := 0;
end;

function FindFirst(const Path: string; Attr: Integer;
  var F: TSearchRec): Integer;
const
  faSpecial = faHidden or faSysFile or faVolumeID or faDirectory;
begin
  F.ExcludeAttr := not Attr and faSpecial;
  F.FindHandle := FindFirstFile(PChar(Path), F.FindData);
  if F.FindHandle <> INVALID_HANDLE_VALUE then
  begin
    Result := FindMatchingFile(F);
    if Result <> 0 then FindClose(F);
  end else
    Result := GetLastError;
end;

function FindNext(var F: TSearchRec): Integer;
begin
  if FindNextFile(F.FindHandle, F.FindData) then
    Result := FindMatchingFile(F) else
    Result := GetLastError;
end;

procedure FindClose(var F: TSearchRec);
begin
  if F.FindHandle <> INVALID_HANDLE_VALUE then
    Windows.FindClose(F.FindHandle);
end;

{ TStream }

function TStream.GetPosition: Longint;
begin
  Result := Seek(0, 1);
end;

procedure TStream.SetPosition(Pos: Longint);
begin
  Seek(Pos, 0);
end;

function TStream.GetSize: Longint;
var
  Pos: Longint;
begin
  Pos := Seek(0, 1);
  Result := Seek(0, 2);
  Seek(Pos, 0);
end;

procedure TStream.StreamError;
begin
  if Assigned(FOnError) then FOnError(Self,FError);
end;

procedure TStream.ReadBuffer(var Buffer; Count: Longint);
begin
  FError := se_None;
  if (Count = 0) or (Read(Buffer, Count) = Count) then Exit;
  FError := se_Read;
  StreamError;
end;

procedure TStream.WriteBuffer(const Buffer; Count: Longint);
begin
  FError := se_None;
  if (Count = 0) or (Write(Buffer, Count) = Count) then Exit;
  FError := se_Write;
  StreamError;
end;

function TStream.CopyFrom(Source: TStream; Count: Longint): Longint;
const
  MaxBufSize = $F000;
var
  BufSize, N: Integer;
  Buffer: PChar;
begin
  if Count = 0 then
  begin
    Source.Position := 0;
    Count := Source.Size;
  end;
  Result := Count;
  if Count > MaxBufSize then BufSize := MaxBufSize else BufSize := Count;
  GetMem(Buffer, BufSize);
  while Count <> 0 do
  begin
    if Count > BufSize then N := BufSize else N := Count;
    Source.ReadBuffer(Buffer^, N);
    WriteBuffer(Buffer^, N);
    Dec(Count, N);
  end;
  FreeMem(Buffer, BufSize);
end;

{ THandleStream }

constructor THandleStream.Create(AHandle: Integer);
begin
  FHandle := AHandle;
end;

function THandleStream.Read(var Buffer; Count: Longint): Longint;
begin
  Result := FileRead(FHandle, Buffer, Count);
  if Result = -1 then Result := 0;
end;

function THandleStream.Write(const Buffer; Count: Longint): Longint;
begin
  Result := FileWrite(FHandle, Buffer, Count);
  if Result = -1 then Result := 0;
end;

function THandleStream.Seek(Offset: Longint; Origin: Word): Longint;
begin
  Result := FileSeek(FHandle, Offset, Origin);
end;

{ TFileStream }

constructor TFileStream.Create(const FileName: string; Mode: Word);
begin
  FName[0] := chr(Length(FileName));
  Move(FileName[1],FName[1],Length(FileName));
  if Mode = fmCreate then
  begin
    FHandle := FileCreate(FileName);
    if FHandle < 0 then
    begin
      FError := se_Create;
      FErrorInfo := GetLastError;
      StreamError;
    end;
  end else
  begin
    FHandle := FileOpen(FileName, Mode);
    if FHandle < 0 then
    begin
      FError := se_Open;
      FErrorInfo := GetLastError;
      StreamError;
    end;
  end;
end;

destructor TFileStream.Destroy;
begin
  if FHandle >= 0 then FileClose(FHandle);
end;

procedure TFileStream.Flush;
begin
  if FHandle >= 0 then FlushFileBuffers(FHandle);
end;

procedure TFileStream.Truncate;
begin
  if FHandle >= 0 then SetEndOfFile(FHandle);
end;

procedure TFileStream.SetSize(NewSize: Longint);
begin
  Position := NewSize-1;
  Truncate;
end;

{ TCustomMemoryStream }

procedure TCustomMemoryStream.SetPointer(Ptr: Pointer; Size: Longint);
begin
  FMemory := Ptr;
  FSize := Size;
end;

function TCustomMemoryStream.Read(var Buffer; Count: Longint): Longint;
begin
  if (FPosition >= 0) and (Count >= 0) then
  begin
    Result := FSize - FPosition;
    if Result > 0 then
    begin
      if Result > Count then Result := Count;
      Move(Pointer(Longint(FMemory) + FPosition)^, Buffer, Result);
      Inc(FPosition, Result);
      Exit;
    end;
  end;
  Result := 0;
end;

function TCustomMemoryStream.Seek(Offset: Longint; Origin: Word): Longint;
begin
  case Origin of
    soFromBeginning: FPosition := Offset;
    soFromCurrent: Inc(FPosition, Offset);
    soFromEnd: FPosition := FSize + Offset;
  end;
  Result := FPosition;
end;

procedure TCustomMemoryStream.SaveToStream(Stream: TStream);
begin
  if FSize <> 0 then Stream.WriteBuffer(FMemory^, FSize);
end;

procedure TCustomMemoryStream.SaveToFile(const FileName: string);
var
  Stream: TStream;
begin
  Stream := TFileStream.Create(FileName, fmCreate);
  try
    SaveToStream(Stream);
  finally
    Stream.Free;
  end;
end;

{ TMemoryStream }

const
  MemoryDelta = $2000; { Must be a power of 2 }

destructor TMemoryStream.Destroy;
begin
  Clear;
  inherited Destroy;
end;

procedure TMemoryStream.Clear;
begin
  SetCapacity(0);
  FSize := 0;
  FPosition := 0;
end;

procedure TMemoryStream.LoadFromStream(Stream: TStream);
var
  Count: Longint;
begin
  Stream.Position := 0;
  Count := Stream.Size;
  SetSize(Count);
  if Count <> 0 then Stream.ReadBuffer(FMemory^, Count);
end;

procedure TMemoryStream.LoadFromFile(const FileName: string);
var
  Stream: TStream;
begin
  Stream := TFileStream.Create(FileName, fmOpenRead or fmShareDenyWrite);
  try
    LoadFromStream(Stream);
  finally
    Stream.Free;
  end;
end;

procedure TMemoryStream.SetCapacity(NewCapacity: Longint);
begin
  SetPointer(Realloc(NewCapacity), FSize);
  FCapacity := NewCapacity;
end;

procedure TMemoryStream.SetSize(NewSize: Longint);
var
  OldPosition: Longint;
begin
  OldPosition := FPosition;
  SetCapacity(NewSize);
  FSize := NewSize;
  if OldPosition > NewSize then Seek(0, soFromEnd);
end;

function TMemoryStream.Realloc(var NewCapacity: Longint): Pointer;
begin
  if NewCapacity > 0 then
    NewCapacity := (NewCapacity + (MemoryDelta - 1)) and not (MemoryDelta - 1);
  Result := Memory;
  if NewCapacity <> FCapacity then
  begin
    if NewCapacity = 0 then
    begin
      GlobalFreePtr(Memory);
      Result := nil;
    end else
    begin
      if Capacity = 0 then
        Result := GlobalAllocPtr(HeapAllocFlags, NewCapacity)
      else
        Result := GlobalReallocPtr(Memory, NewCapacity, HeapAllocFlags);
      if Result = nil then StreamError;
    end;
  end;
end;

function TMemoryStream.Write(const Buffer; Count: Longint): Longint;
var
  Pos: Longint;
begin
  if (FPosition >= 0) and (Count >= 0) then
  begin
    Pos := FPosition + Count;
    if Pos > 0 then
    begin
      if Pos > FSize then
      begin
        if Pos > FCapacity then
          SetCapacity(Pos);
        FSize := Pos;
      end;
      System.Move(Buffer, Pointer(Longint(FMemory) + FPosition)^, Count);
      FPosition := Pos;
      Result := Count;
      Exit;
    end;
  end;
  Result := 0;
end;

{Version routines}

function GetFileVersion : string;
Var j,w   : Cardinal;
    s,s1  : shortstring;
    buf   : pointer;
    buf2  : pointer;
    q     : DWord;
//    vsinfo: ^VS_FIXEDFILEINFO;
begin
  s := ParamStr(0) + #0;
  j := GetFileVersionInfoSize(@s[1],w);
  if j = 0 then Exit;
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
end;

function GetFullFileVersion : string;
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
begin
  s := ParamStr(0) + #0;
  j := GetFileVersionInfoSize(@s[1],w);
  if j = 0 then Exit;
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
  if (flag and VS_FF_DEBUG) > 0        then s := s + ' debug ';
  if (flag and VS_FF_PRERELEASE) > 0   then s := s + ' prerelease ';
  if (flag and VS_FF_PRIVATEBUILD) > 0 then s := s + ' private ';
  if (flag and VS_FF_SPECIALBUILD) > 0 then s := s + ' special ';
  Result := s;
  GlobalFree(Cardinal(buf));
end;

{browsing for folders and computers routines}

type

{ TSHItemID -- Item ID }

  PSHItemID = ^TSHItemID;
  TSHItemID = packed record           { mkid }
    cb: Word;                         { Size of the ID (including cb itself) }
    abID: array[0..0] of Byte;        { The item ID (variable length) }
  end;

{ TItemIDList -- List if item IDs (combined with 0-terminator) }

  PItemIDList = ^TItemIDList;
  TItemIDList = packed record         { idl }
     mkid: TSHItemID;
   end;

  TFNBFFCallBack = function(Wnd: HWND; uMsg: UINT; lParam, lpData: LPARAM): Integer stdcall;

  PBrowseInfo = ^TBrowseInfo;
  TBrowseInfo = packed record
    hwndOwner: HWND;
    pidlRoot: PItemIDList;
    pszDisplayName: LPSTR;  { Return display name of item selected. }
    lpszTitle: LPCSTR;      { text to go in the banner over the tree. }
    ulFlags: UINT;          { Flags that control the return stuff }
    lpfn: TFNBFFCallBack;
    lParam: LPARAM;         { extra info that's passed back in callbacks }
    iImage: Integer;        { output var: where to return the Image index. }
  end;

const
  shell32 = 'shell32.dll';
  ole32    = 'ole32.dll';

{ Browsing for directory }

  BIF_RETURNONLYFSDIRS   = $0001; { For finding a folder to start document searching }
  BIF_DONTGOBELOWDOMAIN  = $0002; { For starting the Find Computer }
  BIF_STATUSTEXT         = $0004;
  BIF_RETURNFSANCESTORS  = $0008;

  BIF_BROWSEFORCOMPUTER  = $1000; { Browsing for Computers }
  BIF_BROWSEFORPRINTER   = $2000; { Browsing for Printers }
  BIF_BROWSEINCLUDEFILES = $4000; { Browsing for Everything }

{ message from browser }

  BFFM_INITIALIZED       = 1;
  BFFM_SELCHANGED        = 2;

{ messages to browser }

  BFFM_SETSTATUSTEXT      = (WM_USER + 100);
  BFFM_ENABLEOK           = (WM_USER + 101);
  BFFM_SETSELECTION       = (WM_USER + 102);

const
  CSIDL_DRIVES             = $0011;
  CSIDL_NETWORK            = $0012;

function SHBrowseForFolder(var lpbi: TBrowseInfo): PItemIDList; stdcall;
  far; external Shell32 name 'SHBrowseForFolder';
function SHGetPathFromIDList(pidl: PItemIDList; pszPath: LPSTR): BOOL; stdcall;
  far; external Shell32 name 'SHGetPathFromIDList';
function SHGetSpecialFolderLocation(hwndOwner: HWND; nFolder: Integer;
  var ppidl: PItemIDList): HResult; stdcall; far; external Shell32
  name 'SHGetSpecialFolderLocation';
function CoTaskMemAlloc(cb : DWORD) : pointer; stdcall; external ole32
  name 'CoTaskMemAlloc';
procedure CoTaskMemFree(pv: Pointer); stdcall; external ole32
  name 'CoTaskMemFree';

function BrowseForFolder(AParent: HWND;
                         ATitle : string;
                         AKind  : TBrowseFolderKind) : string;
var pi   : PItemIDList;
    bi   : TBrowseInfo;
    pc   : array[0..MAX_PATH] of char;
begin
  strpcopy(@pc[0],ATitle);
  FillChar(bi,SizeOf(bi),0);
  with bi do
  begin
    hwndOwner := AParent;
    case AKind of
      bfDrives : SHGetSpecialFolderLocation(0, CSIDL_DRIVES,pidlRoot);
      bfComputers : SHGetSpecialFolderLocation(0, CSIDL_NETWORK,pidlRoot);
    end;
    pszDisplayName := nil;
    lpszTitle := @pc[0];
    case AKind of
      bfAll,
      bfDrives : ulFlags := BIF_RETURNONLYFSDIRS or BIF_RETURNFSANCESTORS;
      bfComputers : ulFlags := BIF_DONTGOBELOWDOMAIN or BIF_BROWSEFORCOMPUTER;
    end;
    lpfn := nil;
    lParam := 0;
    iImage := 0;
  end;
  pi := SHBrowseForFolder(bi);
  if bi.pidlRoot <> nil then CoTaskMemFree(bi.pidlRoot);
  Result := '';
  if pi <> nil then
  begin
    SHGetPathFromIDList(pi,@pc);
    CoTaskMemFree(pi);
    Result := StrPas(@pc[0]);
  end;
end;

function QuotedStr;
var
  I: Integer;
begin
  Result := S;
  for I := Length(Result) downto 1 do
    if Result[I] = Quote then Insert(Quote, Result, I);
  Result := Quote + Result + Quote;
end;

{ AnsiExtractQuotedStr removes the Quote characters from the beginning and end
  of a quoted string, and reduces pairs of Quote characters within the quoted
  string to a single character. If the first character in Src is not the Quote
  character, the function returns an empty string.  The function copies
  characters from the Src to the result string until the second solitary
  Quote character or the first null character in Src. The Src parameter is
  updated to point to the first character following the quoted string.  If
  the Src string does not contain a matching end Quote character, the Src
  parameter is updated to point to the terminating null character in Src.
  This function supports multibyte character strings (MBCS).  }

function AnsiExtractQuotedStr(var Src: PChar; Quote: Char): string;
var
  P, Dest: PChar;
  DropCount: Integer;
begin
  Result := '';
  if (Src = nil) or (Src^ <> Quote) then Exit;
  Inc(Src);
  DropCount := 1;
  P := Src;
  Src := StrScan(Src, Quote);
  while Src <> nil do   // count adjacent pairs of quote chars
  begin
    Inc(Src);
    if Src^ <> Quote then Break;
    Inc(Src);
    Inc(DropCount);
    Src := StrScan(Src, Quote);
  end;
  if Src = nil then Src := StrEnd(P);
  if ((Src - P) <= 1) then Exit;
  if DropCount = 1 then
    SetString(Result, P, Src - P - 1)
  else
  begin
    SetLength(Result, Src - P - DropCount);
    Dest := PChar(Result);
    Src := StrScan(P, Quote);
    while Src <> nil do
    begin
      Inc(Src);
      if Src^ <> Quote then Break;
      Move(P^, Dest^, Src - P);
      Inc(Dest, Src - P);
      Inc(Src);
      P := Src;
      Src := StrScan(Src, Quote);
    end;
    if Src = nil then Src := StrEnd(P);
    Move(P^, Dest^, Src - P - 1);
  end;
end;

procedure InitPlatformId;
begin
  OSVersionInfo.dwOSVersionInfoSize := SizeOf(OSVersionInfo);
  if GetVersionEx(OSVersionInfo) then
(*    with OSVersionInfo do
    begin
      Win32Platform := dwPlatformId;
      Win32MajorVersion := dwMajorVersion;
      Win32MinorVersion := dwMinorVersion;
      Win32BuildNumber := dwBuildNumber;
      Win32CSDVersion := szCSDVersion;
    end;*)
end;

initialization

  InitDriveSpacePtr;
  InitPlatformId;

end.

