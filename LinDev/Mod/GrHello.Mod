MODULE GrHello; (*$MAIN*)

IMPORT Console, GrColors, GrScr, GrFonts;

BEGIN
  Console.Clear(GrColors.Orange);
  Console.SetColors(GrColors.LGreenOnYellow);
  Console.SetFont(GrFonts.ZxSpecRom8x8);
  Console.At(3, 3);
  Console.WriteStr("Hello World! ");
  Console.SetColors(GrColors.GreenOnBlack);
  Console.SetFont(GrFonts.MsDosCga8x8);
  Console.At(6, 6);
  Console.WriteStr("Hello World! ");
  GrScr.Update;
  GrScr.Close;
END GrHello.
