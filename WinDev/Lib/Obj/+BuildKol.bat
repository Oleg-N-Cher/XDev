@REM Build the library Kol
@REM =====================
@CD ..

:tcc
@SET Lib=Kol.a
@IF EXIST %Lib% DEL %Lib%
@CALL Bin\smart %Lib% KolTypes -noinit
@CALL Bin\smart %Lib% KolStrings -noinit
@CALL Bin\smart %Lib% KolRegistry -noinit
@CALL Bin\smart %Lib% KolWindows

:djgpp
@IF NOT EXIST Obj\.djgpp GOTO tcc64
@SET Lib=KolDJGPP.a
@IF EXIST %Lib% DEL %Lib%
@CALL Bin\smartdjgpp %Lib% KolTypes -noinit
@CALL Bin\smartdjgpp %Lib% KolStrings -noinit
@CALL Bin\smartdjgpp %Lib% KolRegistry -noinit
@CALL Bin\smartdjgpp %Lib% KolWindows

:tcc64
@IF NOT EXIST Obj\.tcc64 GOTO exit
@SET Lib=Kol64.a
@IF EXIST %Lib% DEL %Lib%
@CALL Bin\smart64 %Lib% KolTypes -noinit
@CALL Bin\smart64 %Lib% KolStrings -noinit
@CALL Bin\smart64 %Lib% KolRegistry -noinit
@CALL Bin\smart64 %Lib% KolWindows

:exit
@CD Obj