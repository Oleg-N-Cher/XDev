@REM Build the library Pow
@REM =====================

:tcc
@SET Lib=..\Pow.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\smart %Lib% PowStrings -noinit

:djgpp
@IF NOT EXIST .djgpp GOTO exit
@SET Lib=..\PowDJGPP.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\smartdjgpp %Lib% PowStrings -noinit

:exit
