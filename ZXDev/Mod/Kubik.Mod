MODULE Kubik; (*$MAIN*)
IMPORT Basic;

CONST
	HowManyTimes = 1000;
VAR
	(* Завести 6 переменных (по количеству граней кубика). *)
	one, two, three, four, five, six, n, number: INTEGER;
BEGIN
	Basic.RANDOMIZE(0);
	(* Обнулить наши счётчики граней кубика. *)
	one := 0; two := 0; three := 0; four := 0; five := 0; six := 0;
	(* Повторить 1000 раз выбрасывание кубика *)
	FOR n := 1 TO HowManyTimes DO
		(* и посчитать сколько раз выпала каждая грань. *)
		number := Basic.RND(1, 6);
		IF number = 1 THEN one := one + 1 END;
		IF number = 2 THEN two := two + 1 END;
		IF number = 3 THEN three := three + 1 END;
		IF number = 4 THEN four := four + 1 END;
		IF number = 5 THEN five := five + 1 END;
		IF number = 6 THEN six := six + 1 END;
	END;

	(* Нарисовать цветную таблицу *) (*
				+---+------------+
				| 1 |    200     |
				+---+------------+
				| 2 |    200     |
				+---+------------+
				| 3 |    200     |
				+---+------------+
				| 4 |    300     |
				+---+------------+
				| 5 |     50     |
				+---+------------+
				| 6 |     50     |
				+---+------------+
	*)
	Basic.BORDER(Basic.Black); Basic.PAPER(Basic.Black);
	Basic.INK(Basic.Cyan); Basic.CLS;
	Basic.PRSTR("+---+------------+"); Basic.PRLN;
	Basic.PRSTR("| "); Basic.INK(Basic.Red); Basic.PRINT(1);
		Basic.INK(Basic.Cyan); Basic.PRSTR(" |            |"); Basic.PRLN;
	Basic.PRSTR("+---+------------+"); Basic.PRLN;
	Basic.PRSTR("| "); Basic.INK(Basic.Yellow); Basic.PRINT(2);
		Basic.INK(Basic.Cyan); Basic.PRSTR(" |            |"); Basic.PRLN;
	Basic.PRSTR("+---+------------+"); Basic.PRLN;
	Basic.PRSTR("| "); Basic.INK(Basic.Green); Basic.PRINT(3);
		Basic.INK(Basic.Cyan); Basic.PRSTR(" |            |"); Basic.PRLN;
	Basic.PRSTR("+---+------------+"); Basic.PRLN;
	Basic.PRSTR("| "); Basic.INK(Basic.Magenta); Basic.PRINT(4);
		Basic.INK(Basic.Cyan); Basic.PRSTR(" |            |"); Basic.PRLN;
	Basic.PRSTR("+---+------------+"); Basic.PRLN;
	Basic.PRSTR("| "); Basic.INK(Basic.Blue); Basic.PRINT(5);
		Basic.INK(Basic.Cyan); Basic.PRSTR(" |            |"); Basic.PRLN;
	Basic.PRSTR("+---+------------+"); Basic.PRLN;
	Basic.PRSTR("| "); Basic.INK(Basic.White); Basic.PRINT(6);
		Basic.INK(Basic.Cyan); Basic.PRSTR(" |            |"); Basic.PRLN;
	Basic.PRSTR("+---+------------+");
	(* и вывести результаты. *)
	Basic.AT(1, 10); Basic.INK(Basic.Red); Basic.PRINT(one);
	Basic.AT(3, 10); Basic.INK(Basic.Yellow); Basic.PRINT(two);
	Basic.AT(5, 10); Basic.INK(Basic.Green); Basic.PRINT(three);
	Basic.AT(7, 10); Basic.INK(Basic.Magenta); Basic.PRINT(four);
	Basic.AT(9, 10); Basic.INK(Basic.Blue); Basic.PRINT(five);
	Basic.AT(11, 10); Basic.INK(Basic.White); Basic.PRINT(six);
END Kubik.
