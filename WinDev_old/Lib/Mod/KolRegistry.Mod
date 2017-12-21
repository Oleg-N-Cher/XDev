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

MODULE KolRegistry; (* nonportable (Win32) *)
IMPORT S := SYSTEM, W := WinApi, Ignore, Typ := KolTypes, KolStrings;

CONST
  HKEY_CLASSES_ROOT* = W.HKEY_CLASSES_ROOT;
  HKEY_CURRENT_USER* = W.HKEY_CURRENT_USER;
  HKEY_LOCAL_MACHINE* = W.HKEY_LOCAL_MACHINE;
  HKEY_USERS* = W.HKEY_USERS;

  REG_BINARY* = W.REG_BINARY;
  REG_DWORD* = W.REG_DWORD;
  REG_DWORD_LITTLE_ENDIAN* = W.REG_DWORD_LITTLE_ENDIAN;
  REG_DWORD_BIG_ENDIAN* = W.REG_DWORD_BIG_ENDIAN;
  REG_EXPAND_SZ* = W.REG_EXPAND_SZ;
  REG_LINK* = W.REG_LINK;
  REG_MULTI_SZ* = W.REG_MULTI_SZ;
  REG_NONE* = W.REG_NONE;
  REG_RESOURCE_LIST* = W.REG_RESOURCE_LIST;
  REG_SZ* = W.REG_SZ;

TYPE
  HKey* = W.HKEY;
  DWORD = Typ.DWORD;
  SHORTCHAR = CHAR;
  Integer = Typ.Integer;
  KOLChar = (*KolTypesA*)Typ.KOLChar;
  KOLString = Typ.KOLString;
  PByte = Typ.PByte;
  PKOLChar = Typ.PKOLChar;
  PKOLString = Typ.PKOLString;
  TDateTime = (*KolTypesA*)Typ.TDateTime;

(*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*)
(*[Registry FUNCTIONS DECLARATIONS]*)

PROCEDURE ^ OpenRead* (key: HKey; IN subKey: KOLString): HKey;
(* Opens registry key for read operations (including enumerating of subkeys).
   Pass either handle of opened earlier key or one of constans
   HKEY_CLASSES_ROOT, HKEY_CURRENT_USER, HKEY_LOCAL_MACHINE, HKEY_USERS
   as a first parameter. If not successful, 0 is returned. *)
PROCEDURE ^ OpenWrite* (key: HKey; IN subKey: KOLString): HKey;
(* Opens registry key for write operations (including adding new values or
   subkeys), as well as for read operations too. See also RegKeyOpenRead. *)
PROCEDURE ^ OpenCreate* (key: HKey; IN subKey: KOLString): HKey;
(* Creates and opens key. *)
(*
PROCEDURE ^ GetStr* (key: HKey; IN valueName: KOLString):
  PKOLString;
(* Reads key, which must have type REG_SZ (null-terminated string). If
   not successful, empty string is returned. This function as well as all
   other registry manipulation functions, does nothing, if Key passed is 0
   (without producing any error). *)
PROCEDURE ^ GetStrEx* (key: HKey; IN valueName: KOLString;
  expandEnvVars: BOOLEAN): PKOLString;
*)
(* Like RegKeyGetStr, but accepts REG_EXPAND_SZ type, expanding all
   environment variables in resulting string.
   |<br>
   Code provided by neuron, e-mailto:neuron@hollowtube.mine.nu *)
PROCEDURE ^ GetDw* (key: HKey; IN valueName: KOLString): DWORD;
(* Reads key value, which must have type REG_DWORD. If ValueName passed
   is '' (empty string), unnamed (default) value is reading. If not
   successful, 0 is returned. *)
