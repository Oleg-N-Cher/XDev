@REM Build the library Kol
@REM =====================

:tcc64
@IF NOT EXIST .tcc64 GOTO exit
@SET Lib=..\Kol64.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\smart64 %Lib% KolTypes -noinit
@CALL ..\Bin\smart64 %Lib% KolStrings -noinit
@CALL ..\Bin\smart64 %Lib% KolRegistry -noinit
@CALL ..\Bin\smart64 %Lib% KolWindows

:exit
