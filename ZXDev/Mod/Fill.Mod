(*$MAIN*) MODULE Fill; IMPORT b := Basic;
BEGIN
  b.Init;
  b.POKE(23693, 56); b.BORDER(b.White); b.CLS;
  b.PLOT(0, 0); b.DRAW(255, 0); b.PLOT(128, 0); b.DRAW(0, 175);
  b.CIRCLEROM(60, 88, 60); b.CIRCLEROM(194, 88, 60);
  b.PAINT(1, 17, b.Blue); b.PAINT(250, 17, b.Red);
  b.PAUSE(100);
  b.CLS; b.CIRCLEROM(128, 88, 87); b.PAINT(128, 18, b.Green);
  b.PAUSE(b.WaitAKey);
  b.Quit
END Fill.
