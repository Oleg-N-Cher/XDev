MODULE Strings;

TYPE
  CHAR = SHORTCHAR;

PROCEDURE Length* (s: ARRAY OF CHAR): SHORTINT;
  VAR i: SHORTINT;
BEGIN
  i := 0; WHILE (i < LEN(s)) & (s[i] # 0X) DO INC(i) END;
  RETURN i
END Length;

PROCEDURE StrToInt* (str: ARRAY OF CHAR; VAR result: SHORTINT): BOOLEAN;
(* MIN(SHORTINT) not supported! *)
VAR
  pos, sign: BYTE; ch: CHAR; prev: SHORTINT;
BEGIN
  result := 0; pos := 0; sign := 1;
  WHILE pos < LEN(str) DO
    ch := str[pos];
    CASE ch OF
    |      "-": IF pos = 0 THEN sign := -1 ELSE RETURN FALSE END;
    | "0".."9": prev := result; result := result*10 + ORD(ch) - ORD("0");
                IF result < prev THEN (* Overflow! *) RETURN FALSE END;
    |       0X: result := result*sign; RETURN (pos > 0)
    ELSE RETURN FALSE
    END;
    INC(pos);
  END;
  result := result*sign; RETURN (pos > 0)
END StrToInt;

END Strings.