@REM Build the library Oak
@REM =====================

:MinGW64
@SET Lib=..\Rose64.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\solid64 %Lib% Rose
@CALL ..\Bin\solid64 %Lib% RoseRedir
