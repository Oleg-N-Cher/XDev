(* Copyright (C) 2012-2013 Oleg N. Cher, VEDAsoft Oberon Club *)
(* http://zx.oberon2.ru *)

MODULE Is64BitWindows;
IMPORT
  SYSTEM, WinApi, IO := Console;

CONST
  Is64Bit = (SIZE(SYSTEM.PTR) = 8);

PROCEDURE Is64BitWindows* (): BOOLEAN;
CONST
  False = 0;
TYPE
  Bool = WinApi.BOOL;
  Handle = WinApi.HANDLE;
  ISWOW64PROCESS = PROCEDURE(hProcess: Handle; VAR Wow64Process: Bool): Bool;
VAR
  IsWow64Process: ISWOW64PROCESS; wow64Process: Bool;
BEGIN
  IF Is64Bit THEN RETURN TRUE END;
  IsWow64Process := SYSTEM.VAL(ISWOW64PROCESS, WinApi.GetProcAddress(
    WinApi.GetModuleHandle(SYSTEM.VAL(WinApi.PtrSTR, SYSTEM.ADR("Kernel32"))),
    SYSTEM.VAL(WinApi.PtrSTR, SYSTEM.ADR("IsWow64Process")))
  );
  RETURN (IsWow64Process # NIL)
    & (IsWow64Process(WinApi.GetCurrentProcess(), wow64Process) # False)
    & (wow64Process # False)
END Is64BitWindows;

BEGIN (*$MAIN*)
  IO.WriteStr("Runned under Windows ");
  IF Is64Bit OR Is64BitWindows() THEN
    IO.WriteStrLn("64 bit");
  ELSE
    IO.WriteStrLn("32 bit");
  END;
END Is64BitWindows.