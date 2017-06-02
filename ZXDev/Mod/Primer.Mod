(*$MAIN*) MODULE Primer; IMPORT b := Basic;

CONST
  Message = " Hello World of Nice Programs!";
  Copyright = "(c) VEDAsoft '2017";

BEGIN
  b.Init;
  b.BORDER(b.Green); b.PAPER(b.Black); b.INK(b.White); b.CLS;

  b.PLOT(120, 96);
  b.DRAW(16, 0); b.DRAW(0, -16); b.DRAW(-16, 0); b.DRAW(0, 16);
  b.INK(b.Red); b.CIRCLE(128, 88, 30);
  b.INK(b.Green); b.CIRCLE(128, 88, 50);
  b.INK(b.Yellow); b.CIRCLE(128, 88, 70);

  b.BRIGHT(b.On); b.PRSTR(Message);
  b.AT(21, 14); b.INK(b.Cyan); b.PRSTR(Copyright);
  b.PAUSE(b.WaitAKey);
  b.Quit
END Primer.
