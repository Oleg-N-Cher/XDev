(* Spiral on the ball (Pascal/Fast, UK-NC) for ZXDev/Oberon-2 *)
(* Copyright (C) 1996 AzAtom *)
(* http://azatom.narod.ru, http://zx-pk.ru/forum.php *)
 
MODULE Spiral11;
IMPORT Basic, G := GrPixel, Math;
 
CONST
  cx = 128; cy = 88; (* Coords of screen center *)
  R  = 80; (* Radius. Can be changed from 1 to 88 *)
  A  = 30; (* Angle. Can be changed from 0 to 90 *)
  V  = 20; (* Number of turns. Can be changed from 1 to .. *)

VAR
  i, x, y: INT16; yr1, yr2: REAL;
	Sina, Cosa: ARRAY 361 OF REAL;

PROCEDURE PrepareTables;
VAR
  i, q: INT8;
BEGIN
  (* Подготовка массива синусов и косинусов *)
  Sina[0] := Math.Sin(0); Cosa[0] := Math.Cos(0);
  G.PutPixel(37, 0); G.PutPixel(37, 1); G.PutPixel(37, 2); G.PutPixel(0, 0);
  FOR i := 1 TO 36 DO
    yr1 := i * Math.Pi / 18;
    Sina[i*10] := Math.Sin(yr1); Cosa[i*10] := Math.Cos(yr1);
    yr1 := (Sina[i*10] - Sina[(i-1) * 10]) / 10;
    yr2 := (Cosa[i*10] - Cosa[(i-1) * 10]) / 10;
    FOR q := 1 TO 9 DO
      Sina[(i-1)*10 + q] := Sina[(i-1)*10] + yr1*q;
      Cosa[(i-1)*10 + q] := Cosa[(i-1)*10] + yr2*q;
    END;
    G.PutPixel(i, 0);
  END;
END PrepareTables;

BEGIN (*$MAIN*)
  Basic.Init; Basic.CLS;
  PrepareTables; Basic.CLS;

  yr1 := R * Sina[A]; (* Размах по y *)
  yr2 := R * Cosa[A]; (* Начало по y *)

  i := V * 36;
  REPEAT
    (* Когда i дойдёт до V*36, первый косинус должен V раз дойти до 360. *)
    (* Когда i дойдёт до V*36, второй синус должен дойти до 180. *)
    G.PutPixel(
      cx + SHORT(ENTIER(R*Cosa[i*10 MOD 360] * Sina[i*5 DIV V])),
      (* Когда i дойдёт до V*36, первый синус должен v раз дойти до 360. *)
      (* Когда i дойдёт до V*36, второй синус должен дойти до 180. *)
      (* Когда i дойдёт до V*36, третий косинус должен дойти до 180. *)
      cy + SHORT(ENTIER(yr1*Sina[i*10 MOD 360] * Sina[i*5 DIV V]
         - yr2*Cosa[i*5 DIV V]))
    );
  DEC(i);
  UNTIL i < 0;

  Basic.PAUSE(0);
  Basic.Quit
END Spiral11.
