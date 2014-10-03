MODULE GrScr;	(** Versia for SDL *)
IMPORT SYSTEM, Sdl := SdlLib, Cfg := GrConfig, Ignore;

TYPE
  Color* = INTEGER;
  Coords = INTEGER;
VAR
  Screen-: Sdl.PSurface;
  MustLock-: BOOLEAN;
  ActualWidth-, ActualHeight-, VirtualWidth-, VirtualHeight-,
  ActualMaxX-, ActualMaxY- : Coords;
  DepthBits-: SHORTINT;
  AppTitle-: POINTER [1] TO ARRAY OF CHAR;

PROCEDURE Close* ;
BEGIN
  Sdl.Quit;
END Close;

PROCEDURE Update* ;
BEGIN
  Ignore.Int( Sdl.Flip(Screen) );
END Update;

BEGIN
  IF Sdl.Init(Sdl.INIT_VIDEO) < 0 THEN HALT(1) END;
  IF Cfg.AppTitle # NIL THEN
    Sdl.WM_SetCaption(SYSTEM.VAL(Sdl.PChar, SYSTEM.ADR(AppTitle)), NIL);
  END;
    Screen := Sdl.SetVideoMode (ActualWidth, ActualHeight,
      DepthBits, Sdl.SWSURFACE + Sdl.DOUBLEBUF);
  IF Screen = NIL THEN Sdl.Quit; HALT(1) END;
  MustLock := Sdl.MustLock(Screen);
END GrScr.