(*
PROCEDURE ^ RegKeySetStr* (key: HKey; IN valueName: KOLString;
  IN value: KOLString): BOOLEAN;
(* Writes new key value as null-terminated string (type REG_SZ). If not
   successful, returns False. *)
PROCEDURE ^ RegKeySetStrEx* (key: HKey; IN valueName: KOLString;
  IN value: KOLString; expand: BOOLEAN): BOOLEAN;
(* Writes new key value as REG_SZ or REG_EXPAND_SZ. - by neuron, e-mailto:neuron@hollowtube.mine.nu *)
PROCEDURE ^ RegKeySetDw* (key: HKey; IN valueName: KOLString; value: DWORD):
  BOOLEAN;
(* Writes new key value as dword (with type REG_DWORD). Returns False,
   if not successful. *)
*)
PROCEDURE ^ Close* (key: HKey);
(* Closes key, opened using RegKeyOpenRead or RegKeyOpenWrite. (But does
   nothing, if Key passed is 0). *)
PROCEDURE ^ Delete* (key: HKey; IN subKey: KOLString): BOOLEAN;
(* Deletes key. Does nothing if key passed is 0 (returns FALSE). *)
(*
PROCEDURE ^ RegKeyDeleteValue* (key: HKey; IN subKey: KOLString): BOOLEAN;
(* Deletes value. - by neuron, e-mailto:neuron@hollowtube.mine.nu *)
*)
PROCEDURE ^ Exists* (key: HKey; IN subKey: (*Ansi*)KOLString): BOOLEAN;
(*
(* Returns TRUE, if given subkey exists under given Key. *)
PROCEDURE ^ RegKeyValExists* (key: HKey; IN valueName: KOLString): BOOLEAN;
(* Returns TRUE, if given value exists under the Key.
*)
PROCEDURE ^ RegKeyValueSize* (key: HKey; IN valueName: KOLString): Integer;
(* Returns a size of value. This is a size of buffer needed to store
   registry key value. For string value, size returned is equal to a
   length of string plus 1 for terminated null character. *)
PROCEDURE ^ RegKeyGetBinary* (key: HKey; IN valueName: KOLString;
  VAR buffer: ARRAY OF BYTE; count: Integer): Integer;
(* Reads binary data from a registry, writing it to the Buffer.
   It is supposed that size of Buffer provided is at least Count bytes.
   Returned value is actul count of bytes read from the registry and written
   to the Buffer.
   |<br>
   This function can be used to get data of any type from the registry, not
   only REG_BINARY. *)
PROCEDURE ^ RegKeySetBinary* (key: HKey; IN valueName: KOLString;
  IN buffer: ARRAY OF BYTE; count: Integer): BOOLEAN;
(* Stores binary data in the registry. *)
PROCEDURE ^ RegKeyGetDateTime* (key: HKey; IN valueName: KOLString): TDateTime;
(* Returns datetime variable stored in registry in binary format. *)
PROCEDURE ^ RegKeySetDateTime* (key: HKey; IN valueName: KOLString;
  dateTime: TDateTime): BOOLEAN;
(* Stores DateTime variable in the registry. *)

(*-------------------------------------------------------
// registry functions by Valerian Luft <luft@valerian.de>
//-------------------------------------------------------
*)
(*
PROCEDURE ^ RegKeyGetSubKeys( Key: HKey; List: PKOLStrList): BOOLEAN;
(* The function enumerates subkeys of the specified open registry key.
   True is returned, if successful.
*)
PROCEDURE ^ RegKeyGetValueNames(Key: HKey; List: PKOLStrList): BOOLEAN;
(* The function enumerates value names of the specified open registry key.
   True is returned, if successful.
*)
*)
PROCEDURE ^ RegKeyGetValueTyp* (key: HKey; IN valueName: KOLString): DWORD;
(* The function receives the type of data stored in the specified value.
   |<br>
   If the function fails, the return value is the Key value.
   |<br>
   If the function succeeds, the return value return will be one of the following:
   |<br>
   REG_BINARY , REG_DWORD, REG_DWORD_LITTLE_ENDIAN,
   REG_DWORD_BIG_ENDIAN, REG_EXPAND_SZ, REG_LINK , REG_MULTI_SZ,
   REG_NONE, REG_RESOURCE_LIST, REG_SZ

|<hr> *)*)

