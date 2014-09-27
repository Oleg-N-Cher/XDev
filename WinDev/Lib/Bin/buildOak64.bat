@REM Build the library Oak
@REM =====================

@IF NOT EXIST .tcc64 GOTO exit
@SET Lib=..\x86-64\Oak64.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\smart64 %Lib% Out

:exit
