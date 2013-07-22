MODULE GrScr;	(** Versia for SDL *)
IMPORT S := SYSTEM, Sdl := SdlLib, Cfg := GrConfig;

TYPE
  Color* = INTEGER;
VAR
  Screen-: Sdl.PSurface;
  mustLock-: BOOLEAN;

  Black-, Blue-, Green-, Cyan-, Red-, Magenta-, Olive-, White-, Gray,
  LightBlue-, LightGreen-, LightCyan-, LightRed-, LightMagenta-,
  Yellow-, LightWhite-, Orange-: Color;

PROCEDURE Close* ;
BEGIN
  Sdl.Quit;
END Close;

BEGIN
  IF Sdl.Init(Sdl.INIT_VIDEO) < 0 THEN HALT(1) END;
  IF Cfg.AppTitle # "" THEN
    Sdl.WM_SetCaption(S.VAL(Sdl.PChar, S.ADR(Cfg.AppTitle)), NIL);
  END;
    Screen := Sdl.SetVideoMode (Cfg.ActualWidth, Cfg.ActualHeight,
      Cfg.DepthBits, Sdl.SWSURFACE);
  IF Screen = NIL THEN Sdl.Quit; HALT(1) END;
  mustLock := Sdl.MustLock(Screen);

  Black        := Sdl.MapRGB(Screen.format,  0,  0,  0);
  Blue         := Sdl.MapRGB(Screen.format,  0,  0,128);
  Green        := Sdl.MapRGB(Screen.format,  0,128,  0);
  Cyan         := Sdl.MapRGB(Screen.format,  0,128,128);
  Red          := Sdl.MapRGB(Screen.format,128,  0,  0);
  Magenta      := Sdl.MapRGB(Screen.format,128,  0,128);
  Olive        := Sdl.MapRGB(Screen.format,128,128,  0);
  White        := Sdl.MapRGB(Screen.format,192,192,192);
  Gray         := Sdl.MapRGB(Screen.format,128,128,128);
  LightBlue    := Sdl.MapRGB(Screen.format,  0,  0,255);
  LightGreen   := Sdl.MapRGB(Screen.format,  0,255,  0);
  LightCyan    := Sdl.MapRGB(Screen.format,  0,255,255);
  LightRed     := Sdl.MapRGB(Screen.format,255,  0,  0);
  LightMagenta := Sdl.MapRGB(Screen.format,255,  0,255);
  Yellow       := Sdl.MapRGB(Screen.format,255,255,  0);
  LightWhite   := Sdl.MapRGB(Screen.format,255,255,255);
  Orange       := Sdl.MapRGB(Screen.format,255,128,  0);
END GrScr.