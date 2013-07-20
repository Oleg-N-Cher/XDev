MODULE GrScr;	(** Versia for SDL *)
IMPORT S := SYSTEM, Sdl := SdlLib, Cfg := GrConfig;

VAR
  Screen: Sdl.PSurface;
  (*videoInfo: Sdl.PVideoInfo;*)

PROCEDURE Close* ;
BEGIN
  Sdl.Quit;
END Close;

BEGIN
  IF Sdl.Init(Sdl.INIT_VIDEO) < 0 THEN HALT(1) END;
  IF Cfg.AppTitle # "" THEN
    Sdl.WM_SetCaption(S.VAL(Sdl.PChar, S.ADR(Cfg.AppTitle)), NIL);
  END;
  (*videoInfo := Sdl.GetVideoInfo();
  IF videoInfo.hw_available THEN
    Screen := Sdl.SetVideoMode (Cfg.ActualWidth, Cfg.ActualHeight,
    Cfg.DepthBits, {Sdl.HWSURFACE});
  ELSE*)
    Screen := Sdl.SetVideoMode (Cfg.ActualWidth, Cfg.ActualHeight,
    Cfg.DepthBits, Sdl.SWSURFACE);(*
  END;*)
  IF Screen = NIL THEN Sdl.Quit; HALT(1) END;
END GrScr.