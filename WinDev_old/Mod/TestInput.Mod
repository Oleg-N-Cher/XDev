MODULE TestInput; (*$MAIN*)

IMPORT Console, GrColors, GrScr, GrFonts, Input;

VAR
  key: Input.Key;
BEGIN
  Console.Clear(GrColors.Orange);
  Console.SetColors(GrColors.LGreenOnGreen);
  Console.SetFont(GrFonts.ZxSpecRom8x8);
  Console.At(0, 0);
  Console.WriteStr(" Please type your name: ");
  Console.SetColors(GrColors.BlackOnRed);
  Console.SetFont(GrFonts.MsDosCga8x8);
  Console.At(0, 2);
  LOOP
    GrScr.Update;
    key := Input.Read(); Console.WriteCh(key); (*Console.WriteInt(ORD(key));*)
  END;
END TestInput.
