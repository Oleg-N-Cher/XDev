(* Sinus example (Pascal/Fast, UK-NC) for ZXDev/Oberon-2 *)
(* Copyright (C) 2013 Oleg N. Cher, VEDAsoft Oberon Club *)
(* http://zx.oberon2.ru *)

MODULE GraphSinus;
IMPORT G := Graph, Math;

CONST
	k1 = 20; k2 = 50;
VAR
	KD, MD, i, s, ox, oy: INT16;

PROCEDURE Sign (x: INT16): INT8;
BEGIN
	IF x > 0 THEN RETURN 1 END;
	IF x < 0 THEN RETURN -1 END;
	RETURN 0
END Sign;

BEGIN (*$MAIN*)
	KD := G.ZX;
	MD := G.ZXMono;
	G.InitGraph(@KD, @MD, "");
	ox := (G.GetMaxX() + 1) DIV 2;
	oy := (G.GetMaxY() + 1) DIV 2;
	G.SetColor(G.White);
	G.Line(0, oy, G.GetMaxX() + 1, oy);
	G.Line(ox, 0, ox, G.GetMaxY() + 1);
	G.Line(G.GetMaxX() - 4, oy - 3, G.GetMaxX(), oy - 1);
	G.Line(G.GetMaxX() - 4, oy + 3, G.GetMaxX(), oy + 1);
	G.Line(ox - 3, 5, ox - 1, 1);
	G.Line(ox + 3, 5, ox + 1, 1);
	FOR i := 1 TO ox - 10 DO
		s := SHORT(ENTIER(Math.Sin(i / k1) * k2));
		IF s # 0 THEN
			G.Line(i + ox, s + oy, ox, oy + Sign(s));
			G.Line(ox - i, oy - s, ox, oy - Sign(s));
		END;
	END;
	(*c := ReadKey;*)
	G.CloseGraph;
END GraphSinus.