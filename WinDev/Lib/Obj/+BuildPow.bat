@REM Build the library Pow
@REM =====================
@CD ..

:tcc
@SET Lib=x86\Pow.a
@IF EXIST %Lib% DEL %Lib%
@CALL Bin\smart %Lib% PowStrings -noinit

:djgpp
@IF NOT EXIST Obj\.djgpp GOTO tcc64
@SET Lib=x86\PowDJGPP.a
@IF EXIST %Lib% DEL %Lib%
@CALL Bin\smartdjgpp %Lib% PowStrings -noinit

:tcc64
@IF NOT EXIST Obj\.tcc64 GOTO exit
@SET Lib=x86-64\Pow64.a
@IF EXIST %Lib% DEL %Lib%
@CALL Bin\smart64 %Lib% PowStrings -noinit

:exit
@CD Obj