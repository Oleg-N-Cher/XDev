(* Flower example (Pascal/Fast, UK-NC) for ZXDev/Oberon-2 *)
(* Copyright (C) 2013 Oleg N. Cher, VEDAsoft Oberon Club *)
(* http://zx.oberon2.ru *)

MODULE Flower;
IMPORT G := Graph, Math;

VAR
  KD, MD, x0, y0: SHORTINT;

PROCEDURE Flower (x, y, radius, n: SHORTINT; a1, a3, a5: SHORTREAL);
CONST
  p = Math.Pi / 180;
VAR
  b1, b3, b5, q, r, dg, rd, cosRd, sinRd: SHORTREAL;
BEGIN
  q := a1 + a3 + a5;
  b1 := radius * a1 / q; b3 := radius * a3 / q; b5 := radius * a5 / q;
  dg := 360;
  REPEAT
    rd := dg * p; q := n * rd;
    r := ABS(
      b1 * Math.Sin(q * 0.5) + b3 * Math.Sin(q * 1.5) + b5 * Math.Sin(q * 2.5));
    cosRd := Math.Cos(rd); sinRd := Math.Sin(rd);
    G.Line(x, y, x + SHORT(ENTIER(r*cosRd)), y + SHORT(ENTIER(r*sinRd)));
    G.PutPixel(x + SHORT(ENTIER((r+4)*cosRd)), y + SHORT(ENTIER((r+4)*sinRd)));
    dg := dg - 0.5;
  UNTIL dg = 0;
  q := radius / 10;
  REPEAT
    n := 345; G.SetColor(G.Green);
    REPEAT
      G.PutPixel(
        x + SHORT(ENTIER(q*Math.Cos(n*p))), y + SHORT(ENTIER(q*Math.Sin(n*p))));
      n := n - 15;
    UNTIL n < 0;
    q := q - radius / 50
  UNTIL q < 0;
END Flower;

BEGIN (*$MAIN*)
  KD := G.ZX;
  MD := G.ZXColor;
  G.InitGraph(@KD, @MD, "");
  G.SetBkColor(G.Green); G.SetColor(G.Red); G.ClearDevice;
  x0 := (G.GetMaxX() + 1) DIV 2;
  y0 := (G.GetMaxY() + 1) DIV 2;
  Flower(x0, y0, y0 DIV 2 * 3, 5, 1, 0.25, 0.1);
  (*c := ReadKey;*)
  G.CloseGraph
END Flower.