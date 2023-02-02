(*$MAIN*) MODULE Life; (* Coded by Yprit, 2019 *)
IMPORT B := Basic;
VAR
	x, y, SPACE: INT8; S: INT16;
	T, T1: ARRAY 33, 23 OF INT8;
BEGIN
	B.Init;
	B.BORDER(5); B.PAPER(6); B.INK(0); B.OVER(1); B.CLS;
	B.FLASH(1); B.PRCHAR(" "); B.FLASH(0);
	B.AT(21, 0); B.PRSTR("R to random, Space to start");
	y := 1; x := 1;

	REPEAT
		IF SPACE = 0 THEN 
			LOOP (* Расстановка клеток *)
				B.PAUSE(10);
				IF ((B.PEEK(23560) = 80) OR (B.PEEK(23560) = 112)) & (x < 32) THEN
					B.AT(y - 1, x); B.FLASH(1); B.PRCHAR(" ");
					B.AT(y - 1, x - 1); B.FLASH(0); B.PRCHAR(" "); INC(x);
				ELSIF ((B.PEEK(23560) = 79) OR (B.PEEK(23560) = 111)) & (x > 1) THEN
					DEC(x); B.AT(y - 1, x - 1); B.FLASH(1); B.PRCHAR(" ");
					B.AT(y - 1, x); B.FLASH(0); B.PRCHAR(" ");
				ELSIF ((B.PEEK(23560) = 81) OR (B.PEEK(23560) = 113)) & (y > 1) THEN
					DEC(y); B.AT(y - 1, x - 1); B.FLASH(1); B.PRCHAR(" ");
					B.AT(y, x - 1); B.FLASH(0); B.PRCHAR(" ");
				ELSIF ((B.PEEK(23560) = 65) OR (B.PEEK(23560) = 97)) & (y < 21) THEN
					B.AT(y, x - 1); B.FLASH(1); B.PRCHAR(" ");
					B.AT(y - 1, x - 1); B.FLASH(0); B.PRCHAR(" "); INC(y);
				ELSIF (B.PEEK(23560) = 77) OR (B.PEEK(23560) = 109) THEN
					T[x, y] := 1 - T[x, y]; B.AT(y - 1, x - 1); B.PRCHAR("X");
				ELSIF (B.PEEK(23560)=82) OR (B.PEEK(23560)=114) THEN (*рандомайзер*)
					FOR x := 1 TO 32 DO
						FOR y := 1 TO 21 DO
							T[x, y] := SHORT(B.RND(0,1)); B.AT(y-1,x-1);
							IF T[x, y] = 1 THEN B.PRCHAR("X") ELSE B.PRCHAR(" ") END;
						END;
					END;
				END;
				IF B.PEEK(23560) = 32 THEN
					B.OVER(0); B.FLASH(0); B.AT(21,0); B.PRSTR("GEN.");
					B.AT(21, 5); B.PRSTR("    Hold [SPACE] to stop"); SPACE := 1; EXIT
				END;
				B.POKE(23560, 0);
			END;
		END;

		FOR x := 1 TO 32 DO
			FOR y := 1 TO 21 DO
				IF (T[x,y]=0 (*МЕРТВА*))&(T[x-1,y-1]+T[x-1,y]+T[x-1,y+1]+T[x,y-1]+T[x,y+1]+T[x+1,y-1]+T[x+1,y]+T[x+1,y+1]=3) THEN T1[x,y]:=1;
				ELSIF (T[x,y]=1 (*ЖИВА*))&((T[x-1,y-1]+T[x-1,y]+T[x-1,y+1]+T[x,y-1]+T[x,y+1]+T[x+1,y-1]+T[x+1,y]+T[x+1,y+1]<2)OR(T[x-1,y-1]+T[x-1,y]+T[x-1,y+1]+T[x,y-1]+T[x,y+1]+T[x+1,y-1]+T[x+1,y]+T[x+1,y+1]>3))THEN T1[x,y]:=0;
				ELSE T1[x,y]:=T[x,y];
				END;
			END;
		END;

		T := T1;

		B.AT(0, 0);
		FOR y := 1 TO 21 DO
			FOR x := 1 TO 32 DO
				IF T[x, y] # 0 THEN B.PRCHAR("X") ELSE B.PRCHAR(" ") END;
			END;
		END;

		INC(S); B.AT(21, 4); B.PRINT(S);

	UNTIL B.INKEY() = " ";
	B.Quit
END Life.
