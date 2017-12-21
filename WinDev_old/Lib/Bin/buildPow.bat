@REM Build the library Pow
@REM =====================

:MinGW
@SET Lib=..\Pow.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\smart %Lib% PowStrings -noinit

:DJGPP
@IF NOT EXIST .djgpp GOTO exit
@SET Lib=..\PowDJGPP.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\smartdjgpp %Lib% PowStrings -noinit

:exit
