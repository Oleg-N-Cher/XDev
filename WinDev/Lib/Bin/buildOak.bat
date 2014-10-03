@REM Build the library Oak
@REM =====================

:tcc
@SET Lib=..\Oak.a
@IF EXIST %Lib% DEL %Lib%
@CALL ..\Bin\smart %Lib% Out

:djgpp
@IF NOT EXIST .djgpp GOTO exit
@SET Lib=..\OakDJGPP.a
@IF EXIST %Lib% DEL %Lib%
::@CALL ..\Bin\soliddjgpp %Lib% AclUtils
::@CALL ..\Bin\soliddjgpp %Lib% AclLib

:exit
