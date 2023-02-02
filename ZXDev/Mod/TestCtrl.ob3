MODULE TestCtrl;
IMPORT B := Basic, Key := Control, Laser := Laser2;

VAR
  pressed: SET;
BEGIN (*$MAIN*)
  B.CLS;
  LOOP
    pressed := Key.Get();
    IF Key.Left IN pressed THEN B.PAPER(B.Green) ELSE B.PAPER(B.Black) END;
    Laser.SETV(0, 8, 10, 8);
    IF Key.Right IN pressed THEN B.PAPER(B.Yellow) ELSE B.PAPER(B.Black) END;
    Laser.SETV(22, 8, 10, 8);
    IF Key.Up IN pressed THEN B.PAPER(B.Cyan) ELSE B.PAPER(B.Black) END;
    Laser.SETV(10, 0, 12, 8);
    IF Key.Down IN pressed THEN B.PAPER(B.Magenta) ELSE B.PAPER(B.Black) END;
    Laser.SETV(10, 16, 12, 8);
    IF Key.Fire IN pressed THEN B.BORDER(B.Red) ELSE B.BORDER(B.Black) END;
  END;
END TestCtrl.