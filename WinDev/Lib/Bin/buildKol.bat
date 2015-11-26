@REM Build the library Kol
@REM =====================

:tcc
@SET Lib=..\Kol.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\smart %Lib% KolTypes -noinit
@CALL ..\Bin\smart %Lib% KolStrings -noinit
@CALL ..\Bin\smart %Lib% KolRegistry -noinit
@CALL ..\Bin\smart %Lib% KolWindows
@CALL ..\Bin\solid %Lib% KolObj
@CALL ..\Bin\smart %Lib% KolFiles -noinit
@CALL ..\Bin\solid %Lib% KolXXSocket

:djgpp
@IF NOT EXIST .djgpp GOTO exit
@SET Lib=..\KolDJGPP.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\smartdjgpp %Lib% KolTypes -noinit
@CALL ..\Bin\smartdjgpp %Lib% KolStrings -noinit
@CALL ..\Bin\smartdjgpp %Lib% KolRegistry -noinit
@CALL ..\Bin\smartdjgpp %Lib% KolWindows
@CALL ..\Bin\soliddjgpp %Lib% KolObj
@CALL ..\Bin\smartdjgpp %Lib% KolFiles -noinit
@CALL ..\Bin\soliddjgpp %Lib% KolXXSocket

:exit
