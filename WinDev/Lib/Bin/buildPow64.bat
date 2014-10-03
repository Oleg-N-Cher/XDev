@REM Build the library Pow
@REM =====================

:tcc64
@IF NOT EXIST .tcc64 GOTO exit
@SET Lib=..\Pow64.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\smart64 %Lib% PowStrings -noinit

:exit
