MODULE MoveSpr;

(* "MoveSpr" Demo for Sinclair ZX Spectrum, 48 Kb. *)
(* Copyright (C) 2017 Oleg N. Cher, VEDAsoft. *)

IMPORT L := Laser, B := Basic, Key := Control;

CONST
	MaxX = 28; (* Максимально допустимое значение координаты x *)
	MaxY = 20; (* Максимально допустимое значение координаты y *)
  SizeBytes = 5(*hdr*) + 8*9(*data*) ;

TYPE
  Sprite = ARRAY SizeBytes * 1 (*frames*) + 1 OF SHORTCHAR;

CONST
  Turtle = Sprite (
    1X, 0X, 0X, 4X, 2X, (* SPN, offset, LEN, HGT *)
    000X,0FFX,000X,000X,000X,0FFX,040X,000X,
    007X,07EX,0E0X,000X,007X,081X,0E0X,000X,
    00FX,0BEX,0F0X,000X,007X,07FX,070X,000X,
    01AX,0FFX,078X,000X,03DX,0FFX,07CX,000X,
    039X,0FEX,09DX,0F0X,076X,001X,0EDX,0DCX,
    0FFX,0FFX,0FDX,08EX,000X,000X,001X,0AEX,
    00FX,000X,078X,0F8X,01EX,000X,03CX,000X,
    03CX,000X,03EX,000X,03CX,000X,00EX,000X,
    005X,005X,005X,005X,005X,005X,005X,005X,
    0X
  );

VAR
  pressed: SET; x, y: BYTE;

BEGIN (*$MAIN*)
	B.Init; L.InitSpritesAr(Turtle);
	B.BORDER(B.Green); B.PAPER(B.Black); B.CLS; (* Подготовка экрана *)
	x := 10; y := 10; (* Начальные координаты спрайта *)
	LOOP (* Вечный цикл *)
		L.PTBL(x, y, 1); (* Выводим на экран спрайт с номером 1 *)
		(* Есть обработка кнопок, нажатых вместе *)
		pressed := Key.Get();
	  IF Key.Up IN pressed THEN y := y - 1 END;
	  IF Key.Down IN pressed THEN y := y + 1 END;
	  IF Key.Left IN pressed THEN x := x - 1 END;
	  IF Key.Right IN pressed THEN x := x + 1 END;
		(* Исправляем координаты при выходе за пределы экрана *)
		IF x < 0 THEN x := 0 END;
		IF y < 0 THEN y := 0 END;
		IF x > MaxX THEN x := MaxX END;
		IF y > MaxY THEN y := MaxY END;
	END;
	(*B.Quit;*)
END MoveSpr.
