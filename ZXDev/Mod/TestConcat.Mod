(*$MAIN*) MODULE TestConcat; IMPORT Console;

CONST Str* = "String 1 "+ 0DX + 0AX + 0X + "String 2 " + '"' + "'" + 0FFX;
Str2* = "  '  ";
Str3* = '  "  ';

VAR str: ARRAY 13 OF CHAR;

BEGIN
	str := "Hello, ";
	str := str + "World";
	Console.WriteStr(str); Console.WriteLn;
	Console.WriteInt(LEN(str$)); Console.WriteLn;
END TestConcat.
