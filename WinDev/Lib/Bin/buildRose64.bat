@REM Build the library Oak
@REM =====================

@IF NOT EXIST .tcc64 GOTO exit
@SET Lib=..\Rose64.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\solid64 %Lib% Rose
@CALL ..\Bin\solid64 %Lib% RoseRedir

:exit
