(*/////////////////////////////////////////////////////////////////////
//                         W  I  N  D  O  W  S
/////////////////////////////////////////////////////////////////////*)

(* -- Set of window-related utility functions. -- *)

MODULE KolWindows;
IMPORT S := SYSTEM, W := WinApi, Typ := KolTypes;

CONST
  Wv31*         =  0;
  Wv95*         =  1;
  Wv98*         =  2;
  WvME*         =  3;
  WvNT*         =  4;
  WvY2K*        =  5;
  WvXP*         =  6;
  WvServer2003* =  7;
  WvVista*      =  8;
  WvSeven*      =  9;
  Wv8*          = 10;

TYPE
  TWindowsVersion* = Typ.Byte;
  TWindowsVersions* = SET;
  (* Set of Windows version (e.g. to define a range of versions supported by the
     application). *)

VAR
  saveWinVer, saveIs64Bit: Typ.UByte;

PROCEDURE WinVer* (): TWindowsVersion;
VAR
  majorVersion, minorVersion: Typ.UByte;
  dwVersion: Typ.Integer;
BEGIN
  IF saveWinVer = 0FFX THEN
    dwVersion := W.GetVersion();
    majorVersion := CHR( dwVersion );
    minorVersion := CHR( dwVersion DIV 100H );
    IF dwVersion >= 0 THEN
      saveWinVer := CHR(WvNT);
      IF majorVersion >= 6X THEN
        IF minorVersion >= 2X THEN
          saveWinVer := CHR(Wv8);
        ELSIF minorVersion = 1X THEN
          saveWinVer := CHR(WvSeven);
        ELSE
          saveWinVer := CHR(WvVista);
        END;
      ELSE
        IF majorVersion >= 5X THEN
          IF minorVersion >= 1X THEN
            saveWinVer := CHR(WvXP);
            IF minorVersion >= 2X THEN
              saveWinVer := CHR(WvServer2003);
            END;
          ELSE
            saveWinVer := CHR(WvY2K);
          END;
        END;
      END;
    ELSE
      saveWinVer := CHR(Wv95);
      IF (majorVersion > 4X) OR
         (majorVersion = 4X) & (minorVersion >= 10X)
      THEN
        saveWinVer := CHR(Wv98);
        IF (majorVersion = 4X) & (minorVersion >= 5AX) THEN
          saveWinVer := CHR(WvME);
        END;
      ELSE
        IF majorVersion <= 3X THEN
          saveWinVer := CHR(Wv31)
        END;
      END;
    END;
  END;
  RETURN saveWinVer
END WinVer;

PROCEDURE IsWinVer* (ver: TWindowsVersions): BOOLEAN;
(* Returns TRUE if Windows version is in given range of values. *)
BEGIN
  RETURN WinVer() IN ver
END IsWinVer;

PROCEDURE Is64Bit* (): BOOLEAN;
CONST
  False = 0;
TYPE
  Bool = W.BOOL;
  Handle = W.HANDLE;
  ISWOW64PROCESS = PROCEDURE(hProcess: Handle; VAR Wow64Process: Bool): Bool;
VAR
  IsWow64Process: ISWOW64PROCESS; wow64Process: Bool;
BEGIN
  IF SIZE(S.PTR) = 8 THEN RETURN TRUE END;
  IF saveIs64Bit = 0FFX THEN
    IsWow64Process := S.VAL(ISWOW64PROCESS, W.GetProcAddress(
      W.GetModuleHandle(S.VAL(W.PtrSTR, S.ADR("Kernel32"))),
      S.VAL(W.PtrSTR, S.ADR("IsWow64Process")))
    );
    saveIs64Bit := S.VAL(Typ.UByte,
      (IsWow64Process # NIL) &
      (IsWow64Process(W.GetCurrentProcess(), wow64Process) # False) &
      (wow64Process # False)
    );
  END;
  RETURN S.VAL(BOOLEAN, saveIs64Bit)
END Is64Bit;

BEGIN
  saveWinVer := 0FFX; saveIs64Bit := 0FFX;
END KolWindows.