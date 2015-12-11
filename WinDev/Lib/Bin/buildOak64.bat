@REM Build the library Oak
@REM =====================

:MinGW64
@SET Lib=..\Oak64.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\smart64 %Lib% Out