(*//////////////////////////////////////////////////////////////////////
//                        R  E  G  I  S  T  R  Y
//////////////////////////////////////////////////////////////////////*)
(* -- registry -- *)

PROCEDURE OpenRead* (key: HKey; IN subKey: KOLString): HKey;
VAR
  result: HKey;
BEGIN
  IF W.RegOpenKeyExA(
    key,
    S.VAL(W.PtrSTR, S.ADR(subKey)),
    0,
    W.KEY_READ,
    result
  )
    # W.ERROR_SUCCESS
  THEN
    result := NIL;
  END;
  RETURN result
END OpenRead;

PROCEDURE OpenWrite* (key: HKey; IN subKey: KOLString): HKey;
VAR
  result: HKey;
BEGIN
  IF W.RegOpenKeyExA(
    key,
    S.VAL(W.PtrSTR, S.ADR(subKey)),
    0,
    W.KEY_READ + W.KEY_WRITE,
    result
  )
    # W.ERROR_SUCCESS
  THEN
    result := NIL;
  END;
  RETURN result
END OpenWrite;

PROCEDURE OpenCreate* (key: HKey; IN subKey: KOLString): HKey;
VAR
  result: HKey; dwDisp: DWORD;
BEGIN
  IF W.RegCreateKeyExA(
    key,
    S.VAL(W.PtrSTR, S.ADR(subKey)),
    0,
    NIL,
    {},
    W.KEY_ALL_ACCESS,
    NIL,
    result,
    dwDisp
  )
    # W.ERROR_SUCCESS
  THEN
    result := NIL;
  END;
  RETURN result
END OpenCreate;

PROCEDURE GetDw* (key: HKey; IN valueName: KOLString): DWORD;
VAR
  dwType, dwSize, result: DWORD;
BEGIN
  dwSize := SIZE(DWORD);
  result := 0;
  IF
    (key = NIL)
  OR
    (W.RegQueryValueExA(
      key,
      S.VAL(W.PtrSTR, S.ADR(valueName)),
      NIL,
      dwType,
      S.VAL(PByte, S.ADR(result)),
      dwSize
    )
      # W.ERROR_SUCCESS)
  OR
    (dwType # W.REG_DWORD)
  THEN
    result := 0;
  END;
  RETURN result
END GetDw;
(*
PROCEDURE GetStr* (key: HKey; IN valueName: KOLString): PKOLString;
VAR
  dwType, dwSize: DWORD;
  buffer: PKOLString;

  PROCEDURE Query(): BOOLEAN;
  BEGIN
    RETURN W.RegQueryValueExA(
      key,
      S.VAL(W.PtrSTR, S.ADR(valueName)),
      NIL,
      dwType,
      buffer,
      dwSize)
        = W.ERROR_SUCCESS
    END Query;
BEGIN
  IF key = NIL THEN RETURN KolStringsA.PtrToEmptyKOLString END;
  dwSize := 0;
  buffer := NIL;
  IF ~ Query() OR (dwType # W.REG_SZ) THEN
    RETURN KolStringsA.PtrToEmptyKOLString
  END;
  NEW(buffer, dwSize * SIZE(KOLChar));
  IF Query() THEN RETURN buffer END;
  RETURN KolStringsA.PtrToEmptyKOLString  
END GetStr;
*)

PROCEDURE GetStrNoGC* (key: HKey; IN valueName: KOLString;
  OUT result: KOLString): BOOLEAN;
VAR
  dwType, dwSize: DWORD;

  PROCEDURE Query(): BOOLEAN;
  BEGIN
    RETURN W.RegQueryValueExA(
      key,
      S.VAL(W.PtrSTR, S.ADR(valueName)),
      NIL,
      dwType,
      S.VAL(W.PtrSTR, S.ADR(result)),
      dwSize)
        = W.ERROR_SUCCESS
    END Query;
BEGIN
  result[0] := 0X;
  IF key = NIL THEN RETURN FALSE END;
  dwSize := 0;
  IF ~ Query() OR (dwType # W.REG_SZ) THEN RETURN FALSE END;
  IF (LEN(result) <= dwSize) & Query() THEN RETURN TRUE END;
  RETURN FALSE  
END GetStrNoGC;
(*
PROCEDURE GetStrEx* (key: HKey; IN valueName: KOLString;
  expandEnvVars: BOOLEAN): PKOLString;
VAR
  dwType, dwSize: DWORD;
  buffer, buffer2: PKOLString;
  sz: Integer;

  PROCEDURE Query(): BOOLEAN;
  BEGIN
    RETURN W.RegQueryValueExA(
      key,
      S.VAL(W.PtrSTR, S.ADR(valueName)),
      NIL,
      dwType,
      buffer,
      dwSize)
        = W.ERROR_SUCCESS
    END Query;
BEGIN
  IF key = NIL THEN RETURN KolStringsA.PtrToEmptyKOLString END;
  dwSize := 0;
  buffer := NIL;
  IF ~ Query() OR ((dwType # W.REG_SZ) & (dwType # W.REG_EXPAND_SZ)) THEN
    RETURN KolStringsA.PtrToEmptyKOLString
  END;
  NEW(buffer, dwSize * SIZE(KOLChar));
  IF Query() THEN
    IF (dwType = W.REG_EXPAND_SZ) & (expandEnvVars) THEN
      sz := W.ExpandEnvironmentStringsA(buffer, NIL, 0);
        (* bug in size detection! sometimes we get *)
        (* an additional 2 bytes at the end... *)
      NEW(buffer2, sz * SIZE(KOLChar));
      Ignore.Int(
        W.ExpandEnvironmentStringsA(buffer, buffer2, sz)
      );
      RETURN buffer2
    END;
    RETURN buffer
  END;
  RETURN KolStringsA.PtrToEmptyKOLString
END GetStrEx;

PROCEDURE GetStrExNoGC* (key: HKey; IN valueName: KOLString;
  expandEnvVars: BOOLEAN; OUT result: KOLString): BOOLEAN;
VAR
  dwType, dwSize: DWORD;
(*  buffer, buffer2: PKOLString;*)
  sz: Integer;

  PROCEDURE Query(): BOOLEAN;
  BEGIN
    RETURN W.RegQueryValueExA(
      key,
      S.VAL(W.PtrSTR, S.ADR(valueName)),
      NIL,
      dwType,
      S.VAL(W.PtrSTR, S.ADR(result)),
      dwSize)
        = W.ERROR_SUCCESS
    END Query;
BEGIN
  result[0] := 0X;
  IF key = NIL THEN RETURN FALSE END;
  dwSize := 0;
  IF ~ Query() OR ((dwType # W.REG_SZ) & (dwType # W.REG_EXPAND_SZ)) THEN
    RETURN FALSE
  END;
  IF (LEN(result) <= dwSize) & Query() THEN
    IF (dwType = W.REG_EXPAND_SZ) & (expandEnvVars) THEN
      sz := W.ExpandEnvironmentStringsA(S.VAL(W.PtrSTR, S.ADR(result)), NIL, 0);
        (* bug in size detection! sometimes we get *)
        (* an additional 2 bytes at the end... *)
      NEW(buffer2, sz * SIZE(KOLChar));
      Ignore.Int(
        W.ExpandEnvironmentStringsA(buffer, buffer2, sz)
      );
      RETURN buffer2
    END;
    RETURN TRUE
  END;
  RETURN FALSE
END GetStrExNoGC;
*)
PROCEDURE SetDw* (key: HKey; IN valueName: KOLString; value: DWORD):
  BOOLEAN;
BEGIN
  RETURN
    (key # NIL)
  &
    (W.RegSetValueExA(
      key,
      S.VAL(W.PtrSTR, S.ADR(valueName)),
      0,
      W.REG_DWORD,
      S.VAL(W.PtrVoid, S.ADR(value)),
      SIZE(DWORD))
    = W.ERROR_SUCCESS
  )
END SetDw;

PROCEDURE KeySetStr* (key: HKey; IN valueName, value: KOLString):
  BOOLEAN;
BEGIN
  RETURN
    (key # NIL)
  &
    (W.RegSetValueExA(
      key,
      S.VAL(W.PtrSTR, S.ADR(valueName)),
      0,
      W.REG_SZ,
      S.VAL(W.PtrSTR, S.ADR(value)),
      (KolStrings.Length(value) + 1)*SIZE(KOLChar))
    = W.ERROR_SUCCESS
  )
END KeySetStr;
(*
(*//[FUNCTION RegKeySetStrEx]*)
PROCEDURE KeySetStrEx* (key: HKey; IN valueName: KOLString;
  IN value: KOLString; expand: BOOLEAN): BOOLEAN;
VAR
  dwType: DWORD; UPtrValue: UPKOLChar;
BEGIN
  dwType := W.REG_SZ;
  IF expand THEN dwType := W.REG_EXPAND_SZ END;
  UPtrValue := S.VAL(UPKOLChar, S.ADR(value));
  RETURN (key # 0) & (W.RegSetValueEx(key, (*PKOLChar*)valueName, 0,
    dwType, (*PKOLChar*)UPtrValue[0],
    (KolStringsA.Length(value) + 1)*SIZE(KOLChar)) = W.ERROR_SUCCESS)
END KeySetStrEx;
*)

PROCEDURE Close* (key: HKey);
BEGIN
  IF key # NIL THEN Ignore.Int(W.RegCloseKey(key)) END;
END Close;

PROCEDURE Delete* (key: HKey; IN subKey: KOLString): BOOLEAN;
VAR
  result: BOOLEAN;
BEGIN
  result := FALSE;
  IF key # NIL THEN
    result := W.RegDeleteKey(key, S.VAL(W.PtrSTR, S.ADR(subKey))) =
      W.ERROR_SUCCESS
  END;
  RETURN result
END Delete;
(*
(*//[FUNCTION RegKeyDeleteValue]*)
PROCEDURE KeyDeleteValue* (key: HKey; IN subKey: KOLString): BOOLEAN;
VAR
  result: BOOLEAN;
BEGIN
  result := FALSE;
  IF key # NIL THEN
    result := W.RegDeleteValue(key, S.VAL(W.PtrSTR, S.ADR(subKey))) =
      W.ERROR_SUCCESS
  END;
  RETURN result
END KeyDeleteValue;
*)
PROCEDURE Exists* (key: HKey; IN subKey: KOLString): BOOLEAN;
VAR
  k: HKey;
BEGIN
  IF key = NIL THEN RETURN FALSE END;
  k := OpenRead(key, subKey);
  IF k # NIL THEN Close(k) END;
  RETURN k # NIL
END Exists;
(*
(*//[FUNCTION RegKeyValExists]*)
PROCEDURE KeyValExists* (key: HKey; IN valueName: KOLString): BOOLEAN;
VAR
  dwType, dwSize: DWORD;
BEGIN
  RETURN (key # NIL) &
         (W.RegQueryValueEx(key, S.VAL(W.PtrSTR, S.ADR(valueName)), NIL,
         dwType, NIL, dwSize ) = W.ERROR_SUCCESS);
END KeyValExists;

(*//[FUNCTION RegKeyValueSize]*)
PROCEDURE KeyValueSize* (key: HKey; IN valueName: KOLString): Integer;
VAR
  result: Integer;
BEGIN
  result := 0;
  IF key = NIL THEN RETURN 0 END;
  Ignore.Int(
    W.RegQueryValueEx(key, S.VAL(W.PtrSTR, S.ADR(valueName)), NIL, NIL, NIL,
    (*@ DWORD*)result)
  );
  RETURN result
END KeyValueSize;
(*
(*//[FUNCTION RegKeyGetBinary]*)
PROCEDURE KeyGetBinary* (key: HKey; IN valueName: KOLString;
  OUT buffer: ARRAY OF BYTE; count: Integer): Integer;
TYPE
  UPtrDWORDAsPtrSChar = POINTER TO ARRAY [untagged] SIZE(DWORD) OF SHORTCHAR;
VAR
  result: Integer; UPtrBuffer: UPtrDWORDAsPtrSChar;
BEGIN
  result := 0;
  IF key = 0 THEN RETURN 0 END;
  result := count;
  UPtrBuffer := S.VAL(UPtrDWORDAsPtrSChar, S.ADR(buffer));
  S.PUTREG(0,
  W.RegQueryValueEx(key, (*PKOLChar*)valueName, NIL, NIL,
    UPtrBuffer[0], result));
  RETURN result
END KeyGetBinary;

(*//[FUNCTION RegKeySetBinary]*)
PROCEDURE KeySetBinary* (key: HKey; IN valueName: KOLString;
  IN buffer: ARRAY OF BYTE; count: Integer): BOOLEAN;
TYPE
  UPtrDWORDAsPtrSChar = POINTER TO ARRAY [untagged] SIZE(DWORD) OF SHORTCHAR;
VAR
  UPtrBuffer: UPtrDWORDAsPtrSChar;
BEGIN
  UPtrBuffer := S.VAL(UPtrDWORDAsPtrSChar, S.ADR(buffer));
  RETURN (key # 0) & (W.RegSetValueEx(key, (*PKOLChar*)valueName, 0,
         W.REG_BINARY, UPtrBuffer[0], count)
         = W.ERROR_SUCCESS)
END KeySetBinary;

(*//[FUNCTION RegKeyGetDateTime]*)
PROCEDURE KeyGetDateTime* (key: HKey; IN valueName: KOLString): TDateTime;
TYPE
  UPtrResult = POINTER TO ARRAY [untagged] SIZE(TDateTime) OF BYTE;
VAR
  result: TDateTime;
BEGIN
  S.PUTREG(0,
  RegKeyGetBinary(key, valueName,
    S.VAL(UPtrResult, S.ADR(result)), SIZE(TDateTime)));
  RETURN result
END KeyGetDateTime;

(*//[FUNCTION RegKeySetDateTime]*)
PROCEDURE KeySetDateTime* (key: HKey; IN valueName: KOLString;
  dateTime: TDateTime): BOOLEAN;
TYPE
  UPtrResult = POINTER TO ARRAY [untagged] SIZE(TDateTime) OF BYTE;
BEGIN
  RETURN RegKeySetBinary(key, valueName,
    S.VAL(UPtrResult, S.ADR(dateTime)), SIZE(TDateTime))
END KeySetDateTime;

(*
{$IFDEF OLD_REGKEYGETSUBKEYS}
//-----------------------------------------------
// functions by Valerian Luft <luft@valerian.de>
//-----------------------------------------------
//[function RegKeyGetSubKeys]
function RegKeyGetSubKeys( const Key: HKey; List: PStrList) : Boolean;
var
  I, Size, NumSubKeys, MaxSubKeyLen : DWORD;
  KeyName: AnsiString;
begin
  Result := False;
  List.Clear ;
  if RegQueryInfoKey(Key, nil, nil, nil, @NumSubKeys, @MaxSubKeyLen, nil, nil, nil, nil,
nil, nil) = ERROR_SUCCESS then
    begin
      if NumSubKeys > 0 then begin
        for I := 0 to NumSubKeys-1 do
        begin
          Size := MaxSubKeyLen+1;
          SetLength(KeyName, Size);
          //FillChar(KeyName[1],Size,#0);
          RegEnumKeyEx(Key, I, @KeyName[1], Size, nil, nil, nil, nil);
          SetLength(KeyName, lstrlen(@KeyName[1]));
          List.Add(KeyName);
        end;
      end;
      Result:= True;
  end;
end;
{$ELSE} // new (faster) version by Alex Shyshko (Psychedelic)
function RegKeyGetSubKeys(const Key: HKey; List: PKOLStrList) : Boolean;
var
  i, MaxSubKeyLen, Size: DWORD;
  Buf: PKOLChar;
begin
 Result:=false;
 List.Clear;

 if RegQueryInfoKey(Key, nil, nil, nil, nil, @MaxSubKeyLen, nil, nil, nil, nil,
     nil, nil) = ERROR_SUCCESS then
  begin
  if MaxSubKeyLen > 0 then
    begin
      GetMem(Buf,MaxSubKeyLen + 1);
      i:=0;
      Size:=MaxSubKeyLen + 1;

      while RegEnumKeyEx(Key,i,buf,Size,nil,nil,nil,nil) <> ERROR_NO_MORE_ITEMS do
      begin
       List.Add(KOLString(Buf));
       Size:=MaxSubKeyLen + 1;
       inc(i);
      end;

      FreeMem(Buf{,MaxSubKeyLen + 1});
    end; // if MaxSubKeyLen
   Result:=true;
  end; // if RegQueryInfoKey

end;
{$ENDIF}

//[function RegKeyGetValueNames]
{$IFDEF OLD_REGKEYGETVALUENAMES}
function RegKeyGetValueNames(const Key: HKey; List: PKOLStrList): Boolean;
var
  I, Size, NumSubKeys, NumValueNames, MaxValueNameLen: DWORD;
  ValueName: KOLString;
begin
  List.Clear ;
  Result:=False;
  if RegQueryInfoKey(Key, nil, nil, nil, @NumSubKeys, nil, nil, @NumValueNames,
@MaxValueNameLen, nil, nil, nil) = ERROR_SUCCESS then
  begin
     if NumValueNames > 0 then
        for I := 0 to NumValueNames - 1 do begin
          Size := MaxValueNameLen + 1;
          SetLength(ValueName, Size);
          FillChar(ValueName[1],Size,#0);
          RegEnumValue(Key, I, @ValueName[1], Size, nil, nil, nil, nil);
          ValueName := Trim(ValueName);
          List.Add(ValueName);
        end;
     Result := True;
  end ;
end;
{$ELSE} // new (faster) version by Alex Shyshko (Psychedelic)
function RegKeyGetValueNames(const Key: HKey; List: PKOLStrList) : Boolean;
var
  i, MaxValueNameLen, Size: DWORD;
  Buf: PKOLchar;
begin
 Result:=false;
 List.Clear;

 if RegQueryInfoKey(Key, nil, nil, nil, nil, nil, nil, nil, @MaxValueNameLen, nil,
     nil, nil) = ERROR_SUCCESS then
  begin
  if MaxValueNameLen > 0 then
    begin
      Size:=MaxValueNameLen+1;
      GetMem(Buf,Size * SizeOf(KOLChar) );
      i:=0;
      while RegEnumValue(Key,i,buf,Size,nil,nil,nil,nil) <> ERROR_NO_MORE_ITEMS do
      begin
       List.Add(KOLString(Buf));
       Size:=MaxValueNameLen+1;
       inc(i);
      end;

      FreeMem(Buf {,MaxValueNameLen + ... system always knows how long buffer is});
    end; // if MaxValueNameLen
   Result:=true;
  end; // if RegQueryInfoKey

end;
{$ENDIF}
*)

(*//[FUNCTION RegKeyGetValueTyp]*)
PROCEDURE KeyGetValueTyp* (key: HKey; IN valueName: KOLString): DWORD;
VAR
  result: DWORD;
BEGIN
  result := key;
  IF key # 0 THEN
    S.PUTREG(0,
    W.RegQueryValueEx(key, valueName, NIL, result, NIL, NIL))
  END;
  RETURN result
END KeyGetValueTyp;
*)*)
PROCEDURE- _init* "/*-noinit*/";

END KolRegistry.