MODULE TestInPar;
IMPORT SYSTEM, Platform, Console;
TYPE
  Struct = RECORD a, b: INTEGER END;
  Struct1 = RECORD[1] a, b: INTEGER END;
  StructPtr = POINTER TO Struct;
  Struct1Ptr = POINTER TO Struct1;

VAR
  arr: ARRAY 50 OF CHAR;
	ptr: POINTER TO ARRAY OF CHAR;
	struct: Struct; structPtr: StructPtr;
	struct1: Struct1; struct1Ptr: Struct1Ptr;

(*
PROCEDURE A(IN a: INTEGER); BEGIN END A;
*)

PROCEDURE Write* (str: ARRAY OF CHAR);
BEGIN
  Console.WriteStr(str)
END Write;

PROCEDURE WriteIn* (IN str: ARRAY OF CHAR);
BEGIN
  Console.WriteStr(str); (*COPY("bla-bla-bla", str)*)
END WriteIn;

PROCEDURE Write1* (IN str: ARRAY[1] OF CHAR);
BEGIN
  Console.WriteStr(str)
END Write1;

PROCEDURE Write2* (str: ARRAY[1] OF CHAR);
BEGIN
  Console.WriteStr(str)
END Write2;

PROCEDURE WriteVar* (VAR str: ARRAY OF CHAR);
BEGIN
  Console.WriteStr(str); COPY("bla-bla-bla", str)
END WriteVar;

PROCEDURE StructIn* (IN str: Struct);
BEGIN
END StructIn;

PROCEDURE StructIn1* (IN str: Struct1);
BEGIN
END StructIn1;

PROCEDURE StructVar* (IN str: Struct);
BEGIN
END StructVar;

BEGIN (*$MAIN*)
  Write("Bla-bla-bla");
  WriteIn("Bla-bla-bla");
  WriteIn("a");
  Write1("Bla-bla-bla");
  Write2("Bla-bla-bla");

  COPY("Array", arr);
  Write(arr);
  WriteIn(arr);
  WriteIn(arr);
  Write1(arr);
  Write2(arr);
  WriteVar(arr);

  NEW(ptr, 100); COPY("Pointer", ptr^);
  Write(ptr^);
  WriteIn(ptr^);
  WriteIn(ptr^);
  Write1(ptr^);
  Write2(ptr^);
  WriteVar(ptr^);
(*
  StructIn(struct); StructIn(structPtr^);
  StructVar(struct); StructVar(structPtr^);
  StructIn1(struct1); StructIn1(struct1Ptr^);
*)
END TestInPar.
