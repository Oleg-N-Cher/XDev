MODULE GrScr;	(** Versia for SDL *)
IMPORT SYSTEM, Sdl := SdlLib, Cfg := GrConfig;

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

PROCEDURE TimeLeft (): INTEGER;
CONST
  TickInterval = 60;
VAR
  nextTime, now: INTEGER;
BEGIN
  nextTime := 0;
  now := Sdl.GetTicks();
  IF nextTime <= now THEN
    nextTime := now + TickInterval;
    RETURN 0
  END;
  RETURN nextTime-now
END TimeLeft;

PROCEDURE WaitAClick;
VAR
  event: Sdl.Event;
  done: BOOLEAN;
BEGIN
  (* Wait for a keystroke *)
  done := FALSE;
  WHILE ( ~ done ) DO
    (* Check for events *)
    Sdl.Delay(10);
    LOOP
      IF Sdl.WaitEvent(event) = 0 THEN EXIT END;
      CASE SYSTEM.VAL(CHAR, event.type) OF
        Sdl.KEYDOWN:
          (* Any key press quits the app... *)
          done := TRUE;
          EXIT
      | Sdl.QUITEV:
          done := TRUE;
          EXIT
      | Sdl.MOUSEBUTTONDOWN, Sdl.MOUSEBUTTONUP:
          done := TRUE;
          EXIT
        ELSE
          EXIT
        END
    END;
    Sdl.PumpEvents;
    Sdl.Delay(TimeLeft())
  END
END WaitAClick;

PROCEDURE Close* ;
BEGIN
  WaitAClick; Sdl.Quit;
END Close;

PROCEDURE Update* ;
BEGIN
  IF Sdl.Flip(Screen) THEN END;
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