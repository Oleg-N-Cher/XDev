MODULE TestSdl2; (*$MAIN*)
IMPORT Sdl := Sdl2Lib;

VAR
  Screen: Sdl.Window;

BEGIN
  IF Sdl.Init(Sdl.INIT_VIDEO) < 0 THEN HALT(1) END;
  Screen := Sdl.CreateWindow(NIL, 320, 240, 320, 240, 0);

  IF Screen = NIL THEN Sdl.Quit; HALT(1) END;

  Sdl.Delay(5000);
  Sdl.DestroyWindow(Screen);
  Sdl.Quit
END TestSdl2.
