MODULE Strings; (*$MAIN*)
IMPORT IO := Console, Str := Strings;

VAR
  str: ARRAY 3 OF SHORTCHAR; str2: ARRAY 10 OF SHORTCHAR;

PROCEDURE Length* (s: ARRAY OF SHORTCHAR): SHORTINT;
  VAR i: SHORTINT;
BEGIN
  i := 0; WHILE (i < LEN(s)) & (s[i] # 0X) DO INC(i) END;
  RETURN i
END Length;

BEGIN str2 := "GARBAGE!";
  str := "12"; str[2]:="s";  IO.WriteInt(Str.Length(str));
  IO.WriteLn;
  IO.WriteInt(Length(str));
END Strings.
