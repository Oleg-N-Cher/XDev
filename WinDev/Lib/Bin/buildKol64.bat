@REM Build the library Kol
@REM =====================

:MinGW64
@SET Lib=..\Kol64.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\smart64 %Lib% KolTypes -noinit
@CALL ..\Bin\smart64 %Lib% KolStrings -noinit
@CALL ..\Bin\smart64 %Lib% KolRegistry -noinit
@CALL ..\Bin\smart64 %Lib% KolWindows
@CALL ..\Bin\solid64 %Lib% KolObj
@CALL ..\Bin\smart64 %Lib% KolFiles -noinit
@CALL ..\Bin\solid64 %Lib% KolXXSocket
