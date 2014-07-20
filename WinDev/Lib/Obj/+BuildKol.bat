@REM Build the library Kol
@REM =====================
@CD ..

:tcc
@SET Lib=Kol.a
@IF EXIST %Lib% DEL %Lib%
@CALL Bin\smart %Lib% KolTypesA -noinit
@CALL Bin\smart %Lib% KolStringsA -noinit
@CALL Bin\smart %Lib% KolRegKeyA -noinit

:djgpp
@IF NOT EXIST Obj\.djgpp GOTO tcc64
@SET Lib=KolDJGPP.a
@IF EXIST %Lib% DEL %Lib%
@CALL Bin\smartdjgpp %Lib% KolTypesA -noinit
@CALL Bin\smartdjgpp %Lib% KolStringsA -noinit
@CALL Bin\smartdjgpp %Lib% KolRegKeyA -noinit

:tcc64
@IF NOT EXIST Obj\.tcc64 GOTO exit
@SET Lib=Kol64.a
@IF EXIST %Lib% DEL %Lib%
@CALL Bin\smart64 %Lib% KolTypesA -noinit
@CALL Bin\smart64 %Lib% KolStringsA -noinit
@CALL Bin\smart64 %Lib% KolRegKeyA -noinit

:exit
@CD Obj