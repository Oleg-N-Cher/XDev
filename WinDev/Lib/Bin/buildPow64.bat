@REM Build the library Pow
@REM =====================

:MinGW64
@SET Lib=..\Pow64.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\smart64 %Lib% PowStrings -noinit
