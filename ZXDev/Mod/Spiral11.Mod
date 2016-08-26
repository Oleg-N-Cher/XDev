(* Spiral on the ball (Pascal/Fast, UK-NC) for ZXDev/Oberon-2 *)
(* Copyright (C) 1996 AzAtom *)
(* http://azatom.narod.ru, http://zx-pk.ru/forum.php *)
 
MODULE Spiral11;
IMPORT G := GrPixel, Math;
 
CONST
  cx = 128; cy = 88;
  R  = 80; (* Can be changed from 1 to 88*)
  A  = 30; (* Can be changed from 0 to 90*)
  A2 = A * 3.1415/180;
  V  = 20; (* Can be changed from 1 to ..*)

VAR
  i, x, y: INTEGER; yr1, yr2: REAL;

BEGIN (*$MAIN*)
  yr1 := R * Math.Sin(A2); yr2 := R * Math.Cos(A2);
  FOR i := 0 TO V*36 DO
    G.PutPixel(
      cx + SHORT(ENTIER(R*Math.Cos(3.1415*i/18)*Math.Sin(3.1415*i/(36*V)))),
      cy + SHORT(ENTIER(yr1*Math.Sin(3.1415*i/18)*Math.Sin(3.1415*i/(36*V))
         - yr2*Math.Cos(3.1415*i/(36*V))))
    )
  END;
END Spiral11.
