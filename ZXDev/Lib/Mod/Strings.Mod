MODULE Strings;

PROCEDURE StrToInt* (IN str: ARRAY OF CHAR; VAR result: INTEGER): BOOLEAN;
(* MIN(INTEGER) not supported! *)
VAR
  pos, sign: SHORTINT; ch: CHAR; prev: INTEGER;
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