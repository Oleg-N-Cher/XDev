MODULE GrColors;	(** Versia for SDL *)
IMPORT Sdl := SdlLib, GrScr;

VAR
  Black-, Blue-, Green-, Cyan-, Red-, Magenta-, Olive-, White-, Gray,
  LightBlue-, LightGreen-, LightCyan-, LightRed-, LightMagenta-,
  Yellow-, LightWhite-, Orange- : GrScr.Color;

BEGIN
  Black        := Sdl.MapRGB(GrScr.Screen.format,   0,   0,   0);
  Blue         := Sdl.MapRGB(GrScr.Screen.format,   0,   0, 128);
  Green        := Sdl.MapRGB(GrScr.Screen.format,   0, 128,   0);
  Cyan         := Sdl.MapRGB(GrScr.Screen.format,   0, 128, 128);
  Red          := Sdl.MapRGB(GrScr.Screen.format, 128,   0,   0);
  Magenta      := Sdl.MapRGB(GrScr.Screen.format, 128,   0, 128);
  Olive        := Sdl.MapRGB(GrScr.Screen.format, 128, 128,   0);
  White        := Sdl.MapRGB(GrScr.Screen.format, 192, 192, 192);
  Gray         := Sdl.MapRGB(GrScr.Screen.format, 128, 128, 128);
  LightBlue    := Sdl.MapRGB(GrScr.Screen.format,   0,   0, 255);
  LightGreen   := Sdl.MapRGB(GrScr.Screen.format,   0, 255,   0);
  LightCyan    := Sdl.MapRGB(GrScr.Screen.format,   0, 255, 255);
  LightRed     := Sdl.MapRGB(GrScr.Screen.format, 255,   0,   0);
  LightMagenta := Sdl.MapRGB(GrScr.Screen.format, 255,   0, 255);
  Yellow       := Sdl.MapRGB(GrScr.Screen.format, 255, 255,   0);
  LightWhite   := Sdl.MapRGB(GrScr.Screen.format, 255, 255, 255);
  Orange       := Sdl.MapRGB(GrScr.Screen.format, 255, 128,   0);
END GrColors.