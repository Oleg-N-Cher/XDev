(*$MAIN*) MODULE TestFontRus; (*$866*)
IMPORT b := Basic, GrFonts, io := Console;

BEGIN
  b.Init; io.Clear(io.Black); io.SetColors(io.YellowOnGreen);
  b.FONT(GrFonts.MsDosCgaRus8x8);
  io.WriteStr("ฺฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฟ"); io.WriteLn;
  io.WriteStr("ณฒฑฐเจขฅโ, ‘ ขฅซจฉ!ฐฑฒณ"); io.WriteLn;
  io.WriteStr("ภฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤู"); io.WriteLn;
  io.SetColors(io.CyanOnBlue);
  io.At(2, 4); io.WriteStr("ษออออออออออออออออออออออป");
  io.At(2, 5); io.WriteStr("บ   เจขฅโ, ‘ ขฅซจฉ!   บ");
  io.At(2, 6); io.WriteStr("ศออออออออออออออออออออออผ");
  io.SetColors(io.RedOnYellow);
  io.At(5, 8); io.WriteStr("ึฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤท");
  io.At(5, 9); io.WriteStr("บ   เจขฅโ, ‘ ขฅซจฉ!   บ");
  io.At(5,10); io.WriteStr("ำฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฝ");
  io.SetColors(io.GreenOnBlack);
  io.At(8,12); io.WriteStr("ีออออออออออออออออออออออธ");
  io.At(8,13); io.WriteStr("ณ   เจขฅโ, ‘ ขฅซจฉ!   ณ");
  io.At(8,14); io.WriteStr("ิออออออออออออออออออออออพ");
  b.PAUSE(0);
  b.Quit
END TestFontRus.
