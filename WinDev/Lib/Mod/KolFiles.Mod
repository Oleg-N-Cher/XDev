(*//[START OF KOL.pas]*)
(****************************************************************

        KKKKK    KKKKK    OOOOOOOOO    LLLLL
        KKKKK    KKKKK  OOOOOOOOOOOOO  LLLLL
        KKKKK    KKKKK  OOOOO   OOOOO  LLLLL
        KKKKK  KKKKK    OOOOO   OOOOO  LLLLL
        KKKKKKKKKK      OOOOO   OOOOO  LLLLL
        KKKKK  KKKKK    OOOOO   OOOOO  LLLLL
        KKKKK    KKKKK  OOOOO   OOOOO  LLLLL
        KKKKK    KKKKK  OOOOOOOOOOOOO  LLLLLLLLLLLLL
        KKKKK    KKKKK    OOOOOOOOO    LLLLLLLLLLLLL

  Key Objects Library (C) 2000 by Kladov Vladimir.

//[VERSION]
****************************************************************
* VERSION 2.94++
****************************************************************
//[END OF VERSION]

  K.O.L. - is a set of objects to create small programs
  with the Delphi, but without the VCL. KOL allows to
  create executables of size about 10 times smaller then
  those created with the VCL. But this does not mean that
  KOL is less power then the VCL - perhaps just the opposite...

  KOL is provided free with the source code.
  Copyright (C) Vladimir Kladov, 2000-2003.

  For code provided by other  developers (even if later
  changed by me) authors are noted in the source.

  mailto: bonanzas@online.sinor.ru
  Web-Page: http://bonanzas.rinet.ru

  See also Mirror Classes Kit (M.C.K.) which allows
  to create KOL programs visually.

****************************************************************)

MODULE KolFiles; (* nonportable (Win32) *)
IMPORT S := SYSTEM, W := WinApi, KolTypes, KolStrings;

(*//[OpenFile CONSTANTS]*)
CONST
  ofOpenRead* = BITS((*$IFDEF LIN} O_RDONLY {$ELSE*) 80000000H (*$ENDIF*));
  (* Use this flag (in combination with others) to open file for "read" only. *)
  ofOpenWrite* = BITS((*$IFDEF LIN} O_WRONLY {$ELSE*) 40000000H (*ENDIF*));
  (* Use this flag (in combination with others) to open file for "write" only. *)
  ofOpenReadWrite* = BITS((*$IFDEF LIN} O_RDWR {$ELSE*) 0C0000000H (*ENDIF*));
  (* Use this flag (in combination with others) to open file for "read" and "write". *)

  ofShareExclusive* = BITS((*$IFDEF LIN} $10 {$ELSE*) 00H (*ENDIF*));
  (* Use this flag (in combination with others) to open file for exclusive use. *)
  ofShareDenyWrite* = BITS((*$IFDEF LIN} $20 {$ELSE*) 01H (*ENDIF*));
  (* Use this flag (in combination with others) to open file in share mode, when
     only attempts to open it in other process for "write" will be impossible.
     I.e., other processes could open this file simultaneously for read only
     access. *)
  ofShareDenyRead* = BITS((*$IFDEF LIN} 0 {not supported} {$ELSE*) 02H (*ENDIF*));
  (* Use this flag (in combination with others) to open file in share mode, when
     only attempts to open it for "read" in other processes will be disabled.
     I.e., other processes could open it for "write" only access. *)
  ofShareDenyNone* = BITS((*$IFDEF LIN} $30 {$ELSE*) 03H (*ENDIF*));
  (* Use this flag (in combination with others) to open file in full sharing mode.
     I.e. any process will be able open this file using the same share flag. *)
  ofCreateNew* = BITS((*$IFDEF LIN} O_CREAT or O_TRUNC {$ELSE*) 100H (*ENDIF*));
  (* Default creation disposition. Use this flag for creating new file (usually
     for write access. *)
  ofCreateAlways* = BITS((*$IFDEF LIN} O_CREAT {$ELSE*) 200H (*ENDIF*));
  (* Use this flag (in combination with others) to open existing or creating new
     file. If existing file is opened, it is truncated to size 0. *)
  ofOpenExisting* = BITS((*$IFDEF LIN} 0 {$ELSE*) 300H (*ENDIF*));
  (* Use this flag (in combination with others) to open existing file only. *)
  ofOpenAlways* = BITS((*$IFDEF LIN} O_CREAT {$ELSE*) 400H (*ENDIF*));
  (* Use this flag (in combination with others) to open existing or create new
     (if such file is not yet exists). *)
  ofTruncateExisting* = BITS((*$IFDEF LIN} O_TRUNC {$ELSE*) 500H (*ENDIF*));
  (* Use this flag (in combination with others) to open existing file and truncate
     it to size 0. *)

  ofAttrReadOnly*   = BITS((*$IFDEF LIN} 0 {$ELSE*) 10000H (*ENDIF*));
  (* Use this flag to create Read-Only file (?). *)
  ofAttrHidden*     = BITS((*$IFDEF LIN} 0 {$ELSE*) 20000H (*ENDIF*));
  (* Use this flag to create hidden file. *)
  ofAttrSystem*     = BITS((*$IFDEF LIN} 0 {$ELSE*) 40000H (*ENDIF*));
  (* Use this flag to create system file. *)
  ofAttrTemp*       = BITS((*$IFDEF LIN} 0 {$ELSE*) 1000000H (*ENDIF*));
  (* Use this flag to create temp file. *)
  ofAttrArchive*    = BITS((*$IFDEF LIN} 0 {$ELSE*) 200000H (*ENDIF*));
  (* Use this flag to create archive file. *)
  ofAttrCompressed* = BITS((*$IFDEF LIN} 0 {$ELSE*) 8000000H (*ENDIF*));
  (* Use this flag to create compressed file. Has effect only on NTFS, and
     only if ofAttrCompressed is not specified also. *)
  ofAttrOffline*    = BITS((*$IFDEF LIN} 0 {$ELSE*) 10000000H (*ENDIF*));
  (* Use this flag to create offline file. *)
(*//[END OF OpenFileConstants]*)

  MAX_PATH* = W.MAX_PATH;

  DirDelimiters = ":\/";

TYPE
  DWORD = KolTypes.DWORD;
  Integer = KolTypes.Integer;
  KOLChar = KolTypes.KOLChar;
  KOLString = KolTypes.KOLString;
  THandle = KolTypes.THandle;

VAR
  hInstance-: W.HINSTANCE;  (* Handle of this instance *)

(*
/////////////////////////////////////////////////////////////////////////
//
//
//                          F   I   L   E   S
//
//
/////////////////////////////////////////////////////////////////////////
//[FILES]
{
   This part of the unit modified by Tim Slusher and Vladimir Kladov.
}

{* Set of utility methods to work with files
   and reqistry.
   When programming KOL, which is Windows API-oriented, You should
   avoid alien (for Windows) embedded Pascal files handling, and
   use API-calls which implemented very well. This set of functions
   is intended to make this easier.
   Also TDirList object implementation present here and some registry
   access functions, which allow to make code more elegant.
}

*)
(*//[FUNCTION FileCreate]*)
PROCEDURE FileCreate* (IN fileName: KOLString; openFlags: SET): THandle;
VAR
  attr: SET;
BEGIN
  attr := S.LSH(openFlags, -16) * BITS(1FFFH); (* (openFlags shr 16) and $1FFF*)
  IF attr = {} THEN attr := W.FILE_ATTRIBUTE_NORMAL END;
  RETURN W.CreateFile(S.VAL(W.PtrSTR, S.ADR(fileName)), openFlags * BITS(0F0000000H),
           openFlags * BITS(0FH) (* openFlags and $F *), NIL,
           ORD(S.LSH(openFlags, -8) * BITS(0FH)) (* (openFlags shr 8) and $F *),
           attr, NIL)
END FileCreate;
(*//[END FileCreate]*)
(*
{$IFDEF _D3orHigher}
function WFileCreate(const FileName: WideString; OpenFlags: DWord): THandle;
var Attr: DWORD;
begin
  Attr := (OpenFlags shr 16) and $1FFF;
  if Attr = 0 then Attr := FILE_ATTRIBUTE_NORMAL;
  Result := CreateFileW( PWideChar(FileName), OpenFlags and $F0000000,
                        OpenFlags and $F, nil, (OpenFlags shr 8) and $F,
                        Attr, 0 );
end;
{$ENDIF _D3orHigher}
*)
(*//[FUNCTION FileClose]*)
PROCEDURE FileClose* (handle: THandle): BOOLEAN;
BEGIN
  RETURN W.CloseHandle(handle) # 0
END FileClose;
(*//[END FileClose]*)
(*
{$UNDEF ASM_LOCAL}
{$IFDEF ASM_UNICODE}
  {$DEFINE ASM_LOCAL}
{$ENDIF}
{$IFDEF FILE_EXISTS_EX}
  {$UNDEF ASM_LOCAL}
{$ENDIF}

//[FUNCTION FileExists]
{$IFDEF WIN}
{$IFDEF ASM_LOCAL}
function FileExists( const FileName : KOLString ) : Boolean;
const size_TWin32FindData = sizeof( {$IFDEF UNICODE_CTRLS} TWin32FindDataW {$ELSE} TWin32FindDataA {$ENDIF} );
asm
        CALL     EAX2PChar
        PUSH     EAX
        CALL     GetFileAttributes
        INC      EAX
        JZ       @@exit
        DEC      EAX
        {$IFDEF PARANOIA} DB $24, FILE_ATTRIBUTE_DIRECTORY {$ELSE} AND AL, FILE_ATTRIBUTE_DIRECTORY {$ENDIF}
        SETZ     AL
@@exit:
end;
{$ELSE ASM_VERSION} //Pascal
function FileExists( const FileName : KOLString ) : Boolean;
{$IFDEF FILE_EXISTS_EX}
var FD: TFindFileData;
    //F: DWORD;
    LFT: TFileTime;
    Hi, Lo: Word;
{$ELSE}
var Code: Integer;
{$ENDIF}
begin
  {$IFDEF FILE_EXISTS_EX}
  Result := FALSE;
  if not Find_First( Filename, FD ) then Exit;
  if FD.dwFileAttributes and FILE_ATTRIBUTE_DIRECTORY <> 0 then Exit;
  FileTimeToLocalFileTime( FD.ftLastWriteTime, LFT );
  if FileTimeToDosDateTime( LFT, Hi, Lo ) then Result := TRUE;
  Find_Close( FD );
  {$ELSE}
  Code := GetFileAttributes(PKOLChar(FileName));
  Result := (Code <> -1) and (FILE_ATTRIBUTE_DIRECTORY and Code = 0);
  {$ENDIF}
end;
{$ENDIF ASM_VERSION}
{$ENDIF WIN}
//[END FileExists]

{$IFDEF _D3orHigher}
function WFileExists( const FileName: WideString ) : Boolean;
{$IFDEF notimplemented_FILE_EXISTS_EX}
var FD: TFindFileData;
    //F: DWORD;
    LFT: TFileTime;
    Hi, Lo: Word;
{$ELSE}
var Code: Integer;
{$ENDIF}
begin
  {$IFDEF notimplemented_FILE_EXISTS_EX}
  Result := FALSE;
  if not WFind_First( Filename, FD ) then Exit;
  if FD.dwFileAttributes and FILE_ATTRIBUTE_DIRECTORY <> 0 then Exit;
  FileTimeToLocalFileTime( FD.ftLastWriteTime, LFT );
  if FileTimeToDosDateTime( LFT, Hi, Lo ) then Result := TRUE;
  WFind_Close( FD );
  {$ELSE}
  Code := GetFileAttributesW(PWideChar(FileName));
  Result := (Code <> -1) and (FILE_ATTRIBUTE_DIRECTORY and Code = 0);
  {$ENDIF}
end;
{$ENDIF _D3orHigher}

//[FUNCTION FileSeek]
{$IFDEF WIN}
{$IFDEF ASM_STREAM}
function FileSeek(Handle: THandle; {$IFNDEF STREAM_COMPAT} const {$ENDIF} MoveTo: TStrmMove; MoveMethod: TMoveMethod): TStrmSize;
asm
        MOVZX    ECX, CL
        PUSH     ECX
        PUSH     0
        PUSH     EDX
        PUSH     EAX
        CALL     SetFilePointer
end;
{$ELSE ASM_VERSION} //Pascal
function FileSeek(Handle: THandle; {$IFNDEF STREAM_COMPAT} const {$ENDIF} MoveTo: TStrmMove; MoveMethod: TMoveMethod): TStrmSize;
{$IFDEF STREAM_LARGE64}
var HiPtr: DWORD;
{$ENDIF}
begin
  {$IFDEF STREAM_LARGE64}
  HiPtr := MoveTo shr 32;
  Result := SetFilePointer(Handle, DWORD( MoveTo ), @ HiPtr, Ord( MoveMethod ) );
  if (DWORD( Result ) = $FFFFFFFF {INVALID_SET_FILE_POINTER}) and
     (GetLastError <> NO_ERROR) then
     Result := -1; // Int64(-1)
  if Result >= 0 then
    Result := Result or (HiPtr shl 32);
  {$ELSE}
  Result := SetFilePointer(Handle, MoveTo, nil, Ord( MoveMethod ) );
  {$ENDIF}
end;
{$ENDIF ASM_VERSION}
{$ENDIF WIN}
//[END FileSeek]

//[FUNCTION FileRead]
{$IFDEF WIN}
{$IFDEF ASM_VERSION}
{$ELSE ASM_VERSION} //Pascal
function FileRead(Handle: THandle; var Buffer; Count: DWord): DWord;
begin
     if not ReadFile(Handle, Buffer, Count, Result, nil) then
       Result := 0;
end;
{$ENDIF ASM_VERSION}
{$ENDIF WIN}
//[END FileRead]

//[FUNCTION File2Str]
{$IFDEF ASM_VERSION}
{$ELSE ASM_VERSION} //Pascal
function File2Str(Handle: THandle): AnsiString;
var Pos, Size: DWORD;
begin
  Result := '';
  if Handle = 0 then Exit;
  Pos := FileSeek( Handle, 0, spCurrent );
  Size := GetFileSize( Handle, nil );
  SetString( Result, nil, Size - Pos + 1 );
  FileRead( Handle, Result[ 1 ], Size - Pos );
  Result[ Size - Pos + 1 ] := #0;
end;
{$ENDIF ASM_VERSION}
//[END File2Str]

{$IFNDEF _D2}
function File2WStr(Handle: THandle): WideString;
var Pos, Size: DWORD;
begin
  Result := '';
  if Handle = 0 then Exit;
  Pos := FileSeek( Handle, 0, spCurrent );
  Size := GetFileSize( Handle, nil );
  SetString( Result, nil, (Size - Pos + 1) div Sizeof( WideChar ) + 1 ); // fixed by zhoudi
  FileRead( Handle, Result[ 1 ], Size - Pos );
  Result[ Length(Result) ] := #0; // fixed by zhoudi 
end;
{$ENDIF _D2}

//[FUNCTION FileWrite]
{$IFDEF WIN}
{$IFDEF ASM_VERSION}
{$ELSE ASM_VERSION} //Pascal
function FileWrite(Handle: THandle; const Buffer; Count: DWord): DWord;
begin
     if not WriteFile(Handle, Buffer, Count, Result, nil) then
       Result := 0;
end;
{$ENDIF ASM_VERSION}
{$ENDIF WIN}
//[END FileWrite]

//[FUNCTION FileEOF]
{$IFDEF ASM_VERSION}
{$ELSE ASM_VERSION} //Pascal
function FileEOF( Handle: THandle ) : Boolean;
var Siz, Pos : DWord;
begin
  Siz := GetFileSize( Handle, nil );
  Pos := FileSeek( Handle, 0, spCurrent );
  Result := Pos >= Siz;
end;
{$ENDIF ASM_VERSION}
//[END FileEOF]

//[FUNCTION FileFullPath]
{$IFDEF WIN}
{$IFDEF ASM_noVERSION_UNICODE}
function FileFullPath( const FileName: AnsiString ) : AnsiString;
const
  BkSlash: AnsiString = '\';
  szTShFileInfo = sizeof( TShFileInfo );
asm
        PUSH     EBX
        PUSH     ESI
        MOV      EBX, EDX
        PUSH     EAX

        XCHG     EAX, EDX
        CALL     System.@LStrClr

        POP      EDX
        PUSH     0
        MOV      EAX, ESP
        CALL     System.@LStrAsg
        MOV      ESI, ESP

@@loo:  CMP      dword ptr [ESI], 0
        JZ       @@fin

        MOV      EAX, ESI
        MOV      EDX, [BkSlash]
        PUSH     0
        MOV      ECX, ESP
        CALL     Parse

        CMP      dword ptr [EBX], 0
        JE       @@1
        MOV      EAX, EBX
        MOV      EDX, [BkSlash]
        CALL     System.@LStrCat
        JMP      @@2
@@1:
        POP      EAX
        PUSH     EAX
        CALL     System.@LStrLen
        CMP      EAX, 2
        JNE      @@2
        POP      EAX
        PUSH     EAX
        CMP      byte ptr [EAX+1], ':'
        JNE      @@2

        MOV      EAX, EBX
        POP      EDX
        PUSH     EDX
        CALL     System.@LStrAsg
        JMP      @@3
@@2:
        PUSH     0
        MOV      EAX, ESP
        MOV      EDX, [EBX]
        CALL     System.@LStrAsg
        MOV      EAX, ESP
        MOV      EDX, [ESP+4]
        CALL     System.@LStrCat
        POP      EAX
        PUSH     EAX
        SUB      ESP, szTShFileInfo
        MOV      EDX, ESP
        PUSH     SHGFI_DISPLAYNAME
        PUSH     szTShFileInfo
        PUSH     EDX
        PUSH     0
        PUSH     EAX
        CALL     ShGetFileInfo
        LEA      EDX, [ESP].TShFileInfo.szDisplayName
        CMP      byte ptr [EDX], 0
        JE       @@clr_stk
        LEA      EAX, [ESP+szTShFileInfo+4]
        {$IFDEF _D2009orHigher}
        XOR      ECX, ECX
        {$ENDIF}
        CALL     System.@LStrFromPChar
@@clr_stk:
        ADD      ESP, szTShFileInfo
        CALL     RemoveStr
        POP      EDX
        PUSH     EDX
        MOV      EAX, EBX
        CALL     System.@LStrCat

@@3:    CALL     RemoveStr
        JMP      @@loo

@@fin:  CALL     RemoveStr
        POP      ESI
        POP      EBX
end;
{$ELSE ASM_VERSION} //Pascal
function FileFullPath( const FileName: KOLString ) : KOLString;
var SFI: TShFileInfo;
    Src, S: KOLString;
begin
  Result := '';
  Src := FileName;
  while Src <> '' do
  begin
    S := Parse( Src, '\' );
    if Result <> '' then
      Result := Result + '\';
    if (Result = '') and (Length( S ) = 2) and (S[ 2 ] = ':') then
      Result := S
    else
    begin
      {$IFDEF UNICODE_CTRLS} ShGetFileInfoW {$ELSE} ShGetFileInfoA {$ENDIF}
        ( PKOLChar( Result + S ), 0, SFI, Sizeof( SFI ), SHGFI_DISPLAYNAME );
      if SFI.szDisplayName[ 0 ] <> #0 then
        S := SFI.szDisplayName;
      Result := Result + S;
    end;
  end;
  if ExtractFileExt( Result ) = '' then
  // case when flag 'Hide extensions for registered file types' is set on
  // in the Explorer:
    Result := Result + ExtractFileExt( FileName );
end;
{$ENDIF ASM_VERSION}
{$ENDIF WIN}
//[END FileFullPath]

{$IFDEF WIN}
//[function FileShortPath]
function FileShortPath( const FileName: KOLString ): KOLString;
var Buf: array[ 0..MAX_PATH ] of KOLChar;
begin
  GetShortPathName( PKOLChar( FileName ), Buf, Sizeof( Buf ) );
  Result := Buf;
end;

//[function FileIconSystemIdx]
function FileIconSystemIdx( const Path: KOLString ): Integer;
var SFI: TShFileInfo;
begin
  SFI.iIcon := 0; // Bartov
  {$IFDEF UNICODE_CTRLS} ShGetFileInfoW {$ELSE} ShGetFileInfoA {$ENDIF}
    ( PKOLChar( Path ), 0, SFI, sizeof( SFI ), SHGFI_SMALLICON or SHGFI_SYSICONINDEX );
  Result := SFI.iIcon;
end;

//[function FileIconSysIdxOffline]
function FileIconSysIdxOffline( const Path: KOLString ): Integer;
var SFI: TShFileInfo;
begin
  SFI.iIcon := 0; // Bartov
  {$IFDEF UNICODE_CTRLS} ShGetFileInfoW {$ELSE} ShGetFileInfoA {$ENDIF}
    ( PKOLChar( Path ), FILE_ATTRIBUTE_NORMAL, SFI, sizeof( SFI ),
    SHGFI_SMALLICON or SHGFI_SYSICONINDEX or SHGFI_USEFILEATTRIBUTES );
  Result := SFI.iIcon;
end;
{$ENDIF WIN}

//[procedure LogFileOutput]
procedure LogFileOutput( const filepath, str: KOLString );
var F: THandle;
    Tmp: KOLString;
begin
  F := FileCreate( filepath, ofOpenWrite or ofOpenAlways or ofShareDenyWrite );
  if F = INVALID_HANDLE_VALUE then Exit;
  FileSeek( F, 0, spEnd );
  Tmp := str + {$IFDEF LIN} #10 {$ELSE} #13#10 {$ENDIF};
  FileWrite( F, PKOLChar( Tmp )^, Length( Tmp ) * Sizeof(KOLChar) );
  FileClose( F );
end;

//[function StrLoadFromFile]
function StrLoadFromFile( const Filename: KOLString ): AnsiString;
var F: THandle;
begin
  {$IFDEF WIN}
  if StrEq( Filename, 'CON' ) then
    Result := File2Str(GetStdHandle(STD_INPUT_HANDLE))
  else
  {$ENDIF WIN}
  begin
    Result := '';
    F := FileCreate( Filename, ofOpenRead or ofOpenExisting or ofShareDenyWrite );
    if F = INVALID_HANDLE_VALUE then Exit;
    Result := File2Str( F );
    FileClose( F ); {Dark Knight}
  end;
end;

function Str2File( Filename: PKOLChar; Str: PAnsiChar ): Boolean;
var L: Integer;
begin
  L := StrLen( Str );
  Result := Mem2File( Filename, Str, L ) = L;
end;

function WStr2File( Filename: PKOLChar; Str: PWideChar ): Boolean;
var L: Integer;
begin
  L := WStrLen( Str );
  Result := Mem2File( Filename, Str, L * Sizeof(WideChar) ) = L;
end;

//[function StrSaveToFile]
function StrSaveToFile( const Filename: KOLString; const Str: AnsiString ): Boolean;
begin
  Result := Mem2File( PKOLChar( Filename ), PAnsiChar( Str ), Length( Str ) )
            = Length( Str );
end;

{$IFNDEF _D2}
function WStrLoadFromFile( const Filename: KOLString ): WideString;
var F: THandle;
begin
  {$IFDEF WIN}
  if StrEq( Filename, 'CON' ) then
    Result := File2WStr(GetStdHandle(STD_INPUT_HANDLE))
  else
  {$ENDIF WIN}
  begin
    Result := '';
    F := FileCreate( Filename, ofOpenRead or ofOpenExisting or ofShareDenyWrite );
    if F = INVALID_HANDLE_VALUE then Exit;
    Result := File2WStr( F );
    FileClose( F ); {Dark Knight}
  end;
end;

function WStrSaveToFile( const Filename: KOLString; const Str: WideString ): Boolean;
var BytesToSave: Integer;
begin
  BytesToSave := Length( Str ) * Sizeof(WideChar);
  Result := Mem2File( PKOLChar( Filename ), PWideChar( Str ), BytesToSave )
            = BytesToSave; // fixed by zhoudi 
end;
{$ENDIF _D2}


//[function Mem2File]
function Mem2File( Filename: PKOLChar; Mem: Pointer; Len: Integer ): Integer;
var F: THandle;
begin
  Result := 0;
  F := FileCreate( Filename, ofOpenWrite or ofCreateAlways );
  if F = INVALID_HANDLE_VALUE then Exit;
  Result := FileWrite( F, Mem^, Len );
  FileClose( F );
end;

//[function File2Mem]
function File2Mem( Filename: PKOLChar; Mem: Pointer; MaxLen: Integer ): Integer;
var F: THandle;
begin
  Result := 0;
  F := FileCreate( Filename, ofOpenRead or ofOpenExisting or ofShareDenyWrite );
  if F = INVALID_HANDLE_VALUE then Exit;
  Result := FileRead( F, Mem^, MaxLen );
  FileClose( F );
end;

{$IFDEF WIN}
function Find_First( const FilePathName: KOLString; var F: TFindFileData ): Boolean;
begin
  F.FindHandle := FindFirstFile( PKOLChar( FilePathName ),
    {$IFDEF UNICODE_CTRLS} PWin32FindDataW {$ELSE} PWin32FindData {$ENDIF}
    ( @ F )^ );
  Result := F.FindHandle <> INVALID_HANDLE_VALUE;
end;
function Find_Next( var F: TFindFileData ): Boolean;
begin
  Result := FindNextFile( F.FindHandle,
      {$IFDEF UNICODE_CTRLS} PWin32FindDataW {$ELSE} PWin32FindData {$ENDIF}
      ( @ F )^ );
end;
procedure Find_Close( var F: TFindFileData );
begin
  Windows.FindClose( F.FindHandle );
end;
{$ENDIF WIN}

//[FUNCTION FileSize]
{$IFDEF WIN}
function FileSize( const Path: KOLString ) : {$IFDEF _D2orD3} Integer {$ELSE} Int64 {$ENDIF};
var FD : TFindFileData;
begin
  Result := 0;
  if not Find_First( Path, FD ) then exit;
  {$IFDEF _D2orD3}
  Result := FD.nFileSizeLow;
  {$ELSE}
  I64( Result ).Lo := FD.nFileSizeLow;
  I64( Result ).Hi := FD.nFileSizeHigh;
  {$ENDIF}
  Find_Close( FD );
end;
{$ENDIF WIN}
//[END FileSize]

//[procedure FileTime]
procedure FileTime( const Path: KOLString;
  CreateTime, LastAccessTime, LastModifyTime: PFileTime );
var FD : TFindFileData;
begin
  if not Find_First( Path, FD ) then exit;
  if CreateTime <> nil then
    CreateTime^ := FD.ftCreationTime;
  if LastAccessTime <> nil then
    LastAccessTime^ := FD.ftLastAccessTime;
  if LastModifyTime <> nil then
    LastModifyTime^ := FD.ftLastWriteTime;
  Find_Close( FD );
end;

//[function GetUniqueFilename]
function GetUniqueFilename( PathName: KOLString ) : KOLString;
var Path, Nam, Ext : KOLString;
    I, J, K : Integer;
begin
  Result := PathName;
  Path := ExtractFilePath( PathName );
  if not DirectoryExists( Path ) then Exit;
  Nam := ExtractFileNameWOext( PathName );
  if Nam = '' then
  begin
    Path := ExcludeTrailingPathDelimiter( Path );
    PathName := Path;
    Result := Path;
  end;
  Nam := ExtractFileNameWOext( PathName );
  Ext := ExtractFileExt( PathName );
  I := Length( Nam );
  for J := I downto 1 do
  if not ((Nam[ J ] >= '0') and (Nam[ J ] <= '9')) then
  begin
    I := J;
    break;
  end;
  K := Str2Int( CopyEnd( Nam, I + 1 ) );
  while FileExists( Result ) do
  begin
    Inc( K );
    Result := Path + Copy( Nam, 1, I ) + Int2Str( K ) + Ext;
  end;
end;

{$IFDEF WIN}
//[FUNCTION CompareSystemTime]
{$IFDEF ASM_VERSION}
{$ELSE ASM_VERSION} //Pascal
function CompareSystemTime(const D1, D2 : TSystemTime) : Integer;
var R: Integer;
   procedure CompareFields(const F1, F2 : Integer);
   begin
      if R <> 0 then Exit;
      if F1 = F2 then Exit;
      if F1 < F2 then
         R := -1
      else
         R := 1;
   end;
begin
   R := 0;
   CompareFields( D1.wYear, D2.wYear );
   CompareFields( D1.wMonth, D2.wMonth );
   CompareFields( D1.wDay, D2.wDay );
   CompareFields( D1.wHour, D2.wHour );
   CompareFields( D1.wMinute, D2.wMinute );
   CompareFields( D1.wSecond, D2.wSecond );
   CompareFields( D1.wMilliseconds, D2.wMilliseconds );
   Result := R;
end;
{$ENDIF ASM_VERSION}
//[END CompareSystemTime]

//[function FileTimeCompare]
function FileTimeCompare( const FT1, FT2 : TFileTime ) : Integer;
var ST1, ST2 : TSystemTime;
begin
  FileTimeToSystemTime( FT1, ST1 );
  FileTimeToSystemTime( FT2, ST2 );
  Result := CompareSystemTime( ST1, ST2 );
end;
{$ENDIF WIN}

{$IFDEF WIN}
//[FUNCTION DirectoryExists]
{$IFDEF ASM_VERSION}
{$ELSE ASM_VERSION} //Pascal
function DirectoryExists(const Name: KOLString): Boolean;
var
  Code: Integer;
  e: DWORD;
begin
  e := SetErrorMode( SEM_NOOPENFILEERRORBOX or SEM_FAILCRITICALERRORS );
  Code := GetFileAttributes(PKOLChar(Name));
  Result := (Code <> -1) and (FILE_ATTRIBUTE_DIRECTORY and Code <> 0);
  SetErrorMode( e );
end;
{$ENDIF ASM_VERSION}
//[END DirectoryExists]

function DiskPresent( const DrivePath: KOLString ): Boolean;
var e: DWORD;
    restore: Boolean;
begin
  e := 0;
  Restore := FALSE;
  if (Copy( DrivePath, 1, 2 ) = '\\') then
  else
  CASE GetDriveType( PKOLChar( DrivePath ) ) OF
  DRIVE_REMOVABLE, DRIVE_CDROM, DRIVE_RAMDISK:
    begin
      e := SetErrorMode( SEM_NOOPENFILEERRORBOX or SEM_FAILCRITICALERRORS );
      Restore := TRUE;
    end;
  END;
  Result := DirectoryExists( DrivePath );
  if Restore then
    SetErrorMode( e );
end;

{$IFDEF _D3orHigher}
function WDirectoryExists(const Name: WideString): Boolean;
var
  Code: Integer;
begin
  Code := GetFileAttributesW(PWideChar(Name));
  Result := (Code <> -1) and (FILE_ATTRIBUTE_DIRECTORY and Code <> 0);
end;
{$ENDIF _D3orHigher}

{$ENDIF WIN}

//[function CheckDirectoryContent]
function CheckDirectoryContent( const Name: KOLString; SubDirsOnly: Boolean; const Mask: AnsiString ): Boolean;
var FD: TFindFileData;
begin
  if not DirectoryExists( Name ) then
    Result := TRUE
  else
  begin
    if not Find_First( IncludeTrailingPathDelimiter( Name ) + Mask, FD ) then
      Result := TRUE
    else
    begin
      Result := TRUE;
      repeat
        if not {$IFDEF UNICODE_CTRLS}WStrIn{$ELSE}StrIn{$ENDIF}( FD.cFileName, ['.','..'] ) then
        begin
          if SubDirsOnly and LongBool(FD.dwFileAttributes and FILE_ATTRIBUTE_DIRECTORY)
             or not SubDirsOnly then
          begin
            Result := FALSE;
            break;
          end;
        end;
      until not Find_Next( FD );
      Find_Close( FD );
    end;
  end;
end;

//[function DirectoryEmpty]
function DirectoryEmpty(const Name: KOLString): Boolean;
begin
  Result := CheckDirectoryContent( Name, FALSE, '*.*' );
end;

//[function DirectoryHasSubdirs]
function DirectoryHasSubdirs( const Path: KOLString ): Boolean;
begin
  Result := not CheckDirectoryContent( Path, TRUE, '*.*' );
end;
*)
(*//[FUNCTION GetStartDir]*)
(*$IFDEF ASM_UNICODE}
function GetStartDir : AnsiString;
asm
        PUSH     EBX
        MOV      EBX, EAX

        XOR      EAX, EAX
        MOV      AH, 2
        SUB      ESP, EAX
        MOV      EDX, ESP
        PUSH     EAX
        PUSH     EDX
        PUSH     0
        CALL     GetModuleFileName // in KOL_ANSI

        LEA      EDX, [ESP + EAX]
@@1:    DEC      EDX
        CMP      byte ptr [EDX], '\'
        JNZ      @@1

        INC      EDX
        MOV      byte ptr [EDX], 0

        MOV      EAX, EBX
        MOV      EDX, ESP
        {$IFDEF _D2009orHigher}
        XOR      ECX, ECX
        {$ENDIF}
        CALL     System.@LStrFromPChar // AnsiSafe!

        ADD      ESP, 200h
        POP      EBX
end;
{$ELSE ASM_VERSION} //Pascal
  {$IFDEF WIN}
    {$UNDEF LINUX_USE_HOME_STARTFDIR}
  {$ENDIF}

PROCEDURE GetStartDir* (): POINTER TO KOLString;
(*-$IFNDEF LINUX_USE_HOME_STARTFDIR*)
VAR
  buffer: POINTER TO ARRAY OF KOLChar;
  i: Integer;
(*-$ENDIF*)
BEGIN
  (*-$IFDEF LINUX_USE_HOME_STARTFDIR)
    Result := getenv( 'HOME' );
  ($ELSE*)
    NEW(buffer, MAX_PATH + 1);
    i := W.GetModuleFileNameW( 0, buffer^, MAX_PATH );
    FOR i := i TO 0 BY -1 DO
      IF buffer[ i ] = (*-$IFDEF LIN} '/' {$ELSE*) '\' (*-$ENDIF*) THEN
        buffer[ i + 1 ] := 0X;
        RETURN buffer
      END
    END;
    RETURN buffer;
  (*-$ENDIF*)
END GetStartDir;*)
(*-$ENDIF ASM_VERSION*)
(*//[END GetStartDir]*)

(*//[FUNCTION ExePath]
PROCEDURE ExePath* (): POINTER TO KOLString;
VAR
  buf: POINTER TO ARRAY OF KOLChar;
BEGIN
  NEW(buf, MAX_PATH + 2);
  buf[ MAX_PATH+1 ] := 0X;
  S.PUTREG(0,
  W.GetModuleFileNameW(0, buf^, MAX_PATH + 1));
  RETURN buf
END ExePath;*)

(*//[FUNCTION ExePathNoGC]
PROCEDURE ExePathNoGC* (VAR path: KOLString);
VAR
  buf: ARRAY MAX_PATH + 2 OF KOLChar;
BEGIN
  buf[ MAX_PATH+1 ] := 0X;
  S.PUTREG(0,
  W.GetModuleFileNameW(0, S.VAL(W.PtrWSTR, S.ADR(buf)), MAX_PATH + 1));
  path := buf$;
END ExePathNoGC;

PROCEDURE ModulePath* (): POINTER TO KOLString;
VAR
  buf: POINTER TO ARRAY OF KOLChar;
BEGIN
  NEW(buf, MAX_PATH + 2);
  buf[ MAX_PATH+1 ] := 0X;
  S.PUTREG(0,
  W.GetModuleFileNameW(hInstance, buf^, MAX_PATH + 1));
  RETURN buf
END ModulePath;

PROCEDURE ModulePathNoGC* (OUT path: KOLString);
BEGIN
  S.PUTREG(0,
  W.GetModuleFileNameW(hInstance, S.VAL(W.PtrWSTR, S.ADR(path)), LEN(path)));
END ModulePathNoGC;*)

(*
{-}
//[function DirectorySize]
function DirectorySize( const Path: KOLString ): I64;
var DirList: PDirList;
    I: Integer;
begin
  Result := MakeInt64( 0, 0 );
  DirList := NewDirList( Path, {$IFDEF LIN} '*' {$ELSE} '*.*' {$ENDIF}, 0 );
  for I := 0 to DirList.Count-1 do
  begin
    if LongBool( DirList.Items[ I ].dwFileAttributes and FILE_ATTRIBUTE_DIRECTORY ) then
      Result := Add64( Result, DirectorySize( DirList.Path + DirList.Names[ I ] ) )
    else
      Result := Add64( Result, MakeInt64( DirList.Items[ I ].nFileSizeLow,
             DirList.Items[ I ].nFileSizeHigh ) );
  end;
  DirList.Free;
end;
{+}

{$IFDEF WIN} //vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//[function GetFileList]
function GetFileList(const dir: Ansistring): PStrList;
var
   Srch: TFindFileData;
   succ: Boolean;
begin
   result := nil;
   succ := Find_First(dir, Srch);
   while succ do begin
      if (not (Srch.dwFileAttributes and FILE_ATTRIBUTE_DIRECTORY > 0))then begin
         if Result = nil then begin
            Result := NewStrList;
         end;
         Result.Add(AnsiString(Srch.cFileName)); // TODO: because AStrList
      end;
      succ := Find_Next(Srch);
   end;
   Find_Close(Srch);
end;

{$ENDIF WIN}
(*//[function ExcludeTrailingChar]*)
PROCEDURE ExcludeTrailingChar*
  (IN S: KOLString; C: KOLChar): POINTER TO KOLString;
BEGIN
  Result := S;
  if Result <> '' then
  if Result[ Length( Result ) ] = C then
    Delete( Result, Length( Result ), 1 );
END ExcludeTrailingChar;

//[function IncludeTrailingChar]
{$IFDEF ASM_UNICODE}
function IncludeTrailingChar( const S: KOLString; C: KOLChar ): KOLString;
asm
  push edx
  push ecx
  xchg ecx, eax
  xchg edx, ecx
  call System.@LStrAsg
  pop  eax
  pop  edx
  mov  ecx, [eax]
  jecxz @@1
  add  ecx, [ecx-4]
  dec  ecx
  cmp  byte ptr [ecx], dl
  jz   @@exit
@@1:
  push eax
  push 0
  mov  eax, esp
  {$IFDEF _D2009orHigher}
  //push ecx
  xor ecx, ecx
  {$ENDIF}
  call System.@LStrFromChar
  {$IFDEF _D2009orHigher}
  //pop  ecx
  {$ENDIF}
  mov  edx, [esp]
  mov  eax, [esp+4]
  call System.@LStrCat 
  call RemoveStr
  pop  eax
@@exit:
end;
{$ELSE PASCAL}
function IncludeTrailingChar( const S: KOLString; C: KOLChar ): KOLString;
begin
  Result := S;
  if (Result = '') or (Result[ Length( Result ) ] <> C) then
    Result := Result + C;
end;
{$ENDIF ASM_VERSION}


//---------------------------------------------------------
// Following functions/procedures are created by Edward Aretino:
// IncludeTrailingPathDelimiter, ExcludeTrailingPathDelimiter,
// ForceDirectories, CreateDir, ChangeFileExt
//---------------------------------------------------------
//[function IncludeTrailingPathDelimiter]
function IncludeTrailingPathDelimiter(const S: KOLString): KOLString;
begin
   Result := IncludeTrailingChar( S, {$IFDEF UNIX} '/' {$ELSE} '\' {$ENDIF} );
end;

//[function ExcludeTrailingPathDelimiter]
function ExcludeTrailingPathDelimiter(const S: KOLString): KOLString;
begin
   Result := ExcludeTrailingChar( S, {$IFDEF UNIX} '/' {$ELSE} '\' {$ENDIF} );
end;

function ExtractFileDrive( const Path: KOLString ) : KOLString;
var i, j: Integer;
begin
  Result := Path;
  if Result = '' then Exit;
  if pos( KOLString(':'), Result ) > 1 then
    Result := Parse( Result, ':' ) + ':\'
  else
  if Length( Result ) > 2 then
  begin
    j := 0;
    for i := 3 to Length( Result ) do
      if Result[ i ] = '\' then
      begin
        inc( j );
        if j = 2 then
        begin
          Result := Copy( Result, 1, i );
          break;
        end;
      end;
    Result := IncludeTrailingPathDelimiter( Result );
  end
    else
  if Length( Result ) = 1 then
    Result := Result + ':\';
end;
*)

PROCEDURE ExtractFilePath* (IN path: KOLString; VAR res: KOLString): BOOLEAN;
VAR
  p: INTEGER;
BEGIN
  p := KolStrings.DelimiterLast(path, DirDelimiters);
  IF path[p] # 0X THEN RETURN KolStrings.SubStr(path, 0, p+1, res) END;
  res[0] := 0X; RETURN TRUE
END ExtractFilePath;
(*
{$IFDEF _D3orHigher}
function WExtractFilePath( const Path: WideString ) : WideString;
var P, P0: PWideChar;
begin
  P0 := PWideChar( Path );
  P := W__DelimiterLast( P0, ':\/' );
  if P^ = #0 then
    Result := ''
  else
    Result := Copy( Path, 1, P - P0 + 1 );
end;
{$ENDIF}

{$IFDEF ASM_VERSION}
{$IFNDEF _D2}
{$DEFINE ASM_LStrFromPCharLen}
{$ENDIF}
{$ENDIF ASM_VERSION}

function IsNetworkPath( const Path: KOLString ): Boolean;
begin
  Result := (Length( Path ) >= 2) and (Path[1] = '\') and (Path[2] = '\');
end;*)

PROCEDURE ExtractFileName* (IN path: KOLString; VAR name: KOLString): BOOLEAN;
VAR
  p: INTEGER;
BEGIN
  p := KolStrings.DelimiterLast(path, DirDelimiters);
  IF path[p] # 0X THEN
    RETURN KolStrings.SubStr(path, p+1, SHORT(LEN(path)), name)
  END;
  RETURN KolStrings.SubStr(path, 0, p, name)
END ExtractFileName;

(*//[function ExtractFileNameWOext]
{$IFDEF ASM_UNICODE}
function ExtractFileNameWOext( const Path : KOLString ) : KOLString;
asm
  push ebx

  push edx
  push eax
  call ExtractFileName
  pop  edx // Path - не нужен больше
  mov  eax, [esp] // eax = Result = ExtractFileName(Path)
  mov  eax, [eax]
  push 0
  mov  edx, esp
  call ExtractFileExt
  mov  eax, [esp]
  call System.@LStrLen
  xchg ebx, eax   // ebx = Length(ExtractFileExt(Result))
  call RemoveStr  // ExtractFileExt - больше не нужен
  mov  eax, [esp]
  mov  eax, [eax]
  call System.@LStrLen // eax = Length(Result)
  sub  eax, ebx
  xchg ecx, eax
  xor  edx, edx
  inc  edx
  mov  eax, [esp]
  mov  eax, [eax]
  call System.@LStrCopy

  pop  ebx
end;
{$ELSE PASCAL}
function ExtractFileNameWOext( const Path : KOLString ) : KOLString;
begin
  Result := ExtractFileName( Path );
  Result := Copy( Result, 1, Length( Result ) - Length( ExtractFileExt( Result ) ) );
end;
{$ENDIF ASM_VERSION}

{$IFDEF ASM_UNICODE}
const
  ExtDelimeters: PAnsiChar = '.';

//[function ExtractFileExt]
function ExtractFileExt( const Path : KOLString ) : KOLString;
asm
        PUSH     EDX
        MOV      EDX, [ExtDelimeters]
        CALL     EAX2PChar
        CALL     __DelimiterLast
@@1:    XCHG     EDX, EAX
        POP      EAX
        {$IFDEF _D2009orHigher}
        PUSH     ECX
        XOR      ECX, ECX
        {$ENDIF}
        CALL     System.@LStrFromPChar
        {$IFDEF _D2009orHigher}
        POP      ECX // this routine hasn't touch ECX
        {$ENDIF}
end;
{$ELSE ASM_VERSION} //Pascal
function ExtractFileExt( const Path : KOLString ) : KOLString;
var P: PKOLChar;
begin
  P := __DelimiterLast( PKOLChar( Path ), '.' );
  Result := P;
end;
{$ENDIF ASM_VERSION}
//[END ExtractFilePath]

//[function ReplaceExt]
{$IFDEF ASM_UNICODE}
function ReplaceExt( const Path, NewExt: KOLString ): KOLString;
asm
  push ecx // result
  push edx // NewExt
  push eax // Path

  push 0
  mov  edx, esp
  call ExtractFilePath
  pop  eax
  xchg [esp], eax // eax=Path, Path in stack replaced with ExtractFilePath(Path)

  push 0
  mov  edx, esp
  call ExtractFileNameWOext
  // now stack conatins: result,NewExt,ExtractFilePath(Path),ExtractFileNameWOext(Path)<-ESP

  mov  eax, [esp+12]
  mov  edx, esp
  push dword ptr [edx+4] // ExtractFilePath(Path)
  push dword ptr [edx]   // ExtractFileNameWOext(Path)
  push dword ptr [edx+8] // NewExt
  mov  edx,  3
  call System.@LStrCatN
  call RemoveStr
  call RemoveStr
  pop  ecx
  pop  ecx
end;
{$ELSE PASCAL}
function ReplaceExt( const Path, NewExt: KOLString ): KOLString;
begin
  Result := ExtractFilePath( Path ) + ExtractFileNameWOext( Path ) +
    NewExt;
end;
{$ENDIF}

//[function ForceDirectories]
function ForceDirectories(Dir: KOLString): Boolean;
begin
 Result := Length(Dir) > 0; {Centronix}
 If not Result then Exit;
 Dir := ExcludeTrailingPathDelimiter(Dir);
 If (Length(Dir) < 3) or DirectoryExists(Dir) or
   (ExtractFilePath(Dir) = Dir) then Exit; // avoid 'xyz:\' problem.
 Result := ForceDirectories(ExtractFilePath(Dir)) and CreateDir(Dir);
end;

//[function CreateDir]
function CreateDir(const Dir: KOLString): Boolean;
begin
   Result := {$IFDEF WIN} {Windows.}CreateDirectory(PKOLChar(Dir), nil)
             {$ELSE LIN} Libc.__mkdir(PAnsiChar(Dir), S_IRWXU or S_IRWXG or S_IRWXO) = 0
             {$ENDIF};
end;

//[function ChangeFileExt]
function ChangeFileExt(FileName: KOLString; const Extension: KOLString): KOLString;
var
   FileExt: KOLString;
begin
   FileExt := ExtractFileExt(FileName);
   DeleteTail(FileName, Length(FileExt));
   Result := FileName+ Extension;
end;

//[function ReplaceFileExt]
function ReplaceFileExt( const Path, NewExt: KOLString ): KOLString;
begin
  Result := ExtractFilePath( Path ) +
            ExtractFileNameWOext( ExtractFileName( Path ) ) +
            NewExt;
end;

{$IFDEF WIN} //vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//[function ExtractShortPathName]
function ExtractShortPathName( const Path: KOLString ): KOLString;
var
  Buffer: array[0..MAX_PATH - 1] of KOLChar;
begin
  SetString(Result, Buffer,
    GetShortPathName(PKOLChar(Path), Buffer, SizeOf(Buffer) div Sizeof(KOLChar)));
end;

{$IFDEF GDI}
//[function FilePathShortened]
function FilePathShortened( const Path: KOLString; MaxLen: Integer ): KOLString;
begin
  Result := FilePathShortenPixels( Path, 0, MaxLen );
end;

//[function PixelsLength]
function PixelsLength( DC: HDC; const Text: KOLString ): Integer;
var Sz: TSize;
begin
  if DC = 0 then
    Result := Length( Text )
  else
  begin
    {$IFDEF UNICODE_CTRLS}Windows.GetTextExtentPoint32W
    {$ELSE}               Windows.GetTextExtentPoint32A
    {$ENDIF}( DC, PKOLChar( Text ), Length( Text ), Sz );
    Result := Sz.cx;
  end;
end;

//[function FilePathShortenPixels]
function FilePathShortenPixels( const Path: KOLString; DC: HDC; MaxPixels: Integer ): KOLString;
var L0, L1: Integer;
    Prev: KOLString;
begin
 Result := Path;
 L0 := PixelsLength( DC, Result );
 while L0 > MaxPixels do
 begin
   Prev := Result;
   L1 := pos( KOLString('\...\'), Result ); // ambiguous
   if L1 <= 0 then
     Result := ExcludeTrailingPathDelimiter( ExtractFilePath( Result ) )
   else
     Result := Copy( Result, 1, L1 - 1 );
   if Result <> '' then
     Result := IncludeTrailingPathDelimiter( ExtractFilePath( Result ) ) + '...\' + ExtractFileName( Path );
   if (Result = '') or (Result = Prev) then
   begin
     L1 := Length( ExtractFilePath( Result ) );
     while (PixelsLength( DC, Result ) > MaxPixels) and (L1 > 1) do
     begin
       Dec( L1 );
       Result := Copy( Result, 1, L1 ) + '...\' + ExtractFileName( Result );
     end;
     if PixelsLength( DC, Result ) > MaxPixels then
     begin
       L1 := MaxPixels + 1;
       while ((MaxPixels > 0) and (L1 > 1) or (MaxPixels = 0) and (L1 > 0)) and
             (PixelsLength( DC, Result ) > MaxPixels) do
       begin
         Dec( L1 );
         Result := Copy( ExtractFileName( Path ), 1, L1 ) + '...';
       end;
     end;
     break;
   end;
   L0 := PixelsLength( DC, Result );
 end;
end;
{$ENDIF GDI}

//[procedure CutFirstDirectory]
procedure CutFirstDirectory(var S: KOLString);
var
  Root: Boolean;
  P: Integer;
begin
  if S = '\' then
    S := ''
  else
  begin
    if S[1] = '\' then
    begin
      Root := True;
      Delete(S, 1, 1);
    end
    else
      Root := False;
    if S[1] = '.' then
      Delete(S, 1, 4);
    P := Pos( KOLString('\'), S ); 
    if P <> 0 then
    begin
      Delete(S, 1, P);
      S := '...\' + S;
    end
    else
      S := '';
    if Root then
      S := '\' + S;
  end;
end;

{$IFDEF GDI}
//[function MinimizeName]
function MinimizeName( const Path: KOLString; DC: HDC; MaxPixels: Integer ): KOLString;
var
  Drive, Dir, Name: KOLString;
begin
  Result := Path;
  Dir := ExtractFilePath(Result);
  Name := ExtractFileName(Result);

  if (Length(Dir) >= 2) and (Dir[2] = ':') then
  begin
    Drive := Copy(Dir, 1, 2);
    Delete(Dir, 1, 2);
  end
  else
    Drive := '';
  while ((Dir <> '') or (Drive <> '')) and (PixelsLength(DC, Result) > MaxPixels) do
  begin
    if Dir = '\...\' then
    begin
      Drive := '';
      Dir := '...\';
    end
    else if Dir = '' then
      Drive := ''
    else
      CutFirstDirectory(Dir);
    Result := Drive + Dir + Name;
  end;
end;
{$ENDIF GDI}
*)
(*//[function GetSystemDir]*)(*
PROCEDURE GetSystemDir* (): POINTER TO KOLString;
VAR
  buf: POINTER TO ARRAY OF KOLChar;
BEGIN
  NEW(buf, MAX_PATH + 1);
  W.GetSystemDirectoryW( buf[ 0 ]^, MAX_PATH + 1);
  RETURN IncludeTrailingPathDelimiter( PKOLChar( @ Buf[ 0 ] ) );
END GetSystemDir;

//*
//[function GetWindowsDir]
PROCEDURE GetWindowsDir* (): POINTER TO KOLString;
VAR
  Buf : array[ 0..MAX_PATH ] of KOLChar;
BEGIN
  GetWindowsDirectory( @Buf[ 0 ], MAX_PATH + 1 );
  Result := IncludeTrailingPathDelimiter( PKOLChar( @ Buf[ 0 ] ) );
END GetWindowsDir;
{$ENDIF WIN} //^^^^^^^^^^^

//[function GetWorkDir]
{$IFDEF WIN}
function GetWorkDir : KOLString;
var Buf: array[ 0..MAX_PATH ] of KOLChar;
begin
  GetCurrentDirectory( MAX_PATH + 1, @ Buf[ 0 ] );
  Result := IncludeTrailingPathDelimiter( PKOLChar( @ Buf[ 0 ] ) );
end;
{$ENDIF WIN}

//[function GetTempDir]
{$IFDEF ASM_UNICODE}
function GetTempDir : KOLString; 
asm
  push eax
  sub esp, 264
  push esp
  push 261
  call GetTempPath
  mov  edx, esp
  mov  eax, [esp+264]
  {$IFDEF _D2009orHigher}
  xor  ecx, ecx 
  {$ENDIF}
  call System.@LStrFromPChar
  add esp, 264
  pop edx
  mov eax, [edx]
  call IncludeTrailingPathDelimiter
end;
{$ELSE PASCAL}
function GetTempDir : KOLString;
{$IFDEF WIN} var Buf : Array[ 0..MAX_PATH ] of KOLChar; {$ENDIF WIN}
begin
  {$IFDEF LIN} Result := '/tmp/'; {$ELSE WIN}
  GetTempPath( MAX_PATH + 1, @Buf[ 0 ] );
  Result := IncludeTrailingPathDelimiter( PKOLChar( @ Buf[ 0 ] ) );
  {$ENDIF WIN}
end;
{$ENDIF}

{$IFDEF WIN}
//[function CreateTempFile]
{$IFDEF ASM_UNICODE}
function CreateTempFile( const DirPath, Prefix: KOLString ): KOLString;
asm
  push ecx
  call EAX2PCHAR
  call EDX2PCHAR
  sub  esp, 264
  push esp
  push 0
  push edx
  push eax
  call GetTempFileName
  mov  eax, [esp+264]
  mov  edx, esp
  {$IFDEF _D2009orHigher}
  xor ecx, ecx // ecx is argument
  {$ENDIF}
  call System.@LStrFromPChar 
  add  esp, 268
end;
{$ELSE PASCAL}
function CreateTempFile( const DirPath, Prefix: KOLString ): KOLString;
var Buf: array[ 0..MAX_PATH ] of KOLChar;
begin
  GetTempFileName( PKOLChar( DirPath ), PKOLChar( Prefix ), 0, Buf );
  Result := Buf;
end;
{$ENDIF ASM_VERSION}
{$ENDIF WIN}

//[function GetFileListStr]
function GetFileListStr(FPath{e.g.'c:\tmp\'}, FMask{e.g.'*.*'}: KOLString): KOLString;
{* List of files in string, separating each path from others with FileOpSeparator.
   E.g.: 'c:\tmp\unit1.dcu'#13'c:\tmp\unit1.~pa' (for use with DeleteFile2Recycle())}
var
   Srch: TFindFileData;
   succ: Boolean;
   dir:KOLString;
begin
   result := '';
   if (FPath<>'') then FPath := IncludeTrailingPathDelimiter( FPath );
   if (FMask<>'') and (FMask[1]={$IFDEF LIN} '/' {$ELSE} '\' {$ENDIF}) then
     FMask := CopyEnd(FMask,2);
   dir:=FPath+FMask;
   succ := Find_First(dir, Srch);
   while succ do begin
      if (not (Srch.dwFileAttributes and FILE_ATTRIBUTE_DIRECTORY > 0))then begin
         if Result<>''then Result:=Result+FileOpSeparator;
         Result:=Result+FPath+Srch.cFileName;
      end;
      succ := Find_Next(Srch);
   end;
   Find_Close(Srch);
end;

//[function DeleteFiles]
function DeleteFiles( const DirPath: KOLString ): Boolean;
var Files, Name: KOLString;
begin
  Files := GetFileListStr( ExtractFilePath( DirPath ), ExtractFileName( DirPath ) );
  Result := TRUE;
  while Files <> '' do
  begin
    Name := Parse( Files, FileOpSeparator );
    Result := Result and DeleteFile( PKOLChar( Name ) );
  end;
end;

{$IFDEF WIN_GDI} //>>>>>>>>>>>>
//[function DeleteFile2Recycle]
function DeleteFile2Recycle( const Filename : KOLString ) : Boolean;
begin
  Result := DoFileOp( Filename, '', FO_DELETE, FOF_ALLOWUNDO or
    FOF_NOCONFIRMATION or FOF_SIMPLEPROGRESS, 'Deleting...' );
end;

//[function CopyMoveFiles]
function CopyMoveFiles( const FromList, ToList: KOLString; Move: Boolean ): Boolean;
begin
  Result := DoFileOp(FromList, ToList, FO_COPY - Integer( Move ),
  FOF_ALLOWUNDO, nil);                   //|\\ FO_COPY = 2, FO_MOVE = 1

end;

{-}
//[function DiskFreeSpace]
function DiskFreeSpace( const Path: KOLString ): I64;
type TGetDFSEx = function( Path: PKOLChar; CallerFreeBytes, TotalBytes, FreeBytes: Pointer )
                 : Bool; stdcall;
var GetDFSEx: TGetDFSEx;
    Kern32: THandle;
    V: TOSVersionInfo;
    Ex: Boolean;
    SpC, BpS, NFC, TNC: DWORD;
    FBA, TNB: I64;
begin
  GetDFSEx := nil;
  V.dwOSVersionInfoSize := Sizeof( V );
  GetVersionEx
    ( POSVersionInfo( @ V )^ ); // bug in Windows.pas !
  Ex := FALSE;
  if V.dwPlatformId = VER_PLATFORM_WIN32_NT then
  begin
    Ex := V.dwMajorVersion >= 4;
  end
    else
  if V.dwPlatformId = VER_PLATFORM_WIN32_WINDOWS then
  begin
    Ex := V.dwMajorVersion > 4;
    if not Ex then
    if V.dwMajorVersion = 4 then
    begin
      Ex := V.dwMinorVersion > 0;
      if not Ex then
        Ex := LoWord( V.dwBuildNumber ) >= $1111;
    end;
  end;
  if Ex then
  begin
    Kern32 := GetModuleHandle( 'kernel32' );
    GetDFSEx := GetProcAddress( Kern32, 'GetDiskFreeSpaceExA' );
  end;
  if Assigned( GetDFSEx ) then
    GetDFSEx( PKOLChar( Path ), @ FBA, @ TNB, @Result )
  else
  begin
    GetDiskFreeSpace( PKOLChar( Path ), SpC, BpS, NFC, TNC );
    Result := Mul64i( MakeInt64( SpC * BpS, 0 ), NFC );
  end;
end;
{+}

//[END FILES]

//[function DoFileOp]
function DoFileOp( const FromList, ToList: KOLString; FileOp: UINT; Flags: Word;
  Title: PKOLChar): Boolean;
var FOS : {$IFDEF UNICODE_CTRLS}TSHFileOpStructW{$ELSE}TSHFileOpStruct{$ENDIF};
    Buf : PKOLChar;
    L : Integer;
begin
  L := Length( FromList );
  Buf := AllocMem( L+2 );
  Move( FromList[ 1 ], Buf^, L );
  for L := L downto 0 do
    if Buf[ L ] = FileOpSeparator then Buf[ L ] := #0;
  FillChar( FOS, Sizeof( FOS ), #0 );
  if Applet <> nil then
    FOS.Wnd := Applet.Handle;
  FOS.wFunc := FileOp;
  FOS.lpszProgressTitle := Title;
  FOS.pFrom := Buf;
  FOS.pTo := PKOLChar( ToList + #0 );
  FOS.fFlags := Flags;
  FOS.fAnyOperationsAborted := True;
  Result := {$IFDEF UNICODE_CTRLS}SHFileOperationW{$ELSE}SHFileOperationA{$ENDIF}( FOS ) = 0;
  if Result then
    Result := not FOS.fAnyOperationsAborted;
  FreeMem( Buf );
end;
{$ENDIF WIN_GDI}

{$IFDEF WIN}
//[function DirIconSysIdxOffline]
function DirIconSysIdxOffline( const Path: KOLString ): Integer;
var SFI: TShFileInfo;
begin
  SFI.iIcon := 0; // Bartov
  {$IFDEF UNICODE_CTRLS} ShGetFileInfoW {$ELSE} ShGetFileInfoA {$ENDIF}
    ( PKOLChar( Path ), FILE_ATTRIBUTE_DIRECTORY, SFI, sizeof( SFI ),
    SHGFI_SMALLICON or SHGFI_SYSICONINDEX or SHGFI_USEFILEATTRIBUTES );
  Result := SFI.iIcon;
end;
{$ENDIF WIN}

{ TDirList }

//[function NewDirList]
function NewDirList( const DirPath, Filter: KOLString; Attr: DWORD ): PDirList;
begin
  {-}
  New( Result, Create );
  {+}{++}(*Result := PDirList.Create;*){--}
  Result.ScanDirectory( DirPath, Filter, Attr );
end;
//[END NewDirList]

//[function NewDirListEx]
function NewDirListEx( const DirPath, Filters: KOLString; Attr: DWORD ): PDirList;
begin
  {-}
  New( Result, Create );
  {+}{++}(*Result := PDirList.Create;*){--}
  Result.ScanDirectoryEx( DirPath, Filters, Attr );
end;
//[END NewDirListEx]

//[procedure TDirList.Clear]
{$IFDEF ASM_VERSION}
{$ELSE ASM_VERSION} //Pascal
procedure TDirList.Clear;
begin
  if FList <> nil then
    FList.Release;
  FList := nil;
end;
{$ENDIF ASM_VERSION}

//[destructor TDirList.Destroy]
{$IFDEF ASM_VERSION}
{$ELSE ASM_VERSION} //Pascal
destructor TDirList.Destroy;
begin
  Clear;
  FPath := '';
  inherited;
end;
{$ENDIF ASM_VERSION}

//[FUNCTION FindFilter]
{$IFDEF ASM_UNICODE}
function FindFilter( const Filter: AnsiString): AnsiString;
asm
        XCHG     EAX, EDX
        PUSH     EAX
        CALL     System.@LStrAsg
        POP      EAX
        CMP      dword ptr [EAX], 0
        JNE      @@exit
        LEA      EDX, @@mask_all
        {$IFDEF _D2009orHigher}
        XOR      ECX, ECX 
        {$ENDIF}
        JE       System.@LStrFromPChar
@@mask_all:  DB  '*.*',0
@@exit:
end;
{$ELSE ASM_VERSION} //Pascal
function FindFilter(const Filter: KOLString): KOLString;
begin
  Result := Filter;
  if Result = '' then Result := '*.*';
end;
{$ENDIF ASM_VERSION}
//[END FindFilter]

//+
//[function TDirList.Get]
function TDirList.Get(Idx: Integer): PFindFileData;
begin
  Result := FList.Items[ Idx ];
end;

//[function TDirList.GetCount]
{$IFDEF ASM_VERSION}
{$ELSE ASM_VERSION} //Pascal
function TDirList.GetCount: Integer;
begin
  Result := 0;
  if FList = nil then Exit;
  Result := FList.Count;
end;
{$ENDIF ASM_VERSION}

//[function TDirList.GetNames]
{$IFDEF ASM_UNICODE}
function TDirList.GetNames(Idx: Integer): Ansistring;
asm
        MOV      EAX, [EAX].fList
        {$IFDEF TLIST_FAST}
        PUSH     ECX
        CALL     TList.Get
        LEA      EDX, [EAX + offset TWin32FindData.cFileName] //
        POP      EAX
        {$IFDEF _D2009orHigher}
        XOR      ECX, ECX
        {$ENDIF}
        CALL     System.@LStrFromPChar
        {$ELSE}
        MOV      EAX, [EAX].TList.fItems
        MOV      EDX, [EAX + EDX*4]
        ADD      EDX, offset TWin32FindData.cFileName //
        MOV      EAX, ECX
          {$IFDEF _D2009orHigher}
          XOR      ECX, ECX 
          {$ENDIF}
        CALL     System.@LStrFromPChar
        {$ENDIF}
end;
{$ELSE ASM_VERSION} //Pascal
function TDirList.GetNames(Idx: Integer): KOLString;
begin
  Result := PKOLChar(@PFindFileData(fList.Items[ Idx ]).cFileName[0]);
end;
{$ENDIF ASM_VERSION}

//[function TDirList.GetIsDirectory]
function TDirList.GetIsDirectory(Idx: Integer): Boolean;
begin
  Result := LongBool( Items[ Idx ].dwFileAttributes and FILE_ATTRIBUTE_DIRECTORY );
end;

{$IFDEF ASM_noVERSION}
//[function TDirList.SatisfyFilter]
function TDirList.SatisfyFilter(FileName: PAnsiChar; FileAttr,
  FindAttr: DWord): Boolean;
asm
        PUSH     EBX
        PUSH     ESI
        PUSH     EDI
        XCHG     EBX, EAX // EBX = @ Self
        MOV      EAX, [FindAttr]
        MOV      EDI, EDX // EDI = FileName
        MOV      EDX, EAX
        AND      EDX, ECX
        CMP      EDX, EAX
        JE       @@1

        TEST AL, FILE_ATTRIBUTE_NORMAL
        JZ      @@ret_false
@@1:
        CMP      word ptr [EDI], '.'
        JE       @@1_1
        CMP      word ptr [EDI], '..'
        JNE      @@1_1
        CMP      byte ptr [EDI+2], 0
        JNE      @@1_1
@@1_0:
        MOV      ECX, [FindAttr]
        TEST     CL, FILE_ATTRIBUTE_NORMAL
        JZ       @@1_1
        CMP      ECX, FILE_ATTRIBUTE_NORMAL
        JE       @@1_1
        TEST     AL, FILE_ATTRIBUTE_DIRECTORY
        JZ       @@1_1
        TEST     CL, FILE_ATTRIBUTE_DIRECTORY
        JNZ      @@ret_true

@@1_1:
        MOV      ECX, [EBX].fFilters
        JECXZ    @@ret_false //?

        MOV      ESI, [ECX].TStrList.fList
        MOV      ESI, [ESI].TList.fItems
        MOV      ECX, [ECX].TStrList.fCount
        JECXZ    @@ret_false

@@2:
        LODSD
        TEST     EAX, EAX
        JZ       @@nx_filter

        PUSHAD

        MOV      EDX, [EAX]
        CMP      DX, $002E
        JE       @@F_d_dd
        AND      EDX, $FFFFFF
        CMP      EDX, $002E2E
        JE       @@F_d_dd

        MOV      EDX, [EDI]
        CMP      DX, $002E
        JE       @@4
        AND      EDX, $FFFFFF
        CMP      EDX, $002E2E
        JE       @@4
        JMP      @@chk_anti

@@F_d_dd:
        MOV      EDX, EDI
        PUSH     EAX
        CALL     StrComp
        TEST     EAX, EAX
        POP      EAX
        JZ       @@popad_ret_true

@@chk_anti:
        XCHG     EDX, EAX // EDX = filter[ i ]
        MOV      EAX, EDI // EAX = FileName
        CMP      byte ptr [EDX], '^'
        JNE      @@3

        INC      EDX
        CALL     _2StrSatisfy
        TEST     AL, AL
        JZ       @@4
        POPAD
        JMP      @@ret_false

@@3:    CALL     _2StrSatisfy
        TEST     AL, AL
        JZ       @@4
@@popad_ret_true:
        POPAD
@@ret_true:
        MOV      AL, 1
        JMP      @@exit

@@4:    POPAD
@@nx_filter:
        LOOP     @@2

@@ret_false:
        XOR      EAX, EAX
@@exit:
        POP      EDI
        POP      ESI
        POP      EBX
end;
{$ELSE ASM_VERSION} //Pascal
function TDirList.SatisfyFilter(FileName: PKOLChar; FileAttr,
  FindAttr: DWord): Boolean;
{$IFDEF F_P}
const Dot: AnsiString = '.';
{$ENDIF F_P}
var I: Integer;
    F: PKOLChar;
    HasOnlyNegFilters: Boolean;
begin
  Result := (((FileAttr and FindAttr) = FindAttr) or
            LongBool(FindAttr and FILE_ATTRIBUTE_NORMAL));
  if not Result then Exit;

  if (FileName <> {$IFDEF UNICODE_CTRLS} WideString( '.' )
                  {$ELSE} {$IFDEF F_P}Dot{$ELSE}'.'{$ENDIF}
                  {$ENDIF UNICODE_CTRLS} ) and
     (FileName <> '..') then
  if LongBool( FindAttr and FILE_ATTRIBUTE_NORMAL ) and
     (FindAttr <> FILE_ATTRIBUTE_NORMAL) then
     if LongBool( FindAttr and FILE_ATTRIBUTE_DIRECTORY ) and
        LongBool( FileAttr and FILE_ATTRIBUTE_DIRECTORY ) then Exit;

  HasOnlyNegFilters := TRUE;
  for I := 0 to fFilters.Count - 1 do
  begin
    F := PKOLChar(fFilters.fList.Items[ I ]);
    if F = '' then continue;

    if (F = {$IFDEF UNICODE_CTRLS} WideString( '.' ) {$ELSE}
            {$IFDEF F_P}Dot{$ELSE}'.'{$ENDIF}
            {$ENDIF UNICODE_CTRLS} ) or (F = '..') then
    begin
      if FileName = F then
        Exit;
    end
      else
    if (Filename = {$IFDEF UNICODE_CTRLS} WideString( '.' ) {$ELSE}
                   {$IFDEF F_P}Dot{$ELSE}'.'{$ENDIF}
                   {$ENDIF UNICODE_CTRLS} ) or (FileName = '..') then
      continue;

    if F[ 0 ] = '^' then
    begin
      if StrSatisfy( FileName, PKOLChar(@F[ 1 ]) ) then
      begin
         Result := False;
         Exit;
      end;
    end
      else
    begin
      HasOnlyNegFilters := FALSE;
      if StrSatisfy( FileName, F ) then
      begin
        Result := True;
        Exit;
      end;
    end;
  end;

  Result := HasOnlyNegFilters and
            (FileName <> {$IFDEF UNICODE_CTRLS} WideString( '.' ) {$ELSE}
                         {$IFDEF F_P}Dot{$ELSE}'.'{$ENDIF}
                         {$ENDIF UNICODE_CTRLS} ) and (FileName <> '..');
end;
{$ENDIF ASM_VERSION}

{$IFDEF ASM_nononoVERSION}
//[procedure TDirList.ScanDirectory]
procedure TDirList.ScanDirectory(const DirPath, Filter: KOLString;
  Attr: DWord);
const   sz_win32finddata = sizeof(TWin32FindData);
asm
        PUSH     EBX
        PUSH     EDI
        MOV      EBX, EAX

        PUSHAD
        CALL     Clear
        CALL     NewList
        MOV      [EBX].fList, EAX
        POPAD

        PUSHAD
        LEA      EAX, [EBX].fPath
        CALL     System.@LStrAsg
        POPAD

        MOV      EAX, [EBX].fPath
        TEST     EAX, EAX
        JE       @@exit

        PUSHAD
        LEA      EDX, [EBX].fPath
        MOV      EAX, [EDX]
        CALL     IncludeTrailingPathDelimiter

        MOV      EAX, [EBX].fFilters
        TEST     EAX, EAX
        JNZ      @@1
        CALL     NewStrList
        MOV      [EBX].fFilters, EAX
        POPAD

        PUSHAD
        PUSH     ECX
        XCHG     EAX, ECX
        MOV      EDX, offset[@@star_d_star]
        CALL     StrComp
        TEST     AL, AL
        POP      EDX
        JNZ      @@asg_Filter
        MOV      EDX, offset[@@star]
@@asg_Filter:
        MOV      EAX, [EBX].fFilters
        CALL     TStrList.Add
        JMP      @@1

@@star_d_star:
        DB       '*.*', 0 // PCHAR
        
        {$IFDEF _D2009orHigher}
        DW       0, 1 
        {$ENDIF}
        DD       -1, 1
@@star: DB       '*', 0

@@1:
        POPAD

        ADD      ESP, -sz_win32finddata
        XOR      EDX, EDX
        PUSH     EDX
        PUSH     EDX
        XCHG     EAX, ECX
        MOV      EDX, ESP
        CALL     FindFilter

        LEA      EAX, [ESP+4]
        MOV      EDX, [EBX].fPath
        POP      ECX
        PUSH     ECX
        CALL     System.@LStrCat3
        CALL     RemoveStr

        POP      EAX
        MOV      EDX, ESP
        PUSH     EAX
        PUSH     EDX
        PUSH     EAX
        CALL     FindFirstFile
        MOV      EDI, EAX
        INC      EAX
        MOV      EAX, ESP

        PUSHFD
        CALL     System.@LStrClr
        POPFD
        POP      ECX

        JZ       @@fin

@@loop:
        MOV      ECX, [ESP].TWin32FindData.dwFileAttributes
        PUSH     [Attr]
        LEA      EDX, [ESP+4].TWin32FindData.cFileName
        MOV      EAX, EBX
        CALL     SatisfyFilter

        TEST     AL, AL
        JZ       @@next

        MOV      ECX, [EBX].fOnItem.TMethod.Code
        JECXZ    @@accept
        MOV      EAX, [EBX].fOnItem.TMethod.Data
        MOV      ECX, ESP
        PUSH     1
        MOV      EDX, ESP
        PUSH     EDX
        MOV      EDX, EBX
        CALL     dword ptr [EBX].fOnItem.TMethod.Code
        POP      ECX
        JECXZ    @@next
        LOOP     @@fin

@@accept:
        MOV      EAX, sz_win32finddata
        PUSH     EAX
          CALL     System.@GetMem
          PUSH     EAX
            XCHG     EDX, EAX
            MOV      EAX, [EBX].fList
            CALL     TList.Add
          POP      EDX
        POP      ECX
        MOV      EAX, ESP
        CALL     System.Move

@@next:
        PUSH     ESP
        PUSH     EDI
        CALL     FindNextFile
        TEST     EAX, EAX
        JNZ      @@loop

        PUSH     EDI
        CALL     FindClose

@@fin:
        ADD      ESP, sz_win32finddata
@@exit:
        XOR      EAX, EAX
        XCHG     EAX, [EBX].fFilters
        CALL     TObj.Free
        POP      EDI
        POP      EBX
end;
{$ELSE ASM_VERSION} //Pascal
procedure TDirList.ScanDirectory(const DirPath, Filter: KOLString;
  Attr: DWord);
var FindData : TFindFileData;
    E : PFindFileData;
    Action: TDirItemAction;
    {$IFDEF FORCE_ALTERNATEFILENAME}
    IsUnicode: AnsiString;
    {$ENDIF}
begin
  Clear;
  FPath := DirPath;
  if FPath = '' then Exit;
  FPath := IncludeTrailingPathDelimiter( FPath );
  if not Assigned(fFilters) then 
  begin
    fFilters := {$IFDEF UNICODE_CTRLS} NewWStrList {$ELSE} NewStrList {$ENDIF};
    if Filter = '*.*' then
      fFilters.Add( '*' )
    else
      fFilters.Add( Filter );
  end;
  if Find_First( PKOLChar( FPath + FindFilter( Filter ) ), FindData ) then 
  begin // D[u]fa. fix mem leaks (FList, fFilters)
    FList := NewList;
  while True do
  begin
      {$IFDEF FORCE_ALTERNATEFILENAME} //+MtsVN
    IsUnicode := FindData.cFileName;
    if (IsUnicode <> '.') and (IsUnicode <> '..') then
    begin
     if pos('?', IsUnicode) > 0 then
         CopyMemory( @FindData.cFileName, @FindData.cAlternateFileName,
                     SizeOf(FindData.cAlternateFileName));
    end;
    {$ENDIF}
    if SatisfyFilter( PKOLChar(@FindData.cFileName[0]),
                      FindData.dwFileAttributes, Attr ) then
    begin
      Action := diAccept;
      if Assigned( OnItem ) then
        OnItem( @Self, FindData, Action );
      CASE Action OF
      diSkip: ;
      diAccept:
        begin
          GetMem( E, Sizeof( FindData ) );
          E^ := FindData;
          FList.Add( E );
        end;
      diCancel: break;
      END;
    end;
    if not Find_Next( FindData ) then break;
  end;
  Find_Close( FindData );
  end;
  Free_And_Nil(fFilters);                                                       //D[u]fa
end;
{$ENDIF ASM_VERSION}

//[procedure TDirList.ScanDirectoryEx]
{$IFDEF ASM_UNICODE}
procedure TDirList.ScanDirectoryEx(const DirPath, Filters: AnsiString;
  Attr: DWord);
asm
        PUSH     EBX
        MOV      EBX, EAX

        PUSHAD
        LEA      EAX, [EBX].fFilters
        CALL     Free_And_Nil

        CALL     NewStrList
        MOV      [EBX].fFilters, EAX
        POPAD

        PUSHAD
        PUSH     0
        MOV      EAX, ESP
        MOV      EDX, ECX
        CALL     System.@LStrLAsg
@@1:    MOV      ECX, [ESP]
        JECXZ    @@2
        MOV      EAX, ESP
        MOV      EDX, offset[@@semicolon]
        PUSH     0
        MOV      ECX, ESP
        CALL     Parse
        MOV      EAX, [ESP]
        MOV      EDX, ESP
        CALL     Trim
        POP      EDX
        PUSH     EDX
        TEST     EDX, EDX
        JZ       @@filt_added
        MOV      EAX, [EBX].fFilters
        CALL     TStrList.Add
@@filt_added:
        CALL     RemoveStr
        JMP      @@1

        //       ';' string literal
        {$IFDEF _D2009orHigher}
        DW       0, 1 
        {$ENDIF}
        DD       -1, 1
@@semicolon:
        DB       ';',0

@@2:    POP      ECX
        POPAD
        XOR      ECX, ECX
        PUSH     [Attr]
        CALL     ScanDirectory
        POP      EBX
@@exit:
end;
{$ELSE ASM_VERSION} //Pascal
procedure TDirList.ScanDirectoryEx(const DirPath, Filters: KOLString;
  Attr: DWord);
var F, FF: KOLString;
begin
  FF := Filters;
  Free_And_Nil( fFilters );
  fFilters := {$IFDEF UNICODE_CTRLS} NewWStrList {$ELSE} NewStrList {$ENDIF};
  repeat
    F := Trim( Parse( FF, ';' ) );
    if F <> '' then
      fFilters.Add( F );
  until FF = '';
  ScanDirectory( DirPath, '', Attr );
end;
{$ENDIF ASM_VERSION}

type
  PSortDirData = ^TSortDirData;
  TSortDirData = packed Record
    FoldersFirst, CaseSensitive : Boolean;
    Rules : array[ 0..11 ] of TSortDirRules;
    Dir : PDirList;
  end;

//[FUNCTION CompareDirItems]
{$DEFINE CompareDirItems_ASM}
{$IFNDEF ASM_VERSION} {$UNDEF CompareDirItems_ASM} {$ENDIF}
{$IFDEF TLIST_FAST}   {$UNDEF CompareDirItems_ASM} {$ENDIF}
{$IFDEF CompareDirItems_ASM} {$DEFINE SwapDirItems_ASM} {$ENDIF}

//[PROCEDURE SwapDirItems]
{$IFDEF SwapDirItems_ASM}
{$ELSE ASM_VERSION} //Pascal
procedure SwapDirItems( const Data : PSortDirData; const e1, e2 : DWORD );
var Tmp : Pointer;
begin
  Tmp := Data.Dir.FList.{$IFDEF TLIST_FAST} Items {$ELSE} fItems {$ENDIF} [ e1 ];
  Data.Dir.FList.{$IFDEF TLIST_FAST} Items {$ELSE} fItems {$ENDIF}[ e1 ] :=
    Data.Dir.FList. {$IFDEF TLIST_FAST} Items {$ELSE} fItems {$ENDIF}[ e2 ];
  Data.Dir.FList.{$IFDEF TLIST_FAST} Items {$ELSE} fItems {$ENDIF}[ e2 ] := Tmp;
end;
{$ENDIF ASM_VERSION}
//[END SwapDirItems]

{always!} {$UNDEF CompareDirItems_ASM}

{$IFDEF CompareDirItems_ASM}
function CompareDirItems( const Data : PSortDirData; const e1, e2 : DWORD ) : Integer;
asm
        PUSH     EBX
        PUSH     ESI
        PUSH     EDI
        XCHG     EBX, EAX
        MOV      EAX, [EBX].TSortDirData.Dir
        MOV      EAX, [EAX].TDirList.fList
        MOV      EAX, [EAX].TList.fItems
        MOV      ESI, [EAX+EDX*4]
        MOV      EDI, [EAX+ECX*4]
        MOV      DL, byte ptr[ESI].TWin32FindData.dwFileAttributes
        MOV      DH, byte ptr[EDI].TWin32FindData.dwFileAttributes
        AND      DX, 2020h
        XOR      EAX, EAX
        CMP      DL, DH
        JE       @@1
        CMP      [EBX].TSortDirData.FoldersFirst, AL
        JE       @@1
        OR       AL, DL
        JNE      @@exit_near
        DEC      EAX
@@exit_near:
        POP      EDI
        POP      ESI
        POP      EBX
        RET

@@sdrByDateChanged:
        LEA      EAX, [ESI].TWin32FindData.ftLastWriteTime
        LEA      EDX, [EDI].TWin32FindData.ftLastWriteTime
        JMP      @@sdrByDate1

@@sdrByDateAccessed:
        LEA      EAX, [ESI].TWin32FindData.ftLastAccessTime
        LEA      EDX, [EDI].TWin32FindData.ftLastAccessTime
        JMP      @@sdrByDate1

@@jmp_table:
        DD       offset[@@exit1], offset[@@2], offset[@@2]
        DD       offset[@@sdrByName], offset[@@sdrByExt]
        DD       offset[@@sdrBySize], offset[@@sdrBySize]
        DD       offset[@@sdrByDateCreate], offset[@@sdrByDateChanged]
        DD       offset[@@sdrByDateAccessed]

@@1:
        LEA      EDX, [EBX].TSortDirData.Rules
        PUSH     EDX
@@2:
        POP      EDX
        XOR      EAX, EAX
        MOV      AL, [EDX]
        INC      EDX
        PUSH     EDX

        JMP      dword ptr [@@jmp_table+EAX*4]

@@sdrByDateCreate:
        LEA      EAX, [ESI].TWin32FindData.ftCreationTime
        LEA      EDX, [EDI].TWin32FindData.ftCreationTime
@@sdrByDate1:
        PUSH     EDX
        PUSH     EAX
        CALL     CompareFileTime
        TEST     EAX, EAX
        JE       @@2
        JMP      @@exit1

@@sdrBySize:
        MOV      EAX, [ESI].TWin32FindData.nFileSizeHigh
        SUB      EAX, [EDI].TWin32FindData.nFileSizeHigh
        JNE      @@sdrBySize1
        MOV      EAX, [ESI].TWin32FindData.nFileSizeLow
        SUB      EAX, [EDI].TWin32FindData.nFileSizeLow
@@to_2:
        JE       @@2
@@sdrBySize1:
        POP      EDX
        DEC      EDX
        CMP      byte ptr[EDX], sdrBySizeDescending
        JNE      @@sdrBySize2
        NEG      EAX
@@sdrBySize2:
        JNE      @@exit

        {$IFDEF _D2009orHigher}
        DW       0, 1 
        {$ENDIF}
        DD       -1, 1
@@point:DB       '.',0

@@sdrByExt:
        LEA      EAX, [EDI].TWin32FindData.cFileName
        MOV      EDX, offset[@@point]
        PUSH     EDX
        CALL     __DelimiterLast
        POP      EDX
        PUSH     EAX
        LEA      EAX, [ESI].TWin32FindData.cFileName
        CALL     __DelimiterLast
        POP      EDX
        JMP      @@sdrByName0

@@sdrByName:
        LEA      EAX, [ESI].TWin32FindData.cFileName
        LEA      EDX, [EDI].TWin32FindData.cFileName
@@sdrByName0:
        CMP      [EBX].TSortDirData.CaseSensitive, 0
        JNE      @@sdrByName1
        CALL     _AnsiCompareStrNoCase
        JMP      @@sdrByName2
@@sdrByName1:
        CALL     _AnsiCompareStr
@@sdrByName2:
        TEST     EAX, EAX
        JE       @@to_2
        //JMP    @@exit1

@@exit1:
        POP      EDX
@@exit:
        POP      EDI
        POP      ESI
        POP      EBX
end;
{$ELSE ASM_VERSION} //Pascal
function CompareDirItems( const Data : PSortDirData; const e1, e2 : DWORD ) : Integer;
var I : Integer;
    Item1, Item2 : PFindFileData;
    S1, S2 : PKOLChar;
    IsDir1, IsDir2 : Boolean;
    Date1, Date2 : PFileTime;
begin
  Item1 := Data.Dir.fList.Items[ e1 ];
  Item2 := Data.Dir.fList.Items[ e2 ];
  Result := 0;
  IsDir1 := (Item1.dwFileAttributes and FILE_ATTRIBUTE_DIRECTORY) <> 0;
  IsDir2 := (Item2.dwFileAttributes and FILE_ATTRIBUTE_DIRECTORY) <> 0;
  if (IsDir1 <> IsDir2) and Data.FoldersFirst then
  begin
    if IsDir1 then Result := -1 else Result := 1;
    exit;
  end;
  for I := 0 to High(Data.Rules) do
  begin
    case Data.Rules[ I ] of
    sdrByName:
      begin
        S1 := Item1.cFileName;
        S2 := Item2.cFileName;
        if not Data.CaseSensitive then
          Result := {$IFDEF UNICODE_CTRLS}
                      WStrComp( WAnsiUpperCase( S1 ), WAnsiUpperCase( S2 ) )
                    {$ELSE} _AnsiCompareStrNoCase( S1, S2 ) {$ENDIF}
        else
          Result := {$IFDEF UNICODE_CTRLS}
                      _WStrComp( S1, S2 )
                    {$ELSE}
                      _AnsiCompareStr( S1, S2 )
                    {$ENDIF};
      end;
    sdrByExt:
      begin
        S1 := Item1.cFileName;
        S2 := Item2.cFileName;
        S1 := {$IFDEF UNICODE_CTRLS} @ S1[ DelimiterLast( WideString( S1 ), '.' ) - 1 ]
              {$ELSE} __DelimiterLast( S1, '.' ) {$ENDIF};
        S2 := {$IFDEF UNICODE_CTRLS} @ S2[ DelimiterLast( WideString( S2 ), '.' ) - 1 ]
              {$ELSE} __DelimiterLast( S2, '.' ) {$ENDIF};
        if not Data.CaseSensitive then
           Result := {$IFDEF UNICODE_CTRLS}
                       WStrComp( WAnsiUpperCase( S1 ), WAnsiUpperCase( S2 ) )
                     {$ELSE} _AnsiCompareStrNoCase( S1, S2 ) {$ENDIF}
        else
           Result := {$IFDEF UNICODE_CTRLS} WStrComp( S1, S2 )
                     {$ELSE} _AnsiCompareStr( S1, S2 ) {$ENDIF};
      end;
    sdrBySize, sdrBySizeDescending:
      begin
        if Item1.nFileSizeHigh < Item2.nFileSizeHigh then
           Result := -1
        else
        if Item1.nFileSizeHigh > Item2.nFileSizeHigh then
           Result := 1
        else
        if Item1.nFileSizeLow < Item2.nFileSizeLow then
           Result := -1
        else
        if Item1.nFileSizeLow > Item2.nFileSizeLow then
           Result := 1;
        if Data.Rules[ I ] = sdrBySizeDescending then
           Result := -Result;
      end;
    sdrByDateCreate:
      begin
        Date1 := @Item1.ftCreationTime;
        Date2 := @Item2.ftCreationTime;
        Result := FileTimeCompare( Date1^, Date2^ );
      end;
    sdrByDateChanged:
      begin
        Date1 := @Item1.ftLastWriteTime;
        Date2 := @Item2.ftLastWriteTime;
        Result := FileTimeCompare( Date1^, Date2^ );
      end;
    sdrByDateAccessed:
      begin
        Date1 := @Item1.ftLastAccessTime;
        Date2 := @Item2.ftLastAccessTime;
        Result := FileTimeCompare( Date1^, Date2^ );
      end;
    end; {case}
    if Result <> 0 then break;
  end;
end;
{$ENDIF ASM_VERSION}
//[END CompareDirItems]

{$IFDEF ASM_VERSION}
{$ELSE ASM_VERSION} //Pascal
procedure TDirList.Sort(Rules: array of TSortDirRules);
var SortDirData : TSortDirData;
    I, J : Integer;

    function RulePresent( Rule : TSortDirRules ) : Boolean;
    var K : Integer;
    begin
      Result := True;
      for K := J - 1 downto 0 do
        if Rule = SortDirData.Rules[ K ] then exit;
      Result := False;
    end;

    procedure AddRule( Rule : TSortDirRules );
    begin
      if J > High( SortDirData.Rules ) then exit;
      if RulePresent( Rule ) then exit;
      SortDirData.Rules[ J ] := Rule;
      Inc( J );
    end;
begin
  if fList = nil then Exit;
  J := 0;
  for I := 0 to High(Rules) do
    AddRule( Rules[ I ] );
  for I := 0 to High(DefSortDirRules) do
    AddRule( DefSortDirRules[ I ] );
  while J < High( SortDirData.Rules ) do
  begin
    SortDirData.Rules[ J ] := sdrNone;
    Inc( J );
  end;

  SortDirData.Dir := @Self;
  SortDirData.FoldersFirst := RulePresent( sdrFoldersFirst );
  SortDirData.CaseSensitive := RulePresent( sdrCaseSensitive );
  SortData( Pointer( @SortDirData ), fList.fCount, @CompareDirItems, @SwapDirItems );
end;
{$ENDIF ASM_VERSION}

//[function TDirList.FileList]
function TDirList.FileList(const Separator: KOLString; Dirs,
  FullPaths: Boolean): KOLString;
var I: Integer;
begin
  Result := '';
  for I := 0 to Count-1 do
  begin
    if not Dirs and IsDirectory[ I ] then Continue;
    if FullPaths then
      Result := Result + Path;
    Result := Result + Names[ I ] + Separator;
  end;
end;
*)

PROCEDURE SameFile* (IN fileName1, fileName2: KOLString): BOOLEAN;
(*
	dwVolumeSerialNumber
			Serial number of the volume that contains the file.
	nFileIndexHigh
			High-order word of a unique identifier associated with the file.
	nFileIndexLow
			Low-order word of a unique identifier associated with the file. This identifier and the volume serial number uniquely identify a file. This number may change when the system is restarted or when the file is opened. After a process opens a file, the identifier is constant until the file is closed. An application can use this identifier and the volume serial number to determine whether two handles refer to the same file.
			Note that this value is useful only while the file is open by at least one process. If no processes have it open, the index may change the next time the file is opened.
			The identifier (low and high parts) and the volume serial number uniquely identify a file on a single computer. To determine whether two open handles represent the same file, combine this identifier and the volume serial number for each file and compare them.
*)
VAR
	fileInfo1, fileInfo2: W.BY_HANDLE_FILE_INFORMATION;
	handle1, handle2: W.HANDLE; same: BOOLEAN; res: W.BOOL;
BEGIN
	same := FALSE;
	(* File 1 *) 
	handle1 := W.CreateFileA(
		S.VAL(W.PtrSTR, S.ADR(fileName1)), W.GENERIC_READ,
		W.FILE_SHARE_READ, NIL, W.OPEN_EXISTING, {}, NIL);
	IF handle1 # S.VAL(W.HANDLE, W.INVALID_HANDLE_VALUE) THEN
		(* File 2 *)
		handle2 := W.CreateFileA(
			S.VAL(W.PtrSTR, S.ADR(fileName2)), W.GENERIC_READ,
			W.FILE_SHARE_READ, NIL, W.OPEN_EXISTING, {}, NIL);
		IF handle2 # S.VAL(W.HANDLE, W.INVALID_HANDLE_VALUE) THEN
			same :=
				(W.GetFileInformationByHandle(handle1, fileInfo1) # 0) &
				(W.GetFileInformationByHandle(handle2, fileInfo2) # 0) &
				(fileInfo1.nFileIndexLow = fileInfo2.nFileIndexLow) &
				(fileInfo1.nFileIndexHigh = fileInfo2.nFileIndexHigh) &
				(fileInfo1.dwVolumeSerialNumber = fileInfo2.dwVolumeSerialNumber);
			res := W.CloseHandle(handle2);
		END;
		res := W.CloseHandle(handle1);
	END;
	RETURN same
END SameFile;

(*
BEGIN
  hInstance := W.GetModuleHandle(NIL);*)
PROCEDURE- _init* "/*-noinit*/";

END KolFiles.
