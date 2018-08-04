(* Spiral on the ball, fast version. (Pascal/Fast, UK-NC) for ZXDev/Oberon-2 *)
(* Copyright (C) 1996 AzAtom *)
(* http://azatom.narod.ru, http://zx-pk.ru/forum.php *)
(* Целочисленные вычисления *)

MODULE Spiral11f2;
IMPORT G := Graph, Math;

CONST
  cx = 128; cy = 88; (* Coords of screen center *)
  R = 80; (* Radius. Can be changed from 1 to 88 *)
  A = 30; (* Angle. Can be changed from 0 to 90 *)
  V = 20; (* Number of turns. Can be changed from 1 to .. *)

VAR
  KD, MD: SHORTINT; i, r1, r2: SHORTINT; Sina, Cosa: ARRAY 361 OF SHORTINT;

PROCEDURE PrepareTables;
VAR
  i: SHORTINT; q: BYTE; yr1, yr2: REAL;
BEGIN
  (* Подготовка массива синусов и косинусов *)
  Sina[0] := SHORT(SHORT(ENTIER(Math.Sin(0) * 256)));
  Cosa[0] := SHORT(SHORT(ENTIER(Math.Cos(0) * 256)));
  G.PutPixel(37,0); G.PutPixel(37,1); G.PutPixel(37,2); G.PutPixel(0,0);
  FOR i := 1 TO 36 DO
    yr1 := i*3.1416 / 18;
    Sina[i*10] := SHORT(SHORT(ENTIER(Math.Sin(yr1)*256)));
    yr1 := (Sina[i*10] - Sina[(i-1)*10]) / 10;
    FOR q := 1 TO 9 DO
      Sina[(i-1)*10 + q] := SHORT(SHORT(ENTIER(Sina[(i-1)*10] + yr1*q)));
    END;
    G.PutPixel(i, 0);
  END;
  FOR i := 1 TO 360 DO
    Cosa[i] := Sina[(i + 90) MOD 360];
  END;
END PrepareTables;

BEGIN (*$MAIN*)
  KD := G.ZX;
  MD := G.ZXMono;
  G.InitGraph(KD, MD, "");

  PrepareTables;

  r1 := (R * Sina[A]) DIV 256; (* Размах по y *)
  r2 := (R * Cosa[A]) DIV 256; (* Начало по y *)

  i := V * 36;
  REPEAT
    G.PutPixel(
   (* Когда i дойдёт до v*36, первый косинус должен v раз дойти до 360. *)
   (* Когда i дойдёт до v*36, второй синус должен дойти до 180. *)
      cx + R*Cosa[i*10 MOD 360] DIV 256 * Sina[i*5 DIV V] DIV 256,
   (* Когда i дойдёт до v*36, первый синус должен v раз дойти до 360. *)
   (* Когда i дойдёт до v*36, второй синус должен дойти до 180. *)
   (* Когда i дойдёт до v*36, третий косинус должен дойти до 180. *)
      cy + r1*Sina[i*10 MOD 360] DIV 256 * Sina[i*5 DIV V] DIV 256
         - r2*Cosa[i*5 DIV V] DIV 256
    );
  DEC(i);
  UNTIL i < 0;

  G.CloseGraph
END Spiral11f2.
