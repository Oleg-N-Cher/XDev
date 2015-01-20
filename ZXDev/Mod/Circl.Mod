(*

(c) Reobne, 2014

http://zx.pk.ru/showpost.php?p=714675&postcount=238

Сделал первый "продукт" в среде ZXDev.

Иллюстрация окружностей и работы EORFill.
http://zx.pk.ru/showpost.php?p=714673&postcount=380

Первоначальный алгоритм рисования окружности
http://zx.pk.ru/showpost.php?p=714282&postcount=318

где-то нарыл denpopov, потом его исправляли, в основном Titus.
За основу взял пример с цветочком. Flower.Mod
*)

MODULE Circl;
IMPORT G := Graph, Basic, Asm;

VAR
  KD, MD, x0, y0, R, i: INTEGER;

PROCEDURE Circ (x, y, Radius: INTEGER);
VAR
  X,Y,A:INTEGER;

	PROCEDURE Plot4;
	VAR
	  ty:INTEGER;
	BEGIN
	  ty:=(y+Y);
		IF ty<0 THEN ty:=0 ELSIF ty>G.GetMaxY() THEN ty:=G.GetMaxY() END;
		G.PutPixel(x +X,ty);
		IF X#0 THEN G.PutPixel(x -X,ty); END;
	  ty:=(y-Y);
		IF ty<0 THEN ty:=0 ELSIF ty>G.GetMaxY() THEN ty:=G.GetMaxY() END;
		G.PutPixel(x +X,ty);
		IF X#0 THEN G.PutPixel(x -X,ty); END;
	END Plot4;
BEGIN
(*This is the entire algorithm:*)

	Y:= Radius;
	X:=0;
	A := Radius DIV 2;
	REPEAT
			(*;Could just use Plot8*)
		Plot4;X := X + 1;
		A := A - X;
		IF A<0 THEN A:=A+Y ; Y:=Y-1 END;
	UNTIL X >= Y;

(*; Now more or less reverse the above to get the other eighth*)

	A := -(Radius DIV 2) - 1;
	Plot4;
	REPEAT
		A := A + Y;
		Y := Y - 1;
		IF A>0 THEN X:=X+1;A:=A-X;Plot4; END;
	UNTIL ~(Y>=0);
	
END Circ;

PROCEDURE EORFill;
BEGIN
  Asm.Code("  LD   L,#0X20       ");
  Asm.Code("loop1$:              ");
  Asm.Code("  DEC L              ");
  Asm.Code("  LD   H,#0X40       ");
  Asm.Code("  XOR A              ");
  Asm.Code("  LD   C,#3          ");
  Asm.Code("loop2$:              ");
  Asm.Code("  LD   B,#8          ");
  Asm.Code("  LD   DE,#32-7*256  ");
  Asm.Code("loop3$:              ");
  Asm.Code("  XOR (HL)           ");
  Asm.Code("  LD (HL),A          ");
  Asm.Code("  INC H              ");
  Asm.Code("  XOR (HL)           ");
  Asm.Code("  LD (HL),A          ");
  Asm.Code("  INC H              ");
  Asm.Code("  XOR (HL)           ");
  Asm.Code("  LD (HL),A          ");
  Asm.Code("  INC H              ");
  Asm.Code("  XOR (HL)           ");
  Asm.Code("  LD (HL),A          ");
  Asm.Code("  INC H              ");
  Asm.Code("  XOR (HL)           ");
  Asm.Code("  LD (HL),A          ");
  Asm.Code("  INC H              ");
  Asm.Code("  XOR (HL)           ");
  Asm.Code("  LD (HL),A          ");
  Asm.Code("  INC H              ");
  Asm.Code("  XOR (HL)           ");
  Asm.Code("  LD (HL),A          ");
  Asm.Code("  INC H              ");
  Asm.Code("  XOR (HL)           ");
  Asm.Code("  LD (HL),A          ");
  Asm.Code("  ADD HL,DE          ");
  Asm.Code("  DJNZ loop3$        ");
  Asm.Code("  LD DE,#8*256-8*32  ");
  Asm.Code("  ADD HL,DE          ");
  Asm.Code("  DEC C              ");
  Asm.Code("  JR NZ,loop2$       ");
  Asm.Code("  DEC L              ");
  Asm.Code("  INC L              ");
  Asm.Code("  JR NZ,loop1$       ");
END EORFill;

BEGIN (*$MAIN*)
  KD := G.ZX;
  MD := G.ZXMono;
  G.InitGraph(KD, MD, "");
  G.SetBkColor(G.Green); G.SetColor(G.Black); G.ClearDevice;
  Basic.OVER(1);
	FOR i:=0 TO 20 DO
	  x0 := Basic.RNDW(-60,G.GetMaxX()+60);
  	y0 := Basic.RNDW(-60,G.GetMaxY()+60);
	  
		FOR R:=20 TO 60 BY 20 DO
  		Circ(x0, y0, R);
	  END;
  END;
	EORFill;
  G.CloseGraph
END Circl.