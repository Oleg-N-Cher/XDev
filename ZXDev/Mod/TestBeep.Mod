MODULE TestBeep; (* https://zxpress.ru/article.php?id=5440 *)
IMPORT B := Basic;

TYPE Melody = ARRAY 29 OF BYTE;

CONST
  Freq = Melody(
    7, 16, 16, 14, 16, 12, 7, 7, 7, 16, 16, 14, 21, 19, 0, 19, 9, 9,
    17, 17, 16, 14, 12, 7, 16, 16, 14, 16, 12
  );
  Temp = Melody(
    25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 50, 25, 25,
    25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 50
  );

VAR
  i: BYTE;
BEGIN (*$MAIN*)
  B.Init;
  FOR i := 0 TO LEN(Freq) - 1 DO
    IF Freq[i] # 0 THEN B.BEEP(Temp[i] * 10, Freq[i])
    ELSE B.PAUSE(Temp[i] DIV 2)
    END
  END
  B.Quit
END TestBeep.
