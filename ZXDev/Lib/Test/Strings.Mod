MODULE TestStrings; (*$MAIN*)
IMPORT IO := Console, Str := Strings, P := Platform, Asm;

VAR
  str: ARRAY 3 OF SHORTCHAR;
  str2: ARRAY 10 OF SHORTCHAR;
  numbuf: ARRAY 7 OF SHORTCHAR;

PROCEDURE Length* (s: ARRAY OF SHORTCHAR): SHORTINT;
  VAR i: SHORTINT;
BEGIN
  i := 0; WHILE (i < LEN(s)) & (s[i] # 0X) DO INC(i) END;
  RETURN i
END Length;

PROCEDURE Check (n: SHORTINT; b: BOOLEAN);
BEGIN
  IF b THEN IO.WriteStr(numbuf)
  ELSE IO.WriteInt(n); IO.WriteStr(": FALSE") END;
  IO.WriteLn;
END Check;

BEGIN str2 := "GARBAGE!";
  str := "12"; str[2]:="s"; IO.WriteInt(Str.Length(str));
  IO.WriteCh(" "); IO.WriteInt(Length(str)); IO.WriteLn; IO.WriteLn;

  Check(0, Str.UIntToStr(0, numbuf));
  Check(10, Str.UIntToStr(10, numbuf));
  Check(555, Str.UIntToStr(555, numbuf));
  Check(9999, Str.UIntToStr(9999, numbuf));
  Check(32767, Str.UIntToStr(32767, numbuf));
  Check(P.ToSHORT(65535), Str.UIntToStr(P.ToSHORT(65535), numbuf));

  Check(0, Str.IntToStr(0, numbuf));
  Check(10, Str.IntToStr(10, numbuf));
  Check(500, Str.IntToStr(500, numbuf));
  Check(9000, Str.IntToStr(9000, numbuf));
  Check(30000, Str.IntToStr(30000, numbuf));
  Check(-10, Str.IntToStr(-10, numbuf));
  Check(-555, Str.IntToStr(-555, numbuf));
  Check(-9999, Str.IntToStr(-9999, numbuf));
  Check(-32767, Str.IntToStr(-32767, numbuf));
  Check(-32768, Str.IntToStr(-32768, numbuf));

  Asm.Code("LD HL,#10072"); Asm.Code("EXX");
END TestStrings.
