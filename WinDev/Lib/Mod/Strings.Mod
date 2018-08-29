MODULE Strings;

PROCEDURE Length* (str: ARRAY OF SHORTCHAR): INTEGER;
VAR
  len: INTEGER;
BEGIN
  len := 0;
  WHILE (len < LEN(str)) & (str[len] # 0X) DO INC(len) END;
  RETURN len
END Length;

END Strings.
