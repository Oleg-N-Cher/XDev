(* Flower example (Pascal/Fast, UK-NC) for ZXDev/Oberon-2 *)
(* Copyright (C) 2013 Oleg N. Cher, VEDAsoft Oberon Club *)
(* http://zx.oberon2.ru *)

MODULE Flower;
IMPORT GrApp, GrConsole, G := GrPixel, Math, Input;

VAR
  KD, MD, x0, y0: INTEGER;

PROCEDURE Round (x: REAL): INTEGER;
BEGIN
  RETURN SHORT(ENTIER(x + 0.5))
END Round;

PROCEDURE Flower (x, y, radius, n: INTEGER; a1, a3, a5: REAL);
CONST
  p = 3.14159 / 180.0;
VAR
  b1, b3, b5, q, r, dg, rd, cosRd, sinRd: REAL;
BEGIN
  q := a1 + a3 + a5;
  b1 := radius * a1 / q; b3 := radius * a3 / q; b5 := radius * a5 / q;
  dg := 360.0;
  REPEAT
    rd := dg * p; q := n * rd;
    r := ABS(
      b1 * Math.Sin(q * 0.5) + b3 * Math.Sin(q * 1.5) + b5 * Math.Sin(q * 2.5));
    cosRd := Math.Cos(rd); sinRd := Math.Sin(rd);
    G.Line(x, y, x + Round(r*cosRd), y + Round(r*sinRd));
    G.Dot(x + Round((r+4.0)*cosRd), y + Round((r+4.0)*sinRd));
    dg := dg - 0.5;
  UNTIL dg = 0.0;
  q := radius / 10.0;
  REPEAT
    n := 345; G.Ink(GrApp.Green);
    REPEAT
      G.Dot(
        x + Round(q*Math.Cos(n*p)), y + Round(q*Math.Sin(n*p)));
      n := n - 15;
    UNTIL n < 0;
    q := q - radius / 50.0
  UNTIL q < 0.0;
END Flower;

BEGIN (*$MAIN*)
  GrConsole.Clear(GrApp.Green); G.Ink(GrApp.Red);
  x0 := (GrApp.ActualMaxX + 1) DIV 2;
  y0 := (GrApp.ActualMaxY + 1) DIV 2;
  Flower(x0, y0, y0 DIV 2 * 3, 5, 1.0, 0.25, 0.1);
  (*c := ReadKey;*)
  GrApp.Redraw;
  IF Input.Read() = " " THEN END;
  GrApp.Close
END Flower.
