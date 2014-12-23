MODULE GrApp;	(** Ver. for SDL *)
IMPORT SYSTEM, Sdl := SdlLib, Cfg := GrConfig, Ignore;

TYPE
  Color* = INTEGER;
  Colors* = RECORD [1] paper*, ink*: Color END;
  Coords = INTEGER;

VAR
  Screen-: Sdl.PSurface;
  MustLock-: BOOLEAN;
  ActualWidth-, ActualHeight-, VirtualWidth-, VirtualHeight-,
  ActualMaxX-, ActualMaxY- : Coords;
  DepthBits-: SHORTINT;
  AppTitle-: POINTER [1] TO ARRAY OF CHAR;

  Black-, Blue-, Green-, Cyan-, Red-, Magenta-, Olive-, White-,
  Gray-, LightBlue-, LightGreen-, LightCyan-, LightRed-,
  LightMagenta-, Yellow-, LightWhite-, Orange- : Color;

  BlackOnBlack-, BlueOnBlack-, GreenOnBlack-, CyanOnBlack-,
  RedOnBlack-, MagentaOnBlack-, OliveOnBlack-, WhiteOnBlack-,
  GrayOnBlack-, LBlueOnBlack-, LGreenOnBlack-, LCyanOnBlack-,
  LRedOnBlack-, LMagentaOnBlack-, YellowOnBlack-, LWhiteOnBlack-,
  OrangeOnBlack-,

  BlackOnBlue-, BlueOnBlue-, GreenOnBlue-, CyanOnBlue-,
  RedOnBlue-, MagentaOnBlue-, OliveOnBlue-, WhiteOnBlue-,
  GrayOnBlue-, LBlueOnBlue-, LGreenOnBlue-, LCyanOnBlue-,
  LRedOnBlue-, LMagentaOnBlue-, YellowOnBlue-, LWhiteOnBlue-,
  OrangeOnBlue-,

  BlackOnGreen-, BlueOnGreen-, GreenOnGreen-, CyanOnGreen-,
  RedOnGreen-, MagentaOnGreen-, OliveOnGreen-, WhiteOnGreen-,
  GrayOnGreen-, LBlueOnGreen-, LGreenOnGreen-, LCyanOnGreen-,
  LRedOnGreen-, LMagentaOnGreen-, YellowOnGreen-, LWhiteOnGreen-,
  OrangeOnGreen-,

  BlackOnCyan-, BlueOnCyan-, GreenOnCyan-, CyanOnCyan-,
  RedOnCyan-, MagentaOnCyan-, OliveOnCyan-, WhiteOnCyan-,
  GrayOnCyan-, LBlueOnCyan-, LGreenOnCyan-, LCyanOnCyan-,
  LRedOnCyan-, LMagentaOnCyan-, YellowOnCyan-, LWhiteOnCyan-,
  OrangeOnCyan-,

  BlackOnRed-, BlueOnRed-, GreenOnRed-, CyanOnRed-,
  RedOnRed-, MagentaOnRed-, OliveOnRed-, WhiteOnRed-,
  GrayOnRed-, LBlueOnRed-, LGreenOnRed-, LCyanOnRed-,
  LRedOnRed-, LMagentaOnRed-, YellowOnRed-, LWhiteOnRed-,
  OrangeOnRed-,

  BlackOnMagenta-, BlueOnMagenta-, GreenOnMagenta-, CyanOnMagenta-,
  RedOnMagenta-, MagentaOnMagenta-, OliveOnMagenta-, WhiteOnMagenta-,
  GrayOnMagenta-, LBlueOnMagenta-, LGreenOnMagenta-, LCyanOnMagenta-,
  LRedOnMagenta-, LMagentaOnMagenta-, YellowOnMagenta-, LWhiteOnMagenta-,
  OrangeOnMagenta-,

  BlackOnOlive-, BlueOnOlive-, GreenOnOlive-, CyanOnOlive-,
  RedOnOlive-, MagentaOnOlive-, OliveOnOlive-, WhiteOnOlive-,
  GrayOnOlive-, LBlueOnOlive-, LGreenOnOlive-, LCyanOnOlive-,
  LRedOnOlive-, LMagentaOnOlive-, YellowOnOlive-, LWhiteOnOlive-,
  OrangeOnOlive-,

  BlackOnWhite-, BlueOnWhite-, GreenOnWhite-, CyanOnWhite-,
  RedOnWhite-, MagentaOnWhite-, OliveOnWhite-, WhiteOnWhite-,
  GrayOnWhite-, LBlueOnWhite-, LGreenOnWhite-, LCyanOnWhite-,
  LRedOnWhite-, LMagentaOnWhite-, YellowOnWhite-, LWhiteOnWhite-,
  OrangeOnWhite-,

  BlackOnGray-, BlueOnGray-, GreenOnGray-, CyanOnGray-,
  RedOnGray-, MagentaOnGray-, OliveOnGray-, WhiteOnGray-,
  GrayOnGray-, LBlueOnGray-, LGreenOnGray-, LCyanOnGray-,
  LRedOnGray-, LMagentaOnGray-, YellowOnGray-, LWhiteOnGray-,
  OrangeOnGray-,

  BlackOnLBlue-, BlueOnLBlue-, GreenOnLBlue-, CyanOnLBlue-,
  RedOnLBlue-, MagentaOnLBlue-, OliveOnLBlue-, WhiteOnLBlue-,
  GrayOnLBlue-, LBlueOnLBlue-, LGreenOnLBlue-, LCyanOnLBlue-,
  LRedOnLBlue-, LMagentaOnLBlue-, YellowOnLBlue-, LWhiteOnLBlue-,
  OrangeOnLBlue-,

  BlackOnLGreen-, BlueOnLGreen-, GreenOnLGreen-, CyanOnLGreen-,
  RedOnLGreen-, MagentaOnLGreen-, OliveOnLGreen-, WhiteOnLGreen-,
  GrayOnLGreen-, LBlueOnLGreen-, LGreenOnLGreen-, LCyanOnLGreen-,
  LRedOnLGreen-, LMagentaOnLGreen-, YellowOnLGreen-, LWhiteOnLGreen-,
  OrangeOnLGreen-,

  BlackOnLCyan-, BlueOnLCyan-, GreenOnLCyan-, CyanOnLCyan-,
  RedOnLCyan-, MagentaOnLCyan-, OliveOnLCyan-, WhiteOnLCyan-,
  GrayOnLCyan-, LBlueOnLCyan-, LGreenOnLCyan-, LCyanOnLCyan-,
  LRedOnLCyan-, LMagentaOnLCyan-, YellowOnLCyan-, LWhiteOnLCyan-,
  OrangeOnLCyan-,

  BlackOnLRed-, BlueOnLRed-, GreenOnLRed-, CyanOnLRed-,
  RedOnLRed-, MagentaOnLRed-, OliveOnLRed-, WhiteOnLRed-,
  GrayOnLRed-, LBlueOnLRed-, LGreenOnLRed-, LCyanOnLRed-,
  LRedOnLRed-, LMagentaOnLRed-, YellowOnLRed-, LWhiteOnLRed-,
  OrangeOnLRed-,

  BlackOnLMagenta-, BlueOnLMagenta-, GreenOnLMagenta-, CyanOnLMagenta-,
  RedOnLMagenta-, MagentaOnLMagenta-, OliveOnLMagenta-, WhiteOnLMagenta-,
  GrayOnLMagenta-, LBlueOnLMagenta-, LGreenOnLMagenta-, LCyanOnLMagenta-,
  LRedOnLMagenta-, LMagentaOnLMagenta-, YellowOnLMagenta-, LWhiteOnLMagenta-,
  OrangeOnLMagenta-,

  BlackOnYellow-, BlueOnYellow-, GreenOnYellow-, CyanOnYellow-,
  RedOnYellow-, MagentaOnYellow-, OliveOnYellow-, WhiteOnYellow-,
  GrayOnYellow-, LBlueOnYellow-, LGreenOnYellow-, LCyanOnYellow-,
  LRedOnYellow-, LMagentaOnYellow-, YellowOnYellow-, LWhiteOnYellow-,
  OrangeOnYellow-,

  BlackOnLWhite-, BlueOnLWhite-, GreenOnLWhite-, CyanOnLWhite-,
  RedOnLWhite-, MagentaOnLWhite-, OliveOnLWhite-, WhiteOnLWhite-,
  GrayOnLWhite-, LBlueOnLWhite-, LGreenOnLWhite-, LCyanOnLWhite-,
  LRedOnLWhite-, LMagentaOnLWhite-, YellowOnLWhite-, LWhiteOnLWhite-,
  OrangeOnLWhite-,

  BlackOnOrange-, BlueOnOrange-, GreenOnOrange-, CyanOnOrange-,
  RedOnOrange-, MagentaOnOrange-, OliveOnOrange-, WhiteOnOrange-,
  GrayOnOrange-, LBlueOnOrange-, LGreenOnOrange-, LCyanOnOrange-,
  LRedOnOrange-, LMagentaOnOrange-, YellowOnOrange-, LWhiteOnOrange-

    : Colors;

PROCEDURE Close* ;
BEGIN
  Sdl.Quit;
END Close;

PROCEDURE FillArea* (color: Color);
BEGIN
  IF MustLock & (Sdl.LockSurface(Screen) = 0) THEN RETURN END;
  (* dstrect is NIL, the whole surface will be filled with color. *)
  Ignore.Int(Sdl.FillRect(Screen, NIL, color));
  IF MustLock THEN Sdl.UnlockSurface(Screen) END;
END FillArea;

PROCEDURE Redraw* ;
BEGIN
  Ignore.Int( Sdl.Flip(Screen) );
END Redraw;

BEGIN
  IF Sdl.Init(Sdl.INIT_VIDEO) < 0 THEN HALT(1) END;
  IF Cfg.AppTitle # NIL THEN
    Sdl.WM_SetCaption(SYSTEM.VAL(Sdl.PChar, SYSTEM.ADR(AppTitle)), NIL);
  END;
    Screen := Sdl.SetVideoMode (ActualWidth, ActualHeight,
      DepthBits, Sdl.SWSURFACE + Sdl.DOUBLEBUF);
  IF Screen = NIL THEN Sdl.Quit; HALT(1) END;
  MustLock := Sdl.MustLock(Screen);
END GrApp.
