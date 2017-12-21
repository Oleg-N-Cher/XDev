MODULE Debug;
IMPORT SYSTEM, W := WinApi, Ignore;

TYPE
  PtrSTR = ARRAY OF CHAR;
VAR
  hConOut: W.HANDLE;

PROCEDURE WriteCh (ch: CHAR);
VAR
  bytesWritten: INTEGER;
BEGIN
  Ignore.Int(
    W.WriteFile(hConOut, SYSTEM.VAL(W.PtrSTR, SYSTEM.ADR(ch)), 1, bytesWritten, NIL)
  );
END WriteCh;

PROCEDURE WriteStr* (IN str: ARRAY OF CHAR);
VAR
  strLen, maxLen: INTEGER;
BEGIN
  strLen := 0; maxLen := SHORT(LEN(str));
  WHILE (strLen < maxLen) & (str[strLen] # 0X) DO
    WriteCh(str[strLen]); INC(strLen);
  END;
END WriteStr;

PROCEDURE WriteInt* (x: LONGINT);
VAR
  n: LONGINT; buf: ARRAY 20 OF CHAR;
BEGIN
  IF x < 0 THEN
    IF x = MIN(LONGINT) THEN WriteStr("-9223372036854775808"); RETURN END;
    WriteCh("-"); x := -x;
  END;
  n := 0;
  REPEAT
    buf[n] := CHR(x MOD 10 + ORD("0")); x := x DIV 10; INC(n);
  UNTIL x = 0;
  REPEAT DEC(n); WriteCh(buf[n]) UNTIL n = 0;
END WriteInt;

PROCEDURE WriteLn* ;
BEGIN
  WriteCh(0DX); WriteCh(0AX);
END WriteLn;

PROCEDURE Int* (IN msg: ARRAY OF CHAR; i: LONGINT);
BEGIN
  WriteStr(msg); WriteInt(i); WriteLn;
END Int;

PROCEDURE Ptr* (IN msg: ARRAY OF CHAR; ptr: SYSTEM.PTR);
BEGIN
  WriteStr(msg);
  IF SIZE(SYSTEM.PTR) = SIZE(INTEGER) THEN
    WriteInt(SYSTEM.VAL(INTEGER, ptr)); WriteLn;
  END;
  IF SIZE(SYSTEM.PTR) = SIZE(LONGINT) THEN
    WriteInt(SYSTEM.VAL(LONGINT, ptr)); WriteLn;
  END;
END Ptr;

PROCEDURE Bool* (IN msg: ARRAY OF CHAR; b: BOOLEAN);
BEGIN
  WriteStr(msg);
  IF b THEN WriteStr("TRUE") ELSE WriteStr("FALSE") END; WriteLn;
END Bool;

PROCEDURE Str* (IN msg: ARRAY OF CHAR);
BEGIN
  WriteStr(msg); WriteLn;
END Str;

PROCEDURE -sprintf (str: PtrSTR; n: LONGINT)	'sprintf(str, "%ld", n)'; 
PROCEDURE -sprintfL (str: PtrSTR; n: LONGINT)	'sprintf(str, "%lld", n)';

PROCEDURE IntToStr (n: LONGINT; VAR str: ARRAY OF CHAR);
  (** UNSAFE! Make sure that size of array 'str' is enough. *)
BEGIN
  IF SIZE(LONGINT) = 4 THEN sprintf(str, n) END;
  IF SIZE(LONGINT) = 8 THEN sprintfL(str, n) END;
END IntToStr;

PROCEDURE IntBox* (i: LONGINT);
VAR
  str: ARRAY 21 OF CHAR;
BEGIN
  IntToStr(i, str);
  Ignore.Int( W.MessageBox(NIL,
    SYSTEM.VAL(W.PtrSTR, SYSTEM.ADR(str)), NIL, W.MB_OK)
  );
END IntBox;

BEGIN
  IF 0=W.AllocConsole() THEN END;
  hConOut := W.GetStdHandle(W.STD_OUTPUT_HANDLE);
END Debug.
