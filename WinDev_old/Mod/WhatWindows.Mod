(* Copyright (C) 2012-2013 Oleg N. Cher, VEDAsoft Oberon Club *)
(* http://zx.oberon2.ru *)

MODULE WhatWindows; (*$MAIN*)
IMPORT
  SYSTEM, Win := KolWindows, IO := Console;

CONST
  Is64Bit = (SIZE(SYSTEM.PTR) = 8);

PROCEDURE ShowBit;
BEGIN
  IF Is64Bit OR Win.Is64Bit() THEN
    IO.WriteStrLn(" (64 bit)");
  ELSE
    IO.WriteStrLn(" (32 bit)");
  END;
END ShowBit;

BEGIN
  IO.WriteStr("Runned under Windows ");
  CASE Win.WinVer() OF
  | Win.Wv95         : IO.WriteStr("95");
  | Win.Wv98         : IO.WriteStr("98");
  | Win.WvME         : IO.WriteStr("ME");
  | Win.WvNT         : IO.WriteStr("NT");
  | Win.WvY2K        : IO.WriteStr("2000");
  | Win.WvXP         : IO.WriteStr("XP"); ShowBit;
  | Win.WvServer2003 : IO.WriteStr("Server 2003"); ShowBit;
  | Win.WvVista      : IO.WriteStr("Vista"); ShowBit;
  | Win.WvSeven      : IO.WriteStr("7"); ShowBit;
  | Win.Wv8          : IO.WriteStr("8"); ShowBit;
  ELSE END;
END WhatWindows.